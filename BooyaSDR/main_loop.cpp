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
#include "record.h"
#include "radio.h"       // import radioDataArrived()
#include "spectrum.h"    // import sp.mainDataAvailable()
#include "openFX3.h"     // import fx3dev, EndPt
#include "main_loop.h"
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
pthread_mutex_t mutexShowStats;     // unlock to show stats

// test data variable
#define FAKE_TABLE_SIZE (1024*128)
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
    contexts    = new PUCHAR[QUEUE_SIZE];

    if(EndPt) { // real data
        long pktSize = EndPt->MaxPktSize;
        EndPt->SetXferSize(global.transferSize);
        long ppx = global.transferSize/pktSize;
        printf("init_main_loop, buffer transferSize = %ld. packet size = %ld. packets per transfer = %ld\n"
            ,global.transferSize,pktSize,ppx);
    } else // fake data
        printf("buffer transferSize = %ld bytes.\n",global.transferSize);

    // Allocate all the buffers for the input queues
    for (int i=0; i< QUEUE_SIZE; i++) {
        buffers[i]        = new UCHAR[global.transferSize];
        inOvLap[i].hEvent = CreateEvent(NULL, false, false, NULL);
    }

    // Allocate fake data sine table
    sine_table = ( double *) malloc(FAKE_TABLE_SIZE * sizeof( double));
    sine_table_offset = ( unsigned short *) malloc(FAKE_TABLE_SIZE * sizeof( unsigned short));
    dc = 32*1024;
    double pi = 4*atan(1);
    double dphi = 2*pi/FAKE_TABLE_SIZE;
    for (int i=0; i< FAKE_TABLE_SIZE; i++)
        sine_table[i] = 300*sin(i*dphi);
    for (int i=0; i< FAKE_TABLE_SIZE; i++) {
        double xx = (1000.*sin(i*dphi)+dc);
        unsigned short ux = (unsigned short) xx;
//        printf("double %f, short %u\n",xx,ux);
        sine_table_offset[i] = (unsigned short)(1000.*sin(i*dphi)+dc);
    }
//    for (int i=0; i< FAKE_TABLE_SIZE; i++) {
//        double xx = (1000.*sin(i*dphi)+dc);
//        unsigned short ux = (unsigned short) xx;
//        printf("double %f, short %u\n",xx,ux);
//        sine_table_offset[i] = (unsigned short)(1000.*sin(i*dphi)+dc);
//    }

    buffersDBG		= new PUSHORT[QUEUE_SIZE];
    if(global.fs == 1e8) ftone = 3.125e6;

    // Allocate all the buffers for the input queues
    for (int i=0; i< QUEUE_SIZE; i++) {
        buffers[i]        = new UCHAR[global.transferSize];
        inOvLap[i].hEvent = CreateEvent(NULL, false, false, NULL);
    }

    int kidx = 0, strd = round(FAKE_TABLE_SIZE*ftone/global.fs);
    int len = global.transferSize/sizeof(short);
    for (int i=0; i< QUEUE_SIZE; i++) {
        buffersDBG[i] = new USHORT[len];
        for(int n=0;n<len;n++) {
            buffersDBG[i][n] = sine_table_offset[kidx];
            kidx += strd;
            kidx %= FAKE_TABLE_SIZE;
        }
    }
}

int start_main_loop(void *main_loopf(void *arg)) { // pass in the main_loopf thread function

    kbRead = 0; // zeros the kilobytes counter

    pthread_mutex_init(&mutexShowStats, NULL);
    pthread_mutex_lock(&mutexShowStats);

    int rc, t = 0;
    rc = pthread_create(&ShowStats_thread[0], NULL, tShowStats, (void *)t);

    global.start = true;
    global.pause = false;
    rc = pthread_create(&main_loop_thread[0], NULL, main_loopf, (void *)t);

    return 1; // init success
}

void *main_loop(void *arg) {

    if(inject_tone)
        printf("Fake data, inject tone.\n");

    int callShowStatsRate = 32*QUEUE_SIZE;

    if(global.start) { // start the device data stream

        // Queue-up the first batch of transfer requests
        for (int n=0; n< QUEUE_SIZE; n++) {
            contexts[n] = EndPt->BeginDataXfer(buffers[n], global.transferSize, &inOvLap[n]);
            if (EndPt->NtStatus || EndPt->UsbdStatus) {// BeginDataXfer failed
                printf("Xfer request rejected. STATUS = %ld %ld",EndPt->NtStatus,EndPt->UsbdStatus);
                pthread_exit(NULL);
            }
        }
        global.start = false;
        fx3FWControl(FX3Start);       // start the firmware
        global.run = true;
        idx = 0;    // buffer cycle index
        IDX = 1;    // absolute index
        QueryPerformanceCounter(&StartingTime);  // set the start time
    }

    // The infinite xfer loop.
    while ( true ) {
        LONG rLen = global.transferSize;	// Reset this each time through because
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
                    memcpy(buffers[idx],buffersDBG[idx],global.transferSize);
                BytesXferred += rLen;
                if(rLen < global.transferSize) printf("rLen = %d\n",rLen);
            } else
                Failures++;
        }

        radioDataArrived();         // play the radio
        sp.mainDataAvailable(idx);  // process waterfall data
        record.dataAvailable(idx);

        // Re-submit this queue element to keep the queue full
        contexts[idx] = EndPt->BeginDataXfer(buffers[idx], global.transferSize, &inOvLap[idx]);
        if (EndPt->NtStatus || EndPt->UsbdStatus) { // BeginDataXfer failed
            printf("Xfer request rejected. NTSTATUS = %u",EndPt->NtStatus);
            break;
        }
        if ((IDX%callShowStatsRate)==0) { //Only update the display at the call rate
            pthread_mutex_unlock(&mutexShowStats);
            if ( !global.run ) break;
        }
        ++idx;
        ++IDX;
        idx = idx%QUEUE_SIZE;
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
        double(global.transferSize)/double(global.fs*sizeof(short))*1e7;

    // Create an unnamed waitable timer.
    hTimer = CreateWaitableTimer(NULL, TRUE, NULL);
    if (NULL == hTimer)
    {
        printf("CreateWaitableTimer failed (%d)\n", GetLastError());
//        return 1;
    }
    liDueTime.QuadPart = -timeIncrement;

    if (!SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, 0))
    {
        printf("SetWaitableTimer failed (%d)\n", GetLastError());
 //       return 2;
    }

    const int callShowStatsRate = 16*QUEUE_SIZE;

    if(global.start) { // start the device data stream
        global.start = false;
        global.run = true;
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
            memcpy(buffers[idx],buffersDBG[idx],global.transferSize);
        else { // frequency sweep
            unsigned short *pshort = (unsigned short *) buffers[idx];
            int N =global.transferSize/sizeof(unsigned short);
            for(int n = 0;n < N;n++){
                pshort[n] = (unsigned short) sine_table_offset[m];
                m += dm;
                m %= FAKE_TABLE_SIZE;
            }
        }

        if(idx%1 ==0) dm++;
        if(dm > FAKE_TABLE_SIZE) dm -= FAKE_TABLE_SIZE;

        BytesXferred += global.transferSize;
        radioDataArrived(); // play the radio, signal the radio loop
        sp.mainDataAvailable(idx); // signal the spectrum display loop
        RECORD_DATA_AVAILABLE

        if ((IDX%callShowStatsRate)==0) { //Only update the display at the call rate
            pthread_mutex_unlock(&mutexShowStats);
            if ( !global.run ) break;
        }
        ++idx;
        ++IDX;
        idx = idx%QUEUE_SIZE;

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
         //       return 2;
            }
        }
    }  // End of the infinite loop

    pthread_exit(NULL);
}

void *tShowStats(void *args)
{
    LARGE_INTEGER EndingTime;
    double timeElapsed = 0;

    while(true) {
        pthread_mutex_lock(&mutexShowStats);
//        monitor.monitorQ();
        if(global.run == false)
            pthread_exit(NULL);

        double timeStart = double(StartingTime.QuadPart)*count2sec;
        QueryPerformanceCounter(&EndingTime);
        double timeElapsed = double(EndingTime.QuadPart)*count2sec - timeStart;
        kbRead += double(BytesXferred)/1000.;
            double mBps = (double)kbRead/timeElapsed/1000;
        printf("Read %.0f kB/%4.3f s, %6.3f Mb/s, %ld fails",
            kbRead,timeElapsed,mBps,Failures);
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
