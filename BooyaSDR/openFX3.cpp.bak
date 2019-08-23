// MIT License Copyright (c) 2017 Booya Corp.
// booyasdr@gmail.com, http://booyasdr.sf.net

/*
fx3dev - global pointer to the fx3 device class
initFX3() - initializes fx3dev, called externally
GetFx3Device() - opens fx3dev, called by initFX3()
fx3FWControl(fx3FWControl command) - controls fx3 firmware
    with commands: FX3Start, FX3Stop, FX3Reset
AbortXferLoop() - cleanup when transfer loop stops
*/

#include <sys/stat.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>

#include "global.h"
#include "openfx3.h"

using namespace std;

void fx3FWControl(FX3Control command) { // firmware control
        long lgt = 0;
        fx3dev->ControlEndPt->ReqCode = command;
        fx3dev->ControlEndPt->Write((PUCHAR)0,lgt);
}

void GetFx3Device(void);    // open the device, called in initFX3()

CCyFX3Device        *fx3dev = NULL;
const int			VENDOR_ID	    = 0x04B4;
const int			STREAMER_ID	    = 0x00F1;
const int			BOOTLOADER_ID	= 0x00F3;
CCyUSBEndPoint		*EndPt;
bool				bHighSpeedDevice;
bool				bSuperSpeedDevice;

int openFX3() {

    fx3dev = new CCyFX3Device;              // instantiate the device
    if (fx3dev == NULL) return 0;           // return if failed
    int n = fx3dev->DeviceCount();          // return if no devices connected
    if(n == 0) { printf("Device Count = 0, Exit\n"); return 0; }
    GetFx3Device();                         // open class

   char fwname[] = "slavefifo.img";  // firmware file name
 	if(!fx3dev->IsBootLoaderRunning()) { // brute force reset
        fx3FWControl(FX3Reset);       // reset the fx3 firmware
        printf("Reset Device\n");
        Sleep(300);
        fx3dev->Close();            // close class
        delete fx3dev;              // destroy class
        Sleep(300);
        fx3dev = new CCyFX3Device;  // create class
        GetFx3Device();             // open class
	}
    FX3_FWDWNLOAD_ERROR_CODE dlf;
 	if(fx3dev->IsBootLoaderRunning()) {
         dlf = fx3dev->DownloadFw(fwname, RAM);
        Sleep(500); // wait for download to finish
 	}
    if(dlf == 0 ) {
        struct stat stbuf;
        stat(fwname,&stbuf);
        char *timestr;
        timestr = ctime(&stbuf.st_mtime);
        printf("Loaded NEW FIRMWARE %s %s",fwname,timestr);
    } else if(dlf != 0 ) printf("OLD FIRMWARE\n");

    GetFx3Device();         // open class with new firmware
 	if(!fx3dev->IsOpen()) {
        printf("Failed to open device\n");
        return 0;
 	}
    EndPt = fx3dev->BulkInEndPt;
    if(!EndPt) {
        printf("No Bulk In end point\n");
        return 0;      // init failed
    }

    return 1; // init success

}

void GetFx3Device() {   // open class

    if (fx3dev == NULL) return;
    int n = fx3dev->DeviceCount();
    // Walk through all devices looking for VENDOR_ID/STREAMER_ID
    if(n == 0) { printf("Device Count = 0, Exit\n"); return; }

 	fx3dev->Open(0);
// go down the list of devices to find our device
    for (int i=1; i<=n; i++) {
        cout << hex << fx3dev->VendorID << " "
            << hex << fx3dev->ProductID << " " << fx3dev->FriendlyName<< '\n';
        if ((fx3dev->VendorID == VENDOR_ID) && (fx3dev->ProductID == STREAMER_ID))
            break;
        if ((fx3dev->VendorID == VENDOR_ID) && (fx3dev->ProductID == BOOTLOADER_ID))
            break;
        fx3dev->Open(i);
    }
}
