#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <sys/time.h>

#include "fx2dev.h"
#include <lusb0_usb.h>

CypressFX2Device fx2dev;

int openFX2(void) {
/////////////////////////   Set Clock Edge      //////////////////////////////////////
//    const char *ninvfile="bench_cinv_x38.ihx";
    const char *ninvfile="bench_ninv_x38.ihx";
    const char *file;

    file = ninvfile;
/////////////////////////   End Set Clock Edge  //////////////////////////////////////
/////////////////////////   Start FX2 Init   //////////////////////////////////////

	int arg_vend=0x4b4,arg_prod=0x8613,arg_nth=0;
	struct usb_device *usbdev=NULL;

	usb_init();
	int rv=usb_find_busses();
	if(rv<0)	{  fprintf(stderr,"usb_find_busses failed (rv=%d)\n",rv);  return(0);  }
	rv=usb_find_devices();
	if(rv<0)	{  fprintf(stderr,"usb_find_devices failed (rv=%d)\n",rv);  return(0);  }

    usbdev=USBFindDevice(arg_vend,arg_prod,arg_nth);
    if(!usbdev) { fprintf(stderr,"No unconfigured Cypress FX2 attached. Exit.\n"); return(0); }

	fprintf(stderr,"Using ID %04x:%04x on %s.    %s.\n",
		usbdev->descriptor.idVendor,usbdev->descriptor.idProduct,
		usbdev->bus->dirname,usbdev->filename);

	if(fx2dev.open(usbdev)) return(0);

    fprintf(stderr,"Putting 8051 into reset.\n");
    fx2dev.FX2Reset(/*running=*/0);

    fprintf(stderr,"Programming 8051 using \"%s\".\n",file);
    if(fx2dev.ProgramIHexFile(file)) {
        printf("Programming 8051 failed, file name: %s\n",file);
        return(0);
    };

    fprintf(stderr,"Putting 8051 out of reset.\n");
    fx2dev.FX2Reset(/*running=*/1);

	if(!fx2dev.IsOpen())
	{  fprintf(stderr,"minRead: Not connected!\n");  return(0);  }

	int interface=0, alt_interface=1;    // = 1 for bulk read
	if(usb_claim_interface(fx2dev.usbhdl,interface)<0) {
        fprintf(stderr,"Failed to claim interface %d: %s\n",
		interface,usb_strerror());  return(0);  }

    if(usb_set_altinterface(fx2dev.usbhdl,alt_interface)<0)
    {
        fprintf(stderr,"Failed to set altinterface %d: %s\n",
            alt_interface,usb_strerror());
        return(0);
    }
    return(1);
}
/////////////////////////   End FX2 Init   //////////////////////////////////////
