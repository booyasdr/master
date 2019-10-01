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

static uint8 hostreadmarkep1init(void);
static uint8 hostreadmarkep1poll(void);
static uint8 readmarkeeprom(void);

void main(void)
{
	int n;
	const uint16 eeprom_mark_adr = 0x400;
	uint16 adr = eeprom_mark_adr;

	err = (xdata unsigned char *) 0x1200;	

	for(n = 0;n < 200;n++);
	readmarkeeprom();
	for(n=0;n<32;n++) dat[n] = (xdata char)HWmark[n];
	
	hostreadmarkep1init();
	for(;;) hostreadmarkep1poll();	
}

