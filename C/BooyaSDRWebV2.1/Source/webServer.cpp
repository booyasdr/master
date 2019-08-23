///* Server program example for IPv4 */
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include <ddk/ndis.h>
#include "include/cWebSockets.h"
#include "webServer.h"
#include "radio.h"

webServerClass webServer;

void* webServerClass::listener(void *args) { // listen for new connections

    class webServerClass *pwebServer = (class webServerClass *) args;
    class listenerInputClass *pinput = (class listenerInputClass *) &pwebServer->listenerInput;
    char ip_address[256], app[256];
    int retval, fromlen;
    struct sockaddr_in local, from;
    WSADATA wsaData;
    SOCKET listen_socket, msgsock;

    unsigned short port=pinput->in_port;
    strcpy(ip_address,pinput->address);
    strcpy(app,pinput->in_app);

    if ((retval = WSAStartup(0x202, &wsaData)) != 0) {
        fprintf(stderr,"Server: WSAStartup() failed with error %d\n", retval);
        WSACleanup();
        return 0;
    }
    else
       printf("Server: WSAStartup() is OK.\n");

    memset((char *) &local, '\0',sizeof(local));
    local.sin_family = AF_INET;
//    *ip_address = '\0';
    local.sin_addr.s_addr = (!ip_address) ? INADDR_ANY:inet_addr(ip_address);

    local.sin_port = htons(port);    /* Port MUST be in Network Byte Order */
    listen_socket = socket(AF_INET, SOCK_STREAM,0);    // TCP socket

    if (listen_socket == INVALID_SOCKET){
        fprintf(stderr,"Server: socket() failed with error %d\n", WSAGetLastError());
        WSACleanup();
        return 0;
    }
    else
       printf("Server: socket() is OK.\n");

//     bind() associates a local address and port combination with the socket just created.
    if (bind(listen_socket, (struct sockaddr*)&local, sizeof(local)) == SOCKET_ERROR) {
        fprintf(stderr,"Server: bind() failed with error %d\n", WSAGetLastError());
        WSACleanup();
        return 0;
    }
    else
        printf("Server: bind() is OK.\n");

    if (listen(listen_socket, /*backlog*/ 5 ) == SOCKET_ERROR) {
        fprintf(stderr,"Server: listen() failed with error %d\n", WSAGetLastError());
        WSACleanup();
        return 0;
    }

    while(1) {
        printf("Server: %s: I'm listening and waiting connection\non port %d, protocol %s\n"
               , app, port, (SOCK_STREAM == SOCK_STREAM)?"TCP":"UDP");

        fromlen =sizeof(from);
        msgsock = accept(listen_socket, (struct sockaddr *)&from, &fromlen);
        if (msgsock == INVALID_SOCKET) {
            fprintf(stderr,"Server: accept() error %d\n", WSAGetLastError());
            WSACleanup();
            return 0;
        }  else {
            printf("Server: accept() is OK from %s : %d.\n",inet_ntoa(from.sin_addr), ntohs(from.sin_port));
            ioctlsocket(msgsock,FIONBIO,0);         // enable blocking on msgsock
        }

        printf("\nServer: accepted connection from %s, port %d\n", inet_ntoa(from.sin_addr), ntohs(from.sin_port));
        pwebServer->newConnection(msgsock,&from);

    } // while(1)
    WSACleanup();
    return 0;
}

connectionClass* webServerClass::newConnection(SOCKET msgsock,struct sockaddr_in *pfrom) {
   bool found = false;
   connectionClass *pc;
   int n;
   MUTEXCONNECTIONLIST_LOCK
   for( n = 0; n < maxConnection; n++) {
      if(connection[n].state == notConnected) {
         pc = &connection[n];
         pc->id = n;
         found = true;
         break;
      }
   }
   if(!found) {
      printf("Connection overflow, connection rejected\n");
      MUTEXCONNECTIONLIST_UNLOCK
      return 0;
   }
   connectionList[nConnection] = pc;
   nConnection++;

   MUTEXCONNECTIONLIST_UNLOCK
   printf("Opening socket %d connection %d with %d open connections\n",msgsock,pc->id,nConnection);

   pc->init(this); // pass server pointer to the connection initialization
   pc->sock = msgsock;
   pc->from = *pfrom;

   return pc;
}

void webServerClass::closeConnection(connectionClass* pc) {
   pc->isOpen = false;
   pc->state = notConnected;
//   Sleep(300); // wait for pipes to clear
   pc->ru->stop(); // stop the radio
   while(!pc->WSq.empty()) pc->WSq.pop();
   bool found = false;
   MUTEXCONNECTIONLIST_LOCK
   for(int n = 0; n < nConnection; n++) {
     if (pc == connectionList[n]) found = true;
     if (found) {
         connectionList[n] = connectionList[n+1];
     }
   }
   if(!found) { //second call
      MUTEXCONNECTIONLIST_UNLOCK
      return;
   }
   nConnection--;
   if(nConnection < maxConnection)
     connectionList[nConnection] = NULL;

   MUTEXCONNECTIONLIST_UNLOCK
   closesocket(pc->sock);
}

void *webServerClass::serverStatus(void *args) {
   webServerClass *p = (webServerClass *) args;
   connectionClass **connectionList = (connectionClass **)p->connectionList;
   connectionClass *pc = NULL;
   char text[1000];
   float cpu_usage= 50;

   while (1) {
      Sleep(2000);
WEBSERVERMUTEXCONNECTIONLIST_LOCK
      int M = p->nConnection;
      sprintf(text,"cpu_usage=%.1f clients=%d",cpu_usage,M);
      for(int m = 0; m < M; m++) {
         pc = connectionList[m];
         if(pc->state > notConnected) {
             if(pc->isOpen)
               pc->sendWSData((char*)"MSG",(char *) text, strlen(text));
         }
      }
WEBSERVERMUTEXCONNECTIONLIST_UNLOCK
	}
	pthread_exit(NULL);
	return NULL;
}
