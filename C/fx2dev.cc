#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
#include <ctype.h>


#include "fx2dev.h"
#include <lusb0_usb.h>

struct usb_device *USBFindDevice(const char *bus,const char *dev)
{
	for(usb_bus *b=usb_busses; b; b=b->next)
	{
		if(strcmp(b->dirname,bus))  continue;
		for(struct usb_device *d=b->devices; d; d=d->next)
		{
			if(strcmp(d->filename,dev))  continue;
			return(d);
		}
	}
	return(NULL);
}

struct usb_device *USBFindDevice(int vendor,int product,int nth)
{
	for(usb_bus *b=usb_busses; b; b=b->next)
	{
		for(struct usb_device *d=b->devices; d; d=d->next)
		{
			if(d->descriptor.idVendor==vendor &&
				d->descriptor.idProduct==product)
			{
				if(!nth--)
				{  return(d);  }
			}
		}
	}
	return(NULL);
}

// HMMM.... There is usb_device::num_children and **usb_device::children.

void USBDump(FILE *out)
{
	for(usb_bus *b=usb_busses; b; b=b->next)
	{
		for(struct usb_device *d=b->devices; d; d=d->next)
		{
			bool is_fx2_dev = (d->descriptor.idVendor==0x4b4 &&
				d->descriptor.idProduct==0x8613);
			fprintf(out,"Bus %s Device %s: ID %04x:%04x%s\n",
				b->dirname,d->filename,
				d->descriptor.idVendor,d->descriptor.idProduct,
				is_fx2_dev ? " (unconfigured FX2)" : "");
		}
	}
}

// HMMM.... There is usb_device::num_children and **usb_device::children.

void USBDumpBusses(FILE *out)
{
	for(usb_bus *b=usb_busses; b; b=b->next)
	{
		for(struct usb_device *d=b->devices; d; d=d->next)
		{
			bool is_fx2_dev = (d->descriptor.idVendor==0x4b4 &&
				d->descriptor.idProduct==0x8613);
			fprintf(out,"Bus %s Device %s: ID %04x:%04x%s\n",
				b->dirname,d->filename,
				d->descriptor.idVendor,d->descriptor.idProduct,
				is_fx2_dev ? " (unconfigured FX2)" : "");
		}
	}
}


//------------------------------------------------------------------------------

int CypressFX2Device::FX2Reset(bool running)
{
	// Reset is accomplished by writing a 1 to address 0xE600.
	// Start running by writing a 0 to that address.
	const size_t reset_addr=0xe600;
	unsigned char val = running ? 0 : 1;

	return(WriteRAM(reset_addr,&val,1));
}

int CypressFX2Device::WriteRAM(size_t addr,const unsigned char *data,
	size_t nbytes)
{
	if(!IsOpen())
	{  fprintf(stderr,"WriteRAM: Not connected!\n");  return(1);  }

	int n_errors=0;

	const size_t chunk_size=16;
	const unsigned char *d=data;
	const unsigned char *dend=data+nbytes;
	while(d<dend)
	{
		size_t bs=dend-d;
		if(bs>chunk_size)  bs=chunk_size;
		size_t dl_addr=addr+(d-data);
		int rv=usb_control_msg(usbhdl,0x40,0xa0,
			/*addr=*/dl_addr,0,
			/*buf=*/(char*)d,/*size=*/bs,
			/*timeout=*/1000/*msec*/);
		if(rv<0)
		{  fprintf(stderr,"Writing %u bytes at 0x%x: %s\n",
			bs,dl_addr,usb_strerror());  ++n_errors;  }
		d+=bs;
	}

	return(n_errors);
}

int CypressFX2Device::ReadRAM(size_t addr,unsigned char *data,size_t nbytes)
{
	if(!IsOpen())
	{  fprintf(stderr,"ReadRAM: Not connected!\n");  return(1);  }

	int n_errors=0;

	const size_t chunk_size=16;

	unsigned char *d=data;
	unsigned char *dend=data+nbytes;
	while(d<dend)
	{
		size_t bs=dend-d;
		if(bs>chunk_size)  bs=chunk_size;
		size_t rd_addr=addr+(d-data);
		int rv=usb_control_msg(usbhdl,0xc0,0xa0,
			/*addr=*/rd_addr,0,
			/*buf=*/(char*)d,/*size=*/bs,
			/*timeout=*/1000/*msec*/);
		if(rv<0)
		{  fprintf(stderr,"Reading %u bytes at 0x%x: %s\n",
			bs,rd_addr,usb_strerror());  ++n_errors;  }
		d+=bs;
	}

	return(n_errors);
}

int CypressFX2Device::_ProgramIHexLine(const char *buf,
	const char *path,int line)
{
	const char *s=buf;
	if(*s!=':')
	{  fprintf(stderr,"%s:%d: format violation (1)\n",path,line);
		return(1);  }
	++s;

	unsigned int nbytes=0,addr=0,type=0;
	if(sscanf(s,"%02x%04x%02x",&nbytes,&addr,&type)!=3)
	{  fprintf(stderr,"%s:%d: format violation (2)\n",path,line);
		return(1);  }
	s+=8;

	if(type==0)
	{
		//printf("  Writing nbytes=%d at addr=0x%04x\n",nbytes,addr);
		assert(nbytes>=0 && nbytes<256);
		unsigned char data[nbytes];
		unsigned char cksum=nbytes+addr+(addr>>8)+type;
		for(unsigned int i=0; i<nbytes; i++)
		{
			unsigned int d=0;
			if(sscanf(s,"%02x",&d)!=1)
			{  fprintf(stderr,"%s:%d: format violation (3)\n",path,line);
				return(1);  }
			s+=2;
			data[i]=d;
			cksum+=d;
		}
		unsigned int file_cksum=0;
		if(sscanf(s,"%02x",&file_cksum)!=1)
		{  fprintf(stderr,"%s:%d: format violation (4)\n",path,line);
			return(1);  }
		if((cksum+file_cksum)&0xff)
		{  fprintf(stderr,"%s:%d: checksum mismatch (%u/%u)\n",
			path,line,cksum,file_cksum);  return(1);  }
		if(WriteRAM(addr,data,nbytes))
		{  return(1);  }
	}
	else if(type==1)
	{
		// EOF marker. Oh well, trust it.
		return(-1);
	}
	else
	{
		fprintf(stderr,"%s:%d: Unknown entry type %d\n",path,line,type);
		return(1);
	}

	return(0);
}

int CypressFX2Device::ProgramIHexFile(const char *path)
{
	if(!IsOpen())
	{  fprintf(stderr,"ProgramIHexFile: Not connected!\n");  return(1);  }

	FILE *fp=fopen(path,"r");
	if(!fp)
	{  fprintf(stderr,"Failed to open %s: %s\n",path,strerror(errno));
		return(0);  }

	int n_errors=0;

	const size_t buflen=1024;  // Hopefully much too long for real life...
	char buf[buflen];
	int line=1;
	for(;;++line)
	{
		*buf='\0';
		if(!fgets(buf,buflen,fp))
		{
			if(feof(fp))
			{  break;  }
			fprintf(stderr,"Reading %s (line %d): %s\n",path,line,
				strerror(ferror(fp)));
			fclose(fp);  fp=NULL;
			return(3);
		}

		int rv=_ProgramIHexLine(buf,path,line);
		if(rv<0)  break;
		if(rv)
		{  ++n_errors;  }
	}

	if(fp)
	{  fclose(fp);  }

	return(n_errors ? -1 : 0);
}

int CypressFX2Device::open(struct usb_device *_usbdev)
{
	close();
	usbdev=_usbdev;
	usbhdl=usb_open(usbdev);
	if(!usbhdl)
	{  fprintf(stderr,"Failed to open device: %s\n",usb_strerror());
		return(1);  }
	return(0);
}

int CypressFX2Device::close()
{
	int rv=0;
	if(usbhdl)
	{
		rv=usb_close(usbhdl);  usbhdl=NULL;
		if(rv)
		{  fprintf(stderr,"closing USB device: %s\n",usb_strerror());  }
	}
	usbdev=NULL;
	return(rv);
}

