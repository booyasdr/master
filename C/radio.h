// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef RADIO_H
#define RADIO_H

#include <pthread.h>
#include "fftw3.h"
#include "global.h"
#include "monitor.h"

#define N_RADIO_THREAD 3
#define N_DEC_BUF 10

class radioClass {
    float ***inDec;             // point to each threads decimation input buffers
    fftwf_complex ***outDec;    // decimation output buffer per thread
    unsigned short **overlapData;        // data that overlaps form one thread call to another size = halfFft
    fftwf_plan **pdec;          // fftw plan buffers per thread per buffer
    float *wndw;                // window variables

    pthread_t radio_thread[N_RADIO_THREAD];  // radio thread descriptor pointer

    pthread_mutex_t mutexRadioDataAvailable; // unlock to signal data available
    pthread_mutex_t mutexRadioControl;       // radio control lock

public:
   int fftPerBuf;              // number of decimation fft per input buffer
   int halfFft   = 256;      // half the size of the first decimation stage fft

   bool radioOn;    // radio on flag
   int lastBufIdx;  // index to next decimation (1st stage) buffer to be processed
   double processGain = 1; // amplitude gain of signal processing

   Queue<int,30> Q;
   void init( void );
   static void *radiof(void *arg);

   void radioTurnOn(void);
   void radioTurnOff(void);
   bool radioIsOn(void);

   void enQ(int idx) { // signal new data arrived
      if(!radioOn) return;
      pthread_mutex_lock (&mutexRadioControl);
      Q.push(idx);
      pthread_mutex_unlock (&mutexRadioDataAvailable); // signal data available
      pthread_mutex_unlock (&mutexRadioControl);
   }
//    profileClassClass *profC;

};

extern class radioClass radio;
#endif
