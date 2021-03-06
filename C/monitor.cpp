// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

/* Record processing times and buffer ids to measure data monitor and latency
*/

#include "monitor.h"
#include "global.h"

//class profileClass profiler;
class monitor monitor;

monitor::monitor() {

    LARGE_INTEGER  EndingTime, Start;
//    LARGE_INTEGER  ElapsedMicroseconds;

    QueryPerformanceCounter(&Start);
    startTime = (double) Start.QuadPart *count2usec;

    if(!monitorOn) return;
    sprintf( filename, "c:\\sdr\\monitor.dat");
    file = fopen(filename,"w");

    sprintf( filename, "c:\\sdr\\log.txt");
    log = fopen(filename,"w");

    rcv_idx = 0;
    proc_idx = 0;
    monitor_data = new monitor_entry[MONITOR_LEN];
    ZeroMemory(monitor_data,MONITOR_LEN*sizeof(monitor_entry));

//    LARGE_INTEGER  ElapsedMicroseconds;
    QueryPerformanceCounter(&Start);
    Sleep(10);

    QueryPerformanceCounter(&EndingTime);
//    ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - start_time.QuadPart;
//    double latencyusec = double(ElapsedMicroseconds.QuadPart * 1000000)/double(Frequency.QuadPart);
}

void monitor::receive_time(int idx, int IDX, void *buffer) {
    if(!monitorOn) return;
    if(rcv_idx >= MONITOR_LEN) return;
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
    if(proc_idx >= MONITOR_LEN) return;
    struct monitor_entry* entry = &monitor_data[proc_idx++];
    LARGE_INTEGER now;
    entry->radioThread_id = tid;
    entry->process_buffer = buffer;
    QueryPerformanceCounter(&now);
    entry->process_time.QuadPart = now.QuadPart - start_time.QuadPart;
}

void monitor::dump( void ) {
    if(!monitorOn) return;
    monitorOn = false;
    printf("dump monitor\n");
    if(!file) return;
    double tlast = 0;
    for(int n =0; n<MONITOR_LEN;n++) {
        double ttime = double(monitor_data[n].transfer_time.QuadPart-
            monitor_data[0].transfer_time.QuadPart)*count2usec;
        double ptime = double(monitor_data[n].process_time.QuadPart-
            monitor_data[0].transfer_time.QuadPart)*count2usec;
        double dtime = ttime-tlast;
        tlast = ttime;
        double latency = ptime - ttime;

        fprintf(file,"%d %d %d %d %d %.1f %.1f %.1f %.1f\n",
            monitor_data[n].idx,
            monitor_data[n].IDX,
            monitor_data[n].radioThread_id,
            monitor_data[n].transfer_buffer,
            monitor_data[n].process_buffer,
            ttime,
            ptime,
            dtime,
            latency);
    }
    fclose(file);
}
