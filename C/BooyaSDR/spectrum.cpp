// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

/* fft 2*1024*halfFftSp1024 samples for display */

#include <stdio.h>
#include <fftw3.h>
#include <math.h>

#include "pthread.h"
#include "spectrum.h"
#include "global.h"
#include "monitor.h"
#include "main_loop.h"          // idx, buffers

fftwf_plan ps[NSPTHREAD];       // fft plan
float **ins;                    // fft input data pointer and loop pointer
float *wndws;                   // window variables
fftwf_complex **outs;           // output buffer
float *outloops;                // output data loop pointer
unsigned short *waterfall;      // output short integer for display
int wfidx = 1;
unsigned short *spOutData[2];     // output short integer for display

#define N_OUT_MAG 4
float **outMagsq;                // output magnitude squared pointer
int outMagsqCount[N_OUT_MAG]={0};
int idxMag = 0;
int halfSpFft;

pthread_t spectrum_thread[NSPTHREAD];
pthread_mutex_t mutexSpMagsq;   // spectrum output

const int halfFftSp1024Max  = 1024;     // maximum half fft in units of 1024
int halfFftSp1024           = 64;       // half the spectrum fft in units of 1024

spClass sp;

void *spectrumThreadf( void *arg);

// allocate enough memory for maximum fft size as held in halfFftMax
void initSpectrumf( void ) {

    sp.initPeriod();
    pthread_mutex_init(&mutexSpMagsq, NULL);
    pthread_mutex_unlock(&mutexSpMagsq);

    int halfFftMax  = halfFftSp1024Max*1024;
    spOutData[0] = (unsigned short *) malloc(sizeof(unsigned short)*halfFftMax);
    spOutData[1] = (unsigned short *) malloc(sizeof(unsigned short)*halfFftMax);
    ZeroMemory(spOutData[0],sizeof(unsigned short)*halfFftMax);
    ZeroMemory(spOutData[1],sizeof(unsigned short)*halfFftMax);
    waterfall = spOutData[0];

    ins     = (float**) fftwf_malloc(sizeof(float *) * NSPTHREAD );
    outs    = (fftwf_complex**) fftwf_malloc(sizeof(fftwf_complex *) * NSPTHREAD);
    wndws   = (float*) fftwf_malloc(sizeof(float) * 2 * halfFftMax);
    for(int n = 0; n < NSPTHREAD; n++ ) {
        ins[n]      = (float*) fftwf_malloc(sizeof(float) * 2 * halfFftMax);
        outs[n]     = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * (halfFftMax + 1));
        ps[n] = NULL;
    }
    outMagsq = (float**) fftwf_malloc(sizeof(float* ) * N_OUT_MAG);
    for(int n = 0; n < N_OUT_MAG; n++)
        outMagsq[n] = (float*) fftwf_malloc(sizeof(float) * (halfFftMax + 1));

    sizeSpectrumf(halfFftSp1024, 1024);

    for(int t = 0; t < NSPTHREAD; t++) {
        sp.ti[t] = t;
        int rc = pthread_create(&spectrum_thread[t], NULL, spectrumThreadf, (void *)&sp.ti[t]);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            break;
        }
    }
}

// resize the fft as commanded
void sizeSpectrumf( int newHalfFftSp1024, int twidth ) {

    halfFftSp1024 = newHalfFftSp1024;
    halfSpFft   = halfFftSp1024*twidth;
    printf("Replan the spectrum FFT, halfSpFft = %d\n",halfSpFft);
    sp.reset();
    for(int n = 0; n < NSPTHREAD; n ++) {
        fftwf_destroy_plan(ps[n]); // destroy old plan
        Sleep(30);
        ps[n] = fftwf_plan_dft_r2c_1d(2*halfSpFft, ins[n], outs[n],0); // create new plan
    }
    double N = 2*halfSpFft -1;
    double pi = 4*atan(1);
    for(int n = 0; n < halfSpFft; n++) {
//            wndws[n] = (.54 - .46*cos(2*pi*n/N))/16;  // Hamming
        wndws[n] = (.42-.5*cos((2*pi*n)/N)+.08*cos((4*pi*n)/N)); // Blackman
        wndws[2*halfSpFft-n-1] = wndws[n]; // Blackman
//        if( n< 500) printf("%f \n",wndws[n]);
    }
    printf("Done replan the spectrum FFT\n");
}

extern pthread_mutex_t mutexImageUpdate;

void *spectrumThreadf( void *arg){
    long *t_idx = (long *) arg;
    pthread_t thisth = pthread_self();
    printf("spectrumThreadf t_idx %d pthread_self is %u\n",*t_idx,thisth);

    int halfBuf = global.transferSize/sizeof(short)/2;   // half input buffer size

    unsigned char **pbuffer = buffers;

    unsigned short *inloop;
    unsigned short *outloop;
    float *inFftLoop, *outFftLoop, *outMagsqLoop;
    float x;
    unsigned char *c;
    unsigned long *y;

    y = (unsigned long *)&x;
    c = (unsigned char *) y;
    c = c + 3;

    while(true) {
        spectrum_element el = sp.process(); // block on data available
//        halfSpFft = halfFftSp1024*twidth;   // this could change
//unpack
        int bspidx = el.inidx-1;
        long spbuf = el.spbuf;

        int Nbuf = ceil((double)halfSpFft/(double)halfBuf);          // number of buffers to conbine in fft
        if(Nbuf < 1)   Nbuf = 1;
        if(Nbuf > 1)   bspidx -= (Nbuf-1);   // reduce the index by Nbuf-1
        if(bspidx < 0) bspidx += QUEUE_SIZE;

        inFftLoop = ins[spbuf];

//        printf("bspidx %d Nbuf %d spbuf %d %g\n",bspidx,Nbuf,spbuf,elapsed);
        #define DC 32768
//        #define DC 0
        // load the buffers into the input
        int h = 0;
        int left = 2 * halfSpFft;
        int lim;
        for(int n = 0; n < Nbuf;n++) {
           inloop = (unsigned short *) pbuffer[bspidx];
           lim = ( left > 2*halfBuf ? 2*halfBuf : left );
           for(int m = 0; m < lim/4;m++) {
                *inFftLoop++ = (*inloop++ - DC)*wndws[h++];
                *inFftLoop++ = (*inloop++ - DC)*wndws[h++];
                *inFftLoop++ = (*inloop++ - DC)*wndws[h++];
                *inFftLoop++ = (*inloop++ - DC)*wndws[h++];
           }
//           printf("bspidx %d lim %d \n",bspidx,lim);
           bspidx = (bspidx+1)%QUEUE_SIZE;
           left -= lim;
        }

        if(ps[spbuf] == NULL) { // try and prevent fftw crash
            printf("ERROR ps[spbuf] %d spbuf %d\n",ps[spbuf],spbuf);
            continue;
        }

        fftwf_execute(ps[spbuf]);  // do the fft

        outFftLoop = (float *) outs[spbuf];
//printf("outs[spbuf] %f %f\n",outFftLoop[1000],outFftLoop[1001]);
        float *thisOutMagsq = outMagsq[idxMag];
        outMagsqLoop = thisOutMagsq;

        for(int m = 0; m < halfSpFft/4;m++) {
            *outMagsqLoop   += (*outFftLoop * *outFftLoop) ; outFftLoop++;
            *outMagsqLoop++ += (*outFftLoop * *outFftLoop) ; outFftLoop++;

            *outMagsqLoop   += (*outFftLoop * *outFftLoop) ; outFftLoop++;
            *outMagsqLoop++ += (*outFftLoop * *outFftLoop) ; outFftLoop++;

            *outMagsqLoop   += (*outFftLoop * *outFftLoop) ; outFftLoop++;
            *outMagsqLoop++ += (*outFftLoop * *outFftLoop) ; outFftLoop++;

            *outMagsqLoop   += (*outFftLoop * *outFftLoop) ; outFftLoop++;
            *outMagsqLoop++ += (*outFftLoop * *outFftLoop) ; outFftLoop++;
       }
       if( el.didx == 0 ) {
    pthread_mutex_lock(&mutexSpMagsq);
//            outMagsqLoop = outMagsq[idxMag];
            outMagsqLoop = thisOutMagsq;

            idxMag++;
            idxMag %= N_OUT_MAG;
    pthread_mutex_unlock(&mutexSpMagsq);
            outloop = waterfall;
//printf("outMagsq[0] %f\n",outMagsq[idxMag][8*1024+500]);
           for(int m = 0; m < halfSpFft/4;m++) {
                x = *outMagsqLoop++; *y = *y<<1;  *outloop++ = *c;
                x = *outMagsqLoop++; *y = *y<<1;  *outloop++ = *c;
                x = *outMagsqLoop++; *y = *y<<1;  *outloop++ = *c;
                x = *outMagsqLoop++; *y = *y<<1;  *outloop++ = *c;
           }
           pthread_mutex_unlock(&mutexImageUpdate); // signal image data update
//           ZeroMemory(outMagsq[idxMag],halfSpFft*sizeof(float));
           ZeroMemory(thisOutMagsq,halfSpFft*sizeof(float));
           int aaa = 4;

       }
    } // while
    pthread_exit(NULL);
}
