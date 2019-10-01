                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.2.0 #8008 (Jul  6 2012) (MINGW32)
                              4 ; This file was generated Wed Apr 29 06:16:33 2015
                              5 ;--------------------------------------------------------
                              6 	.module eeprom_mark
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _strncmp
                             14 	.globl _strcpy
                             15 	.globl _sprintf
                             16 	.globl _EIP
                             17 	.globl _B
                             18 	.globl _EIE
                             19 	.globl _ACC
                             20 	.globl _EICON
                             21 	.globl _PSW
                             22 	.globl _TH2
                             23 	.globl _TL2
                             24 	.globl _RCAP2H
                             25 	.globl _RCAP2L
                             26 	.globl _T2CON
                             27 	.globl _SBUF1
                             28 	.globl _SCON1
                             29 	.globl _GPIFSGLDATLNOX
                             30 	.globl _GPIFSGLDATLX
                             31 	.globl _GPIFSGLDATH
                             32 	.globl _GPIFTRIG
                             33 	.globl _EP01STAT
                             34 	.globl _IP
                             35 	.globl _OEE
                             36 	.globl _OED
                             37 	.globl _OEC
                             38 	.globl _OEB
                             39 	.globl _OEA
                             40 	.globl _IOE
                             41 	.globl _IOD
                             42 	.globl _AUTOPTRSETUP
                             43 	.globl _EP68FIFOFLGS
                             44 	.globl _EP24FIFOFLGS
                             45 	.globl _EP2468STAT
                             46 	.globl _IE
                             47 	.globl _INT4CLR
                             48 	.globl _INT2CLR
                             49 	.globl _IOC
                             50 	.globl _AUTODAT2
                             51 	.globl _AUTOPTRL2
                             52 	.globl _AUTOPTRH2
                             53 	.globl _AUTODAT1
                             54 	.globl _APTR1L
                             55 	.globl _APTR1H
                             56 	.globl _SBU
                             57 	.globl _SCO
                             58 	.globl _MPA
                             59 	.globl _EXIF
                             60 	.globl _IOB
                             61 	.globl _SPC_
                             62 	.globl _CKCO
                             63 	.globl _TH1
                             64 	.globl _TH0
                             65 	.globl _TL1
                             66 	.globl _TL0
                             67 	.globl _TMOD
                             68 	.globl _TCON
                             69 	.globl _PCON
                             70 	.globl _DPS
                             71 	.globl _DPH1
                             72 	.globl _DPL1
                             73 	.globl _DPH
                             74 	.globl _DPL
                             75 	.globl _SP
                             76 	.globl _IOA
                             77 	.globl _EP8FIFOBUF
                             78 	.globl _EP6FIFOBUF
                             79 	.globl _EP4FIFOBUF
                             80 	.globl _EP2FIFOBUF
                             81 	.globl _EP1INBUF
                             82 	.globl _EP1OUTBUF
                             83 	.globl _EP0BUF
                             84 	.globl _CT4
                             85 	.globl _CT3
                             86 	.globl _CT2
                             87 	.globl _CT1
                             88 	.globl _USBTEST
                             89 	.globl _TESTCFG
                             90 	.globl _DBUG
                             91 	.globl _UDMACRCQUAL
                             92 	.globl _UDMACRCL
                             93 	.globl _UDMACRCH
                             94 	.globl _GPIFHOLDAMOUNT
                             95 	.globl _FLOWSTBHPERIOD
                             96 	.globl _FLOWSTBEDGE
                             97 	.globl _FLOWSTB
                             98 	.globl _FLOWHOLDOFF
                             99 	.globl _FLOWEQ1CTL
                            100 	.globl _FLOWEQ0CTL
                            101 	.globl _FLOWLOGIC
                            102 	.globl _FLOWSTATE
                            103 	.globl _GPIFABORT
                            104 	.globl _GPIFREADYSTAT
                            105 	.globl _GPIFREADYCFG
                            106 	.globl _XGPIFSGLDATLNOX
                            107 	.globl _XGPIFSGLDATLX
                            108 	.globl _XGPIFSGLDATH
                            109 	.globl _EP8GPIFTRIG
                            110 	.globl _EP8GPIFPFSTOP
                            111 	.globl _EP8GPIFFLGSEL
                            112 	.globl _EP6GPIFTRIG
                            113 	.globl _EP6GPIFPFSTOP
                            114 	.globl _EP6GPIFFLGSEL
                            115 	.globl _EP4GPIFTRIG
                            116 	.globl _EP4GPIFPFSTOP
                            117 	.globl _EP4GPIFFLGSEL
                            118 	.globl _EP2GPIFTRIG
                            119 	.globl _EP2GPIFPFSTOP
                            120 	.globl _EP2GPIFFLGSEL
                            121 	.globl _GPIFTCB0
                            122 	.globl _GPIFTCB1
                            123 	.globl _GPIFTCB2
                            124 	.globl _GPIFTCB3
                            125 	.globl _GPIFADRL
                            126 	.globl _GPIFADRH
                            127 	.globl _GPIFCTLCFG
                            128 	.globl _GPIFIDLECTL
                            129 	.globl _GPIFIDLECS
                            130 	.globl _GPIFWFSELECT
                            131 	.globl _SETUPDAT
                            132 	.globl _SUDPTRCTL
                            133 	.globl _SUDPTRL
                            134 	.globl _SUDPTRH
                            135 	.globl _EP8FIFOBCL
                            136 	.globl _EP8FIFOBCH
                            137 	.globl _EP6FIFOBCL
                            138 	.globl _EP6FIFOBCH
                            139 	.globl _EP4FIFOBCL
                            140 	.globl _EP4FIFOBCH
                            141 	.globl _EP2FIFOBCL
                            142 	.globl _EP2FIFOBCH
                            143 	.globl _EP8FIFOFLGS
                            144 	.globl _EP6FIFOFLGS
                            145 	.globl _EP4FIFOFLGS
                            146 	.globl _EP2FIFOFLGS
                            147 	.globl _EP8CS
                            148 	.globl _EP6CS
                            149 	.globl _EP4CS
                            150 	.globl _EP2CS
                            151 	.globl _EP1INCS
                            152 	.globl _EP1OUTCS
                            153 	.globl _EP0CS
                            154 	.globl _EP8BCL
                            155 	.globl _EP8BCH
                            156 	.globl _EP6BCL
                            157 	.globl _EP6BCH
                            158 	.globl _EP4BCL
                            159 	.globl _EP4BCH
                            160 	.globl _EP2BCL
                            161 	.globl _EP2BCH
                            162 	.globl _EP1INBC
                            163 	.globl _EP1OUTBC
                            164 	.globl _EP0BCL
                            165 	.globl _EP0BCH
                            166 	.globl _FNADDR
                            167 	.globl _MICROFRAME
                            168 	.globl _USBFRAMEL
                            169 	.globl _USBFRAMEH
                            170 	.globl _TOGCTL
                            171 	.globl _WAKEUPCS
                            172 	.globl _SUSPEND
                            173 	.globl _USBCS
                            174 	.globl _XAUTODAT2
                            175 	.globl _XAUTODAT1
                            176 	.globl _I2CTL
                            177 	.globl _I2DAT
                            178 	.globl _I2CS
                            179 	.globl _PORTECFG
                            180 	.globl _PORTCCFG
                            181 	.globl _PORTACFG
                            182 	.globl _INTSETUP
                            183 	.globl _INT4IVEC
                            184 	.globl _INT2IVEC
                            185 	.globl _CLRERRCNT
                            186 	.globl _ERRCNTLIM
                            187 	.globl _USBERRIRQ
                            188 	.globl _USBERRIE
                            189 	.globl _GPIFIRQ
                            190 	.globl _GPIFIE
                            191 	.globl _EPIRQ
                            192 	.globl _EPIE
                            193 	.globl _USBIRQ
                            194 	.globl _USBIE
                            195 	.globl _NAKIRQ
                            196 	.globl _NAKIE
                            197 	.globl _IBNIRQ
                            198 	.globl _IBNIE
                            199 	.globl _EP8FIFOIRQ
                            200 	.globl _EP8FIFOIE
                            201 	.globl _EP6FIFOIRQ
                            202 	.globl _EP6FIFOIE
                            203 	.globl _EP4FIFOIRQ
                            204 	.globl _EP4FIFOIE
                            205 	.globl _EP2FIFOIRQ
                            206 	.globl _EP2FIFOIE
                            207 	.globl _OUTPKTEND
                            208 	.globl _INPKTEND
                            209 	.globl _EP8ISOINPKTS
                            210 	.globl _EP6ISOINPKTS
                            211 	.globl _EP4ISOINPKTS
                            212 	.globl _EP2ISOINPKTS
                            213 	.globl _EP8FIFOPFL
                            214 	.globl _EP8FIFOPFH
                            215 	.globl _EP6FIFOPFL
                            216 	.globl _EP6FIFOPFH
                            217 	.globl _EP4FIFOPFL
                            218 	.globl _EP4FIFOPFH
                            219 	.globl _EP2FIFOPFL
                            220 	.globl _EP2FIFOPFH
                            221 	.globl _EP8AUTOINLENL
                            222 	.globl _EP8AUTOINLENH
                            223 	.globl _EP6AUTOINLENL
                            224 	.globl _EP6AUTOINLENH
                            225 	.globl _EP4AUTOINLENL
                            226 	.globl _EP4AUTOINLENH
                            227 	.globl _EP2AUTOINLENL
                            228 	.globl _EP2AUTOINLENH
                            229 	.globl _EP8FIFOCFG
                            230 	.globl _EP6FIFOCFG
                            231 	.globl _EP4FIFOCFG
                            232 	.globl _EP2FIFOCFG
                            233 	.globl _EP8CFG
                            234 	.globl _EP6CFG
                            235 	.globl _EP4CFG
                            236 	.globl _EP2CFG
                            237 	.globl _EP1INCFG
                            238 	.globl _EP1OUTCFG
                            239 	.globl _REVCTL
                            240 	.globl _REVID
                            241 	.globl _FIFOPINPOLAR
                            242 	.globl _UART230
                            243 	.globl _BPADDRL
                            244 	.globl _BPADDRH
                            245 	.globl _BREAKPT
                            246 	.globl _FIFORESET
                            247 	.globl _PINFLAGSCD
                            248 	.globl _PINFLAGSAB
                            249 	.globl _IFCONFIG
                            250 	.globl _CPUCS
                            251 	.globl _RES_WAVEDATA_END
                            252 	.globl _GPIF_WAVE_DATA
                            253 	.globl _FWmark
                            254 	.globl _HWmark
                            255 	.globl _command
                            256 	.globl _dat
                            257 	.globl _err
                            258 ;--------------------------------------------------------
                            259 ; special function registers
                            260 ;--------------------------------------------------------
                            261 	.area RSEG    (ABS,DATA)
   0000                     262 	.org 0x0000
                    0080    263 _IOA	=	0x0080
                    0081    264 _SP	=	0x0081
                    0082    265 _DPL	=	0x0082
                    0083    266 _DPH	=	0x0083
                    0084    267 _DPL1	=	0x0084
                    0085    268 _DPH1	=	0x0085
                    0086    269 _DPS	=	0x0086
                    0087    270 _PCON	=	0x0087
                    0088    271 _TCON	=	0x0088
                    0089    272 _TMOD	=	0x0089
                    008A    273 _TL0	=	0x008a
                    008B    274 _TL1	=	0x008b
                    008C    275 _TH0	=	0x008c
                    008D    276 _TH1	=	0x008d
                    008E    277 _CKCO	=	0x008e
                    008F    278 _SPC_	=	0x008f
                    0090    279 _IOB	=	0x0090
                    0091    280 _EXIF	=	0x0091
                    0092    281 _MPA	=	0x0092
                    0098    282 _SCO	=	0x0098
                    0099    283 _SBU	=	0x0099
                    009A    284 _APTR1H	=	0x009a
                    009B    285 _APTR1L	=	0x009b
                    009C    286 _AUTODAT1	=	0x009c
                    009D    287 _AUTOPTRH2	=	0x009d
                    009E    288 _AUTOPTRL2	=	0x009e
                    009F    289 _AUTODAT2	=	0x009f
                    00A0    290 _IOC	=	0x00a0
                    00A1    291 _INT2CLR	=	0x00a1
                    00A2    292 _INT4CLR	=	0x00a2
                    00A8    293 _IE	=	0x00a8
                    00AA    294 _EP2468STAT	=	0x00aa
                    00AB    295 _EP24FIFOFLGS	=	0x00ab
                    00AC    296 _EP68FIFOFLGS	=	0x00ac
                    00AF    297 _AUTOPTRSETUP	=	0x00af
                    00B0    298 _IOD	=	0x00b0
                    00B1    299 _IOE	=	0x00b1
                    00B2    300 _OEA	=	0x00b2
                    00B3    301 _OEB	=	0x00b3
                    00B4    302 _OEC	=	0x00b4
                    00B5    303 _OED	=	0x00b5
                    00B6    304 _OEE	=	0x00b6
                    00B8    305 _IP	=	0x00b8
                    00BA    306 _EP01STAT	=	0x00ba
                    00BB    307 _GPIFTRIG	=	0x00bb
                    00BD    308 _GPIFSGLDATH	=	0x00bd
                    00BE    309 _GPIFSGLDATLX	=	0x00be
                    00BF    310 _GPIFSGLDATLNOX	=	0x00bf
                    00C0    311 _SCON1	=	0x00c0
                    00C1    312 _SBUF1	=	0x00c1
                    00C8    313 _T2CON	=	0x00c8
                    00CA    314 _RCAP2L	=	0x00ca
                    00CB    315 _RCAP2H	=	0x00cb
                    00CC    316 _TL2	=	0x00cc
                    00CD    317 _TH2	=	0x00cd
                    00D0    318 _PSW	=	0x00d0
                    00D8    319 _EICON	=	0x00d8
                    00E0    320 _ACC	=	0x00e0
                    00E8    321 _EIE	=	0x00e8
                    00F0    322 _B	=	0x00f0
                    00F8    323 _EIP	=	0x00f8
                            324 ;--------------------------------------------------------
                            325 ; special function bits
                            326 ;--------------------------------------------------------
                            327 	.area RSEG    (ABS,DATA)
   0000                     328 	.org 0x0000
                            329 ;--------------------------------------------------------
                            330 ; overlayable register banks
                            331 ;--------------------------------------------------------
                            332 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     333 	.ds 8
                            334 ;--------------------------------------------------------
                            335 ; internal ram data
                            336 ;--------------------------------------------------------
                            337 	.area DSEG    (DATA)
   0022                     338 _err::
   0022                     339 	.ds 2
   0024                     340 _dat::
   0024                     341 	.ds 2
   0026                     342 _command::
   0026                     343 	.ds 2
   0028                     344 _HWmark::
   0028                     345 	.ds 2
   002A                     346 _hostreadmarkep1poll_ep1outbc_1_46:
   002A                     347 	.ds 1
   002B                     348 _hostreadmarkep1poll_n_1_46:
   002B                     349 	.ds 2
   002D                     350 _FWmark::
   002D                     351 	.ds 3
   0030                     352 _writemarkeeprom_mark_1_62:
   0030                     353 	.ds 3
   0033                     354 _writemarkeeprom_sloc0_1_0:
   0033                     355 	.ds 2
   0035                     356 _writemarkeeprom_sloc1_1_0:
   0035                     357 	.ds 2
   0037                     358 _main_mark_1_65:
   0037                     359 	.ds 16
                            360 ;--------------------------------------------------------
                            361 ; overlayable items in internal ram 
                            362 ;--------------------------------------------------------
                            363 	.area	OSEG    (OVR,DATA)
   0010                     364 _EERead_PARM_2:
   0010                     365 	.ds 3
   0013                     366 _EERead_n_1_36:
   0013                     367 	.ds 2
                            368 	.area	OSEG    (OVR,DATA)
                            369 	.area	OSEG    (OVR,DATA)
   0010                     370 _EEWrite_PARM_2:
   0010                     371 	.ds 1
                            372 ;--------------------------------------------------------
                            373 ; Stack segment in internal ram 
                            374 ;--------------------------------------------------------
                            375 	.area	SSEG	(DATA)
   0061                     376 __start__stack:
   0061                     377 	.ds	1
                            378 
                            379 ;--------------------------------------------------------
                            380 ; indirectly addressable internal ram data
                            381 ;--------------------------------------------------------
                            382 	.area ISEG    (DATA)
                            383 ;--------------------------------------------------------
                            384 ; absolute internal ram data
                            385 ;--------------------------------------------------------
                            386 	.area IABS    (ABS,DATA)
                            387 	.area IABS    (ABS,DATA)
                            388 ;--------------------------------------------------------
                            389 ; bit data
                            390 ;--------------------------------------------------------
                            391 	.area BSEG    (BIT)
                            392 ;--------------------------------------------------------
                            393 ; paged external ram data
                            394 ;--------------------------------------------------------
                            395 	.area PSEG    (PAG,XDATA)
                            396 ;--------------------------------------------------------
                            397 ; external ram data
                            398 ;--------------------------------------------------------
                            399 	.area XSEG    (XDATA)
                    E400    400 _GPIF_WAVE_DATA	=	0xe400
                    E480    401 _RES_WAVEDATA_END	=	0xe480
                    E600    402 _CPUCS	=	0xe600
                    E601    403 _IFCONFIG	=	0xe601
                    E602    404 _PINFLAGSAB	=	0xe602
                    E603    405 _PINFLAGSCD	=	0xe603
                    E604    406 _FIFORESET	=	0xe604
                    E605    407 _BREAKPT	=	0xe605
                    E606    408 _BPADDRH	=	0xe606
                    E607    409 _BPADDRL	=	0xe607
                    E608    410 _UART230	=	0xe608
                    E609    411 _FIFOPINPOLAR	=	0xe609
                    E60A    412 _REVID	=	0xe60a
                    E60B    413 _REVCTL	=	0xe60b
                    E610    414 _EP1OUTCFG	=	0xe610
                    E611    415 _EP1INCFG	=	0xe611
                    E612    416 _EP2CFG	=	0xe612
                    E613    417 _EP4CFG	=	0xe613
                    E614    418 _EP6CFG	=	0xe614
                    E615    419 _EP8CFG	=	0xe615
                    E618    420 _EP2FIFOCFG	=	0xe618
                    E619    421 _EP4FIFOCFG	=	0xe619
                    E61A    422 _EP6FIFOCFG	=	0xe61a
                    E61B    423 _EP8FIFOCFG	=	0xe61b
                    E620    424 _EP2AUTOINLENH	=	0xe620
                    E621    425 _EP2AUTOINLENL	=	0xe621
                    E622    426 _EP4AUTOINLENH	=	0xe622
                    E623    427 _EP4AUTOINLENL	=	0xe623
                    E624    428 _EP6AUTOINLENH	=	0xe624
                    E625    429 _EP6AUTOINLENL	=	0xe625
                    E626    430 _EP8AUTOINLENH	=	0xe626
                    E627    431 _EP8AUTOINLENL	=	0xe627
                    E630    432 _EP2FIFOPFH	=	0xe630
                    E631    433 _EP2FIFOPFL	=	0xe631
                    E632    434 _EP4FIFOPFH	=	0xe632
                    E633    435 _EP4FIFOPFL	=	0xe633
                    E634    436 _EP6FIFOPFH	=	0xe634
                    E635    437 _EP6FIFOPFL	=	0xe635
                    E636    438 _EP8FIFOPFH	=	0xe636
                    E637    439 _EP8FIFOPFL	=	0xe637
                    E640    440 _EP2ISOINPKTS	=	0xe640
                    E641    441 _EP4ISOINPKTS	=	0xe641
                    E642    442 _EP6ISOINPKTS	=	0xe642
                    E643    443 _EP8ISOINPKTS	=	0xe643
                    E648    444 _INPKTEND	=	0xe648
                    E649    445 _OUTPKTEND	=	0xe649
                    E650    446 _EP2FIFOIE	=	0xe650
                    E651    447 _EP2FIFOIRQ	=	0xe651
                    E652    448 _EP4FIFOIE	=	0xe652
                    E653    449 _EP4FIFOIRQ	=	0xe653
                    E654    450 _EP6FIFOIE	=	0xe654
                    E655    451 _EP6FIFOIRQ	=	0xe655
                    E656    452 _EP8FIFOIE	=	0xe656
                    E657    453 _EP8FIFOIRQ	=	0xe657
                    E658    454 _IBNIE	=	0xe658
                    E659    455 _IBNIRQ	=	0xe659
                    E65A    456 _NAKIE	=	0xe65a
                    E65B    457 _NAKIRQ	=	0xe65b
                    E65C    458 _USBIE	=	0xe65c
                    E65D    459 _USBIRQ	=	0xe65d
                    E65E    460 _EPIE	=	0xe65e
                    E65F    461 _EPIRQ	=	0xe65f
                    E660    462 _GPIFIE	=	0xe660
                    E661    463 _GPIFIRQ	=	0xe661
                    E662    464 _USBERRIE	=	0xe662
                    E663    465 _USBERRIRQ	=	0xe663
                    E664    466 _ERRCNTLIM	=	0xe664
                    E665    467 _CLRERRCNT	=	0xe665
                    E666    468 _INT2IVEC	=	0xe666
                    E667    469 _INT4IVEC	=	0xe667
                    E668    470 _INTSETUP	=	0xe668
                    E670    471 _PORTACFG	=	0xe670
                    E671    472 _PORTCCFG	=	0xe671
                    E672    473 _PORTECFG	=	0xe672
                    E678    474 _I2CS	=	0xe678
                    E679    475 _I2DAT	=	0xe679
                    E67A    476 _I2CTL	=	0xe67a
                    E67B    477 _XAUTODAT1	=	0xe67b
                    E67C    478 _XAUTODAT2	=	0xe67c
                    E680    479 _USBCS	=	0xe680
                    E681    480 _SUSPEND	=	0xe681
                    E682    481 _WAKEUPCS	=	0xe682
                    E683    482 _TOGCTL	=	0xe683
                    E684    483 _USBFRAMEH	=	0xe684
                    E685    484 _USBFRAMEL	=	0xe685
                    E686    485 _MICROFRAME	=	0xe686
                    E687    486 _FNADDR	=	0xe687
                    E68A    487 _EP0BCH	=	0xe68a
                    E68B    488 _EP0BCL	=	0xe68b
                    E68D    489 _EP1OUTBC	=	0xe68d
                    E68F    490 _EP1INBC	=	0xe68f
                    E690    491 _EP2BCH	=	0xe690
                    E691    492 _EP2BCL	=	0xe691
                    E694    493 _EP4BCH	=	0xe694
                    E695    494 _EP4BCL	=	0xe695
                    E698    495 _EP6BCH	=	0xe698
                    E699    496 _EP6BCL	=	0xe699
                    E69C    497 _EP8BCH	=	0xe69c
                    E69D    498 _EP8BCL	=	0xe69d
                    E6A0    499 _EP0CS	=	0xe6a0
                    E6A1    500 _EP1OUTCS	=	0xe6a1
                    E6A2    501 _EP1INCS	=	0xe6a2
                    E6A3    502 _EP2CS	=	0xe6a3
                    E6A4    503 _EP4CS	=	0xe6a4
                    E6A5    504 _EP6CS	=	0xe6a5
                    E6A6    505 _EP8CS	=	0xe6a6
                    E6A7    506 _EP2FIFOFLGS	=	0xe6a7
                    E6A8    507 _EP4FIFOFLGS	=	0xe6a8
                    E6A9    508 _EP6FIFOFLGS	=	0xe6a9
                    E6AA    509 _EP8FIFOFLGS	=	0xe6aa
                    E6AB    510 _EP2FIFOBCH	=	0xe6ab
                    E6AC    511 _EP2FIFOBCL	=	0xe6ac
                    E6AD    512 _EP4FIFOBCH	=	0xe6ad
                    E6AE    513 _EP4FIFOBCL	=	0xe6ae
                    E6AF    514 _EP6FIFOBCH	=	0xe6af
                    E6B0    515 _EP6FIFOBCL	=	0xe6b0
                    E6B1    516 _EP8FIFOBCH	=	0xe6b1
                    E6B2    517 _EP8FIFOBCL	=	0xe6b2
                    E6B3    518 _SUDPTRH	=	0xe6b3
                    E6B4    519 _SUDPTRL	=	0xe6b4
                    E6B5    520 _SUDPTRCTL	=	0xe6b5
                    E6B8    521 _SETUPDAT	=	0xe6b8
                    E6C0    522 _GPIFWFSELECT	=	0xe6c0
                    E6C1    523 _GPIFIDLECS	=	0xe6c1
                    E6C2    524 _GPIFIDLECTL	=	0xe6c2
                    E6C3    525 _GPIFCTLCFG	=	0xe6c3
                    E6C4    526 _GPIFADRH	=	0xe6c4
                    E6C5    527 _GPIFADRL	=	0xe6c5
                    E6CE    528 _GPIFTCB3	=	0xe6ce
                    E6CF    529 _GPIFTCB2	=	0xe6cf
                    E6D0    530 _GPIFTCB1	=	0xe6d0
                    E6D1    531 _GPIFTCB0	=	0xe6d1
                    E6D2    532 _EP2GPIFFLGSEL	=	0xe6d2
                    E6D3    533 _EP2GPIFPFSTOP	=	0xe6d3
                    E6D4    534 _EP2GPIFTRIG	=	0xe6d4
                    E6DA    535 _EP4GPIFFLGSEL	=	0xe6da
                    E6DB    536 _EP4GPIFPFSTOP	=	0xe6db
                    E6DC    537 _EP4GPIFTRIG	=	0xe6dc
                    E6E2    538 _EP6GPIFFLGSEL	=	0xe6e2
                    E6E3    539 _EP6GPIFPFSTOP	=	0xe6e3
                    E6E4    540 _EP6GPIFTRIG	=	0xe6e4
                    E6EA    541 _EP8GPIFFLGSEL	=	0xe6ea
                    E6EB    542 _EP8GPIFPFSTOP	=	0xe6eb
                    E6EC    543 _EP8GPIFTRIG	=	0xe6ec
                    E6F0    544 _XGPIFSGLDATH	=	0xe6f0
                    E6F1    545 _XGPIFSGLDATLX	=	0xe6f1
                    E6F2    546 _XGPIFSGLDATLNOX	=	0xe6f2
                    E6F3    547 _GPIFREADYCFG	=	0xe6f3
                    E6F4    548 _GPIFREADYSTAT	=	0xe6f4
                    E6F5    549 _GPIFABORT	=	0xe6f5
                    E6C6    550 _FLOWSTATE	=	0xe6c6
                    E6C7    551 _FLOWLOGIC	=	0xe6c7
                    E6C8    552 _FLOWEQ0CTL	=	0xe6c8
                    E6C9    553 _FLOWEQ1CTL	=	0xe6c9
                    E6CA    554 _FLOWHOLDOFF	=	0xe6ca
                    E6CB    555 _FLOWSTB	=	0xe6cb
                    E6CC    556 _FLOWSTBEDGE	=	0xe6cc
                    E6CD    557 _FLOWSTBHPERIOD	=	0xe6cd
                    E60C    558 _GPIFHOLDAMOUNT	=	0xe60c
                    E67D    559 _UDMACRCH	=	0xe67d
                    E67E    560 _UDMACRCL	=	0xe67e
                    E67F    561 _UDMACRCQUAL	=	0xe67f
                    E6F8    562 _DBUG	=	0xe6f8
                    E6F9    563 _TESTCFG	=	0xe6f9
                    E6FA    564 _USBTEST	=	0xe6fa
                    E6FB    565 _CT1	=	0xe6fb
                    E6FC    566 _CT2	=	0xe6fc
                    E6FD    567 _CT3	=	0xe6fd
                    E6FE    568 _CT4	=	0xe6fe
                    E740    569 _EP0BUF	=	0xe740
                    E780    570 _EP1OUTBUF	=	0xe780
                    E7C0    571 _EP1INBUF	=	0xe7c0
                    F000    572 _EP2FIFOBUF	=	0xf000
                    F400    573 _EP4FIFOBUF	=	0xf400
                    F800    574 _EP6FIFOBUF	=	0xf800
                    FC00    575 _EP8FIFOBUF	=	0xfc00
                            576 ;--------------------------------------------------------
                            577 ; absolute external ram data
                            578 ;--------------------------------------------------------
                            579 	.area XABS    (ABS,XDATA)
                            580 ;--------------------------------------------------------
                            581 ; external initialized ram data
                            582 ;--------------------------------------------------------
                            583 	.area XISEG   (XDATA)
                            584 	.area HOME    (CODE)
                            585 	.area GSINIT0 (CODE)
                            586 	.area GSINIT1 (CODE)
                            587 	.area GSINIT2 (CODE)
                            588 	.area GSINIT3 (CODE)
                            589 	.area GSINIT4 (CODE)
                            590 	.area GSINIT5 (CODE)
                            591 	.area GSINIT  (CODE)
                            592 	.area GSFINAL (CODE)
                            593 	.area CSEG    (CODE)
                            594 ;--------------------------------------------------------
                            595 ; interrupt vector 
                            596 ;--------------------------------------------------------
                            597 	.area HOME    (CODE)
   0000                     598 __interrupt_vect:
   0000 02 00 08            599 	ljmp	__sdcc_gsinit_startup
                            600 ;--------------------------------------------------------
                            601 ; global & static initialisations
                            602 ;--------------------------------------------------------
                            603 	.area HOME    (CODE)
                            604 	.area GSINIT  (CODE)
                            605 	.area GSFINAL (CODE)
                            606 	.area GSINIT  (CODE)
                            607 	.globl __sdcc_gsinit_startup
                            608 	.globl __sdcc_program_startup
                            609 	.globl __start__stack
                            610 	.globl __mcs51_genXINIT
                            611 	.globl __mcs51_genXRAMCLEAR
                            612 	.globl __mcs51_genRAMCLEAR
                            613 ;	eeprom_read.h:14: xdata unsigned char *err =(xdata char*)0x1200;
   0061 75 22 00            614 	mov	_err,#0x00
   0064 75 23 12            615 	mov	(_err + 1),#0x12
                            616 ;	eeprom_read.h:15: xdata unsigned char *dat =(xdata char*)0x1000;
   0067 75 24 00            617 	mov	_dat,#0x00
   006A 75 25 10            618 	mov	(_dat + 1),#0x10
                            619 ;	eeprom_read.h:119: xdata unsigned char *command = (xdata unsigned char *)0x1100;
   006D 75 26 00            620 	mov	_command,#0x00
   0070 75 27 11            621 	mov	(_command + 1),#0x11
                            622 ;	eeprom_read.h:120: xdata unsigned char *HWmark = (xdata unsigned char *)0x1140;
   0073 75 28 40            623 	mov	_HWmark,#0x40
   0076 75 29 11            624 	mov	(_HWmark + 1),#0x11
                            625 ;	eeprom_mark.c:19: char *FWmark = "FWEEPRv000.001";
   0079 75 2D 4C            626 	mov	_FWmark,#__str_4
   007C 75 2E 0F            627 	mov	(_FWmark + 1),#(__str_4 >> 8)
   007F 75 2F 80            628 	mov	(_FWmark + 2),#0x80
                            629 	.area GSFINAL (CODE)
   0082 02 00 03            630 	ljmp	__sdcc_program_startup
                            631 ;--------------------------------------------------------
                            632 ; Home
                            633 ;--------------------------------------------------------
                            634 	.area HOME    (CODE)
                            635 	.area HOME    (CODE)
   0003                     636 __sdcc_program_startup:
   0003 12 06 DF            637 	lcall	_main
                            638 ;	return from main will lock up
   0006 80 FE               639 	sjmp .
                            640 ;--------------------------------------------------------
                            641 ; code
                            642 ;--------------------------------------------------------
                            643 	.area CSEG    (CODE)
                            644 ;------------------------------------------------------------
                            645 ;Allocation info for local variables in function 'EERead'
                            646 ;------------------------------------------------------------
                            647 ;HWmark                    Allocated with name '_EERead_PARM_2'
                            648 ;ee_adr                    Allocated to registers r6 r7 
                            649 ;n                         Allocated with name '_EERead_n_1_36'
                            650 ;------------------------------------------------------------
                            651 ;	eeprom_read.h:34: static uint8 EERead(uint16 ee_adr, 	unsigned char HWmark[32])
                            652 ;	-----------------------------------------
                            653 ;	 function EERead
                            654 ;	-----------------------------------------
   0085                     655 _EERead:
                    0007    656 	ar7 = 0x07
                    0006    657 	ar6 = 0x06
                    0005    658 	ar5 = 0x05
                    0004    659 	ar4 = 0x04
                    0003    660 	ar3 = 0x03
                    0002    661 	ar2 = 0x02
                    0001    662 	ar1 = 0x01
                    0000    663 	ar0 = 0x00
   0085 AE 82               664 	mov	r6,dpl
   0087 AF 83               665 	mov	r7,dph
                            666 ;	eeprom_read.h:39: I2CS = I2CS_START;
   0089 90 E6 78            667 	mov	dptr,#_I2CS
   008C 74 80               668 	mov	a,#0x80
   008E F0                  669 	movx	@dptr,a
                            670 ;	eeprom_read.h:40: I2DAT = EEPROM_ADR | I2CWRITE;
   008F 90 E6 79            671 	mov	dptr,#_I2DAT
   0092 74 A2               672 	mov	a,#0xA2
   0094 F0                  673 	movx	@dptr,a
                            674 ;	eeprom_read.h:41: while(!(I2CS & I2CS_DONE));
   0095                     675 00101$:
   0095 90 E6 78            676 	mov	dptr,#_I2CS
   0098 E0                  677 	movx	a,@dptr
   0099 FD                  678 	mov	r5,a
   009A 30 E0 F8            679 	jnb	acc.0,00101$
                            680 ;	eeprom_read.h:44: if(!(I2CS & I2CS_ACK)) return(1);
   009D 90 E6 78            681 	mov	dptr,#_I2CS
   00A0 E0                  682 	movx	a,@dptr
   00A1 FD                  683 	mov	r5,a
   00A2 20 E1 04            684 	jb	acc.1,00105$
   00A5 75 82 01            685 	mov	dpl,#0x01
   00A8 22                  686 	ret
   00A9                     687 00105$:
                            688 ;	eeprom_read.h:47: I2DAT = (ee_adr>>8);
   00A9 90 E6 79            689 	mov	dptr,#_I2DAT
   00AC EF                  690 	mov	a,r7
   00AD F0                  691 	movx	@dptr,a
                            692 ;	eeprom_read.h:48: while(!(I2CS & I2CS_DONE));
   00AE                     693 00106$:
   00AE 90 E6 78            694 	mov	dptr,#_I2CS
   00B1 E0                  695 	movx	a,@dptr
   00B2 FD                  696 	mov	r5,a
   00B3 30 E0 F8            697 	jnb	acc.0,00106$
                            698 ;	eeprom_read.h:51: if(!(I2CS & I2CS_ACK)) return(2);
   00B6 90 E6 78            699 	mov	dptr,#_I2CS
   00B9 E0                  700 	movx	a,@dptr
   00BA FD                  701 	mov	r5,a
   00BB 20 E1 04            702 	jb	acc.1,00110$
   00BE 75 82 02            703 	mov	dpl,#0x02
   00C1 22                  704 	ret
   00C2                     705 00110$:
                            706 ;	eeprom_read.h:54: I2DAT = (ee_adr & 0xff);
   00C2 7F 00               707 	mov	r7,#0x00
   00C4 90 E6 79            708 	mov	dptr,#_I2DAT
   00C7 EE                  709 	mov	a,r6
   00C8 F0                  710 	movx	@dptr,a
                            711 ;	eeprom_read.h:55: while(!(I2CS & I2CS_DONE));
   00C9                     712 00111$:
   00C9 90 E6 78            713 	mov	dptr,#_I2CS
   00CC E0                  714 	movx	a,@dptr
   00CD FF                  715 	mov	r7,a
   00CE 30 E0 F8            716 	jnb	acc.0,00111$
                            717 ;	eeprom_read.h:58: if(!(I2CS & I2CS_ACK)) return(3);
   00D1 90 E6 78            718 	mov	dptr,#_I2CS
   00D4 E0                  719 	movx	a,@dptr
   00D5 FF                  720 	mov	r7,a
   00D6 20 E1 04            721 	jb	acc.1,00115$
   00D9 75 82 03            722 	mov	dpl,#0x03
   00DC 22                  723 	ret
   00DD                     724 00115$:
                            725 ;	eeprom_read.h:61: I2CS = I2CS_START;
   00DD 90 E6 78            726 	mov	dptr,#_I2CS
   00E0 74 80               727 	mov	a,#0x80
   00E2 F0                  728 	movx	@dptr,a
                            729 ;	eeprom_read.h:62: I2DAT = EEPROM_ADR | I2CREAD;
   00E3 90 E6 79            730 	mov	dptr,#_I2DAT
   00E6 74 A3               731 	mov	a,#0xA3
   00E8 F0                  732 	movx	@dptr,a
                            733 ;	eeprom_read.h:63: while(!(I2CS & I2CS_DONE));
   00E9                     734 00116$:
   00E9 90 E6 78            735 	mov	dptr,#_I2CS
   00EC E0                  736 	movx	a,@dptr
   00ED FF                  737 	mov	r7,a
   00EE 30 E0 F8            738 	jnb	acc.0,00116$
                            739 ;	eeprom_read.h:66: if(!(I2CS & I2CS_ACK)) return(5);
   00F1 90 E6 78            740 	mov	dptr,#_I2CS
   00F4 E0                  741 	movx	a,@dptr
   00F5 FF                  742 	mov	r7,a
   00F6 20 E1 04            743 	jb	acc.1,00120$
   00F9 75 82 05            744 	mov	dpl,#0x05
   00FC 22                  745 	ret
   00FD                     746 00120$:
                            747 ;	eeprom_read.h:69: HWmark[0] = I2DAT;
   00FD AD 10               748 	mov	r5,_EERead_PARM_2
   00FF AE 11               749 	mov	r6,(_EERead_PARM_2 + 1)
   0101 AF 12               750 	mov	r7,(_EERead_PARM_2 + 2)
   0103 90 E6 79            751 	mov	dptr,#_I2DAT
   0106 E0                  752 	movx	a,@dptr
   0107 FC                  753 	mov	r4,a
   0108 8D 82               754 	mov	dpl,r5
   010A 8E 83               755 	mov	dph,r6
   010C 8F F0               756 	mov	b,r7
   010E 12 08 12            757 	lcall	__gptrput
                            758 ;	eeprom_read.h:70: while(!(I2CS & I2CS_DONE));
   0111                     759 00121$:
   0111 90 E6 78            760 	mov	dptr,#_I2CS
   0114 E0                  761 	movx	a,@dptr
   0115 FC                  762 	mov	r4,a
   0116 30 E0 F8            763 	jnb	acc.0,00121$
                            764 ;	eeprom_read.h:71: if(!(I2CS & I2CS_ACK)) return(6);
   0119 90 E6 78            765 	mov	dptr,#_I2CS
   011C E0                  766 	movx	a,@dptr
   011D FC                  767 	mov	r4,a
   011E 20 E1 04            768 	jb	acc.1,00126$
   0121 75 82 06            769 	mov	dpl,#0x06
   0124 22                  770 	ret
                            771 ;	eeprom_read.h:74: while(!(I2CS & I2CS_DONE));
   0125                     772 00126$:
   0125 90 E6 78            773 	mov	dptr,#_I2CS
   0128 E0                  774 	movx	a,@dptr
   0129 FC                  775 	mov	r4,a
   012A 30 E0 F8            776 	jnb	acc.0,00126$
                            777 ;	eeprom_read.h:75: if(!(I2CS & I2CS_ACK)) return(7);
   012D 90 E6 78            778 	mov	dptr,#_I2CS
   0130 E0                  779 	movx	a,@dptr
   0131 FC                  780 	mov	r4,a
   0132 20 E1 04            781 	jb	acc.1,00130$
   0135 75 82 07            782 	mov	dpl,#0x07
   0138 22                  783 	ret
   0139                     784 00130$:
                            785 ;	eeprom_read.h:77: HWmark[0] = I2DAT;
   0139 90 E6 79            786 	mov	dptr,#_I2DAT
   013C E0                  787 	movx	a,@dptr
   013D FC                  788 	mov	r4,a
   013E 8D 82               789 	mov	dpl,r5
   0140 8E 83               790 	mov	dph,r6
   0142 8F F0               791 	mov	b,r7
   0144 12 08 12            792 	lcall	__gptrput
                            793 ;	eeprom_read.h:78: while(!(I2CS & I2CS_DONE));
   0147                     794 00131$:
   0147 90 E6 78            795 	mov	dptr,#_I2CS
   014A E0                  796 	movx	a,@dptr
   014B FC                  797 	mov	r4,a
   014C 30 E0 F8            798 	jnb	acc.0,00131$
                            799 ;	eeprom_read.h:79: if(!(I2CS & I2CS_ACK)) return(8);
   014F 90 E6 78            800 	mov	dptr,#_I2CS
   0152 E0                  801 	movx	a,@dptr
   0153 FC                  802 	mov	r4,a
   0154 20 E1 04            803 	jb	acc.1,00135$
   0157 75 82 08            804 	mov	dpl,#0x08
   015A 22                  805 	ret
   015B                     806 00135$:
                            807 ;	eeprom_read.h:81: HWmark[1] = I2DAT;
   015B 74 01               808 	mov	a,#0x01
   015D 2D                  809 	add	a,r5
   015E FA                  810 	mov	r2,a
   015F E4                  811 	clr	a
   0160 3E                  812 	addc	a,r6
   0161 FB                  813 	mov	r3,a
   0162 8F 04               814 	mov	ar4,r7
   0164 90 E6 79            815 	mov	dptr,#_I2DAT
   0167 E0                  816 	movx	a,@dptr
   0168 F9                  817 	mov	r1,a
   0169 8A 82               818 	mov	dpl,r2
   016B 8B 83               819 	mov	dph,r3
   016D 8C F0               820 	mov	b,r4
   016F 12 08 12            821 	lcall	__gptrput
                            822 ;	eeprom_read.h:82: while(!(I2CS & I2CS_DONE));
   0172                     823 00136$:
   0172 90 E6 78            824 	mov	dptr,#_I2CS
   0175 E0                  825 	movx	a,@dptr
   0176 FC                  826 	mov	r4,a
   0177 30 E0 F8            827 	jnb	acc.0,00136$
                            828 ;	eeprom_read.h:83: if(!(I2CS & I2CS_ACK)) return(8);
   017A 90 E6 78            829 	mov	dptr,#_I2CS
   017D E0                  830 	movx	a,@dptr
   017E FC                  831 	mov	r4,a
   017F 20 E1 04            832 	jb	acc.1,00193$
   0182 75 82 08            833 	mov	dpl,#0x08
   0185 22                  834 	ret
                            835 ;	eeprom_read.h:85: for(n = 2;n<31;n++) {
   0186                     836 00193$:
   0186 75 13 02            837 	mov	_EERead_n_1_36,#0x02
   0189 75 14 00            838 	mov	(_EERead_n_1_36 + 1),#0x00
   018C                     839 00159$:
   018C C3                  840 	clr	c
   018D E5 13               841 	mov	a,_EERead_n_1_36
   018F 94 1F               842 	subb	a,#0x1F
   0191 E5 14               843 	mov	a,(_EERead_n_1_36 + 1)
   0193 64 80               844 	xrl	a,#0x80
   0195 94 80               845 	subb	a,#0x80
   0197 50 36               846 	jnc	00162$
                            847 ;	eeprom_read.h:86: HWmark[n] = I2DAT;
   0199 E5 13               848 	mov	a,_EERead_n_1_36
   019B 2D                  849 	add	a,r5
   019C F8                  850 	mov	r0,a
   019D E5 14               851 	mov	a,(_EERead_n_1_36 + 1)
   019F 3E                  852 	addc	a,r6
   01A0 F9                  853 	mov	r1,a
   01A1 8F 02               854 	mov	ar2,r7
   01A3 90 E6 79            855 	mov	dptr,#_I2DAT
   01A6 E0                  856 	movx	a,@dptr
   01A7 FC                  857 	mov	r4,a
   01A8 88 82               858 	mov	dpl,r0
   01AA 89 83               859 	mov	dph,r1
   01AC 8A F0               860 	mov	b,r2
   01AE 12 08 12            861 	lcall	__gptrput
                            862 ;	eeprom_read.h:87: while(!(I2CS & I2CS_DONE));
   01B1                     863 00141$:
   01B1 90 E6 78            864 	mov	dptr,#_I2CS
   01B4 E0                  865 	movx	a,@dptr
   01B5 FC                  866 	mov	r4,a
   01B6 30 E0 F8            867 	jnb	acc.0,00141$
                            868 ;	eeprom_read.h:88: if(!(I2CS & I2CS_ACK)) return(9);
   01B9 90 E6 78            869 	mov	dptr,#_I2CS
   01BC E0                  870 	movx	a,@dptr
   01BD FC                  871 	mov	r4,a
   01BE 20 E1 04            872 	jb	acc.1,00161$
   01C1 75 82 09            873 	mov	dpl,#0x09
   01C4 22                  874 	ret
   01C5                     875 00161$:
                            876 ;	eeprom_read.h:85: for(n = 2;n<31;n++) {
   01C5 05 13               877 	inc	_EERead_n_1_36
   01C7 E4                  878 	clr	a
   01C8 B5 13 C1            879 	cjne	a,_EERead_n_1_36,00159$
   01CB 05 14               880 	inc	(_EERead_n_1_36 + 1)
   01CD 80 BD               881 	sjmp	00159$
   01CF                     882 00162$:
                            883 ;	eeprom_read.h:91: I2CS = I2CS_LASTRD;
   01CF 90 E6 78            884 	mov	dptr,#_I2CS
   01D2 74 20               885 	mov	a,#0x20
   01D4 F0                  886 	movx	@dptr,a
                            887 ;	eeprom_read.h:92: HWmark[31] = I2DAT;
   01D5 74 1F               888 	mov	a,#0x1F
   01D7 2D                  889 	add	a,r5
   01D8 FD                  890 	mov	r5,a
   01D9 E4                  891 	clr	a
   01DA 3E                  892 	addc	a,r6
   01DB FE                  893 	mov	r6,a
   01DC 90 E6 79            894 	mov	dptr,#_I2DAT
   01DF E0                  895 	movx	a,@dptr
   01E0 FC                  896 	mov	r4,a
   01E1 8D 82               897 	mov	dpl,r5
   01E3 8E 83               898 	mov	dph,r6
   01E5 8F F0               899 	mov	b,r7
   01E7 12 08 12            900 	lcall	__gptrput
                            901 ;	eeprom_read.h:93: while(!(I2CS & I2CS_DONE));
   01EA                     902 00146$:
   01EA 90 E6 78            903 	mov	dptr,#_I2CS
   01ED E0                  904 	movx	a,@dptr
   01EE FC                  905 	mov	r4,a
   01EF 30 E0 F8            906 	jnb	acc.0,00146$
                            907 ;	eeprom_read.h:94: HWmark[31] = I2DAT;
   01F2 90 E6 79            908 	mov	dptr,#_I2DAT
   01F5 E0                  909 	movx	a,@dptr
   01F6 FC                  910 	mov	r4,a
   01F7 8D 82               911 	mov	dpl,r5
   01F9 8E 83               912 	mov	dph,r6
   01FB 8F F0               913 	mov	b,r7
   01FD 12 08 12            914 	lcall	__gptrput
                            915 ;	eeprom_read.h:95: while(!(I2CS & I2CS_DONE));
   0200                     916 00149$:
   0200 90 E6 78            917 	mov	dptr,#_I2CS
   0203 E0                  918 	movx	a,@dptr
   0204 FF                  919 	mov	r7,a
   0205 30 E0 F8            920 	jnb	acc.0,00149$
                            921 ;	eeprom_read.h:96: if(!(I2CS & I2CS_ACK)) return(10);
   0208 90 E6 78            922 	mov	dptr,#_I2CS
   020B E0                  923 	movx	a,@dptr
   020C FF                  924 	mov	r7,a
   020D 20 E1 04            925 	jb	acc.1,00153$
   0210 75 82 0A            926 	mov	dpl,#0x0A
   0213 22                  927 	ret
   0214                     928 00153$:
                            929 ;	eeprom_read.h:107: I2CS = I2CS_STOP;
   0214 90 E6 78            930 	mov	dptr,#_I2CS
   0217 74 40               931 	mov	a,#0x40
   0219 F0                  932 	movx	@dptr,a
                            933 ;	eeprom_read.h:108: while(!(I2CS & I2CS_DONE));
   021A                     934 00154$:
   021A 90 E6 78            935 	mov	dptr,#_I2CS
   021D E0                  936 	movx	a,@dptr
   021E FF                  937 	mov	r7,a
   021F 30 E0 F8            938 	jnb	acc.0,00154$
                            939 ;	eeprom_read.h:110: if(!(I2CS & I2CS_ACK)) return(11);
   0222 90 E6 78            940 	mov	dptr,#_I2CS
   0225 E0                  941 	movx	a,@dptr
   0226 FF                  942 	mov	r7,a
   0227 20 E1 04            943 	jb	acc.1,00158$
   022A 75 82 0B            944 	mov	dpl,#0x0B
   022D 22                  945 	ret
   022E                     946 00158$:
                            947 ;	eeprom_read.h:112: return(64);
   022E 75 82 40            948 	mov	dpl,#0x40
   0231 22                  949 	ret
                            950 ;------------------------------------------------------------
                            951 ;Allocation info for local variables in function 'readmarkeeprom'
                            952 ;------------------------------------------------------------
                            953 ;n                         Allocated to registers r6 r7 
                            954 ;------------------------------------------------------------
                            955 ;	eeprom_read.h:123: static uint8 readmarkeeprom(void) {
                            956 ;	-----------------------------------------
                            957 ;	 function readmarkeeprom
                            958 ;	-----------------------------------------
   0232                     959 _readmarkeeprom:
                            960 ;	eeprom_read.h:127: I2CTL = 0x01;	// Set 400kHz:
   0232 90 E6 7A            961 	mov	dptr,#_I2CTL
   0235 74 01               962 	mov	a,#0x01
   0237 F0                  963 	movx	@dptr,a
                            964 ;	eeprom_read.h:128: SYNCDELAY;
   0238 00                  965 	nop; 
                            966 ;	eeprom_read.h:130: for(n=0;n<128;n++) HWmark[n] = 0x00;
   0239 7E 00               967 	mov	r6,#0x00
   023B 7F 00               968 	mov	r7,#0x00
   023D                     969 00101$:
   023D C3                  970 	clr	c
   023E EE                  971 	mov	a,r6
   023F 94 80               972 	subb	a,#0x80
   0241 EF                  973 	mov	a,r7
   0242 64 80               974 	xrl	a,#0x80
   0244 94 80               975 	subb	a,#0x80
   0246 50 13               976 	jnc	00104$
   0248 EE                  977 	mov	a,r6
   0249 25 28               978 	add	a,_HWmark
   024B F5 82               979 	mov	dpl,a
   024D EF                  980 	mov	a,r7
   024E 35 29               981 	addc	a,(_HWmark + 1)
   0250 F5 83               982 	mov	dph,a
   0252 E4                  983 	clr	a
   0253 F0                  984 	movx	@dptr,a
   0254 0E                  985 	inc	r6
   0255 BE 00 E5            986 	cjne	r6,#0x00,00101$
   0258 0F                  987 	inc	r7
   0259 80 E2               988 	sjmp	00101$
   025B                     989 00104$:
                            990 ;	eeprom_read.h:131: err[32+3] = EERead( 0x0400,HWmark);
   025B 74 23               991 	mov	a,#0x23
   025D 25 22               992 	add	a,_err
   025F FE                  993 	mov	r6,a
   0260 E4                  994 	clr	a
   0261 35 23               995 	addc	a,(_err + 1)
   0263 FF                  996 	mov	r7,a
   0264 85 28 10            997 	mov	_EERead_PARM_2,_HWmark
   0267 85 29 11            998 	mov	(_EERead_PARM_2 + 1),(_HWmark + 1)
   026A 75 12 00            999 	mov	(_EERead_PARM_2 + 2),#0x00
   026D 90 04 00           1000 	mov	dptr,#0x0400
   0270 C0 07              1001 	push	ar7
   0272 C0 06              1002 	push	ar6
   0274 12 00 85           1003 	lcall	_EERead
   0277 AD 82              1004 	mov	r5,dpl
   0279 D0 06              1005 	pop	ar6
   027B D0 07              1006 	pop	ar7
   027D 8E 82              1007 	mov	dpl,r6
   027F 8F 83              1008 	mov	dph,r7
   0281 ED                 1009 	mov	a,r5
   0282 F0                 1010 	movx	@dptr,a
                           1011 ;	eeprom_read.h:132: return(0);
   0283 75 82 00           1012 	mov	dpl,#0x00
   0286 22                 1013 	ret
                           1014 ;------------------------------------------------------------
                           1015 ;Allocation info for local variables in function 'hostreadmarkep1init'
                           1016 ;------------------------------------------------------------
                           1017 ;	eeprom_read.h:136: static uint8 hostreadmarkep1init(void) {
                           1018 ;	-----------------------------------------
                           1019 ;	 function hostreadmarkep1init
                           1020 ;	-----------------------------------------
   0287                    1021 _hostreadmarkep1init:
                           1022 ;	eeprom_read.h:138: EP1OUTCFG=0xa0;
   0287 90 E6 10           1023 	mov	dptr,#_EP1OUTCFG
   028A 74 A0              1024 	mov	a,#0xA0
   028C F0                 1025 	movx	@dptr,a
                           1026 ;	eeprom_read.h:139: EP1INCFG=0xa0;
   028D 90 E6 11           1027 	mov	dptr,#_EP1INCFG
   0290 74 A0              1028 	mov	a,#0xA0
   0292 F0                 1029 	movx	@dptr,a
                           1030 ;	eeprom_read.h:141: SYNCDELAY;
   0293 00                 1031 	nop; 
                           1032 ;	eeprom_read.h:142: EP1OUTBC=0xff; // Arm endpoint 1 for OUT (host->device) transfers
   0294 90 E6 8D           1033 	mov	dptr,#_EP1OUTBC
   0297 74 FF              1034 	mov	a,#0xFF
   0299 F0                 1035 	movx	@dptr,a
                           1036 ;	eeprom_read.h:144: return(0);
   029A 75 82 00           1037 	mov	dpl,#0x00
   029D 22                 1038 	ret
                           1039 ;------------------------------------------------------------
                           1040 ;Allocation info for local variables in function 'hostreadmarkep1poll'
                           1041 ;------------------------------------------------------------
                           1042 ;src                       Allocated to registers 
                           1043 ;dest                      Allocated to registers r5 r6 
                           1044 ;ep1outbc                  Allocated with name '_hostreadmarkep1poll_ep1outbc_1_46'
                           1045 ;n                         Allocated with name '_hostreadmarkep1poll_n_1_46'
                           1046 ;------------------------------------------------------------
                           1047 ;	eeprom_read.h:147: static uint8 hostreadmarkep1poll(void) {
                           1048 ;	-----------------------------------------
                           1049 ;	 function hostreadmarkep1poll
                           1050 ;	-----------------------------------------
   029E                    1051 _hostreadmarkep1poll:
                           1052 ;	eeprom_read.h:153: if(!(EP1OUTCS & bmEPBUSY)) {
   029E 90 E6 A1           1053 	mov	dptr,#_EP1OUTCS
   02A1 E0                 1054 	movx	a,@dptr
   02A2 FF                 1055 	mov	r7,a
   02A3 30 E1 03           1056 	jnb	acc.1,00169$
   02A6 02 04 37           1057 	ljmp	00114$
   02A9                    1058 00169$:
                           1059 ;	eeprom_read.h:154: ep1outbc = EP1OUTBC;
   02A9 90 E6 8D           1060 	mov	dptr,#_EP1OUTBC
   02AC E0                 1061 	movx	a,@dptr
   02AD F5 2A              1062 	mov	_hostreadmarkep1poll_ep1outbc_1_46,a
                           1063 ;	eeprom_read.h:155: if(ep1outbc != 0xff ) {
   02AF 74 FF              1064 	mov	a,#0xFF
   02B1 B5 2A 03           1065 	cjne	a,_hostreadmarkep1poll_ep1outbc_1_46,00170$
   02B4 02 04 37           1066 	ljmp	00114$
   02B7                    1067 00170$:
                           1068 ;	eeprom_read.h:156: src = EP1OUTBUF;
                           1069 ;	eeprom_read.h:157: dest = EP1INBUF;
   02B7 7D C0              1070 	mov	r5,#_EP1INBUF
   02B9 7E E7              1071 	mov	r6,#(_EP1INBUF >> 8)
                           1072 ;	eeprom_read.h:158: while (EP1INCS & 0x02);
   02BB                    1073 00101$:
   02BB 90 E6 A2           1074 	mov	dptr,#_EP1INCS
   02BE E0                 1075 	movx	a,@dptr
   02BF FC                 1076 	mov	r4,a
   02C0 20 E1 F8           1077 	jb	acc.1,00101$
                           1078 ;	eeprom_read.h:159: for(n=0; n<32; n++) command[n] = src[n];
   02C3 7B 00              1079 	mov	r3,#0x00
   02C5 7C 00              1080 	mov	r4,#0x00
   02C7                    1081 00115$:
   02C7 C3                 1082 	clr	c
   02C8 EB                 1083 	mov	a,r3
   02C9 94 20              1084 	subb	a,#0x20
   02CB EC                 1085 	mov	a,r4
   02CC 64 80              1086 	xrl	a,#0x80
   02CE 94 80              1087 	subb	a,#0x80
   02D0 50 20              1088 	jnc	00118$
   02D2 EB                 1089 	mov	a,r3
   02D3 25 26              1090 	add	a,_command
   02D5 F9                 1091 	mov	r1,a
   02D6 EC                 1092 	mov	a,r4
   02D7 35 27              1093 	addc	a,(_command + 1)
   02D9 FA                 1094 	mov	r2,a
   02DA EB                 1095 	mov	a,r3
   02DB 24 80              1096 	add	a,#_EP1OUTBUF
   02DD F5 82              1097 	mov	dpl,a
   02DF EC                 1098 	mov	a,r4
   02E0 34 E7              1099 	addc	a,#(_EP1OUTBUF >> 8)
   02E2 F5 83              1100 	mov	dph,a
   02E4 E0                 1101 	movx	a,@dptr
   02E5 F8                 1102 	mov	r0,a
   02E6 89 82              1103 	mov	dpl,r1
   02E8 8A 83              1104 	mov	dph,r2
   02EA F0                 1105 	movx	@dptr,a
   02EB 0B                 1106 	inc	r3
   02EC BB 00 D8           1107 	cjne	r3,#0x00,00115$
   02EF 0C                 1108 	inc	r4
   02F0 80 D5              1109 	sjmp	00115$
   02F2                    1110 00118$:
                           1111 ;	eeprom_read.h:160: for( n=0; n < ep1outbc ; n++ ) { 
   02F2 8D 03              1112 	mov	ar3,r5
   02F4 8E 04              1113 	mov	ar4,r6
   02F6 79 00              1114 	mov	r1,#0x00
   02F8 7A 00              1115 	mov	r2,#0x00
   02FA                    1116 00119$:
   02FA A8 2A              1117 	mov	r0,_hostreadmarkep1poll_ep1outbc_1_46
   02FC 7F 00              1118 	mov	r7,#0x00
   02FE C3                 1119 	clr	c
   02FF E9                 1120 	mov	a,r1
   0300 98                 1121 	subb	a,r0
   0301 EA                 1122 	mov	a,r2
   0302 64 80              1123 	xrl	a,#0x80
   0304 8F F0              1124 	mov	b,r7
   0306 63 F0 80           1125 	xrl	b,#0x80
   0309 95 F0              1126 	subb	a,b
   030B 50 1D              1127 	jnc	00122$
                           1128 ;	eeprom_read.h:161: *dest++ = command[n];
   030D E9                 1129 	mov	a,r1
   030E 25 26              1130 	add	a,_command
   0310 F5 82              1131 	mov	dpl,a
   0312 EA                 1132 	mov	a,r2
   0313 35 27              1133 	addc	a,(_command + 1)
   0315 F5 83              1134 	mov	dph,a
   0317 E0                 1135 	movx	a,@dptr
   0318 FF                 1136 	mov	r7,a
   0319 8B 82              1137 	mov	dpl,r3
   031B 8C 83              1138 	mov	dph,r4
   031D F0                 1139 	movx	@dptr,a
   031E A3                 1140 	inc	dptr
   031F AB 82              1141 	mov	r3,dpl
   0321 AC 83              1142 	mov	r4,dph
                           1143 ;	eeprom_read.h:160: for( n=0; n < ep1outbc ; n++ ) { 
   0323 09                 1144 	inc	r1
   0324 B9 00 D3           1145 	cjne	r1,#0x00,00119$
   0327 0A                 1146 	inc	r2
   0328 80 D0              1147 	sjmp	00119$
   032A                    1148 00122$:
                           1149 ;	eeprom_read.h:163: *err++ = 0x5a;
   032A 85 22 82           1150 	mov	dpl,_err
   032D 85 23 83           1151 	mov	dph,(_err + 1)
   0330 74 5A              1152 	mov	a,#0x5A
   0332 F0                 1153 	movx	@dptr,a
   0333 05 22              1154 	inc	_err
   0335 E4                 1155 	clr	a
   0336 B5 22 02           1156 	cjne	a,_err,00176$
   0339 05 23              1157 	inc	(_err + 1)
   033B                    1158 00176$:
                           1159 ;	eeprom_read.h:164: EP1INBC = ep1outbc;
   033B 90 E6 8F           1160 	mov	dptr,#_EP1INBC
   033E E5 2A              1161 	mov	a,_hostreadmarkep1poll_ep1outbc_1_46
   0340 F0                 1162 	movx	@dptr,a
                           1163 ;	eeprom_read.h:165: while (EP1INCS & 0x02);
   0341                    1164 00104$:
   0341 90 E6 A2           1165 	mov	dptr,#_EP1INCS
   0344 E0                 1166 	movx	a,@dptr
   0345 FF                 1167 	mov	r7,a
   0346 20 E1 F8           1168 	jb	acc.1,00104$
                           1169 ;	eeprom_read.h:166: dest = EP1INBUF;
   0349 7D C0              1170 	mov	r5,#_EP1INBUF
   034B 7E E7              1171 	mov	r6,#(_EP1INBUF >> 8)
                           1172 ;	eeprom_read.h:167: if(!strncmp(command,"getHW",5)) {
   034D AB 26              1173 	mov	r3,_command
   034F AC 27              1174 	mov	r4,(_command + 1)
   0351 7F 00              1175 	mov	r7,#0x00
   0353 75 10 22           1176 	mov	_strncmp_PARM_2,#__str_0
   0356 75 11 0F           1177 	mov	(_strncmp_PARM_2 + 1),#(__str_0 >> 8)
   0359 75 12 80           1178 	mov	(_strncmp_PARM_2 + 2),#0x80
   035C 75 13 05           1179 	mov	_strncmp_PARM_3,#0x05
   035F 75 14 00           1180 	mov	(_strncmp_PARM_3 + 1),#0x00
   0362 8B 82              1181 	mov	dpl,r3
   0364 8C 83              1182 	mov	dph,r4
   0366 8F F0              1183 	mov	b,r7
   0368 C0 06              1184 	push	ar6
   036A C0 05              1185 	push	ar5
   036C 12 07 93           1186 	lcall	_strncmp
   036F E5 82              1187 	mov	a,dpl
   0371 85 83 F0           1188 	mov	b,dph
   0374 D0 05              1189 	pop	ar5
   0376 D0 06              1190 	pop	ar6
   0378 45 F0              1191 	orl	a,b
                           1192 ;	eeprom_read.h:168: for( n=0; HWmark[n] != '\0' ; n++ )  
   037A 70 40              1193 	jnz	00108$
   037C 8D 04              1194 	mov	ar4,r5
   037E 8E 07              1195 	mov	ar7,r6
   0380 FA                 1196 	mov	r2,a
   0381 FB                 1197 	mov	r3,a
   0382                    1198 00123$:
   0382 EA                 1199 	mov	a,r2
   0383 25 28              1200 	add	a,_HWmark
   0385 F5 82              1201 	mov	dpl,a
   0387 EB                 1202 	mov	a,r3
   0388 35 29              1203 	addc	a,(_HWmark + 1)
   038A F5 83              1204 	mov	dph,a
   038C E0                 1205 	movx	a,@dptr
   038D F9                 1206 	mov	r1,a
   038E 60 12              1207 	jz	00126$
                           1208 ;	eeprom_read.h:169: *dest++ = (xdata unsigned char) HWmark[n];					
   0390 8C 82              1209 	mov	dpl,r4
   0392 8F 83              1210 	mov	dph,r7
   0394 E9                 1211 	mov	a,r1
   0395 F0                 1212 	movx	@dptr,a
   0396 A3                 1213 	inc	dptr
   0397 AC 82              1214 	mov	r4,dpl
   0399 AF 83              1215 	mov	r7,dph
                           1216 ;	eeprom_read.h:168: for( n=0; HWmark[n] != '\0' ; n++ )  
   039B 0A                 1217 	inc	r2
   039C BA 00 E3           1218 	cjne	r2,#0x00,00123$
   039F 0B                 1219 	inc	r3
   03A0 80 E0              1220 	sjmp	00123$
   03A2                    1221 00126$:
                           1222 ;	eeprom_read.h:170: *dest++ = '\0';
   03A2 8C 82              1223 	mov	dpl,r4
   03A4 8F 83              1224 	mov	dph,r7
   03A6 E4                 1225 	clr	a
   03A7 F0                 1226 	movx	@dptr,a
   03A8 74 01              1227 	mov	a,#0x01
   03AA 2C                 1228 	add	a,r4
   03AB FD                 1229 	mov	r5,a
   03AC E4                 1230 	clr	a
   03AD 3F                 1231 	addc	a,r7
   03AE FE                 1232 	mov	r6,a
                           1233 ;	eeprom_read.h:171: n++;
   03AF 74 01              1234 	mov	a,#0x01
   03B1 2A                 1235 	add	a,r2
   03B2 FC                 1236 	mov	r4,a
   03B3 E4                 1237 	clr	a
   03B4 3B                 1238 	addc	a,r3
   03B5 FF                 1239 	mov	r7,a
                           1240 ;	eeprom_read.h:172: EP1INBC = n;
   03B6 90 E6 8F           1241 	mov	dptr,#_EP1INBC
   03B9 EC                 1242 	mov	a,r4
   03BA F0                 1243 	movx	@dptr,a
                           1244 ;	eeprom_read.h:173: SYNCDELAY;
   03BB 00                 1245 	nop; 
   03BC                    1246 00108$:
                           1247 ;	eeprom_read.h:175: if(!strncmp(command,"getFW",5)) {
   03BC A9 26              1248 	mov	r1,_command
   03BE AA 27              1249 	mov	r2,(_command + 1)
   03C0 7B 00              1250 	mov	r3,#0x00
   03C2 75 10 28           1251 	mov	_strncmp_PARM_2,#__str_1
   03C5 75 11 0F           1252 	mov	(_strncmp_PARM_2 + 1),#(__str_1 >> 8)
   03C8 75 12 80           1253 	mov	(_strncmp_PARM_2 + 2),#0x80
   03CB 75 13 05           1254 	mov	_strncmp_PARM_3,#0x05
   03CE 75 14 00           1255 	mov	(_strncmp_PARM_3 + 1),#0x00
   03D1 89 82              1256 	mov	dpl,r1
   03D3 8A 83              1257 	mov	dph,r2
   03D5 8B F0              1258 	mov	b,r3
   03D7 C0 06              1259 	push	ar6
   03D9 C0 05              1260 	push	ar5
   03DB 12 07 93           1261 	lcall	_strncmp
   03DE E5 82              1262 	mov	a,dpl
   03E0 85 83 F0           1263 	mov	b,dph
   03E3 D0 05              1264 	pop	ar5
   03E5 D0 06              1265 	pop	ar6
   03E7 45 F0              1266 	orl	a,b
                           1267 ;	eeprom_read.h:176: for( n=0; FWmark[n] != '\0' ; n++ )  
   03E9 70 46              1268 	jnz	00110$
   03EB F5 2B              1269 	mov	_hostreadmarkep1poll_n_1_46,a
   03ED F5 2C              1270 	mov	(_hostreadmarkep1poll_n_1_46 + 1),a
   03EF                    1271 00127$:
   03EF E5 2B              1272 	mov	a,_hostreadmarkep1poll_n_1_46
   03F1 25 2D              1273 	add	a,_FWmark
   03F3 F8                 1274 	mov	r0,a
   03F4 E5 2C              1275 	mov	a,(_hostreadmarkep1poll_n_1_46 + 1)
   03F6 35 2E              1276 	addc	a,(_FWmark + 1)
   03F8 F9                 1277 	mov	r1,a
   03F9 AB 2F              1278 	mov	r3,(_FWmark + 2)
   03FB 88 82              1279 	mov	dpl,r0
   03FD 89 83              1280 	mov	dph,r1
   03FF 8B F0              1281 	mov	b,r3
   0401 12 0F 02           1282 	lcall	__gptrget
   0404 FB                 1283 	mov	r3,a
   0405 60 15              1284 	jz	00130$
                           1285 ;	eeprom_read.h:177: *dest++ = (xdata unsigned char) FWmark[n];					
   0407 8D 82              1286 	mov	dpl,r5
   0409 8E 83              1287 	mov	dph,r6
   040B EB                 1288 	mov	a,r3
   040C F0                 1289 	movx	@dptr,a
   040D A3                 1290 	inc	dptr
   040E AD 82              1291 	mov	r5,dpl
   0410 AE 83              1292 	mov	r6,dph
                           1293 ;	eeprom_read.h:176: for( n=0; FWmark[n] != '\0' ; n++ )  
   0412 05 2B              1294 	inc	_hostreadmarkep1poll_n_1_46
   0414 E4                 1295 	clr	a
   0415 B5 2B D7           1296 	cjne	a,_hostreadmarkep1poll_n_1_46,00127$
   0418 05 2C              1297 	inc	(_hostreadmarkep1poll_n_1_46 + 1)
   041A 80 D3              1298 	sjmp	00127$
   041C                    1299 00130$:
                           1300 ;	eeprom_read.h:178: *dest++ = '\0';
   041C 8D 82              1301 	mov	dpl,r5
   041E 8E 83              1302 	mov	dph,r6
   0420 E4                 1303 	clr	a
   0421 F0                 1304 	movx	@dptr,a
                           1305 ;	eeprom_read.h:179: n++;
   0422 74 01              1306 	mov	a,#0x01
   0424 25 2B              1307 	add	a,_hostreadmarkep1poll_n_1_46
   0426 FC                 1308 	mov	r4,a
   0427 E4                 1309 	clr	a
   0428 35 2C              1310 	addc	a,(_hostreadmarkep1poll_n_1_46 + 1)
   042A FF                 1311 	mov	r7,a
                           1312 ;	eeprom_read.h:180: EP1INBC = n;
   042B 90 E6 8F           1313 	mov	dptr,#_EP1INBC
   042E EC                 1314 	mov	a,r4
   042F F0                 1315 	movx	@dptr,a
                           1316 ;	eeprom_read.h:181: SYNCDELAY;
   0430 00                 1317 	nop; 
   0431                    1318 00110$:
                           1319 ;	eeprom_read.h:183: EP1OUTBC = 0xff;
   0431 90 E6 8D           1320 	mov	dptr,#_EP1OUTBC
   0434 74 FF              1321 	mov	a,#0xFF
   0436 F0                 1322 	movx	@dptr,a
   0437                    1323 00114$:
                           1324 ;	eeprom_read.h:186: return(0);
   0437 75 82 00           1325 	mov	dpl,#0x00
   043A 22                 1326 	ret
                           1327 ;------------------------------------------------------------
                           1328 ;Allocation info for local variables in function 'EEErase'
                           1329 ;------------------------------------------------------------
                           1330 ;ee_adr                    Allocated to registers r6 r7 
                           1331 ;------------------------------------------------------------
                           1332 ;	eeprom_mark.c:47: static uint8 EEErase(uint16 ee_adr)
                           1333 ;	-----------------------------------------
                           1334 ;	 function EEErase
                           1335 ;	-----------------------------------------
   043B                    1336 _EEErase:
   043B AE 82              1337 	mov	r6,dpl
   043D AF 83              1338 	mov	r7,dph
                           1339 ;	eeprom_mark.c:49: I2CS = I2CS_START;
   043F 90 E6 78           1340 	mov	dptr,#_I2CS
   0442 74 80              1341 	mov	a,#0x80
   0444 F0                 1342 	movx	@dptr,a
                           1343 ;	eeprom_mark.c:50: I2DAT = EEPROM_ADR | I2CWRITE;
   0445 90 E6 79           1344 	mov	dptr,#_I2DAT
   0448 74 A2              1345 	mov	a,#0xA2
   044A F0                 1346 	movx	@dptr,a
                           1347 ;	eeprom_mark.c:51: while(!(I2CS & I2CS_DONE));
   044B                    1348 00101$:
   044B 90 E6 78           1349 	mov	dptr,#_I2CS
   044E E0                 1350 	movx	a,@dptr
   044F FD                 1351 	mov	r5,a
   0450 30 E0 F8           1352 	jnb	acc.0,00101$
                           1353 ;	eeprom_mark.c:54: if(!(I2CS & I2CS_ACK)) return(1);
   0453 90 E6 78           1354 	mov	dptr,#_I2CS
   0456 E0                 1355 	movx	a,@dptr
   0457 FD                 1356 	mov	r5,a
   0458 20 E1 04           1357 	jb	acc.1,00105$
   045B 75 82 01           1358 	mov	dpl,#0x01
   045E 22                 1359 	ret
   045F                    1360 00105$:
                           1361 ;	eeprom_mark.c:57: I2DAT = (ee_adr>>8);
   045F 90 E6 79           1362 	mov	dptr,#_I2DAT
   0462 EF                 1363 	mov	a,r7
   0463 F0                 1364 	movx	@dptr,a
                           1365 ;	eeprom_mark.c:58: while(!(I2CS & I2CS_DONE));
   0464                    1366 00106$:
   0464 90 E6 78           1367 	mov	dptr,#_I2CS
   0467 E0                 1368 	movx	a,@dptr
   0468 FD                 1369 	mov	r5,a
   0469 30 E0 F8           1370 	jnb	acc.0,00106$
                           1371 ;	eeprom_mark.c:61: if(!(I2CS & I2CS_ACK)) return(2);
   046C 90 E6 78           1372 	mov	dptr,#_I2CS
   046F E0                 1373 	movx	a,@dptr
   0470 FD                 1374 	mov	r5,a
   0471 20 E1 04           1375 	jb	acc.1,00110$
   0474 75 82 02           1376 	mov	dpl,#0x02
   0477 22                 1377 	ret
   0478                    1378 00110$:
                           1379 ;	eeprom_mark.c:64: I2DAT = (ee_adr & 0xff);
   0478 7F 00              1380 	mov	r7,#0x00
   047A 90 E6 79           1381 	mov	dptr,#_I2DAT
   047D EE                 1382 	mov	a,r6
   047E F0                 1383 	movx	@dptr,a
                           1384 ;	eeprom_mark.c:65: while(!(I2CS & I2CS_DONE));
   047F                    1385 00111$:
   047F 90 E6 78           1386 	mov	dptr,#_I2CS
   0482 E0                 1387 	movx	a,@dptr
   0483 FF                 1388 	mov	r7,a
   0484 30 E0 F8           1389 	jnb	acc.0,00111$
                           1390 ;	eeprom_mark.c:68: if(!(I2CS & I2CS_ACK)) return(3);
   0487 90 E6 78           1391 	mov	dptr,#_I2CS
   048A E0                 1392 	movx	a,@dptr
   048B FF                 1393 	mov	r7,a
   048C 20 E1 04           1394 	jb	acc.1,00115$
   048F 75 82 03           1395 	mov	dpl,#0x03
   0492 22                 1396 	ret
   0493                    1397 00115$:
                           1398 ;	eeprom_mark.c:71: I2DAT = 0xff;
   0493 90 E6 79           1399 	mov	dptr,#_I2DAT
   0496 74 FF              1400 	mov	a,#0xFF
   0498 F0                 1401 	movx	@dptr,a
                           1402 ;	eeprom_mark.c:72: while(!(I2CS & I2CS_DONE));
   0499                    1403 00116$:
   0499 90 E6 78           1404 	mov	dptr,#_I2CS
   049C E0                 1405 	movx	a,@dptr
   049D FF                 1406 	mov	r7,a
   049E 30 E0 F8           1407 	jnb	acc.0,00116$
                           1408 ;	eeprom_mark.c:74: I2CS = I2CS_STOP;
                           1409 ;	eeprom_mark.c:76: if(!(I2CS & I2CS_ACK)) return(4);
   04A1 90 E6 78           1410 	mov	dptr,#_I2CS
   04A4 74 40              1411 	mov	a,#0x40
   04A6 F0                 1412 	movx	@dptr,a
   04A7 E0                 1413 	movx	a,@dptr
   04A8 FF                 1414 	mov	r7,a
   04A9 20 E1 04           1415 	jb	acc.1,00127$
   04AC 75 82 04           1416 	mov	dpl,#0x04
   04AF 22                 1417 	ret
   04B0                    1418 00127$:
                           1419 ;	eeprom_mark.c:81: I2CS = I2CS_START;
   04B0 90 E6 78           1420 	mov	dptr,#_I2CS
   04B3 74 80              1421 	mov	a,#0x80
   04B5 F0                 1422 	movx	@dptr,a
                           1423 ;	eeprom_mark.c:82: I2DAT = EEPROM_ADR | I2CWRITE;
   04B6 90 E6 79           1424 	mov	dptr,#_I2DAT
   04B9 74 A2              1425 	mov	a,#0xA2
   04BB F0                 1426 	movx	@dptr,a
                           1427 ;	eeprom_mark.c:83: while(!(I2CS & I2CS_DONE));
   04BC                    1428 00121$:
   04BC 90 E6 78           1429 	mov	dptr,#_I2CS
   04BF E0                 1430 	movx	a,@dptr
   04C0 FF                 1431 	mov	r7,a
   04C1 30 E0 F8           1432 	jnb	acc.0,00121$
                           1433 ;	eeprom_mark.c:85: if((I2CS & I2CS_ACK)) break;
   04C4 90 E6 78           1434 	mov	dptr,#_I2CS
   04C7 E0                 1435 	movx	a,@dptr
   04C8 FF                 1436 	mov	r7,a
   04C9 30 E1 E4           1437 	jnb	acc.1,00127$
                           1438 ;	eeprom_mark.c:88: return(64);
   04CC 75 82 40           1439 	mov	dpl,#0x40
   04CF 22                 1440 	ret
                           1441 ;------------------------------------------------------------
                           1442 ;Allocation info for local variables in function 'EEWrite'
                           1443 ;------------------------------------------------------------
                           1444 ;a                         Allocated with name '_EEWrite_PARM_2'
                           1445 ;ee_adr                    Allocated to registers r6 r7 
                           1446 ;------------------------------------------------------------
                           1447 ;	eeprom_mark.c:96: static uint8 EEWrite(uint16 ee_adr, unsigned char a)
                           1448 ;	-----------------------------------------
                           1449 ;	 function EEWrite
                           1450 ;	-----------------------------------------
   04D0                    1451 _EEWrite:
   04D0 AE 82              1452 	mov	r6,dpl
   04D2 AF 83              1453 	mov	r7,dph
                           1454 ;	eeprom_mark.c:98: I2CS = I2CS_START;
   04D4 90 E6 78           1455 	mov	dptr,#_I2CS
   04D7 74 80              1456 	mov	a,#0x80
   04D9 F0                 1457 	movx	@dptr,a
                           1458 ;	eeprom_mark.c:99: I2DAT = EEPROM_ADR | I2CWRITE;
   04DA 90 E6 79           1459 	mov	dptr,#_I2DAT
   04DD 74 A2              1460 	mov	a,#0xA2
   04DF F0                 1461 	movx	@dptr,a
                           1462 ;	eeprom_mark.c:100: while(!(I2CS & I2CS_DONE));
   04E0                    1463 00101$:
   04E0 90 E6 78           1464 	mov	dptr,#_I2CS
   04E3 E0                 1465 	movx	a,@dptr
   04E4 FD                 1466 	mov	r5,a
   04E5 30 E0 F8           1467 	jnb	acc.0,00101$
                           1468 ;	eeprom_mark.c:103: if(!(I2CS & I2CS_ACK)) return(1);
   04E8 90 E6 78           1469 	mov	dptr,#_I2CS
   04EB E0                 1470 	movx	a,@dptr
   04EC FD                 1471 	mov	r5,a
   04ED 20 E1 04           1472 	jb	acc.1,00105$
   04F0 75 82 01           1473 	mov	dpl,#0x01
   04F3 22                 1474 	ret
   04F4                    1475 00105$:
                           1476 ;	eeprom_mark.c:106: I2DAT = (ee_adr>>8);
   04F4 90 E6 79           1477 	mov	dptr,#_I2DAT
   04F7 EF                 1478 	mov	a,r7
   04F8 F0                 1479 	movx	@dptr,a
                           1480 ;	eeprom_mark.c:107: while(!(I2CS & I2CS_DONE));
   04F9                    1481 00106$:
   04F9 90 E6 78           1482 	mov	dptr,#_I2CS
   04FC E0                 1483 	movx	a,@dptr
   04FD FD                 1484 	mov	r5,a
   04FE 30 E0 F8           1485 	jnb	acc.0,00106$
                           1486 ;	eeprom_mark.c:110: if(!(I2CS & I2CS_ACK)) return(2);
   0501 90 E6 78           1487 	mov	dptr,#_I2CS
   0504 E0                 1488 	movx	a,@dptr
   0505 FD                 1489 	mov	r5,a
   0506 20 E1 04           1490 	jb	acc.1,00110$
   0509 75 82 02           1491 	mov	dpl,#0x02
   050C 22                 1492 	ret
   050D                    1493 00110$:
                           1494 ;	eeprom_mark.c:113: I2DAT = (ee_adr & 0xff);
   050D 7F 00              1495 	mov	r7,#0x00
   050F 90 E6 79           1496 	mov	dptr,#_I2DAT
   0512 EE                 1497 	mov	a,r6
   0513 F0                 1498 	movx	@dptr,a
                           1499 ;	eeprom_mark.c:114: while(!(I2CS & I2CS_DONE));
   0514                    1500 00111$:
   0514 90 E6 78           1501 	mov	dptr,#_I2CS
   0517 E0                 1502 	movx	a,@dptr
   0518 FF                 1503 	mov	r7,a
   0519 30 E0 F8           1504 	jnb	acc.0,00111$
                           1505 ;	eeprom_mark.c:117: if(!(I2CS & I2CS_ACK)) return(3);
   051C 90 E6 78           1506 	mov	dptr,#_I2CS
   051F E0                 1507 	movx	a,@dptr
   0520 FF                 1508 	mov	r7,a
   0521 20 E1 04           1509 	jb	acc.1,00115$
   0524 75 82 03           1510 	mov	dpl,#0x03
   0527 22                 1511 	ret
   0528                    1512 00115$:
                           1513 ;	eeprom_mark.c:120: I2DAT = a;
   0528 90 E6 79           1514 	mov	dptr,#_I2DAT
   052B E5 10              1515 	mov	a,_EEWrite_PARM_2
   052D F0                 1516 	movx	@dptr,a
                           1517 ;	eeprom_mark.c:121: while(!(I2CS & I2CS_DONE));
   052E                    1518 00116$:
   052E 90 E6 78           1519 	mov	dptr,#_I2CS
   0531 E0                 1520 	movx	a,@dptr
   0532 FF                 1521 	mov	r7,a
   0533 30 E0 F8           1522 	jnb	acc.0,00116$
                           1523 ;	eeprom_mark.c:123: I2CS = I2CS_STOP;
                           1524 ;	eeprom_mark.c:125: if(!(I2CS & I2CS_ACK)) return(4);
   0536 90 E6 78           1525 	mov	dptr,#_I2CS
   0539 74 40              1526 	mov	a,#0x40
   053B F0                 1527 	movx	@dptr,a
   053C E0                 1528 	movx	a,@dptr
   053D FF                 1529 	mov	r7,a
   053E 20 E1 04           1530 	jb	acc.1,00127$
   0541 75 82 04           1531 	mov	dpl,#0x04
   0544 22                 1532 	ret
   0545                    1533 00127$:
                           1534 ;	eeprom_mark.c:130: I2CS = I2CS_START;
   0545 90 E6 78           1535 	mov	dptr,#_I2CS
   0548 74 80              1536 	mov	a,#0x80
   054A F0                 1537 	movx	@dptr,a
                           1538 ;	eeprom_mark.c:131: I2DAT = EEPROM_ADR | I2CWRITE;
   054B 90 E6 79           1539 	mov	dptr,#_I2DAT
   054E 74 A2              1540 	mov	a,#0xA2
   0550 F0                 1541 	movx	@dptr,a
                           1542 ;	eeprom_mark.c:132: while(!(I2CS & I2CS_DONE));
   0551                    1543 00121$:
   0551 90 E6 78           1544 	mov	dptr,#_I2CS
   0554 E0                 1545 	movx	a,@dptr
   0555 FF                 1546 	mov	r7,a
   0556 30 E0 F8           1547 	jnb	acc.0,00121$
                           1548 ;	eeprom_mark.c:134: if((I2CS & I2CS_ACK)) break;
   0559 90 E6 78           1549 	mov	dptr,#_I2CS
   055C E0                 1550 	movx	a,@dptr
   055D FF                 1551 	mov	r7,a
   055E 30 E1 E4           1552 	jnb	acc.1,00127$
                           1553 ;	eeprom_mark.c:136: return(64);
   0561 75 82 40           1554 	mov	dpl,#0x40
   0564 22                 1555 	ret
                           1556 ;------------------------------------------------------------
                           1557 ;Allocation info for local variables in function 'writemarkeeprom'
                           1558 ;------------------------------------------------------------
                           1559 ;mark                      Allocated with name '_writemarkeeprom_mark_1_62'
                           1560 ;n                         Allocated to registers r3 r4 
                           1561 ;sloc0                     Allocated with name '_writemarkeeprom_sloc0_1_0'
                           1562 ;sloc1                     Allocated with name '_writemarkeeprom_sloc1_1_0'
                           1563 ;------------------------------------------------------------
                           1564 ;	eeprom_mark.c:153: static uint8 writemarkeeprom(struct mark *mark) {
                           1565 ;	-----------------------------------------
                           1566 ;	 function writemarkeeprom
                           1567 ;	-----------------------------------------
   0565                    1568 _writemarkeeprom:
   0565 85 82 30           1569 	mov	_writemarkeeprom_mark_1_62,dpl
   0568 85 83 31           1570 	mov	(_writemarkeeprom_mark_1_62 + 1),dph
   056B 85 F0 32           1571 	mov	(_writemarkeeprom_mark_1_62 + 2),b
                           1572 ;	eeprom_mark.c:157: I2CTL = 0x01;	// Set 400kHz:
   056E 90 E6 7A           1573 	mov	dptr,#_I2CTL
   0571 74 01              1574 	mov	a,#0x01
   0573 F0                 1575 	movx	@dptr,a
                           1576 ;	eeprom_mark.c:158: SYNCDELAY;
   0574 00                 1577 	nop; 
                           1578 ;	eeprom_mark.c:160: for(n=0;n<128;n++) HWmark[n] = 0x00;
   0575 7B 00              1579 	mov	r3,#0x00
   0577 7C 00              1580 	mov	r4,#0x00
   0579                    1581 00101$:
   0579 C3                 1582 	clr	c
   057A EB                 1583 	mov	a,r3
   057B 94 80              1584 	subb	a,#0x80
   057D EC                 1585 	mov	a,r4
   057E 64 80              1586 	xrl	a,#0x80
   0580 94 80              1587 	subb	a,#0x80
   0582 50 13              1588 	jnc	00104$
   0584 EB                 1589 	mov	a,r3
   0585 25 28              1590 	add	a,_HWmark
   0587 F5 82              1591 	mov	dpl,a
   0589 EC                 1592 	mov	a,r4
   058A 35 29              1593 	addc	a,(_HWmark + 1)
   058C F5 83              1594 	mov	dph,a
   058E E4                 1595 	clr	a
   058F F0                 1596 	movx	@dptr,a
   0590 0B                 1597 	inc	r3
   0591 BB 00 E5           1598 	cjne	r3,#0x00,00101$
   0594 0C                 1599 	inc	r4
   0595 80 E2              1600 	sjmp	00101$
   0597                    1601 00104$:
                           1602 ;	eeprom_mark.c:164: mark->serial_no_high,mark->serial_no_low);
   0597 74 0E              1603 	mov	a,#0x0E
   0599 25 30              1604 	add	a,_writemarkeeprom_mark_1_62
   059B FA                 1605 	mov	r2,a
   059C E4                 1606 	clr	a
   059D 35 31              1607 	addc	a,(_writemarkeeprom_mark_1_62 + 1)
   059F FB                 1608 	mov	r3,a
   05A0 AC 32              1609 	mov	r4,(_writemarkeeprom_mark_1_62 + 2)
   05A2 8A 82              1610 	mov	dpl,r2
   05A4 8B 83              1611 	mov	dph,r3
   05A6 8C F0              1612 	mov	b,r4
   05A8 12 0F 02           1613 	lcall	__gptrget
   05AB FA                 1614 	mov	r2,a
   05AC A3                 1615 	inc	dptr
   05AD 12 0F 02           1616 	lcall	__gptrget
   05B0 FB                 1617 	mov	r3,a
   05B1 74 0C              1618 	mov	a,#0x0C
   05B3 25 30              1619 	add	a,_writemarkeeprom_mark_1_62
   05B5 F8                 1620 	mov	r0,a
   05B6 E4                 1621 	clr	a
   05B7 35 31              1622 	addc	a,(_writemarkeeprom_mark_1_62 + 1)
   05B9 F9                 1623 	mov	r1,a
   05BA AC 32              1624 	mov	r4,(_writemarkeeprom_mark_1_62 + 2)
   05BC 88 82              1625 	mov	dpl,r0
   05BE 89 83              1626 	mov	dph,r1
   05C0 8C F0              1627 	mov	b,r4
   05C2 12 0F 02           1628 	lcall	__gptrget
   05C5 F8                 1629 	mov	r0,a
   05C6 A3                 1630 	inc	dptr
   05C7 12 0F 02           1631 	lcall	__gptrget
   05CA F9                 1632 	mov	r1,a
                           1633 ;	eeprom_mark.c:163: mark->type,mark->major_version, mark->minor_version,
   05CB 74 0A              1634 	mov	a,#0x0A
   05CD 25 30              1635 	add	a,_writemarkeeprom_mark_1_62
   05CF FC                 1636 	mov	r4,a
   05D0 E4                 1637 	clr	a
   05D1 35 31              1638 	addc	a,(_writemarkeeprom_mark_1_62 + 1)
   05D3 FE                 1639 	mov	r6,a
   05D4 AF 32              1640 	mov	r7,(_writemarkeeprom_mark_1_62 + 2)
   05D6 8C 82              1641 	mov	dpl,r4
   05D8 8E 83              1642 	mov	dph,r6
   05DA 8F F0              1643 	mov	b,r7
   05DC 12 0F 02           1644 	lcall	__gptrget
   05DF F5 33              1645 	mov	_writemarkeeprom_sloc0_1_0,a
   05E1 A3                 1646 	inc	dptr
   05E2 12 0F 02           1647 	lcall	__gptrget
   05E5 F5 34              1648 	mov	(_writemarkeeprom_sloc0_1_0 + 1),a
   05E7 74 08              1649 	mov	a,#0x08
   05E9 25 30              1650 	add	a,_writemarkeeprom_mark_1_62
   05EB FD                 1651 	mov	r5,a
   05EC E4                 1652 	clr	a
   05ED 35 31              1653 	addc	a,(_writemarkeeprom_mark_1_62 + 1)
   05EF FE                 1654 	mov	r6,a
   05F0 AF 32              1655 	mov	r7,(_writemarkeeprom_mark_1_62 + 2)
   05F2 8D 82              1656 	mov	dpl,r5
   05F4 8E 83              1657 	mov	dph,r6
   05F6 8F F0              1658 	mov	b,r7
   05F8 12 0F 02           1659 	lcall	__gptrget
   05FB F5 35              1660 	mov	_writemarkeeprom_sloc1_1_0,a
   05FD A3                 1661 	inc	dptr
   05FE 12 0F 02           1662 	lcall	__gptrget
   0601 F5 36              1663 	mov	(_writemarkeeprom_sloc1_1_0 + 1),a
                           1664 ;	eeprom_mark.c:162: sprintf(HWmark,"HW%sv%03x.%03xs%04x.%04x",
   0603 AC 28              1665 	mov	r4,_HWmark
   0605 AE 29              1666 	mov	r6,(_HWmark + 1)
   0607 7F 00              1667 	mov	r7,#0x00
   0609 C0 02              1668 	push	ar2
   060B C0 03              1669 	push	ar3
   060D C0 00              1670 	push	ar0
   060F C0 01              1671 	push	ar1
   0611 C0 33              1672 	push	_writemarkeeprom_sloc0_1_0
   0613 C0 34              1673 	push	(_writemarkeeprom_sloc0_1_0 + 1)
   0615 C0 35              1674 	push	_writemarkeeprom_sloc1_1_0
   0617 C0 36              1675 	push	(_writemarkeeprom_sloc1_1_0 + 1)
   0619 C0 30              1676 	push	_writemarkeeprom_mark_1_62
   061B C0 31              1677 	push	(_writemarkeeprom_mark_1_62 + 1)
   061D C0 32              1678 	push	(_writemarkeeprom_mark_1_62 + 2)
   061F 74 2E              1679 	mov	a,#__str_2
   0621 C0 E0              1680 	push	acc
   0623 74 0F              1681 	mov	a,#(__str_2 >> 8)
   0625 C0 E0              1682 	push	acc
   0627 74 80              1683 	mov	a,#0x80
   0629 C0 E0              1684 	push	acc
   062B C0 04              1685 	push	ar4
   062D C0 06              1686 	push	ar6
   062F C0 07              1687 	push	ar7
   0631 12 08 D8           1688 	lcall	_sprintf
   0634 E5 81              1689 	mov	a,sp
   0636 24 EF              1690 	add	a,#0xef
   0638 F5 81              1691 	mov	sp,a
                           1692 ;	eeprom_mark.c:165: for(n=0;n<32;n++) err[n+2] = EEWrite(0x0400+n,0x00);
   063A 7E 00              1693 	mov	r6,#0x00
   063C 7F 00              1694 	mov	r7,#0x00
   063E                    1695 00105$:
   063E C3                 1696 	clr	c
   063F EE                 1697 	mov	a,r6
   0640 94 20              1698 	subb	a,#0x20
   0642 EF                 1699 	mov	a,r7
   0643 64 80              1700 	xrl	a,#0x80
   0645 94 80              1701 	subb	a,#0x80
   0647 50 3B              1702 	jnc	00108$
   0649 74 02              1703 	mov	a,#0x02
   064B 2E                 1704 	add	a,r6
   064C FC                 1705 	mov	r4,a
   064D E4                 1706 	clr	a
   064E 3F                 1707 	addc	a,r7
   064F FD                 1708 	mov	r5,a
   0650 EC                 1709 	mov	a,r4
   0651 25 22              1710 	add	a,_err
   0653 FC                 1711 	mov	r4,a
   0654 ED                 1712 	mov	a,r5
   0655 35 23              1713 	addc	a,(_err + 1)
   0657 FD                 1714 	mov	r5,a
   0658 8E 82              1715 	mov	dpl,r6
   065A 74 04              1716 	mov	a,#0x04
   065C 2F                 1717 	add	a,r7
   065D F5 83              1718 	mov	dph,a
   065F 75 10 00           1719 	mov	_EEWrite_PARM_2,#0x00
   0662 C0 07              1720 	push	ar7
   0664 C0 06              1721 	push	ar6
   0666 C0 05              1722 	push	ar5
   0668 C0 04              1723 	push	ar4
   066A 12 04 D0           1724 	lcall	_EEWrite
   066D AB 82              1725 	mov	r3,dpl
   066F D0 04              1726 	pop	ar4
   0671 D0 05              1727 	pop	ar5
   0673 D0 06              1728 	pop	ar6
   0675 D0 07              1729 	pop	ar7
   0677 8C 82              1730 	mov	dpl,r4
   0679 8D 83              1731 	mov	dph,r5
   067B EB                 1732 	mov	a,r3
   067C F0                 1733 	movx	@dptr,a
   067D 0E                 1734 	inc	r6
   067E BE 00 BD           1735 	cjne	r6,#0x00,00105$
   0681 0F                 1736 	inc	r7
   0682 80 BA              1737 	sjmp	00105$
   0684                    1738 00108$:
                           1739 ;	eeprom_mark.c:166: for(n=0;n<32;n++) err[n+2] = EEWrite(0x0400+n,HWmark[n]);
   0684 7E 00              1740 	mov	r6,#0x00
   0686 7F 00              1741 	mov	r7,#0x00
   0688                    1742 00109$:
   0688 C3                 1743 	clr	c
   0689 EE                 1744 	mov	a,r6
   068A 94 20              1745 	subb	a,#0x20
   068C EF                 1746 	mov	a,r7
   068D 64 80              1747 	xrl	a,#0x80
   068F 94 80              1748 	subb	a,#0x80
   0691 50 48              1749 	jnc	00112$
   0693 74 02              1750 	mov	a,#0x02
   0695 2E                 1751 	add	a,r6
   0696 FC                 1752 	mov	r4,a
   0697 E4                 1753 	clr	a
   0698 3F                 1754 	addc	a,r7
   0699 FD                 1755 	mov	r5,a
   069A EC                 1756 	mov	a,r4
   069B 25 22              1757 	add	a,_err
   069D FC                 1758 	mov	r4,a
   069E ED                 1759 	mov	a,r5
   069F 35 23              1760 	addc	a,(_err + 1)
   06A1 FD                 1761 	mov	r5,a
   06A2 8E 02              1762 	mov	ar2,r6
   06A4 74 04              1763 	mov	a,#0x04
   06A6 2F                 1764 	add	a,r7
   06A7 FB                 1765 	mov	r3,a
   06A8 EE                 1766 	mov	a,r6
   06A9 25 28              1767 	add	a,_HWmark
   06AB F5 82              1768 	mov	dpl,a
   06AD EF                 1769 	mov	a,r7
   06AE 35 29              1770 	addc	a,(_HWmark + 1)
   06B0 F5 83              1771 	mov	dph,a
   06B2 E0                 1772 	movx	a,@dptr
   06B3 F5 10              1773 	mov	_EEWrite_PARM_2,a
   06B5 8A 82              1774 	mov	dpl,r2
   06B7 8B 83              1775 	mov	dph,r3
   06B9 C0 07              1776 	push	ar7
   06BB C0 06              1777 	push	ar6
   06BD C0 05              1778 	push	ar5
   06BF C0 04              1779 	push	ar4
   06C1 12 04 D0           1780 	lcall	_EEWrite
   06C4 AB 82              1781 	mov	r3,dpl
   06C6 D0 04              1782 	pop	ar4
   06C8 D0 05              1783 	pop	ar5
   06CA D0 06              1784 	pop	ar6
   06CC D0 07              1785 	pop	ar7
   06CE 8C 82              1786 	mov	dpl,r4
   06D0 8D 83              1787 	mov	dph,r5
   06D2 EB                 1788 	mov	a,r3
   06D3 F0                 1789 	movx	@dptr,a
   06D4 0E                 1790 	inc	r6
   06D5 BE 00 B0           1791 	cjne	r6,#0x00,00109$
   06D8 0F                 1792 	inc	r7
   06D9 80 AD              1793 	sjmp	00109$
   06DB                    1794 00112$:
                           1795 ;	eeprom_mark.c:168: return(0);
   06DB 75 82 00           1796 	mov	dpl,#0x00
   06DE 22                 1797 	ret
                           1798 ;------------------------------------------------------------
                           1799 ;Allocation info for local variables in function 'main'
                           1800 ;------------------------------------------------------------
                           1801 ;n                         Allocated to registers r6 r7 
                           1802 ;eeprom_mark_adr           Allocated to registers 
                           1803 ;adr                       Allocated to registers 
                           1804 ;mark                      Allocated with name '_main_mark_1_65'
                           1805 ;------------------------------------------------------------
                           1806 ;	eeprom_mark.c:171: void main(void)
                           1807 ;	-----------------------------------------
                           1808 ;	 function main
                           1809 ;	-----------------------------------------
   06DF                    1810 _main:
                           1811 ;	eeprom_mark.c:178: err = (xdata unsigned char *) 0x1200;	
   06DF 75 22 00           1812 	mov	_err,#0x00
   06E2 75 23 12           1813 	mov	(_err + 1),#0x12
                           1814 ;	eeprom_mark.c:190: strcpy(mark.type,"DDS_");
   06E5 75 10 47           1815 	mov	_strcpy_PARM_2,#__str_3
   06E8 75 11 0F           1816 	mov	(_strcpy_PARM_2 + 1),#(__str_3 >> 8)
   06EB 75 12 80           1817 	mov	(_strcpy_PARM_2 + 2),#0x80
   06EE 90 00 37           1818 	mov	dptr,#_main_mark_1_65
   06F1 75 F0 40           1819 	mov	b,#0x40
   06F4 12 07 53           1820 	lcall	_strcpy
                           1821 ;	eeprom_mark.c:192: mark.major_version = 0x0;
   06F7 E4                 1822 	clr	a
   06F8 F5 3F              1823 	mov	((_main_mark_1_65 + 0x0008) + 0),a
   06FA F5 40              1824 	mov	((_main_mark_1_65 + 0x0008) + 1),a
                           1825 ;	eeprom_mark.c:193: mark.minor_version = 0x1;
   06FC 75 41 01           1826 	mov	((_main_mark_1_65 + 0x000a) + 0),#0x01
                           1827 ;	eeprom_mark.c:195: mark.serial_no_high = 0x0;
   06FF E4                 1828 	clr	a
   0700 F5 42              1829 	mov	((_main_mark_1_65 + 0x000a) + 1),a
   0702 F5 43              1830 	mov	((_main_mark_1_65 + 0x000c) + 0),a
   0704 F5 44              1831 	mov	((_main_mark_1_65 + 0x000c) + 1),a
                           1832 ;	eeprom_mark.c:196: mark.serial_no_low  = 0x1;
   0706 75 45 01           1833 	mov	((_main_mark_1_65 + 0x000e) + 0),#0x01
   0709 75 46 00           1834 	mov	((_main_mark_1_65 + 0x000e) + 1),#0x00
                           1835 ;	eeprom_mark.c:200: for(n = 0;n < 200;n++);
   070C 7E C8              1836 	mov	r6,#0xC8
   070E 7F 00              1837 	mov	r7,#0x00
   0710                    1838 00103$:
   0710 1E                 1839 	dec	r6
   0711 BE FF 01           1840 	cjne	r6,#0xFF,00125$
   0714 1F                 1841 	dec	r7
   0715                    1842 00125$:
   0715 EE                 1843 	mov	a,r6
   0716 4F                 1844 	orl	a,r7
   0717 70 F7              1845 	jnz	00103$
                           1846 ;	eeprom_mark.c:201: readmarkeeprom();
   0719 12 02 32           1847 	lcall	_readmarkeeprom
                           1848 ;	eeprom_mark.c:202: for(n=0;n<32;n++) dat[n] = (xdata char)HWmark[n];
   071C 7E 00              1849 	mov	r6,#0x00
   071E 7F 00              1850 	mov	r7,#0x00
   0720                    1851 00104$:
   0720 C3                 1852 	clr	c
   0721 EE                 1853 	mov	a,r6
   0722 94 20              1854 	subb	a,#0x20
   0724 EF                 1855 	mov	a,r7
   0725 64 80              1856 	xrl	a,#0x80
   0727 94 80              1857 	subb	a,#0x80
   0729 50 20              1858 	jnc	00107$
   072B EE                 1859 	mov	a,r6
   072C 25 24              1860 	add	a,_dat
   072E FC                 1861 	mov	r4,a
   072F EF                 1862 	mov	a,r7
   0730 35 25              1863 	addc	a,(_dat + 1)
   0732 FD                 1864 	mov	r5,a
   0733 EE                 1865 	mov	a,r6
   0734 25 28              1866 	add	a,_HWmark
   0736 F5 82              1867 	mov	dpl,a
   0738 EF                 1868 	mov	a,r7
   0739 35 29              1869 	addc	a,(_HWmark + 1)
   073B F5 83              1870 	mov	dph,a
   073D E0                 1871 	movx	a,@dptr
   073E FB                 1872 	mov	r3,a
   073F 8C 82              1873 	mov	dpl,r4
   0741 8D 83              1874 	mov	dph,r5
   0743 F0                 1875 	movx	@dptr,a
   0744 0E                 1876 	inc	r6
   0745 BE 00 D8           1877 	cjne	r6,#0x00,00104$
   0748 0F                 1878 	inc	r7
   0749 80 D5              1879 	sjmp	00104$
   074B                    1880 00107$:
                           1881 ;	eeprom_mark.c:204: hostreadmarkep1init();
   074B 12 02 87           1882 	lcall	_hostreadmarkep1init
   074E                    1883 00109$:
                           1884 ;	eeprom_mark.c:205: for(;;) hostreadmarkep1poll();	
   074E 12 02 9E           1885 	lcall	_hostreadmarkep1poll
   0751 80 FB              1886 	sjmp	00109$
                           1887 	.area CSEG    (CODE)
                           1888 	.area CONST   (CODE)
   0F22                    1889 __str_0:
   0F22 67 65 74 48 57     1890 	.ascii "getHW"
   0F27 00                 1891 	.db 0x00
   0F28                    1892 __str_1:
   0F28 67 65 74 46 57     1893 	.ascii "getFW"
   0F2D 00                 1894 	.db 0x00
   0F2E                    1895 __str_2:
   0F2E 48 57 25 73 76 25  1896 	.ascii "HW%sv%03x.%03xs%04x.%04x"
        30 33 78 2E 25 30
        33 78 73 25 30 34
        78 2E 25 30 34 78
   0F46 00                 1897 	.db 0x00
   0F47                    1898 __str_3:
   0F47 44 44 53 5F        1899 	.ascii "DDS_"
   0F4B 00                 1900 	.db 0x00
   0F4C                    1901 __str_4:
   0F4C 46 57 45 45 50 52  1902 	.ascii "FWEEPRv000.001"
        76 30 30 30 2E 30
        30 31
   0F5A 00                 1903 	.db 0x00
                           1904 	.area XINIT   (CODE)
                           1905 	.area CABS    (ABS,CODE)
