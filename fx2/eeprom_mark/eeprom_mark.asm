;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.2.0 #8008 (Jul  6 2012) (MINGW32)
; This file was generated Wed Apr 29 06:16:33 2015
;--------------------------------------------------------
	.module eeprom_mark
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _strncmp
	.globl _strcpy
	.globl _sprintf
	.globl _EIP
	.globl _B
	.globl _EIE
	.globl _ACC
	.globl _EICON
	.globl _PSW
	.globl _TH2
	.globl _TL2
	.globl _RCAP2H
	.globl _RCAP2L
	.globl _T2CON
	.globl _SBUF1
	.globl _SCON1
	.globl _GPIFSGLDATLNOX
	.globl _GPIFSGLDATLX
	.globl _GPIFSGLDATH
	.globl _GPIFTRIG
	.globl _EP01STAT
	.globl _IP
	.globl _OEE
	.globl _OED
	.globl _OEC
	.globl _OEB
	.globl _OEA
	.globl _IOE
	.globl _IOD
	.globl _AUTOPTRSETUP
	.globl _EP68FIFOFLGS
	.globl _EP24FIFOFLGS
	.globl _EP2468STAT
	.globl _IE
	.globl _INT4CLR
	.globl _INT2CLR
	.globl _IOC
	.globl _AUTODAT2
	.globl _AUTOPTRL2
	.globl _AUTOPTRH2
	.globl _AUTODAT1
	.globl _APTR1L
	.globl _APTR1H
	.globl _SBU
	.globl _SCO
	.globl _MPA
	.globl _EXIF
	.globl _IOB
	.globl _SPC_
	.globl _CKCO
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPS
	.globl _DPH1
	.globl _DPL1
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _IOA
	.globl _EP8FIFOBUF
	.globl _EP6FIFOBUF
	.globl _EP4FIFOBUF
	.globl _EP2FIFOBUF
	.globl _EP1INBUF
	.globl _EP1OUTBUF
	.globl _EP0BUF
	.globl _CT4
	.globl _CT3
	.globl _CT2
	.globl _CT1
	.globl _USBTEST
	.globl _TESTCFG
	.globl _DBUG
	.globl _UDMACRCQUAL
	.globl _UDMACRCL
	.globl _UDMACRCH
	.globl _GPIFHOLDAMOUNT
	.globl _FLOWSTBHPERIOD
	.globl _FLOWSTBEDGE
	.globl _FLOWSTB
	.globl _FLOWHOLDOFF
	.globl _FLOWEQ1CTL
	.globl _FLOWEQ0CTL
	.globl _FLOWLOGIC
	.globl _FLOWSTATE
	.globl _GPIFABORT
	.globl _GPIFREADYSTAT
	.globl _GPIFREADYCFG
	.globl _XGPIFSGLDATLNOX
	.globl _XGPIFSGLDATLX
	.globl _XGPIFSGLDATH
	.globl _EP8GPIFTRIG
	.globl _EP8GPIFPFSTOP
	.globl _EP8GPIFFLGSEL
	.globl _EP6GPIFTRIG
	.globl _EP6GPIFPFSTOP
	.globl _EP6GPIFFLGSEL
	.globl _EP4GPIFTRIG
	.globl _EP4GPIFPFSTOP
	.globl _EP4GPIFFLGSEL
	.globl _EP2GPIFTRIG
	.globl _EP2GPIFPFSTOP
	.globl _EP2GPIFFLGSEL
	.globl _GPIFTCB0
	.globl _GPIFTCB1
	.globl _GPIFTCB2
	.globl _GPIFTCB3
	.globl _GPIFADRL
	.globl _GPIFADRH
	.globl _GPIFCTLCFG
	.globl _GPIFIDLECTL
	.globl _GPIFIDLECS
	.globl _GPIFWFSELECT
	.globl _SETUPDAT
	.globl _SUDPTRCTL
	.globl _SUDPTRL
	.globl _SUDPTRH
	.globl _EP8FIFOBCL
	.globl _EP8FIFOBCH
	.globl _EP6FIFOBCL
	.globl _EP6FIFOBCH
	.globl _EP4FIFOBCL
	.globl _EP4FIFOBCH
	.globl _EP2FIFOBCL
	.globl _EP2FIFOBCH
	.globl _EP8FIFOFLGS
	.globl _EP6FIFOFLGS
	.globl _EP4FIFOFLGS
	.globl _EP2FIFOFLGS
	.globl _EP8CS
	.globl _EP6CS
	.globl _EP4CS
	.globl _EP2CS
	.globl _EP1INCS
	.globl _EP1OUTCS
	.globl _EP0CS
	.globl _EP8BCL
	.globl _EP8BCH
	.globl _EP6BCL
	.globl _EP6BCH
	.globl _EP4BCL
	.globl _EP4BCH
	.globl _EP2BCL
	.globl _EP2BCH
	.globl _EP1INBC
	.globl _EP1OUTBC
	.globl _EP0BCL
	.globl _EP0BCH
	.globl _FNADDR
	.globl _MICROFRAME
	.globl _USBFRAMEL
	.globl _USBFRAMEH
	.globl _TOGCTL
	.globl _WAKEUPCS
	.globl _SUSPEND
	.globl _USBCS
	.globl _XAUTODAT2
	.globl _XAUTODAT1
	.globl _I2CTL
	.globl _I2DAT
	.globl _I2CS
	.globl _PORTECFG
	.globl _PORTCCFG
	.globl _PORTACFG
	.globl _INTSETUP
	.globl _INT4IVEC
	.globl _INT2IVEC
	.globl _CLRERRCNT
	.globl _ERRCNTLIM
	.globl _USBERRIRQ
	.globl _USBERRIE
	.globl _GPIFIRQ
	.globl _GPIFIE
	.globl _EPIRQ
	.globl _EPIE
	.globl _USBIRQ
	.globl _USBIE
	.globl _NAKIRQ
	.globl _NAKIE
	.globl _IBNIRQ
	.globl _IBNIE
	.globl _EP8FIFOIRQ
	.globl _EP8FIFOIE
	.globl _EP6FIFOIRQ
	.globl _EP6FIFOIE
	.globl _EP4FIFOIRQ
	.globl _EP4FIFOIE
	.globl _EP2FIFOIRQ
	.globl _EP2FIFOIE
	.globl _OUTPKTEND
	.globl _INPKTEND
	.globl _EP8ISOINPKTS
	.globl _EP6ISOINPKTS
	.globl _EP4ISOINPKTS
	.globl _EP2ISOINPKTS
	.globl _EP8FIFOPFL
	.globl _EP8FIFOPFH
	.globl _EP6FIFOPFL
	.globl _EP6FIFOPFH
	.globl _EP4FIFOPFL
	.globl _EP4FIFOPFH
	.globl _EP2FIFOPFL
	.globl _EP2FIFOPFH
	.globl _EP8AUTOINLENL
	.globl _EP8AUTOINLENH
	.globl _EP6AUTOINLENL
	.globl _EP6AUTOINLENH
	.globl _EP4AUTOINLENL
	.globl _EP4AUTOINLENH
	.globl _EP2AUTOINLENL
	.globl _EP2AUTOINLENH
	.globl _EP8FIFOCFG
	.globl _EP6FIFOCFG
	.globl _EP4FIFOCFG
	.globl _EP2FIFOCFG
	.globl _EP8CFG
	.globl _EP6CFG
	.globl _EP4CFG
	.globl _EP2CFG
	.globl _EP1INCFG
	.globl _EP1OUTCFG
	.globl _REVCTL
	.globl _REVID
	.globl _FIFOPINPOLAR
	.globl _UART230
	.globl _BPADDRL
	.globl _BPADDRH
	.globl _BREAKPT
	.globl _FIFORESET
	.globl _PINFLAGSCD
	.globl _PINFLAGSAB
	.globl _IFCONFIG
	.globl _CPUCS
	.globl _RES_WAVEDATA_END
	.globl _GPIF_WAVE_DATA
	.globl _FWmark
	.globl _HWmark
	.globl _command
	.globl _dat
	.globl _err
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_IOA	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_DPL1	=	0x0084
_DPH1	=	0x0085
_DPS	=	0x0086
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_CKCO	=	0x008e
_SPC_	=	0x008f
_IOB	=	0x0090
_EXIF	=	0x0091
_MPA	=	0x0092
_SCO	=	0x0098
_SBU	=	0x0099
_APTR1H	=	0x009a
_APTR1L	=	0x009b
_AUTODAT1	=	0x009c
_AUTOPTRH2	=	0x009d
_AUTOPTRL2	=	0x009e
_AUTODAT2	=	0x009f
_IOC	=	0x00a0
_INT2CLR	=	0x00a1
_INT4CLR	=	0x00a2
_IE	=	0x00a8
_EP2468STAT	=	0x00aa
_EP24FIFOFLGS	=	0x00ab
_EP68FIFOFLGS	=	0x00ac
_AUTOPTRSETUP	=	0x00af
_IOD	=	0x00b0
_IOE	=	0x00b1
_OEA	=	0x00b2
_OEB	=	0x00b3
_OEC	=	0x00b4
_OED	=	0x00b5
_OEE	=	0x00b6
_IP	=	0x00b8
_EP01STAT	=	0x00ba
_GPIFTRIG	=	0x00bb
_GPIFSGLDATH	=	0x00bd
_GPIFSGLDATLX	=	0x00be
_GPIFSGLDATLNOX	=	0x00bf
_SCON1	=	0x00c0
_SBUF1	=	0x00c1
_T2CON	=	0x00c8
_RCAP2L	=	0x00ca
_RCAP2H	=	0x00cb
_TL2	=	0x00cc
_TH2	=	0x00cd
_PSW	=	0x00d0
_EICON	=	0x00d8
_ACC	=	0x00e0
_EIE	=	0x00e8
_B	=	0x00f0
_EIP	=	0x00f8
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_err::
	.ds 2
_dat::
	.ds 2
_command::
	.ds 2
_HWmark::
	.ds 2
_hostreadmarkep1poll_ep1outbc_1_46:
	.ds 1
_hostreadmarkep1poll_n_1_46:
	.ds 2
_FWmark::
	.ds 3
_writemarkeeprom_mark_1_62:
	.ds 3
_writemarkeeprom_sloc0_1_0:
	.ds 2
_writemarkeeprom_sloc1_1_0:
	.ds 2
_main_mark_1_65:
	.ds 16
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
_EERead_PARM_2:
	.ds 3
_EERead_n_1_36:
	.ds 2
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
_EEWrite_PARM_2:
	.ds 1
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG	(DATA)
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
_GPIF_WAVE_DATA	=	0xe400
_RES_WAVEDATA_END	=	0xe480
_CPUCS	=	0xe600
_IFCONFIG	=	0xe601
_PINFLAGSAB	=	0xe602
_PINFLAGSCD	=	0xe603
_FIFORESET	=	0xe604
_BREAKPT	=	0xe605
_BPADDRH	=	0xe606
_BPADDRL	=	0xe607
_UART230	=	0xe608
_FIFOPINPOLAR	=	0xe609
_REVID	=	0xe60a
_REVCTL	=	0xe60b
_EP1OUTCFG	=	0xe610
_EP1INCFG	=	0xe611
_EP2CFG	=	0xe612
_EP4CFG	=	0xe613
_EP6CFG	=	0xe614
_EP8CFG	=	0xe615
_EP2FIFOCFG	=	0xe618
_EP4FIFOCFG	=	0xe619
_EP6FIFOCFG	=	0xe61a
_EP8FIFOCFG	=	0xe61b
_EP2AUTOINLENH	=	0xe620
_EP2AUTOINLENL	=	0xe621
_EP4AUTOINLENH	=	0xe622
_EP4AUTOINLENL	=	0xe623
_EP6AUTOINLENH	=	0xe624
_EP6AUTOINLENL	=	0xe625
_EP8AUTOINLENH	=	0xe626
_EP8AUTOINLENL	=	0xe627
_EP2FIFOPFH	=	0xe630
_EP2FIFOPFL	=	0xe631
_EP4FIFOPFH	=	0xe632
_EP4FIFOPFL	=	0xe633
_EP6FIFOPFH	=	0xe634
_EP6FIFOPFL	=	0xe635
_EP8FIFOPFH	=	0xe636
_EP8FIFOPFL	=	0xe637
_EP2ISOINPKTS	=	0xe640
_EP4ISOINPKTS	=	0xe641
_EP6ISOINPKTS	=	0xe642
_EP8ISOINPKTS	=	0xe643
_INPKTEND	=	0xe648
_OUTPKTEND	=	0xe649
_EP2FIFOIE	=	0xe650
_EP2FIFOIRQ	=	0xe651
_EP4FIFOIE	=	0xe652
_EP4FIFOIRQ	=	0xe653
_EP6FIFOIE	=	0xe654
_EP6FIFOIRQ	=	0xe655
_EP8FIFOIE	=	0xe656
_EP8FIFOIRQ	=	0xe657
_IBNIE	=	0xe658
_IBNIRQ	=	0xe659
_NAKIE	=	0xe65a
_NAKIRQ	=	0xe65b
_USBIE	=	0xe65c
_USBIRQ	=	0xe65d
_EPIE	=	0xe65e
_EPIRQ	=	0xe65f
_GPIFIE	=	0xe660
_GPIFIRQ	=	0xe661
_USBERRIE	=	0xe662
_USBERRIRQ	=	0xe663
_ERRCNTLIM	=	0xe664
_CLRERRCNT	=	0xe665
_INT2IVEC	=	0xe666
_INT4IVEC	=	0xe667
_INTSETUP	=	0xe668
_PORTACFG	=	0xe670
_PORTCCFG	=	0xe671
_PORTECFG	=	0xe672
_I2CS	=	0xe678
_I2DAT	=	0xe679
_I2CTL	=	0xe67a
_XAUTODAT1	=	0xe67b
_XAUTODAT2	=	0xe67c
_USBCS	=	0xe680
_SUSPEND	=	0xe681
_WAKEUPCS	=	0xe682
_TOGCTL	=	0xe683
_USBFRAMEH	=	0xe684
_USBFRAMEL	=	0xe685
_MICROFRAME	=	0xe686
_FNADDR	=	0xe687
_EP0BCH	=	0xe68a
_EP0BCL	=	0xe68b
_EP1OUTBC	=	0xe68d
_EP1INBC	=	0xe68f
_EP2BCH	=	0xe690
_EP2BCL	=	0xe691
_EP4BCH	=	0xe694
_EP4BCL	=	0xe695
_EP6BCH	=	0xe698
_EP6BCL	=	0xe699
_EP8BCH	=	0xe69c
_EP8BCL	=	0xe69d
_EP0CS	=	0xe6a0
_EP1OUTCS	=	0xe6a1
_EP1INCS	=	0xe6a2
_EP2CS	=	0xe6a3
_EP4CS	=	0xe6a4
_EP6CS	=	0xe6a5
_EP8CS	=	0xe6a6
_EP2FIFOFLGS	=	0xe6a7
_EP4FIFOFLGS	=	0xe6a8
_EP6FIFOFLGS	=	0xe6a9
_EP8FIFOFLGS	=	0xe6aa
_EP2FIFOBCH	=	0xe6ab
_EP2FIFOBCL	=	0xe6ac
_EP4FIFOBCH	=	0xe6ad
_EP4FIFOBCL	=	0xe6ae
_EP6FIFOBCH	=	0xe6af
_EP6FIFOBCL	=	0xe6b0
_EP8FIFOBCH	=	0xe6b1
_EP8FIFOBCL	=	0xe6b2
_SUDPTRH	=	0xe6b3
_SUDPTRL	=	0xe6b4
_SUDPTRCTL	=	0xe6b5
_SETUPDAT	=	0xe6b8
_GPIFWFSELECT	=	0xe6c0
_GPIFIDLECS	=	0xe6c1
_GPIFIDLECTL	=	0xe6c2
_GPIFCTLCFG	=	0xe6c3
_GPIFADRH	=	0xe6c4
_GPIFADRL	=	0xe6c5
_GPIFTCB3	=	0xe6ce
_GPIFTCB2	=	0xe6cf
_GPIFTCB1	=	0xe6d0
_GPIFTCB0	=	0xe6d1
_EP2GPIFFLGSEL	=	0xe6d2
_EP2GPIFPFSTOP	=	0xe6d3
_EP2GPIFTRIG	=	0xe6d4
_EP4GPIFFLGSEL	=	0xe6da
_EP4GPIFPFSTOP	=	0xe6db
_EP4GPIFTRIG	=	0xe6dc
_EP6GPIFFLGSEL	=	0xe6e2
_EP6GPIFPFSTOP	=	0xe6e3
_EP6GPIFTRIG	=	0xe6e4
_EP8GPIFFLGSEL	=	0xe6ea
_EP8GPIFPFSTOP	=	0xe6eb
_EP8GPIFTRIG	=	0xe6ec
_XGPIFSGLDATH	=	0xe6f0
_XGPIFSGLDATLX	=	0xe6f1
_XGPIFSGLDATLNOX	=	0xe6f2
_GPIFREADYCFG	=	0xe6f3
_GPIFREADYSTAT	=	0xe6f4
_GPIFABORT	=	0xe6f5
_FLOWSTATE	=	0xe6c6
_FLOWLOGIC	=	0xe6c7
_FLOWEQ0CTL	=	0xe6c8
_FLOWEQ1CTL	=	0xe6c9
_FLOWHOLDOFF	=	0xe6ca
_FLOWSTB	=	0xe6cb
_FLOWSTBEDGE	=	0xe6cc
_FLOWSTBHPERIOD	=	0xe6cd
_GPIFHOLDAMOUNT	=	0xe60c
_UDMACRCH	=	0xe67d
_UDMACRCL	=	0xe67e
_UDMACRCQUAL	=	0xe67f
_DBUG	=	0xe6f8
_TESTCFG	=	0xe6f9
_USBTEST	=	0xe6fa
_CT1	=	0xe6fb
_CT2	=	0xe6fc
_CT3	=	0xe6fd
_CT4	=	0xe6fe
_EP0BUF	=	0xe740
_EP1OUTBUF	=	0xe780
_EP1INBUF	=	0xe7c0
_EP2FIFOBUF	=	0xf000
_EP4FIFOBUF	=	0xf400
_EP6FIFOBUF	=	0xf800
_EP8FIFOBUF	=	0xfc00
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
;	eeprom_read.h:14: xdata unsigned char *err =(xdata char*)0x1200;
	mov	_err,#0x00
	mov	(_err + 1),#0x12
;	eeprom_read.h:15: xdata unsigned char *dat =(xdata char*)0x1000;
	mov	_dat,#0x00
	mov	(_dat + 1),#0x10
;	eeprom_read.h:119: xdata unsigned char *command = (xdata unsigned char *)0x1100;
	mov	_command,#0x00
	mov	(_command + 1),#0x11
;	eeprom_read.h:120: xdata unsigned char *HWmark = (xdata unsigned char *)0x1140;
	mov	_HWmark,#0x40
	mov	(_HWmark + 1),#0x11
;	eeprom_mark.c:19: char *FWmark = "FWEEPRv000.001";
	mov	_FWmark,#__str_4
	mov	(_FWmark + 1),#(__str_4 >> 8)
	mov	(_FWmark + 2),#0x80
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	lcall	_main
;	return from main will lock up
	sjmp .
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'EERead'
;------------------------------------------------------------
;HWmark                    Allocated with name '_EERead_PARM_2'
;ee_adr                    Allocated to registers r6 r7 
;n                         Allocated with name '_EERead_n_1_36'
;------------------------------------------------------------
;	eeprom_read.h:34: static uint8 EERead(uint16 ee_adr, 	unsigned char HWmark[32])
;	-----------------------------------------
;	 function EERead
;	-----------------------------------------
_EERead:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r6,dpl
	mov	r7,dph
;	eeprom_read.h:39: I2CS = I2CS_START;
	mov	dptr,#_I2CS
	mov	a,#0x80
	movx	@dptr,a
;	eeprom_read.h:40: I2DAT = EEPROM_ADR | I2CWRITE;
	mov	dptr,#_I2DAT
	mov	a,#0xA2
	movx	@dptr,a
;	eeprom_read.h:41: while(!(I2CS & I2CS_DONE));
00101$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jnb	acc.0,00101$
;	eeprom_read.h:44: if(!(I2CS & I2CS_ACK)) return(1);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jb	acc.1,00105$
	mov	dpl,#0x01
	ret
00105$:
;	eeprom_read.h:47: I2DAT = (ee_adr>>8);
	mov	dptr,#_I2DAT
	mov	a,r7
	movx	@dptr,a
;	eeprom_read.h:48: while(!(I2CS & I2CS_DONE));
00106$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jnb	acc.0,00106$
;	eeprom_read.h:51: if(!(I2CS & I2CS_ACK)) return(2);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jb	acc.1,00110$
	mov	dpl,#0x02
	ret
00110$:
;	eeprom_read.h:54: I2DAT = (ee_adr & 0xff);
	mov	r7,#0x00
	mov	dptr,#_I2DAT
	mov	a,r6
	movx	@dptr,a
;	eeprom_read.h:55: while(!(I2CS & I2CS_DONE));
00111$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00111$
;	eeprom_read.h:58: if(!(I2CS & I2CS_ACK)) return(3);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00115$
	mov	dpl,#0x03
	ret
00115$:
;	eeprom_read.h:61: I2CS = I2CS_START;
	mov	dptr,#_I2CS
	mov	a,#0x80
	movx	@dptr,a
;	eeprom_read.h:62: I2DAT = EEPROM_ADR | I2CREAD;
	mov	dptr,#_I2DAT
	mov	a,#0xA3
	movx	@dptr,a
;	eeprom_read.h:63: while(!(I2CS & I2CS_DONE));
00116$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00116$
;	eeprom_read.h:66: if(!(I2CS & I2CS_ACK)) return(5);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00120$
	mov	dpl,#0x05
	ret
00120$:
;	eeprom_read.h:69: HWmark[0] = I2DAT;
	mov	r5,_EERead_PARM_2
	mov	r6,(_EERead_PARM_2 + 1)
	mov	r7,(_EERead_PARM_2 + 2)
	mov	dptr,#_I2DAT
	movx	a,@dptr
	mov	r4,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrput
;	eeprom_read.h:70: while(!(I2CS & I2CS_DONE));
00121$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jnb	acc.0,00121$
;	eeprom_read.h:71: if(!(I2CS & I2CS_ACK)) return(6);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jb	acc.1,00126$
	mov	dpl,#0x06
	ret
;	eeprom_read.h:74: while(!(I2CS & I2CS_DONE));
00126$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jnb	acc.0,00126$
;	eeprom_read.h:75: if(!(I2CS & I2CS_ACK)) return(7);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jb	acc.1,00130$
	mov	dpl,#0x07
	ret
00130$:
;	eeprom_read.h:77: HWmark[0] = I2DAT;
	mov	dptr,#_I2DAT
	movx	a,@dptr
	mov	r4,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrput
;	eeprom_read.h:78: while(!(I2CS & I2CS_DONE));
00131$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jnb	acc.0,00131$
;	eeprom_read.h:79: if(!(I2CS & I2CS_ACK)) return(8);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jb	acc.1,00135$
	mov	dpl,#0x08
	ret
00135$:
;	eeprom_read.h:81: HWmark[1] = I2DAT;
	mov	a,#0x01
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dptr,#_I2DAT
	movx	a,@dptr
	mov	r1,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrput
;	eeprom_read.h:82: while(!(I2CS & I2CS_DONE));
00136$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jnb	acc.0,00136$
;	eeprom_read.h:83: if(!(I2CS & I2CS_ACK)) return(8);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jb	acc.1,00193$
	mov	dpl,#0x08
	ret
;	eeprom_read.h:85: for(n = 2;n<31;n++) {
00193$:
	mov	_EERead_n_1_36,#0x02
	mov	(_EERead_n_1_36 + 1),#0x00
00159$:
	clr	c
	mov	a,_EERead_n_1_36
	subb	a,#0x1F
	mov	a,(_EERead_n_1_36 + 1)
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00162$
;	eeprom_read.h:86: HWmark[n] = I2DAT;
	mov	a,_EERead_n_1_36
	add	a,r5
	mov	r0,a
	mov	a,(_EERead_n_1_36 + 1)
	addc	a,r6
	mov	r1,a
	mov	ar2,r7
	mov	dptr,#_I2DAT
	movx	a,@dptr
	mov	r4,a
	mov	dpl,r0
	mov	dph,r1
	mov	b,r2
	lcall	__gptrput
;	eeprom_read.h:87: while(!(I2CS & I2CS_DONE));
00141$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jnb	acc.0,00141$
;	eeprom_read.h:88: if(!(I2CS & I2CS_ACK)) return(9);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jb	acc.1,00161$
	mov	dpl,#0x09
	ret
00161$:
;	eeprom_read.h:85: for(n = 2;n<31;n++) {
	inc	_EERead_n_1_36
	clr	a
	cjne	a,_EERead_n_1_36,00159$
	inc	(_EERead_n_1_36 + 1)
	sjmp	00159$
00162$:
;	eeprom_read.h:91: I2CS = I2CS_LASTRD;
	mov	dptr,#_I2CS
	mov	a,#0x20
	movx	@dptr,a
;	eeprom_read.h:92: HWmark[31] = I2DAT;
	mov	a,#0x1F
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dptr,#_I2DAT
	movx	a,@dptr
	mov	r4,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrput
;	eeprom_read.h:93: while(!(I2CS & I2CS_DONE));
00146$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jnb	acc.0,00146$
;	eeprom_read.h:94: HWmark[31] = I2DAT;
	mov	dptr,#_I2DAT
	movx	a,@dptr
	mov	r4,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrput
;	eeprom_read.h:95: while(!(I2CS & I2CS_DONE));
00149$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00149$
;	eeprom_read.h:96: if(!(I2CS & I2CS_ACK)) return(10);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00153$
	mov	dpl,#0x0A
	ret
00153$:
;	eeprom_read.h:107: I2CS = I2CS_STOP;
	mov	dptr,#_I2CS
	mov	a,#0x40
	movx	@dptr,a
;	eeprom_read.h:108: while(!(I2CS & I2CS_DONE));
00154$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00154$
;	eeprom_read.h:110: if(!(I2CS & I2CS_ACK)) return(11);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00158$
	mov	dpl,#0x0B
	ret
00158$:
;	eeprom_read.h:112: return(64);
	mov	dpl,#0x40
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'readmarkeeprom'
;------------------------------------------------------------
;n                         Allocated to registers r6 r7 
;------------------------------------------------------------
;	eeprom_read.h:123: static uint8 readmarkeeprom(void) {
;	-----------------------------------------
;	 function readmarkeeprom
;	-----------------------------------------
_readmarkeeprom:
;	eeprom_read.h:127: I2CTL = 0x01;	// Set 400kHz:
	mov	dptr,#_I2CTL
	mov	a,#0x01
	movx	@dptr,a
;	eeprom_read.h:128: SYNCDELAY;
	nop; 
;	eeprom_read.h:130: for(n=0;n<128;n++) HWmark[n] = 0x00;
	mov	r6,#0x00
	mov	r7,#0x00
00101$:
	clr	c
	mov	a,r6
	subb	a,#0x80
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00104$
	mov	a,r6
	add	a,_HWmark
	mov	dpl,a
	mov	a,r7
	addc	a,(_HWmark + 1)
	mov	dph,a
	clr	a
	movx	@dptr,a
	inc	r6
	cjne	r6,#0x00,00101$
	inc	r7
	sjmp	00101$
00104$:
;	eeprom_read.h:131: err[32+3] = EERead( 0x0400,HWmark);
	mov	a,#0x23
	add	a,_err
	mov	r6,a
	clr	a
	addc	a,(_err + 1)
	mov	r7,a
	mov	_EERead_PARM_2,_HWmark
	mov	(_EERead_PARM_2 + 1),(_HWmark + 1)
	mov	(_EERead_PARM_2 + 2),#0x00
	mov	dptr,#0x0400
	push	ar7
	push	ar6
	lcall	_EERead
	mov	r5,dpl
	pop	ar6
	pop	ar7
	mov	dpl,r6
	mov	dph,r7
	mov	a,r5
	movx	@dptr,a
;	eeprom_read.h:132: return(0);
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'hostreadmarkep1init'
;------------------------------------------------------------
;	eeprom_read.h:136: static uint8 hostreadmarkep1init(void) {
;	-----------------------------------------
;	 function hostreadmarkep1init
;	-----------------------------------------
_hostreadmarkep1init:
;	eeprom_read.h:138: EP1OUTCFG=0xa0;
	mov	dptr,#_EP1OUTCFG
	mov	a,#0xA0
	movx	@dptr,a
;	eeprom_read.h:139: EP1INCFG=0xa0;
	mov	dptr,#_EP1INCFG
	mov	a,#0xA0
	movx	@dptr,a
;	eeprom_read.h:141: SYNCDELAY;
	nop; 
;	eeprom_read.h:142: EP1OUTBC=0xff; // Arm endpoint 1 for OUT (host->device) transfers
	mov	dptr,#_EP1OUTBC
	mov	a,#0xFF
	movx	@dptr,a
;	eeprom_read.h:144: return(0);
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'hostreadmarkep1poll'
;------------------------------------------------------------
;src                       Allocated to registers 
;dest                      Allocated to registers r5 r6 
;ep1outbc                  Allocated with name '_hostreadmarkep1poll_ep1outbc_1_46'
;n                         Allocated with name '_hostreadmarkep1poll_n_1_46'
;------------------------------------------------------------
;	eeprom_read.h:147: static uint8 hostreadmarkep1poll(void) {
;	-----------------------------------------
;	 function hostreadmarkep1poll
;	-----------------------------------------
_hostreadmarkep1poll:
;	eeprom_read.h:153: if(!(EP1OUTCS & bmEPBUSY)) {
	mov	dptr,#_EP1OUTCS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.1,00169$
	ljmp	00114$
00169$:
;	eeprom_read.h:154: ep1outbc = EP1OUTBC;
	mov	dptr,#_EP1OUTBC
	movx	a,@dptr
	mov	_hostreadmarkep1poll_ep1outbc_1_46,a
;	eeprom_read.h:155: if(ep1outbc != 0xff ) {
	mov	a,#0xFF
	cjne	a,_hostreadmarkep1poll_ep1outbc_1_46,00170$
	ljmp	00114$
00170$:
;	eeprom_read.h:156: src = EP1OUTBUF;
;	eeprom_read.h:157: dest = EP1INBUF;
	mov	r5,#_EP1INBUF
	mov	r6,#(_EP1INBUF >> 8)
;	eeprom_read.h:158: while (EP1INCS & 0x02);
00101$:
	mov	dptr,#_EP1INCS
	movx	a,@dptr
	mov	r4,a
	jb	acc.1,00101$
;	eeprom_read.h:159: for(n=0; n<32; n++) command[n] = src[n];
	mov	r3,#0x00
	mov	r4,#0x00
00115$:
	clr	c
	mov	a,r3
	subb	a,#0x20
	mov	a,r4
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00118$
	mov	a,r3
	add	a,_command
	mov	r1,a
	mov	a,r4
	addc	a,(_command + 1)
	mov	r2,a
	mov	a,r3
	add	a,#_EP1OUTBUF
	mov	dpl,a
	mov	a,r4
	addc	a,#(_EP1OUTBUF >> 8)
	mov	dph,a
	movx	a,@dptr
	mov	r0,a
	mov	dpl,r1
	mov	dph,r2
	movx	@dptr,a
	inc	r3
	cjne	r3,#0x00,00115$
	inc	r4
	sjmp	00115$
00118$:
;	eeprom_read.h:160: for( n=0; n < ep1outbc ; n++ ) { 
	mov	ar3,r5
	mov	ar4,r6
	mov	r1,#0x00
	mov	r2,#0x00
00119$:
	mov	r0,_hostreadmarkep1poll_ep1outbc_1_46
	mov	r7,#0x00
	clr	c
	mov	a,r1
	subb	a,r0
	mov	a,r2
	xrl	a,#0x80
	mov	b,r7
	xrl	b,#0x80
	subb	a,b
	jnc	00122$
;	eeprom_read.h:161: *dest++ = command[n];
	mov	a,r1
	add	a,_command
	mov	dpl,a
	mov	a,r2
	addc	a,(_command + 1)
	mov	dph,a
	movx	a,@dptr
	mov	r7,a
	mov	dpl,r3
	mov	dph,r4
	movx	@dptr,a
	inc	dptr
	mov	r3,dpl
	mov	r4,dph
;	eeprom_read.h:160: for( n=0; n < ep1outbc ; n++ ) { 
	inc	r1
	cjne	r1,#0x00,00119$
	inc	r2
	sjmp	00119$
00122$:
;	eeprom_read.h:163: *err++ = 0x5a;
	mov	dpl,_err
	mov	dph,(_err + 1)
	mov	a,#0x5A
	movx	@dptr,a
	inc	_err
	clr	a
	cjne	a,_err,00176$
	inc	(_err + 1)
00176$:
;	eeprom_read.h:164: EP1INBC = ep1outbc;
	mov	dptr,#_EP1INBC
	mov	a,_hostreadmarkep1poll_ep1outbc_1_46
	movx	@dptr,a
;	eeprom_read.h:165: while (EP1INCS & 0x02);
00104$:
	mov	dptr,#_EP1INCS
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00104$
;	eeprom_read.h:166: dest = EP1INBUF;
	mov	r5,#_EP1INBUF
	mov	r6,#(_EP1INBUF >> 8)
;	eeprom_read.h:167: if(!strncmp(command,"getHW",5)) {
	mov	r3,_command
	mov	r4,(_command + 1)
	mov	r7,#0x00
	mov	_strncmp_PARM_2,#__str_0
	mov	(_strncmp_PARM_2 + 1),#(__str_0 >> 8)
	mov	(_strncmp_PARM_2 + 2),#0x80
	mov	_strncmp_PARM_3,#0x05
	mov	(_strncmp_PARM_3 + 1),#0x00
	mov	dpl,r3
	mov	dph,r4
	mov	b,r7
	push	ar6
	push	ar5
	lcall	_strncmp
	mov	a,dpl
	mov	b,dph
	pop	ar5
	pop	ar6
	orl	a,b
;	eeprom_read.h:168: for( n=0; HWmark[n] != '\0' ; n++ )  
	jnz	00108$
	mov	ar4,r5
	mov	ar7,r6
	mov	r2,a
	mov	r3,a
00123$:
	mov	a,r2
	add	a,_HWmark
	mov	dpl,a
	mov	a,r3
	addc	a,(_HWmark + 1)
	mov	dph,a
	movx	a,@dptr
	mov	r1,a
	jz	00126$
;	eeprom_read.h:169: *dest++ = (xdata unsigned char) HWmark[n];					
	mov	dpl,r4
	mov	dph,r7
	mov	a,r1
	movx	@dptr,a
	inc	dptr
	mov	r4,dpl
	mov	r7,dph
;	eeprom_read.h:168: for( n=0; HWmark[n] != '\0' ; n++ )  
	inc	r2
	cjne	r2,#0x00,00123$
	inc	r3
	sjmp	00123$
00126$:
;	eeprom_read.h:170: *dest++ = '\0';
	mov	dpl,r4
	mov	dph,r7
	clr	a
	movx	@dptr,a
	mov	a,#0x01
	add	a,r4
	mov	r5,a
	clr	a
	addc	a,r7
	mov	r6,a
;	eeprom_read.h:171: n++;
	mov	a,#0x01
	add	a,r2
	mov	r4,a
	clr	a
	addc	a,r3
	mov	r7,a
;	eeprom_read.h:172: EP1INBC = n;
	mov	dptr,#_EP1INBC
	mov	a,r4
	movx	@dptr,a
;	eeprom_read.h:173: SYNCDELAY;
	nop; 
00108$:
;	eeprom_read.h:175: if(!strncmp(command,"getFW",5)) {
	mov	r1,_command
	mov	r2,(_command + 1)
	mov	r3,#0x00
	mov	_strncmp_PARM_2,#__str_1
	mov	(_strncmp_PARM_2 + 1),#(__str_1 >> 8)
	mov	(_strncmp_PARM_2 + 2),#0x80
	mov	_strncmp_PARM_3,#0x05
	mov	(_strncmp_PARM_3 + 1),#0x00
	mov	dpl,r1
	mov	dph,r2
	mov	b,r3
	push	ar6
	push	ar5
	lcall	_strncmp
	mov	a,dpl
	mov	b,dph
	pop	ar5
	pop	ar6
	orl	a,b
;	eeprom_read.h:176: for( n=0; FWmark[n] != '\0' ; n++ )  
	jnz	00110$
	mov	_hostreadmarkep1poll_n_1_46,a
	mov	(_hostreadmarkep1poll_n_1_46 + 1),a
00127$:
	mov	a,_hostreadmarkep1poll_n_1_46
	add	a,_FWmark
	mov	r0,a
	mov	a,(_hostreadmarkep1poll_n_1_46 + 1)
	addc	a,(_FWmark + 1)
	mov	r1,a
	mov	r3,(_FWmark + 2)
	mov	dpl,r0
	mov	dph,r1
	mov	b,r3
	lcall	__gptrget
	mov	r3,a
	jz	00130$
;	eeprom_read.h:177: *dest++ = (xdata unsigned char) FWmark[n];					
	mov	dpl,r5
	mov	dph,r6
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	r5,dpl
	mov	r6,dph
;	eeprom_read.h:176: for( n=0; FWmark[n] != '\0' ; n++ )  
	inc	_hostreadmarkep1poll_n_1_46
	clr	a
	cjne	a,_hostreadmarkep1poll_n_1_46,00127$
	inc	(_hostreadmarkep1poll_n_1_46 + 1)
	sjmp	00127$
00130$:
;	eeprom_read.h:178: *dest++ = '\0';
	mov	dpl,r5
	mov	dph,r6
	clr	a
	movx	@dptr,a
;	eeprom_read.h:179: n++;
	mov	a,#0x01
	add	a,_hostreadmarkep1poll_n_1_46
	mov	r4,a
	clr	a
	addc	a,(_hostreadmarkep1poll_n_1_46 + 1)
	mov	r7,a
;	eeprom_read.h:180: EP1INBC = n;
	mov	dptr,#_EP1INBC
	mov	a,r4
	movx	@dptr,a
;	eeprom_read.h:181: SYNCDELAY;
	nop; 
00110$:
;	eeprom_read.h:183: EP1OUTBC = 0xff;
	mov	dptr,#_EP1OUTBC
	mov	a,#0xFF
	movx	@dptr,a
00114$:
;	eeprom_read.h:186: return(0);
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'EEErase'
;------------------------------------------------------------
;ee_adr                    Allocated to registers r6 r7 
;------------------------------------------------------------
;	eeprom_mark.c:47: static uint8 EEErase(uint16 ee_adr)
;	-----------------------------------------
;	 function EEErase
;	-----------------------------------------
_EEErase:
	mov	r6,dpl
	mov	r7,dph
;	eeprom_mark.c:49: I2CS = I2CS_START;
	mov	dptr,#_I2CS
	mov	a,#0x80
	movx	@dptr,a
;	eeprom_mark.c:50: I2DAT = EEPROM_ADR | I2CWRITE;
	mov	dptr,#_I2DAT
	mov	a,#0xA2
	movx	@dptr,a
;	eeprom_mark.c:51: while(!(I2CS & I2CS_DONE));
00101$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jnb	acc.0,00101$
;	eeprom_mark.c:54: if(!(I2CS & I2CS_ACK)) return(1);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jb	acc.1,00105$
	mov	dpl,#0x01
	ret
00105$:
;	eeprom_mark.c:57: I2DAT = (ee_adr>>8);
	mov	dptr,#_I2DAT
	mov	a,r7
	movx	@dptr,a
;	eeprom_mark.c:58: while(!(I2CS & I2CS_DONE));
00106$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jnb	acc.0,00106$
;	eeprom_mark.c:61: if(!(I2CS & I2CS_ACK)) return(2);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jb	acc.1,00110$
	mov	dpl,#0x02
	ret
00110$:
;	eeprom_mark.c:64: I2DAT = (ee_adr & 0xff);
	mov	r7,#0x00
	mov	dptr,#_I2DAT
	mov	a,r6
	movx	@dptr,a
;	eeprom_mark.c:65: while(!(I2CS & I2CS_DONE));
00111$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00111$
;	eeprom_mark.c:68: if(!(I2CS & I2CS_ACK)) return(3);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00115$
	mov	dpl,#0x03
	ret
00115$:
;	eeprom_mark.c:71: I2DAT = 0xff;
	mov	dptr,#_I2DAT
	mov	a,#0xFF
	movx	@dptr,a
;	eeprom_mark.c:72: while(!(I2CS & I2CS_DONE));
00116$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00116$
;	eeprom_mark.c:74: I2CS = I2CS_STOP;
;	eeprom_mark.c:76: if(!(I2CS & I2CS_ACK)) return(4);
	mov	dptr,#_I2CS
	mov	a,#0x40
	movx	@dptr,a
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00127$
	mov	dpl,#0x04
	ret
00127$:
;	eeprom_mark.c:81: I2CS = I2CS_START;
	mov	dptr,#_I2CS
	mov	a,#0x80
	movx	@dptr,a
;	eeprom_mark.c:82: I2DAT = EEPROM_ADR | I2CWRITE;
	mov	dptr,#_I2DAT
	mov	a,#0xA2
	movx	@dptr,a
;	eeprom_mark.c:83: while(!(I2CS & I2CS_DONE));
00121$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00121$
;	eeprom_mark.c:85: if((I2CS & I2CS_ACK)) break;
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.1,00127$
;	eeprom_mark.c:88: return(64);
	mov	dpl,#0x40
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'EEWrite'
;------------------------------------------------------------
;a                         Allocated with name '_EEWrite_PARM_2'
;ee_adr                    Allocated to registers r6 r7 
;------------------------------------------------------------
;	eeprom_mark.c:96: static uint8 EEWrite(uint16 ee_adr, unsigned char a)
;	-----------------------------------------
;	 function EEWrite
;	-----------------------------------------
_EEWrite:
	mov	r6,dpl
	mov	r7,dph
;	eeprom_mark.c:98: I2CS = I2CS_START;
	mov	dptr,#_I2CS
	mov	a,#0x80
	movx	@dptr,a
;	eeprom_mark.c:99: I2DAT = EEPROM_ADR | I2CWRITE;
	mov	dptr,#_I2DAT
	mov	a,#0xA2
	movx	@dptr,a
;	eeprom_mark.c:100: while(!(I2CS & I2CS_DONE));
00101$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jnb	acc.0,00101$
;	eeprom_mark.c:103: if(!(I2CS & I2CS_ACK)) return(1);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jb	acc.1,00105$
	mov	dpl,#0x01
	ret
00105$:
;	eeprom_mark.c:106: I2DAT = (ee_adr>>8);
	mov	dptr,#_I2DAT
	mov	a,r7
	movx	@dptr,a
;	eeprom_mark.c:107: while(!(I2CS & I2CS_DONE));
00106$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jnb	acc.0,00106$
;	eeprom_mark.c:110: if(!(I2CS & I2CS_ACK)) return(2);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jb	acc.1,00110$
	mov	dpl,#0x02
	ret
00110$:
;	eeprom_mark.c:113: I2DAT = (ee_adr & 0xff);
	mov	r7,#0x00
	mov	dptr,#_I2DAT
	mov	a,r6
	movx	@dptr,a
;	eeprom_mark.c:114: while(!(I2CS & I2CS_DONE));
00111$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00111$
;	eeprom_mark.c:117: if(!(I2CS & I2CS_ACK)) return(3);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00115$
	mov	dpl,#0x03
	ret
00115$:
;	eeprom_mark.c:120: I2DAT = a;
	mov	dptr,#_I2DAT
	mov	a,_EEWrite_PARM_2
	movx	@dptr,a
;	eeprom_mark.c:121: while(!(I2CS & I2CS_DONE));
00116$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00116$
;	eeprom_mark.c:123: I2CS = I2CS_STOP;
;	eeprom_mark.c:125: if(!(I2CS & I2CS_ACK)) return(4);
	mov	dptr,#_I2CS
	mov	a,#0x40
	movx	@dptr,a
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00127$
	mov	dpl,#0x04
	ret
00127$:
;	eeprom_mark.c:130: I2CS = I2CS_START;
	mov	dptr,#_I2CS
	mov	a,#0x80
	movx	@dptr,a
;	eeprom_mark.c:131: I2DAT = EEPROM_ADR | I2CWRITE;
	mov	dptr,#_I2DAT
	mov	a,#0xA2
	movx	@dptr,a
;	eeprom_mark.c:132: while(!(I2CS & I2CS_DONE));
00121$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00121$
;	eeprom_mark.c:134: if((I2CS & I2CS_ACK)) break;
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.1,00127$
;	eeprom_mark.c:136: return(64);
	mov	dpl,#0x40
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'writemarkeeprom'
;------------------------------------------------------------
;mark                      Allocated with name '_writemarkeeprom_mark_1_62'
;n                         Allocated to registers r3 r4 
;sloc0                     Allocated with name '_writemarkeeprom_sloc0_1_0'
;sloc1                     Allocated with name '_writemarkeeprom_sloc1_1_0'
;------------------------------------------------------------
;	eeprom_mark.c:153: static uint8 writemarkeeprom(struct mark *mark) {
;	-----------------------------------------
;	 function writemarkeeprom
;	-----------------------------------------
_writemarkeeprom:
	mov	_writemarkeeprom_mark_1_62,dpl
	mov	(_writemarkeeprom_mark_1_62 + 1),dph
	mov	(_writemarkeeprom_mark_1_62 + 2),b
;	eeprom_mark.c:157: I2CTL = 0x01;	// Set 400kHz:
	mov	dptr,#_I2CTL
	mov	a,#0x01
	movx	@dptr,a
;	eeprom_mark.c:158: SYNCDELAY;
	nop; 
;	eeprom_mark.c:160: for(n=0;n<128;n++) HWmark[n] = 0x00;
	mov	r3,#0x00
	mov	r4,#0x00
00101$:
	clr	c
	mov	a,r3
	subb	a,#0x80
	mov	a,r4
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00104$
	mov	a,r3
	add	a,_HWmark
	mov	dpl,a
	mov	a,r4
	addc	a,(_HWmark + 1)
	mov	dph,a
	clr	a
	movx	@dptr,a
	inc	r3
	cjne	r3,#0x00,00101$
	inc	r4
	sjmp	00101$
00104$:
;	eeprom_mark.c:164: mark->serial_no_high,mark->serial_no_low);
	mov	a,#0x0E
	add	a,_writemarkeeprom_mark_1_62
	mov	r2,a
	clr	a
	addc	a,(_writemarkeeprom_mark_1_62 + 1)
	mov	r3,a
	mov	r4,(_writemarkeeprom_mark_1_62 + 2)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	mov	a,#0x0C
	add	a,_writemarkeeprom_mark_1_62
	mov	r0,a
	clr	a
	addc	a,(_writemarkeeprom_mark_1_62 + 1)
	mov	r1,a
	mov	r4,(_writemarkeeprom_mark_1_62 + 2)
	mov	dpl,r0
	mov	dph,r1
	mov	b,r4
	lcall	__gptrget
	mov	r0,a
	inc	dptr
	lcall	__gptrget
	mov	r1,a
;	eeprom_mark.c:163: mark->type,mark->major_version, mark->minor_version,
	mov	a,#0x0A
	add	a,_writemarkeeprom_mark_1_62
	mov	r4,a
	clr	a
	addc	a,(_writemarkeeprom_mark_1_62 + 1)
	mov	r6,a
	mov	r7,(_writemarkeeprom_mark_1_62 + 2)
	mov	dpl,r4
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	_writemarkeeprom_sloc0_1_0,a
	inc	dptr
	lcall	__gptrget
	mov	(_writemarkeeprom_sloc0_1_0 + 1),a
	mov	a,#0x08
	add	a,_writemarkeeprom_mark_1_62
	mov	r5,a
	clr	a
	addc	a,(_writemarkeeprom_mark_1_62 + 1)
	mov	r6,a
	mov	r7,(_writemarkeeprom_mark_1_62 + 2)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	_writemarkeeprom_sloc1_1_0,a
	inc	dptr
	lcall	__gptrget
	mov	(_writemarkeeprom_sloc1_1_0 + 1),a
;	eeprom_mark.c:162: sprintf(HWmark,"HW%sv%03x.%03xs%04x.%04x",
	mov	r4,_HWmark
	mov	r6,(_HWmark + 1)
	mov	r7,#0x00
	push	ar2
	push	ar3
	push	ar0
	push	ar1
	push	_writemarkeeprom_sloc0_1_0
	push	(_writemarkeeprom_sloc0_1_0 + 1)
	push	_writemarkeeprom_sloc1_1_0
	push	(_writemarkeeprom_sloc1_1_0 + 1)
	push	_writemarkeeprom_mark_1_62
	push	(_writemarkeeprom_mark_1_62 + 1)
	push	(_writemarkeeprom_mark_1_62 + 2)
	mov	a,#__str_2
	push	acc
	mov	a,#(__str_2 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	push	ar4
	push	ar6
	push	ar7
	lcall	_sprintf
	mov	a,sp
	add	a,#0xef
	mov	sp,a
;	eeprom_mark.c:165: for(n=0;n<32;n++) err[n+2] = EEWrite(0x0400+n,0x00);
	mov	r6,#0x00
	mov	r7,#0x00
00105$:
	clr	c
	mov	a,r6
	subb	a,#0x20
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00108$
	mov	a,#0x02
	add	a,r6
	mov	r4,a
	clr	a
	addc	a,r7
	mov	r5,a
	mov	a,r4
	add	a,_err
	mov	r4,a
	mov	a,r5
	addc	a,(_err + 1)
	mov	r5,a
	mov	dpl,r6
	mov	a,#0x04
	add	a,r7
	mov	dph,a
	mov	_EEWrite_PARM_2,#0x00
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	lcall	_EEWrite
	mov	r3,dpl
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	dpl,r4
	mov	dph,r5
	mov	a,r3
	movx	@dptr,a
	inc	r6
	cjne	r6,#0x00,00105$
	inc	r7
	sjmp	00105$
00108$:
;	eeprom_mark.c:166: for(n=0;n<32;n++) err[n+2] = EEWrite(0x0400+n,HWmark[n]);
	mov	r6,#0x00
	mov	r7,#0x00
00109$:
	clr	c
	mov	a,r6
	subb	a,#0x20
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00112$
	mov	a,#0x02
	add	a,r6
	mov	r4,a
	clr	a
	addc	a,r7
	mov	r5,a
	mov	a,r4
	add	a,_err
	mov	r4,a
	mov	a,r5
	addc	a,(_err + 1)
	mov	r5,a
	mov	ar2,r6
	mov	a,#0x04
	add	a,r7
	mov	r3,a
	mov	a,r6
	add	a,_HWmark
	mov	dpl,a
	mov	a,r7
	addc	a,(_HWmark + 1)
	mov	dph,a
	movx	a,@dptr
	mov	_EEWrite_PARM_2,a
	mov	dpl,r2
	mov	dph,r3
	push	ar7
	push	ar6
	push	ar5
	push	ar4
	lcall	_EEWrite
	mov	r3,dpl
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	mov	dpl,r4
	mov	dph,r5
	mov	a,r3
	movx	@dptr,a
	inc	r6
	cjne	r6,#0x00,00109$
	inc	r7
	sjmp	00109$
00112$:
;	eeprom_mark.c:168: return(0);
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;n                         Allocated to registers r6 r7 
;eeprom_mark_adr           Allocated to registers 
;adr                       Allocated to registers 
;mark                      Allocated with name '_main_mark_1_65'
;------------------------------------------------------------
;	eeprom_mark.c:171: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	eeprom_mark.c:178: err = (xdata unsigned char *) 0x1200;	
	mov	_err,#0x00
	mov	(_err + 1),#0x12
;	eeprom_mark.c:190: strcpy(mark.type,"DDS_");
	mov	_strcpy_PARM_2,#__str_3
	mov	(_strcpy_PARM_2 + 1),#(__str_3 >> 8)
	mov	(_strcpy_PARM_2 + 2),#0x80
	mov	dptr,#_main_mark_1_65
	mov	b,#0x40
	lcall	_strcpy
;	eeprom_mark.c:192: mark.major_version = 0x0;
	clr	a
	mov	((_main_mark_1_65 + 0x0008) + 0),a
	mov	((_main_mark_1_65 + 0x0008) + 1),a
;	eeprom_mark.c:193: mark.minor_version = 0x1;
	mov	((_main_mark_1_65 + 0x000a) + 0),#0x01
;	eeprom_mark.c:195: mark.serial_no_high = 0x0;
	clr	a
	mov	((_main_mark_1_65 + 0x000a) + 1),a
	mov	((_main_mark_1_65 + 0x000c) + 0),a
	mov	((_main_mark_1_65 + 0x000c) + 1),a
;	eeprom_mark.c:196: mark.serial_no_low  = 0x1;
	mov	((_main_mark_1_65 + 0x000e) + 0),#0x01
	mov	((_main_mark_1_65 + 0x000e) + 1),#0x00
;	eeprom_mark.c:200: for(n = 0;n < 200;n++);
	mov	r6,#0xC8
	mov	r7,#0x00
00103$:
	dec	r6
	cjne	r6,#0xFF,00125$
	dec	r7
00125$:
	mov	a,r6
	orl	a,r7
	jnz	00103$
;	eeprom_mark.c:201: readmarkeeprom();
	lcall	_readmarkeeprom
;	eeprom_mark.c:202: for(n=0;n<32;n++) dat[n] = (xdata char)HWmark[n];
	mov	r6,#0x00
	mov	r7,#0x00
00104$:
	clr	c
	mov	a,r6
	subb	a,#0x20
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00107$
	mov	a,r6
	add	a,_dat
	mov	r4,a
	mov	a,r7
	addc	a,(_dat + 1)
	mov	r5,a
	mov	a,r6
	add	a,_HWmark
	mov	dpl,a
	mov	a,r7
	addc	a,(_HWmark + 1)
	mov	dph,a
	movx	a,@dptr
	mov	r3,a
	mov	dpl,r4
	mov	dph,r5
	movx	@dptr,a
	inc	r6
	cjne	r6,#0x00,00104$
	inc	r7
	sjmp	00104$
00107$:
;	eeprom_mark.c:204: hostreadmarkep1init();
	lcall	_hostreadmarkep1init
00109$:
;	eeprom_mark.c:205: for(;;) hostreadmarkep1poll();	
	lcall	_hostreadmarkep1poll
	sjmp	00109$
	.area CSEG    (CODE)
	.area CONST   (CODE)
__str_0:
	.ascii "getHW"
	.db 0x00
__str_1:
	.ascii "getFW"
	.db 0x00
__str_2:
	.ascii "HW%sv%03x.%03xs%04x.%04x"
	.db 0x00
__str_3:
	.ascii "DDS_"
	.db 0x00
__str_4:
	.ascii "FWEEPRv000.001"
	.db 0x00
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
