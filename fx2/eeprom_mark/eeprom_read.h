/*
 * eeprom_read.h
 * to be put included in other fw to allow host to read HWmark
 * and FWmark over ep1
 *
 */
#include <stdio.h>
#include <string.h>
#include <fx2regs.h>
#define SYNCDELAY       __asm  nop; __endasm

extern char *FWmark;

xdata unsigned char *err =(xdata char*)0x1200;
xdata unsigned char *dat =(xdata char*)0x1000;

#define I2CREAD     0x01    /* 00000001 */
#define I2CWRITE    0x00    /* 00000000 */
#define EEPROM_ADR  0xa2    /* 1010 A2 A1 A0 RW -> 1010 0010 */

typedef unsigned char uint8;
typedef unsigned short uint16;

#define I2CS_START   0x80
#define I2CS_STOP    0x40
#define I2CS_LASTRD  0x20
#define I2CS_ACK     0x02
#define I2CS_DONE    0x01

// Read 32 bytes from EEPROM.
// This takes about 3msec for the Microchip 24LC64.
// Returns 0 on success and >0 on error.
// Will wait for write operation to complete (ACK polling).
static uint8 EERead(uint16 ee_adr, 	unsigned char HWmark[32])
{
	int n;
	
	//WRITE ADDRESS
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

	//READ DATA
	I2CS = I2CS_START;
	I2DAT = EEPROM_ADR | I2CREAD;
	while(!(I2CS & I2CS_DONE));

	// If ACK is set, the slave acknowledges (OK).
	if(!(I2CS & I2CS_ACK)) return(5);
	
	// Read data.
	HWmark[0] = I2DAT;
	while(!(I2CS & I2CS_DONE));
	if(!(I2CS & I2CS_ACK)) return(6);
	// Read data.
	//I2CS = I2CS_LASTRD;
	while(!(I2CS & I2CS_DONE));
	if(!(I2CS & I2CS_ACK)) return(7);
	
	HWmark[0] = I2DAT;
	while(!(I2CS & I2CS_DONE));
	if(!(I2CS & I2CS_ACK)) return(8);
	
	HWmark[1] = I2DAT;
	while(!(I2CS & I2CS_DONE));
	if(!(I2CS & I2CS_ACK)) return(8);
	
	for(n = 2;n<31;n++) {
		HWmark[n] = I2DAT;
		while(!(I2CS & I2CS_DONE));
		if(!(I2CS & I2CS_ACK)) return(9);
	}
	
	I2CS = I2CS_LASTRD;
	HWmark[31] = I2DAT;
	while(!(I2CS & I2CS_DONE));
	HWmark[31] = I2DAT;
	while(!(I2CS & I2CS_DONE));
	if(!(I2CS & I2CS_ACK)) return(10);
	// Wait for WRITE to complete (ACK polling).
//	for(;;)
//	{
//		I2CS = I2CS_START;
//		I2DAT = EEPROM_ADR | I2CREAD;
//		while(!(I2CS & I2CS_DONE));

//		if((I2CS & I2CS_ACK)) break;
//	}

	I2CS = I2CS_STOP;
	while(!(I2CS & I2CS_DONE));
	// If ACK is set, the slave acknowledges (OK).
	if(!(I2CS & I2CS_ACK)) return(11);

	return(64);
}


static uint8 hostreadmarkep1init(void);
static uint8 hostreadmarkep1poll(void);
static uint8 readmarkeeprom(void);
xdata unsigned char *command = (xdata unsigned char *)0x1100;
xdata unsigned char *HWmark = (xdata unsigned char *)0x1140;


static uint8 readmarkeeprom(void) {

	int n;
	
	I2CTL = 0x01;	// Set 400kHz:
	SYNCDELAY;

	for(n=0;n<128;n++) HWmark[n] = 0x00;
	err[32+3] = EERead( 0x0400,HWmark);
	return(0);
}


static uint8 hostreadmarkep1init(void) {

	EP1OUTCFG=0xa0;
	EP1INCFG=0xa0;

	SYNCDELAY;
	EP1OUTBC=0xff; // Arm endpoint 1 for OUT (host->device) transfers
	// end do in ep1init
	return(0);
}	

static uint8 hostreadmarkep1poll(void) {

	xdata unsigned char *src;
	xdata unsigned char *dest;
	uint8 ep1outbc;
	int n;
		if(!(EP1OUTCS & bmEPBUSY)) {
			ep1outbc = EP1OUTBC;
			if(ep1outbc != 0xff ) {
				src = EP1OUTBUF;
				dest = EP1INBUF;
				while (EP1INCS & 0x02);
				for(n=0; n<32; n++) command[n] = src[n];
				for( n=0; n < ep1outbc ; n++ ) { 
					*dest++ = command[n];
				}
				*err++ = 0x5a;
				EP1INBC = ep1outbc;
			   while (EP1INCS & 0x02);
				dest = EP1INBUF;
				if(!strncmp(command,"getHW",5)) {
					for( n=0; HWmark[n] != '\0' ; n++ )  
						*dest++ = (xdata unsigned char) HWmark[n];					
					*dest++ = '\0';
					n++;
					EP1INBC = n;
					SYNCDELAY;
				}
				if(!strncmp(command,"getFW",5)) {
					for( n=0; FWmark[n] != '\0' ; n++ )  
						*dest++ = (xdata unsigned char) FWmark[n];					
					*dest++ = '\0';
					n++;
					EP1INBC = n;
					SYNCDELAY;
				}
				EP1OUTBC = 0xff;
			}
		}
	return(0);
}
