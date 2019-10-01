/*
 * bench_in/bench_in.c -- FX2 USB bulk USB input firmware for host
 *                        controller benchmarking.
 *
 * Copyright (c) 2006--2008 by Wolfgang Wieser ] wwieser (a) gmx <*> de [
 */
//------------------------------------------------------------------------------
// NOTE: In order for this test to work, the following manual wire connections
//       have to be done on the USB-FX2 board:
//   PA2/SLOE      <--> +3V3
//   PA4/FIFOADR0  <-->  GND
//   PA5/FIFOADR1  <--> +3V3
//   RDY0/SLRD     <--> +3V3
//   RDY1/SLWR     <-->  GND
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// NOTE: In order for this test to work, the following manual wire connections
//       have to be done on the USB-FX2 board:
//   PA2/SLOE      <--> +3V3  invert with FIFOPINPOLAR=0x1c to enable;
//   PA4/FIFOADR0  <-->  GND ep2
//   PA5/FIFOADR1  <-->  GND ep2
//   RDY0/SLRD     <--> +3V3 invert with FIFOPINPOLAR=0x0c;
//   RDY1/SLWR     <-->  GND invert with FIFOPINPOLAR=0x0c;
//------------------------------------------------------------------------------

#define ALLOCATE_EXTERN
//#include <fx2regs.h>
#include "c:\gnuradio\fx2\include\fx2regs.h"

// Read TRM p.15-115 for an explanation on this.
// A single nop is sufficient for default setup but like that we're on
// the safe side.
#define	NOP		__asm nop __endasm
//#define	SYNCDELAY	NOP; NOP; NOP; NOP
#define	SYNCDELAY	NOP; NOP; NOP; NOP

// Initialize the FX2 in 16bit sync fifo mode.
static void Initialize(void)
{
//	CPUCS = 0x0a;  // 24MHz, output to CLKOUT signal enabled.
	CPUCS = 0x12;  // 48MHz, output to CLKOUT signal enabled.
	SYNCDELAY;
	
/* WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW	
IFCONFIG: Default: 1000 0000

bit7: 1 = internal clocking of IFCLK; 0 = external
bit6: 0 = 30MHz; 1 = 48MHz
bit5: 1 = enable output to IFCLK
bit4: 1 = invert IFCLK
bit3: 0 = sync mode; 1 = async mode, slave clock synchronous mode
bit1,0: 11 = Slave FIFO; 00 = ports; 01 = reserved; 10 = GPIF 

Example: 0x43 for externally clocked and sync FIFO mode
WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW	
*/

// Internally clocked (48MHz) sync slave fifo mode.
// Output to IFCLK not enabled (set bit5 to enable).
	IFCONFIG = 0x00;
	SYNCDELAY;

	REVCTL = 0x03;   // See TRM...
	SYNCDELAY;
	
	FIFOPINPOLAR=0x00;
	SYNCDELAY;

	/* WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW	
	
	 EPxCFG: Default: 1110 0010

    bit7: VALID: 1=enable
    bit6: DIR: 1=in (USB-FX2 to host); 0=out (host to USB-FX2)
    bit5,4: TYPE1,0: 00=ivalid; 01=isochronous; 10=bulk; 11=interrupt
    bit3: SIZE: 0=512 bytes; 1=1024 bytes
    bit2: always 0
    bit1,0: BUF1,0: 00=quad; 01=invalid; 10=double; 11=triple 

Note that not all buffering schemes, types and directions are available for all endpoints. EP2 and EP6 have the most features as OUT and IN endpoints, respectively.

Example: 0xe0 Quad-buffered (4*512 bytes) bulk input.

WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW WW	
*/

	
	// PORTACFG: FLAGD SLCS(*) 0 0 0 0 INT1 INT0
	PORTACFG = 0x00;
	SYNCDELAY; // maybe not needed

	// disable all ports
	OEA = 0x00;
	OEB = 0x00;
	OEC = 0x00;
	OED = 0x00;
	
	OEB = 0xFF;
	OED = 0xFF;
	
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
}

void main()
{
	unsigned int n, m;
	Initialize();
	for(;;)
	{
		for(n = 0; n < 0x0003; n ++ )
			for(m = 0; m < 0xFFFF; m ++ ) {
				IOB = 0xFF;
				IOD = 0xFF; }
		for(n = 0; n < 0x0003; n ++ )
			for(m = 0; m < 0xFFFF; m ++ ) {
				IOB = 0x00;
				IOD = 0x00; }
	}
}
