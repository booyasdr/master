// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net
#include "global.h"
#include <winsock2.h>
#include <pthread.h>
#include "rssConnection.h"
#include "rssServer.h"

void *rssConnectionClass::init(void *args){
    rssServerClass *prssServer = (rssServerClass *)args; // pc, pointer to connection
    voidPserver = (void *) prssServer;    // set pointer back to server

    // initialize the found connection
    while(!WSq.empty()) WSq.pop();
    memset(msgPool,'\0',sizeof(WSmsg)*MAXMESSAGE);

    pthread_mutex_init(&send_mutex, NULL);
    pthread_mutex_lock(&send_mutex);

    state = http;

//   if(!ru) ru = new radioUserClass(this);

    pthread_create(&send_thread   , NULL, send   , (void *) this);
    pthread_create(&receive_thread, NULL, receive, (void *) this);

    pthread_detach(send_thread);
    pthread_detach(receive_thread);
}

void *rssConnectionClass::close(void ){
   pthread_mutex_unlock(&send_mutex);           // allows connection, send to see notConnected
}

void* rssConnectionClass::receive(void *args) {
   rssConnectionClass *pc = (rssConnectionClass *)args; // pc, pointer to connection
   rssServerClass *prssServer = (rssServerClass *) pc->voidPserver; // point back to server
   // unpack connection data
   connectionState *state = &pc->state;
   SOCKET msgsock = pc->sock;
   Queue<WSmsg*,MAXMESSAGE>  *pWSq = &pc->WSq;           // create a pointer to the queue
   struct sockaddr_in from;
   int fromlen = sizeof(from);
   int retval;
   char text[MSGLEN]; // storage for debug output string
   WSmsg wsmsgRcv;

   while(*state > notConnected) { // receive
      memset(wsmsgRcv.ws.d,'\0',MSGLEN);
      retval = recv(msgsock, wsmsgRcv.ws.d, MSGLEN, 0);  // block

      struct sockaddr_in client_info = {0};
      int addrsize = sizeof(client_info);

      // or get it from the socket itself at any time
      getpeername(msgsock, (struct sockaddr*)&client_info, &addrsize);

      char *ip = inet_ntoa(client_info.sin_addr);
      printf("ip: %s\n", ip);

      wsmsgRcv.ws.l = retval;
      if (retval == SOCKET_ERROR) {
         printf("%2X %2x %2x %2x\n",wsmsgRcv.ws.d[0]&0xff,wsmsgRcv.ws.d[1]&0xff,
         wsmsgRcv.ws.d[2]&0xff,wsmsgRcv.ws.d[3]&0xff);
         fprintf(stderr,"Server: recv() failed: error %d socket %d connection %d of %d, state %d.\n", WSAGetLastError(),msgsock,pc->id,prssServer->nConnection,*state);
         break;
      } else if (retval == 0) {
         printf("%2X %2x %2x %2x %2x %2x %2x %2x\n",wsmsgRcv.ws.d[0]&0xff,wsmsgRcv.ws.d[1]&0xff,
         wsmsgRcv.ws.d[2]&0xff,wsmsgRcv.ws.d[3]&0xff,wsmsgRcv.ws.d[4]&0xff,wsmsgRcv.ws.d[5]&0xff,
         wsmsgRcv.ws.d[6]&0xff,wsmsgRcv.ws.d[7]&0xff);
         printf("Server: recv() failed: error %d socket %d connection %d of %d, state %d.\n", WSAGetLastError(),msgsock,pc->id,prssServer->nConnection,*state);
         break;
      }

      strncpy(wsmsgRcv.raw.d,wsmsgRcv.ws.d,wsmsgRcv.ws.l);
      wsmsgRcv.raw.d[wsmsgRcv.ws.l] = '\0';


   } // while(*state > notConnected)
   printf("prssServer->closeConnection(pc);\n");
   prssServer->closeConnection(pc);
   printf("Exit rssConnectionClass::receive, socket %d connection %d with %d connections open\n",msgsock,pc->id,prssServer->nConnection);
   pthread_exit(NULL);
}

void *rssConnectionClass::send(void *args) {
   rssConnectionClass *pc = (rssConnectionClass *)args;
   rssServerClass *prssServer = (rssServerClass *) pc->voidPserver;
   connectionState *state = &pc->state;
   SOCKET msgsock = pc->sock;
   Queue<WSmsg*,MAXMESSAGE>  *pWSq = &pc->WSq;           // create a pointer to the queue
   struct sockaddr_in from = pc->from;
   int fromlen = sizeof(from);

   WSmsg *wsmsg;
   int retval;
   while(*state > notConnected) {
      pthread_mutex_lock(&pc->send_mutex);
      while(!pWSq->empty()) {
         if(*state == notConnected) break;
         wsmsg = pWSq->front();
         pWSq->pop();
         retval = sendto(msgsock, wsmsg->raw.d,wsmsg->raw.l,0,(struct sockaddr *)&from,fromlen);
         if (retval == SOCKET_ERROR) {
             fprintf(stderr,"Server: send() failed: error %d\n", WSAGetLastError());
             goto error;
         } else
            wsmsg->busy = false;
      }
   } // while(*state > notConnected)

error:
   printf("Exit connectionClass::send, socket %d connection %d with %d connections open\n",msgsock,pc->id,prssServer->nConnection);
   pthread_exit(NULL);
   return NULL;
}
