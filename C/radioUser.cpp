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

#include <mmsystem.h>
#include <stdio.h>
#include <math.h>
#include "radio.h"
#include "radioUser.h"
#include "global.h"
#include "monitor.h"
#include "webServer.h"

class radioUserClass    localRadioUser;

void radioUserClass::init( void ) {
    halfFft   = radio.halfFft;
    fftPerBuf = radio.fftPerBuf;
    bbLen = sampleRate * tuneDuration;
    tuneLength = tuneDuration * g.fs / halfFft;
    processGain = tuneLength;
    if(!allocated) allocate();
    double fs = g.fs;
    blockLength  = tuneLength/2; // halve for overlap
    printf("RadioUser, halfFFT %d, tuneDuration %f, tuneLength %d, blockLength %d, sampleRate %d, bbLen %d\n",
           halfFft,tuneDuration,tuneLength,blockLength,sampleRate,bbLen);

    // Windows Sound Driver Initialization
    wfx.nSamplesPerSec = sampleRate; // sound sample rate
    bbLen = wfx.nSamplesPerSec * tuneDuration;

    wfx.wBitsPerSample = 16; /* sample size */
    wfx.nChannels = 1; /* channels*/

    wfx.cbSize = 0; /* size of _extra_ info */
    wfx.wFormatTag = WAVE_FORMAT_PCM;
    wfx.nBlockAlign = (wfx.wBitsPerSample >> 3) * wfx.nChannels;
    wfx.nAvgBytesPerSec = wfx.nBlockAlign * wfx.nSamplesPerSec;
    header    = (WAVEHDR *) malloc(nsndBuffer*sizeof(WAVEHDR));
    if(!header) {
      printf("header allocation failure.\n");
      return;
    }
    // End Windows Sound Driver Initialization

// RADIO VARIABLE initialization
    df  = fs/2/halfFft;          // first stage frequency sample spacing
    fs2 = fs/halfFft;           // second stage sample rate
    df2 = fs2/tuneLength;       // second stage frequency sample spacing

    bwiAM   = round(BWAM    /df2);
    bwissb  = round(BWSSB   /df2);
    lcoissb = round(LCOSSB  /df2);
    bwicw   = round(BWCW    /df2);

    double dphi = 2*pi/bbLen;
    for(int n = 0; n < bbLen; n++)
        wt[n] = .5 - .5*cos(dphi/2 + dphi*n); // cosine weighting
//    for(int n = 0; n < bbLen/2; n++) wt[n] = n/((double)bbLen)*2 ; // ramp weighting
    for(int n = 0; n < bbLen/2; n++) wt[n+bbLen/2] = 1 - wt[n];
//    profC = new profileClassClass("radioUser");
//    profiler.registerClass(profC);

    run();
}

void radioUserClass::run(void ) {

   if(!pc) { // open wave only for local radio
      if(waveOutOpen(&hWaveOut,WAVE_MAPPER,&wfx,0,0,CALLBACK_NULL) != MMSYSERR_NOERROR) {
         fprintf(stderr, "unable to open WAVE_MAPPER device\n");
         return;
      }
      printf("The Wave Mapper device was opened successfully!\n");

      for(int  m = 0 ; m< nsndBuffer; m++) {
           ZeroMemory( &header[m],   sizeof(WAVEHDR)     );
           header[m].dwBufferLength = bbLen*sizeof(short)/2; // halve for overlap
           header[m].lpData = (LPSTR) sndBuffer[m];
           waveOutPrepareHeader(hWaveOut, &header[m], sizeof(WAVEHDR));
      }
   }
   for(int  m = 0 ; m< nsndBuffer; m++) {
     ZeroMemory( sndBuffer[m], bbLen*sizeof(short) );
     ZeroMemory( rawBuffer[m], bbLen*sizeof(float) );
   }

   pthread_mutex_init(&mutexDAvailable, NULL);
   pthread_mutex_lock(&mutexDAvailable);

   pthread_mutex_init(&mutexControl, NULL);
   pthread_mutex_unlock(&mutexControl);

   pthread_mutex_init(&mutexTuneIdx, NULL);
   pthread_mutex_unlock(&mutexTuneIdx);

   gain = gainDefault;
   IFbuf = 0;
   tbi0 = 0;                      // tune buffer in
   tbi1 = 1;                      // tune buffer in
   blockIdx=0;                    // index for filling tuning buffer

   for(int n = 0; n < N_RADIO_THREAD; n++) {
     int rc = pthread_create(&demod_thread[n], NULL,radioUser, (void *) this);
     if (rc) printf("ERROR; return code from pthread_create() is %d\n", rc);
     pthread_detach(demod_thread[n]);
   }
   isOn = true;
}

void radioUserClass::stop(void ) {
   if(!isOn) return;
   for(int n = 0; n < N_RADIO_THREAD; n++) {
      pthread_mutex_unlock(&mutexDAvailable);  // allows radioUser to see notConnected
      Sleep(100);                                  // wait for first radio thread to end
   }
   isOn = false;
   mode = Silent;
   if(!pc) { // close only for local radio
      if(waveOutClose(hWaveOut) != MMSYSERR_NOERROR) {
         fprintf(stderr, "unable to close WAVE_MAPPER device\n");
         return;
      }
   }
}

void radioUserClass::allocate(void ) {

   sndBuffer   = (short**) fftwf_malloc(sizeof(short*)*nsndBuffer);
   rawBuffer   = (float**) fftwf_malloc(sizeof(float*)*nsndBuffer);
   adpcmBuffer = (unsigned char**)  fftwf_malloc(sizeof(float*)*nsndBuffer);
   adpcmBufferOut = (short**)  fftwf_malloc(sizeof(short*)*nsndBuffer);
   sndBuffer[0]   = (short*) fftwf_malloc(bbLen*sizeof(short)*nsndBuffer);

   for(int  m = 0 ; m< nsndBuffer; m++) {
      sndBuffer[m]   = &sndBuffer[0][m*bbLen/2];
      rawBuffer[m]   = (float*) fftwf_malloc(bbLen*sizeof(float));
      adpcmBuffer[m] = (unsigned char*) fftwf_malloc(bbLen*sizeof(char));
      adpcmBufferOut[m] = (short *) fftwf_malloc(bbLen*sizeof(short));
   }
   tuneBufIn  = (fftwf_complex**) fftwf_malloc(sizeof(fftwf_complex *) * N_IF_BUF);
   tuneBufOut = (fftwf_complex**) fftwf_malloc(sizeof(fftwf_complex *) * N_IF_BUF);
   bbBufIn    = (fftwf_complex**) fftwf_malloc(sizeof(fftwf_complex *) * N_IF_BUF);
   bbBufOut   = (fftwf_complex**) fftwf_malloc(sizeof(fftwf_complex *) * N_IF_BUF);

   ALLOCATE_FFTWF(tuneBufIn[0],fftwf_complex,tuneLength * N_IF_BUF,radioUserClass.init)
   for(int n = 0; n < N_IF_BUF-1; n++) tuneBufIn[n+1] = tuneBufIn[n] + tuneLength;

   ALLOCATE_FFTWF(tuneBufOut[0],fftwf_complex,tuneLength * N_IF_BUF,radioUserClass.init)
   for(int n = 0; n < N_IF_BUF-1; n++) tuneBufOut[n+1] = tuneBufOut[n] + tuneLength;

   ALLOCATE_FFTWF( bbBufIn[0],fftwf_complex, bbLen * N_IF_BUF,radioUserClass.init)
   for(int n = 0; n < N_IF_BUF-1; n++) bbBufIn[n+1] = bbBufIn[n] + bbLen;

   ALLOCATE_FFTWF(bbBufOut[0],fftwf_complex, bbLen * N_IF_BUF,radioUserClass.init)
   for(int n = 0; n < N_IF_BUF-1; n++) bbBufOut[n+1] = bbBufOut[n] + bbLen;

   for(int n = 0; n < N_IF_BUF; n++) {
      if(!(ptune[n] = fftwf_plan_dft_1d(tuneLength, tuneBufIn[n], tuneBufOut[n],FFTW_FORWARD,0))) {
         printf("FFTW plan creation failed ptune[%d] in radioUserClass::init",n);
         getchar(); printf("Press any key to exit\n"); exit(0);
      }
      if(!(pbb[n] = fftwf_plan_dft_1d(bbLen, bbBufIn[n], bbBufOut[n],FFTW_BACKWARD,0))) {
         printf("FFTW plan creation failed pbb[%d] in radioUserClass::init",n);
         getchar(); printf("Press any key to exit\n"); exit(0);
      }
   }
   wt = (float *) malloc(bbLen*sizeof(double));
}

#define DC 32768
// demod function here
int countOutDecNull = 0;
void *radioUserClass::radioUser(void *arg) {
   radioUserClass *ru = (radioUserClass *) arg;
   printf("radioUser %x pthread_self is %u\n",(int)ru,pthread_self());

   float df = ru->df;
   float df2 = ru->df2;
   float *wt = ru->wt;
   int IFbuf;
   int fftPerBuf   = ru->fftPerBuf;
   int tuneLength  = ru->tuneLength;
   int blockLength = ru->blockLength;
   int bbLen = ru->bbLen;
   fftwf_complex** tuneBufIn   = ru->tuneBufIn;
   fftwf_complex** tuneBufOut  = ru->tuneBufOut;
   fftwf_complex** bbBufIn     = ru->bbBufIn;
   fftwf_complex** bbBufOut    = ru->bbBufOut;
   fftwf_plan  *ptune  = ru->ptune;
   fftwf_plan  *pbb    = ru->pbb;
   short **sndBuffer   = ru->sndBuffer;                  // sound output buffer
   float **rawBuffer   = ru->rawBuffer;                  // raw sound output buffer, before AGC and overlap
   unsigned char **adpcmBuffer   = ru->adpcmBuffer;      // raw sound output buffer, before AGC and overlap
   short **adpcmBufferOut   = ru->adpcmBufferOut;        // raw sound output buffer, before AGC and overlap
   short nsndBuffer    = ru->nsndBuffer;                 // number of sound output buffer and output buffer index
   HWAVEOUT hWaveOut   = ru->hWaveOut;                   // sound output device handle
   WAVEHDR *header     = ru->header;                     // wave data header
   connectionClass *pc = ru->pc;
   enum radioMode oldMode = Silent;
   int bwiAM = ru->bwiAM;                           // maximum inband freqeuncy bin @ last stage input
   int bwicw = ru->bwicw;                           // maximum inband freqeuncy bin @ last stage input
   int lcoissb = ru->lcoissb;                       // index of ssb lower cutoff and bandwidth
   int bwissb = ru->bwissb;                         // index of ssb lower cutoff and bandwidth
   double processGain = ru->processGain;

   int nAUD = bbLen;
   int nBufAdpcmin  = nsndBuffer;
   int nBufAdpcmout = nsndBuffer/2;
   int nADPCM = nAUD/2;
   float tuneHz,tuneHzOld= -1;
   int fbin=round((ru->tunekHz*1000+ru->ffHz*100)/df);

//   profileThreadClass *profT = new profileThreadClass;
//   ru->profC->registerThread(profT);

   connectionState *ppcstate, localState = WS; // dummy local state
   bool *pIsOpen, localIsOpen = true;
   if(pc!=NULL) {
		ppcstate = &ru->pc->state;
		pIsOpen = &ru->pc->isOpen;
   } else {
		ppcstate  = &localState;
		pIsOpen = &localIsOpen;
   }
//			profT->init();

   bool tuneLengthisOdd  = tuneLength%2  != 0;
   double centerTuneLength = tuneLength/2; // for bin2 calculation

   double SMeter;
   int smidx = 0;
   int smskip = 8;
   double SMScale = g.Vpp*pow(2,-16)/(50e-6*localRadioUser.processGain*processGain);
   double tunekHzLast = 0, fftHzLast = 0;

   while(*ppcstate != notConnected) {
//			profT->wait();
      fftwf_complex** outDec = ru->deQ(); // block until dataAvialable
      if(!*pIsOpen) continue;             // do not process when connection is not open

//			profT->go();
//        if(!outDec){
//            printf("outDec is NULL %d\n",++countOutDecNull);
//            continue;
//        }
      bool gotoIF = false;
      tuneHz = ru->tunekHz*1000+ru->ffHz*10;
      fbin=round(tuneHz/df);

      pthread_mutex_lock(&ru->mutexTuneIdx);
      COMPLEX **outDecC = (COMPLEX **) outDec;
      COMPLEX *tuneBufInC0 = (COMPLEX *) tuneBufIn[ru->tbi0];
      COMPLEX *tuneBufInC1 = (COMPLEX *) tuneBufIn[ru->tbi1];
      tuneBufInC0 += blockLength;

      int lim0 = fftPerBuf;
      int blockIdx = ru->blockIdx;
      if((ru->blockIdx + fftPerBuf) >= blockLength) { // tuneBufIn will be filled
         gotoIF = true;
         lim0 = blockLength - ru->blockIdx;
         IFbuf = ru->tbi0;
         ru->tbi0 = ru->tbi1;
         ru->tbi1++;
         ru->tbi1 %= N_IF_BUF;
      }
      ru->blockIdx = (ru->blockIdx+fftPerBuf)%blockLength;
      pthread_mutex_unlock(&ru->mutexTuneIdx);

      int k = 0;
      for( ; k < lim0;k++) {
         tuneBufInC0[blockIdx ] = outDecC[k][fbin]; // Load input of second stage
         tuneBufInC1[blockIdx ] = outDecC[k][fbin]; // Load input of second stage
         blockIdx++;
      }

      if(!gotoIF) continue; // continue filling this buffer

      // tuneBufIn has been filled
      // set up buffers new buffer pointers
      tuneBufInC0 = (COMPLEX *) tuneBufIn[ru->tbi0];
      tuneBufInC1 = (COMPLEX *) tuneBufIn[ru->tbi1];
      tuneBufInC0 += blockLength;

      // zero blockIdx and start filling next buffer
      for( blockIdx = 0; k < fftPerBuf;k++,blockIdx++) {
          tuneBufInC0[blockIdx ] = outDecC[k][fbin]; // Load input of second stage
          tuneBufInC1[blockIdx ] = outDecC[k][fbin]; // Load input of second stage
      }

      // demodulate this buffer
      float fc2 = fbin*df;
      int fbin2 = ((int)round((tuneHz-fc2)/df2))%tuneLength;
      bool fbinIsOdd  = ((fbin%2)  != 0);
      if(fbin2 <0) fbin2 += tuneLength;
      bool fbin2IsOdd = ((fbin2%2) != 0);
      bool blockLengthIsOdd = blockLength%2 != 0;
      if(tuneHz != tuneHzOld) {
         printf("tuneHz %.0f, fbin %d, fbinIsOdd %d, fbin2 %d, fbin2IsOdd %d,thread %ld\n",
                tuneHz,fbin,fbinIsOdd,fbin2,fbin2IsOdd,pthread_self());
         tuneHzOld = tuneHz;
      }

      // flip phase of every other sample if fbin is odd
      if( fbinIsOdd ) {
         int kstart = 0;
//         if(blockLengthIsOdd) int kstart = ru->tbi0%2; // alternate kstart 0,1 if blocklength is odd
         fbin2 += blockLength;
         fbin2 %= tuneLength;
//         for(int k = kstart;k < tuneLength;k++,k++) {
//            tuneBufIn[IFbuf][k][0] = -tuneBufIn[IFbuf][k][0];
//            tuneBufIn[IFbuf][k][1] = -tuneBufIn[IFbuf][k][1];
//         }
      }
      fftwf_execute(ptune[IFbuf]); // FFT second stage

    // Third stage, IFFT soudnBufIn
        COMPLEX *tuneBufOutC = (COMPLEX *) tuneBufOut[IFbuf];
        COMPLEX *bbBufInC    = (COMPLEX *) bbBufIn[IFbuf]; // declare pointers for copying
        enum radioMode mode = ru->mode;
        if(mode != oldMode) {
            memset(bbBufIn[0],0,sizeof(fftwf_complex) * bbLen * N_IF_BUF);
            oldMode = mode;
        }

        int kmax = fbin2, n, kmod;

        if( mode == AM)  {
            // Load the bottom
            for( k = kmax, n = 0; k < kmax + bwiAM ; k++, n++ ) {
                kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                bbBufInC[n] = tuneBufOutC[kmod];
            }
            // Load the top
            for( k = kmax-(bwiAM-1), n = bbLen -(bwiAM-1); k < kmax ; k++, n++ ) {
                kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                bbBufInC[n] = tuneBufOutC[kmod];
            }
        } else if( mode == DSB ) {
        // Load the top
            for( k = kmax-bwissb, n = bbLen -bwissb; k < kmax-lcoissb ; k++, n++ ) {
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
        } else if( mode == LSB ) {
        // Load the top
            for( k = kmax-bwissb, n = bbLen -bwissb; k < kmax-lcoissb ; k++, n++ ) {
                 kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                bbBufInC[n] = tuneBufOutC[kmod];
            }
        } else if( mode == USB ) {
        // Load the bottom
            for( k = kmax+lcoissb, n = lcoissb; k < kmax + bwissb ; k++, n++ ) {
                 kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                bbBufInC[n] = tuneBufOutC[kmod];
            }
        } else if( mode == CW ) {
            for( k = kmax, n = 0; k < kmax + 2*bwicw ; k++, n++ ) {
                 kmod = k%tuneLength;
                if(kmod < 0) kmod += tuneLength;
                bbBufInC[n] = tuneBufOutC[kmod];
            }
        } // end if CW mode

        fftwf_execute(pbb[IFbuf]);

        float Gain = pow((double)2.,(double)ru->gain);
        int iBuf = ru->iBuf;
        ru->iBuf = (ru->iBuf+1) % nsndBuffer;
        float *praw = rawBuffer[iBuf];
        float *prawlast = rawBuffer[(iBuf + nsndBuffer - 1) % nsndBuffer];
        float Amag, Aoffset;

        if( mode == AM ) {
            for(int  n = 0; n < bbLen ; n++) {
             praw[n] =  sqrt(bbBufOut[IFbuf][n][0] * bbBufOut[IFbuf][n][0]
                  + bbBufOut[IFbuf][n][1] * bbBufOut[IFbuf][n][1]);
            }
            float AMmeanNew = 0, AMlevel = 4000, a = .8;
            if(ru->AGC.on) { // AGC
               for(int  n = 0; n < bbLen ; n++) AMmeanNew += praw[n];
               AMmeanNew /= bbLen;
               ru->AGC.AMmean = (AMmeanNew - ru->AGC.AMmean)*(1-a) + a*ru->AGC.AMmean;
               Amag = AMlevel/ru->AGC.AMmean;
               Aoffset = - AMlevel*1.5;
            } else { // no AGC
               Amag = ru->AGC.scale*Gain;            // local
               if(pc) Amag = ru->AGC.scale*Gain/4;   // web
               Aoffset = - AMlevel;
            }
        } else { // SSB or CW
            Amag = 8*ru->AGC.scale*Gain;             // local
            if(pc) Amag = 2*8*ru->AGC.scale*Gain;    // web

            bool flipSign = false;

            if(blockLengthIsOdd) {
               if(fbinIsOdd) {
                  if(!fbin2IsOdd) {
                      if((iBuf%2) == 1)flipSign = true;
                  }
               } else {
                  if(fbin2IsOdd) {
                      if((iBuf%2) == 1) flipSign = true;
                  }
               }
            } else {
               if(fbin2IsOdd) {
                   if((iBuf%2) == 1) flipSign = true;
               }
            }

            if(flipSign)
               for(int k = 0, n = 0; k < bbLen ; k++,n++) praw[n] = -bbBufOut[IFbuf][k][0];
            else
               for(int k = 0, n = 0; k < bbLen ; k++,n++) praw[n] = bbBufOut[IFbuf][k][0];

            Aoffset = 0;
        }
         for(int  n = 0; n < bbLen/2 ; n++) {
             sndBuffer[iBuf][n]
               = (praw[n] * wt[n] + prawlast[n+bbLen/2] * wt[n+bbLen/2])*Amag + Aoffset;
         }
         if( ru->first_time) {
            ru->first_time = false;
            continue;
         }
         if(pc == NULL) {   // local radio
            waveOutWrite(hWaveOut, &header[iBuf], sizeof(WAVEHDR)); // local radio
            monitor.record((short *)header[iBuf].lpData,header[iBuf].dwBufferLength);
         } else {            // web radio
#ifdef COMPRESS_AUDIO
//#if 1
         if(iBuf%2) {
            ru->adpcm_state = encode_ima_adpcm_i16_u8(sndBuffer[ru->iadpcmin],adpcmBuffer[ru->iadpcmout], nAUD, ru->adpcm_state);
            // webServer.enQ(pc,(void *)adpcmBuffer[ru->iadpcmout],nADPCM,audio);
            // void sendWSData(char *trigraph, char *hdr,int NhdrByte, char *data,int NByte) {
            pc->sendWSData("AUD",(char *)adpcmBuffer[ru->iadpcmout],nADPCM);

            ru->iadpcmin = (ru->iadpcmin + 2)%nBufAdpcmin;
            ru->iadpcmout = (ru->iadpcmout + 1)%nBufAdpcmout;
         }
#else
            // webServer.enQ(pc,(void *)sndBuffer[iBuf],nAUD,audio);
            // void sendWSData(char *trigraph, char *data,int NByte) {
            pc->sendWSData("AUD ",(char *)sndBuffer[iBuf],nAUD);
#endif
         for(int k = 0; k < bbLen ; k++,n++) {
             SMeter += bbBufOut[IFbuf][k][0]*bbBufOut[IFbuf][k][0];
         }
         smidx++;
         smidx = smidx%smskip;
//         if(smidx == 0) {
//            SMeter = log(sqrt(SMeter/ (bbLen*smskip))*SMScale)/log(2)+9;
//            printf("SMeter %f\n",SMeter);
//            SMeter = 0;
//         }
        }
    } // while(*ppcstate != notConnected)

   printf("Exit radioUser %x pthread_self is %u\n",(int)ru,pthread_self());
   pthread_exit(NULL);
}
