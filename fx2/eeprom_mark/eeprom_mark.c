/*
 * eeprom_read.c -- FX2: erase connected EEPROM.
 *
 * Copyright (c) 2009 by Wolfgang Wieser ] wwieser (a) gmx <*> de [
 *
 * This file may be distributed and/or modified under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation. (See COPYING.GPL for details.)
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */
#include <stdio.h>
#include <string.h>
#include <fx2regs.h>
#include "eeprom_read.h"

char *FWmark = "FWEEPRv000.001";

// declared in eeprom_read.h

// xdata unsigned char *err =(xdata char*)0x1200;
// xdata unsigned char *dat =(xdata char*)0x1000;

// #define SYNCDELAY       __asm  nop; __endasm

// #define I2CREAD     0x01    /* 00000001 */
// #define I2CWRITE    0x00    /* 00000000 */
// #define EEPROM_ADR  0xa2    /* 1010 A2 A1 A0 RW -> 1010 0010 */

// typedef unsigned char uint8;
// typedef unsigned short uint16;

// #define I2CS_START   0x80
// #define I2CS_STOP    0x40
// #define I2CS_LASTRD  0x20
// #define I2CS_ACK     0x02
// #define I2CS_DONE    0x01


// ERASE EEPROM
// Write one byte into EEPROM.
// This takes about 3msec for the Microchip 24LC64.
// Returns 0 on success and >0 on error.
// Will wait for write operation to complete (ACK polling).
static uint8 EEErase(uint16 ee_adr)
{
	I2CS = I2CS_START;
	I2DAT = EEPROM_ADR | I2CWRITE;
	while(!(I2CS & I2CS_DONE));

	// If ACK is set, the slave acknowledges (OK).
	if(!(I2CS & I2CS_ACK)) return(1);

	// Write high address.
	I2DAT = (ee_adr>>8);
	while(!(I2CS & I2CS_DONE));

	// If ACK is set, the slave acknowledges (OK).
	if(!(I2CS & I2CS_ACK)) return(2);

	// Write low addres.
	I2DAT = (ee_adr & 0xff);
	while(!(I2CS & I2CS_DONE));

	// If ACK is set, the slave acknowledges (OK).
	if(!(I2CS & I2CS_ACK)) return(3);

	// Write data.
	I2DAT = 0xff;
	while(!(I2CS & I2CS_DONE));

	I2CS = I2CS_STOP;
	// If ACK is set, the slave acknowledges (OK).
	if(!(I2CS & I2CS_ACK)) return(4);

	// Wait for WRITE to complete (ACK polling).
	for(;;)
	{
		I2CS = I2CS_START;
		I2DAT = EEPROM_ADR | I2CWRITE;
		while(!(I2CS & I2CS_DONE));

		if((I2CS & I2CS_ACK)) break;
	}

	return(64);
}

// WRITE EEPROM
// Write one byte into EEPROM.
// This takes about 3msec for the Microchip 24LC64.
// Returns 0 on success and >0 on error.
// Will wait for write operation to complete (ACK polling).
static uint8 EEWrite(uint16 ee_adr, unsigned char a)
{
	I2CS = I2CS_START;
	I2DAT = EEPROM_ADR | I2CWRITE;
	while(!(I2CS & I2CS_DONE));

	// If ACK is set, the slave acknowledges (OK).
	if(!(I2CS & I2CS_ACK)) return(1);

	// Write high address.
	I2DAT = (ee_adr>>8);
	while(!(I2CS & I2CS_DONE));

	// If ACK is set, the slave acknowledges (OK).
	if(!(I2CS & I2CS_ACK)) return(2);

	// Write low addres.
	I2DAT = (ee_adr & 0xff);
	while(!(I2CS & I2CS_DONE));

	// If ACK is set, the slave acknowledges (OK).
	if(!(I2CS & I2CS_ACK)) return(3);

	// Write data.
	I2DAT = a;
	while(!(I2CS & I2CS_DONE));

	I2CS = I2CS_STOP;
	// If ACK is set, the slave acknowledges (OK).
	if(!(I2CS & I2CS_ACK)) return(4);

	// Wait for WRITE to complete (ACK polling).
	for(;;)
	{
		I2CS = I2CS_START;
		I2DAT = EEPROM_ADR | I2CWRITE;
		while(!(I2CS & I2CS_DONE));

		if((I2CS & I2CS_ACK)) break;
	}
	return(64);
}


struct mark {
	char type[8];
	uint16 major_version, minor_version;
	uint16 serial_no_high,serial_no_low;
};


static uint8 hostreadmarkep1init(void);
static uint8 hostreadmarkep1poll(void);
static uint8 readmarkeeprom(void);
static uint8 writemarkeeprom(struct mark *mark);


static uint8 writemarkeeprom(struct mark *mark) {

	int n;
	
	I2CTL = 0x01;	// Set 400kHz:
	SYNCDELAY;

	for(n=0;n<128;n++) HWmark[n] = 0x00;
	
	sprintf(HWmark,"HW%sv%03x.%03xs%04x.%04x",
		mark->type,mark->major_version, mark->minor_version,
			mark->serial_no_high,mark->serial_no_low);
	for(n=0;n<32;n++) err[n+2] = EEWrite(0x0400+n,0x00);
    for(n=0;n<32;n++) err[n+2] = EEWrite(0x0400+n,HWmark[n]);

	return(0);
}

void main(void)
{
	int n;
	const uint16 eeprom_mark_adr = 0x400;
	uint16 adr = eeprom_mark_adr;
	struct mark mark;

	err = (xdata unsigned char *) 0x1200;	

	// Erase 8192 bytes of EEPROM.
//	for(adr=0; adr<8192; adr++)
//	{
//		if(*err = EEErase(adr)) break;
//	}

// mark the type with 4 charcters
//	strcpy(mark.type,"DAC_");
//	strcpy(mark.type,"ADC_");
//	strcpy(mark.type,"NEW_");
	strcpy(mark.type,"DDS_");
// mark the firmware version with 2 hex digits pont 3 hex digits
	mark.major_version = 0x0;
	mark.minor_version = 0x1;
// serial number has 4 hex high digits point 4 hex low digits
	mark.serial_no_high = 0x0;
	mark.serial_no_low  = 0x1;

//	writemarkeeprom(&mark);

	for(n = 0;n < 200;n++);
	readmarkeeprom();
	for(n=0;n<32;n++) dat[n] = (xdata char)HWmark[n];
	
	hostreadmarkep1init();
	for(;;) hostreadmarkep1poll();	
}

