/* firmware/fx2pipe.c
 * FX2 pipe IO firmware.
 *  2006--2009 by Wolfgang Wieser ] wwieser (a) gmx <*> de [
 * Modified afterwards
 */

// EP2 IN pin configuration, USE FOR D2A
//------------------------------------------------------------------------------
// NOTE: In order for this test to work, the following manual wire connections
//       have to be done on the USB-FX2 board:
//   PA2/SLOE      <-->  GND
//   PA4/FIFOADR0  <-->  GND
//   PA5/FIFOADR1  <-->  GND, address EP2
//   AJ, first try is to reverse the next two with  FIFOPOLARITY
//   RDY0/SLRD     <--> +3V3, RDY1 on the board
//   RDY1/SLWR     <-->  GND, RDY0 on the board
//   PA6           <--> +3V3, added by WW
//------------------------------------------------------------------------------
// Set z[the IO pins on port A:
// 7, PKTEND, FIFOADR1, FIFOADR0, 3, SLOE, 1, 0
// Z    1        0         0      Z   0    Z  Z
// USE with	FIFOPINPOLAR=0x00; // 0 0 0 0 0 0 0 0, for D2A
// EP2 IN pin configuration, USE FOR D2A

// EP6 OUT pin configuration, DO NOT USE FOR D2A
//------------------------------------------------------------------------------
// NOTE: In order for this test to work, the following manual wire connections
//       have to be done on the USB-FX2 board:
//   PA2/SLOE      <--> +3V3
//   PA4/FIFOADR0  <-->  GND
//   PA5/FIFOADR1  <--> +3V3
//   RDY0/SLRD     <--> +3V3, RDY1 on the board
//   RDY1/SLWR     <-->  GND, RDY0 on the board
//   PA6           <--> +3V3, added by WW
//------------------------------------------------------------------------------
// SPECIAL VOODOO: Set the IO pins on port A:
// 7, PKTEND, FIFOADR1, FIFOADR0, 3, SLOE, 1, 0
// Z    1        1         0      Z   1    Z  Z
// EP6 OUT pin configuration, DO NOT USE FOR D2A

#define ALLOCATE_EXTERN
//#include <fx2regs.h>
#include "c:\radio\fx2\include\fx2regs.h"

typedef unsigned char uint8;
typedef unsigned int uint16;  // int is 16 bit.

//  WW says we need 17 NOPs
#define	NOP		__asm nop __endasm
#define	SYNCDELAY	\
	NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; \
	NOP; NOP; NOP; NOP; NOP; NOP; NOP; NOP; \
	NOP


// Initialize the FX2 in 16bit sync fifo mode.
static void Initialize(void)
{
	// Config is put at address 0x3000 by fx2pipe program at firmware
	// download.
	// NOTE: This is for FX2LP; the FX2 has fewer SRAM and so we cannot use
	//       0x3000 but rather 0x1000 or so.
	//       Now we use 0x1000 to support both devices.
	xdata char *cfg_data=(xdata char*)0x1003;
    char cfg_data_ok;
	
	// //		if(cfg_data[0]==0x12U) /* INPUT: USB->HOST */ DO NOT USE FOR D2A
	// cfg_data[0] = 0x12U;

	// // CPUCS
	// cfg_data[4] = 0x12;  // 0x12

	// //IFCONFIG = 0xc3; // 1100 0011 = 0xc3   internally clocked sync mode (perf test)
	// cfg_data[1] = 0xc3;
	// //IFCONFIG = 0x43; // 0100 0011 = 0x43   externally clocked sync mode
	// cfg_data[1] = 0x43;
	// //IFCONFIG = 0x53; // 0101 0011 = 0x53   externally clocked sync mode, invert if clock
	// cfg_data[1] = 0x53;

	// // AUTOIN on EP6
	// // EP6CFG
	// cfg_data[2] = 0xe0;  // bulk: 0xe2 double-buffered; 0xe3 triple-; 0xe0 quad
	// // EP6FIFOCFG
	// cfg_data[3] = 0x0d; // AUTOIN
	// // end AUTOIN on EP6, DO NOT USE FOR D2A

	// AUTOOUT on EP2
	//	else if(cfg_data[0]==0x21U) /* OUTPUT: HOST->USB */
	cfg_data[0] = 0x21U;

	// EP2CFG
	cfg_data[2] = 0xa0;  // bulk: 0xa2 double-buffered; 0xa3 triple-; 0xa0 quad

	// EP2FIFOCFG
	cfg_data[3] = 0x11; // AUTOOUT, or Ox15
	cfg_data[3] = 0x10; // AUTOOUT, or Ox15 width narrow
	// end AUTOIN on EP2

	// First cfg_data must be 21 or 12 to be considered valid.
//	char cfg_data_ok = (cfg_data[0]==0x12U || cfg_data[0]==0x21U);
	cfg_data_ok = (cfg_data[0]==0x12U || cfg_data[0]==0x21U);

	SYNCDELAY;

	// CPUCS: 0 0 PORTCSTB CLKSPD1   CLKSPD0 CLKINV CLKOE 8051RES   00000010
	//   PORTCSTB=1: reads/writes to PORTC generate RD# and WR# strobes
	//   CLKSPD1,0 = 8051 clock speed: 00=12, 01=24, 10=48, 11=X
	//   CLKINV=1 to invert CLKOUT signal
	//   CLKOE=1 to drive CLKOUT pin
	//   8051RES=1 to reset 8051
	// Want: 0001 0010  <-- 48MHz, output enabled.
	//       0000 0010  <-- 12MHz, output enabled.
	CPUCS = cfg_data_ok ? cfg_data[4] : 0x12;  // 0x12
	SYNCDELAY;

	// a = 10; b = 11; c = 12; d = 13; e = 14; f = 15

	// Okay, the most important config register: (default: 10000000)
	//  bit7: 1 = internal clocking of IFCLK; 0 = external
	//  bit6: 0 = 30MHz; 1 = 48MHz
	//  bit5: 1 = enable output to IFCLK
	//  bit4: 1 = invert IFCLK
	//  bit3: 1 = async mode; 0 = sync
	//  bit2: 1 = drive GSTATE[0:2] on PORTE[0:2] (irrelevant for 56-pin package)
	//  bit1,0: 00: ports; 01: reserved; 10: GPIF; 11: Slave FIFO (ext master),
	//IFCONFIG = 0x43; // 0100 0011 = 0x43   externally clocked sync mode
	//IFCONFIG = 0xcb; // 1100 1011 = 0xcb   internally clocked async mode
	//IFCONFIG = 0xc3; // 1100 0011 = 0xc3   internally clocked sync mode (perf test)
	IFCONFIG = cfg_data_ok ? cfg_data[1] : 0xc3;
	SYNCDELAY;

	// Based on TRM and SSRP.
	REVCTL = 0x03;  // See TRM...
	SYNCDELAY;

	// PORTACFG: FLAGD SLCS(*) 0 0 0 0 INT1 INT0
	PORTACFG = 0x00;
	SYNCDELAY; // maybe not needed

	// All default polarities: SLWR active low,...
	FIFOPINPOLAR=0x00;
	SYNCDELAY;

	// Reset...
	EP6CFG=0x00U;  SYNCDELAY;
	EP2CFG=0x00U;  SYNCDELAY;
	EP6FIFOCFG=0x00U;  SYNCDELAY;
	EP2FIFOCFG=0x00U;  SYNCDELAY;
	OEA=0x00U;

//AUTOIN
	if(cfg_data[0]==0x12U) /* INPUT: USB->HOST */ // NOR FOR D2A
	{
		// Configure EP6 (IN):
		// EP6CFG:
		//  1 bit7: VALID: 1 = enable
		//  1 bit6: DIR:   1 = in; 0 = out
		// 10 bit5,4: TYPE1,0: 00 = ivalid; 01=isochronous; 10=bulk; 11=interrupt
		//  0 bit3: SIZE: 0 = 512 bytes; 1 = 1024 bytes
		//  0 bit2: 0
		// 10 bit1,0: BUF1,0: 00=quad; 01=<inval>; 10=double; 11=triple
		// Want: 1110 0010 (enabled, IN, BULK, double-buffered 512 bytes)
		EP6CFG = cfg_data[2];  // bulk: 0xe2 double-buffered; 0xe3 triple-; 0xe0 quad
		SYNCDELAY;

		// To be sure, clear and reset all FIFOs although
		// this is probably not strictly required.
		FIFORESET = 0x80;  SYNCDELAY;  // NAK all requests from host.
		FIFORESET = 0x82;  SYNCDELAY;  // Reset individual EP (2,4,6,8)
		FIFORESET = 0x84;  SYNCDELAY;
		FIFORESET = 0x86;  SYNCDELAY;
		FIFORESET = 0x88;  SYNCDELAY;
		FIFORESET = 0x00;  SYNCDELAY;  // Resume normal operation.

		// EP6FIFOCFG:
		//  bit7: 0
		//  bit6: INFM6  See TRM 15-29 (p.351): Signal line one clock earlier.
		//  bit5: OEP6
		//  bit4: AUTOOUT    1 = enable
		//  bit3: AUTOIN     1 = enable
		//  bit2: ZEROLENIN  1 = enable (?)
		//  bit1: 0
		//  bit0: WORDWIDE   1 = 16bit (default)
		// Want: 0000 1101 -> 0x0d
		EP6FIFOCFG = cfg_data[3]; /*0x0d //&0xfe*/;
		SYNCDELAY;

		// This determines how much data is accumulated in the FIFOs before a
		// USB packet is committed. Use 512 bytes.
		// Not sure if we need the sync delays (WW).
		EP6AUTOINLENH = 0x02; // MSB
		SYNCDELAY;
		EP6AUTOINLENL = 0x00; // LSB
		SYNCDELAY;
	}
//AUTOOUT
	else if(cfg_data[0]==0x21U) /* OUTPUT: HOST->USB */
	{
		// Configure EP2 (OUT):
		// EP2CFG:
		//  1 bit7: VALID: 1 = enable
		//  0 bit6: DIR:   1 = in; 0 = out
		// 10 bit5,4: TYPE1,0: 00 = ivalid; 01=isochronous; 10=bulk; 11=interrupt
		//  0 bit3: SIZE: 0 = 512 bytes; 1 = 1024 bytes
		//  0 bit2: 0
		// 10 bit1,0: BUF1,0: 00=quad; 01=<inval>; 10=double; 11=triple
		// Want: 1010 0010 (enabled, OUT, BULK, double-buffered 512 bytes)
		EP2CFG = cfg_data[2];  // bulk: 0xa2 double-buffered; 0xa3 triple-; 0xa0 quad
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
	FIFOPINPOLAR=0x00; // 0 0 0 0 0 0 0 0
	SYNCDELAY;

		// To be sure, clear and reset all FIFOs although
		// this is probably not strictly required.
		FIFORESET = 0x80;  SYNCDELAY;  // NAK all requests from host.
		FIFORESET = 0x82;  SYNCDELAY;  // Reset individual EP (2,4,6,8)
		FIFORESET = 0x84;  SYNCDELAY;
		FIFORESET = 0x86;  SYNCDELAY;
		FIFORESET = 0x88;  SYNCDELAY;
		FIFORESET = 0x00;  SYNCDELAY;  // Resume normal operation.

		// Arm ouput endpoint TRM p.348 ("prime the pump"):
		OUTPKTEND = 0x82;  SYNCDELAY;
		OUTPKTEND = 0x82;  SYNCDELAY;
		switch(cfg_data[2]&0x03U)
		{  // Fall-through switch!
			case 0x00U:  OUTPKTEND = 0x82;  SYNCDELAY;  // Quad-buffered.
			case 0x03U:  OUTPKTEND = 0x82;  SYNCDELAY;  // Triple-buffered.
		}

		// EP2FIFOCFG:
		//  bit7: 0
		//  bit6: INFM2  See TRM 15-29 (p.351): Signal line one clock earlier.
		//  bit5: OEP2
		//  bit4: AUTOOUT    1 = enable
		//  bit3: AUTOIN     1 = enable
		//  bit2: ZEROLENIN  1 = enable (?)
		//  bit1: 0
		//  bit0: WORDWIDE   1 = 16bit (default)
		// Want: 0001 0001 -> 0x15
		EP2FIFOCFG = cfg_data[3]; /*0x11;*/
		SYNCDELAY;

// SPECIAL VOODOO: Set the IO pins on port A:
// 7, PKTEND, FIFOADR1, FIFOADR0, 3, SLOE, 1, 0
// Z    1        0         0      Z   0    Z  Z
//OEA=0x74U;  // 0111 0100
//IOA=0x50U;  // 0100 0000
	}
}


void main()
{
	Initialize();

	for(;;)
	{
		// Do nothing.
	}
}
