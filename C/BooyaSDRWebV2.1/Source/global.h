// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef GLOBAL_H
#define GLOBAL_H
#define COMPRESS_AUDIO
#define U8NEW

#include <math.h>

extern double count2sec;
extern double count2usec;
extern double pi;

class classGlobal {
    public:

    bool gui, server_mode; // software can run in any combination of gui and server_mode
   int maxConnection;
    bool pause;
    double fs;
    double Vpp;
    int transferSize;
    char execName[256];
    double webrx_fft_size_kHz = 1; // range 1,2,4,8

    classGlobal() {
        pause = false;

        gui = true;              // gui on, off
        server_mode = true;      // web server on, off
         maxConnection = 8;       // number of web connections

         fs =  64e6;
         transferSize = 131072;
         Vpp = 1.5;

// constants
         LARGE_INTEGER Frequency;
         QueryPerformanceFrequency(&Frequency);
         count2sec  = 1  /(double)Frequency.QuadPart;
         count2usec = 1e6/(double)Frequency.QuadPart;
         pi = 4. * atan(1);

// read configuration file
         FILE* fid = fopen("BooyaConfiguration.txt","r");
         char s[256],*a, *key;
         int x = 1;
//         printf("BooyaConfiguration.txt = %d\n",fid);
         if(fid) {
            while(fgets(s,256,fid)) {
               if(a = strstr(s,"//")) *a = '\0';
               x = 1;
               key = "gui";
               if(a = strstr(s,key)) {
                  a = a + strlen(key);
                  sscanf(a,"%d",&x);
                  gui = (x > 0 ? true : false);
               }
               x = 1;
               key = "server";
               if(a = strstr(s,key)) {
                  a = a + strlen(key);
                  sscanf(a,"%d",&x);
                  server_mode = (x > 0 ? true : false);
               }
               x = 1;
               key = "maxConnection";
               if(a = strstr(s,key)) {
                  a = a + strlen(key);
                  sscanf(a,"%d",&maxConnection);
               }
            }
            fclose(fid);
         }
    }
};

extern class classGlobal g;

#define Q_H
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
        else { count--;   inc(&first); }};
//        else { count--;  memset(&element[first],'\0',sizeof(TYPE)); inc(&first); }};
    TYPE front(void) { return element[first]; };
    bool empty(void) {  return (count == 0); };
    // initialize Queue
    Queue(){
      last = SZ-1;
      first = 0;
      count = 0;
    };
};

// allocation macros
#define ALLOCATE(pointer,type,size,function) if(!(pointer = (type *)malloc(sizeof(type)*(size)))) { \
         printf("ALLOCATION ERROR of pointer %s in function %s\n",#pointer,#function); \
         printf("Press any key to exit"); \
         getchar();exit(0);} \
         memset(pointer,'\0',sizeof(type)*size);

#define ALLOCATE_FFTWF(pointer,type,size,function) if(!(pointer = (type *)fftwf_malloc(sizeof(type)*(size)))) { \
         printf("ALLOCATION ERROR of pointer %s in function %s\n",#pointer,#function); \
         printf("Press any key to exit"); \
         getchar(); exit(0); } \
         memset(pointer,'\0',sizeof(type)*size);


#endif
