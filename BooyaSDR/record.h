// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#ifndef RECORD_H
#define RECORD_H

#include "global.h"
#include "stdio.h"
#include "main_loop.h"
#include <queue>
#include <pthread.h>

using namespace std;

#define N_RECORD 4

extern pthread_t thread_record[];
void *recordThreadf(void *args);


class recordClass {

    pthread_mutex_t mutexDataAvailable; // unlock to signal data available
    pthread_mutex_t mutexControl;
    FILE* fid;
    char filename[256];
    long written = 0, len = 1000 / 4; // one transfer is ~1ms @ 64 MHz
    long delayCount = 0, delay = 500, push = 0;
    int ridx;
    char *recbufw;      // constant
    char *recbuf;       // next record
    char **inbufs;

    queue<int> Q;

public:

   void init(void){
        len = 1000 * 8; // one transfer is ~1ms @ 64 MHz

        strcpy(filename,"c:\\sdr\\data\\rfdata.dat");
//        strcpy(filename,"c:\\jahns\\rfdata.dat");
        fid = fopen(filename,"wb");
        if(!fid) {
                printf("record open file failed, abort record\n");
                return;
        }

        recbufw = recbuf = (char *) malloc(len*global.transferSize);
        if(!recbufw) {
                printf("record malloc failed, abort record\n");
                return;
        }
        memset(recbufw,'\0',1);
        inbufs = (char **)buffers;

        static long t;
        for(int n = 0; n < N_RECORD; n++) {
            int rc = pthread_create(&thread_record[n], NULL, recordThreadf, (void *)&t);
            if (rc) {
                printf("ERROR; return code from recordThreadf() is %d\n", rc);
                break;
            }
        }
    }

    recordClass(){
        pthread_mutex_init(&mutexDataAvailable, NULL);
        pthread_mutex_lock(&mutexDataAvailable);

        pthread_mutex_init(&mutexControl, NULL);
        pthread_mutex_unlock(&mutexControl);

    };

    void dataAvailable(int inridx){ // call from main loop
        if( push >= len) return;
        pthread_mutex_lock(&mutexControl);          // lock control data

        if( delayCount > delay) {
            Q.push(inridx);
            push++;
            pthread_mutex_unlock(&mutexDataAvailable);      // unlock control data
        }
        delayCount++;
        pthread_mutex_unlock(&mutexControl);      // unlock control data
    };

    bool doRecord(void) { // call from record thread
        bool notDone = true;
        while(notDone) {
            pthread_mutex_lock(&mutexDataAvailable);  // block on data available
            pthread_mutex_lock(&mutexControl);          // lock control data
            while(!Q.empty()) {
                ridx = Q.front();
                Q.pop();
                char *recbufthis = recbuf; // this record
                recbuf += global.transferSize; // next record

                pthread_mutex_unlock(&mutexControl);          // unlock control data
//                printf("write %d, ridx %d, Qsize %d\n",written,ridx,Q.size());
                memcpy(recbufthis,inbufs[ridx],global.transferSize);
                pthread_mutex_lock(&mutexControl);          // lock control data

                written++;
                if(written >= len) {
                    notDone = false;
                    break;
                }
//                pthread_mutex_unlock(&mutexControl);          // lock control data
            }
            pthread_mutex_unlock(&mutexControl);          // lock control data
        }
        Sleep(200); // wait for all write to finish
        int w = fwrite(recbufw,1,len*global.transferSize,fid);
        printf("File write: %d bytes written to file %s\n",w,filename);
        fclose(fid);

//        return true;
    };

};

extern recordClass record;

# define DO_RECORD

#ifdef DO_RECORD
    #define RECORD_INIT record.init();
    #define RECORD_DATA_AVAILABLE record.dataAvailable(idx);
#else
    #define RECORD_INIT
    #define RECORD_DATA_AVAILABLE
#endif

#endif

