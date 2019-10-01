/*
 * bench_in/bench_in.c -- FX2 USB bulk USB input firmware for host
 *                        controller benchmarking.
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

//------------------------------------------------------------------------------
// NOTE: In order for this test to work, the following manual wire connections
//       have to be done on the USB-FX2 board:
//   PA2/SLOE      <--> +3V3
//   PA4/FIFOADR0  <-->  GND
//   PA5/FIFOADR1  <--> +3V3
//   RDY0/SLRD     <--> +3V3
//   RDY1/SLWR     <-->  GND
//------------------------------------------------------------------------------

#define ALLOCATE_EXTERN
//#include <fx2regs.h>
#include "c:\gnuradio\cycfx2prog\include\fx2regs.h"

// Read TRM p.15-115 for an explanation on this.
// A single nop is sufficient for default setup but like that we're on
// the safe side.
#define	NOP		_asm nop _endasm
#define	SYNCDELAY	NOP; NOP; NOP; NOP


// Initialize the FX2 in 16bit sync fifo mode.
static void Initialize(void)
{
	CPUCS = 0x12;  // 48MHz, output to CLKOUT signal enabled.

	// Internally clocked (48MHz) sync slave fifo mode.
	// Output to IFCLK not enabled (set bit5 to enable).
	IFCONFIG = 0xc3;
	SYNCDELAY;
// external clock, invert clock
	IFCONFIG = 0x53;
	SYNCDELAY;
// external clock
	IFCONFIG = 0x43;
	SYNCDELAY;

	REVCTL = 0x03;   // See TRM...
	SYNCDELAY;

	// Configure EP6 (IN) for bulk input, quad-buffered (4*512 bytes).
	EP6CFG = 0xe0;
	SYNCDELAY;

	FIFORESET = 0x80;  SYNCDELAY;  // NAK all requests from host.
	FIFORESET = 0x82;  SYNCDELAY;  // Reset individual EP (2,4,6,8)
	FIFORESET = 0x84;  SYNCDELAY;
	FIFORESET = 0x86;  SYNCDELAY;
	FIFORESET = 0x88;  SYNCDELAY;
	FIFORESET = 0x00;  SYNCDELAY;  // Resume normal operation.

	// Configure EP6 for AUTOIN, 16bit wide bus.
	EP6FIFOCFG = 0x0d;
	SYNCDELAY;

	// PORTACFG: FLAGD SLCS(*) 0 0 0 0 INT1 INT0
	PORTACFG = 0x00;
	SYNCDELAY; // maybe not needed

	// All default polarities: SLWR active low,...
	FIFOPINPOLAR=0x00;
	SYNCDELAY;

	// This determines how much data is accumulated in the FIFOs before a
	// USB packet is committed. Use 512 bytes to be sure.
	EP6AUTOINLENH = 0x02; // MSB
	SYNCDELAY;
	EP6AUTOINLENL = 0x00; // LSB
	SYNCDELAY;
}


void main()
{
	Initialize();

	for(;;)
	{
		// Actually, there's nothing to do for the '8051 CPU while all
		// the data is flowing inwards.
	}
}
