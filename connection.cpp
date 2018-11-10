// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net
#include "global.h"
#include <winsock2.h>
#include <pthread.h>
#include "connection.h"
#include "radio.h"
#include "webServer.h"

void *connectionClass::init(void *args){
    webServerClass *pwebServer = (webServerClass *)args; // pc, pointer to connection
    voidPserver = (void *) pwebServer;    // set pointer back to server

    // initialize the found connection
    while(!WSq.empty()) WSq.pop();
    memset(msgPool,'\0',sizeof(WSmsg)*MAXMESSAGE);

    pthread_mutex_init(&send_mutex, NULL);
    pthread_mutex_lock(&send_mutex);

    pthread_cancel(send_thread);     // cancel threads incase they were left hanging
    pthread_cancel(receive_thread);

    state = http;

   if(!ru) ru = new radioUserClass(this);

    pthread_create(&send_thread   , NULL, send   , (void *) this);
    pthread_create(&receive_thread, NULL, receive, (void *) this);
}

void* connectionClass::receive(void *args) {
    connectionClass *pc = (connectionClass *)args; // pc, pointer to connection
    webServerClass *pwebServer = (webServerClass *) pc->voidPserver; // point back to server
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
        wsmsgRcv.ws.l = retval;
        if (retval == SOCKET_ERROR) {
            fprintf(stderr,"Server: recv() failed: error %d socket %d connection %d of %d.\n", WSAGetLastError(),msgsock,pc->id,pwebServer->nConnection);
            break;
        } else if (retval == 0) {
            printf("Server: Client closed connection zero byte return, socket %d connection %d of %d.\n",msgsock,pc->id,pwebServer->nConnection);
            break;
        }
        if((wsmsgRcv.ws.d[0]&0xf) == 0x08) { // close opcode
            printf("Server: Client closed connection by opcode, socket  %d connection %d of %d.\n",msgsock,pc->id,pwebServer->nConnection);
            break;
        }
        strncpy(wsmsgRcv.raw.d,wsmsgRcv.ws.d,wsmsgRcv.ws.l);
        wsmsgRcv.raw.d[wsmsgRcv.ws.l] = '\0';

        switch(*state) {
            case http:
                if( WEBSOCKET_valid_connection( wsmsgRcv.ws.d ) ) {
                    *state = handshake; // increment state
                    WSmsg* msghs = pc->newMsg();
                    WEBSOCKET_generate_handshake( wsmsgRcv.ws.d, msghs->ws.d, MSGLEN );
                    msghs->ws.l = strlen(msghs->ws.d);
                    strcpy(msghs->raw.d,msghs->ws.d);
                    msghs->raw.l = msghs->ws.l;
                    pWSq->push(msghs);
                    pthread_mutex_unlock(&pc->send_mutex);
                } else goto Default;
                break;
            case handshake:{
                int len = WEBSOCKET_get_content( wsmsgRcv.ws.d, retval, (unsigned char *)wsmsgRcv.raw.d, MSGLEN );
                wsmsgRcv.raw.d[len] = '\0';
                if(!strcmp(wsmsgRcv.raw.d,"SERVER DE CLIENT openwebrx.js")) {
                        *state = WS; // increment state
                    WSmsg* msgcds = pc->newMsg();
                    strcpy(msgcds->raw.d , "CLIENT DE SERVER BooyaSDR");
                    msgcds->raw.l = strlen(msgcds->raw.d);
                    msgcds->ws.l = WEBSOCKET_set_content( msgcds->raw.d, msgcds->raw.l,
                          (unsigned char *)msgcds->ws.d, MSGLEN );
                    pWSq->push(msgcds);

                    pthread_mutex_unlock(&pc->send_mutex);
                    printf("%2X %2x %2x %2x\n",wsmsgRcv.ws.d[0]&0xff,wsmsgRcv.ws.d[1]&0xff,
                           wsmsgRcv.ws.d[2]&0xff,wsmsgRcv.ws.d[3]&0xff);
        // MSG
                    connectionClass::parmClass *cparm = &pc->parm;
                    cparm->center_freq=16e6;
                    cparm->bandwidth=g.fs/2;
                    cparm->fft_size=1024*g.webrx_fft_size_kHz;
                    cparm->fft_fps=32;
                    #ifdef COMPRESS_AUDIO
                    cparm->audio_compression = "adpcm";
                    #else
                    cparm->audio_compression = "none";
                    #endif

                    #ifdef U8NEW
                    cparm->fft_compression   = "u8new";
                    #else
                    cparm->fft_compression   = "u8bit";
                    #endif

                    sprintf(text,"center_freq=%.2f bandwidth=%.2f fft_size=%.2f fft_fps=%.2f audio_compression=%s "
                        "fft_compression=%s max_clients=%d setup ",
                        cparm->center_freq,cparm->bandwidth,cparm->fft_size,cparm->fft_fps,cparm->audio_compression
                        ,cparm->fft_compression,pwebServer->maxConnection);
                        printf(text);
                        printf("%d\n",pc);
                    pc->sendWSData((char*)"MSG",(char *) text, strlen(text));
                } else goto Default;
                break;
            }
        case WS: {
            int len = WEBSOCKET_get_content( wsmsgRcv.ws.d, retval, (unsigned char *)wsmsgRcv.raw.d, MSGLEN );
            wsmsgRcv.raw.d[len] = '\0';
            if(char *s = strstr(wsmsgRcv.raw.d,"SET")) {
                if(char *f = strstr(s,"mod=")) {
                    f += strlen("mod=");
                    if(!strncmp(f,"am",2)) {
                        pc->ru->mode = AM;
                    } else if(!strncmp(f,"lsb",3)){
                        pc->ru->mode = LSB;
                    } else if(!strncmp(f,"usb",3)){
                        pc->ru->mode = USB;
                    } else if(!strncmp(f,"cw",2)){
                        pc->ru->mode = CW;
                    }
                }
                if(char *f = strstr(s,"zoom=")) {
                    f += strlen("zoom=");
                    sscanf(f,"%d",&pc->parm.sp_header.zoom_level);
                    if( f = strstr(f,"left=")) {
                        f += strlen("left=");
                        sscanf(f,"%f",&pc->parm.sp_header.left);
                    }
//                    printf("SET zoom check. zoom= %d left = %f\n",pc->parm.sp_header.zoom_level,pc->parm.sp_header.left);
                }
                if(char *f = strstr(s,"offset_freq")) {
                    f += strlen("offset_freq=");
                    float offset_freq;
                    sscanf(f,"%f",&offset_freq);
                    pc->ru->tunekHz = (pc->parm.center_freq + offset_freq)/1000.;
                }
                if(char *f = strstr(s,"output_rate")) {
                    f += strlen("output_rate=");
                    int output_rate;
                    sscanf(f,"%d",&output_rate);
                    pc->ru->sampleRate = output_rate;
                }
                if(strstr(s,"start")) {
                    if(!radio.radioIsOn()) radio.radioTurnOn();
                    pc->ru->init();
                    pc->isOpen = true;
                    printf("start\n");
                }
            }
            break;
        } default:
Default:     int len = WEBSOCKET_get_content( wsmsgRcv.ws.d, retval, (unsigned char *)wsmsgRcv.raw.d, MSGLEN );
            wsmsgRcv.raw.d[len] = '\0';
            printf("%2X %2x %2x %2x\n",wsmsgRcv.ws.d[0]&0xff,wsmsgRcv.ws.d[1]&0xff,
                   wsmsgRcv.ws.d[2]&0xff,wsmsgRcv.ws.d[3]&0xff);
            printf("Received Sock %d conn %d addr %s port %d WS msg:\n%s\n",
                   msgsock,pc->id, inet_ntoa(from.sin_addr), ntohs(from.sin_port),wsmsgRcv.raw.d);

        }
    } // while(*state > notConnected)
    pwebServer->closeConnection(pc);
    pthread_exit(NULL);
}

void *connectionClass::send(void *args) {
   connectionClass *pc = (connectionClass *)args;
   webServerClass *pwebServer = (webServerClass *) pc->voidPserver;
   connectionState *state = &pc->state;
   SOCKET msgsock = pc->sock;
   pthread_mutex_t send_mutex = pc->send_mutex;
   Queue<WSmsg*,MAXMESSAGE>  *pWSq = &pc->WSq;           // create a pointer to the queue
   struct sockaddr_in from = pc->from;
   int fromlen = sizeof(from);
   unsigned long msgCount = 0, ioPeriod = 10;

   WSmsg *wsmsg;
   int retval;
   while(*state > notConnected) {
      pthread_mutex_lock(&send_mutex);
      while(!pWSq->empty()) {
         if(*state == notConnected) break;
         wsmsg = pWSq->front();
         pWSq->pop();
         retval = sendto(msgsock, wsmsg->ws.d,wsmsg->ws.l,0,(struct sockaddr *)&from,fromlen);
         if (retval == SOCKET_ERROR) {
             fprintf(stderr,"Server: send() failed: error %d\n", WSAGetLastError());
             goto error;
         } else
            wsmsg->busy = false;
      }
   } // while(*state > notConnected)

error:
   pwebServer->closeConnection(pc);
   printf("Disconnect socket %d connection %d with %d connections open\n",msgsock,pc->id,pwebServer->nConnection);
   pthread_exit(NULL);
   return NULL;
}
