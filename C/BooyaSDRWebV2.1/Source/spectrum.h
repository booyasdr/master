// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef SPECTRUM_H
#define SPECTRUM_H

#include "global.h"
#include "monitor.h"
#include <pthread.h>

typedef struct {
    int inidx;  // input buffer index
    int didx;   // spectrum display index
    int spbuf;  // spectrum buffer index
    void set(int a, int b, int c){inidx = a; didx = b; spbuf = c;};
} spectrum_element;

#define NSPTHREAD 3
#define NSPOUTBUF 4
// make the number of threads NSPTHREAD equal to the number of spectrum buffers

class spectrumClass {

   pthread_mutex_t mutexSpectrumDataAvailable; // unlock to signal data available
   pthread_mutex_t mutexSpectrumControl;       // radio control lock

   double display_period = .064;    // display update period in seconds

   long midx = 0;                   // main loop index
   long midx_period =2;             // number of main loop transfers per fft calls, reset in initPeriod()
   long didx = 0;                   // spectrum display index
   long didx_frequency = 16;        // number of fft calls per display update, reset in initPeriod()

   fftwf_plan ps[NSPTHREAD];       // fft plan
   float **ins;                    // fft input data pointer and loop pointer
   float *wndws;                   // window variables
   fftwf_complex **outs;           // output buffer

   pthread_t spectrum_thread[NSPTHREAD];
   pthread_mutex_t mutexSpMagsq;   // spectrum output

#define N_OUT_MAG 8
   float **outMagsq;               // output magnitude squared pointer
   int idxMag = 0;
//    profileClassClass *profC;
   unsigned short *spOutData[NSPOUTBUF];   // output short integer for display
   int inidx = 0;
   int outidx = 0;

public:
   unsigned short *nextLocalOut(void){
      unsigned short *out = spOutData[outidx++];
      outidx %= NSPOUTBUF;
      return out;
   }      // output short integer for display

   static void *spectrumf(void *arg);
   bool init( void );
   bool initSpectrumf( void );
   bool sizeSpectrumf( int newHalfFftSp1024 );

    void initPeriod(void) {
        if (g.fs ==  16e6) didx_frequency = 32;
        if (g.fs ==  64e6) didx_frequency = 16;
        if (g.fs == 100e6) didx_frequency = 16;

        double ml_period  = // main loop transfer time interval (seconds)
            (double)g.transferSize / (double)g.fs / (double)sizeof(short);
        midx_period =   // integer number of main loop transfer calls per spectrum call
            round((double)display_period / (double)didx_frequency/ ml_period);
        midx_period = ( midx_period < 1 ? 1 :   midx_period );
        double actual_display_period = didx_frequency*midx_period*ml_period;
        printf("Spectrum display period requested %f s actual %f s, midx_period %d, didx_frequency %d\n",
               display_period,actual_display_period,midx_period,didx_frequency);
        printf("Spectrum call period %d mlcall, %f s, mlcall period %f s\n",
               midx_period,midx_period*ml_period,ml_period);

        pthread_mutex_init(&mutexSpectrumDataAvailable, NULL);
        pthread_mutex_lock(&mutexSpectrumDataAvailable);

        pthread_mutex_init(&mutexSpectrumControl, NULL);
        pthread_mutex_unlock(&mutexSpectrumControl);
    }

    PUCHAR *buffers;                // pointer to all input buffers
    spectrum_element sp_el;
    Queue<spectrum_element,30> Q;
    int spbuf = 0;                  // spectrum buffer index
    long ti[NSPTHREAD];             // static storage for thread index

    void enQ(int inidx){ // call from main loop
        if(g.pause) return;
        pthread_mutex_lock(&mutexSpectrumControl);          // lock control data
        midx++;
        midx %= midx_period;
        if(midx != 0) {
            pthread_mutex_unlock(&mutexSpectrumControl);      // unlock control data
            return;
        }
        didx = (didx+1)%didx_frequency; // cycle spectrum.idx

// push a new element onto the spectrum processing queue
        sp_el.set(inidx, didx, spbuf);
        Q.push(sp_el);
        spbuf = (spbuf+1)%NSPTHREAD;

        pthread_mutex_unlock(&mutexSpectrumDataAvailable);  // signal data available
        pthread_mutex_unlock(&mutexSpectrumControl);      // unlock control data
    };

    spectrum_element deQ(void) { // call from thread
        spectrum_element el;
        pthread_mutex_lock(&mutexSpectrumDataAvailable);  // block on data available
        pthread_mutex_lock(&mutexSpectrumControl);          // lock control data

        el = Q.front();
        Q.pop();
        if(!Q.empty())
            pthread_mutex_unlock(&mutexSpectrumDataAvailable); // more data in queue, unblock threads
        pthread_mutex_unlock(&mutexSpectrumControl);        // unlock control data
        return el;
    };

    void reset(void){
        pthread_mutex_lock(&mutexSpectrumControl);          // lock control data
        midx = 0;
        didx = 0;
        while(!Q.empty()) Q.pop();
        pthread_mutex_unlock(&mutexSpectrumControl);      // unlock control data
    };
};

extern spectrumClass spectrum;
extern int halfFftSp1024Max;            // maximum half fft in units of 1024
extern int halfFftSp1024;               // make available for ini


#endif

