#ifndef _CYCFX2PROG_CYCFX2DEVICE_
#define _CYCFX2PROG_CYCFX2DEVICE_ 1

#include <stdio.h>

#define	PPX 8
#define	QueueSize 16

void USBDumpBusses(FILE *out);

struct usb_device *USBFindDevice(const char *bus,const char *dev);
struct usb_device *USBFindDevice(int vendor,int product,int nth=0);

class CypressFX2Device
{
	private:

		// Force a certail "alt" interface; -1 for none.
		int force_alt_interface;

		// Internally used: Program one line of an Intel HEX file.
		// The arguments path and line are just needed for error reporting.
		int _ProgramIHexLine(const char *buf,const char *path,int line);
	private:
		CypressFX2Device(const CypressFX2Device &);
		void operator=(const CypressFX2Device &);
	public:

		struct usb_device *usbdev;
		struct usb_dev_handle *usbhdl;

		CypressFX2Device()
			{  usbdev=NULL;  usbhdl=NULL;  force_alt_interface=-1;  }
		~CypressFX2Device()
			{  close();  }

		// Is opened?
		inline bool IsOpen() const
			{  return(usbhdl);  }

		// Open usb device; will close previous one.
		// Returns 0 on success; 1 on error. Errors written to stderr.
		int open(struct usb_device *_usbdev);

		// Close device. Returns 0 on success. Errors written to stderr.
		int close();

		// Read an intel hex file and download it.
		// Returns 0 on success; 1 on error. Errors written to stderr.
		int ProgramIHexFile(const char *path);
		// Read a flat binary file and download it.
		int WriteRAM(size_t addr,const unsigned char *data,size_t nbytes);
		// Read a portion of ram from the device.
		int ReadRAM(size_t addr,unsigned char *data,size_t nbytes);

		// Put the Cypress FX2 into reset or release reset.
		// running=1 -> running; running=0 -> reset.
		int FX2Reset(bool running);

//		int minRead(int endpoint,size_t nbytes,size_t chunk_size,
//			 char *buffer=0);
};

#endif  /* _CYCFX2PROG_CYCFX2DEVICE_ */
