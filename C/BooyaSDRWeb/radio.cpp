// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

/*
The radio demodulation is done in three stages which are:

Decimation - subband signal from 1 channel fs real,
to halfFft channels, fs/halfFft rate complex signal
fs - sampling rate
halfFft - half the decimation fft length
fs2 = fs/halfFft

Tuning - fft samples from one fs2 rate bands for fine tuning.

Base band - ifft the samples to zero carrier frequency at the sound sample rate.

Base band demodulate - AM square root of the complex magnitude, SSB take the real part
(or imaginary part).

The first stage decimates fs rate real signal into fs2 rate complex bands
spaced  fs2/2 apart. The buffer size is 131072 bytes or 65536 samples each which covers
about 65536/fs time. The first stage fft length is 2048. This fft is 50% overlapped.
The second stage sample rate is then 2fs/2048.

This code uses global variables instead of a classes for compatibility
with pthreads. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "radio.h"
#include "radioUser.h"
#include "global.h"
#include "monitor.h"
#include "main_loop.h"      // for idx, buffers
#include "webServer.h"

class radioClass radio;

void radioClass::radioTurnOn(void) {
    pthread_mutex_lock (&mutexRadioControl);
    while(!Q.empty())Q.pop();
    radioOn = true;
    pthread_mutex_unlock (&mutexRadioControl);
}

void radioClass::radioTurnOff(void) {
    radioOn = false;
    while(!Q.empty())Q.pop();
}

bool radioClass::radioIsOn(void){ return(radioOn); }

void radioClass::init( void ) {
   fftPerBuf = g.transferSize / sizeof(short) /halfFft; // number of ffts per buffer in the first stage

   pdec = (fftwf_plan **) malloc(sizeof(fftwf_plan *) * N_DEC_BUF);
   inDec  = (float***) malloc(sizeof(float**) * N_DEC_BUF);
   outDec = (fftwf_complex***) fftwf_malloc(sizeof(fftwf_complex *) * N_DEC_BUF);
   overlapData = (unsigned short **) malloc(sizeof(unsigned short *) * N_DEC_BUF);

   for(int ndb = 0; ndb < N_DEC_BUF; ndb++) {
      pdec[ndb] = (fftwf_plan *)  malloc(sizeof(fftwf_plan) * fftPerBuf);

      ALLOCATE(inDec[ndb],float*,fftPerBuf,radioClass::init)
      ALLOCATE_FFTWF(outDec[ndb],fftwf_complex*, fftPerBuf,radioClass::init)

      for(int n = 0; n < fftPerBuf; n++) {
         ALLOCATE_FFTWF(inDec[ndb][n],float,2 * halfFft,radioClass::init)
         ALLOCATE_FFTWF(outDec[ndb][n],fftwf_complex, 2 * halfFft, radioClass::init)
      }
      for(int n = 0; n < fftPerBuf; n++)
         if(!( pdec[ndb][n] = fftwf_plan_dft_r2c_1d(2*halfFft, inDec[ndb][n], outDec[ndb][n],0))) {
            printf("FFTW plan creation failed pdec[%d][%d] in radioClass::init",ndb,n);
            getchar();
            printf("Press any key to exit\n");
            exit(0);
         }
      overlapData[ndb] = (unsigned short *) malloc(sizeof(unsigned short) * halfFft);
      ZeroMemory(overlapData[ndb], sizeof(short) * halfFft);
   }

   wndw   = (float*) fftwf_malloc(sizeof(float) * 2 * halfFft); // decimation stage window

   double N = 2*halfFft -1;
   double pi = 4*atan(1);
   double wndwSum = 0;
   for(int n = 0; n < halfFft; n++) {
      wndw[2*halfFft - n - 1] = wndw[n] = (.42-.5*cos(2*pi*n/N)+.08*cos(4*pi*n/N)); // Blackman
      wndwSum += 2*wndw[n];
   }

   processGain = wndwSum/2; // amplitude gain of the first FFT, divide by 2 since half of spectrum is discardedk
   lastBufIdx = 0;

   pthread_mutex_init(&mutexRadioDataAvailable, NULL);
   pthread_mutex_lock(&mutexRadioDataAvailable);

   pthread_mutex_init(&mutexRadioControl, NULL);
   pthread_mutex_unlock(&mutexRadioControl);

//   profC = new profileClassClass("radio");
//   profiler.registerClass(profC);

   for(int n = 0; n < N_RADIO_THREAD; n++) {
      int rc = pthread_create(&radio_thread[n], NULL, radiof, (void *) this);
      if (rc)  printf("ERROR; return code from pthread_create() is %d\n", rc);
   }
}

#define DC 32768

void *radioClass::radiof(void *arg) {
   radioClass *pradio = (radioClass *) arg;
   printf("radiof %x pthread_self is %u\n",(int)pradio,pthread_self());
   pthread_mutex_t *pmutexRadioDataAvailable = &pradio->mutexRadioDataAvailable;
   pthread_mutex_t *pmutexRadioControl = &pradio->mutexRadioControl;

   float ***inDec = pradio->inDec;
   fftwf_complex ***outDec = pradio->outDec;    // decimation output buffer per thread
   unsigned short **overlapData = pradio->overlapData;   // data that overlaps form one thread call to another size = halfFft
   fftwf_plan **pdec = pradio->pdec;            // fftw plan buffers per thread per buffer
   float   *wndw  = pradio->wndw;

   int fftPerBuf = pradio->fftPerBuf;           // number of decimation fft per input buffer
   int halfFft   = pradio->halfFft;             // half the size of the first decimation stage fft

   long lastDecBufIdx = 0;
   long thisDecBufIdx = 0;
   char *buffer;

//   profileThreadClass *profT = new profileThreadClass;
//   pradio->profC->registerThread(profT);
//   profT->init();

    while(true) {
//			profT->wait();
      pthread_mutex_lock(pmutexRadioDataAvailable);  // block here
//			profT->go();

      pthread_mutex_lock(pmutexRadioControl);
      if(pradio->Q.empty()) { //sanity check
         pthread_mutex_unlock(pmutexRadioControl);
         continue;
      }

      int inidx = pradio->Q.front();
      pradio->Q.pop();
      buffer = (char *) buffers[inidx];

      lastDecBufIdx = pradio->lastBufIdx;
      thisDecBufIdx = (lastDecBufIdx+1) % N_DEC_BUF;
      pradio->lastBufIdx = thisDecBufIdx;
      pthread_mutex_unlock(pmutexRadioControl);

      if(!pradio->Q.empty())
         pthread_mutex_unlock(pmutexRadioDataAvailable);

      unsigned short *dataloop; // pointer to input data
      float *inloop;            // pointer to first fft input buffer

      inloop = inDec[thisDecBufIdx][0];
      dataloop = overlapData[lastDecBufIdx];  // restore overlap
      for(int m = 0; m < halfFft;) {
         inloop[m] = (dataloop[m] - DC)*wndw[m]; m++;
         inloop[m] = (dataloop[m] - DC)*wndw[m]; m++;
         inloop[m] = (dataloop[m] - DC)*wndw[m]; m++;
         inloop[m] = (dataloop[m] - DC)*wndw[m]; m++;
      }
      dataloop = (unsigned short *) buffer;
      inloop = inDec[thisDecBufIdx][0] + halfFft;  // finish load dec input 0
      for(int m = 0; m < halfFft;) {
         inloop[m] = (dataloop[m] - DC)*wndw[m]; m++;
         inloop[m] = (dataloop[m] - DC)*wndw[m]; m++;
         inloop[m] = (dataloop[m] - DC)*wndw[m]; m++;
         inloop[m] = (dataloop[m] - DC)*wndw[m]; m++;
      }
      dataloop = (unsigned short *) buffer; // load dec input 1 to end
      for(int k = 1;k < fftPerBuf;k++) {
         inloop = inDec[thisDecBufIdx][k];
         for(int m = 0 ; m < 2*halfFft;) {
             inloop[m] = (dataloop[m] - DC)*wndw[m++];
             inloop[m] = (dataloop[m] - DC)*wndw[m++];
             inloop[m] = (dataloop[m] - DC)*wndw[m++];
             inloop[m] = (dataloop[m] - DC)*wndw[m++];
         }
         dataloop = dataloop + halfFft;
      }
      memcpy(overlapData[thisDecBufIdx],dataloop,halfFft*sizeof(short)); // save overlap

      for(int k = 0; k < fftPerBuf;k++)
         fftwf_execute(pdec[thisDecBufIdx][k]);                         // FFT first stage

      if(localRadioUser.mode != Silent)
         localRadioUser.enQ(outDec[thisDecBufIdx], 0);            // signal demod
      if(g.server_mode){
         WEBSERVERMUTEXCONNECTIONLIST_LOCK
         for(int n = 0; n < webServer.nConnection; n++)
            if(webServer.connectionList[n]->isOpen)
               webServer.connectionList[n]->ru->enQ(outDec[thisDecBufIdx], 0); // signal demod
         WEBSERVERMUTEXCONNECTIONLIST_UNLOCK
      }
   }
}
