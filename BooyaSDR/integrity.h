// MIT License Copyright (c) 2016 Booya Corp.
// booyasdr@gmail.com, http:\\booyasdr.sf.net

#ifndef MONITOR_H
#define MONITOR_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define MONITOR_LEN (1000*5) // 5 seconds worth
#define NFIVESECOND 5*44100

struct monitor_entry {
    int idx;
    int IDX;
    void *transfer_buffer;
    void *process_buffer;
    LARGE_INTEGER transfer_time;
    LARGE_INTEGER process_time;
    ULONG radioThread_id;

};

class monitor {
public:
    bool monitorOn = false; // hard code monitor on and off
    char *filename;
    FILE* file;
    monitor();
    LARGE_INTEGER start_time;
    LARGE_INTEGER Frequency;
    LARGE_INTEGER  EndingTime, Start;
    double startTime;
    double count2usec = 1e6/(double) Frequency.QuadPart;
    int rcv_idx,proc_idx;
    struct monitor_entry *monitor_data;
    void receive_time(int idx, int IDX, void *buffer);
    void process_time(ULONG tid, void *buffer);
    void dump( void );

    short fiveSecondBuffer[NFIVESECOND];
    char *fiveSecondFile = "fiveSecondSound.dat";
    int rec_idx = 0;
    bool on_rec = true;
    FILE *fid;

    void record(short *data, int bytes){
        if(!on_rec) return;
        int shorts = bytes;
        if(rec_idx+bytes > NFIVESECOND) {
            bytes = NFIVESECOND - rec_idx;
            memcpy(&fiveSecondBuffer[rec_idx],data,bytes);
            fid = fopen(fiveSecondFile,"wb");
            fwrite(fiveSecondBuffer,sizeof(short),NFIVESECOND,fid);
            on_rec = false;
            fclose(fid);
        } else {
            memcpy(&fiveSecondBuffer[rec_idx],data,bytes);
            rec_idx += bytes/2;
        }
    }

    bool calibrate;

};

extern class monitor monitor;
#endif
