// MIT License Copyright (c) 2016 Booya Corp.
// booyasdr@gmail.com, http:\\booyasdr.sf.net

/*
The radio demodulation is done in three stages which are:

Decimation - convert signal from 64 MHz real to 256 band of 250 kHz complex. The entire
bandwidth is decimated at once in real time.

Tuning - fft samples from one of the 250 kHz bands for fine tuning.

Sound - ifft the samples at the sound sample rate.

The first stage decimates the 64 MHz real signal into 250 kHz wide complex bands
spaced 125 kHz apart. The buffer size is 131072 bytes or 65536 samples each which covers
about 1 ms of time. The first stage fft length is 512. This fft is 50% overlapped.
The second stage sample rate is then 64MHz x 2 / 512 = 250 kHz. The first stage buffer
size of 1 ms corresponds to only 44 44kHz sound samples. To smooth out the sound, the samples
are stacked prior to the tuning stage fft. The number of sound samples per tuning state
fft is the dlen variable. dlen is also the length of the sound sample ifft.

This code uses global variables instead of a classs for compatibility
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
#include "monitor.h"
#include "fftw3.h"

class agc AGC;
class radioControlClass radioCntrl;

// Sound Driver Interface Variables
HWAVEOUT hWaveOut;  // sound output device handle
WAVEFORMATEX wfx;   // wave format descriptor
MMRESULT result;    // for waveOut return values
WAVEHDR *header;    // wave data header

// RADIO RADIO RADIO RADIO RADIO RADIO RADIO RADIO RADIO RADIO
#define N_RADIO_THREAD 6
pthread_t radio_thread[N_RADIO_THREAD]; // radio thread descriptor pointer

int halfFft   = 256;        // half the size of the first decimation stage fft
int tuneStack = 128;        // number of input buffers to stack at the tuning stage
int fftPerBuf;              // number of decimation fft per input buffer
int tuneLength;             // length of tuning buffer, init to fftPerBuf * tuneStack
int tuneIdx;                // index for filling tuning buffer
float ***inDec;             // point to each threads decimation input buffers
float *wndw;                // window variables
fftwf_complex **outDec;     // decimation output buffer per thread
fftwf_complex *tuneBufIn, *tuneBufOut;      // tune stage in and out buffer
fftwf_complex *soundBufIn, *soundBufOut;    // sound ifft stage in and out buffer
fftwf_plan **pdec, ptune, psound;           // fftw plan buffers per thread per buffer
short **sndBuffer;                          // sound output buffer
short nsndBuffer = 8, iBuf = 0;             // number of sound output buffer and output buffer index
float BWAM, BWCW =  500;                    // bandwidth for demodulation AM and CW
float LCOSSB = 50,  BWSSB = 3000;           // SSB lower cut off and bandwidth
int bwiAM, bwicw;                           // maximum inband reqeuncy bin @ last stage input
int lcoissb, bwissb;                        // index of ssb lower cutoff and bandwidth
int dlen = 0;                               // length of the sound output buffer

float df;                   // decimation stage frequency sample spacing
float fs2;                  // tune stage sample frequency
float fc2;                  // radio tune frequency
float df2;                  // tuning stage frequency sample spacing

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

void radioTurnOn(int idx) {
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

    // Windows PC Sound Driver Interface Initialization
    double fs = global.fs;
    wfx.nSamplesPerSec = 46875; // sound sample rate
    wfx.nSamplesPerSec = 62500; // sound sample rate
    BWAM = 8000;

    tuneStack = round(tuneStack*global.fs/64e6);
    double dlenf = (double)wfx.nSamplesPerSec*(double)global.transferSize/(double)fs/2*tuneStack;
    dlen = (int)round(dlenf);

    wfx.wBitsPerSample = 16; /* sample size */
    wfx.nChannels = 1; /* channels*/

    wfx.cbSize = 0; /* size of _extra_ info */
    wfx.wFormatTag = WAVE_FORMAT_PCM;
    wfx.nBlockAlign = (wfx.wBitsPerSample >> 3) * wfx.nChannels;
    wfx.nAvgBytesPerSec = wfx.nBlockAlign * wfx.nSamplesPerSec;

    if(waveOutOpen(&hWaveOut,WAVE_MAPPER,&wfx,0,0,CALLBACK_NULL
    ) != MMSYSERR_NOERROR) {
        fprintf(stderr, "unable to open WAVE_MAPPER device\n");
        return;
    }
    printf("The Wave Mapper device was opened successfully!\n");

    sndBuffer = (short**) fftwf_malloc(sizeof(short*)*nsndBuffer);
    for(int  m = 0 ; m< nsndBuffer; m++) {
        sndBuffer[m] = (short*) fftwf_malloc(dlen*sizeof(short));
        ZeroMemory(sndBuffer[m], dlen*sizeof(short));
    }
    header = (WAVEHDR *) malloc(nsndBuffer*sizeof(WAVEHDR));
    for(int m = 0; m < nsndBuffer; m++ ) {
        ZeroMemory(&header[m], sizeof(WAVEHDR));
        header[m].dwBufferLength = dlen*sizeof(short);
        header[m].lpData = (LPSTR) sndBuffer[m];

        waveOutPrepareHeader(hWaveOut, &header[m], sizeof(WAVEHDR));
    }
// RADIO RADIO RADIO RADIO RADIO RADIO RADIO RADIO RADIO RADIO

    fftPerBuf = global.transferSize / sizeof(short) /halfFft; // number of ffts per buffer in the first stage
    tuneLength = fftPerBuf * tuneStack; // number of samples in the second tuning stage
    tuneIdx = 0;                        // index to the tuning stage sample

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

    tuneBufIn  = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * tuneLength);
    for(int n =0; n < tuneLength;n++) {tuneBufIn[n][0] = 0;tuneBufIn[n][1] = 0;}
    tuneBufOut = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * tuneLength);
    for(int n =0; n < tuneLength;n++) {tuneBufOut[n][0] = 0;tuneBufOut[n][1] = 0;}
    soundBufIn = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * dlen);
    for(int n =0; n < dlen;n++) {soundBufIn[n][0] = 0;soundBufIn[n][1] = 0;}
    soundBufOut = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex) * dlen);
    for(int n =0; n < dlen;n++) {soundBufOut[n][0] = 0;soundBufOut[n][1] = 0;}
    ptune = fftwf_plan_dft_1d(tuneLength, tuneBufIn, tuneBufOut,FFTW_FORWARD,0);
    psound = fftwf_plan_dft_1d(dlen, soundBufIn, soundBufOut,FFTW_BACKWARD,0);

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
    if(global.fs == 1e8) fcal = 1 +300./4.e6;

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

        int AMidx=round((radioCntrl->AMkHz*1000+radioCntrl->ffHz*100)/df);
        fc2 = AMidx*df*fcal;
        int fbin2 = ((int)round((radioCntrl->AMkHz*1000+radioCntrl->ffHz*100-fc2)/df2))%tuneLength;
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

        typedef struct{ float real; float imag; } COMPLEX;

        pthread_mutex_lock(&mutexTuneIdx);
        for(int k = 0;k < fftPerBuf;k++) {
            fftwf_execute(pdec[thisThread][k]);                // FFT first stage
            tuneBufIn[tuneIdx  ][0] = outDec[thisThread][AMidx][0]; // Load input of second stage
            tuneBufIn[tuneIdx++][1] = outDec[thisThread][AMidx][1]; // Load input of second stage
        }

        if (tuneIdx<tuneLength) {  // if tune buffer not full
            pthread_mutex_unlock(&mutexTuneIdx);
            monitor.process_time(th->t,buffer);
            continue;                           // continue loop to get more data for tune stage
        } else {
            tuneIdx = 0;            // reset tune counter
        }

        monitor.getRadioQlen(radioCntrl->cnt);

       // flip phase of every other sample if AMidx is odd
       if( AMidx%2 != 0 ) {
            for(int k = 1;k < tuneLength;k++,k++) {
                tuneBufIn[k][0] = -tuneBufIn[k][0];
                tuneBufIn[k][1] = -tuneBufIn[k][1];
            }
        }
        fftwf_execute(ptune); // FFT second stage
        pthread_mutex_unlock(&mutexTuneIdx);

    // Third stage, IFFT soudnBufIn
        COMPLEX *soundBufInC = (COMPLEX *) soundBufIn; // declare pointers for copying
        COMPLEX *tuneBufOutC = (COMPLEX *) tuneBufOut;

        int kmax = fbin2;
        int k, n, kmod;
        // zeros third stage input buffer
        ZeroMemory(soundBufIn, dlen * sizeof(fftwf_complex));

        if( (radioCntrl->mode == AM) | (radioCntrl->mode == DSB)  ) {
            // Load the bottom
            for( k = kmax, n = 0; k < kmax + bwiAM ; k++, n++ ) {
                kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                soundBufInC[n] = tuneBufOutC[kmod];
            }
            // Load the top
            for( k = kmax-(bwiAM-1), n = dlen -(bwiAM-1); k < kmax ; k++, n++ ) {
                kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                soundBufInC[n] = tuneBufOutC[kmod];
            }

        } else if( (radioCntrl->mode == DSB)  ) {
        // Load the top
            for( k = kmax-bwissb, n = dlen -bwissb; k < kmax-lcoissb ; k++, n++ ) {
                int kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                soundBufInC[n] = tuneBufOutC[kmod];
            }
        // Load the bottom
            for( k = kmax+lcoissb, n = lcoissb; k < kmax + bwissb ; k++, n++ ) {
                int kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                soundBufInC[n] = tuneBufOutC[kmod];
            }

        } else if( (radioCntrl->mode == LSB)  ) {
        // Load the top
            for( k = kmax-bwissb, n = dlen -bwissb; k < kmax-lcoissb ; k++, n++ ) {
                 kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                soundBufInC[n] = tuneBufOutC[kmod];
            }

        } else if( (radioCntrl->mode == USB)  ) {
        // Load the bottom
            for( k = kmax+lcoissb, n = lcoissb; k < kmax + bwissb ; k++, n++ ) {
                 kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                soundBufInC[n] = tuneBufOutC[kmod];
            }
        } else if( (radioCntrl->mode == CW)  ) {

            if(radioCntrl->newMode == true) {
                for( n = 0; n < tuneLength ;  n++ ) {
                    soundBufIn[n][0] = 0;
                    soundBufIn[n][1] = 0;
                }
                radioCntrl->newMode =false;
            }

            for( k = kmax, n = 0; k < kmax + 2*bwicw ; k++, n++ ) {
                 kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                soundBufInC[n] = tuneBufOutC[kmod];
            }
        } // end if CW mode

        fftwf_execute(psound);

        float raw[dlen], AMmeanNew = 0, AMfactor,AMlevel = 8000,a = .8;
        float SF = pow((double)2.,(double)radioCntrl->gain);

        if( radioCntrl->mode == AM ) {
            if(AGC.on) {
                for(int  n = 0; n < dlen ; n++) {
                    raw[n] =  sqrt(soundBufOut[n][0] * soundBufOut[n][0]
                        + soundBufOut[n][1] * soundBufOut[n][1]);
                        AMmeanNew += raw[n];
                }
                AMmeanNew /= dlen;
                AGC.AMmean = (AMmeanNew - AGC.AMmean)*(1-a) + a*AGC.AMmean;
                AMfactor = AMlevel/AGC.AMmean;
//                printf("AGC.AMmean %f AGC.AMmean %f\n",AGC.AMmean,AMfactor);
                float offset = - AMlevel*1.5;
                for(int  n = 0; n < dlen ; n++) {
                    sndBuffer[iBuf][n] = raw[n] * AMfactor + offset;
                }
            } else {
                float A = AGC.scale*SF;
                float offset = - AMlevel*1.5;
                for(int k = 0, n = 0; k < dlen ; k++,n++) {
                    float raw =  sqrt(soundBufOut[k][0] * soundBufOut[k][0]
                        + soundBufOut[k][1] * soundBufOut[k][1]);
                    sndBuffer[iBuf][n] = raw * A + offset;
                }
            }
        } else {
            float A = 4*AGC.scale*SF;
            for(int k = 0, n = 0; k < dlen ; k++,n++) {
                sndBuffer[iBuf][n] = (short) (soundBufOut[k][0] * A);
            }
        }

        if(monitor.calibrate) {
            if( iBuf ==5 ) {
            double calRMS = 0;
            for(int o = 0; o < dlen; o++) calRMS += (sndBuffer[iBuf][o])*(sndBuffer[iBuf][o]);
            calRMS /= (double) dlen;
            calRMS = sqrt(calRMS);

            printf("calRMS = %f\n",calRMS);
            fflush(stdout);
            }
        } else {
// main sound output
            waveOutWrite(hWaveOut, &header[iBuf], sizeof(WAVEHDR));
        }

// increment sound buffer index
        iBuf = (iBuf+1) % nsndBuffer;
        monitor.process_time(th->t,buffer);

    } // while(true)
    pthread_exit(NULL);
}
