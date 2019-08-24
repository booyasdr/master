// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef RSS_SERVER_H
#define RSS_SERVER_H

#include "global.h"
#include "rssConnection.h"
#define DEFAULT_PORT 8888

#define MUTEXCONNECTIONLIST_LOCK
#define MUTEXCONNECTIONLIST_UNLOCK
#define WEBSERVERMUTEXCONNECTIONLIST_LOCK
#define WEBSERVERMUTEXCONNECTIONLIST_UNLOCK
#define MUTEXCONNECTIONLIST_INIT

#define MUTEXCONNECTIONLIST_LOCK      pthread_mutex_lock(&mutexConnnectionList);
#define MUTEXCONNECTIONLIST_UNLOCK      pthread_mutex_unlock(&mutexConnnectionList);
#define RSSSERVERMUTEXCONNECTIONLIST_LOCK      pthread_mutex_lock(&rssServer.mutexConnnectionList);
#define RSSSERVERMUTEXCONNECTIONLIST_UNLOCK      pthread_mutex_unlock(&rssServer.mutexConnnectionList);
#define MUTEXCONNECTIONLIST_INIT \
		 pthread_mutex_init(&mutexConnnectionList, NULL); \
		 pthread_mutex_unlock(&mutexConnnectionList);

class rssServerClass {

//   pthread_t serverStatus_thread;
   pthread_t listener_thread;

   static void *serverStatus(void *arg);
   static void* listener(void *args);
   rssConnectionClass* newConnection(SOCKET msgsock,struct sockaddr_in *pfrom);

   public:
   pthread_mutex_t mutexConnnectionList;

   int maxConnection;
   int nConnection = 0;
   void closeConnection(rssConnectionClass* pc);

   rssConnectionClass *connection;
   rssConnectionClass **connectionList;

   class listenerInputClass {
      public:
      char in_app[256];
      char address[256];
      unsigned short in_port;
   } listenerInput;

   int initOne(char *in_app, char *address, unsigned short in_port) {

      maxConnection = g.maxConnection;
      connection = new rssConnectionClass[maxConnection];
      connectionList = (rssConnectionClass **) malloc(sizeof(rssConnectionClass)*maxConnection);
      memset( connectionList,'/0',sizeof(rssConnectionClass)*maxConnection);

     strcpy(listenerInput.in_app,in_app);
     strcpy(listenerInput.address,address);
     listenerInput.in_port = in_port;

      MUTEXCONNECTIONLIST_INIT

     pthread_create(&listener_thread , NULL, listener, (void *) this);
//     pthread_create(&serverStatus_thread , NULL, serverStatus, (void *) this);
  }

   int init(char *in_app, char *address, unsigned short in_port) {
      initOne(in_app, address, in_port);
   }

   int init(void) {
     char *ip_address= (char *) "127.0.0.1";
     unsigned short port=DEFAULT_PORT;
     initOne((char *)"default", ip_address, port);
   }
};

extern rssServerClass rssServer;

#endif

