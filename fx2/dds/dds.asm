;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
; This file was generated Sun Oct 26 13:42:35 2014
;--------------------------------------------------------
	.module dds
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
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
	.globl _dat
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
_dat::
	.ds 2
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
_ProcessSendData_len_1_1:
	.ds 2
_ProcessSendData_i_1_1:
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
;	dds.c:24: xdata unsigned char *dat = (xdata unsigned char) 0xE000;
	clr	a
	mov	_dat,a
	mov	(_dat + 1),a
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
;Allocation info for local variables in function 'Initialize'
;------------------------------------------------------------
;n                         Allocated to registers r6 r7 
;------------------------------------------------------------
;	dds.c:26: static void Initialize(void)
;	-----------------------------------------
;	 function Initialize
;	-----------------------------------------
_Initialize:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	dds.c:29: CPUCS=0x10;   // 48 MHz, CLKOUT output disabled. 
	mov	dptr,#_CPUCS
	mov	a,#0x10
	movx	@dptr,a
;	dds.c:50: IFCONFIG=0x43;  // External IFCLK, 48MHz; slave FIFO. 
	mov	dptr,#_IFCONFIG
	mov	a,#0x43
	movx	@dptr,a
;	dds.c:51: SYNCDELAY;
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:53: IFCONFIG=0xC0;  // External IFCLK, 48MHz; slave FIFO. 
	mov	dptr,#_IFCONFIG
	mov	a,#0xC0
	movx	@dptr,a
;	dds.c:54: SYNCDELAY;
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:80: FIFOPINPOLAR=0x00;
	mov	dptr,#_FIFOPINPOLAR
	clr	a
	movx	@dptr,a
;	dds.c:81: SYNCDELAY;
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:83: FIFOPINPOLAR=0x0c;
	mov	dptr,#_FIFOPINPOLAR
	mov	a,#0x0C
	movx	@dptr,a
;	dds.c:84: SYNCDELAY;
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:87: REVCTL=0x03;  // See TRM...
	mov	dptr,#_REVCTL
	mov	a,#0x03
	movx	@dptr,a
;	dds.c:88: SYNCDELAY;
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:90: EP6CFG=0xe2;  // 1110 0010 (bulk IN, 512 bytes, double-buffered)
	mov	dptr,#_EP6CFG
	mov	a,#0xE2
	movx	@dptr,a
;	dds.c:91: SYNCDELAY;
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:93: EP2CFG=0xa2;  // 1010 0010 (bulk OUT, 512 bytes, double-buffered)
	mov	dptr,#_EP2CFG
	mov	a,#0xA2
	movx	@dptr,a
;	dds.c:94: SYNCDELAY;
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:96: FIFORESET = 0x80;  SYNCDELAY;  // NAK all requests from host. 
	mov	dptr,#_FIFORESET
	mov	a,#0x80
	movx	@dptr,a
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:97: FIFORESET = 0x82;  SYNCDELAY;  // Reset individual EP (2,4,6,8)
	mov	dptr,#_FIFORESET
	mov	a,#0x82
	movx	@dptr,a
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:98: FIFORESET = 0x84;  SYNCDELAY;
	mov	dptr,#_FIFORESET
	mov	a,#0x84
	movx	@dptr,a
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:99: FIFORESET = 0x86;  SYNCDELAY;
	mov	dptr,#_FIFORESET
	mov	a,#0x86
	movx	@dptr,a
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:100: FIFORESET = 0x88;  SYNCDELAY;
	mov	dptr,#_FIFORESET
	mov	a,#0x88
	movx	@dptr,a
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:101: FIFORESET = 0x00;  SYNCDELAY;  // Resume normal operation. 
	mov	dptr,#_FIFORESET
	clr	a
	movx	@dptr,a
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:103: EP2FIFOCFG = 0x00;  // Make sure AUTOOUT=0. 
	mov	dptr,#_EP2FIFOCFG
	clr	a
	movx	@dptr,a
;	dds.c:104: SYNCDELAY;
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:109: OUTPKTEND = 0x82;  SYNCDELAY;
	mov	dptr,#_OUTPKTEND
	mov	a,#0x82
	movx	@dptr,a
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:110: OUTPKTEND = 0x82;  SYNCDELAY;
	mov	dptr,#_OUTPKTEND
	mov	a,#0x82
	movx	@dptr,a
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:114: PORTACFG = 0x00;
	mov	dptr,#_PORTACFG
	clr	a
	movx	@dptr,a
;	dds.c:115: SYNCDELAY; // maybe not needed
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
;	dds.c:118: OEA = 0x00;
	mov	_OEA,#0x00
;	dds.c:119: OEB = 0x00;
	mov	_OEB,#0x00
;	dds.c:120: OEC = 0x00;
	mov	_OEC,#0x00
;	dds.c:121: OED = 0x00;
	mov	_OED,#0x00
;	dds.c:123: OED = 0x0F;
	mov	_OED,#0x0F
;	dds.c:125: for(n = 0; n < 100;n++) dat[n] = 0;
	mov	r6,#0x00
	mov	r7,#0x00
00101$:
	clr	c
	mov	a,r6
	subb	a,#0x64
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00105$
	mov	a,r6
	add	a,_dat
	mov	dpl,a
	mov	a,r7
	addc	a,(_dat + 1)
	mov	dph,a
	clr	a
	movx	@dptr,a
	inc	r6
	cjne	r6,#0x00,00101$
	inc	r7
	sjmp	00101$
00105$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ProcessSendData'
;------------------------------------------------------------
;src                       Allocated to registers 
;dest                      Allocated to registers 
;len                       Allocated with name '_ProcessSendData_len_1_1'
;i                         Allocated with name '_ProcessSendData_i_1_1'
;------------------------------------------------------------
;	dds.c:130: static void ProcessSendData(void)
;	-----------------------------------------
;	 function ProcessSendData
;	-----------------------------------------
_ProcessSendData:
;	dds.c:132: xdata const unsigned char *src=EP2FIFOBUF;
;	dds.c:133: xdata unsigned char *dest=EP6FIFOBUF;
;	dds.c:134: unsigned int len = (((int)EP2BCH)<<8 | EP2BCL);
	mov	dptr,#_EP2BCH
	movx	a,@dptr
	mov	r6,a
	mov	r7,#0x00
	mov	dptr,#_EP2BCL
	movx	a,@dptr
	mov	r5,a
	mov	r4,#0x00
	orl	ar7,a
	mov	a,r4
	orl	ar6,a
	mov	_ProcessSendData_len_1_1,r7
	mov	(_ProcessSendData_len_1_1 + 1),r6
;	dds.c:136: for(i=0; i<len; i++,src++,dest++)
	clr	a
	mov	_ProcessSendData_i_1_1,a
	mov	(_ProcessSendData_i_1_1 + 1),a
	mov	r2,#_EP2FIFOBUF
	mov	r3,#(_EP2FIFOBUF >> 8)
	mov	r0,#_EP6FIFOBUF
	mov	r1,#(_EP6FIFOBUF >> 8)
00101$:
	clr	c
	mov	a,_ProcessSendData_i_1_1
	subb	a,_ProcessSendData_len_1_1
	mov	a,(_ProcessSendData_i_1_1 + 1)
	subb	a,(_ProcessSendData_len_1_1 + 1)
	jnc	00104$
;	dds.c:139: dat[i]=*src;
	mov	a,_ProcessSendData_i_1_1
	add	a,_dat
	mov	r6,a
	mov	a,(_ProcessSendData_i_1_1 + 1)
	addc	a,(_dat + 1)
	mov	r7,a
	mov	dpl,r2
	mov	dph,r3
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	mov	r2,dpl
	mov	r3,dph
	mov	dpl,r6
	mov	dph,r7
	mov	a,r5
	movx	@dptr,a
;	dds.c:140: *dest = dat[i];
	mov	dpl,r0
	mov	dph,r1
	mov	a,r5
	movx	@dptr,a
	inc	dptr
	mov	r0,dpl
	mov	r1,dph
;	dds.c:136: for(i=0; i<len; i++,src++,dest++)
	inc	_ProcessSendData_i_1_1
	clr	a
	cjne	a,_ProcessSendData_i_1_1,00101$
	inc	(_ProcessSendData_i_1_1 + 1)
	sjmp	00101$
00104$:
;	dds.c:144: SYNCDELAY;  OUTPKTEND=0x82;
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	mov	dptr,#_OUTPKTEND
	mov	a,#0x82
	movx	@dptr,a
;	dds.c:150: SYNCDELAY;  EP6BCH=len>>8;
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	mov	dptr,#_EP6BCH
	mov	a,(_ProcessSendData_len_1_1 + 1)
	movx	@dptr,a
;	dds.c:151: SYNCDELAY;  EP6BCL=len&0xff;
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	 nop 
	mov	r6,_ProcessSendData_len_1_1
	mov	dptr,#_EP6BCL
	mov	a,r6
	movx	@dptr,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;n                         Allocated to registers r6 r7 
;fu_udH                    Allocated to registers 
;fu_udHC                   Allocated to registers 
;fu_udL                    Allocated to registers 
;dataH                     Allocated to registers 
;dataL                     Allocated to registers 
;resetH                    Allocated to registers 
;resetL                    Allocated to registers 
;triggerH                  Allocated to registers 
;triggerL                  Allocated to registers 
;------------------------------------------------------------
;	dds.c:154: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	dds.c:160: Initialize();
	lcall	_Initialize
;	dds.c:163: IOD = resetL;
	mov	_IOD,#0x00
;	dds.c:164: for(n = 0; n < 0xFFF; n ++ ) {
	mov	r6,#0x00
	mov	r7,#0x00
00106$:
	clr	c
	mov	a,r6
	subb	a,#0xFF
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x8f
	jnc	00109$
;	dds.c:165: IOD = resetH; }
	mov	_IOD,#0x08
;	dds.c:164: for(n = 0; n < 0xFFF; n ++ ) {
	inc	r6
	cjne	r6,#0x00,00106$
	inc	r7
	sjmp	00106$
00109$:
;	dds.c:166: IOD = resetL;
	mov	_IOD,#0x00
00123$:
;	dds.c:171: if(!(EP2CS & (1<<2)))
	mov	dptr,#_EP2CS
	movx	a,@dptr
	mov	r7,a
	jb	acc.2,00132$
;	dds.c:175: while(EP6CS & (1<<3));
00101$:
	mov	dptr,#_EP6CS
	movx	a,@dptr
	mov	r7,a
	jb	acc.3,00101$
;	dds.c:176: ProcessSendData();
	lcall	_ProcessSendData
;	dds.c:180: for(n = 0; n < 80; n ++ ) {
00132$:
	mov	r6,#0x00
	mov	r7,#0x00
00110$:
	clr	c
	mov	a,r6
	subb	a,#0x50
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00113$
;	dds.c:181: IOD = dat[n];
	mov	a,r6
	add	a,_dat
	mov	dpl,a
	mov	a,r7
	addc	a,(_dat + 1)
	mov	dph,a
	movx	a,@dptr
	mov	r5,a
	mov	_IOD,r5
;	dds.c:182: IOD = dat[n];
	mov	_IOD,r5
;	dds.c:180: for(n = 0; n < 80; n ++ ) {
	inc	r6
	cjne	r6,#0x00,00110$
	inc	r7
	sjmp	00110$
00113$:
;	dds.c:186: IOD = fu_udL;
	mov	_IOD,#0x00
;	dds.c:187: for(n = 0; n < 0xF; n ++ ) {
	mov	r6,#0x00
	mov	r7,#0x00
00114$:
	clr	c
	mov	a,r6
	subb	a,#0x0F
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00117$
;	dds.c:188: IOD = fu_udH; }
	mov	_IOD,#0x02
;	dds.c:187: for(n = 0; n < 0xF; n ++ ) {
	inc	r6
	cjne	r6,#0x00,00114$
	inc	r7
	sjmp	00114$
00117$:
;	dds.c:189: for(n = 0; n < 0xF; n ++ ) {
	mov	r6,#0x00
	mov	r7,#0x00
00118$:
	clr	c
	mov	a,r6
	subb	a,#0x0F
	mov	a,r7
	xrl	a,#0x80
	subb	a,#0x80
	jnc	00121$
;	dds.c:190: IOD = fu_udHC; }
	mov	_IOD,#0x03
;	dds.c:189: for(n = 0; n < 0xF; n ++ ) {
	inc	r6
	cjne	r6,#0x00,00118$
	inc	r7
	sjmp	00118$
00121$:
;	dds.c:191: IOD = fu_udL;
	mov	_IOD,#0x00
	sjmp	00123$
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
