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
with pthreads.
*/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include "radio.h"
#include "global.h"
#include "main_loop.h"      // for idx, buffers
#include "fftw3.h"

class agc AGC;
class radioControlClass radioCntrl;

// Sound Driver Variables
HWAVEOUT hWaveOut;  // sound output device handle
WAVEFORMATEX wfx;   // wave format descriptor
MMRESULT result;    // for waveOut return values
WAVEHDR *header;    // wave data header

bool first_time = true;
int delay_ms = 10;

// RADIO VARIABLES
#define N_RADIO_THREAD 3
pthread_t radio_thread[N_RADIO_THREAD]; // radio thread descriptor pointer

// OVERLAP compiler switch to overlap processing to improve sound quality
// OVERLAP is defined by default
#define OVERLAP

int halfFft   = 1024;       // half the size of the first decimation stage fft
int tuneStack = 128;        // number of input buffers to stack at the tuning stage
int fftPerBuf;              // number of decimation fft per input buffer
int tuneLength;             // length of tuning buffer, init to fftPerBuf * tuneStack
int blockLength;            // half length of tuning buffer
int blockIdx;               // index for filling tuning buffer
float ***inDec;             // point to each threads decimation input buffers
float *wndw, *wt;           // window variables
fftwf_complex **outDec;     // decimation output buffer per thread
fftwf_complex **tuneBufIn, **tuneBufOut;    // tune stage in and out buffer
fftwf_complex **bbBufIn, **bbBufOut;        // sound ifft stage in and out buffer
fftwf_plan **pdec, ptune[2], pbb[2];        // fftw plan buffers per thread per buffer
short **sndBuffer;                          // sound output buffer
float **rawBuffer;                          // raw sound output buffer, before AGC and overlap
short nsndBuffer = 8, iBuf = 0;             // number of sound output buffer and output buffer index
float BWAM = 8000, BWCW =  500;             // bandwidth for demodulation AM and CW
float LCOSSB = 50,  BWSSB = 3000;           // SSB lower cut off and bandwidth
int bwiAM, bwicw;                           // maximum inband freqeuncy bin @ last stage input
int lcoissb, bwissb;                        // index of ssb lower cutoff and bandwidth
int dlen;                                   // length of the sound output buffer
int tbi0 = 0,tbi1 = 1;                      // tune buffer in

float df;                   // decimation stage frequency sample spacing
float fs2;                  // tune stage sampling rate
float fc2;                  // radio tune frequency
float df2;                  // tuning stage frequency sample spacing
// End RADIO VARIABLES

agc::agc(){
    scaleDefault = 1./(128.*32.*8);
    scale = scaleDefault;
    AMmean = 0;
}

void *radioThreadf(void *arg);

radioControlClass::radioControlClass(){
    AMkHz = 1250;
    ffHz = 0;
    mode = Silent;
    newMode = false;
    bufIdx = 0;
}

pthread_mutex_t mutexDataAvailable;     // unlock to signal data available
pthread_mutex_t mutexRadioControl;      // radio control lock
pthread_mutex_t mutexTuneIdx;           // tune stage input lock

struct radioThreadArg {
    class radioControlClass *radioCntrl;
    long t;
};

radioThreadArg *threadArg[N_RADIO_THREAD];

void initRadioThread(void ) {

    radioCntrl.buffers = buffers; // set to the global exported by main_loop

    pthread_mutex_init(&mutexDataAvailable, NULL);

    pthread_mutex_lock(&mutexDataAvailable);
    pthread_mutex_init(&mutexRadioControl, NULL);
    pthread_mutex_unlock(&mutexRadioControl);
    pthread_mutex_init(&mutexTuneIdx, NULL);
    pthread_mutex_unlock(&mutexTuneIdx);

    for(int t = 0; t < N_RADIO_THREAD; t++) {
        threadArg[t] = (struct radioThreadArg *) malloc(sizeof(radioThreadArg));
        threadArg[t]->t = t;
        threadArg[t]->radioCntrl = &radioCntrl;

//       printf("Creating thread %d\n", t);
        int rc = pthread_create(&radio_thread[t], NULL,
            (void* (__attribute__((__cdecl__)) *)(void*) )  radioThreadf, (void *) threadArg[t]);
        if (rc) printf("ERROR; return code from pthread_create() is %d\n", rc);
    }
}

void radioTurnOn(void) {
    radioCntrl.radioOn = true;
    pthread_mutex_lock (&mutexRadioControl);
    radioCntrl.bufIdx = idx-1;
    if(radioCntrl.bufIdx < 0) radioCntrl.bufIdx += QUEUE_SIZE;
    radioCntrl.cnt = 1;
    pthread_mutex_unlock (&mutexDataAvailable);
    pthread_mutex_unlock (&mutexTuneIdx);
    pthread_mutex_unlock (&mutexRadioControl);
}

void radioTurnOff(void) {
    radioCntrl.radioOn = false;
    radioCntrl.cnt = 0;
}

bool radioIsOn(void){ return(radioCntrl.radioOn); }

void radioDataArrived(void) { // signal new data arrived
    if(!radioCntrl.radioOn) return;

    pthread_mutex_lock (&mutexRadioControl);
    radioCntrl.cnt++;
    pthread_mutex_unlock (&mutexDataAvailable); // signal data available
    pthread_mutex_unlock (&mutexRadioControl);
}

void initRadio( void ) {

    // Windows Sound Driver Initialization
    double fs = global.fs;
    wfx.nSamplesPerSec = 46875; // sound sample rate
    wfx.nSamplesPerSec = 62500; // sound sample rate

    tuneStack = round(tuneStack*global.fs/64e6);
    double dlenf = (double)wfx.nSamplesPerSec*(double)global.transferSize/(double)fs/2*tuneStack;
    dlen = (int)round(dlenf);

    wfx.wBitsPerSample = 16; /* sample size */
    wfx.nChannels = 1; /* channels*/

    wfx.cbSize = 0; /* size of _extra_ info */
    wfx.wFormatTag = WAVE_FORMAT_PCM;
    wfx.nBlockAlign = (wfx.wBitsPerSample >> 3) * wfx.nChannels;
    wfx.nAvgBytesPerSec = wfx.nBlockAlign * wfx.nSamplesPerSec;

    if(waveOutOpen(&hWaveOut,WAVE_MAPPER,&wfx,0,0,CALLBACK_NULL) != MMSYSERR_NOERROR) {
        fprintf(stderr, "unable to open WAVE_MAPPER device\n");
        return;
    }
    printf("The Wave Mapper device was opened successfully!\n");

    sndBuffer = (short**) fftwf_malloc(sizeof(short*)*nsndBuffer);
    rawBuffer = (float**) fftwf_malloc(sizeof(float*)*nsndBuffer);
    header = (WAVEHDR *) malloc(nsndBuffer*sizeof(WAVEHDR));

    for(int  m = 0 ; m< nsndBuffer; m++) {
        sndBuffer[m] = (short*) fftwf_malloc(dlen*sizeof(short));
        ZeroMemory(sndBuffer[m], dlen*sizeof(short));

        rawBuffer[m] = (float*) fftwf_malloc(dlen*sizeof(float));
        ZeroMemory(rawBuffer[m], dlen*sizeof(float));

        ZeroMemory(&header[m], sizeof(WAVEHDR));

#ifdef OVERLAP
        header[m].dwBufferLength = dlen*sizeof(short)/2;
#else
        header[m].dwBufferLength = dlen*sizeof(short);
#endif
        header[m].lpData = (LPSTR) sndBuffer[m];
        waveOutPrepareHeader(hWaveOut, &header[m], sizeof(WAVEHDR));
    }

// RADIO VARIABLE initialization
    fftPerBuf = global.transferSize / sizeof(short) /halfFft; // number of ffts per buffer in the first stage
    tuneLength = fftPerBuf * tuneStack; // number of samples in the second tuning stage

#ifdef OVERLAP
    blockLength  = tuneLength/2;
#else
    blockLength  = tuneLength;
#endif

    blockIdx = 0;               // index to the tuning stage sample
    df = fs/2/halfFft;          // first stage frequency sample spacing
    fs2 = fs/halfFft;           // second stage sample rate
    df2 = fs2/tuneLength;       // second stage frequency sample spacing

    bwiAM   = round(BWAM    /df2);
    bwissb  = round(BWSSB   /df2);
    lcoissb = round(LCOSSB  /df2);
    bwicw   = round(BWCW    /df2);

    printf("initRadio, transferSize = %d, dlen = %d, halfFft %d, fftPerBuf %d, tuneStack %d, tuneLength %d, df = %.0f, fs2 = %.0f, df2 = %.0f\n",
            global.transferSize,dlen,halfFft,fftPerBuf,tuneStack,tuneLength,df,fs2,df2);

    pdec = (fftwf_plan **) malloc(sizeof(fftwf_plan *) * N_RADIO_THREAD);
    inDec  = (float***) malloc(sizeof(float**) * N_RADIO_THREAD);
    outDec = (fftwf_complex**) fftwf_malloc(sizeof(fftwf_complex *) * N_RADIO_THREAD);

    for(int nthread = 0; nthread < N_RADIO_THREAD; nthread++) {
        pdec[nthread] = (fftwf_plan *)  malloc(sizeof(fftwf_plan)   * fftPerBuf);

        inDec[nthread]  = (float**) malloc(sizeof(float*) * fftPerBuf);
        outDec[nthread] = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * 2*(halfFft +1));

        for(int n = 0; n < fftPerBuf; n++) {
            inDec[nthread][n]  = (float*) fftwf_malloc(sizeof(float) * 2 * halfFft);
            pdec[nthread][n] = fftwf_plan_dft_r2c_1d(2*halfFft, inDec[nthread][n], outDec[nthread],0);
        }
    }

    wndw   = (float*) fftwf_malloc(sizeof(float) * 2 * halfFft); // base decimation stage window

    int N = 2*halfFft -1;
    float pi = 4*atan(1);

    for(int n = 0; n < halfFft; n++) {
        wndw[2*halfFft - n - 1] = wndw[n] = (.42-.5*cos(2*pi*n/N)+.08*cos(4*pi*n/N)); // Blackman
    }
    printf("w %d  %g %g %g %g \n",wndw,wndw[0],wndw[1],wndw[2*halfFft-2],wndw[2*halfFft-1]);

    tuneBufIn  = (fftwf_complex**) fftwf_malloc(sizeof(fftwf_complex *) * 2);
    tuneBufIn[0]  = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * tuneLength);
    tuneBufIn[1]  = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * tuneLength);
    ZeroMemory(tuneBufIn[0], tuneLength * sizeof(fftwf_complex));
    ZeroMemory(tuneBufIn[1], tuneLength * sizeof(fftwf_complex));

    tuneBufOut = (fftwf_complex**) fftwf_malloc(sizeof(fftwf_complex) * 2);
    tuneBufOut[0] = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * tuneLength);
    tuneBufOut[1] = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * tuneLength);
    ZeroMemory(tuneBufOut[0], tuneLength * sizeof(fftwf_complex));
    ZeroMemory(tuneBufOut[1], tuneLength * sizeof(fftwf_complex));

    bbBufIn = (fftwf_complex**) fftwf_malloc(sizeof(fftwf_complex) * 2);
    bbBufIn[0] = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * dlen);
    bbBufIn[1] = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * dlen);
    ZeroMemory(bbBufIn[0], dlen * sizeof(fftwf_complex));
    ZeroMemory(bbBufIn[1], dlen * sizeof(fftwf_complex));

    bbBufOut = (fftwf_complex**) fftwf_malloc(sizeof(fftwf_complex) * 2);
    bbBufOut[0] = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * dlen);
    bbBufOut[1] = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * dlen);
    ZeroMemory(bbBufOut[0], dlen * sizeof(fftwf_complex));
    ZeroMemory(bbBufOut[1], dlen * sizeof(fftwf_complex));

    ptune[0] = fftwf_plan_dft_1d(tuneLength, tuneBufIn[0], tuneBufOut[0],FFTW_FORWARD,0);
    ptune[1] = fftwf_plan_dft_1d(tuneLength, tuneBufIn[1], tuneBufOut[1],FFTW_FORWARD,0);
    pbb[0] = fftwf_plan_dft_1d(dlen, bbBufIn[0], bbBufOut[0],FFTW_BACKWARD,0);
    pbb[1] = fftwf_plan_dft_1d(dlen, bbBufIn[1], bbBufOut[1],FFTW_BACKWARD,0);

    wt = (float *) malloc(dlen*sizeof(double));
    double dphi = 2*pi/dlen;
    for(int n = 0; n < dlen; n++) wt[n] = .5 - .5*cos(dphi/2 + dphi*n); // cosine weighting
//    double dd = 1/(double)dlen*2.;
//    for(int n = 0; n < dlen/2; n++) wt[n] = n/((double)dlen)*2 +dd/2; // ramp weighting

    for(int n = 0; n < dlen/2; n++) wt[n+dlen/2] = 1 - wt[n];

    radioCntrl.gain = 0;
    initRadioThread();
}

#define DC 32768

void *radioThreadf(void *arg) {

    radioThreadArg *th = (radioThreadArg *) arg;
    class radioControlClass *radioCntrl = th->radioCntrl;
    printf("radioThreadf t_idx %d pthread_self is %u\n",(int)th->t,pthread_self());
    long thisThread = th->t;
    long lastThread = 0;
    char *buffer;
    float fcal = 1;
//    if(global.fs == 1e8) fcal = 1 +300./4.e6;

    int sign = 1;
    while(true) {
        pthread_mutex_lock(&mutexDataAvailable);
        pthread_mutex_lock(&mutexRadioControl);
        if(radioCntrl->cnt > 0) { //sanity check
            buffer = (char *)radioCntrl->buffers[radioCntrl->bufIdx];
            radioCntrl->bufIdx = ((radioCntrl->bufIdx + 1)%QUEUE_SIZE);
            lastThread = radioCntrl->lastThread;
            radioCntrl->lastThread = thisThread;
            radioCntrl->cnt--;
            if(radioCntrl->cnt > 0)
                pthread_mutex_unlock(&mutexDataAvailable);
            pthread_mutex_unlock(&mutexRadioControl);
        } else {
            pthread_mutex_unlock(&mutexRadioControl);
            continue;
        }

        unsigned short *dataloop; // pointer to input data
        float *inloop;            // pointer to first fft input buffer
        float *endloop;           // pointer to end data to be copied to beginning

        int fbin=round((radioCntrl->AMkHz*1000+radioCntrl->ffHz*100)/df);
        fc2 = fbin*df*fcal;
        int fbin2 = ((int)round((radioCntrl->AMkHz*1000+radioCntrl->ffHz*100-fc2)/df2))%tuneLength;
        bool fbin2isOdd = fbin2%2 != 0;
//       fbin2 = (fbin2%2 != 0 ? fbin2-1 : fbin2); //make fbin2 even
        if(fbin2 <0) fbin2 += tuneLength;

        inloop = inDec[thisThread][0];
        endloop = inDec[lastThread][fftPerBuf-1] + halfFft;
        for(int m = 0, h = 0, k = halfFft; m < halfFft/4;m++) {
            *inloop++ = *endloop++ *wndw[h++]/wndw[k++];
            *inloop++ = *endloop++ *wndw[h++]/wndw[k++];
            *inloop++ = *endloop++ *wndw[h++]/wndw[k++];
            *inloop++ = *endloop++ *wndw[h++]/wndw[k++];
        }
        dataloop = (unsigned short *) buffer;
        inloop = inDec[thisThread][0] + halfFft;
        for(int m = 0, h = halfFft; m < halfFft/4;m++) {
            *inloop++ = (*dataloop++ - DC)*wndw[h++];
            *inloop++ = (*dataloop++ - DC)*wndw[h++];
            *inloop++ = (*dataloop++ - DC)*wndw[h++];
            *inloop++ = (*dataloop++ - DC)*wndw[h++];
        }
        dataloop = (unsigned short *) buffer;
        for(int k = 1;k < fftPerBuf;k++) {
            inloop = inDec[thisThread][k];
            for(int m = 0, h = 0; m < 2*halfFft/4;m++) {
                *inloop++ = (*dataloop++ - DC)*wndw[h++];
                *inloop++ = (*dataloop++ - DC)*wndw[h++];
                *inloop++ = (*dataloop++ - DC)*wndw[h++];
                *inloop++ = (*dataloop++ - DC)*wndw[h++];
            }
            dataloop = dataloop - halfFft;
        }

        COMPLEX *tuneBufInC0 = (COMPLEX *) tuneBufIn[tbi0];
        COMPLEX *tuneBufInC1 = (COMPLEX *) tuneBufIn[tbi1];
        COMPLEX *outDecC = (COMPLEX *) outDec[thisThread][fbin];

        pthread_mutex_lock(&mutexTuneIdx);
#ifdef OVERLAP
        tuneBufInC0 += blockLength;
        for(int k = 0; k < fftPerBuf;k++) {
            fftwf_execute(pdec[thisThread][k]);                // FFT first stage
            tuneBufInC0[blockIdx   ] = *outDecC; // Load input of second stage
            tuneBufInC1[blockIdx++ ] = *outDecC; // Load input of second stage
        }
        if (blockIdx<blockLength) {  // if tune buffer not full
            pthread_mutex_unlock(&mutexTuneIdx);
            continue;                           // continue loop to get more data for tune stage
        } else {
            blockIdx = 0;            // reset tune counter
            int temp = tbi0;
            tbi0 = tbi1;
            tbi1 = temp;
        }
#else
        for(int k = 0;k < fftPerBuf;k++) {
            fftwf_execute(pdec[thisThread][k]);                // FFT first stage
            tuneBufInC0[blockIdx   ] = *outDecC; // Load input of second stage
            tuneBufInC1[blockIdx++ ] = *outDecC; // Load input of second stage
        }
        if (blockIdx<tuneLength) {  // if tune buffer not full
            pthread_mutex_unlock(&mutexTuneIdx);
            continue;                           // continue loop to get more data for tune stage
        } else {
            blockIdx = 0;            // reset tune counter
            int temp = tbi0;
            tbi0 = tbi1;
            tbi1 = temp;
        }
#endif

       // flip phase of every other sample if fbin is odd
       if( fbin%2 != 0 ) {
            for(int k = 1;k < tuneLength;k++,k++) {
                tuneBufIn[tbi1][k][0] = -tuneBufIn[tbi1][k][0];
                tuneBufIn[tbi1][k][1] = -tuneBufIn[tbi1][k][1];
            }
        }
        fftwf_execute(ptune[tbi1]); // FFT second stage
        pthread_mutex_unlock(&mutexTuneIdx);

    // Third stage, IFFT soudnBufIn
        COMPLEX *tuneBufOutC = (COMPLEX *) tuneBufOut[tbi1];
        COMPLEX *bbBufInC    = (COMPLEX *) bbBufIn[tbi1]; // declare pointers for copying

        int kmax = fbin2, k, n, kmod;
        // zeros third stage input buffer
        ZeroMemory(bbBufIn[tbi1], dlen * sizeof(fftwf_complex));

        if( (radioCntrl->mode == AM) | (radioCntrl->mode == DSB)  ) {
            // Load the bottom
            for( k = kmax, n = 0; k < kmax + bwiAM ; k++, n++ ) {
                kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                bbBufInC[n] = tuneBufOutC[kmod];
            }
            // Load the top
            for( k = kmax-(bwiAM-1), n = dlen -(bwiAM-1); k < kmax ; k++, n++ ) {
                kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                bbBufInC[n] = tuneBufOutC[kmod];
            }
        } else if( (radioCntrl->mode == DSB)  ) {
        // Load the top
            for( k = kmax-bwissb, n = dlen -bwissb; k < kmax-lcoissb ; k++, n++ ) {
                kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                bbBufInC[n] = tuneBufOutC[kmod];
            }
        // Load the bottom
            for( k = kmax+lcoissb, n = lcoissb; k < kmax + bwissb ; k++, n++ ) {
                kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                bbBufInC[n] = tuneBufOutC[kmod];
            }
        } else if( (radioCntrl->mode == LSB)  ) {
        // Load the top
            for( k = kmax-bwissb, n = dlen -bwissb; k < kmax-lcoissb ; k++, n++ ) {
                 kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                bbBufInC[n] = tuneBufOutC[kmod];
            }
        } else if( (radioCntrl->mode == USB)  ) {
        // Load the bottom
            for( k = kmax+lcoissb, n = lcoissb; k < kmax + bwissb ; k++, n++ ) {
                 kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                bbBufInC[n] = tuneBufOutC[kmod];
            }
        } else if( (radioCntrl->mode == CW)  ) {
            for( k = kmax, n = 0; k < kmax + 2*bwicw ; k++, n++ ) {
                 kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                bbBufInC[n] = tuneBufOutC[kmod];
            }
        } // end if CW mode

        fftwf_execute(pbb[tbi1]);

        float raw[dlen], AMmeanNew = 0, AMfactor, AMlevel = 8000, a = .8;
        float SF = pow((double)2.,(double)radioCntrl->gain);
        float *praw = rawBuffer[iBuf], *prawlast = rawBuffer[(iBuf + nsndBuffer - 1) % nsndBuffer];

        if( radioCntrl->mode == AM ) {
            if(AGC.on) {
                for(int  n = 0; n < dlen ; n++) {
                   praw[n] =  sqrt(bbBufOut[tbi1][n][0] * bbBufOut[tbi1][n][0]
                        + bbBufOut[tbi1][n][1] * bbBufOut[tbi1][n][1]);
                        AMmeanNew += praw[n];
                }
                AMmeanNew /= dlen;
                AGC.AMmean = (AMmeanNew - AGC.AMmean)*(1-a) + a*AGC.AMmean;
                AMfactor = AMlevel/AGC.AMmean;
//                printf("AGC.AMmean %f AGC.AMmean %f\n",AGC.AMmean,AMfactor);
                float offset = - AMlevel*1.5;
#ifdef OVERLAP
                for(int  n = 0; n < dlen/2 ; n++) {
                    sndBuffer[iBuf][n]
                      = (praw[n] * wt[n] + prawlast[n+dlen/2] * wt[n+dlen/2]) * AMfactor + offset;
                }
#else
                for(int  n = 0; n < dlen ; n++) {
                    sndBuffer[iBuf][n] = praw[n] * AMfactor + offset;
                }
#endif
            } else { // no AGC
                float A = AGC.scale*SF;
                float offset = - AMlevel*1.5;

                for(int k = 0, n = 0; k < dlen ; k++,n++)
                    praw[n] =  sqrt(bbBufOut[tbi1][k][0] * bbBufOut[tbi1][k][0]
                        + bbBufOut[tbi1][k][1] * bbBufOut[tbi1][k][1]);
#ifdef OVERLAP
                for(int k = 0, n = 0; k < dlen/2 ; k++,n++) {
                    sndBuffer[iBuf][n] = (praw[n] * wt[n] + prawlast[n+dlen/2] * wt[n+dlen/2]) * A + offset;
                }
#else
                for(int k = 0, n = 0; k < dlen ; k++,n++) {
                    praw[n] =  sqrt(bbBufOut[tbi1][k][0] * bbBufOut[tbi1][k][0]
                        + bbBufOut[tbi1][k][1] * bbBufOut[tbi1][k][1]);
                    sndBuffer[iBuf][n] = praw[n] * A + offset;
                }
#endif
            }
        } else { // SSB or CW
            float A = 4*AGC.scale*SF;
            if(fbin2isOdd)
                if(iBuf%2 == 0) A = -A;

            for(int k = 0, n = 0; k < dlen ; k++,n++)
                praw[n] =  (bbBufOut[tbi1][k][0] * A);
//praw[n]=0;
//                sndBuffer[iBuf][n] = (short) (bbBufOut[tbi0][k][0] * A);
#ifdef OVERLAP
                for(int  n = 0; n < dlen/2 ; n++) {
//                praw[n] =  (bbBufOut[tbi0][n][0] * A);
                    sndBuffer[iBuf][n]
//                      = (praw[n+dlen/2] * wt[n] + prawlast[n] * wt[n+dlen/2]) ;
                      = (praw[n] * wt[n] + prawlast[n+dlen/2] * wt[n+dlen/2]) ;
                }
#else
                for(int  n = 0; n < dlen ; n++) {
                    sndBuffer[iBuf][n] = praw[n];
                }
#endif
        }

// main sound output
if( first_time) Sleep(delay_ms);
        waveOutWrite(hWaveOut, &header[iBuf], sizeof(WAVEHDR));
// increment sound buffer index
        iBuf = (iBuf+1) % nsndBuffer;

    } // while(true)
    pthread_exit(NULL);
}
