// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

/* fft 2*1024*halfFftSp1024 samples for display */

#include <stdio.h>
#include <fftw3.h>
#include <math.h>

#include "pthread.h"
#include "spectrumUser.h"
#include "global.h"
#include "monitor.h"
#include "webServer.h"

spUserClass spUser;
extern int halfFftSp1024Max;

// allocate enough memory for maximum fft size as held in halfFftMax
void spUserClass::init( void ) {

   if(!g.server_mode) return; // do not use in server mode

   for(int n = 0; n < NSPUBUF; n++ ) {
      int len  = halfFftSp1024Max*1024;
      ALLOCATE_FFTWF(pyrOut[n],unsigned char *,maxLevel,spUserClass::init)
      ALLOCATE_FFTWF(insu[n],float*, maxLevel,spUserClass::init)
      for(int m = 0; m < maxLevel; m++ ) {
         ALLOCATE_FFTWF(insu[n][m],float,len,spUserClass::init)
         ALLOCATE(pyrOut[n][m],unsigned char,len,spUserClass::init)
         len = len/2;
      }
   }

   pthread_mutex_init(&mutexSpDataAvailable, NULL);
   pthread_mutex_lock(&mutexSpDataAvailable);

   pthread_mutex_init(&mutexSpControl, NULL);
   pthread_mutex_unlock(&mutexSpControl);

//    profC = new profileClassClass("spectrumUser");
//    profiler.registerClass(profC);

    for(int t = 0; t < NSPUTHREAD; t++) {
        int rc = pthread_create(&spectrum_user_thread[t], NULL, spectrumUser, (void *)this);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            getchar();
            printf("Hit any key to exit\n");
            exit(0);
        }
    }
}

void *spUserClass::spectrumUser( void *arg){
   spUserClass *pspUser = (spUserClass *) arg;
   pthread_t thisth = pthread_self();
   printf("spectrumUser %d pthread_self is %u\n",pspUser,thisth);

    float ***insu = pspUser->insu;                // fft input data pointer and loop pointer
    unsigned char ***pyrOut = pspUser->pyrOut;     // output short integer for display
    int *pidxBuf  = &pspUser->idxBuf;
    int maxLevel  = pspUser->maxLevel;

   int halfBuf = g.transferSize/sizeof(short)/2;   // half input buffer size

   float *inloop;
   unsigned char **outloop;
   float *inFftLoop, *outFftLoop, *outMagsqLoop;
   register float x;
   unsigned char *c;
   unsigned long *y;

   y = (unsigned long *)&x;
   c = (unsigned char *) y;
   c = c + 3;

//   profileThreadClass *profT = new profileThreadClass;
//   pspUser->profC->registerThread(profT);
//   profT->init();

   while(true) {
//      profT->wait();
      spectrum_user_element el = spUser.deQ(); // block on data available
//      profT->go();
      *pidxBuf = pspUser->incIdxBuf();

      //unpack
      float *spData = el.ptr;
      int len = el.len;
      float **pin = insu[*pidxBuf];

//      outMagsqLoop = pin[maxLevel-6];
      outloop = pyrOut[*pidxBuf];
		float off = 173-60;

      // load the buffers into the input
      memcpy(pin[0],spData,len*sizeof(float));
      int lim = len;
      for(int n = 0, m = 0; m < lim;m++) {
          x = pin[n][m]; *y = *y<<1; outloop[n][m] = *c;
      }
      for(int n = 1; n < maxLevel;n++) {
         lim = lim/2;
         pin[n][0] = pin[n-1][0]*.75 + pin[n-1][1]*.25;
         x = pin[n][0]; *y = *y<<1; outloop[n][0] = *c;
         for(int m = 1, k = 1; m < lim-2;m++,k+=2) {
             pin[n][m] = pin[n-1][k]*.25 + pin[n-1][k+1]*.5 + pin[n-1][k+2]*.25;
             x = pin[n][m]; *y = *y<<1; outloop[n][m] = *c;
         }
         pin[n][lim-1] = pin[n-1][lim-2]*.25 + pin[n-1][lim-1]*.75;
         x = pin[n][lim-1]; *y = *y<<1; outloop[n][lim-1] = *c;
      }

      int maxLen = pow(2,maxLevel);
WEBSERVERMUTEXCONNECTIONLIST_LOCK
		for(int m = 0; m < webServer.nConnection; m++) {
         if(webServer.connectionList[m]->state > notConnected) {
            connectionClass *pc = webServer.connectionList[m];
            if(pc->isOpen) {
//#ifdef U8NEW
#if 1
               int off_level = maxLevel -pc->parm.sp_header.zoom_level-4-round(log(g.webrx_fft_size_kHz)/log(2));
               int left = round(pc->parm.sp_header.left*1024*pow(2,pc->parm.sp_header.zoom_level));
               int hlen = sizeof(connectionClass::parmClass::sp_header);
               pc->sendWSData("FFT",(char *)&pc->parm.sp_header,hlen,(char*)&outloop[off_level][left], 1024*sizeof(char)*g.webrx_fft_size_kHz );
#else
               int off_level = maxLevel -4-round(log(g.webrx_fft_size_kHz)/log(2));
               pc->sendWSData("FFT",(char*)outloop[ off_level ], 1024*sizeof(char)*g.webrx_fft_size_kHz,spectrum );
#endif // U8NEW
            }
         }
      }

WEBSERVERMUTEXCONNECTIONLIST_UNLOCK
   } // while
   pthread_exit(NULL);
}
