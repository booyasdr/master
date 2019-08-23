// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

#include <stdio.h>
#include "wx_pch.h"
#include "thisApp.h"
#include "global.h"
#include "radio.h"
#include "spectrum.h"
#include "thisApp.h"
#include "main_loop.h"
#include "openfx3.h"
#include "openfx2.h"
#include "fftw3.h"
#include "record.h"

//(*AppHeaders
#include "spectrumFrame.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxFX3App);

bool wxFX3App::OnInit() {

    if(argc > 1) {
        if(!strcmp(argv[1],"fx2_16")) {
           global.fs = 16e6;
           global.transferSize = 131072/2;
        } else if(!strcmp(argv[1],"fx3_64")) {
           global.fs = 64e6;
           global.transferSize = 131072;
        } else if(!strcmp(argv[1],"fx3_100")) {
           global.fs = 100e6;
           global.transferSize = 131072;
        } else {
           global.fs = 64e6;
           global.transferSize = 131072;
        }
    }
    strcpy(global.execName,argv[0]);

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

    // start the data loop
    fftwf_import_wisdom_from_filename("wisdom");
    printf("Booya fs = %.0f\n",global.fs);
    bool FXisopen = false;
    if(global.fs <= 16*1000*1000) { // FX2
        if(!openFX2()) {                    // open the fx2 device
            printf("initFX2() failed, starting fake main loop.\n");
        } else {
            init_main_loop();
            initSpectrumf();
            initRadio();
            start_main_loop(main_loop_fx2);
            FXisopen = true;
        }
    } else { // FX3
        if(!openFX3()) {                    // open the fx3 device
            printf("initFX3() failed, starting fake main loop.\n");
        } else {
            init_main_loop();
            RECORD_INIT
            initSpectrumf();
            initRadio();
            start_main_loop(main_loop);
            FXisopen = true;
        }
    }
    if(!FXisopen) {
        printf("fake fake fake\n");
        init_main_loop();
        RECORD_INIT
        initSpectrumf();
        initRadio();
        start_main_loop(fake_main_loop);
    }
    fftwf_export_wisdom_to_filename("wisdom");

     return wxsOK;

}
