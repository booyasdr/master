// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#include <stdio.h>
#include "wx_pch.h"
#include "thisApp.h"
#include "global.h"
#include "radio.h"
#include "radioUser.h"
#include "spectrum.h"
#include "spectrumUser.h"
#include "thisApp.h"
#include "main_loop.h"
#include "openfx3.h"
#include "openfx2.h"
#include "fftw3.h"
#include "monitor.h"
#include "webServer.h"

HWND hWnd; // console window handle

static void sighandler(int signum) {
	fprintf(stderr, "Signal caught, exiting!\n");
	Sleep(300);
}

void openConsoleWindow() {
	char title[256];
// setup console window
    SetConsoleCtrlHandler( (PHANDLER_ROUTINE) sighandler, TRUE );
    hWnd = GetConsoleWindow();

	SetWindowPos(hWnd,HWND_TOP,400,100,900,800,0); // Console window
	sprintf(title," Booya %d MHz Console",(int)round(g.fs/1e6));
	SetWindowTextA(hWnd,title); // Console window
}

//(*AppHeaders
#include "spectrumFrame.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxFX3App);

bool wxFX3App::OnInit() {
   g.init(argc,argv);
//   if(argc > 1) {
//     if(!strcmp(argv[1],"fx2_16")) {
//        g.fs = 16e6;
//        g.transferSize = 131072;
//     } else if(!strcmp(argv[1],"fx3_64")) {
//        g.fs = 64e6;
//        g.transferSize = 131072*2;
//     } else if(!strcmp(argv[1],"fx3_100")) {
//        g.fs = 100e6;
//        g.transferSize = 131072*4;
//     } else {
//        g.fs = 64e6;
//        g.transferSize = 131072*2;
//     }
//   }
   strcpy(g.execName,argv[0]);
   bool wxsOK = true;
   if(g.gui) {
      //(*AppInitialize
      bool wxsOK = true;
      wxInitAllImageHandlers();
      if ( wxsOK )
      {
      	spectrumFrame* Frame = new spectrumFrame(0);
      	Frame->Show();
      	SetTopWindow(Frame);
      }
      //*)
      wxsOK = true;
   } else {
      wxsOK = true;
   }
   openConsoleWindow();

   if(g.server_mode) webServer.init("default","0.0.0.0",2008);
   printf("MODE: server is %s, gui is %s\n",(g.server_mode ? "ON" : "OFF"),(g.gui ? "ON" : "OFF"));
   if(!g.server_mode && !g.gui) printf("WARNING: program has no output if both the server and gui are off\n");

   fftwf_set_timelimit(30);
   fftwf_import_wisdom_from_filename("wisdom");

   printf("%s\nBooya fs = %.0f\n",monitor.time_stamp(),g.fs);
   bool FXisopen = false;
   if(g.fs <= 16*1000*1000) { // FX2
      if(!openFX2()) {                    // open the fx2 device
         printf("initFX2() failed, starting fake main loop.\n");
      } else {
         init_main_loop();
         spUser.init();
         spectrum.init();
         radio.init();
         localRadioUser.init();
         start_main_loop(main_loop_fx2);
         FXisopen = true;
      }
      } else { // FX3
      if(!openFX3()) {                    // open the fx3 device
         printf("initFX3() failed, starting fake main loop.\n");
      } else {
         init_main_loop();
         spUser.init();
         spectrum.init();
         radio.init();
         localRadioUser.init();
         start_main_loop(main_loop);
         FXisopen = true;
      }
   }
   if(!FXisopen) {
      fprintf(monitor.log,"Device open Failure\n");
      fclose(monitor.log);
      printf("fake fake fake\n");
      init_main_loop();
      spUser.init();
      spectrum.init();
      radio.init();
      localRadioUser.init();
      start_main_loop(fake_main_loop);
   }
   fftwf_export_wisdom_to_filename("wisdom");

   return wxsOK;
}
