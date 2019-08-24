// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef RADIO_USER_H
#define RADIO_USER_H

#include <pthread.h>
#include "fftw3.h"
#include "global.h"
#include "ima_adpcm.h"
#include "connection.h"
#include "monitor.h"

enum radioMode { Silent = 0, AM = 1, DSB = 2,LSB = 3,USB = 4, CW = 5};
#define N_RADIO_THREAD 2
#define N_IF_BUF 4

class agc {
public:
    agc(){
        scaleDefault = 1./(1024.*32.);
        scale = scaleDefault;
        AMmean = 0;
    }
    bool on = false;
    float AMmean;
    float scale,scaleDefault;
};

class radioUserClass {
   bool allocated = false; 	// allocation flag
   bool isOn =      false; 	// radio user on flag
   class connectionClass *pc;
   fftwf_complex **tuneBufIn, **tuneBufOut;    // tune stage in and out buffer
   fftwf_complex **bbBufIn, **bbBufOut;        // sound ifft stage in and out buffer
   fftwf_complex *halfSampPhCorr;              // half sample phase correction
   fftwf_plan  ptune[N_IF_BUF], pbb[N_IF_BUF]; // fftw plan buffers per thread per buffer
   short **sndBuffer;                          // sound output buffer
   float **rawBuffer;                          // raw sound output buffer, before AGC and overlap
   unsigned char **adpcmBuffer;                // raw sound output buffer, before AGC and overlap
   short **adpcmBufferOut;                     // raw sound output buffer, before AGC and overlap
   short nsndBuffer = 8, iBuf = 0;             // number of sound output buffer and output buffer index
   float BWAM = 4000, BWCW =  500;             // bandwidth for demodulation AM and CW
   float LCOSSB = 200,  BWSSB = 2800;          // SSB lower cut off and bandwidth
   int bwiAM, bwicw;                           // maximum inband freqeuncy bin @ last stage input
   int lcoissb, bwissb;                        // index of ssb lower cutoff and bandwidth
   int bbLen;                                  // length of the sound output buffer

   float df;                   // decimation stage frequency sample spacing
   float fs2;                  // tune stage sampling rate
   float fc2;                  // radio tune frequency
   float df2;                  // tuning stage frequency sample spacing

   float *wt;                  // window variables
   int IFbuf;
   int tbi0,tbi1;              // tune buffer in
   int blockIdx;               // index for filling tuning buffer
   int tuneLength;             // length of tuning buffer, init to fs * tuneDuration
   int blockLength;            // half tuneLength
   double tuneDuration = .1;   // duration of tune buffer (sec)
   double processGain = 1;     // signal processing gain of this stage

   // Sound Driver Variables
   HWAVEOUT hWaveOut;  // sound output device handle
   WAVEFORMATEX wfx;   // wave format descriptor
   MMRESULT result;    // for waveOut return values
   WAVEHDR *header;    // wave data header

   bool first_time = true;

   pthread_mutex_t mutexControl;           // tune stage input lock
   pthread_mutex_t mutexTuneIdx;           // tune stage input lock
   pthread_t demod_thread[N_RADIO_THREAD]; // radio thread descriptor pointer
//    profileClassClass *profC;

public:
   pthread_mutex_t mutexDAvailable;        // tune stage input lock
   radioUserClass(void){pc = NULL; memset(demod_thread,'\0',sizeof(pthread_t *)*N_RADIO_THREAD);};
   radioUserClass(class connectionClass *PC) {pc =  PC;  memset(demod_thread,'\0',sizeof(pthread_t *)*N_RADIO_THREAD);};
//    ~radioUserClass(){stop();};
   class agc AGC;

   int fftPerBuf;              // number of decimation fft per input buffer
   int halfFft;                // half the size of the first decimation stage fft

   int sampleRate = 48000;     // output audio sample rate, set by client, default to 48000 Hz
   float tunekHz = 1210;       // radio tune frequency in kHz
   float ffHz = 0;             // fine radio tune frequency 100 Hz
   int gainDefault = -3;       // default gain scale factor
   int gain = gainDefault;     // gain scale factor
   enum radioMode mode = Silent;// current radio mode

   ima_adpcm_state_t adpcm_state = {0};
   ima_adpcm_state_t adpcm_state_out = {0};
   int iadpcmin = 0;
   int iadpcmout = 0;

   void init(void);
   void allocate(void);
   void run(void);
   void stop(void);
   Queue<fftwf_complex**,30> Q;
   int pushcount = 0, popcount = 0;

   void enQ(fftwf_complex **ptr, int len){ // call from main loop
      if(mode == Silent) return;
      pthread_mutex_lock(&mutexControl);          // lock control data
// push a new element onto the spectrum processing queue
      Q.push(ptr);
      ++pushcount;

      pthread_mutex_unlock(&mutexControl);      // unlock control data
      pthread_mutex_unlock(&mutexDAvailable);  // signal data available, must be outside after unlock mutexControl
   };

   fftwf_complex** deQ(void) { // call from thread
      pthread_mutex_lock(&mutexDAvailable);  // block on data available
      pthread_mutex_lock(&mutexControl);          // lock control data
      fftwf_complex** ptr = Q.front();
      Q.pop();
      if(!Q.empty())
         pthread_mutex_unlock(&mutexDAvailable); // more data in queue, unblock threads
      pthread_mutex_unlock(&mutexControl);        // unlock control data
      return ptr;
   };

   static void *radioUser(void *arg);
};

extern class radioUserClass localRadioUser;

typedef struct{ float real; float imag; } COMPLEX;
typedef union{ COMPLEX x; float a[1024*2]; } IFPTR;

#endif
