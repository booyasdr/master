/*
 * convert_string/convert.c -- FX2 USB data converter (filter) example. 
 * 
 * Copyright (c) 2006--2008 by Wolfgang Wieser ] wwieser (a) gmx <*> de [ 
 * 
 * This file may be distributed and/or modified under the terms of the 
 * GNU General Public License version 2 as published by the Free Software 
 * Foundation. (See COPYING.GPL for details.)
 * 
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 * 
 */

#define ALLOCATE_EXTERN
//#include <fx2regs.h>
#include "c:\gnuradio\fx2\include\fx2regs.h"
#include <stdio.h>
// Read TRM p.15-115 for an explanation on this. 
// A single nop is sufficient for default setup but like that we're on 
// the safe side. 
#define	NOP		__asm nop __endasm
#define	SYNCDELAY	NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP
xdata unsigned char *dat = (xdata unsigned char) 0xE000;

static void Initialize(void)
{
	int n;
	CPUCS=0x10;   // 48 MHz, CLKOUT output disabled. 
	
// original convert IFCONFIG
//	IFCONFIG=0xc3;  // Internal IFCLK, 48MHz; A,B as normal ports. 
//	SYNCDELAY;
	
/* WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW	
IFCONFIG: Default: 1000 0000

bit7: 1 = internal clocking of IFCLK; 0 = external
bit6: 0 = 30MHz; 1 = 48MHz
bit5: 1 = enable output to IFCLK
bit4: 1 = invert IFCLK
bit3: 0 = sync mode; 1 = async mode
bit1,0: 11 = Slave FIFO; 00 = ports; 01 = reserved; 10 = GPIF 

Example: 0x43 for externally clocked and sync FIFO mode
WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW	
*/

// new IFCONFIG
	IFCONFIG=0x43;  // External IFCLK, 48MHz; slave FIFO. 
	SYNCDELAY;
// new IFCONFIG
	IFCONFIG=0xC0;  // External IFCLK, 48MHz; slave FIFO. 
	SYNCDELAY;
/* AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ
FIFOPINPOLAR, Slave FIFO Interface Pins Polarity E609
b7 b6 b5 b4 b3 b2 b1 b0
0 0 PKTEND SLOE SLRD SLWR EF FF

Bit 5 PKTEND FIFO Packet End Polarity
This bit selects the polarity of the PKTEND FIFO input pin. 0 selects the polarity shown in the
data sheet (active low). 1 selects active high.
Bit 4 SLOE FIFO Output Enable Polarity
This bit selects the polarity of the SLOE FIFO input pin. 0 selects the polarity shown in the
data sheet (active low). 1 selects active high.
Bit 3 SLRD FIFO Read Polarity
This bit selects the polarity of the SLRD FIFO input pin. 0 selects the polarity shown in the data
sheet (active low). 1 selects active high.
Bit 2 SLWR FIFO Write Polarity
This bit selects the polarity of the SLWR FIFO input pin. 0 selects the polarity shown in the
data sheet (active low). 1 selects active high.
Bit 1 EF Empty Flag Polarity
This bit selects the polarity of the SLWR FIFO output pin. 0 selects the polarity shown in the
data sheet (active low). 1 selects active high.
Bit 0 FF Full Flag Polarity
This bit selects the polarity of the SLWR FIFO output pin. 0 selects the polarity shown in the
data sheet (active low). 1 selects active high.
 AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ AJ
*/
	FIFOPINPOLAR=0x00;
	SYNCDELAY;

	FIFOPINPOLAR=0x0c;
	SYNCDELAY;


	REVCTL=0x03;  // See TRM...
	SYNCDELAY;
	
	EP6CFG=0xe2;  // 1110 0010 (bulk IN, 512 bytes, double-buffered)
	SYNCDELAY;
	
	EP2CFG=0xa2;  // 1010 0010 (bulk OUT, 512 bytes, double-buffered)
	SYNCDELAY;
	
	FIFORESET = 0x80;  SYNCDELAY;  // NAK all requests from host. 
	FIFORESET = 0x82;  SYNCDELAY;  // Reset individual EP (2,4,6,8)
	FIFORESET = 0x84;  SYNCDELAY;
	FIFORESET = 0x86;  SYNCDELAY;
	FIFORESET = 0x88;  SYNCDELAY;
	FIFORESET = 0x00;  SYNCDELAY;  // Resume normal operation. 
	
	EP2FIFOCFG = 0x00;  // Make sure AUTOOUT=0. 
	SYNCDELAY;
//	EP2FIFOCFG = 0x10;  // AUTOOUT=1. 
//	SYNCDELAY;
	
	// Be sure to clear the 2 buffers (double-buffered) (required!). 
	OUTPKTEND = 0x82;  SYNCDELAY;
	OUTPKTEND = 0x82;  SYNCDELAY;
	
		
	// PORTACFG: FLAGD SLCS(*) 0 0 0 0 INT1 INT0
	PORTACFG = 0x00;
	SYNCDELAY; // maybe not needed

	// disable all ports
	OEA = 0x00;
	OEB = 0x00;
	OEC = 0x00;
	OED = 0x00;
	
	OED = 0x0F;

	for(n = 0; n < 100;n++) dat[n] = 0;
	
}

// This will read the EP2 data and put it into EP6 for transmission. 
static void ProcessSendData(void)
{
	xdata const unsigned char *src=EP2FIFOBUF;
	xdata unsigned char *dest=EP6FIFOBUF;
	unsigned int len = (((int)EP2BCH)<<8 | EP2BCL);
	unsigned int i;
	for(i=0; i<len; i++,src++,dest++)
	{
//		*dest=*src;
		dat[i]=*src;
		*dest = dat[i];
	}
	
	// "Skip" the received OUT packet to "forget" it (see TRM p. 9-26): 
	SYNCDELAY;  OUTPKTEND=0x82;
	// Note: Setting EP2BCL would source a packet into the GPIF side. 
//	SYNCDELAY;  EP2BCL=0x01;
	
	// Arm the endpoint. Be sure to set BCH before BCL because BCL access 
	// actually arms the endpoint. 
	SYNCDELAY;  EP6BCH=len>>8;
	SYNCDELAY;  EP6BCL=len&0xff;
}

void main(void)
{
	signed int n;
	unsigned char fu_udH = 2, fu_udHC = 3, fu_udL = 0;
	unsigned char dataH = 4, dataL = 0, resetH = 8, resetL = 0, triggerH = 0x10, triggerL = 0;
	
	Initialize();
	
	// pulse the reset
	IOD = resetL;
		for(n = 0; n < 0xFFF; n ++ ) {
			IOD = resetH; }
	IOD = resetL;
	
	for(;;)
	{
		// Wait for input on EP2 (EP2 non-empty). 
		if(!(EP2CS & (1<<2)))
		{
			// Wait for EP6 buffer to become non-full so that we don't 
			// overwrite content. 
			while(EP6CS & (1<<3));
			ProcessSendData();
		
 }

	for(n = 0; n < 80; n ++ ) {
		IOD = dat[n];
		IOD = dat[n];
				}

	// pulse the fu_ud
	IOD = fu_udL;
		for(n = 0; n < 0xF; n ++ ) {
			IOD = fu_udH; }
		for(n = 0; n < 0xF; n ++ ) {
			IOD = fu_udHC; }
	IOD = fu_udL;
	
	}
}
