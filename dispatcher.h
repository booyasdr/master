// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef DISPATCH_H
#define DISPATCH_H

#include "global.h"
#include "connection.h"
#define DEFAULT_PORT 4951

typedef enum{ spec, audio} dataType;
typedef struct {
    connectionClass *pc;
    dataType type;
    void *hdr;    // input buffer index
    int hdrlen;   // spectrum buffer index
    void *ptr;    // input buffer index
    int len;      // spectrum buffer index
    void set(connectionClass *a, void *b, int c, dataType d){pc = a; ptr = b; len = c; type = d;};
    void set(connectionClass *a, dataType d, void *b, int c){pc = a; ptr = b; len = c; type = d;};
    void set(connectionClass *a, dataType dt, void *ph, int lh, void *pd, int ld)
    	{pc = a; type = dt; hdr = ph; hdrlen = lh; ptr = pd; len = ld;};
} send_element;

class dispatcherClass {

    pthread_mutex_t mutexDataAvailable; // unlock to signal data available
    pthread_mutex_t mutexControl;       // radio control lock

    Queue<send_element,15> spQ;

    pthread_t dispatch_thread;

public:
    static void *dispatch(void *arg);

    int init(void) {
        pthread_mutex_init(&mutexDataAvailable, NULL);
        pthread_mutex_lock(&mutexDataAvailable);

        pthread_mutex_init(&mutexControl, NULL);
        pthread_mutex_unlock(&mutexControl);

//        pthread_create(&dispatch_thread , NULL, dispatch, (void *) this);
   }

    void enQ(connectionClass *pc, void *ptr, int len, dataType type){ // call from main loop
        send_element sp_el;
        pthread_mutex_lock(&mutexControl);          // lock control data

// push a new element onto the spectrum processing queue
        sp_el.set(pc,type,0,0, ptr,len);
        spQ.push(sp_el);

        pthread_mutex_unlock(&mutexDataAvailable);  // signal data available
        pthread_mutex_unlock(&mutexControl);      // unlock control data
    };

    void enQ(connectionClass *pc, dataType type, void *hdrptr, int hdrlen, void *ptr, int len){ // call from main loop
        send_element sp_el;
        pthread_mutex_lock(&mutexControl);          // lock control data

// push a new element onto the spectrum processing queue
        sp_el.set(pc,type, hdrptr,hdrlen, ptr,len);
        spQ.push(sp_el);

        pthread_mutex_unlock(&mutexDataAvailable);  // signal data available
        pthread_mutex_unlock(&mutexControl);      // unlock control data
    };

    send_element deQ(void) { // call from thread
        send_element el;
        memset(&el,0,sizeof(send_element));
        pthread_mutex_lock(&mutexDataAvailable);  // block on data available
        pthread_mutex_lock(&mutexControl);          // lock control data

        if(spQ.empty())
            memset(&el,0,sizeof(send_element));
        else {
            el = spQ.front();
            spQ.pop();
        }
        if(!spQ.empty())
            pthread_mutex_unlock(&mutexDataAvailable); // more data in queue, unblock threads
        pthread_mutex_unlock(&mutexControl);        // unlock control data
        return el;
    };

    void reset(void){
        pthread_mutex_lock(&mutexControl);          // lock control data
        while(!spQ.empty()) spQ.pop();
        pthread_mutex_unlock(&mutexControl);      // unlock control data
    };
};

extern dispatcherClass dispatcher;
#endif

