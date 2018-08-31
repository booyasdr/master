// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

/* fft 2*1024*halfFftSp1024 samples for display */

#include <stdio.h>
#include <fftw3.h>
#include <math.h>

#include "pthread.h"
#include "spectrum.h"
#include "spectrumUser.h"
#include "global.h"
#include "monitor.h"
#include "main_loop.h"          // idx, buffers

int halfFftSp1024Max  = 512;           // maximum half fft in units of 1024
int halfFftSp1024      = 64;           // half the spectrum fft in units of 1024

spectrumClass spectrum;

// allocate enough memory for maximum fft size as held in halfFftMax
bool spectrumClass::init( void ) {

    spectrum.initPeriod();
    pthread_mutex_init(&mutexSpMagsq, NULL);
    pthread_mutex_unlock(&mutexSpMagsq);
    int halfFftMax  = halfFftSp1024Max*1024;

   for(int n = 0; n < NSPOUTBUF; n++) {
      ALLOCATE(spOutData[n],unsigned short,halfFftMax,spectrumClass::init);
   }
//    waterfallIn = spOutData[0];
//    waterfallOut = spOutData[1];

    ALLOCATE_FFTWF( ins,float*, NSPTHREAD,spectrumClass::init)
    ALLOCATE_FFTWF( outs,fftwf_complex*, NSPTHREAD,spectrumClass::init)
    ALLOCATE_FFTWF(wndws,float,halfFftMax,spectrumClass::init)
    if(!wndws) return false;
    for(int n = 0; n < NSPTHREAD; n++ ) {
      ALLOCATE_FFTWF(ins[n],float,2*halfFftMax,spectrumClass::init)
      ALLOCATE_FFTWF(outs[n],fftwf_complex,halfFftMax+1,spectrumClass::init)
      ps[n] = NULL;
    }
    outMagsq = (float**) fftwf_malloc(sizeof(float* ) * N_OUT_MAG);
    for(int n = 0; n < N_OUT_MAG; n++) {
      ALLOCATE_FFTWF(outMagsq[n],float,(halfFftMax + 1),spectrumClass::init)
    }
   if(!sizeSpectrumf(halfFftSp1024)) return false;

//    profC = new profileClassClass("spectrum");
//    profiler.registerClass(profC);

    for(int t = 0; t < NSPTHREAD; t++) {
        int rc = pthread_create(&spectrum_thread[t], NULL, spectrumf, (void *)this);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            break;
        }
    }
    return true;
}

// resize the fft as commanded
bool spectrumClass::sizeSpectrumf( int newHalfFftSp1024 ) {

    halfFftSp1024 = newHalfFftSp1024;
    int halfFft   = halfFftSp1024*1024;
    printf("Replan the spectrum FFT, halfFft = %d\n",halfFft);
    spectrum.reset();
    for(int n = 0; n < NSPTHREAD; n ++) {
        fftwf_destroy_plan(ps[n]); // destroy old plan
        Sleep(30);
        if(!(ps[n] = fftwf_plan_dft_r2c_1d(2*halfFft, ins[n], outs[n],0))) { // create new plan
             printf("FFTW plan creation failed ps[%d] in sizeSpectrumf",n);
             getchar(); printf("Press any key to exit\n"); exit(0);
      }
    }
    double N = 2*halfFft -1;
    double pi = 4*atan(1);
    for(int n = 0; n < halfFft; n++) {
//            wndws[n] = (.54 - .46*cos(2*pi*n/N))/16;  // Hamming
        wndws[n] = (.42-.5*cos((2*pi*n)/N)+.08*cos((4*pi*n)/N)); // Blackman
        wndws[2*halfFft-n-1] = wndws[n]; // Blackman
    }
    printf("Done replan the spectrum FFT\n");
    return true;
}

extern pthread_mutex_t mutexImageUpdate;

void *spectrumClass::spectrumf( void *arg){
    spectrumClass *pspectrum = (spectrumClass *) arg;
    pthread_t thisth = pthread_self();
    printf("spectrumf %d pthread_self is %u\n",*pspectrum,thisth);

    int halfBuf = g.transferSize/sizeof(short)/2;   // half input buffer size

   fftwf_plan *ps = pspectrum->ps;       // fft plan
   float **ins = pspectrum->ins;                    // fft input data pointer and loop pointer
   float *wndws = pspectrum->wndws;                   // window variables
   fftwf_complex **outs = pspectrum->outs;           // output buffer
   unsigned short **spOutData = pspectrum->spOutData;   // output short integer for display
   float **outMagsq = pspectrum->outMagsq;               // output magnitude squared pointer
   int *pidxMag = &pspectrum->idxMag;
   int *pinidx = &pspectrum->inidx;
   pthread_mutex_t *pmutexSpMagsq = &pspectrum->mutexSpMagsq;   // spectrum output
//   unsigned short *waterfall = pspectrum->waterfallIn;      // output short integer for display

    unsigned char **pbuffer = ::buffers;

    unsigned short *inloop;
    unsigned short *outloop;
    float *inFftLoop, *outFftLoop, *outMagsqLoop;
    float x;
    unsigned char *c;
    unsigned long *y;

    y = (unsigned long *)&x;
    c = (unsigned char *) y;
    c = c + 3;

//   profileThreadClass *profT = new profileThreadClass;
//   pspectrum->profC->registerThread(profT);
//   profT->init();

    while(true) {
//			profT->wait();
        spectrum_element el = pspectrum->deQ(); // block on data available
//         profT->go();
        int halfFft = halfFftSp1024*1024;   // this could change
//unpack queue element
        int bspidx = el.inidx-1;
        long spbuf = el.spbuf;

        int Nbuf = ceil((double)halfFft/(double)halfBuf);          // number of buffers to conbine in fft
        if(Nbuf < 1)   Nbuf = 1;
        if(Nbuf > 1)   bspidx -= (Nbuf-1);   // reduce the index by Nbuf-1
        if(bspidx < 0) bspidx += QUEUE_SIZE;

        inFftLoop = ins[spbuf];

//        printf("bspidx %d Nbuf %d spbuf %d %g\n",bspidx,Nbuf,spbuf,elapsed);
        #define DC 32768
//        #define DC 0
        // load the buffers into the input
        int h = 0;
        int left = 2 * halfFft;
        int lim;
        for(int n = 0; n < Nbuf;n++) {
           inloop = (unsigned short *) pbuffer[bspidx];
           lim = ( left > 2*halfBuf ? 2*halfBuf : left );
           for(int m = 0, j = 0; m < lim/4;m++) {
                inFftLoop[h] = (inloop[j] - DC)*wndws[h]; h++; j++;
                inFftLoop[h] = (inloop[j] - DC)*wndws[h]; h++; j++;
                inFftLoop[h] = (inloop[j] - DC)*wndws[h]; h++; j++;
                inFftLoop[h] = (inloop[j] - DC)*wndws[h]; h++; j++;
           }
           bspidx = (bspidx+1)%QUEUE_SIZE;
           left -= lim;
        }

        if(ps[spbuf] == NULL) { // try and prevent fftw crash
            printf("ERROR ps[spbuf] %d spbuf %d\n",ps[spbuf],spbuf);
            continue;
        }

        fftwf_execute(ps[spbuf]);  // do the fft

        outFftLoop = (float *) outs[spbuf];
        outMagsqLoop = outMagsq[*pidxMag];

        for(int m = 0, i = 0, j = 0, k = 1; m < halfFft/4;m++) {
            outMagsqLoop[i] += ( outFftLoop[j] * outFftLoop[j] + outFftLoop[k] * outFftLoop[k]);
            i++; j+=2; k+=2;
            outMagsqLoop[i] += ( outFftLoop[j] * outFftLoop[j] + outFftLoop[k] * outFftLoop[k]);
            i++; j+=2; k+=2;
            outMagsqLoop[i] += ( outFftLoop[j] * outFftLoop[j] + outFftLoop[k] * outFftLoop[k]);
            i++; j+=2; k+=2;
            outMagsqLoop[i] += ( outFftLoop[j] * outFftLoop[j] + outFftLoop[k] * outFftLoop[k]);
            i++; j+=2; k+=2;
       }
      if( el.didx == 0 ) {
         spUser.enQ(outMagsqLoop,halfFft); // signal spUser
         pthread_mutex_lock(pmutexSpMagsq);
            *pidxMag = (*pidxMag+1)%N_OUT_MAG;
         pthread_mutex_unlock(pmutexSpMagsq);
         if(g.gui) { // for local gui only
            outloop = spOutData[*pinidx];
            (*pinidx)++;
            (*pinidx) %= NSPOUTBUF;
            for(int m = 0, j = 0; m < halfFft/4;m++) {
               x = outMagsqLoop[j]; *y = *y<<1;  outloop[j] = *c; j++;
               x = outMagsqLoop[j]; *y = *y<<1;  outloop[j] = *c; j++;
               x = outMagsqLoop[j]; *y = *y<<1;  outloop[j] = *c; j++;
               x = outMagsqLoop[j]; *y = *y<<1;  outloop[j] = *c; j++;
            }
//            unsigned short *temp = pspectrum->waterfallOut;
//            pspectrum->waterfallOut = pspectrum->waterfallIn;
//            pspectrum->waterfallIn = temp;
            pthread_mutex_unlock(&mutexImageUpdate); // signal image data update
         }
         ZeroMemory(outMagsq[*pidxMag],halfFft*sizeof(float));
      }
    } // while
    pthread_exit(NULL);
}
