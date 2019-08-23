// MIT License Copyright (c) 2016 Booya Corp.
// booyasdr@gmail.com, http:\\booyasdr.sf.net

/* Record processing times and buffer ids to measure data monitor and latency
*/

#include "monitor.h"

class monitor monitor;

monitor::monitor() {

    calibrate = true;
    calibrate = false;


    LARGE_INTEGER  EndingTime, Start;
//    LARGE_INTEGER  ElapsedMicroseconds;
    QueryPerformanceFrequency(&Frequency);
    count2usec = 1e6/(double) Frequency.QuadPart;

    QueryPerformanceCounter(&Start);
    startTime = (double) Start.QuadPart *count2usec;


    if(!monitorOn) return;
    sprintf( filename, "monitor.dat");
    rcv_idx = 0;
    proc_idx = 0;
    monitor_data = new monitor_entry[monitor_LEN];
    ZeroMemory(monitor_data,monitor_LEN*sizeof(monitor_entry));
    file = fopen(filename,"w");

//    LARGE_INTEGER  ElapsedMicroseconds;
    QueryPerformanceCounter(&Start);
    Sleep(10);

    QueryPerformanceCounter(&EndingTime);
//    ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - start_time.QuadPart;
//    double latencyusec = double(ElapsedMicroseconds.QuadPart * 1000000)/double(Frequency.QuadPart);


}

void monitor::receive_time(int idx, int IDX, void *buffer) {
    if(!monitorOn) return;
    if(rcv_idx >= monitor_LEN) return;
    struct monitor_entry* entry = &monitor_data[rcv_idx++];
    LARGE_INTEGER now;
    entry->idx = idx;
    entry->IDX = IDX;
    entry->transfer_buffer = buffer;
    QueryPerformanceCounter(&now);
    if(IDX == 0) start_time.QuadPart = now.QuadPart;
    entry->transfer_time.QuadPart = now.QuadPart - start_time.QuadPart;
    }

void monitor::process_time(ULONG tid, void *buffer) {
    if(!monitorOn) return;
    if(proc_idx >= monitor_LEN) return;
    struct monitor_entry* entry = &monitor_data[proc_idx++];
    LARGE_INTEGER now;
    entry->radioThread_id = tid;
    entry->process_buffer = buffer;
    QueryPerformanceCounter(&now);
    entry->process_time.QuadPart = now.QuadPart - start_time.QuadPart;
}

void monitor::dump( void ) {
    if(!monitorOn) return;
    printf("dump monitor\n");
    if(!file) return;
    double freq = double(Frequency.QuadPart);
    double tlast = 0;
    for(int n =0; n<monitor_LEN;n++) {
        double ttime = double(monitor_data[n].transfer_time.QuadPart-
            monitor_data[0].transfer_time.QuadPart)/freq*1e6;
        double ptime = double(monitor_data[n].process_time.QuadPart-
            monitor_data[0].transfer_time.QuadPart)/freq*1e6;
        double dtime = ttime-tlast;
        double latency = ptime - ttime;
        tlast = ttime;

        fprintf(file,"%d %d %d %d %d %.1f %.1f %.1f %.1f\n",
            monitor_data[n].idx,
            monitor_data[n].IDX,
            monitor_data[n].radioThread_id,
            monitor_data[n].transfer_buffer,
            monitor_data[n].process_buffer,
            ttime,
            dtime,
            ptime,
            latency);
    }
}
