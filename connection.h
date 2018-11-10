// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net
#ifndef CONNECTION_H
#define CONNECTION_H

#include <pthread.h>
#include <winsock2.h>
#include "radioUser.h"
#include "include/cWebSockets.h"

#define MSGLEN (16*1024)
#define MAXMESSAGE 100

typedef struct{ char d[MSGLEN]; int l; } msg;
typedef struct{ msg raw; msg ws; bool busy; } WSmsg;

typedef enum{notConnected, http, handshake, WS} connectionState;

class connectionClass {

	public:
	class radioUserClass *ru = NULL;    // initialize NULL
	int id;
	SOCKET sock;
	struct sockaddr_in from;
	connectionState state = notConnected;
	bool isOpen;
	pthread_t receive_thread;
	pthread_t send_thread;
	pthread_mutex_t    send_mutex;
	Queue<WSmsg*,MAXMESSAGE> WSq;
	WSmsg msgPool[MAXMESSAGE];
	void *voidPserver;

   void *init(void *args);      // pass in webServer pointer
   static void *receive(void *args);   // pass in this as thread argument
   static void *send(void *args);      // pass in this as thread argument

	class parmClass {
		public:
		float center_freq=16e6;
		float bandwidth=32e6;
		float fft_size=4096/4;
		float fft_fps=20;
		char *audio_compression=(char *)"none";
		char *fft_compression=(char *)"none";
		int zoom_level = 0;
		double left = 0;
		struct sp_header{
			unsigned int zoom_level;
			float left;
		} sp_header;
	} parm;

	WSmsg* newMsg( void ) {
	  int n;
	  for( n = 0; n < MAXMESSAGE; n++)
			if(!msgPool[n].busy) break;
	  if( n >= MAXMESSAGE) {
			printf("Message pool overflow\n");
			return NULL;
	  }
	  WSmsg* pmsg = &msgPool[n];
	  memset(pmsg,'\0', sizeof(WSmsg));
	  pmsg->busy = true;
	  return pmsg;
	}

	void sendWSData(char *trigraph, char *data,int NByte) {
	  WSmsg* msg = newMsg();
	  if(!msg) return;
	  strcpy(msg->raw.d,trigraph);
	  strcat(msg->raw.d," ");

	  memcpy(&msg->raw.d[4],data,NByte);
	//        msg->raw.l = strlen(msg->raw.d)+1 + NByte;
	  msg->raw.l = 4 + NByte;
	  msg->ws.l = WEBSOCKET_set_content( msg->raw.d, msg->raw.l,
	  (unsigned char *) msg->ws.d, MSGLEN );
	  WSq.push(msg);
	  pthread_mutex_unlock(&send_mutex);
	}

	void sendWSData(char *trigraph, char *hdr,int NhdrByte, char *data,int NByte) {
	  WSmsg* msg = newMsg();
	  if(!msg) return;
	  strcpy(msg->raw.d,trigraph);
	  strcat(msg->raw.d," ");

	  memcpy(&msg->raw.d[4],hdr,NhdrByte);
	  memcpy(&msg->raw.d[4+NhdrByte],data,NByte);
	//        msg->raw.l = strlen(msg->raw.d)+1 + NByte;
	  msg->raw.l = 4 + NhdrByte + NByte;
	  msg->ws.l = WEBSOCKET_set_content( msg->raw.d, msg->raw.l,
	  (unsigned char *) msg->ws.d, MSGLEN );
	  WSq.push(msg);
	  pthread_mutex_unlock(&send_mutex);
	}
};

#endif

