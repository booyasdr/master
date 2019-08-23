// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef SPECTRUM_H
#define SPECTRUM_H

#include "global.h"
#include <pthread.h>

typedef struct {
    int inidx;  // input buffer index
    int didx;   // spectrum display index
    int spbuf;  // spectrum buffer index
    void set(int a, int b, int c){inidx = a; didx = b; spbuf = c;};
} spectrum_element;

#define NSPTHREAD 4
// make the number of threads NSPTHREAD equal to the number of sp buffers

class spClass {

    pthread_mutex_t mutexSpectrumDataAvailable; // unlock to signal data available
    pthread_mutex_t mutexSpectrumControl;       // radio control lock

    double display_period = .064;    // display update period in seconds

    long midx = 0;                   // main loop index
    long midx_period =2;             // number of main loop transfers per spectrum calls, reset in initPeriod()
    long didx = 0;                   // spectrum display index
    long didx_frequency = 16;        // number of fft calls per display update period, reset in initPeriod()

public:
    void initPeriod(void) {
        if (global.fs ==  16e6) didx_frequency = 32;
        if (global.fs ==  64e6) didx_frequency = 32;
        if (global.fs == 100e6) didx_frequency = 16;

        double ml_period  = // time interval (seconds)
            (double)global.transferSize / (double)global.fs / (double)sizeof(short);
        midx_period =   // integer number of ml calls per spectrum call
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
    Queue<spectrum_element,15> spQ;
    int spbuf = 0;                  // spectrum buffer index
    long ti[NSPTHREAD];             // static storage for thread index

    void mainDataAvailable(int inidx){ // call from main loop
        if(global.pause) return;
        if(!global.run) return;
        pthread_mutex_lock(&mutexSpectrumControl);          // lock control data
        midx++;
        midx %= midx_period;
        if(midx != 0) {
            pthread_mutex_unlock(&mutexSpectrumControl);      // unlock control data
            return;
        }
        didx = (didx+1)%didx_frequency; // cycle sp.idx

// push a new element onto the spectrum processing queue
        sp_el.set(inidx, didx, spbuf);
        spQ.push(sp_el);
        spbuf = (spbuf+1)%NSPTHREAD;

//        printf("didx %d, midx %d, next %d, current %d, spbuf %d\n",
//              didx,midx,next,current,spbuf);
        pthread_mutex_unlock(&mutexSpectrumDataAvailable);  // signal data available
        pthread_mutex_unlock(&mutexSpectrumControl);      // unlock control data
    };

    spectrum_element process(void) { // call from thread
        spectrum_element el;
        pthread_mutex_lock(&mutexSpectrumDataAvailable);  // block on data available
        pthread_mutex_lock(&mutexSpectrumControl);          // lock control data

        el = spQ.front();
        spQ.pop();
        if(!spQ.empty())
            pthread_mutex_unlock(&mutexSpectrumDataAvailable); // more data in queue, unblock threads
        pthread_mutex_unlock(&mutexSpectrumControl);        // unlock control data
//        printf("%d %d %d\n",el.inidx,el.didx,el.spbuf);
        return el;
    };

    void reset(void){
        pthread_mutex_lock(&mutexSpectrumControl);          // lock control data
        midx = 0;
        didx = 0;
        while(!spQ.empty()) spQ.pop();
        pthread_mutex_unlock(&mutexSpectrumControl);      // unlock control data
    };
};

extern spClass sp;
extern int halfFftSp1024;               // make available for ini
extern unsigned short *waterfall;       // data for plotting

void initSpectrumf( void );
void sizeSpectrumf( int newHalfFftSp1024, int twidth );

#endif

