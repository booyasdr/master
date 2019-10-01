                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.2.0 #8008 (Jul  6 2012) (MINGW32)
                              4 ; This file was generated Tue Apr 21 19:48:53 2015
                              5 ;--------------------------------------------------------
                              6 	.module convert_serial2
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _EPCS_Offset_Lookup_Table
                             13 	.globl _main
                             14 	.globl _EIP
                             15 	.globl _B
                             16 	.globl _EIE
                             17 	.globl _ACC
                             18 	.globl _EICON
                             19 	.globl _PSW
                             20 	.globl _TH2
                             21 	.globl _TL2
                             22 	.globl _RCAP2H
                             23 	.globl _RCAP2L
                             24 	.globl _T2CON
                             25 	.globl _SBUF1
                             26 	.globl _SCON1
                             27 	.globl _GPIFSGLDATLNOX
                             28 	.globl _GPIFSGLDATLX
                             29 	.globl _GPIFSGLDATH
                             30 	.globl _GPIFTRIG
                             31 	.globl _EP01STAT
                             32 	.globl _IP
                             33 	.globl _OEE
                             34 	.globl _OED
                             35 	.globl _OEC
                             36 	.globl _OEB
                             37 	.globl _OEA
                             38 	.globl _IOE
                             39 	.globl _IOD
                             40 	.globl _AUTOPTRSETUP
                             41 	.globl _EP68FIFOFLGS
                             42 	.globl _EP24FIFOFLGS
                             43 	.globl _EP2468STAT
                             44 	.globl _IE
                             45 	.globl _INT4CLR
                             46 	.globl _INT2CLR
                             47 	.globl _IOC
                             48 	.globl _AUTODAT2
                             49 	.globl _AUTOPTRL2
                             50 	.globl _AUTOPTRH2
                             51 	.globl _AUTODAT1
                             52 	.globl _APTR1L
                             53 	.globl _APTR1H
                             54 	.globl _SBU
                             55 	.globl _SCO
                             56 	.globl _MPA
                             57 	.globl _EXIF
                             58 	.globl _IOB
                             59 	.globl _SPC_
                             60 	.globl _CKCO
                             61 	.globl _TH1
                             62 	.globl _TH0
                             63 	.globl _TL1
                             64 	.globl _TL0
                             65 	.globl _TMOD
                             66 	.globl _TCON
                             67 	.globl _PCON
                             68 	.globl _DPS
                             69 	.globl _DPH1
                             70 	.globl _DPL1
                             71 	.globl _DPH
                             72 	.globl _DPL
                             73 	.globl _SP
                             74 	.globl _IOA
                             75 	.globl _myOutEndpntDscr
                             76 	.globl _myInEndpntDscr
                             77 	.globl _myIntrfcDscr
                             78 	.globl _myConfigDscr
                             79 	.globl _myDeviceQualDscr
                             80 	.globl _myDeviceDscr
                             81 	.globl _EP8FIFOBUF
                             82 	.globl _EP6FIFOBUF
                             83 	.globl _EP4FIFOBUF
                             84 	.globl _EP2FIFOBUF
                             85 	.globl _EP1INBUF
                             86 	.globl _EP1OUTBUF
                             87 	.globl _EP0BUF
                             88 	.globl _CT4
                             89 	.globl _CT3
                             90 	.globl _CT2
                             91 	.globl _CT1
                             92 	.globl _USBTEST
                             93 	.globl _TESTCFG
                             94 	.globl _DBUG
                             95 	.globl _UDMACRCQUAL
                             96 	.globl _UDMACRCL
                             97 	.globl _UDMACRCH
                             98 	.globl _GPIFHOLDAMOUNT
                             99 	.globl _FLOWSTBHPERIOD
                            100 	.globl _FLOWSTBEDGE
                            101 	.globl _FLOWSTB
                            102 	.globl _FLOWHOLDOFF
                            103 	.globl _FLOWEQ1CTL
                            104 	.globl _FLOWEQ0CTL
                            105 	.globl _FLOWLOGIC
                            106 	.globl _FLOWSTATE
                            107 	.globl _GPIFABORT
                            108 	.globl _GPIFREADYSTAT
                            109 	.globl _GPIFREADYCFG
                            110 	.globl _XGPIFSGLDATLNOX
                            111 	.globl _XGPIFSGLDATLX
                            112 	.globl _XGPIFSGLDATH
                            113 	.globl _EP8GPIFTRIG
                            114 	.globl _EP8GPIFPFSTOP
                            115 	.globl _EP8GPIFFLGSEL
                            116 	.globl _EP6GPIFTRIG
                            117 	.globl _EP6GPIFPFSTOP
                            118 	.globl _EP6GPIFFLGSEL
                            119 	.globl _EP4GPIFTRIG
                            120 	.globl _EP4GPIFPFSTOP
                            121 	.globl _EP4GPIFFLGSEL
                            122 	.globl _EP2GPIFTRIG
                            123 	.globl _EP2GPIFPFSTOP
                            124 	.globl _EP2GPIFFLGSEL
                            125 	.globl _GPIFTCB0
                            126 	.globl _GPIFTCB1
                            127 	.globl _GPIFTCB2
                            128 	.globl _GPIFTCB3
                            129 	.globl _GPIFADRL
                            130 	.globl _GPIFADRH
                            131 	.globl _GPIFCTLCFG
                            132 	.globl _GPIFIDLECTL
                            133 	.globl _GPIFIDLECS
                            134 	.globl _GPIFWFSELECT
                            135 	.globl _SETUPDAT
                            136 	.globl _SUDPTRCTL
                            137 	.globl _SUDPTRL
                            138 	.globl _SUDPTRH
                            139 	.globl _EP8FIFOBCL
                            140 	.globl _EP8FIFOBCH
                            141 	.globl _EP6FIFOBCL
                            142 	.globl _EP6FIFOBCH
                            143 	.globl _EP4FIFOBCL
                            144 	.globl _EP4FIFOBCH
                            145 	.globl _EP2FIFOBCL
                            146 	.globl _EP2FIFOBCH
                            147 	.globl _EP8FIFOFLGS
                            148 	.globl _EP6FIFOFLGS
                            149 	.globl _EP4FIFOFLGS
                            150 	.globl _EP2FIFOFLGS
                            151 	.globl _EP8CS
                            152 	.globl _EP6CS
                            153 	.globl _EP4CS
                            154 	.globl _EP2CS
                            155 	.globl _EP1INCS
                            156 	.globl _EP1OUTCS
                            157 	.globl _EP0CS
                            158 	.globl _EP8BCL
                            159 	.globl _EP8BCH
                            160 	.globl _EP6BCL
                            161 	.globl _EP6BCH
                            162 	.globl _EP4BCL
                            163 	.globl _EP4BCH
                            164 	.globl _EP2BCL
                            165 	.globl _EP2BCH
                            166 	.globl _EP1INBC
                            167 	.globl _EP1OUTBC
                            168 	.globl _EP0BCL
                            169 	.globl _EP0BCH
                            170 	.globl _FNADDR
                            171 	.globl _MICROFRAME
                            172 	.globl _USBFRAMEL
                            173 	.globl _USBFRAMEH
                            174 	.globl _TOGCTL
                            175 	.globl _WAKEUPCS
                            176 	.globl _SUSPEND
                            177 	.globl _USBCS
                            178 	.globl _XAUTODAT2
                            179 	.globl _XAUTODAT1
                            180 	.globl _I2CTL
                            181 	.globl _I2DAT
                            182 	.globl _I2CS
                            183 	.globl _PORTECFG
                            184 	.globl _PORTCCFG
                            185 	.globl _PORTACFG
                            186 	.globl _INTSETUP
                            187 	.globl _INT4IVEC
                            188 	.globl _INT2IVEC
                            189 	.globl _CLRERRCNT
                            190 	.globl _ERRCNTLIM
                            191 	.globl _USBERRIRQ
                            192 	.globl _USBERRIE
                            193 	.globl _GPIFIRQ
                            194 	.globl _GPIFIE
                            195 	.globl _EPIRQ
                            196 	.globl _EPIE
                            197 	.globl _USBIRQ
                            198 	.globl _USBIE
                            199 	.globl _NAKIRQ
                            200 	.globl _NAKIE
                            201 	.globl _IBNIRQ
                            202 	.globl _IBNIE
                            203 	.globl _EP8FIFOIRQ
                            204 	.globl _EP8FIFOIE
                            205 	.globl _EP6FIFOIRQ
                            206 	.globl _EP6FIFOIE
                            207 	.globl _EP4FIFOIRQ
                            208 	.globl _EP4FIFOIE
                            209 	.globl _EP2FIFOIRQ
                            210 	.globl _EP2FIFOIE
                            211 	.globl _OUTPKTEND
                            212 	.globl _INPKTEND
                            213 	.globl _EP8ISOINPKTS
                            214 	.globl _EP6ISOINPKTS
                            215 	.globl _EP4ISOINPKTS
                            216 	.globl _EP2ISOINPKTS
                            217 	.globl _EP8FIFOPFL
                            218 	.globl _EP8FIFOPFH
                            219 	.globl _EP6FIFOPFL
                            220 	.globl _EP6FIFOPFH
                            221 	.globl _EP4FIFOPFL
                            222 	.globl _EP4FIFOPFH
                            223 	.globl _EP2FIFOPFL
                            224 	.globl _EP2FIFOPFH
                            225 	.globl _EP8AUTOINLENL
                            226 	.globl _EP8AUTOINLENH
                            227 	.globl _EP6AUTOINLENL
                            228 	.globl _EP6AUTOINLENH
                            229 	.globl _EP4AUTOINLENL
                            230 	.globl _EP4AUTOINLENH
                            231 	.globl _EP2AUTOINLENL
                            232 	.globl _EP2AUTOINLENH
                            233 	.globl _EP8FIFOCFG
                            234 	.globl _EP6FIFOCFG
                            235 	.globl _EP4FIFOCFG
                            236 	.globl _EP2FIFOCFG
                            237 	.globl _EP8CFG
                            238 	.globl _EP6CFG
                            239 	.globl _EP4CFG
                            240 	.globl _EP2CFG
                            241 	.globl _EP1INCFG
                            242 	.globl _EP1OUTCFG
                            243 	.globl _REVCTL
                            244 	.globl _REVID
                            245 	.globl _FIFOPINPOLAR
                            246 	.globl _UART230
                            247 	.globl _BPADDRL
                            248 	.globl _BPADDRH
                            249 	.globl _BREAKPT
                            250 	.globl _FIFORESET
                            251 	.globl _PINFLAGSCD
                            252 	.globl _PINFLAGSAB
                            253 	.globl _IFCONFIG
                            254 	.globl _CPUCS
                            255 	.globl _RES_WAVEDATA_END
                            256 	.globl _GPIF_WAVE_DATA
                            257 	.globl _Selfpwr
                            258 	.globl _Rwuen
                            259 	.globl _Rwuen_allowed
                            260 	.globl _latency_us
                            261 	.globl _bytes_waiting_for_xmit
                            262 	.globl _USB_strings
                            263 	.globl _InterfaceSetting
                            264 	.globl _Configuration
                            265 ;--------------------------------------------------------
                            266 ; special function registers
                            267 ;--------------------------------------------------------
                            268 	.area RSEG    (ABS,DATA)
   0000                     269 	.org 0x0000
                    0080    270 _IOA	=	0x0080
                    0081    271 _SP	=	0x0081
                    0082    272 _DPL	=	0x0082
                    0083    273 _DPH	=	0x0083
                    0084    274 _DPL1	=	0x0084
                    0085    275 _DPH1	=	0x0085
                    0086    276 _DPS	=	0x0086
                    0087    277 _PCON	=	0x0087
                    0088    278 _TCON	=	0x0088
                    0089    279 _TMOD	=	0x0089
                    008A    280 _TL0	=	0x008a
                    008B    281 _TL1	=	0x008b
                    008C    282 _TH0	=	0x008c
                    008D    283 _TH1	=	0x008d
                    008E    284 _CKCO	=	0x008e
                    008F    285 _SPC_	=	0x008f
                    0090    286 _IOB	=	0x0090
                    0091    287 _EXIF	=	0x0091
                    0092    288 _MPA	=	0x0092
                    0098    289 _SCO	=	0x0098
                    0099    290 _SBU	=	0x0099
                    009A    291 _APTR1H	=	0x009a
                    009B    292 _APTR1L	=	0x009b
                    009C    293 _AUTODAT1	=	0x009c
                    009D    294 _AUTOPTRH2	=	0x009d
                    009E    295 _AUTOPTRL2	=	0x009e
                    009F    296 _AUTODAT2	=	0x009f
                    00A0    297 _IOC	=	0x00a0
                    00A1    298 _INT2CLR	=	0x00a1
                    00A2    299 _INT4CLR	=	0x00a2
                    00A8    300 _IE	=	0x00a8
                    00AA    301 _EP2468STAT	=	0x00aa
                    00AB    302 _EP24FIFOFLGS	=	0x00ab
                    00AC    303 _EP68FIFOFLGS	=	0x00ac
                    00AF    304 _AUTOPTRSETUP	=	0x00af
                    00B0    305 _IOD	=	0x00b0
                    00B1    306 _IOE	=	0x00b1
                    00B2    307 _OEA	=	0x00b2
                    00B3    308 _OEB	=	0x00b3
                    00B4    309 _OEC	=	0x00b4
                    00B5    310 _OED	=	0x00b5
                    00B6    311 _OEE	=	0x00b6
                    00B8    312 _IP	=	0x00b8
                    00BA    313 _EP01STAT	=	0x00ba
                    00BB    314 _GPIFTRIG	=	0x00bb
                    00BD    315 _GPIFSGLDATH	=	0x00bd
                    00BE    316 _GPIFSGLDATLX	=	0x00be
                    00BF    317 _GPIFSGLDATLNOX	=	0x00bf
                    00C0    318 _SCON1	=	0x00c0
                    00C1    319 _SBUF1	=	0x00c1
                    00C8    320 _T2CON	=	0x00c8
                    00CA    321 _RCAP2L	=	0x00ca
                    00CB    322 _RCAP2H	=	0x00cb
                    00CC    323 _TL2	=	0x00cc
                    00CD    324 _TH2	=	0x00cd
                    00D0    325 _PSW	=	0x00d0
                    00D8    326 _EICON	=	0x00d8
                    00E0    327 _ACC	=	0x00e0
                    00E8    328 _EIE	=	0x00e8
                    00F0    329 _B	=	0x00f0
                    00F8    330 _EIP	=	0x00f8
                            331 ;--------------------------------------------------------
                            332 ; special function bits
                            333 ;--------------------------------------------------------
                            334 	.area RSEG    (ABS,DATA)
   0000                     335 	.org 0x0000
                            336 ;--------------------------------------------------------
                            337 ; overlayable register banks
                            338 ;--------------------------------------------------------
                            339 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     340 	.ds 8
                            341 ;--------------------------------------------------------
                            342 ; overlayable bit register bank
                            343 ;--------------------------------------------------------
                            344 	.area BIT_BANK	(REL,OVR,DATA)
   0021                     345 bits:
   0021                     346 	.ds 1
                    8000    347 	b0 = bits[0]
                    8100    348 	b1 = bits[1]
                    8200    349 	b2 = bits[2]
                    8300    350 	b3 = bits[3]
                    8400    351 	b4 = bits[4]
                    8500    352 	b5 = bits[5]
                    8600    353 	b6 = bits[6]
                    8700    354 	b7 = bits[7]
                            355 ;--------------------------------------------------------
                            356 ; internal ram data
                            357 ;--------------------------------------------------------
                            358 	.area DSEG    (DATA)
   0008                     359 _Configuration::
   0008                     360 	.ds 1
   0009                     361 _InterfaceSetting::
   0009                     362 	.ds 1
   000A                     363 _USB_strings::
   000A                     364 	.ds 9
   0013                     365 _SetupCommand_i_1_21:
   0013                     366 	.ds 2
   0015                     367 _bytes_waiting_for_xmit::
   0015                     368 	.ds 2
   0017                     369 _latency_us::
   0017                     370 	.ds 2
                            371 ;--------------------------------------------------------
                            372 ; overlayable items in internal ram 
                            373 ;--------------------------------------------------------
                            374 	.area	OSEG    (OVR,DATA)
                            375 ;--------------------------------------------------------
                            376 ; Stack segment in internal ram 
                            377 ;--------------------------------------------------------
                            378 	.area	SSEG	(DATA)
   0022                     379 __start__stack:
   0022                     380 	.ds	1
                            381 
                            382 ;--------------------------------------------------------
                            383 ; indirectly addressable internal ram data
                            384 ;--------------------------------------------------------
                            385 	.area ISEG    (DATA)
                            386 ;--------------------------------------------------------
                            387 ; absolute internal ram data
                            388 ;--------------------------------------------------------
                            389 	.area IABS    (ABS,DATA)
                            390 	.area IABS    (ABS,DATA)
                            391 ;--------------------------------------------------------
                            392 ; bit data
                            393 ;--------------------------------------------------------
                            394 	.area BSEG    (BIT)
   0000                     395 _Rwuen_allowed::
   0000                     396 	.ds 1
   0001                     397 _Rwuen::
   0001                     398 	.ds 1
   0002                     399 _Selfpwr::
   0002                     400 	.ds 1
                            401 ;--------------------------------------------------------
                            402 ; paged external ram data
                            403 ;--------------------------------------------------------
                            404 	.area PSEG    (PAG,XDATA)
                            405 ;--------------------------------------------------------
                            406 ; external ram data
                            407 ;--------------------------------------------------------
                            408 	.area XSEG    (XDATA)
                    E400    409 _GPIF_WAVE_DATA	=	0xe400
                    E480    410 _RES_WAVEDATA_END	=	0xe480
                    E600    411 _CPUCS	=	0xe600
                    E601    412 _IFCONFIG	=	0xe601
                    E602    413 _PINFLAGSAB	=	0xe602
                    E603    414 _PINFLAGSCD	=	0xe603
                    E604    415 _FIFORESET	=	0xe604
                    E605    416 _BREAKPT	=	0xe605
                    E606    417 _BPADDRH	=	0xe606
                    E607    418 _BPADDRL	=	0xe607
                    E608    419 _UART230	=	0xe608
                    E609    420 _FIFOPINPOLAR	=	0xe609
                    E60A    421 _REVID	=	0xe60a
                    E60B    422 _REVCTL	=	0xe60b
                    E610    423 _EP1OUTCFG	=	0xe610
                    E611    424 _EP1INCFG	=	0xe611
                    E612    425 _EP2CFG	=	0xe612
                    E613    426 _EP4CFG	=	0xe613
                    E614    427 _EP6CFG	=	0xe614
                    E615    428 _EP8CFG	=	0xe615
                    E618    429 _EP2FIFOCFG	=	0xe618
                    E619    430 _EP4FIFOCFG	=	0xe619
                    E61A    431 _EP6FIFOCFG	=	0xe61a
                    E61B    432 _EP8FIFOCFG	=	0xe61b
                    E620    433 _EP2AUTOINLENH	=	0xe620
                    E621    434 _EP2AUTOINLENL	=	0xe621
                    E622    435 _EP4AUTOINLENH	=	0xe622
                    E623    436 _EP4AUTOINLENL	=	0xe623
                    E624    437 _EP6AUTOINLENH	=	0xe624
                    E625    438 _EP6AUTOINLENL	=	0xe625
                    E626    439 _EP8AUTOINLENH	=	0xe626
                    E627    440 _EP8AUTOINLENL	=	0xe627
                    E630    441 _EP2FIFOPFH	=	0xe630
                    E631    442 _EP2FIFOPFL	=	0xe631
                    E632    443 _EP4FIFOPFH	=	0xe632
                    E633    444 _EP4FIFOPFL	=	0xe633
                    E634    445 _EP6FIFOPFH	=	0xe634
                    E635    446 _EP6FIFOPFL	=	0xe635
                    E636    447 _EP8FIFOPFH	=	0xe636
                    E637    448 _EP8FIFOPFL	=	0xe637
                    E640    449 _EP2ISOINPKTS	=	0xe640
                    E641    450 _EP4ISOINPKTS	=	0xe641
                    E642    451 _EP6ISOINPKTS	=	0xe642
                    E643    452 _EP8ISOINPKTS	=	0xe643
                    E648    453 _INPKTEND	=	0xe648
                    E649    454 _OUTPKTEND	=	0xe649
                    E650    455 _EP2FIFOIE	=	0xe650
                    E651    456 _EP2FIFOIRQ	=	0xe651
                    E652    457 _EP4FIFOIE	=	0xe652
                    E653    458 _EP4FIFOIRQ	=	0xe653
                    E654    459 _EP6FIFOIE	=	0xe654
                    E655    460 _EP6FIFOIRQ	=	0xe655
                    E656    461 _EP8FIFOIE	=	0xe656
                    E657    462 _EP8FIFOIRQ	=	0xe657
                    E658    463 _IBNIE	=	0xe658
                    E659    464 _IBNIRQ	=	0xe659
                    E65A    465 _NAKIE	=	0xe65a
                    E65B    466 _NAKIRQ	=	0xe65b
                    E65C    467 _USBIE	=	0xe65c
                    E65D    468 _USBIRQ	=	0xe65d
                    E65E    469 _EPIE	=	0xe65e
                    E65F    470 _EPIRQ	=	0xe65f
                    E660    471 _GPIFIE	=	0xe660
                    E661    472 _GPIFIRQ	=	0xe661
                    E662    473 _USBERRIE	=	0xe662
                    E663    474 _USBERRIRQ	=	0xe663
                    E664    475 _ERRCNTLIM	=	0xe664
                    E665    476 _CLRERRCNT	=	0xe665
                    E666    477 _INT2IVEC	=	0xe666
                    E667    478 _INT4IVEC	=	0xe667
                    E668    479 _INTSETUP	=	0xe668
                    E670    480 _PORTACFG	=	0xe670
                    E671    481 _PORTCCFG	=	0xe671
                    E672    482 _PORTECFG	=	0xe672
                    E678    483 _I2CS	=	0xe678
                    E679    484 _I2DAT	=	0xe679
                    E67A    485 _I2CTL	=	0xe67a
                    E67B    486 _XAUTODAT1	=	0xe67b
                    E67C    487 _XAUTODAT2	=	0xe67c
                    E680    488 _USBCS	=	0xe680
                    E681    489 _SUSPEND	=	0xe681
                    E682    490 _WAKEUPCS	=	0xe682
                    E683    491 _TOGCTL	=	0xe683
                    E684    492 _USBFRAMEH	=	0xe684
                    E685    493 _USBFRAMEL	=	0xe685
                    E686    494 _MICROFRAME	=	0xe686
                    E687    495 _FNADDR	=	0xe687
                    E68A    496 _EP0BCH	=	0xe68a
                    E68B    497 _EP0BCL	=	0xe68b
                    E68D    498 _EP1OUTBC	=	0xe68d
                    E68F    499 _EP1INBC	=	0xe68f
                    E690    500 _EP2BCH	=	0xe690
                    E691    501 _EP2BCL	=	0xe691
                    E694    502 _EP4BCH	=	0xe694
                    E695    503 _EP4BCL	=	0xe695
                    E698    504 _EP6BCH	=	0xe698
                    E699    505 _EP6BCL	=	0xe699
                    E69C    506 _EP8BCH	=	0xe69c
                    E69D    507 _EP8BCL	=	0xe69d
                    E6A0    508 _EP0CS	=	0xe6a0
                    E6A1    509 _EP1OUTCS	=	0xe6a1
                    E6A2    510 _EP1INCS	=	0xe6a2
                    E6A3    511 _EP2CS	=	0xe6a3
                    E6A4    512 _EP4CS	=	0xe6a4
                    E6A5    513 _EP6CS	=	0xe6a5
                    E6A6    514 _EP8CS	=	0xe6a6
                    E6A7    515 _EP2FIFOFLGS	=	0xe6a7
                    E6A8    516 _EP4FIFOFLGS	=	0xe6a8
                    E6A9    517 _EP6FIFOFLGS	=	0xe6a9
                    E6AA    518 _EP8FIFOFLGS	=	0xe6aa
                    E6AB    519 _EP2FIFOBCH	=	0xe6ab
                    E6AC    520 _EP2FIFOBCL	=	0xe6ac
                    E6AD    521 _EP4FIFOBCH	=	0xe6ad
                    E6AE    522 _EP4FIFOBCL	=	0xe6ae
                    E6AF    523 _EP6FIFOBCH	=	0xe6af
                    E6B0    524 _EP6FIFOBCL	=	0xe6b0
                    E6B1    525 _EP8FIFOBCH	=	0xe6b1
                    E6B2    526 _EP8FIFOBCL	=	0xe6b2
                    E6B3    527 _SUDPTRH	=	0xe6b3
                    E6B4    528 _SUDPTRL	=	0xe6b4
                    E6B5    529 _SUDPTRCTL	=	0xe6b5
                    E6B8    530 _SETUPDAT	=	0xe6b8
                    E6C0    531 _GPIFWFSELECT	=	0xe6c0
                    E6C1    532 _GPIFIDLECS	=	0xe6c1
                    E6C2    533 _GPIFIDLECTL	=	0xe6c2
                    E6C3    534 _GPIFCTLCFG	=	0xe6c3
                    E6C4    535 _GPIFADRH	=	0xe6c4
                    E6C5    536 _GPIFADRL	=	0xe6c5
                    E6CE    537 _GPIFTCB3	=	0xe6ce
                    E6CF    538 _GPIFTCB2	=	0xe6cf
                    E6D0    539 _GPIFTCB1	=	0xe6d0
                    E6D1    540 _GPIFTCB0	=	0xe6d1
                    E6D2    541 _EP2GPIFFLGSEL	=	0xe6d2
                    E6D3    542 _EP2GPIFPFSTOP	=	0xe6d3
                    E6D4    543 _EP2GPIFTRIG	=	0xe6d4
                    E6DA    544 _EP4GPIFFLGSEL	=	0xe6da
                    E6DB    545 _EP4GPIFPFSTOP	=	0xe6db
                    E6DC    546 _EP4GPIFTRIG	=	0xe6dc
                    E6E2    547 _EP6GPIFFLGSEL	=	0xe6e2
                    E6E3    548 _EP6GPIFPFSTOP	=	0xe6e3
                    E6E4    549 _EP6GPIFTRIG	=	0xe6e4
                    E6EA    550 _EP8GPIFFLGSEL	=	0xe6ea
                    E6EB    551 _EP8GPIFPFSTOP	=	0xe6eb
                    E6EC    552 _EP8GPIFTRIG	=	0xe6ec
                    E6F0    553 _XGPIFSGLDATH	=	0xe6f0
                    E6F1    554 _XGPIFSGLDATLX	=	0xe6f1
                    E6F2    555 _XGPIFSGLDATLNOX	=	0xe6f2
                    E6F3    556 _GPIFREADYCFG	=	0xe6f3
                    E6F4    557 _GPIFREADYSTAT	=	0xe6f4
                    E6F5    558 _GPIFABORT	=	0xe6f5
                    E6C6    559 _FLOWSTATE	=	0xe6c6
                    E6C7    560 _FLOWLOGIC	=	0xe6c7
                    E6C8    561 _FLOWEQ0CTL	=	0xe6c8
                    E6C9    562 _FLOWEQ1CTL	=	0xe6c9
                    E6CA    563 _FLOWHOLDOFF	=	0xe6ca
                    E6CB    564 _FLOWSTB	=	0xe6cb
                    E6CC    565 _FLOWSTBEDGE	=	0xe6cc
                    E6CD    566 _FLOWSTBHPERIOD	=	0xe6cd
                    E60C    567 _GPIFHOLDAMOUNT	=	0xe60c
                    E67D    568 _UDMACRCH	=	0xe67d
                    E67E    569 _UDMACRCL	=	0xe67e
                    E67F    570 _UDMACRCQUAL	=	0xe67f
                    E6F8    571 _DBUG	=	0xe6f8
                    E6F9    572 _TESTCFG	=	0xe6f9
                    E6FA    573 _USBTEST	=	0xe6fa
                    E6FB    574 _CT1	=	0xe6fb
                    E6FC    575 _CT2	=	0xe6fc
                    E6FD    576 _CT3	=	0xe6fd
                    E6FE    577 _CT4	=	0xe6fe
                    E740    578 _EP0BUF	=	0xe740
                    E780    579 _EP1OUTBUF	=	0xe780
                    E7C0    580 _EP1INBUF	=	0xe7c0
                    F000    581 _EP2FIFOBUF	=	0xf000
                    F400    582 _EP4FIFOBUF	=	0xf400
                    F800    583 _EP6FIFOBUF	=	0xf800
                    FC00    584 _EP8FIFOBUF	=	0xfc00
                            585 ;--------------------------------------------------------
                            586 ; absolute external ram data
                            587 ;--------------------------------------------------------
                            588 	.area XABS    (ABS,XDATA)
   3D00                     589 	.org 0x3D00
   3D00                     590 _myDeviceDscr::
   3D00                     591 	.ds 18
   3D20                     592 	.org 0x3D20
   3D20                     593 _myDeviceQualDscr::
   3D20                     594 	.ds 10
   3D30                     595 	.org 0x3D30
   3D30                     596 _myConfigDscr::
   3D30                     597 	.ds 9
   3D39                     598 	.org 0x3D39
   3D39                     599 _myIntrfcDscr::
   3D39                     600 	.ds 9
   3D42                     601 	.org 0x3D42
   3D42                     602 _myInEndpntDscr::
   3D42                     603 	.ds 7
   3D49                     604 	.org 0x3D49
   3D49                     605 _myOutEndpntDscr::
   3D49                     606 	.ds 7
                            607 ;--------------------------------------------------------
                            608 ; external initialized ram data
                            609 ;--------------------------------------------------------
                            610 	.area XISEG   (XDATA)
                            611 	.area HOME    (CODE)
                            612 	.area GSINIT0 (CODE)
                            613 	.area GSINIT1 (CODE)
                            614 	.area GSINIT2 (CODE)
                            615 	.area GSINIT3 (CODE)
                            616 	.area GSINIT4 (CODE)
                            617 	.area GSINIT5 (CODE)
                            618 	.area GSINIT  (CODE)
                            619 	.area GSFINAL (CODE)
                            620 	.area CSEG    (CODE)
                            621 ;--------------------------------------------------------
                            622 ; interrupt vector 
                            623 ;--------------------------------------------------------
                            624 	.area HOME    (CODE)
   0000                     625 __interrupt_vect:
   0000 02 00 79            626 	ljmp	__sdcc_gsinit_startup
   0003 32                  627 	reti
   0004                     628 	.ds	7
   000B 32                  629 	reti
   000C                     630 	.ds	7
   0013 32                  631 	reti
   0014                     632 	.ds	7
   001B 32                  633 	reti
   001C                     634 	.ds	7
   0023 32                  635 	reti
   0024                     636 	.ds	7
   002B 32                  637 	reti
   002C                     638 	.ds	7
   0033 32                  639 	reti
   0034                     640 	.ds	7
   003B 32                  641 	reti
   003C                     642 	.ds	7
   0043 02 07 20            643 	ljmp	_USB_isr
                            644 ;--------------------------------------------------------
                            645 ; global & static initialisations
                            646 ;--------------------------------------------------------
                            647 	.area HOME    (CODE)
                            648 	.area GSINIT  (CODE)
                            649 	.area GSFINAL (CODE)
                            650 	.area GSINIT  (CODE)
                            651 	.globl __sdcc_gsinit_startup
                            652 	.globl __sdcc_program_startup
                            653 	.globl __start__stack
                            654 	.globl __mcs51_genXINIT
                            655 	.globl __mcs51_genXRAMCLEAR
                            656 	.globl __mcs51_genRAMCLEAR
                            657 ;	convert_serial2.c:109: char * USB_strings[] = { "EN", "WieserLabs & freesoft.org", "FX2 case converter" };
   00D2 75 0A 6A            658 	mov	(_USB_strings + 0),#__str_0
   00D5 75 0B 09            659 	mov	(_USB_strings + 1),#(__str_0 >> 8)
   00D8 75 0C 80            660 	mov	(_USB_strings + 2),#0x80
   00DB 75 0D 6D            661 	mov	((_USB_strings + 0x0003) + 0),#__str_1
   00DE 75 0E 09            662 	mov	((_USB_strings + 0x0003) + 1),#(__str_1 >> 8)
   00E1 75 0F 80            663 	mov	((_USB_strings + 0x0003) + 2),#0x80
   00E4 75 10 87            664 	mov	((_USB_strings + 0x0006) + 0),#__str_2
   00E7 75 11 09            665 	mov	((_USB_strings + 0x0006) + 1),#(__str_2 >> 8)
   00EA 75 12 80            666 	mov	((_USB_strings + 0x0006) + 2),#0x80
                            667 ;	convert_serial2.c:497: unsigned int bytes_waiting_for_xmit = 0;
   00ED E4                  668 	clr	a
   00EE F5 15               669 	mov	_bytes_waiting_for_xmit,a
   00F0 F5 16               670 	mov	(_bytes_waiting_for_xmit + 1),a
                            671 ;	convert_serial2.c:498: unsigned int latency_us = 40000;
   00F2 75 17 40            672 	mov	_latency_us,#0x40
   00F5 75 18 9C            673 	mov	(_latency_us + 1),#0x9C
                            674 ;	convert_serial2.c:42: BOOL Rwuen_allowed = FALSE;	// Allow remote wakeup to be enabled
   00F8 C2 00               675 	clr	_Rwuen_allowed
                            676 ;	convert_serial2.c:43: BOOL Rwuen = FALSE;		// Remote wakeup enable
   00FA C2 01               677 	clr	_Rwuen
                            678 ;	convert_serial2.c:44: BOOL Selfpwr = FALSE;		// Device is (not) self-powered
   00FC C2 02               679 	clr	_Selfpwr
                            680 ;	convert_serial2.c:127: DEVICEDSCR xdata at 0x3d00 myDeviceDscr = {
   00FE 90 3D 00            681 	mov	dptr,#_myDeviceDscr
   0101 74 12               682 	mov	a,#0x12
   0103 F0                  683 	movx	@dptr,a
   0104 90 3D 01            684 	mov	dptr,#(_myDeviceDscr + 0x0001)
   0107 74 01               685 	mov	a,#0x01
   0109 F0                  686 	movx	@dptr,a
   010A 90 3D 02            687 	mov	dptr,#(_myDeviceDscr + 0x0002)
   010D E4                  688 	clr	a
   010E F0                  689 	movx	@dptr,a
   010F A3                  690 	inc	dptr
   0110 74 02               691 	mov	a,#0x02
   0112 F0                  692 	movx	@dptr,a
   0113 90 3D 04            693 	mov	dptr,#(_myDeviceDscr + 0x0004)
   0116 E4                  694 	clr	a
   0117 F0                  695 	movx	@dptr,a
   0118 90 3D 05            696 	mov	dptr,#(_myDeviceDscr + 0x0005)
   011B F0                  697 	movx	@dptr,a
   011C 90 3D 06            698 	mov	dptr,#(_myDeviceDscr + 0x0006)
   011F F0                  699 	movx	@dptr,a
   0120 90 3D 07            700 	mov	dptr,#(_myDeviceDscr + 0x0007)
   0123 74 40               701 	mov	a,#0x40
   0125 F0                  702 	movx	@dptr,a
   0126 90 3D 08            703 	mov	dptr,#(_myDeviceDscr + 0x0008)
   0129 74 99               704 	mov	a,#0x99
   012B F0                  705 	movx	@dptr,a
   012C A3                  706 	inc	dptr
   012D 74 11               707 	mov	a,#0x11
   012F F0                  708 	movx	@dptr,a
   0130 90 3D 0A            709 	mov	dptr,#(_myDeviceDscr + 0x000a)
   0133 74 17               710 	mov	a,#0x17
   0135 F0                  711 	movx	@dptr,a
   0136 A3                  712 	inc	dptr
   0137 E4                  713 	clr	a
   0138 F0                  714 	movx	@dptr,a
   0139 90 3D 0C            715 	mov	dptr,#(_myDeviceDscr + 0x000c)
   013C F0                  716 	movx	@dptr,a
   013D A3                  717 	inc	dptr
   013E 74 01               718 	mov	a,#0x01
   0140 F0                  719 	movx	@dptr,a
   0141 90 3D 0E            720 	mov	dptr,#(_myDeviceDscr + 0x000e)
   0144 74 01               721 	mov	a,#0x01
   0146 F0                  722 	movx	@dptr,a
   0147 90 3D 0F            723 	mov	dptr,#(_myDeviceDscr + 0x000f)
   014A 74 02               724 	mov	a,#0x02
   014C F0                  725 	movx	@dptr,a
   014D 90 3D 10            726 	mov	dptr,#(_myDeviceDscr + 0x0010)
   0150 E4                  727 	clr	a
   0151 F0                  728 	movx	@dptr,a
   0152 90 3D 11            729 	mov	dptr,#(_myDeviceDscr + 0x0011)
   0155 74 01               730 	mov	a,#0x01
   0157 F0                  731 	movx	@dptr,a
                            732 ;	convert_serial2.c:152: DEVICEQUALDSCR xdata at 0x3d20 myDeviceQualDscr = {
   0158 90 3D 20            733 	mov	dptr,#_myDeviceQualDscr
   015B 74 0A               734 	mov	a,#0x0A
   015D F0                  735 	movx	@dptr,a
   015E 90 3D 21            736 	mov	dptr,#(_myDeviceQualDscr + 0x0001)
   0161 74 06               737 	mov	a,#0x06
   0163 F0                  738 	movx	@dptr,a
   0164 90 3D 22            739 	mov	dptr,#(_myDeviceQualDscr + 0x0002)
   0167 E4                  740 	clr	a
   0168 F0                  741 	movx	@dptr,a
   0169 A3                  742 	inc	dptr
   016A 74 02               743 	mov	a,#0x02
   016C F0                  744 	movx	@dptr,a
   016D 90 3D 24            745 	mov	dptr,#(_myDeviceQualDscr + 0x0004)
   0170 E4                  746 	clr	a
   0171 F0                  747 	movx	@dptr,a
   0172 90 3D 25            748 	mov	dptr,#(_myDeviceQualDscr + 0x0005)
   0175 F0                  749 	movx	@dptr,a
   0176 90 3D 26            750 	mov	dptr,#(_myDeviceQualDscr + 0x0006)
   0179 F0                  751 	movx	@dptr,a
   017A 90 3D 27            752 	mov	dptr,#(_myDeviceQualDscr + 0x0007)
   017D 74 40               753 	mov	a,#0x40
   017F F0                  754 	movx	@dptr,a
   0180 90 3D 28            755 	mov	dptr,#(_myDeviceQualDscr + 0x0008)
   0183 74 01               756 	mov	a,#0x01
   0185 F0                  757 	movx	@dptr,a
                            758 ;	convert_serial2.c:170: CONFIGDSCR xdata at 0x3d30 myConfigDscr = {
   0186 90 3D 30            759 	mov	dptr,#_myConfigDscr
   0189 74 09               760 	mov	a,#0x09
   018B F0                  761 	movx	@dptr,a
   018C 90 3D 31            762 	mov	dptr,#(_myConfigDscr + 0x0001)
   018F 74 02               763 	mov	a,#0x02
   0191 F0                  764 	movx	@dptr,a
   0192 90 3D 32            765 	mov	dptr,#(_myConfigDscr + 0x0002)
   0195 74 20               766 	mov	a,#0x20
   0197 F0                  767 	movx	@dptr,a
   0198 A3                  768 	inc	dptr
   0199 E4                  769 	clr	a
   019A F0                  770 	movx	@dptr,a
   019B 90 3D 34            771 	mov	dptr,#(_myConfigDscr + 0x0004)
   019E 74 01               772 	mov	a,#0x01
   01A0 F0                  773 	movx	@dptr,a
   01A1 90 3D 35            774 	mov	dptr,#(_myConfigDscr + 0x0005)
   01A4 74 01               775 	mov	a,#0x01
   01A6 F0                  776 	movx	@dptr,a
   01A7 90 3D 36            777 	mov	dptr,#(_myConfigDscr + 0x0006)
   01AA E4                  778 	clr	a
   01AB F0                  779 	movx	@dptr,a
   01AC 90 3D 37            780 	mov	dptr,#(_myConfigDscr + 0x0007)
   01AF 74 A0               781 	mov	a,#0xA0
   01B1 F0                  782 	movx	@dptr,a
   01B2 90 3D 38            783 	mov	dptr,#(_myConfigDscr + 0x0008)
   01B5 74 1E               784 	mov	a,#0x1E
   01B7 F0                  785 	movx	@dptr,a
                            786 ;	convert_serial2.c:181: INTRFCDSCR xdata at 0x3d30+DSCR_OFFSET(0,0) myIntrfcDscr = {
   01B8 90 3D 39            787 	mov	dptr,#_myIntrfcDscr
   01BB 74 09               788 	mov	a,#0x09
   01BD F0                  789 	movx	@dptr,a
   01BE 90 3D 3A            790 	mov	dptr,#(_myIntrfcDscr + 0x0001)
   01C1 74 04               791 	mov	a,#0x04
   01C3 F0                  792 	movx	@dptr,a
   01C4 90 3D 3B            793 	mov	dptr,#(_myIntrfcDscr + 0x0002)
   01C7 E4                  794 	clr	a
   01C8 F0                  795 	movx	@dptr,a
   01C9 90 3D 3C            796 	mov	dptr,#(_myIntrfcDscr + 0x0003)
   01CC F0                  797 	movx	@dptr,a
   01CD 90 3D 3D            798 	mov	dptr,#(_myIntrfcDscr + 0x0004)
   01D0 74 02               799 	mov	a,#0x02
   01D2 F0                  800 	movx	@dptr,a
   01D3 90 3D 3E            801 	mov	dptr,#(_myIntrfcDscr + 0x0005)
   01D6 74 FF               802 	mov	a,#0xFF
   01D8 F0                  803 	movx	@dptr,a
   01D9 90 3D 3F            804 	mov	dptr,#(_myIntrfcDscr + 0x0006)
   01DC 74 FF               805 	mov	a,#0xFF
   01DE F0                  806 	movx	@dptr,a
   01DF 90 3D 40            807 	mov	dptr,#(_myIntrfcDscr + 0x0007)
   01E2 74 FF               808 	mov	a,#0xFF
   01E4 F0                  809 	movx	@dptr,a
   01E5 90 3D 41            810 	mov	dptr,#(_myIntrfcDscr + 0x0008)
   01E8 E4                  811 	clr	a
   01E9 F0                  812 	movx	@dptr,a
                            813 ;	convert_serial2.c:193: ENDPNTDSCR xdata at 0x3d30+DSCR_OFFSET(1,0) myInEndpntDscr = {
   01EA 90 3D 42            814 	mov	dptr,#_myInEndpntDscr
   01ED 74 07               815 	mov	a,#0x07
   01EF F0                  816 	movx	@dptr,a
   01F0 90 3D 43            817 	mov	dptr,#(_myInEndpntDscr + 0x0001)
   01F3 74 05               818 	mov	a,#0x05
   01F5 F0                  819 	movx	@dptr,a
   01F6 90 3D 44            820 	mov	dptr,#(_myInEndpntDscr + 0x0002)
   01F9 74 86               821 	mov	a,#0x86
   01FB F0                  822 	movx	@dptr,a
   01FC 90 3D 45            823 	mov	dptr,#(_myInEndpntDscr + 0x0003)
   01FF 74 02               824 	mov	a,#0x02
   0201 F0                  825 	movx	@dptr,a
   0202 90 3D 46            826 	mov	dptr,#(_myInEndpntDscr + 0x0004)
   0205 E4                  827 	clr	a
   0206 F0                  828 	movx	@dptr,a
   0207 A3                  829 	inc	dptr
   0208 74 02               830 	mov	a,#0x02
   020A F0                  831 	movx	@dptr,a
   020B 90 3D 48            832 	mov	dptr,#(_myInEndpntDscr + 0x0006)
   020E E4                  833 	clr	a
   020F F0                  834 	movx	@dptr,a
                            835 ;	convert_serial2.c:203: ENDPNTDSCR xdata at 0x3d30+DSCR_OFFSET(1,1) myOutEndpntDscr = {
   0210 90 3D 49            836 	mov	dptr,#_myOutEndpntDscr
   0213 74 07               837 	mov	a,#0x07
   0215 F0                  838 	movx	@dptr,a
   0216 90 3D 4A            839 	mov	dptr,#(_myOutEndpntDscr + 0x0001)
   0219 74 05               840 	mov	a,#0x05
   021B F0                  841 	movx	@dptr,a
   021C 90 3D 4B            842 	mov	dptr,#(_myOutEndpntDscr + 0x0002)
   021F 74 02               843 	mov	a,#0x02
   0221 F0                  844 	movx	@dptr,a
   0222 90 3D 4C            845 	mov	dptr,#(_myOutEndpntDscr + 0x0003)
   0225 74 02               846 	mov	a,#0x02
   0227 F0                  847 	movx	@dptr,a
   0228 90 3D 4D            848 	mov	dptr,#(_myOutEndpntDscr + 0x0004)
   022B E4                  849 	clr	a
   022C F0                  850 	movx	@dptr,a
   022D A3                  851 	inc	dptr
   022E 74 02               852 	mov	a,#0x02
   0230 F0                  853 	movx	@dptr,a
   0231 90 3D 4F            854 	mov	dptr,#(_myOutEndpntDscr + 0x0006)
   0234 E4                  855 	clr	a
   0235 F0                  856 	movx	@dptr,a
                            857 	.area GSFINAL (CODE)
   0236 02 00 46            858 	ljmp	__sdcc_program_startup
                            859 ;--------------------------------------------------------
                            860 ; Home
                            861 ;--------------------------------------------------------
                            862 	.area HOME    (CODE)
                            863 	.area HOME    (CODE)
   0046                     864 __sdcc_program_startup:
   0046 12 09 05            865 	lcall	_main
                            866 ;	return from main will lock up
   0049 80 FE               867 	sjmp .
                            868 ;--------------------------------------------------------
                            869 ; code
                            870 ;--------------------------------------------------------
                            871 	.area CSEG    (CODE)
                            872 ;------------------------------------------------------------
                            873 ;Allocation info for local variables in function 'count_array_size'
                            874 ;------------------------------------------------------------
                            875 ;array                     Allocated to registers 
                            876 ;size                      Allocated to registers r3 r4 
                            877 ;------------------------------------------------------------
                            878 ;	convert_serial2.c:217: static int count_array_size(void ** array)
                            879 ;	-----------------------------------------
                            880 ;	 function count_array_size
                            881 ;	-----------------------------------------
   0239                     882 _count_array_size:
                    0007    883 	ar7 = 0x07
                    0006    884 	ar6 = 0x06
                    0005    885 	ar5 = 0x05
                    0004    886 	ar4 = 0x04
                    0003    887 	ar3 = 0x03
                    0002    888 	ar2 = 0x02
                    0001    889 	ar1 = 0x01
                    0000    890 	ar0 = 0x00
   0239 AD 82               891 	mov	r5,dpl
   023B AE 83               892 	mov	r6,dph
   023D AF F0               893 	mov	r7,b
                            894 ;	convert_serial2.c:220: for (size=0; *array != 0; array++, size++);
   023F 7B 00               895 	mov	r3,#0x00
   0241 7C 00               896 	mov	r4,#0x00
   0243                     897 00101$:
   0243 8D 82               898 	mov	dpl,r5
   0245 8E 83               899 	mov	dph,r6
   0247 8F F0               900 	mov	b,r7
   0249 12 09 40            901 	lcall	__gptrget
   024C F8                  902 	mov	r0,a
   024D A3                  903 	inc	dptr
   024E 12 09 40            904 	lcall	__gptrget
   0251 F9                  905 	mov	r1,a
   0252 A3                  906 	inc	dptr
   0253 12 09 40            907 	lcall	__gptrget
   0256 FA                  908 	mov	r2,a
   0257 E4                  909 	clr	a
   0258 C0 E0               910 	push	acc
   025A E4                  911 	clr	a
   025B C0 E0               912 	push	acc
   025D E4                  913 	clr	a
   025E C0 E0               914 	push	acc
   0260 88 82               915 	mov	dpl,r0
   0262 89 83               916 	mov	dph,r1
   0264 8A F0               917 	mov	b,r2
   0266 12 00 4B            918 	lcall	___gptr_cmp
   0269 15 81               919 	dec	sp
   026B 15 81               920 	dec	sp
   026D 15 81               921 	dec	sp
   026F 60 0E               922 	jz	00104$
   0271 74 03               923 	mov	a,#0x03
   0273 2D                  924 	add	a,r5
   0274 FD                  925 	mov	r5,a
   0275 E4                  926 	clr	a
   0276 3E                  927 	addc	a,r6
   0277 FE                  928 	mov	r6,a
   0278 0B                  929 	inc	r3
   0279 BB 00 C7            930 	cjne	r3,#0x00,00101$
   027C 0C                  931 	inc	r4
   027D 80 C4               932 	sjmp	00101$
   027F                     933 00104$:
                            934 ;	convert_serial2.c:221: return size;
   027F 8B 82               935 	mov	dpl,r3
   0281 8C 83               936 	mov	dph,r4
   0283 22                  937 	ret
                            938 ;------------------------------------------------------------
                            939 ;Allocation info for local variables in function 'SetupCommand'
                            940 ;------------------------------------------------------------
                            941 ;i                         Allocated with name '_SetupCommand_i_1_21'
                            942 ;interface                 Allocated to registers r6 r7 
                            943 ;------------------------------------------------------------
                            944 ;	convert_serial2.c:224: static void SetupCommand(void)
                            945 ;	-----------------------------------------
                            946 ;	 function SetupCommand
                            947 ;	-----------------------------------------
   0284                     948 _SetupCommand:
                            949 ;	convert_serial2.c:231: switch(SETUPDAT[0] & SETUP_MASK) {
   0284 90 E6 B8            950 	mov	dptr,#_SETUPDAT
   0287 E0                  951 	movx	a,@dptr
   0288 FF                  952 	mov	r7,a
   0289 53 07 60            953 	anl	ar7,#0x60
   028C BF 00 02            954 	cjne	r7,#0x00,00222$
   028F 80 03               955 	sjmp	00223$
   0291                     956 00222$:
   0291 02 07 10            957 	ljmp	00163$
   0294                     958 00223$:
                            959 ;	convert_serial2.c:234: switch(SETUPDAT[1])
   0294 90 E6 B9            960 	mov	dptr,#(_SETUPDAT + 0x0001)
   0297 E0                  961 	movx	a,@dptr
   0298 FF                  962 	mov  r7,a
   0299 24 F4               963 	add	a,#0xff - 0x0B
   029B 50 03               964 	jnc	00224$
   029D 02 07 06            965 	ljmp	00161$
   02A0                     966 00224$:
   02A0 EF                  967 	mov	a,r7
   02A1 2F                  968 	add	a,r7
   02A2 2F                  969 	add	a,r7
   02A3 90 02 A7            970 	mov	dptr,#00225$
   02A6 73                  971 	jmp	@a+dptr
   02A7                     972 00225$:
   02A7 02 05 13            973 	ljmp	00133$
   02AA 02 05 B5            974 	ljmp	00139$
   02AD 02 07 06            975 	ljmp	00161$
   02B0 02 06 6C            976 	ljmp	00149$
   02B3 02 07 06            977 	ljmp	00161$
   02B6 02 07 06            978 	ljmp	00161$
   02B9 02 02 CB            979 	ljmp	00102$
   02BC 02 07 06            980 	ljmp	00161$
   02BF 02 04 FF            981 	ljmp	00132$
   02C2 02 04 F6            982 	ljmp	00131$
   02C5 02 04 A5            983 	ljmp	00125$
   02C8 02 04 D3            984 	ljmp	00128$
                            985 ;	convert_serial2.c:236: case SC_GET_DESCRIPTOR:
   02CB                     986 00102$:
                            987 ;	convert_serial2.c:237: switch(SETUPDAT[3])
   02CB 90 E6 BB            988 	mov	dptr,#(_SETUPDAT + 0x0003)
   02CE E0                  989 	movx	a,@dptr
   02CF FF                  990 	mov	r7,a
   02D0 BF 01 02            991 	cjne	r7,#0x01,00226$
   02D3 80 19               992 	sjmp	00103$
   02D5                     993 00226$:
   02D5 BF 02 02            994 	cjne	r7,#0x02,00227$
   02D8 80 46               995 	sjmp	00105$
   02DA                     996 00227$:
   02DA BF 03 03            997 	cjne	r7,#0x03,00228$
   02DD 02 03 BA            998 	ljmp	00113$
   02E0                     999 00228$:
   02E0 BF 06 02           1000 	cjne	r7,#0x06,00229$
   02E3 80 22              1001 	sjmp	00104$
   02E5                    1002 00229$:
   02E5 BF 07 03           1003 	cjne	r7,#0x07,00230$
   02E8 02 03 6D           1004 	ljmp	00109$
   02EB                    1005 00230$:
   02EB 02 04 9A           1006 	ljmp	00123$
                           1007 ;	convert_serial2.c:239: case GD_DEVICE:
   02EE                    1008 00103$:
                           1009 ;	convert_serial2.c:240: SUDPTRH = MSB(&myDeviceDscr);
   02EE 7E 00              1010 	mov	r6,#_myDeviceDscr
   02F0 7F 3D              1011 	mov	r7,#(_myDeviceDscr >> 8)
   02F2 8F 06              1012 	mov	ar6,r7
   02F4 90 E6 B3           1013 	mov	dptr,#_SUDPTRH
   02F7 EE                 1014 	mov	a,r6
   02F8 F0                 1015 	movx	@dptr,a
                           1016 ;	convert_serial2.c:241: SUDPTRL = LSB(&myDeviceDscr);
   02F9 7E 00              1017 	mov	r6,#_myDeviceDscr
   02FB 7F 3D              1018 	mov	r7,#(_myDeviceDscr >> 8)
   02FD 7F 00              1019 	mov	r7,#0x00
   02FF 90 E6 B4           1020 	mov	dptr,#_SUDPTRL
   0302 EE                 1021 	mov	a,r6
   0303 F0                 1022 	movx	@dptr,a
                           1023 ;	convert_serial2.c:242: break;
   0304 02 07 18           1024 	ljmp	00164$
                           1025 ;	convert_serial2.c:243: case GD_DEVICE_QUALIFIER:
   0307                    1026 00104$:
                           1027 ;	convert_serial2.c:244: SUDPTRH = MSB(&myDeviceQualDscr);
   0307 7E 20              1028 	mov	r6,#_myDeviceQualDscr
   0309 7F 3D              1029 	mov	r7,#(_myDeviceQualDscr >> 8)
   030B 8F 06              1030 	mov	ar6,r7
   030D 90 E6 B3           1031 	mov	dptr,#_SUDPTRH
   0310 EE                 1032 	mov	a,r6
   0311 F0                 1033 	movx	@dptr,a
                           1034 ;	convert_serial2.c:245: SUDPTRL = LSB(&myDeviceQualDscr);
   0312 7E 20              1035 	mov	r6,#_myDeviceQualDscr
   0314 7F 3D              1036 	mov	r7,#(_myDeviceQualDscr >> 8)
   0316 7F 00              1037 	mov	r7,#0x00
   0318 90 E6 B4           1038 	mov	dptr,#_SUDPTRL
   031B EE                 1039 	mov	a,r6
   031C F0                 1040 	movx	@dptr,a
                           1041 ;	convert_serial2.c:246: break;
   031D 02 07 18           1042 	ljmp	00164$
                           1043 ;	convert_serial2.c:247: case GD_CONFIGURATION:
   0320                    1044 00105$:
                           1045 ;	convert_serial2.c:248: myConfigDscr.type = CONFIG_DSCR;
   0320 90 3D 31           1046 	mov	dptr,#(_myConfigDscr + 0x0001)
   0323 74 02              1047 	mov	a,#0x02
   0325 F0                 1048 	movx	@dptr,a
                           1049 ;	convert_serial2.c:249: if (USBCS & bmHSM) {
   0326 90 E6 80           1050 	mov	dptr,#_USBCS
   0329 E0                 1051 	movx	a,@dptr
   032A FF                 1052 	mov	r7,a
   032B 30 E7 14           1053 	jnb	acc.7,00107$
                           1054 ;	convert_serial2.c:251: myInEndpntDscr.mp = 512;
   032E 90 3D 46           1055 	mov	dptr,#(_myInEndpntDscr + 0x0004)
   0331 E4                 1056 	clr	a
   0332 F0                 1057 	movx	@dptr,a
   0333 A3                 1058 	inc	dptr
   0334 74 02              1059 	mov	a,#0x02
   0336 F0                 1060 	movx	@dptr,a
                           1061 ;	convert_serial2.c:252: myOutEndpntDscr.mp = 512;
   0337 90 3D 4D           1062 	mov	dptr,#(_myOutEndpntDscr + 0x0004)
   033A E4                 1063 	clr	a
   033B F0                 1064 	movx	@dptr,a
   033C A3                 1065 	inc	dptr
   033D 74 02              1066 	mov	a,#0x02
   033F F0                 1067 	movx	@dptr,a
   0340 80 12              1068 	sjmp	00108$
   0342                    1069 00107$:
                           1070 ;	convert_serial2.c:255: myInEndpntDscr.mp = 64;
   0342 90 3D 46           1071 	mov	dptr,#(_myInEndpntDscr + 0x0004)
   0345 74 40              1072 	mov	a,#0x40
   0347 F0                 1073 	movx	@dptr,a
   0348 A3                 1074 	inc	dptr
   0349 E4                 1075 	clr	a
   034A F0                 1076 	movx	@dptr,a
                           1077 ;	convert_serial2.c:256: myOutEndpntDscr.mp = 64;
   034B 90 3D 4D           1078 	mov	dptr,#(_myOutEndpntDscr + 0x0004)
   034E 74 40              1079 	mov	a,#0x40
   0350 F0                 1080 	movx	@dptr,a
   0351 A3                 1081 	inc	dptr
   0352 E4                 1082 	clr	a
   0353 F0                 1083 	movx	@dptr,a
   0354                    1084 00108$:
                           1085 ;	convert_serial2.c:258: SUDPTRH = MSB(&myConfigDscr);
   0354 7E 30              1086 	mov	r6,#_myConfigDscr
   0356 7F 3D              1087 	mov	r7,#(_myConfigDscr >> 8)
   0358 8F 06              1088 	mov	ar6,r7
   035A 90 E6 B3           1089 	mov	dptr,#_SUDPTRH
   035D EE                 1090 	mov	a,r6
   035E F0                 1091 	movx	@dptr,a
                           1092 ;	convert_serial2.c:259: SUDPTRL = LSB(&myConfigDscr);
   035F 7E 30              1093 	mov	r6,#_myConfigDscr
   0361 7F 3D              1094 	mov	r7,#(_myConfigDscr >> 8)
   0363 7F 00              1095 	mov	r7,#0x00
   0365 90 E6 B4           1096 	mov	dptr,#_SUDPTRL
   0368 EE                 1097 	mov	a,r6
   0369 F0                 1098 	movx	@dptr,a
                           1099 ;	convert_serial2.c:260: break;
   036A 02 07 18           1100 	ljmp	00164$
                           1101 ;	convert_serial2.c:261: case GD_OTHER_SPEED_CONFIGURATION:
   036D                    1102 00109$:
                           1103 ;	convert_serial2.c:262: myConfigDscr.type = OTHERSPEED_DSCR;
   036D 90 3D 31           1104 	mov	dptr,#(_myConfigDscr + 0x0001)
   0370 74 07              1105 	mov	a,#0x07
   0372 F0                 1106 	movx	@dptr,a
                           1107 ;	convert_serial2.c:263: if (USBCS & bmHSM) {
   0373 90 E6 80           1108 	mov	dptr,#_USBCS
   0376 E0                 1109 	movx	a,@dptr
   0377 FF                 1110 	mov	r7,a
   0378 30 E7 14           1111 	jnb	acc.7,00111$
                           1112 ;	convert_serial2.c:266: myInEndpntDscr.mp = 64;
   037B 90 3D 46           1113 	mov	dptr,#(_myInEndpntDscr + 0x0004)
   037E 74 40              1114 	mov	a,#0x40
   0380 F0                 1115 	movx	@dptr,a
   0381 A3                 1116 	inc	dptr
   0382 E4                 1117 	clr	a
   0383 F0                 1118 	movx	@dptr,a
                           1119 ;	convert_serial2.c:267: myOutEndpntDscr.mp = 64;
   0384 90 3D 4D           1120 	mov	dptr,#(_myOutEndpntDscr + 0x0004)
   0387 74 40              1121 	mov	a,#0x40
   0389 F0                 1122 	movx	@dptr,a
   038A A3                 1123 	inc	dptr
   038B E4                 1124 	clr	a
   038C F0                 1125 	movx	@dptr,a
   038D 80 12              1126 	sjmp	00112$
   038F                    1127 00111$:
                           1128 ;	convert_serial2.c:271: myInEndpntDscr.mp = 512;
   038F 90 3D 46           1129 	mov	dptr,#(_myInEndpntDscr + 0x0004)
   0392 E4                 1130 	clr	a
   0393 F0                 1131 	movx	@dptr,a
   0394 A3                 1132 	inc	dptr
   0395 74 02              1133 	mov	a,#0x02
   0397 F0                 1134 	movx	@dptr,a
                           1135 ;	convert_serial2.c:272: myOutEndpntDscr.mp = 512;
   0398 90 3D 4D           1136 	mov	dptr,#(_myOutEndpntDscr + 0x0004)
   039B E4                 1137 	clr	a
   039C F0                 1138 	movx	@dptr,a
   039D A3                 1139 	inc	dptr
   039E 74 02              1140 	mov	a,#0x02
   03A0 F0                 1141 	movx	@dptr,a
   03A1                    1142 00112$:
                           1143 ;	convert_serial2.c:274: SUDPTRH = MSB(&myConfigDscr);
   03A1 7E 30              1144 	mov	r6,#_myConfigDscr
   03A3 7F 3D              1145 	mov	r7,#(_myConfigDscr >> 8)
   03A5 8F 06              1146 	mov	ar6,r7
   03A7 90 E6 B3           1147 	mov	dptr,#_SUDPTRH
   03AA EE                 1148 	mov	a,r6
   03AB F0                 1149 	movx	@dptr,a
                           1150 ;	convert_serial2.c:275: SUDPTRL = LSB(&myConfigDscr);
   03AC 7E 30              1151 	mov	r6,#_myConfigDscr
   03AE 7F 3D              1152 	mov	r7,#(_myConfigDscr >> 8)
   03B0 7F 00              1153 	mov	r7,#0x00
   03B2 90 E6 B4           1154 	mov	dptr,#_SUDPTRL
   03B5 EE                 1155 	mov	a,r6
   03B6 F0                 1156 	movx	@dptr,a
                           1157 ;	convert_serial2.c:276: break;
   03B7 02 07 18           1158 	ljmp	00164$
                           1159 ;	convert_serial2.c:277: case GD_STRING:
   03BA                    1160 00113$:
                           1161 ;	convert_serial2.c:278: if (SETUPDAT[2] >= count_array_size((void **) USB_strings)) {
   03BA 90 E6 BA           1162 	mov	dptr,#(_SETUPDAT + 0x0002)
   03BD E0                 1163 	movx	a,@dptr
   03BE FF                 1164 	mov	r7,a
   03BF 90 00 0A           1165 	mov	dptr,#_USB_strings
   03C2 75 F0 40           1166 	mov	b,#0x40
   03C5 C0 07              1167 	push	ar7
   03C7 12 02 39           1168 	lcall	_count_array_size
   03CA AD 82              1169 	mov	r5,dpl
   03CC AE 83              1170 	mov	r6,dph
   03CE D0 07              1171 	pop	ar7
   03D0 7C 00              1172 	mov	r4,#0x00
   03D2 C3                 1173 	clr	c
   03D3 EF                 1174 	mov	a,r7
   03D4 9D                 1175 	subb	a,r5
   03D5 EC                 1176 	mov	a,r4
   03D6 64 80              1177 	xrl	a,#0x80
   03D8 8E F0              1178 	mov	b,r6
   03DA 63 F0 80           1179 	xrl	b,#0x80
   03DD 95 F0              1180 	subb	a,b
   03DF 40 0B              1181 	jc	00179$
                           1182 ;	convert_serial2.c:279: EZUSB_STALL_EP0();
   03E1 90 E6 A0           1183 	mov	dptr,#_EP0CS
   03E4 E0                 1184 	movx	a,@dptr
   03E5 FF                 1185 	mov	r7,a
   03E6 44 01              1186 	orl	a,#0x01
   03E8 F0                 1187 	movx	@dptr,a
   03E9 02 07 18           1188 	ljmp	00164$
                           1189 ;	convert_serial2.c:281: for (i=0; i<31; i++) {
   03EC                    1190 00179$:
   03EC E4                 1191 	clr	a
   03ED F5 13              1192 	mov	_SetupCommand_i_1_21,a
   03EF F5 14              1193 	mov	(_SetupCommand_i_1_21 + 1),a
   03F1                    1194 00116$:
   03F1 C3                 1195 	clr	c
   03F2 E5 13              1196 	mov	a,_SetupCommand_i_1_21
   03F4 94 1F              1197 	subb	a,#0x1F
   03F6 E5 14              1198 	mov	a,(_SetupCommand_i_1_21 + 1)
   03F8 64 80              1199 	xrl	a,#0x80
   03FA 94 80              1200 	subb	a,#0x80
   03FC 50 7B              1201 	jnc	00119$
                           1202 ;	convert_serial2.c:282: if (USB_strings[SETUPDAT[2]][i] == '\0') break;
   03FE 90 E6 BA           1203 	mov	dptr,#(_SETUPDAT + 0x0002)
   0401 E0                 1204 	movx	a,@dptr
   0402 75 F0 03           1205 	mov	b,#0x03
   0405 A4                 1206 	mul	ab
   0406 24 0A              1207 	add	a,#_USB_strings
   0408 F9                 1208 	mov	r1,a
   0409 87 03              1209 	mov	ar3,@r1
   040B 09                 1210 	inc	r1
   040C 87 04              1211 	mov	ar4,@r1
   040E 09                 1212 	inc	r1
   040F 87 05              1213 	mov	ar5,@r1
   0411 19                 1214 	dec	r1
   0412 19                 1215 	dec	r1
   0413 E5 13              1216 	mov	a,_SetupCommand_i_1_21
   0415 2B                 1217 	add	a,r3
   0416 FB                 1218 	mov	r3,a
   0417 E5 14              1219 	mov	a,(_SetupCommand_i_1_21 + 1)
   0419 3C                 1220 	addc	a,r4
   041A FC                 1221 	mov	r4,a
   041B 8B 82              1222 	mov	dpl,r3
   041D 8C 83              1223 	mov	dph,r4
   041F 8D F0              1224 	mov	b,r5
   0421 12 09 40           1225 	lcall	__gptrget
   0424 60 53              1226 	jz	00119$
                           1227 ;	convert_serial2.c:283: EP0BUF[2*i+2] = USB_strings[SETUPDAT[2]][i];
   0426 E5 13              1228 	mov	a,_SetupCommand_i_1_21
   0428 25 E0              1229 	add	a,acc
   042A FD                 1230 	mov	r5,a
   042B 24 02              1231 	add	a,#0x02
   042D 24 40              1232 	add	a,#_EP0BUF
   042F FB                 1233 	mov	r3,a
   0430 E4                 1234 	clr	a
   0431 34 E7              1235 	addc	a,#(_EP0BUF >> 8)
   0433 FC                 1236 	mov	r4,a
   0434 90 E6 BA           1237 	mov	dptr,#(_SETUPDAT + 0x0002)
   0437 E0                 1238 	movx	a,@dptr
   0438 75 F0 03           1239 	mov	b,#0x03
   043B A4                 1240 	mul	ab
   043C 24 0A              1241 	add	a,#_USB_strings
   043E F9                 1242 	mov	r1,a
   043F 87 02              1243 	mov	ar2,@r1
   0441 09                 1244 	inc	r1
   0442 87 06              1245 	mov	ar6,@r1
   0444 09                 1246 	inc	r1
   0445 87 07              1247 	mov	ar7,@r1
   0447 19                 1248 	dec	r1
   0448 19                 1249 	dec	r1
   0449 E5 13              1250 	mov	a,_SetupCommand_i_1_21
   044B 2A                 1251 	add	a,r2
   044C FA                 1252 	mov	r2,a
   044D E5 14              1253 	mov	a,(_SetupCommand_i_1_21 + 1)
   044F 3E                 1254 	addc	a,r6
   0450 FE                 1255 	mov	r6,a
   0451 8A 82              1256 	mov	dpl,r2
   0453 8E 83              1257 	mov	dph,r6
   0455 8F F0              1258 	mov	b,r7
   0457 12 09 40           1259 	lcall	__gptrget
   045A FA                 1260 	mov	r2,a
   045B 8B 82              1261 	mov	dpl,r3
   045D 8C 83              1262 	mov	dph,r4
   045F F0                 1263 	movx	@dptr,a
                           1264 ;	convert_serial2.c:284: EP0BUF[2*i+3] = '\0';
   0460 74 03              1265 	mov	a,#0x03
   0462 2D                 1266 	add	a,r5
   0463 24 40              1267 	add	a,#_EP0BUF
   0465 F5 82              1268 	mov	dpl,a
   0467 E4                 1269 	clr	a
   0468 34 E7              1270 	addc	a,#(_EP0BUF >> 8)
   046A F5 83              1271 	mov	dph,a
   046C E4                 1272 	clr	a
   046D F0                 1273 	movx	@dptr,a
                           1274 ;	convert_serial2.c:281: for (i=0; i<31; i++) {
   046E 05 13              1275 	inc	_SetupCommand_i_1_21
   0470 E4                 1276 	clr	a
   0471 B5 13 02           1277 	cjne	a,_SetupCommand_i_1_21,00236$
   0474 05 14              1278 	inc	(_SetupCommand_i_1_21 + 1)
   0476                    1279 00236$:
   0476 02 03 F1           1280 	ljmp	00116$
   0479                    1281 00119$:
                           1282 ;	convert_serial2.c:286: EP0BUF[0] = 2*i+2;
   0479 E5 13              1283 	mov	a,_SetupCommand_i_1_21
   047B 25 E0              1284 	add	a,acc
   047D FE                 1285 	mov	r6,a
   047E 0E                 1286 	inc	r6
   047F 0E                 1287 	inc	r6
   0480 90 E7 40           1288 	mov	dptr,#_EP0BUF
   0483 EE                 1289 	mov	a,r6
   0484 F0                 1290 	movx	@dptr,a
                           1291 ;	convert_serial2.c:287: EP0BUF[1] = STRING_DSCR;
   0485 90 E7 41           1292 	mov	dptr,#(_EP0BUF + 0x0001)
   0488 74 03              1293 	mov	a,#0x03
   048A F0                 1294 	movx	@dptr,a
                           1295 ;	convert_serial2.c:288: SYNCDELAY; EP0BCH = 0;
   048B 00                 1296 	nop 
   048C 90 E6 8A           1297 	mov	dptr,#_EP0BCH
   048F E4                 1298 	clr	a
   0490 F0                 1299 	movx	@dptr,a
                           1300 ;	convert_serial2.c:289: SYNCDELAY; EP0BCL = 2*i+2;
   0491 00                 1301 	nop 
   0492 90 E6 8B           1302 	mov	dptr,#_EP0BCL
   0495 EE                 1303 	mov	a,r6
   0496 F0                 1304 	movx	@dptr,a
                           1305 ;	convert_serial2.c:291: break;
   0497 02 07 18           1306 	ljmp	00164$
                           1307 ;	convert_serial2.c:292: default:            // Invalid request
   049A                    1308 00123$:
                           1309 ;	convert_serial2.c:293: EZUSB_STALL_EP0();
   049A 90 E6 A0           1310 	mov	dptr,#_EP0CS
   049D E0                 1311 	movx	a,@dptr
   049E FF                 1312 	mov	r7,a
   049F 44 01              1313 	orl	a,#0x01
   04A1 F0                 1314 	movx	@dptr,a
                           1315 ;	convert_serial2.c:295: break;
   04A2 02 07 18           1316 	ljmp	00164$
                           1317 ;	convert_serial2.c:296: case SC_GET_INTERFACE:
   04A5                    1318 00125$:
                           1319 ;	convert_serial2.c:297: interface = SETUPDAT[4];
   04A5 90 E6 BC           1320 	mov	dptr,#(_SETUPDAT + 0x0004)
   04A8 E0                 1321 	movx	a,@dptr
   04A9 FE                 1322 	mov	r6,a
   04AA 7F 00              1323 	mov	r7,#0x00
                           1324 ;	convert_serial2.c:298: if (interface < NUM_INTERFACES) {
   04AC C3                 1325 	clr	c
   04AD EE                 1326 	mov	a,r6
   04AE 94 01              1327 	subb	a,#0x01
   04B0 EF                 1328 	mov	a,r7
   04B1 64 80              1329 	xrl	a,#0x80
   04B3 94 80              1330 	subb	a,#0x80
   04B5 40 03              1331 	jc	00237$
   04B7 02 07 18           1332 	ljmp	00164$
   04BA                    1333 00237$:
                           1334 ;	convert_serial2.c:299: EP0BUF[0] = InterfaceSetting[interface];
   04BA EE                 1335 	mov	a,r6
   04BB 24 09              1336 	add	a,#_InterfaceSetting
   04BD F9                 1337 	mov	r1,a
   04BE 87 05              1338 	mov	ar5,@r1
   04C0 90 E7 40           1339 	mov	dptr,#_EP0BUF
   04C3 ED                 1340 	mov	a,r5
   04C4 F0                 1341 	movx	@dptr,a
                           1342 ;	convert_serial2.c:300: EP0BCH = 0;
   04C5 90 E6 8A           1343 	mov	dptr,#_EP0BCH
   04C8 E4                 1344 	clr	a
   04C9 F0                 1345 	movx	@dptr,a
                           1346 ;	convert_serial2.c:301: EP0BCL = 1;
   04CA 90 E6 8B           1347 	mov	dptr,#_EP0BCL
   04CD 74 01              1348 	mov	a,#0x01
   04CF F0                 1349 	movx	@dptr,a
                           1350 ;	convert_serial2.c:303: break;
   04D0 02 07 18           1351 	ljmp	00164$
                           1352 ;	convert_serial2.c:304: case SC_SET_INTERFACE:
   04D3                    1353 00128$:
                           1354 ;	convert_serial2.c:305: interface = SETUPDAT[4];
   04D3 90 E6 BC           1355 	mov	dptr,#(_SETUPDAT + 0x0004)
   04D6 E0                 1356 	movx	a,@dptr
   04D7 FD                 1357 	mov	r5,a
   04D8 FE                 1358 	mov	r6,a
   04D9 7F 00              1359 	mov	r7,#0x00
                           1360 ;	convert_serial2.c:306: if (interface < NUM_INTERFACES) {
   04DB C3                 1361 	clr	c
   04DC EE                 1362 	mov	a,r6
   04DD 94 01              1363 	subb	a,#0x01
   04DF EF                 1364 	mov	a,r7
   04E0 64 80              1365 	xrl	a,#0x80
   04E2 94 80              1366 	subb	a,#0x80
   04E4 40 03              1367 	jc	00238$
   04E6 02 07 18           1368 	ljmp	00164$
   04E9                    1369 00238$:
                           1370 ;	convert_serial2.c:307: InterfaceSetting[interface] = SETUPDAT[2];
   04E9 EE                 1371 	mov	a,r6
   04EA 24 09              1372 	add	a,#_InterfaceSetting
   04EC F9                 1373 	mov	r1,a
   04ED 90 E6 BA           1374 	mov	dptr,#(_SETUPDAT + 0x0002)
   04F0 E0                 1375 	movx	a,@dptr
   04F1 FF                 1376 	mov	r7,a
   04F2 F7                 1377 	mov	@r1,a
                           1378 ;	convert_serial2.c:309: break;
   04F3 02 07 18           1379 	ljmp	00164$
                           1380 ;	convert_serial2.c:310: case SC_SET_CONFIGURATION:
   04F6                    1381 00131$:
                           1382 ;	convert_serial2.c:311: Configuration = SETUPDAT[2];
   04F6 90 E6 BA           1383 	mov	dptr,#(_SETUPDAT + 0x0002)
   04F9 E0                 1384 	movx	a,@dptr
   04FA F5 08              1385 	mov	_Configuration,a
                           1386 ;	convert_serial2.c:312: break;
   04FC 02 07 18           1387 	ljmp	00164$
                           1388 ;	convert_serial2.c:313: case SC_GET_CONFIGURATION:
   04FF                    1389 00132$:
                           1390 ;	convert_serial2.c:314: EP0BUF[0] = Configuration;
   04FF 90 E7 40           1391 	mov	dptr,#_EP0BUF
   0502 E5 08              1392 	mov	a,_Configuration
   0504 F0                 1393 	movx	@dptr,a
                           1394 ;	convert_serial2.c:315: EP0BCH = 0;
   0505 90 E6 8A           1395 	mov	dptr,#_EP0BCH
   0508 E4                 1396 	clr	a
   0509 F0                 1397 	movx	@dptr,a
                           1398 ;	convert_serial2.c:316: EP0BCL = 1;
   050A 90 E6 8B           1399 	mov	dptr,#_EP0BCL
   050D 74 01              1400 	mov	a,#0x01
   050F F0                 1401 	movx	@dptr,a
                           1402 ;	convert_serial2.c:317: break;
   0510 02 07 18           1403 	ljmp	00164$
                           1404 ;	convert_serial2.c:318: case SC_GET_STATUS:
   0513                    1405 00133$:
                           1406 ;	convert_serial2.c:319: switch(SETUPDAT[0])
   0513 90 E6 B8           1407 	mov	dptr,#_SETUPDAT
   0516 E0                 1408 	movx	a,@dptr
   0517 FF                 1409 	mov	r7,a
   0518 BF 80 02           1410 	cjne	r7,#0x80,00239$
   051B 80 0D              1411 	sjmp	00134$
   051D                    1412 00239$:
   051D BF 81 02           1413 	cjne	r7,#0x81,00240$
   0520 80 2D              1414 	sjmp	00135$
   0522                    1415 00240$:
   0522 BF 82 02           1416 	cjne	r7,#0x82,00241$
   0525 80 3E              1417 	sjmp	00136$
   0527                    1418 00241$:
   0527 02 05 AA           1419 	ljmp	00137$
                           1420 ;	convert_serial2.c:321: case GS_DEVICE:
   052A                    1421 00134$:
                           1422 ;	convert_serial2.c:322: EP0BUF[0] = ((BYTE)Rwuen << 1) | (BYTE)Selfpwr;
   052A A2 01              1423 	mov	c,_Rwuen
   052C E4                 1424 	clr	a
   052D 33                 1425 	rlc	a
   052E 25 E0              1426 	add	a,acc
   0530 FF                 1427 	mov	r7,a
   0531 A2 02              1428 	mov	c,_Selfpwr
   0533 E4                 1429 	clr	a
   0534 33                 1430 	rlc	a
   0535 FE                 1431 	mov	r6,a
   0536 42 07              1432 	orl	ar7,a
   0538 90 E7 40           1433 	mov	dptr,#_EP0BUF
   053B EF                 1434 	mov	a,r7
   053C F0                 1435 	movx	@dptr,a
                           1436 ;	convert_serial2.c:323: EP0BUF[1] = 0;
   053D 90 E7 41           1437 	mov	dptr,#(_EP0BUF + 0x0001)
                           1438 ;	convert_serial2.c:324: EP0BCH = 0;
   0540 E4                 1439 	clr	a
   0541 F0                 1440 	movx	@dptr,a
   0542 90 E6 8A           1441 	mov	dptr,#_EP0BCH
   0545 F0                 1442 	movx	@dptr,a
                           1443 ;	convert_serial2.c:325: EP0BCL = 2;
   0546 90 E6 8B           1444 	mov	dptr,#_EP0BCL
   0549 74 02              1445 	mov	a,#0x02
   054B F0                 1446 	movx	@dptr,a
                           1447 ;	convert_serial2.c:326: break;
   054C 02 07 18           1448 	ljmp	00164$
                           1449 ;	convert_serial2.c:327: case GS_INTERFACE:
   054F                    1450 00135$:
                           1451 ;	convert_serial2.c:328: EP0BUF[0] = 0;
   054F 90 E7 40           1452 	mov	dptr,#_EP0BUF
                           1453 ;	convert_serial2.c:329: EP0BUF[1] = 0;
                           1454 ;	convert_serial2.c:330: EP0BCH = 0;
   0552 E4                 1455 	clr	a
   0553 F0                 1456 	movx	@dptr,a
   0554 90 E7 41           1457 	mov	dptr,#(_EP0BUF + 0x0001)
   0557 F0                 1458 	movx	@dptr,a
   0558 90 E6 8A           1459 	mov	dptr,#_EP0BCH
   055B F0                 1460 	movx	@dptr,a
                           1461 ;	convert_serial2.c:331: EP0BCL = 2;
   055C 90 E6 8B           1462 	mov	dptr,#_EP0BCL
   055F 74 02              1463 	mov	a,#0x02
   0561 F0                 1464 	movx	@dptr,a
                           1465 ;	convert_serial2.c:332: break;
   0562 02 07 18           1466 	ljmp	00164$
                           1467 ;	convert_serial2.c:333: case GS_ENDPOINT:
   0565                    1468 00136$:
                           1469 ;	convert_serial2.c:334: EP0BUF[0] = *(BYTE xdata *) epcs(SETUPDAT[4]) & bmEPSTALL;
   0565 90 E6 BC           1470 	mov	dptr,#(_SETUPDAT + 0x0004)
   0568 E0                 1471 	movx	a,@dptr
   0569 FF                 1472 	mov	r7,a
   056A 53 07 7E           1473 	anl	ar7,#0x7E
   056D 90 E6 BC           1474 	mov	dptr,#(_SETUPDAT + 0x0004)
   0570 E0                 1475 	movx	a,@dptr
   0571 FE                 1476 	mov	r6,a
   0572 C3                 1477 	clr	c
   0573 74 80              1478 	mov	a,#0x80
   0575 9E                 1479 	subb	a,r6
   0576 E4                 1480 	clr	a
   0577 33                 1481 	rlc	a
   0578 4F                 1482 	orl	a,r7
   0579 90 09 60           1483 	mov	dptr,#_EPCS_Offset_Lookup_Table
   057C 93                 1484 	movc	a,@a+dptr
   057D FF                 1485 	mov	r7,a
   057E 33                 1486 	rlc	a
   057F 95 E0              1487 	subb	a,acc
   0581 FE                 1488 	mov	r6,a
   0582 74 A1              1489 	mov	a,#0xA1
   0584 2F                 1490 	add	a,r7
   0585 FF                 1491 	mov	r7,a
   0586 74 E6              1492 	mov	a,#0xE6
   0588 3E                 1493 	addc	a,r6
   0589 FE                 1494 	mov	r6,a
   058A 8F 82              1495 	mov	dpl,r7
   058C 8E 83              1496 	mov	dph,r6
   058E E0                 1497 	movx	a,@dptr
   058F FF                 1498 	mov	r7,a
   0590 53 07 01           1499 	anl	ar7,#0x01
   0593 90 E7 40           1500 	mov	dptr,#_EP0BUF
   0596 EF                 1501 	mov	a,r7
   0597 F0                 1502 	movx	@dptr,a
                           1503 ;	convert_serial2.c:335: EP0BUF[1] = 0;
   0598 90 E7 41           1504 	mov	dptr,#(_EP0BUF + 0x0001)
                           1505 ;	convert_serial2.c:336: EP0BCH = 0;
   059B E4                 1506 	clr	a
   059C F0                 1507 	movx	@dptr,a
   059D 90 E6 8A           1508 	mov	dptr,#_EP0BCH
   05A0 F0                 1509 	movx	@dptr,a
                           1510 ;	convert_serial2.c:337: EP0BCL = 2;
   05A1 90 E6 8B           1511 	mov	dptr,#_EP0BCL
   05A4 74 02              1512 	mov	a,#0x02
   05A6 F0                 1513 	movx	@dptr,a
                           1514 ;	convert_serial2.c:338: break;
   05A7 02 07 18           1515 	ljmp	00164$
                           1516 ;	convert_serial2.c:339: default:            // Invalid Command
   05AA                    1517 00137$:
                           1518 ;	convert_serial2.c:340: EZUSB_STALL_EP0();
   05AA 90 E6 A0           1519 	mov	dptr,#_EP0CS
   05AD E0                 1520 	movx	a,@dptr
   05AE FF                 1521 	mov	r7,a
   05AF 44 01              1522 	orl	a,#0x01
   05B1 F0                 1523 	movx	@dptr,a
                           1524 ;	convert_serial2.c:342: break;
   05B2 02 07 18           1525 	ljmp	00164$
                           1526 ;	convert_serial2.c:343: case SC_CLEAR_FEATURE:
   05B5                    1527 00139$:
                           1528 ;	convert_serial2.c:344: switch(SETUPDAT[0])
   05B5 90 E6 B8           1529 	mov	dptr,#_SETUPDAT
   05B8 E0                 1530 	movx	a,@dptr
   05B9 FF                 1531 	mov	r7,a
   05BA 60 08              1532 	jz	00140$
   05BC BF 02 02           1533 	cjne	r7,#0x02,00243$
   05BF 80 1B              1534 	sjmp	00144$
   05C1                    1535 00243$:
   05C1 02 07 18           1536 	ljmp	00164$
                           1537 ;	convert_serial2.c:346: case FT_DEVICE:
   05C4                    1538 00140$:
                           1539 ;	convert_serial2.c:347: if(SETUPDAT[2] == 1)
   05C4 90 E6 BA           1540 	mov	dptr,#(_SETUPDAT + 0x0002)
   05C7 E0                 1541 	movx	a,@dptr
   05C8 FF                 1542 	mov	r7,a
   05C9 BF 01 05           1543 	cjne	r7,#0x01,00142$
                           1544 ;	convert_serial2.c:348: Rwuen = FALSE;       // Disable Remote Wakeup
   05CC C2 01              1545 	clr	_Rwuen
   05CE 02 07 18           1546 	ljmp	00164$
   05D1                    1547 00142$:
                           1548 ;	convert_serial2.c:350: EZUSB_STALL_EP0();
   05D1 90 E6 A0           1549 	mov	dptr,#_EP0CS
   05D4 E0                 1550 	movx	a,@dptr
   05D5 FF                 1551 	mov	r7,a
   05D6 44 01              1552 	orl	a,#0x01
   05D8 F0                 1553 	movx	@dptr,a
                           1554 ;	convert_serial2.c:351: break;
   05D9 02 07 18           1555 	ljmp	00164$
                           1556 ;	convert_serial2.c:352: case FT_ENDPOINT:
   05DC                    1557 00144$:
                           1558 ;	convert_serial2.c:353: if(SETUPDAT[2] == 0)
   05DC 90 E6 BA           1559 	mov	dptr,#(_SETUPDAT + 0x0002)
   05DF E0                 1560 	movx	a,@dptr
   05E0 60 03              1561 	jz	00246$
   05E2 02 06 61           1562 	ljmp	00146$
   05E5                    1563 00246$:
                           1564 ;	convert_serial2.c:355: *(BYTE xdata *) epcs(SETUPDAT[4]) &= ~bmEPSTALL;
   05E5 90 E6 BC           1565 	mov	dptr,#(_SETUPDAT + 0x0004)
   05E8 E0                 1566 	movx	a,@dptr
   05E9 FF                 1567 	mov	r7,a
   05EA 53 07 7E           1568 	anl	ar7,#0x7E
   05ED 90 E6 BC           1569 	mov	dptr,#(_SETUPDAT + 0x0004)
   05F0 E0                 1570 	movx	a,@dptr
   05F1 FE                 1571 	mov	r6,a
   05F2 C3                 1572 	clr	c
   05F3 74 80              1573 	mov	a,#0x80
   05F5 9E                 1574 	subb	a,r6
   05F6 E4                 1575 	clr	a
   05F7 33                 1576 	rlc	a
   05F8 4F                 1577 	orl	a,r7
   05F9 90 09 60           1578 	mov	dptr,#_EPCS_Offset_Lookup_Table
   05FC 93                 1579 	movc	a,@a+dptr
   05FD FF                 1580 	mov	r7,a
   05FE 33                 1581 	rlc	a
   05FF 95 E0              1582 	subb	a,acc
   0601 FE                 1583 	mov	r6,a
   0602 74 A1              1584 	mov	a,#0xA1
   0604 2F                 1585 	add	a,r7
   0605 FF                 1586 	mov	r7,a
   0606 74 E6              1587 	mov	a,#0xE6
   0608 3E                 1588 	addc	a,r6
   0609 FE                 1589 	mov	r6,a
   060A 90 E6 BC           1590 	mov	dptr,#(_SETUPDAT + 0x0004)
   060D E0                 1591 	movx	a,@dptr
   060E FD                 1592 	mov	r5,a
   060F 53 05 7E           1593 	anl	ar5,#0x7E
   0612 90 E6 BC           1594 	mov	dptr,#(_SETUPDAT + 0x0004)
   0615 E0                 1595 	movx	a,@dptr
   0616 FC                 1596 	mov	r4,a
   0617 C3                 1597 	clr	c
   0618 74 80              1598 	mov	a,#0x80
   061A 9C                 1599 	subb	a,r4
   061B E4                 1600 	clr	a
   061C 33                 1601 	rlc	a
   061D 4D                 1602 	orl	a,r5
   061E 90 09 60           1603 	mov	dptr,#_EPCS_Offset_Lookup_Table
   0621 93                 1604 	movc	a,@a+dptr
   0622 FD                 1605 	mov	r5,a
   0623 33                 1606 	rlc	a
   0624 95 E0              1607 	subb	a,acc
   0626 FC                 1608 	mov	r4,a
   0627 74 A1              1609 	mov	a,#0xA1
   0629 2D                 1610 	add	a,r5
   062A FD                 1611 	mov	r5,a
   062B 74 E6              1612 	mov	a,#0xE6
   062D 3C                 1613 	addc	a,r4
   062E FC                 1614 	mov	r4,a
   062F 8D 82              1615 	mov	dpl,r5
   0631 8C 83              1616 	mov	dph,r4
   0633 E0                 1617 	movx	a,@dptr
   0634 FD                 1618 	mov	r5,a
   0635 53 05 FE           1619 	anl	ar5,#0xFE
   0638 8F 82              1620 	mov	dpl,r7
   063A 8E 83              1621 	mov	dph,r6
   063C ED                 1622 	mov	a,r5
   063D F0                 1623 	movx	@dptr,a
                           1624 ;	convert_serial2.c:356: EZUSB_RESET_DATA_TOGGLE( SETUPDAT[4] );
   063E 90 E6 BC           1625 	mov	dptr,#(_SETUPDAT + 0x0004)
   0641 E0                 1626 	movx	a,@dptr
   0642 54 80              1627 	anl	a,#0x80
   0644 C4                 1628 	swap	a
   0645 23                 1629 	rl	a
   0646 54 1F              1630 	anl	a,#0x1F
   0648 FF                 1631 	mov	r7,a
   0649 90 E6 BC           1632 	mov	dptr,#(_SETUPDAT + 0x0004)
   064C E0                 1633 	movx	a,@dptr
   064D FE                 1634 	mov	r6,a
   064E 74 0F              1635 	mov	a,#0x0F
   0650 5E                 1636 	anl	a,r6
   0651 90 E6 83           1637 	mov	dptr,#_TOGCTL
   0654 2F                 1638 	add	a,r7
   0655 F0                 1639 	movx	@dptr,a
   0656 90 E6 83           1640 	mov	dptr,#_TOGCTL
   0659 E0                 1641 	movx	a,@dptr
   065A FF                 1642 	mov	r7,a
   065B 44 20              1643 	orl	a,#0x20
   065D F0                 1644 	movx	@dptr,a
   065E 02 07 18           1645 	ljmp	00164$
   0661                    1646 00146$:
                           1647 ;	convert_serial2.c:359: EZUSB_STALL_EP0();
   0661 90 E6 A0           1648 	mov	dptr,#_EP0CS
   0664 E0                 1649 	movx	a,@dptr
   0665 FF                 1650 	mov	r7,a
   0666 44 01              1651 	orl	a,#0x01
   0668 F0                 1652 	movx	@dptr,a
                           1653 ;	convert_serial2.c:362: break;
   0669 02 07 18           1654 	ljmp	00164$
                           1655 ;	convert_serial2.c:363: case SC_SET_FEATURE:
   066C                    1656 00149$:
                           1657 ;	convert_serial2.c:364: switch(SETUPDAT[0])
   066C 90 E6 B8           1658 	mov	dptr,#_SETUPDAT
   066F E0                 1659 	movx	a,@dptr
   0670 FF                 1660 	mov	r7,a
   0671 60 08              1661 	jz	00150$
   0673 BF 02 02           1662 	cjne	r7,#0x02,00248$
   0676 80 29              1663 	sjmp	00158$
   0678                    1664 00248$:
   0678 02 06 FC           1665 	ljmp	00159$
                           1666 ;	convert_serial2.c:366: case FT_DEVICE:
   067B                    1667 00150$:
                           1668 ;	convert_serial2.c:367: if((SETUPDAT[2] == 1) && Rwuen_allowed)
   067B 90 E6 BA           1669 	mov	dptr,#(_SETUPDAT + 0x0002)
   067E E0                 1670 	movx	a,@dptr
   067F FF                 1671 	mov	r7,a
   0680 BF 01 08           1672 	cjne	r7,#0x01,00155$
   0683 30 00 05           1673 	jnb	_Rwuen_allowed,00155$
                           1674 ;	convert_serial2.c:368: Rwuen = TRUE;      // Enable Remote Wakeup
   0686 D2 01              1675 	setb	_Rwuen
   0688 02 07 18           1676 	ljmp	00164$
   068B                    1677 00155$:
                           1678 ;	convert_serial2.c:369: else if(SETUPDAT[2] == 2)
   068B 90 E6 BA           1679 	mov	dptr,#(_SETUPDAT + 0x0002)
   068E E0                 1680 	movx	a,@dptr
   068F FF                 1681 	mov	r7,a
   0690 BF 02 03           1682 	cjne	r7,#0x02,00252$
   0693 02 07 18           1683 	ljmp	00164$
   0696                    1684 00252$:
                           1685 ;	convert_serial2.c:379: EZUSB_STALL_EP0();
   0696 90 E6 A0           1686 	mov	dptr,#_EP0CS
   0699 E0                 1687 	movx	a,@dptr
   069A FF                 1688 	mov	r7,a
   069B 44 01              1689 	orl	a,#0x01
   069D F0                 1690 	movx	@dptr,a
                           1691 ;	convert_serial2.c:380: break;
   069E 02 07 18           1692 	ljmp	00164$
                           1693 ;	convert_serial2.c:381: case FT_ENDPOINT:
   06A1                    1694 00158$:
                           1695 ;	convert_serial2.c:382: *(BYTE xdata *) epcs(SETUPDAT[4]) |= bmEPSTALL;
   06A1 90 E6 BC           1696 	mov	dptr,#(_SETUPDAT + 0x0004)
   06A4 E0                 1697 	movx	a,@dptr
   06A5 FF                 1698 	mov	r7,a
   06A6 53 07 7E           1699 	anl	ar7,#0x7E
   06A9 90 E6 BC           1700 	mov	dptr,#(_SETUPDAT + 0x0004)
   06AC E0                 1701 	movx	a,@dptr
   06AD FE                 1702 	mov	r6,a
   06AE C3                 1703 	clr	c
   06AF 74 80              1704 	mov	a,#0x80
   06B1 9E                 1705 	subb	a,r6
   06B2 E4                 1706 	clr	a
   06B3 33                 1707 	rlc	a
   06B4 4F                 1708 	orl	a,r7
   06B5 90 09 60           1709 	mov	dptr,#_EPCS_Offset_Lookup_Table
   06B8 93                 1710 	movc	a,@a+dptr
   06B9 FF                 1711 	mov	r7,a
   06BA 33                 1712 	rlc	a
   06BB 95 E0              1713 	subb	a,acc
   06BD FE                 1714 	mov	r6,a
   06BE 74 A1              1715 	mov	a,#0xA1
   06C0 2F                 1716 	add	a,r7
   06C1 FF                 1717 	mov	r7,a
   06C2 74 E6              1718 	mov	a,#0xE6
   06C4 3E                 1719 	addc	a,r6
   06C5 FE                 1720 	mov	r6,a
   06C6 90 E6 BC           1721 	mov	dptr,#(_SETUPDAT + 0x0004)
   06C9 E0                 1722 	movx	a,@dptr
   06CA FD                 1723 	mov	r5,a
   06CB 53 05 7E           1724 	anl	ar5,#0x7E
   06CE 90 E6 BC           1725 	mov	dptr,#(_SETUPDAT + 0x0004)
   06D1 E0                 1726 	movx	a,@dptr
   06D2 FC                 1727 	mov	r4,a
   06D3 C3                 1728 	clr	c
   06D4 74 80              1729 	mov	a,#0x80
   06D6 9C                 1730 	subb	a,r4
   06D7 E4                 1731 	clr	a
   06D8 33                 1732 	rlc	a
   06D9 4D                 1733 	orl	a,r5
   06DA 90 09 60           1734 	mov	dptr,#_EPCS_Offset_Lookup_Table
   06DD 93                 1735 	movc	a,@a+dptr
   06DE FD                 1736 	mov	r5,a
   06DF 33                 1737 	rlc	a
   06E0 95 E0              1738 	subb	a,acc
   06E2 FC                 1739 	mov	r4,a
   06E3 74 A1              1740 	mov	a,#0xA1
   06E5 2D                 1741 	add	a,r5
   06E6 FD                 1742 	mov	r5,a
   06E7 74 E6              1743 	mov	a,#0xE6
   06E9 3C                 1744 	addc	a,r4
   06EA FC                 1745 	mov	r4,a
   06EB 8D 82              1746 	mov	dpl,r5
   06ED 8C 83              1747 	mov	dph,r4
   06EF E0                 1748 	movx	a,@dptr
   06F0 FD                 1749 	mov	r5,a
   06F1 43 05 01           1750 	orl	ar5,#0x01
   06F4 8F 82              1751 	mov	dpl,r7
   06F6 8E 83              1752 	mov	dph,r6
   06F8 ED                 1753 	mov	a,r5
   06F9 F0                 1754 	movx	@dptr,a
                           1755 ;	convert_serial2.c:383: break;
                           1756 ;	convert_serial2.c:384: default:
   06FA 80 1C              1757 	sjmp	00164$
   06FC                    1758 00159$:
                           1759 ;	convert_serial2.c:385: EZUSB_STALL_EP0();
   06FC 90 E6 A0           1760 	mov	dptr,#_EP0CS
   06FF E0                 1761 	movx	a,@dptr
   0700 FF                 1762 	mov	r7,a
   0701 44 01              1763 	orl	a,#0x01
   0703 F0                 1764 	movx	@dptr,a
                           1765 ;	convert_serial2.c:387: break;
                           1766 ;	convert_serial2.c:388: default:                     // *** Invalid Command
   0704 80 12              1767 	sjmp	00164$
   0706                    1768 00161$:
                           1769 ;	convert_serial2.c:389: EZUSB_STALL_EP0();
   0706 90 E6 A0           1770 	mov	dptr,#_EP0CS
   0709 E0                 1771 	movx	a,@dptr
   070A FF                 1772 	mov	r7,a
   070B 44 01              1773 	orl	a,#0x01
   070D F0                 1774 	movx	@dptr,a
                           1775 ;	convert_serial2.c:392: break;
                           1776 ;	convert_serial2.c:394: default:
   070E 80 08              1777 	sjmp	00164$
   0710                    1778 00163$:
                           1779 ;	convert_serial2.c:395: EZUSB_STALL_EP0();
   0710 90 E6 A0           1780 	mov	dptr,#_EP0CS
   0713 E0                 1781 	movx	a,@dptr
   0714 FF                 1782 	mov	r7,a
   0715 44 01              1783 	orl	a,#0x01
   0717 F0                 1784 	movx	@dptr,a
                           1785 ;	convert_serial2.c:397: }
   0718                    1786 00164$:
                           1787 ;	convert_serial2.c:400: EP0CS |= bmHSNAK;
   0718 90 E6 A0           1788 	mov	dptr,#_EP0CS
   071B E0                 1789 	movx	a,@dptr
   071C 44 80              1790 	orl	a,#0x80
   071E F0                 1791 	movx	@dptr,a
   071F 22                 1792 	ret
                           1793 ;------------------------------------------------------------
                           1794 ;Allocation info for local variables in function 'USB_isr'
                           1795 ;------------------------------------------------------------
                           1796 ;	convert_serial2.c:403: static void USB_isr(void) __interrupt 8
                           1797 ;	-----------------------------------------
                           1798 ;	 function USB_isr
                           1799 ;	-----------------------------------------
   0720                    1800 _USB_isr:
   0720 C0 21              1801 	push	bits
   0722 C0 E0              1802 	push	acc
   0724 C0 F0              1803 	push	b
   0726 C0 82              1804 	push	dpl
   0728 C0 83              1805 	push	dph
   072A C0 07              1806 	push	(0+7)
   072C C0 06              1807 	push	(0+6)
   072E C0 05              1808 	push	(0+5)
   0730 C0 04              1809 	push	(0+4)
   0732 C0 03              1810 	push	(0+3)
   0734 C0 02              1811 	push	(0+2)
   0736 C0 01              1812 	push	(0+1)
   0738 C0 00              1813 	push	(0+0)
   073A C0 D0              1814 	push	psw
   073C 75 D0 00           1815 	mov	psw,#0x00
                           1816 ;	convert_serial2.c:406: EXIF &= ~0x10;
   073F AF 91              1817 	mov	r7,_EXIF
   0741 74 EF              1818 	mov	a,#0xEF
   0743 5F                 1819 	anl	a,r7
   0744 F5 91              1820 	mov	_EXIF,a
                           1821 ;	convert_serial2.c:409: USBIRQ = 0x01;
   0746 90 E6 5D           1822 	mov	dptr,#_USBIRQ
   0749 74 01              1823 	mov	a,#0x01
   074B F0                 1824 	movx	@dptr,a
                           1825 ;	convert_serial2.c:411: SetupCommand();
   074C 12 02 84           1826 	lcall	_SetupCommand
   074F D0 D0              1827 	pop	psw
   0751 D0 00              1828 	pop	(0+0)
   0753 D0 01              1829 	pop	(0+1)
   0755 D0 02              1830 	pop	(0+2)
   0757 D0 03              1831 	pop	(0+3)
   0759 D0 04              1832 	pop	(0+4)
   075B D0 05              1833 	pop	(0+5)
   075D D0 06              1834 	pop	(0+6)
   075F D0 07              1835 	pop	(0+7)
   0761 D0 83              1836 	pop	dph
   0763 D0 82              1837 	pop	dpl
   0765 D0 F0              1838 	pop	b
   0767 D0 E0              1839 	pop	acc
   0769 D0 21              1840 	pop	bits
   076B 32                 1841 	reti
                           1842 ;------------------------------------------------------------
                           1843 ;Allocation info for local variables in function 'Initialize'
                           1844 ;------------------------------------------------------------
                           1845 ;	convert_serial2.c:418: static void Initialize(void)
                           1846 ;	-----------------------------------------
                           1847 ;	 function Initialize
                           1848 ;	-----------------------------------------
   076C                    1849 _Initialize:
                           1850 ;	convert_serial2.c:426: IFCONFIG=0xc0;  // Internal IFCLK, 48MHz; A,B as normal ports. 
   076C 90 E6 01           1851 	mov	dptr,#_IFCONFIG
   076F 74 C0              1852 	mov	a,#0xC0
   0771 F0                 1853 	movx	@dptr,a
                           1854 ;	convert_serial2.c:427: SYNCDELAY;
   0772 00                 1855 	nop 
                           1856 ;	convert_serial2.c:429: REVCTL=0x03;  // See TRM...
   0773 90 E6 0B           1857 	mov	dptr,#_REVCTL
   0776 74 03              1858 	mov	a,#0x03
   0778 F0                 1859 	movx	@dptr,a
                           1860 ;	convert_serial2.c:430: SYNCDELAY;
   0779 00                 1861 	nop 
                           1862 ;	convert_serial2.c:432: EP1OUTCFG=0;
   077A 90 E6 10           1863 	mov	dptr,#_EP1OUTCFG
                           1864 ;	convert_serial2.c:433: EP1INCFG=0;
                           1865 ;	convert_serial2.c:434: EP4CFG=0;
                           1866 ;	convert_serial2.c:435: EP8CFG=0;
   077D E4                 1867 	clr	a
   077E F0                 1868 	movx	@dptr,a
   077F 90 E6 11           1869 	mov	dptr,#_EP1INCFG
   0782 F0                 1870 	movx	@dptr,a
   0783 90 E6 13           1871 	mov	dptr,#_EP4CFG
   0786 F0                 1872 	movx	@dptr,a
   0787 90 E6 15           1873 	mov	dptr,#_EP8CFG
   078A F0                 1874 	movx	@dptr,a
                           1875 ;	convert_serial2.c:438: EP6CFG=0xe0;   // 1110 0000  (IN)
   078B 90 E6 14           1876 	mov	dptr,#_EP6CFG
   078E 74 E0              1877 	mov	a,#0xE0
   0790 F0                 1878 	movx	@dptr,a
                           1879 ;	convert_serial2.c:439: EP2CFG=0xa0;   // 1010 0000  (OUT)
   0791 90 E6 12           1880 	mov	dptr,#_EP2CFG
   0794 74 A0              1881 	mov	a,#0xA0
   0796 F0                 1882 	movx	@dptr,a
                           1883 ;	convert_serial2.c:443: FIFORESET = 0x80;  SYNCDELAY;  // NAK all requests from host. 
   0797 90 E6 04           1884 	mov	dptr,#_FIFORESET
   079A 74 80              1885 	mov	a,#0x80
   079C F0                 1886 	movx	@dptr,a
   079D 00                 1887 	nop 
                           1888 ;	convert_serial2.c:444: FIFORESET = 0x82;  SYNCDELAY;  // Reset individual EP (2,4,6,8)
   079E 90 E6 04           1889 	mov	dptr,#_FIFORESET
   07A1 74 82              1890 	mov	a,#0x82
   07A3 F0                 1891 	movx	@dptr,a
   07A4 00                 1892 	nop 
                           1893 ;	convert_serial2.c:445: FIFORESET = 0x84;  SYNCDELAY;
   07A5 90 E6 04           1894 	mov	dptr,#_FIFORESET
   07A8 74 84              1895 	mov	a,#0x84
   07AA F0                 1896 	movx	@dptr,a
   07AB 00                 1897 	nop 
                           1898 ;	convert_serial2.c:446: FIFORESET = 0x86;  SYNCDELAY;
   07AC 90 E6 04           1899 	mov	dptr,#_FIFORESET
   07AF 74 86              1900 	mov	a,#0x86
   07B1 F0                 1901 	movx	@dptr,a
   07B2 00                 1902 	nop 
                           1903 ;	convert_serial2.c:447: FIFORESET = 0x88;  SYNCDELAY;
   07B3 90 E6 04           1904 	mov	dptr,#_FIFORESET
   07B6 74 88              1905 	mov	a,#0x88
   07B8 F0                 1906 	movx	@dptr,a
   07B9 00                 1907 	nop 
                           1908 ;	convert_serial2.c:448: FIFORESET = 0x80;  SYNCDELAY;  // NAK all requests from host. 
   07BA 90 E6 04           1909 	mov	dptr,#_FIFORESET
   07BD 74 80              1910 	mov	a,#0x80
   07BF F0                 1911 	movx	@dptr,a
   07C0 00                 1912 	nop 
                           1913 ;	convert_serial2.c:449: FIFORESET = 0x00;  SYNCDELAY;  // Resume normal operation. 
   07C1 90 E6 04           1914 	mov	dptr,#_FIFORESET
   07C4 E4                 1915 	clr	a
   07C5 F0                 1916 	movx	@dptr,a
   07C6 00                 1917 	nop 
                           1918 ;	convert_serial2.c:452: OUTPKTEND = 0x82; SYNCDELAY;
   07C7 90 E6 49           1919 	mov	dptr,#_OUTPKTEND
   07CA 74 82              1920 	mov	a,#0x82
   07CC F0                 1921 	movx	@dptr,a
   07CD 00                 1922 	nop 
                           1923 ;	convert_serial2.c:453: OUTPKTEND = 0x82; SYNCDELAY;
   07CE 90 E6 49           1924 	mov	dptr,#_OUTPKTEND
   07D1 74 82              1925 	mov	a,#0x82
   07D3 F0                 1926 	movx	@dptr,a
   07D4 00                 1927 	nop 
                           1928 ;	convert_serial2.c:454: OUTPKTEND = 0x82; SYNCDELAY;
   07D5 90 E6 49           1929 	mov	dptr,#_OUTPKTEND
   07D8 74 82              1930 	mov	a,#0x82
   07DA F0                 1931 	movx	@dptr,a
   07DB 00                 1932 	nop 
                           1933 ;	convert_serial2.c:456: INPKTEND = 0x86; SYNCDELAY;
   07DC 90 E6 48           1934 	mov	dptr,#_INPKTEND
   07DF 74 86              1935 	mov	a,#0x86
   07E1 F0                 1936 	movx	@dptr,a
   07E2 00                 1937 	nop 
                           1938 ;	convert_serial2.c:457: INPKTEND = 0x86; SYNCDELAY;
   07E3 90 E6 48           1939 	mov	dptr,#_INPKTEND
   07E6 74 86              1940 	mov	a,#0x86
   07E8 F0                 1941 	movx	@dptr,a
   07E9 00                 1942 	nop 
                           1943 ;	convert_serial2.c:458: INPKTEND = 0x86; SYNCDELAY;
   07EA 90 E6 48           1944 	mov	dptr,#_INPKTEND
   07ED 74 86              1945 	mov	a,#0x86
   07EF F0                 1946 	movx	@dptr,a
   07F0 00                 1947 	nop 
                           1948 ;	convert_serial2.c:469: EP2FIFOCFG = 0;   SYNCDELAY;
   07F1 90 E6 18           1949 	mov	dptr,#_EP2FIFOCFG
   07F4 E4                 1950 	clr	a
   07F5 F0                 1951 	movx	@dptr,a
   07F6 00                 1952 	nop 
                           1953 ;	convert_serial2.c:470: EP6FIFOCFG = 0;   SYNCDELAY;
   07F7 90 E6 1A           1954 	mov	dptr,#_EP6FIFOCFG
   07FA E4                 1955 	clr	a
   07FB F0                 1956 	movx	@dptr,a
   07FC 00                 1957 	nop 
                           1958 ;	convert_serial2.c:479: SUDPTRCTL = 1;
   07FD 90 E6 B5           1959 	mov	dptr,#_SUDPTRCTL
   0800 74 01              1960 	mov	a,#0x01
   0802 F0                 1961 	movx	@dptr,a
                           1962 ;	convert_serial2.c:482: IE = 0x80;
   0803 75 A8 80           1963 	mov	_IE,#0x80
                           1964 ;	convert_serial2.c:483: EIE = 0x01;
   0806 75 E8 01           1965 	mov	_EIE,#0x01
                           1966 ;	convert_serial2.c:486: USBIE = 0x01;
   0809 90 E6 5C           1967 	mov	dptr,#_USBIE
   080C 74 01              1968 	mov	a,#0x01
   080E F0                 1969 	movx	@dptr,a
   080F 22                 1970 	ret
                           1971 ;------------------------------------------------------------
                           1972 ;Allocation info for local variables in function 'ProcessXmitData'
                           1973 ;------------------------------------------------------------
                           1974 ;	convert_serial2.c:501: static void ProcessXmitData(void)
                           1975 ;	-----------------------------------------
                           1976 ;	 function ProcessXmitData
                           1977 ;	-----------------------------------------
   0810                    1978 _ProcessXmitData:
                           1979 ;	convert_serial2.c:504: TCON &= ~0x30;
   0810 AF 88              1980 	mov	r7,_TCON
   0812 74 CF              1981 	mov	a,#0xCF
   0814 5F                 1982 	anl	a,r7
   0815 F5 88              1983 	mov	_TCON,a
                           1984 ;	convert_serial2.c:506: SYNCDELAY;
   0817 00                 1985 	nop 
                           1986 ;	convert_serial2.c:509: EP6BCH = MSB(bytes_waiting_for_xmit);
   0818 AF 16              1987 	mov	r7,(_bytes_waiting_for_xmit + 1)
   081A 90 E6 98           1988 	mov	dptr,#_EP6BCH
   081D EF                 1989 	mov	a,r7
   081E F0                 1990 	movx	@dptr,a
                           1991 ;	convert_serial2.c:510: EP6BCL = LSB(bytes_waiting_for_xmit);
   081F AE 15              1992 	mov	r6,_bytes_waiting_for_xmit
   0821 90 E6 99           1993 	mov	dptr,#_EP6BCL
   0824 EE                 1994 	mov	a,r6
   0825 F0                 1995 	movx	@dptr,a
                           1996 ;	convert_serial2.c:512: bytes_waiting_for_xmit = 0;
   0826 E4                 1997 	clr	a
   0827 F5 15              1998 	mov	_bytes_waiting_for_xmit,a
   0829 F5 16              1999 	mov	(_bytes_waiting_for_xmit + 1),a
   082B 22                 2000 	ret
                           2001 ;------------------------------------------------------------
                           2002 ;Allocation info for local variables in function 'putchar'
                           2003 ;------------------------------------------------------------
                           2004 ;c                         Allocated to registers r7 
                           2005 ;dest                      Allocated to registers r5 r6 
                           2006 ;------------------------------------------------------------
                           2007 ;	convert_serial2.c:516: static void putchar(char c)
                           2008 ;	-----------------------------------------
                           2009 ;	 function putchar
                           2010 ;	-----------------------------------------
   082C                    2011 _putchar:
   082C AF 82              2012 	mov	r7,dpl
                           2013 ;	convert_serial2.c:518: xdata unsigned char *dest=EP6FIFOBUF + bytes_waiting_for_xmit;
   082E AD 15              2014 	mov	r5,_bytes_waiting_for_xmit
   0830 74 F8              2015 	mov	a,#(_EP6FIFOBUF >> 8)
   0832 25 16              2016 	add	a,(_bytes_waiting_for_xmit + 1)
   0834 FE                 2017 	mov	r6,a
                           2018 ;	convert_serial2.c:522: while(EP6CS & (1<<3));
   0835                    2019 00101$:
   0835 90 E6 A5           2020 	mov	dptr,#_EP6CS
   0838 E0                 2021 	movx	a,@dptr
   0839 FC                 2022 	mov	r4,a
   083A 20 E3 F8           2023 	jb	acc.3,00101$
                           2024 ;	convert_serial2.c:524: *dest = c;
   083D 8D 82              2025 	mov	dpl,r5
   083F 8E 83              2026 	mov	dph,r6
   0841 EF                 2027 	mov	a,r7
   0842 F0                 2028 	movx	@dptr,a
                           2029 ;	convert_serial2.c:525: ++bytes_waiting_for_xmit;
   0843 05 15              2030 	inc	_bytes_waiting_for_xmit
   0845 E4                 2031 	clr	a
   0846 B5 15 02           2032 	cjne	a,_bytes_waiting_for_xmit,00122$
   0849 05 16              2033 	inc	(_bytes_waiting_for_xmit + 1)
   084B                    2034 00122$:
                           2035 ;	convert_serial2.c:529: if (bytes_waiting_for_xmit >= 512 ) ProcessXmitData();
   084B E5 16              2036 	mov	a,(_bytes_waiting_for_xmit + 1)
   084D 54 FE              2037 	anl	a,#0xFE
   084F 60 03              2038 	jz	00105$
   0851 12 08 10           2039 	lcall	_ProcessXmitData
   0854                    2040 00105$:
                           2041 ;	convert_serial2.c:532: if (bytes_waiting_for_xmit && !(TCON & 0x10)) {
   0854 E5 15              2042 	mov	a,_bytes_waiting_for_xmit
   0856 45 16              2043 	orl	a,(_bytes_waiting_for_xmit + 1)
   0858 60 19              2044 	jz	00109$
   085A E5 88              2045 	mov	a,_TCON
   085C 20 E4 14           2046 	jb	acc.4,00109$
                           2047 ;	convert_serial2.c:533: TH0 = MSB(0xffff - latency_us);
   085F 74 FF              2048 	mov	a,#0xFF
   0861 C3                 2049 	clr	c
   0862 95 17              2050 	subb	a,_latency_us
   0864 FE                 2051 	mov	r6,a
   0865 74 FF              2052 	mov	a,#0xFF
   0867 95 18              2053 	subb	a,(_latency_us + 1)
   0869 FD                 2054 	mov	r5,a
   086A 8D 8C              2055 	mov	_TH0,r5
                           2056 ;	convert_serial2.c:534: TL0 = LSB(0xffff - latency_us);
   086C 7F 00              2057 	mov	r7,#0x00
   086E 8E 8A              2058 	mov	_TL0,r6
                           2059 ;	convert_serial2.c:535: TCON |= 0x10;
   0870 43 88 10           2060 	orl	_TCON,#0x10
   0873                    2061 00109$:
   0873 22                 2062 	ret
                           2063 ;------------------------------------------------------------
                           2064 ;Allocation info for local variables in function 'ProcessRecvData'
                           2065 ;------------------------------------------------------------
                           2066 ;src                       Allocated to registers 
                           2067 ;len                       Allocated to registers r5 r4 
                           2068 ;i                         Allocated to registers r2 r3 
                           2069 ;------------------------------------------------------------
                           2070 ;	convert_serial2.c:540: static void ProcessRecvData(void)
                           2071 ;	-----------------------------------------
                           2072 ;	 function ProcessRecvData
                           2073 ;	-----------------------------------------
   0874                    2074 _ProcessRecvData:
                           2075 ;	convert_serial2.c:542: xdata const unsigned char *src=EP2FIFOBUF;
   0874 7E 00              2076 	mov	r6,#_EP2FIFOBUF
   0876 7F F0              2077 	mov	r7,#(_EP2FIFOBUF >> 8)
                           2078 ;	convert_serial2.c:543: int len = (((int)EP2BCH)<<8) | EP2BCL;
   0878 90 E6 90           2079 	mov	dptr,#_EP2BCH
   087B E0                 2080 	movx	a,@dptr
   087C FC                 2081 	mov	r4,a
   087D 7D 00              2082 	mov	r5,#0x00
   087F 90 E6 91           2083 	mov	dptr,#_EP2BCL
   0882 E0                 2084 	movx	a,@dptr
   0883 7A 00              2085 	mov	r2,#0x00
   0885 42 05              2086 	orl	ar5,a
   0887 EA                 2087 	mov	a,r2
   0888 42 04              2088 	orl	ar4,a
                           2089 ;	convert_serial2.c:546: for(i=0; i<len; i++,src++)
   088A 7A 00              2090 	mov	r2,#0x00
   088C 7B 00              2091 	mov	r3,#0x00
   088E                    2092 00105$:
   088E C3                 2093 	clr	c
   088F EA                 2094 	mov	a,r2
   0890 9D                 2095 	subb	a,r5
   0891 EB                 2096 	mov	a,r3
   0892 64 80              2097 	xrl	a,#0x80
   0894 8C F0              2098 	mov	b,r4
   0896 63 F0 80           2099 	xrl	b,#0x80
   0899 95 F0              2100 	subb	a,b
   089B 50 60              2101 	jnc	00108$
                           2102 ;	convert_serial2.c:548: if(*src>='a' && *src<='z')
   089D 8E 82              2103 	mov	dpl,r6
   089F 8F 83              2104 	mov	dph,r7
   08A1 E0                 2105 	movx	a,@dptr
   08A2 F9                 2106 	mov	r1,a
   08A3 B9 61 00           2107 	cjne	r1,#0x61,00121$
   08A6                    2108 00121$:
   08A6 40 27              2109 	jc	00102$
   08A8 E9                 2110 	mov	a,r1
   08A9 24 85              2111 	add	a,#0xff - 0x7A
   08AB 40 22              2112 	jc	00102$
                           2113 ;	convert_serial2.c:549: {  putchar(*src-'a'+'A');  }
   08AD 74 E0              2114 	mov	a,#0xE0
   08AF 29                 2115 	add	a,r1
   08B0 F5 82              2116 	mov	dpl,a
   08B2 C0 07              2117 	push	ar7
   08B4 C0 06              2118 	push	ar6
   08B6 C0 05              2119 	push	ar5
   08B8 C0 04              2120 	push	ar4
   08BA C0 03              2121 	push	ar3
   08BC C0 02              2122 	push	ar2
   08BE 12 08 2C           2123 	lcall	_putchar
   08C1 D0 02              2124 	pop	ar2
   08C3 D0 03              2125 	pop	ar3
   08C5 D0 04              2126 	pop	ar4
   08C7 D0 05              2127 	pop	ar5
   08C9 D0 06              2128 	pop	ar6
   08CB D0 07              2129 	pop	ar7
   08CD 80 22              2130 	sjmp	00107$
   08CF                    2131 00102$:
                           2132 ;	convert_serial2.c:551: {  putchar(*src);  }
   08CF 8E 82              2133 	mov	dpl,r6
   08D1 8F 83              2134 	mov	dph,r7
   08D3 E0                 2135 	movx	a,@dptr
   08D4 F5 82              2136 	mov	dpl,a
   08D6 C0 07              2137 	push	ar7
   08D8 C0 06              2138 	push	ar6
   08DA C0 05              2139 	push	ar5
   08DC C0 04              2140 	push	ar4
   08DE C0 03              2141 	push	ar3
   08E0 C0 02              2142 	push	ar2
   08E2 12 08 2C           2143 	lcall	_putchar
   08E5 D0 02              2144 	pop	ar2
   08E7 D0 03              2145 	pop	ar3
   08E9 D0 04              2146 	pop	ar4
   08EB D0 05              2147 	pop	ar5
   08ED D0 06              2148 	pop	ar6
   08EF D0 07              2149 	pop	ar7
   08F1                    2150 00107$:
                           2151 ;	convert_serial2.c:546: for(i=0; i<len; i++,src++)
   08F1 0A                 2152 	inc	r2
   08F2 BA 00 01           2153 	cjne	r2,#0x00,00124$
   08F5 0B                 2154 	inc	r3
   08F6                    2155 00124$:
   08F6 0E                 2156 	inc	r6
   08F7 BE 00 94           2157 	cjne	r6,#0x00,00105$
   08FA 0F                 2158 	inc	r7
   08FB 80 91              2159 	sjmp	00105$
   08FD                    2160 00108$:
                           2161 ;	convert_serial2.c:555: SYNCDELAY;
   08FD 00                 2162 	nop 
                           2163 ;	convert_serial2.c:556: OUTPKTEND=0x82;
   08FE 90 E6 49           2164 	mov	dptr,#_OUTPKTEND
   0901 74 82              2165 	mov	a,#0x82
   0903 F0                 2166 	movx	@dptr,a
   0904 22                 2167 	ret
                           2168 ;------------------------------------------------------------
                           2169 ;Allocation info for local variables in function 'main'
                           2170 ;------------------------------------------------------------
                           2171 ;	convert_serial2.c:560: void main(void)
                           2172 ;	-----------------------------------------
                           2173 ;	 function main
                           2174 ;	-----------------------------------------
   0905                    2175 _main:
                           2176 ;	convert_serial2.c:563: USBCS |= 0x08;
   0905 90 E6 80           2177 	mov	dptr,#_USBCS
   0908 E0                 2178 	movx	a,@dptr
   0909 44 08              2179 	orl	a,#0x08
   090B F0                 2180 	movx	@dptr,a
                           2181 ;	convert_serial2.c:564: Initialize();
   090C 12 07 6C           2182 	lcall	_Initialize
                           2183 ;	convert_serial2.c:565: USBCS |= 0x02;
                           2184 ;	convert_serial2.c:566: USBCS &= ~(0x08);
   090F 90 E6 80           2185 	mov	dptr,#_USBCS
   0912 E0                 2186 	movx	a,@dptr
   0913 44 02              2187 	orl	a,#0x02
   0915 F0                 2188 	movx	@dptr,a
   0916 E0                 2189 	movx	a,@dptr
   0917 54 F7              2190 	anl	a,#0xF7
   0919 F0                 2191 	movx	@dptr,a
                           2192 ;	convert_serial2.c:570: CKCO &= ~(0x08);
   091A AF 8E              2193 	mov	r7,_CKCO
   091C 74 F7              2194 	mov	a,#0xF7
   091E 5F                 2195 	anl	a,r7
   091F F5 8E              2196 	mov	_CKCO,a
                           2197 ;	convert_serial2.c:571: TMOD = 0x01;
   0921 75 89 01           2198 	mov	_TMOD,#0x01
                           2199 ;	convert_serial2.c:572: TCON &= ~0x30;
   0924 AF 88              2200 	mov	r7,_TCON
   0926 74 CF              2201 	mov	a,#0xCF
   0928 5F                 2202 	anl	a,r7
   0929 F5 88              2203 	mov	_TCON,a
   092B                    2204 00106$:
                           2205 ;	convert_serial2.c:577: if(!(EP2CS & (1<<2)))
   092B 90 E6 A3           2206 	mov	dptr,#_EP2CS
   092E E0                 2207 	movx	a,@dptr
   092F FF                 2208 	mov	r7,a
   0930 20 E2 03           2209 	jb	acc.2,00102$
                           2210 ;	convert_serial2.c:579: ProcessRecvData();
   0933 12 08 74           2211 	lcall	_ProcessRecvData
   0936                    2212 00102$:
                           2213 ;	convert_serial2.c:583: if((TCON & 0x20))
   0936 E5 88              2214 	mov	a,_TCON
   0938 30 E5 F0           2215 	jnb	acc.5,00106$
                           2216 ;	convert_serial2.c:585: ProcessXmitData();
   093B 12 08 10           2217 	lcall	_ProcessXmitData
   093E 80 EB              2218 	sjmp	00106$
                           2219 	.area CSEG    (CODE)
                           2220 	.area CONST   (CODE)
   0960                    2221 _EPCS_Offset_Lookup_Table:
   0960 00                 2222 	.db #0x00	;  0
   0961 01                 2223 	.db #0x01	;  1
   0962 02                 2224 	.db #0x02	;  2
   0963 02                 2225 	.db #0x02	;  2
   0964 03                 2226 	.db #0x03	;  3
   0965 03                 2227 	.db #0x03	;  3
   0966 04                 2228 	.db #0x04	;  4
   0967 04                 2229 	.db #0x04	;  4
   0968 05                 2230 	.db #0x05	;  5
   0969 05                 2231 	.db #0x05	;  5
   096A                    2232 __str_0:
   096A 45 4E              2233 	.ascii "EN"
   096C 00                 2234 	.db 0x00
   096D                    2235 __str_1:
   096D 57 69 65 73 65 72  2236 	.ascii "WieserLabs & freesoft.org"
        4C 61 62 73 20 26
        20 66 72 65 65 73
        6F 66 74 2E 6F 72
        67
   0986 00                 2237 	.db 0x00
   0987                    2238 __str_2:
   0987 46 58 32 20 63 61  2239 	.ascii "FX2 case converter"
        73 65 20 63 6F 6E
        76 65 72 74 65 72
   0999 00                 2240 	.db 0x00
                           2241 	.area XINIT   (CODE)
                           2242 	.area CABS    (ABS,CODE)
