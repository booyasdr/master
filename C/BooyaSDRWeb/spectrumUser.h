// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef SPECTRUM_USER_H
#define SPECTRUM_USER_H

#include "global.h"
#include "monitor.h"
#include <pthread.h>

typedef struct {
    float *ptr;  // input buffer index
    int len;  // spectrum buffer index
    void set(float *a, int b){ptr = a; len = b;};
} spectrum_user_element;

#define NSPUTHREAD 3
#define NSPUBUF 3

class spUserClass {

private:
    float **insu[NSPUBUF];                // fft input data pointer and loop pointer
    unsigned char **pyrOut[NSPUBUF];     // output short integer for display

    int idxBuf = 0; // output buffer index
    int incIdxBuf() {
        idxBuf = (idxBuf + 1) % NSPUBUF;
        return idxBuf;
    }

    pthread_mutex_t mutexSpDataAvailable; // unlock to signal data available
    pthread_mutex_t mutexSpControl;       // radio control lock

    int level=3, maxLevel = 10;

    static void *spectrumUser(void *arg);

    Queue<spectrum_user_element,30> Q;
    pthread_t spectrum_user_thread[NSPUTHREAD];
//    profileClassClass *profC;

public:
   void init( void );
   spectrum_user_element sp_el;

   int idx = 1;
   void enQ(float *ptr, int len){   // call from spectrum

      if(!g.server_mode) return;    // spUser output in only needed in server mode

      pthread_mutex_lock(&mutexSpControl);          // lock control data
      int skip = 1;

      if((idx%skip)==0) {
         // push a new element onto the spectrum processing queue
         sp_el.set(ptr,len);
         Q.push(sp_el);
         pthread_mutex_unlock(&mutexSpDataAvailable);  // signal data available
      }
      idx = idx++%skip;
      pthread_mutex_unlock(&mutexSpControl);      // unlock control data
   };

   spectrum_user_element deQ(void) { // call from thread
      spectrum_user_element el;
      pthread_mutex_lock(&mutexSpDataAvailable);   // block on data available
      pthread_mutex_lock(&mutexSpControl);         // lock control data

      el = Q.front();
      Q.pop();
      if(!Q.empty())
         pthread_mutex_unlock(&mutexSpDataAvailable); // more data in queue, unblock threads
      pthread_mutex_unlock(&mutexSpControl);          // unlock control data
      return el;
   };

   void reset(void){
      pthread_mutex_lock(&mutexSpControl);            // lock control data
      while(!Q.empty()) Q.pop();
      pthread_mutex_unlock(&mutexSpControl);          // unlock control data
   };
};

extern spUserClass spUser;

#endif

