;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
; This file was generated Sun Apr 26 07:15:20 2015
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
	.globl _HWmark
	.globl _command
	.globl _jump_table
	.globl _dat
	.globl _err
	.globl _FWmark
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
_FWmark::
	.ds 3
_err::
	.ds 2
_dat::
	.ds 2
_jump_table::
	.ds 2
_command::
	.ds 2
_HWmark::
	.ds 2
_writemarkeeprom_mark_1_1:
	.ds 3
_writemarkeeprom_sloc0_1_0:
	.ds 2
_writemarkeeprom_sloc1_1_0:
	.ds 2
_main_mark_1_1:
	.ds 16
_hostreadmarkep1poll_ep1outbc_1_1:
	.ds 1
_hostreadmarkep1poll_n_1_1:
	.ds 2
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
_EEWrite_PARM_2:
	.ds 1
	.area	OSEG    (OVR,DATA)
_EERead_PARM_2:
	.ds 3
_EERead_n_1_1:
	.ds 2
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
;	eeprom_mark.c:19: char *FWmark = "FWEEPRv000.001";
	mov	_FWmark,#__str_5
	mov	(_FWmark + 1),#(__str_5 >> 8)
	mov	(_FWmark + 2),#0x80
;	eeprom_mark.c:21: xdata unsigned char *err =(xdata char*)0x1200;
	mov	_err,#0x00
	mov	(_err + 1),#0x12
;	eeprom_mark.c:22: xdata unsigned char *dat =(xdata char*)0x1000;
	mov	_dat,#0x00
	mov	(_dat + 1),#0x10
;	eeprom_mark.c:23: xdata unsigned char *jump_table =(xdata char*)0x1400;
	mov	_jump_table,#0x00
	mov	(_jump_table + 1),#0x14
;	eeprom_mark.c:234: xdata unsigned char *command = (xdata unsigned char *)0x1100;
	mov	_command,#0x00
	mov	(_command + 1),#0x11
;	eeprom_mark.c:235: xdata unsigned char *HWmark = (xdata unsigned char *)0x1140;
	mov	_HWmark,#0x40
	mov	(_HWmark + 1),#0x11
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
;Allocation info for local variables in function 'EEErase'
;------------------------------------------------------------
;ee_adr                    Allocated to registers r6 r7 
;------------------------------------------------------------
;	eeprom_mark.c:43: static uint8 EEErase(uint16 ee_adr)
;	-----------------------------------------
;	 function EEErase
;	-----------------------------------------
_EEErase:
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
;	eeprom_mark.c:45: I2CS = I2CS_START;
	mov	dptr,#_I2CS
	mov	a,#0x80
	movx	@dptr,a
;	eeprom_mark.c:46: I2DAT = EEPROM_ADR | I2CWRITE;
	mov	dptr,#_I2DAT
	mov	a,#0xA2
	movx	@dptr,a
;	eeprom_mark.c:47: while(!(I2CS & I2CS_DONE));
00101$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jnb	acc.0,00101$
;	eeprom_mark.c:50: if(!(I2CS & I2CS_ACK)) return(1);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jb	acc.1,00105$
	mov	dpl,#0x01
	ret
00105$:
;	eeprom_mark.c:53: I2DAT = (ee_adr>>8);
	mov	dptr,#_I2DAT
	mov	a,r7
	movx	@dptr,a
;	eeprom_mark.c:54: while(!(I2CS & I2CS_DONE));
00106$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jnb	acc.0,00106$
;	eeprom_mark.c:57: if(!(I2CS & I2CS_ACK)) return(2);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jb	acc.1,00110$
	mov	dpl,#0x02
	ret
00110$:
;	eeprom_mark.c:60: I2DAT = (ee_adr & 0xff);
	mov	r7,#0x00
	mov	dptr,#_I2DAT
	mov	a,r6
	movx	@dptr,a
;	eeprom_mark.c:61: while(!(I2CS & I2CS_DONE));
00111$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00111$
;	eeprom_mark.c:64: if(!(I2CS & I2CS_ACK)) return(3);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00115$
	mov	dpl,#0x03
	ret
00115$:
;	eeprom_mark.c:67: I2DAT = 0xff;
	mov	dptr,#_I2DAT
	mov	a,#0xFF
	movx	@dptr,a
;	eeprom_mark.c:68: while(!(I2CS & I2CS_DONE));
00116$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00116$
;	eeprom_mark.c:70: I2CS = I2CS_STOP;
;	eeprom_mark.c:72: if(!(I2CS & I2CS_ACK)) return(4);
	mov	dptr,#_I2CS
	mov	a,#0x40
	movx	@dptr,a
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00127$
	mov	dpl,#0x04
	ret
00127$:
;	eeprom_mark.c:77: I2CS = I2CS_START;
	mov	dptr,#_I2CS
	mov	a,#0x80
	movx	@dptr,a
;	eeprom_mark.c:78: I2DAT = EEPROM_ADR | I2CWRITE;
	mov	dptr,#_I2DAT
	mov	a,#0xA2
	movx	@dptr,a
;	eeprom_mark.c:79: while(!(I2CS & I2CS_DONE));
00121$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00121$
;	eeprom_mark.c:81: if((I2CS & I2CS_ACK)) break;
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.1,00127$
;	eeprom_mark.c:84: return(64);
	mov	dpl,#0x40
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'EEWrite'
;------------------------------------------------------------
;a                         Allocated with name '_EEWrite_PARM_2'
;ee_adr                    Allocated to registers r6 r7 
;------------------------------------------------------------
;	eeprom_mark.c:92: static uint8 EEWrite(uint16 ee_adr, unsigned char a)
;	-----------------------------------------
;	 function EEWrite
;	-----------------------------------------
_EEWrite:
	mov	r6,dpl
	mov	r7,dph
;	eeprom_mark.c:94: I2CS = I2CS_START;
	mov	dptr,#_I2CS
	mov	a,#0x80
	movx	@dptr,a
;	eeprom_mark.c:95: I2DAT = EEPROM_ADR | I2CWRITE;
	mov	dptr,#_I2DAT
	mov	a,#0xA2
	movx	@dptr,a
;	eeprom_mark.c:96: while(!(I2CS & I2CS_DONE));
00101$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jnb	acc.0,00101$
;	eeprom_mark.c:99: if(!(I2CS & I2CS_ACK)) return(1);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jb	acc.1,00105$
	mov	dpl,#0x01
	ret
00105$:
;	eeprom_mark.c:102: I2DAT = (ee_adr>>8);
	mov	dptr,#_I2DAT
	mov	a,r7
	movx	@dptr,a
;	eeprom_mark.c:103: while(!(I2CS & I2CS_DONE));
00106$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jnb	acc.0,00106$
;	eeprom_mark.c:106: if(!(I2CS & I2CS_ACK)) return(2);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jb	acc.1,00110$
	mov	dpl,#0x02
	ret
00110$:
;	eeprom_mark.c:109: I2DAT = (ee_adr & 0xff);
	mov	r7,#0x00
	mov	dptr,#_I2DAT
	mov	a,r6
	movx	@dptr,a
;	eeprom_mark.c:110: while(!(I2CS & I2CS_DONE));
00111$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00111$
;	eeprom_mark.c:113: if(!(I2CS & I2CS_ACK)) return(3);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00115$
	mov	dpl,#0x03
	ret
00115$:
;	eeprom_mark.c:116: I2DAT = a;
	mov	dptr,#_I2DAT
	mov	a,_EEWrite_PARM_2
	movx	@dptr,a
;	eeprom_mark.c:117: while(!(I2CS & I2CS_DONE));
00116$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00116$
;	eeprom_mark.c:119: I2CS = I2CS_STOP;
;	eeprom_mark.c:121: if(!(I2CS & I2CS_ACK)) return(4);
	mov	dptr,#_I2CS
	mov	a,#0x40
	movx	@dptr,a
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00127$
	mov	dpl,#0x04
	ret
00127$:
;	eeprom_mark.c:126: I2CS = I2CS_START;
	mov	dptr,#_I2CS
	mov	a,#0x80
	movx	@dptr,a
;	eeprom_mark.c:127: I2DAT = EEPROM_ADR | I2CWRITE;
	mov	dptr,#_I2DAT
	mov	a,#0xA2
	movx	@dptr,a
;	eeprom_mark.c:128: while(!(I2CS & I2CS_DONE));
00121$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00121$
;	eeprom_mark.c:130: if((I2CS & I2CS_ACK)) break;
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.1,00127$
;	eeprom_mark.c:132: return(64);
	mov	dpl,#0x40
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'EERead'
;------------------------------------------------------------
;HWmark                    Allocated with name '_EERead_PARM_2'
;ee_adr                    Allocated to registers r6 r7 
;n                         Allocated with name '_EERead_n_1_1'
;------------------------------------------------------------
;	eeprom_mark.c:140: static uint8 EERead(uint16 ee_adr, 	unsigned char HWmark[32])
;	-----------------------------------------
;	 function EERead
;	-----------------------------------------
_EERead:
	mov	r6,dpl
	mov	r7,dph
;	eeprom_mark.c:145: I2CS = I2CS_START;
	mov	dptr,#_I2CS
	mov	a,#0x80
	movx	@dptr,a
;	eeprom_mark.c:146: I2DAT = EEPROM_ADR | I2CWRITE;
	mov	dptr,#_I2DAT
	mov	a,#0xA2
	movx	@dptr,a
;	eeprom_mark.c:147: while(!(I2CS & I2CS_DONE));
00101$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jnb	acc.0,00101$
;	eeprom_mark.c:150: if(!(I2CS & I2CS_ACK)) return(1);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jb	acc.1,00105$
	mov	dpl,#0x01
	ret
00105$:
;	eeprom_mark.c:153: I2DAT = (ee_adr>>8);
	mov	dptr,#_I2DAT
	mov	a,r7
	movx	@dptr,a
;	eeprom_mark.c:154: while(!(I2CS & I2CS_DONE));
00106$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jnb	acc.0,00106$
;	eeprom_mark.c:157: if(!(I2CS & I2CS_ACK)) return(2);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r5,a
	jb	acc.1,00110$
	mov	dpl,#0x02
	ret
00110$:
;	eeprom_mark.c:160: I2DAT = (ee_adr & 0xff);
	mov	r7,#0x00
	mov	dptr,#_I2DAT
	mov	a,r6
	movx	@dptr,a
;	eeprom_mark.c:161: while(!(I2CS & I2CS_DONE));
00111$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00111$
;	eeprom_mark.c:164: if(!(I2CS & I2CS_ACK)) return(3);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00115$
	mov	dpl,#0x03
	ret
00115$:
;	eeprom_mark.c:167: I2CS = I2CS_START;
	mov	dptr,#_I2CS
	mov	a,#0x80
	movx	@dptr,a
;	eeprom_mark.c:168: I2DAT = EEPROM_ADR | I2CREAD;
	mov	dptr,#_I2DAT
	mov	a,#0xA3
	movx	@dptr,a
;	eeprom_mark.c:169: while(!(I2CS & I2CS_DONE));
00116$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00116$
;	eeprom_mark.c:172: if(!(I2CS & I2CS_ACK)) return(5);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00120$
	mov	dpl,#0x05
	ret
00120$:
;	eeprom_mark.c:175: HWmark[0] = I2DAT;
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
;	eeprom_mark.c:176: while(!(I2CS & I2CS_DONE));
00121$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jnb	acc.0,00121$
;	eeprom_mark.c:177: if(!(I2CS & I2CS_ACK)) return(6);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jb	acc.1,00126$
	mov	dpl,#0x06
	ret
;	eeprom_mark.c:180: while(!(I2CS & I2CS_DONE));
00126$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jnb	acc.0,00126$
;	eeprom_mark.c:181: if(!(I2CS & I2CS_ACK)) return(7);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jb	acc.1,00130$
	mov	dpl,#0x07
	ret
00130$:
;	eeprom_mark.c:183: HWmark[0] = I2DAT;
	mov	dptr,#_I2DAT
	movx	a,@dptr
	mov	r4,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrput
;	eeprom_mark.c:184: while(!(I2CS & I2CS_DONE));
00131$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jnb	acc.0,00131$
;	eeprom_mark.c:185: if(!(I2CS & I2CS_ACK)) return(8);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jb	acc.1,00135$
	mov	dpl,#0x08
	ret
00135$:
;	eeprom_mark.c:187: HWmark[1] = I2DAT;
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
;	eeprom_mark.c:188: while(!(I2CS & I2CS_DONE));
00136$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jnb	acc.0,00136$
;	eeprom_mark.c:189: if(!(I2CS & I2CS_ACK)) return(8);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jb	acc.1,00193$
	mov	dpl,#0x08
	ret
;	eeprom_mark.c:191: for(n = 2;n<31;n++) {
00193$:
	mov	_EERead_n_1_1,#0x02
	mov	(_EERead_n_1_1 + 1),#0x00
00159$:
	clr	c
	mov	a,_EERead_n_1_1
	subb	a,#0x1F
	mov	a,(_EERead_n_1_1 + 1)
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00162$
;	eeprom_mark.c:192: HWmark[n] = I2DAT;
	mov	a,_EERead_n_1_1
	add	a,r5
	mov	r0,a
	mov	a,(_EERead_n_1_1 + 1)
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
;	eeprom_mark.c:193: while(!(I2CS & I2CS_DONE));
00141$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jnb	acc.0,00141$
;	eeprom_mark.c:194: if(!(I2CS & I2CS_ACK)) return(9);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jb	acc.1,00161$
	mov	dpl,#0x09
	ret
00161$:
;	eeprom_mark.c:191: for(n = 2;n<31;n++) {
	inc	_EERead_n_1_1
	clr	a
	cjne	a,_EERead_n_1_1,00159$
	inc	(_EERead_n_1_1 + 1)
	sjmp	00159$
00162$:
;	eeprom_mark.c:197: I2CS = I2CS_LASTRD;
	mov	dptr,#_I2CS
	mov	a,#0x20
	movx	@dptr,a
;	eeprom_mark.c:198: HWmark[31] = I2DAT;
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
;	eeprom_mark.c:199: while(!(I2CS & I2CS_DONE));
00146$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r4,a
	jnb	acc.0,00146$
;	eeprom_mark.c:200: HWmark[31] = I2DAT;
	mov	dptr,#_I2DAT
	movx	a,@dptr
	mov	r4,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrput
;	eeprom_mark.c:201: while(!(I2CS & I2CS_DONE));
00149$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00149$
;	eeprom_mark.c:202: if(!(I2CS & I2CS_ACK)) return(10);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00153$
	mov	dpl,#0x0A
	ret
00153$:
;	eeprom_mark.c:213: I2CS = I2CS_STOP;
	mov	dptr,#_I2CS
	mov	a,#0x40
	movx	@dptr,a
;	eeprom_mark.c:214: while(!(I2CS & I2CS_DONE));
00154$:
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.0,00154$
;	eeprom_mark.c:216: if(!(I2CS & I2CS_ACK)) return(11);
	mov	dptr,#_I2CS
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00158$
	mov	dpl,#0x0B
	ret
00158$:
;	eeprom_mark.c:218: return(64);
	mov	dpl,#0x40
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'readmarkeeprom'
;------------------------------------------------------------
;n                         Allocated to registers r6 r7 
;------------------------------------------------------------
;	eeprom_mark.c:238: static uint8 readmarkeeprom(void) {
;	-----------------------------------------
;	 function readmarkeeprom
;	-----------------------------------------
_readmarkeeprom:
;	eeprom_mark.c:242: I2CTL = 0x01;	// Set 400kHz:
	mov	dptr,#_I2CTL
	mov	a,#0x01
	movx	@dptr,a
;	eeprom_mark.c:243: SYNCDELAY;
	 nop; 
;	eeprom_mark.c:245: for(n=0;n<128;n++) HWmark[n] = 0x00;
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
;	eeprom_mark.c:246: err[32+3] = EERead( 0x0400,HWmark);
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
;	eeprom_mark.c:247: return(0);
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'writemarkeeprom'
;------------------------------------------------------------
;mark                      Allocated with name '_writemarkeeprom_mark_1_1'
;n                         Allocated to registers r3 r4 
;sloc0                     Allocated with name '_writemarkeeprom_sloc0_1_0'
;sloc1                     Allocated with name '_writemarkeeprom_sloc1_1_0'
;------------------------------------------------------------
;	eeprom_mark.c:251: static uint8 writemarkeeprom(struct mark *mark) {
;	-----------------------------------------
;	 function writemarkeeprom
;	-----------------------------------------
_writemarkeeprom:
	mov	_writemarkeeprom_mark_1_1,dpl
	mov	(_writemarkeeprom_mark_1_1 + 1),dph
	mov	(_writemarkeeprom_mark_1_1 + 2),b
;	eeprom_mark.c:255: I2CTL = 0x01;	// Set 400kHz:
	mov	dptr,#_I2CTL
	mov	a,#0x01
	movx	@dptr,a
;	eeprom_mark.c:256: SYNCDELAY;
	 nop; 
;	eeprom_mark.c:258: for(n=0;n<128;n++) HWmark[n] = 0x00;
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
;	eeprom_mark.c:262: mark->serial_no_high,mark->serial_no_low);
	mov	a,#0x0E
	add	a,_writemarkeeprom_mark_1_1
	mov	r2,a
	clr	a
	addc	a,(_writemarkeeprom_mark_1_1 + 1)
	mov	r3,a
	mov	r4,(_writemarkeeprom_mark_1_1 + 2)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	mov	a,#0x0C
	add	a,_writemarkeeprom_mark_1_1
	mov	r0,a
	clr	a
	addc	a,(_writemarkeeprom_mark_1_1 + 1)
	mov	r1,a
	mov	r4,(_writemarkeeprom_mark_1_1 + 2)
	mov	dpl,r0
	mov	dph,r1
	mov	b,r4
	lcall	__gptrget
	mov	r0,a
	inc	dptr
	lcall	__gptrget
	mov	r1,a
;	eeprom_mark.c:261: mark->type,mark->major_version, mark->minor_version,
	mov	a,#0x0A
	add	a,_writemarkeeprom_mark_1_1
	mov	r4,a
	clr	a
	addc	a,(_writemarkeeprom_mark_1_1 + 1)
	mov	r6,a
	mov	r7,(_writemarkeeprom_mark_1_1 + 2)
	mov	dpl,r4
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	_writemarkeeprom_sloc0_1_0,a
	inc	dptr
	lcall	__gptrget
	mov	(_writemarkeeprom_sloc0_1_0 + 1),a
	mov	a,#0x08
	add	a,_writemarkeeprom_mark_1_1
	mov	r5,a
	clr	a
	addc	a,(_writemarkeeprom_mark_1_1 + 1)
	mov	r6,a
	mov	r7,(_writemarkeeprom_mark_1_1 + 2)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	_writemarkeeprom_sloc1_1_0,a
	inc	dptr
	lcall	__gptrget
	mov	(_writemarkeeprom_sloc1_1_0 + 1),a
;	eeprom_mark.c:260: sprintf(HWmark,"HW%sv%03x.%03xs%04x.%04x",
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
	push	_writemarkeeprom_mark_1_1
	push	(_writemarkeeprom_mark_1_1 + 1)
	push	(_writemarkeeprom_mark_1_1 + 2)
	mov	a,#__str_0
	push	acc
	mov	a,#(__str_0 >> 8)
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
;	eeprom_mark.c:263: for(n=0;n<32;n++) err[n+2] = EEWrite(0x0400+n,0x00);
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
	mov	ar2,r6
	mov	a,#0x04
	add	a,r7
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
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
;	eeprom_mark.c:264: for(n=0;n<32;n++) err[n+2] = EEWrite(0x0400+n,HWmark[n]);
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
;	eeprom_mark.c:266: return(0);
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;n                         Allocated to registers r6 r7 
;eeprom_mark_adr           Allocated to registers 
;adr                       Allocated to registers 
;mark                      Allocated with name '_main_mark_1_1'
;------------------------------------------------------------
;	eeprom_mark.c:269: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	eeprom_mark.c:276: err = (xdata unsigned char *) 0x1200;	
	mov	_err,#0x00
	mov	(_err + 1),#0x12
;	eeprom_mark.c:287: strcpy(mark.type,"TEST");
	mov	_strcpy_PARM_2,#__str_1
	mov	(_strcpy_PARM_2 + 1),#(__str_1 >> 8)
	mov	(_strcpy_PARM_2 + 2),#0x80
	mov	dptr,#_main_mark_1_1
	mov	b,#0x40
	lcall	_strcpy
;	eeprom_mark.c:288: strcpy(mark.type,"ADC_");
	mov	_strcpy_PARM_2,#__str_2
	mov	(_strcpy_PARM_2 + 1),#(__str_2 >> 8)
	mov	(_strcpy_PARM_2 + 2),#0x80
	mov	dptr,#_main_mark_1_1
	mov	b,#0x40
	lcall	_strcpy
;	eeprom_mark.c:290: mark.major_version = 0x0;
	clr	a
	mov	((_main_mark_1_1 + 0x0008) + 0),a
	mov	((_main_mark_1_1 + 0x0008) + 1),a
;	eeprom_mark.c:291: mark.minor_version = 0x1;
	mov	((_main_mark_1_1 + 0x000a) + 0),#0x01
;	eeprom_mark.c:293: mark.serial_no_high = 0x0;
	clr	a
	mov	((_main_mark_1_1 + 0x000a) + 1),a
	mov	((_main_mark_1_1 + 0x000c) + 0),a
	mov	((_main_mark_1_1 + 0x000c) + 1),a
;	eeprom_mark.c:294: mark.serial_no_low  = 0x1;
	mov	((_main_mark_1_1 + 0x000e) + 0),#0x01
	mov	((_main_mark_1_1 + 0x000e) + 1),#0x00
;	eeprom_mark.c:298: for(n = 0;n < 200;n++);
	mov	r6,#0xC8
	mov	r7,#0x00
00103$:
	dec	r6
	cjne	r6,#0xFF,00120$
	dec	r7
00120$:
	mov	a,r6
	orl	a,r7
	jnz	00103$
;	eeprom_mark.c:299: readmarkeeprom();
	lcall	_readmarkeeprom
;	eeprom_mark.c:300: for(n=0;n<32;n++) dat[n] = (xdata char)HWmark[n];
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
;	eeprom_mark.c:302: hostreadmarkep1init();
	lcall	_hostreadmarkep1init
00109$:
;	eeprom_mark.c:303: for(;;) hostreadmarkep1poll();	
	lcall	_hostreadmarkep1poll
	sjmp	00109$
;------------------------------------------------------------
;Allocation info for local variables in function 'hostreadmarkep1init'
;------------------------------------------------------------
;	eeprom_mark.c:308: static uint8 hostreadmarkep1init(void) {
;	-----------------------------------------
;	 function hostreadmarkep1init
;	-----------------------------------------
_hostreadmarkep1init:
;	eeprom_mark.c:310: EP1OUTCFG=0xa0;
	mov	dptr,#_EP1OUTCFG
	mov	a,#0xA0
	movx	@dptr,a
;	eeprom_mark.c:311: EP1INCFG=0xa0;
	mov	dptr,#_EP1INCFG
	mov	a,#0xA0
	movx	@dptr,a
;	eeprom_mark.c:313: SYNCDELAY;
	 nop; 
;	eeprom_mark.c:314: EP1OUTBC=0xff; // Arm endpoint 1 for OUT (host->device) transfers
	mov	dptr,#_EP1OUTBC
	mov	a,#0xFF
	movx	@dptr,a
;	eeprom_mark.c:316: return(0);
	mov	dpl,#0x00
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'hostreadmarkep1poll'
;------------------------------------------------------------
;src                       Allocated to registers 
;dest                      Allocated to registers r5 r6 
;ep1outbc                  Allocated with name '_hostreadmarkep1poll_ep1outbc_1_1'
;n                         Allocated with name '_hostreadmarkep1poll_n_1_1'
;------------------------------------------------------------
;	eeprom_mark.c:319: static uint8 hostreadmarkep1poll(void) {
;	-----------------------------------------
;	 function hostreadmarkep1poll
;	-----------------------------------------
_hostreadmarkep1poll:
;	eeprom_mark.c:325: if(!(EP1OUTCS & bmEPBUSY)) {
	mov	dptr,#_EP1OUTCS
	movx	a,@dptr
	mov	r7,a
	jnb	acc.1,00153$
	ljmp	00114$
00153$:
;	eeprom_mark.c:326: ep1outbc = EP1OUTBC;
	mov	dptr,#_EP1OUTBC
	movx	a,@dptr
	mov	_hostreadmarkep1poll_ep1outbc_1_1,a
;	eeprom_mark.c:327: if(ep1outbc != 0xff ) {
	mov	a,#0xFF
	cjne	a,_hostreadmarkep1poll_ep1outbc_1_1,00154$
	ljmp	00114$
00154$:
;	eeprom_mark.c:328: src = EP1OUTBUF;
;	eeprom_mark.c:329: dest = EP1INBUF;
	mov	r5,#_EP1INBUF
	mov	r6,#(_EP1INBUF >> 8)
;	eeprom_mark.c:330: while (EP1INCS & 0x02);
00101$:
	mov	dptr,#_EP1INCS
	movx	a,@dptr
	mov	r4,a
	jb	acc.1,00101$
;	eeprom_mark.c:331: for(n=0; n<32; n++) command[n] = src[n];
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
;	eeprom_mark.c:332: for( n=0; n < ep1outbc ; n++ ) { 
	mov	ar3,r5
	mov	ar4,r6
	mov	r1,#0x00
	mov	r2,#0x00
00119$:
	mov	r0,_hostreadmarkep1poll_ep1outbc_1_1
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
;	eeprom_mark.c:333: *dest++ = command[n];
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
;	eeprom_mark.c:332: for( n=0; n < ep1outbc ; n++ ) { 
	inc	r1
	cjne	r1,#0x00,00119$
	inc	r2
	sjmp	00119$
00122$:
;	eeprom_mark.c:335: *err++ = 0x5a;
	mov	dpl,_err
	mov	dph,(_err + 1)
	mov	a,#0x5A
	movx	@dptr,a
	inc	_err
	clr	a
	cjne	a,_err,00160$
	inc	(_err + 1)
00160$:
;	eeprom_mark.c:336: EP1INBC = ep1outbc;
	mov	dptr,#_EP1INBC
	mov	a,_hostreadmarkep1poll_ep1outbc_1_1
	movx	@dptr,a
;	eeprom_mark.c:337: while (EP1INCS & 0x02);
00104$:
	mov	dptr,#_EP1INCS
	movx	a,@dptr
	mov	r7,a
	jb	acc.1,00104$
;	eeprom_mark.c:338: dest = EP1INBUF;
	mov	r5,#_EP1INBUF
	mov	r6,#(_EP1INBUF >> 8)
;	eeprom_mark.c:339: if(!strncmp(command,"getHW",5)) {
	mov	r3,_command
	mov	r4,(_command + 1)
	mov	r7,#0x00
	mov	_strncmp_PARM_2,#__str_3
	mov	(_strncmp_PARM_2 + 1),#(__str_3 >> 8)
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
;	eeprom_mark.c:340: for( n=0; HWmark[n] != '\0' ; n++ )  
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
;	eeprom_mark.c:341: *dest++ = (xdata unsigned char) HWmark[n];					
	mov	dpl,r4
	mov	dph,r7
	mov	a,r1
	movx	@dptr,a
	inc	dptr
	mov	r4,dpl
	mov	r7,dph
;	eeprom_mark.c:340: for( n=0; HWmark[n] != '\0' ; n++ )  
	inc	r2
	cjne	r2,#0x00,00123$
	inc	r3
	sjmp	00123$
00126$:
;	eeprom_mark.c:342: *dest++ = '\0';
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
;	eeprom_mark.c:343: n++;
	mov	a,#0x01
	add	a,r2
	mov	r4,a
	clr	a
	addc	a,r3
	mov	r7,a
;	eeprom_mark.c:344: EP1INBC = n;
	mov	dptr,#_EP1INBC
	mov	a,r4
	movx	@dptr,a
;	eeprom_mark.c:345: SYNCDELAY;
	 nop; 
00108$:
;	eeprom_mark.c:347: if(!strncmp(command,"getFW",5)) {
	mov	r1,_command
	mov	r2,(_command + 1)
	mov	r3,#0x00
	mov	_strncmp_PARM_2,#__str_4
	mov	(_strncmp_PARM_2 + 1),#(__str_4 >> 8)
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
;	eeprom_mark.c:348: for( n=0; FWmark[n] != '\0' ; n++ )  
	jnz	00110$
	mov	_hostreadmarkep1poll_n_1_1,a
	mov	(_hostreadmarkep1poll_n_1_1 + 1),a
00127$:
	mov	a,_hostreadmarkep1poll_n_1_1
	add	a,_FWmark
	mov	r0,a
	mov	a,(_hostreadmarkep1poll_n_1_1 + 1)
	addc	a,(_FWmark + 1)
	mov	r1,a
	mov	r3,(_FWmark + 2)
	mov	dpl,r0
	mov	dph,r1
	mov	b,r3
	lcall	__gptrget
	mov	r3,a
	jz	00130$
;	eeprom_mark.c:349: *dest++ = (xdata unsigned char) FWmark[n];					
	mov	dpl,r5
	mov	dph,r6
	mov	a,r3
	movx	@dptr,a
	inc	dptr
	mov	r5,dpl
	mov	r6,dph
;	eeprom_mark.c:348: for( n=0; FWmark[n] != '\0' ; n++ )  
	inc	_hostreadmarkep1poll_n_1_1
	clr	a
	cjne	a,_hostreadmarkep1poll_n_1_1,00127$
	inc	(_hostreadmarkep1poll_n_1_1 + 1)
	sjmp	00127$
00130$:
;	eeprom_mark.c:350: *dest++ = '\0';
	mov	dpl,r5
	mov	dph,r6
	clr	a
	movx	@dptr,a
;	eeprom_mark.c:351: n++;
	mov	a,#0x01
	add	a,_hostreadmarkep1poll_n_1_1
	mov	r4,a
	clr	a
	addc	a,(_hostreadmarkep1poll_n_1_1 + 1)
	mov	r7,a
;	eeprom_mark.c:352: EP1INBC = n;
	mov	dptr,#_EP1INBC
	mov	a,r4
	movx	@dptr,a
;	eeprom_mark.c:353: SYNCDELAY;
	 nop; 
00110$:
;	eeprom_mark.c:355: EP1OUTBC = 0xff;
	mov	dptr,#_EP1OUTBC
	mov	a,#0xFF
	movx	@dptr,a
00114$:
;	eeprom_mark.c:358: return(0);
	mov	dpl,#0x00
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
__str_0:
	.ascii "HW%sv%03x.%03xs%04x.%04x"
	.db 0x00
__str_1:
	.ascii "TEST"
	.db 0x00
__str_2:
	.ascii "ADC_"
	.db 0x00
__str_3:
	.ascii "getHW"
	.db 0x00
__str_4:
	.ascii "getFW"
	.db 0x00
__str_5:
	.ascii "FWEEPRv000.001"
	.db 0x00
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
