// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

/*
The main_loop thread streams the data from the external board into PC memory.

init_main_loop(void)
main_loop(void *arg) - main real data infinite transfer loop started as thread
fake_main_loop(void *arg) - fake test data transfer loop, runs when board not connected
void ShowStats() - periodically called to show transfer statistics in console window
kbRead - count kilobytes transfered
*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "global.h"
#include "radio.h"       // import radio.enQ()
#include "spectrum.h"    // import spectrum.enQ()
#include "openFX3.h"     // import fx3dev, EndPt
#include "main_loop.h"
#include "monitor.h"
#include "webServer.h"
#include <pthread.h>

// transfer variables
PUCHAR			*buffers;                       // export, main data buffers
PUCHAR			*contexts;
OVERLAPPED		inOvLap[QUEUE_SIZE];

int idx;            // queue index              // export
unsigned long IDX;  // absolute index
pthread_t main_loop_thread[2], ShowStats_thread[1];

// transfer statistic variables
double kbRead = 0;
LARGE_INTEGER StartingTime;
unsigned long BytesXferred = 0;
unsigned long Failures = 0;

void *tShowStats(void *args);       // thread function
const int callShowStatsRate = 32*QUEUE_SIZE;
pthread_mutex_t mutexShowStats;     // unlock to show stats

// test data variable
#define FAKE_TABLE_SIZE (128*1024)
double *sine_table, dc, ftone = 2e6;
unsigned short *sine_table_offset;
int COS_OFF;
bool inject_tone;
PUSHORT			*buffersDBG;

int init_main_loop(void) {

    // if inject tone true:
    // tone instead of real data with board connected
    // tone instead of sweep for fake data without board connected
    inject_tone = true;
    inject_tone = false;

    // Allocate the arrays needed for input
    buffers		= new PUCHAR[QUEUE_SIZE];
    contexts   = new PUCHAR[QUEUE_SIZE];

    if(EndPt) { // real data
        long pktSize = EndPt->MaxPktSize;
        EndPt->SetXferSize(g.transferSize);
        long ppx = g.transferSize/pktSize;
        printf("init_main_loop, buffer transferSize = %ld. packet size = %ld. packets per transfer = %ld\n"
            ,g.transferSize,pktSize,ppx);
    } else // fake data
        printf("buffer transferSize = %ld bytes.\n",g.transferSize);

    // Allocate all the buffers for the input queues
    for (int i=0; i< QUEUE_SIZE; i++) {
//      if( !(buffers[i] = (UCHAR *)malloc(sizeof(UCHAR)*g.transferSize))) {
        ALLOCATE(buffers[i],UCHAR,g.transferSize,init_main_loop)
        inOvLap[i].hEvent = CreateEvent(NULL, false, false, NULL);
    }

    // Allocate fake data sine table
   ALLOCATE(sine_table,double,FAKE_TABLE_SIZE,init_main_loop)
   ALLOCATE(sine_table_offset,unsigned short,FAKE_TABLE_SIZE,init_main_loop)
//    sine_table = ( double *) malloc(FAKE_TABLE_SIZE * sizeof( double));
//    sine_table_offset = ( unsigned short *) malloc(FAKE_TABLE_SIZE * sizeof( unsigned short));
    dc = 32*1024;
    double pi = 4*atan(1);
    double dphi = 2*pi/FAKE_TABLE_SIZE;
    for (int i=0; i< FAKE_TABLE_SIZE; i++)
        sine_table[i] = 300*sin(i*dphi);
    for (int i=0; i< FAKE_TABLE_SIZE; i++)
        sine_table_offset[i] = 10*sin(i*dphi)+dc;

    buffersDBG		= new PUSHORT[QUEUE_SIZE];
    if(g.fs == 1e8) ftone = 3.125e6;
	int N = g.transferSize*QUEUE_SIZE;
    double feven = round(ftone*N/g.fs)*g.fs/N;
    double fbbeven = round(500.*N/(double)g.fs)*g.fs/N;
    int len = g.transferSize/sizeof(short);
    int idx = 0;
    dphi = 2*pi/g.fs;
    for (int i=0; i< QUEUE_SIZE; i++) {
        buffersDBG[i] = new USHORT[len];
        for(int n=0;n<len;n++){
            buffersDBG[i][n] = 500*sin(idx*dphi*feven)*sin(idx*dphi*fbbeven)+dc;
            idx++;
        }
    }
    return 1;
}

int start_main_loop(void *main_loopf(void *arg)) { // pass in the main_loopf thread function

   kbRead = 0; // zeros the kilobytes counter

   pthread_mutex_init(&mutexShowStats, NULL);
   pthread_mutex_lock(&mutexShowStats);

   Sleep(500);

    int rc, t = 0;
    rc = pthread_create(&ShowStats_thread[0], NULL, tShowStats, (void *)t);
    g.pause = false;
    rc = pthread_create(&main_loop_thread[0], NULL, main_loopf, (void *)t);

   if(main_loopf == main_loop) {
   fx3FWControl(FX3Start);       // start the firmware
   }
   QueryPerformanceCounter(&StartingTime);  // set the start time

    return 1; // init success
}

void *main_loop(void *arg) {
    if(inject_tone)
        printf("Fake data, inject tone.\n");
      else
         printf("Main loop started.\n");
        // Queue-up the first batch of transfer requests
        for (int n=0; n< QUEUE_SIZE; n++) {
            contexts[n] = EndPt->BeginDataXfer(buffers[n], g.transferSize, &inOvLap[n]);
            if (EndPt->NtStatus || EndPt->UsbdStatus) {// BeginDataXfer failed
                printf("Xfer request rejected. STATUS = %ld %ld",EndPt->NtStatus,EndPt->UsbdStatus);
                pthread_exit(NULL);
            }
        }
        idx = 0;    // buffer cycle index
        IDX = 1;    // absolute index

    // The infinite xfer loop.
    while ( true ) {
        LONG rLen = g.transferSize;	// Reset this each time through because
        // FinishDataXfer may modify it
        if (!EndPt->WaitForXfer(&inOvLap[idx], 5000)) { // block on transfer
            EndPt->Abort(); // abort if timeout
            if (EndPt->LastError == ERROR_IO_PENDING)
                WaitForSingleObject(inOvLap[idx].hEvent, 5000);
            break;
        }

        if (EndPt->Attributes == 2) { // BULK Endpoint
            if (EndPt->FinishDataXfer(buffers[idx], rLen, &inOvLap[idx], contexts[idx])) {
                if(inject_tone)
                    memcpy(buffers[idx],buffersDBG[idx],g.transferSize);
                BytesXferred += rLen;
                if(rLen < g.transferSize) printf("rLen = %d   rLen = %d   rLen = %d   rLen = %d   rLen = %d\n",rLen);
            } else
                Failures++;
        }

        radio.enQ(idx);     // play the radio
        spectrum.enQ(idx);  // process waterfall data

			int rc = ResetEvent(&inOvLap[idx]); // might help with tripple trace
			// ResetEvent succeeded if rc != 0
        // Re-submit this queue element to keep the queue full
        contexts[idx] = EndPt->BeginDataXfer(buffers[idx], g.transferSize, &inOvLap[idx]);
        if (EndPt->NtStatus || EndPt->UsbdStatus) { // BeginDataXfer failed
            printf("Xfer request rejected. NTSTATUS = %u",EndPt->NtStatus);
            break;
        }
        if ((IDX%callShowStatsRate)==0) { //Only update the stats output at the call rate
            pthread_mutex_unlock(&mutexShowStats);
        }
        ++idx;
        ++IDX;
        idx = idx%QUEUE_SIZE;
        if(IDX == MONITOR_LEN) monitor.dump();

    }  // End of the infinite loop

    fx3FWControl(FX3Reset); // reset the firmware
    Sleep(200);
    pthread_exit(NULL);
}

bool device_not_connected = false;

void *fake_main_loop(void *arg) {

    if(inject_tone)
        printf("Fake data, inject tone.\n");
    else
        printf("Fake data, inject frequency sweep.\n");

    device_not_connected = true;

    HANDLE hTimer = NULL;
    LARGE_INTEGER liDueTime,nowTime;
    double lasttime, nowtime, timeIncrement =
        double(g.transferSize)/double(g.fs*sizeof(short))*1e7/1.0001;

    // Create an unnamed waitable timer.
    hTimer = CreateWaitableTimer(NULL, TRUE, NULL);
    if (NULL == hTimer) {
        printf("CreateWaitableTimer failed (%d)\n", GetLastError());
    }
    liDueTime.QuadPart = -timeIncrement;

    if (!SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, 0)) {
        printf("SetWaitableTimer failed (%d)\n", GetLastError());
    }

    QueryPerformanceCounter(&StartingTime);  // set the start time
    lasttime = (double)StartingTime.QuadPart*count2usec*10;

    idx = 0;    // buffer cycle index
    IDX = 1;    // absolute index

    int dm = 0,m = 0, k = 0, dk = 10;

    // The infinite xfer loop.
    while ( true ) {
        // Wait for the timer.
        if (WaitForSingleObject(hTimer, INFINITE) != WAIT_OBJECT_0)
            printf("WaitForSingleObject failed (%d)\n", GetLastError());;

        if(inject_tone)
            memcpy(buffers[idx],buffersDBG[idx],g.transferSize);
        else { // frequency sweep
            unsigned short *pshort = (unsigned short *) buffers[idx];
            int N =g.transferSize/sizeof(unsigned short);
            for(int n = 0;n < N;n++){
                pshort[n] = (unsigned short) sine_table_offset[m];
                m += dm;
                m %= FAKE_TABLE_SIZE;
            }
        }

        if(idx%1 ==0) dm++;
        if(dm > FAKE_TABLE_SIZE) dm -= FAKE_TABLE_SIZE;

        BytesXferred += g.transferSize;

        monitor.receive_time(idx,IDX,0);
        radio.enQ(idx);         // play the radio
        spectrum.enQ(idx);  // process waterfall data
         monitor.process_time(IDX, 0);

        if ((IDX%callShowStatsRate)==0) { //Only update the display at the call rate
            pthread_mutex_unlock(&mutexShowStats);
        }
        ++idx;
        ++IDX;
        idx = idx%QUEUE_SIZE;
       if(IDX == MONITOR_LEN) monitor.dump();

        lasttime += timeIncrement;
        QueryPerformanceCounter(&nowTime);  // set the start time
        nowtime = (double)nowTime.QuadPart*count2usec*10;
        double elapsedtime = lasttime - nowtime;

        if(elapsedtime < -timeIncrement ) {}
            // more than one left, do not reset the timer so that wait falls through
        else { // less than one left, reset the timer
                if(elapsedtime>0)elapsedtime = -elapsedtime-timeIncrement;
            liDueTime.QuadPart = elapsedtime;
            if (!SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, 0)) {
                printf("SetWaitableTimer failed (%d)\n", GetLastError());
            }
        }
    }  // End of the infinite loop

    pthread_exit(NULL);
}

void *tShowStats(void *args) {
    LARGE_INTEGER EndingTime;
    double timeElapsed = 0;

    while(true) {
        pthread_mutex_lock(&mutexShowStats);
        double timeStart = double(StartingTime.QuadPart)*count2sec;
        QueryPerformanceCounter(&EndingTime);
        double timeElapsed = double(EndingTime.QuadPart)*count2sec - timeStart;
        kbRead += double(BytesXferred)/1000.;
            double MBps = (double)kbRead/timeElapsed/1000;
        printf("%s, %6.3f MB/s, UpHr %.3f, Conn %d of %d",monitor.time_stamp(),MBps,timeElapsed/3600,webServer.nConnection,webServer.maxConnection);
        if(device_not_connected) {
            printf(", Device not connected, ");
            if(inject_tone)
                printf("Fake data, Inject tone\n");
            else
                printf("Fake data, Frequency sweep\n");
        } else {
            if(inject_tone)
                printf(", Device connected, Fake data, Inject tone\n");
            else
                printf("\n");
        }
        BytesXferred = 0;
//        profiler.report();
    }
}

// SET WAITABLE TIMER EXAMPLE
//
//#include <windows.h>
//#include <stdio.h>
//
//int main()
//{
//    HANDLE hTimer = NULL;
//    LARGE_INTEGER liDueTime;
//
//    liDueTime.QuadPart = -100000000LL;
//
//    // Create an unnamed waitable timer.
//    hTimer = CreateWaitableTimer(NULL, TRUE, NULL);
//    if (NULL == hTimer)
//    {
//        printf("CreateWaitableTimer failed (%d)\n", GetLastError());
//        return 1;
//    }
//
//    printf("Waiting for 10 seconds...\n");
//
//    // Set a timer to wait for 10 seconds.
//    if (!SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, 0))
//    {
//        printf("SetWaitableTimer failed (%d)\n", GetLastError());
//        return 2;
//    }
//
//    // Wait for the timer.
//
//    if (WaitForSingleObject(hTimer, INFINITE) != WAIT_OBJECT_0)
//        printf("WaitForSingleObject failed (%d)\n", GetLastError());
//    else printf("Timer was signaled.\n");
//
//    return 0;
//}
//
