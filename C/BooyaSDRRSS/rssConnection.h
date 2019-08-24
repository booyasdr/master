// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net
#ifndef RSSCONNECTION_H
#define RSSCONNECTION_H

#include <pthread.h>
#include <winsock2.h>
#include "connection.h"
#include "global.h"
#include "include/cWebSockets.h"

#define MSGLEN (16*1024)
#define MAXMESSAGE 100

//typedef struct{ char d[MSGLEN]; int l; } msg;
//typedef struct{ msg raw; msg ws; bool busy; } WSmsg;

//typedef enum{notConnected, http, handshake, WS} connectionState;

class rssConnectionClass {

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
   void *close(void );
   static void *receive(void *args);   // pass in this as thread argument
   static void *send(void *args);      // pass in this as thread argument

   int nstart, nend;

	class parmClass {
		public:
		float center_freq=16e6;
		float bandwidth=15e6;
		float fft_size=4096/4;
		float fft_fps=20;
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

	void RSSsendInit() {
      int halfFftSp1024 = round(g.fs/2./1000./500.);  // init spectrum global
      float x = halfFftSp1024*1024;
      parm.bandwidth = 15e6;
      parm.center_freq = 0    + parm.bandwidth/2;  // for test
      parm.center_freq = 15e6 + parm.bandwidth/2;
      double a = 2*parm.bandwidth/g.fs;
      parm.zoom_level = 0;

      for(int n = 0; (n<100)&&(x*a >= 512);n++) {
         x /= 2;
         parm.zoom_level = n+1;
         parm.fft_size = x*a;
      }

      double fend = parm.center_freq + parm.bandwidth/2;
      double df = g.fs/2/halfFftSp1024/1024*pow(2,parm.zoom_level);
      nend   = round(fend/df);
      nend = (nend < parm.fft_size ? parm.fft_size : nend);

      char s[512];
//      sprintf(s,"F 22500000|S 15000000|O 0|C %.0f|",parm.fft_size);
      sprintf(s,"F %.0f|S %.0f|O 0|C %.0f|",parm.center_freq,parm.bandwidth,parm.fft_size);
      printf("RSS: %s  zoom_level %d, nend %d\n",s,parm.zoom_level,nend);
      WSmsg* msghs = newMsg();
      strcpy(msghs->raw.d,s);
      msghs->raw.l = strlen(msghs->raw.d);
      WSq.push(msghs);
      pthread_mutex_unlock(&send_mutex);

      Sleep(200);
      isOpen = true;
   }
	void RSSsendData( unsigned char **outloop ) {
      unsigned short x[1024];
      WSmsg* msghs = newMsg();
      if(!msghs) {
         printf("RSSsendData Overflow\n");
         return;
      }
      int N = parm.fft_size;
      int Nbyte = 2*N+2;
      for(int n = 0; n <N;n++) {
         x[n] = outloop[6][nend-n]-150;
      }
      x[N] = 0xfe; x[N+1] = 0xfe;
      memcpy(msghs->raw.d,x,Nbyte);
      msghs->raw.l = Nbyte;
      WSq.push(msghs);
      pthread_mutex_unlock(&send_mutex);
   }
};

#endif

