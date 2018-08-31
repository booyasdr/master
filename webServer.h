// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include "global.h"
#include "connection.h"
#define DEFAULT_PORT 2008

#define MUTEXCONNECTIONLIST_LOCK
#define MUTEXCONNECTIONLIST_UNLOCK
#define WEBSERVERMUTEXCONNECTIONLIST_LOCK
#define WEBSERVERMUTEXCONNECTIONLIST_UNLOCK
#define MUTEXCONNECTIONLIST_INIT

#define MUTEXCONNECTIONLIST_LOCK      pthread_mutex_lock(&mutexConnnectionList);
#define MUTEXCONNECTIONLIST_UNLOCK      pthread_mutex_unlock(&mutexConnnectionList);
#define WEBSERVERMUTEXCONNECTIONLIST_LOCK      pthread_mutex_lock(&webServer.mutexConnnectionList);
#define WEBSERVERMUTEXCONNECTIONLIST_UNLOCK      pthread_mutex_unlock(&webServer.mutexConnnectionList);
#define MUTEXCONNECTIONLIST_INIT \
		 pthread_mutex_init(&mutexConnnectionList, NULL); \
		 pthread_mutex_unlock(&mutexConnnectionList);

class webServerClass {

   pthread_t serverStatus_thread;
   pthread_t listener_thread;

   static void *serverStatus(void *arg);
   static void* listener(void *args);
   connectionClass* newConnection(SOCKET msgsock,struct sockaddr_in *pfrom);

   public:
   pthread_mutex_t mutexConnnectionList;

   int maxConnection;
   int nConnection = 0;
   void closeConnection(connectionClass* pc);

   connectionClass *connection;
   connectionClass **connectionList;

   class listenerInputClass {
      public:
      char in_app[256];
      char address[256];
      unsigned short in_port;
   } listenerInput;

   int initOne(char *in_app, char *address, unsigned short in_port) {

      maxConnection = g.maxConnection;
      connection = new connectionClass[maxConnection];
      connectionList = (connectionClass **) malloc(sizeof(connectionClass)*maxConnection);
      memset( connectionList,'/0',sizeof(connectionClass)*maxConnection);

     strcpy(listenerInput.in_app,in_app);
     strcpy(listenerInput.address,address);
     listenerInput.in_port = in_port;

      MUTEXCONNECTIONLIST_INIT

     pthread_create(&listener_thread , NULL, listener, (void *) this);
     pthread_create(&serverStatus_thread , NULL, serverStatus, (void *) this);
  }

   int init(char *in_app, char *address, unsigned short in_port) {
      initOne(in_app, address, in_port);
   }

   int init(void) {
     char *ip_address= (char *) "127.0.6.1";
     unsigned short port=DEFAULT_PORT;
     initOne((char *)"default", ip_address, port);
   }
};

extern webServerClass webServer;

#endif

