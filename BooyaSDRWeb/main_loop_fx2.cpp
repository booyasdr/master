#include <stdio.h>
#include <sys/time.h>

#include "openFX2.h"
#include "global.h"
#include "main_loop.h" // buffers, idx
#include <lusb0_usb.h>
#include "radio.h"
#include "spectrum.h"

void *main_loop_fx2(void *arg)
{
    const int callShowStatsRate = round(2*32*QUEUE_SIZE*g.fs/64/1000/1000);
    int nusbbuf = QUEUE_SIZE;

    int ep = 6;
    ep|=0x80; // set to in
    unsigned int ret, timeout=1000;
    int tsub = 0, trep = 0;
    void *context[nusbbuf];
    for (tsub = 0; tsub < nusbbuf; tsub++) {
        context[tsub]= NULL;
        ret = usb_bulk_setup_async(fx2dev.usbhdl, &context[tsub],
                             (unsigned char) ep);
    }

    timeval start_tv,end_tv;
    gettimeofday(&start_tv,NULL);

     for (tsub = 0; tsub < nusbbuf-1; tsub++) {
        void *p = (void *)buffers[tsub];
        ret = usb_submit_async(context[tsub],(char *) p, g.transferSize);
    }

    idx = 0;    // buffer cycle index
    IDX = 1;    // absolute index
    QueryPerformanceCounter(&StartingTime);  // set the start time
/////////////////////////   Start Main Loop    //////////////////////////////////////
    while( true)
    {
        ret = usb_submit_async(context[tsub],( char *) buffers[tsub],  g.transferSize);
        tsub++;
        if (tsub >= nusbbuf) tsub = 0;

        if(ret < 0) {printf("usb_bulk_submit_async error\n"); break; }

        ret = usb_reap_async(context[trep++], timeout);
        if (trep >= nusbbuf) trep = 0;
        BytesXferred += ret;

        if (ret < g.transferSize) {
            printf("usb_reap_async ret = %d tsub = %d trep = %d \n",ret,tsub,trep);
//            break;
        }

        radio.enQ(idx); // play the radio
        spectrum.enQ(idx);  // process waterfall data

        if ((IDX%callShowStatsRate)==0) { //Only update the display at the call rate
            pthread_mutex_unlock(&mutexShowStats);
        }
        ++idx;
        ++IDX;
//        if(IDX == MONITOR_LEN) monitor.dump();
        idx = idx%QUEUE_SIZE;
   }

/////////////////////////    End Main Loop    //////////////////////////////////////
/////////////////////////    Start last reap  //////////////////////////////////////

    for (tsub = 0; tsub < nusbbuf-1; tsub++) {
        ret = usb_reap_async(context[trep++], timeout);
        if (trep >= nusbbuf) trep = 0;
    }
/////////////////////////    End last reap  //////////////////////////////////////
	int interface=0, alt_interface=1;    // = 1 for bulk read
    for (tsub = 0; tsub < nusbbuf; tsub++)  usb_free_async(&context[tsub]);
	usb_release_interface(fx2dev.usbhdl,interface);

    pthread_exit(NULL);

} // main
