//#include "webServer.h"
#include "dispatcher.h"

dispatcherClass dispatcher;

void *dispatcherClass::dispatch(void *args) {
   dispatcherClass *p = (dispatcherClass *) args;

   Sleep(200);
   while (1) {
      send_element el = p->deQ();
      if(el.ptr)
         if(el.type == spec)
#ifdef U8NEW
            el.pc->sendWSData((char *) "FFT",(char *)el.hdr, el.hdrlen,(char *)el.ptr, el.len);
#else
            el.pc->sendWSData((char *) "FFT",(char *)el.ptr, el.len);
#endif

         else if(el.type == audio)
            el.pc->sendWSData((char *) "AUD",(char *)el.ptr, el.len);
   }
   pthread_exit(NULL);
   return NULL;
}
