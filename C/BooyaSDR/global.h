// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef GLOBAL_H
#define GLOBAL_H

#include <math.h>

extern double count2sec;
extern double count2usec;
extern double pi;

class cglobal {
    public:

    bool start;
    bool run;
    bool pause;

    double fs;
    int transferSize;
    char execName[256];

    cglobal() {
        start = false;
        run = false;
        pause = false;

         fs = 100e6;
         fs =  16e6;
         fs =  64e6;

         transferSize = 131072;

         // constants

         LARGE_INTEGER Frequency;
         QueryPerformanceFrequency(&Frequency);
         count2sec  = 1  /(double)Frequency.QuadPart;
         count2usec = 1e6/(double)Frequency.QuadPart;
         pi = 4. * atan(1);
    }
};

extern class cglobal global;


template <class TYPE, int SZ> // a non allocating queue type
struct Queue {
    TYPE element[SZ];
    int last = SZ-1;
    int first = 0;
    int count = 0;
    int inc(int *x) {
        *x = (*x+1)%SZ; };
    int dec(int *x) { *x = (*x+SZ-1)%SZ; };
    int push(TYPE nw){
        inc(&last);
        element[last] = nw;
        if(++count > SZ) {count--; inc(&first);}; // increment count, drop one if > size
    };
    void pop(void){if(count <= 0 ) { count = 0; first = 0; last = SZ-1; return; }
        else { count--;  memset(&element[first],'\0',sizeof(TYPE)); inc(&first); }};
    TYPE front(void){ return element[first]; };
    bool empty(void) { if(count == 0) return true; else return false; };
};

#endif
