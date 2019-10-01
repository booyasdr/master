                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Sun Apr 26 07:15:20 2015
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
                            253 	.globl _HWmark
                            254 	.globl _command
                            255 	.globl _jump_table
                            256 	.globl _dat
                            257 	.globl _err
                            258 	.globl _FWmark
                            259 ;--------------------------------------------------------
                            260 ; special function registers
                            261 ;--------------------------------------------------------
                            262 	.area RSEG    (ABS,DATA)
   0000                     263 	.org 0x0000
                    0080    264 _IOA	=	0x0080
                    0081    265 _SP	=	0x0081
                    0082    266 _DPL	=	0x0082
                    0083    267 _DPH	=	0x0083
                    0084    268 _DPL1	=	0x0084
                    0085    269 _DPH1	=	0x0085
                    0086    270 _DPS	=	0x0086
                    0087    271 _PCON	=	0x0087
                    0088    272 _TCON	=	0x0088
                    0089    273 _TMOD	=	0x0089
                    008A    274 _TL0	=	0x008a
                    008B    275 _TL1	=	0x008b
                    008C    276 _TH0	=	0x008c
                    008D    277 _TH1	=	0x008d
                    008E    278 _CKCO	=	0x008e
                    008F    279 _SPC_	=	0x008f
                    0090    280 _IOB	=	0x0090
                    0091    281 _EXIF	=	0x0091
                    0092    282 _MPA	=	0x0092
                    0098    283 _SCO	=	0x0098
                    0099    284 _SBU	=	0x0099
                    009A    285 _APTR1H	=	0x009a
                    009B    286 _APTR1L	=	0x009b
                    009C    287 _AUTODAT1	=	0x009c
                    009D    288 _AUTOPTRH2	=	0x009d
                    009E    289 _AUTOPTRL2	=	0x009e
                    009F    290 _AUTODAT2	=	0x009f
                    00A0    291 _IOC	=	0x00a0
                    00A1    292 _INT2CLR	=	0x00a1
                    00A2    293 _INT4CLR	=	0x00a2
                    00A8    294 _IE	=	0x00a8
                    00AA    295 _EP2468STAT	=	0x00aa
                    00AB    296 _EP24FIFOFLGS	=	0x00ab
                    00AC    297 _EP68FIFOFLGS	=	0x00ac
                    00AF    298 _AUTOPTRSETUP	=	0x00af
                    00B0    299 _IOD	=	0x00b0
                    00B1    300 _IOE	=	0x00b1
                    00B2    301 _OEA	=	0x00b2
                    00B3    302 _OEB	=	0x00b3
                    00B4    303 _OEC	=	0x00b4
                    00B5    304 _OED	=	0x00b5
                    00B6    305 _OEE	=	0x00b6
                    00B8    306 _IP	=	0x00b8
                    00BA    307 _EP01STAT	=	0x00ba
                    00BB    308 _GPIFTRIG	=	0x00bb
                    00BD    309 _GPIFSGLDATH	=	0x00bd
                    00BE    310 _GPIFSGLDATLX	=	0x00be
                    00BF    311 _GPIFSGLDATLNOX	=	0x00bf
                    00C0    312 _SCON1	=	0x00c0
                    00C1    313 _SBUF1	=	0x00c1
                    00C8    314 _T2CON	=	0x00c8
                    00CA    315 _RCAP2L	=	0x00ca
                    00CB    316 _RCAP2H	=	0x00cb
                    00CC    317 _TL2	=	0x00cc
                    00CD    318 _TH2	=	0x00cd
                    00D0    319 _PSW	=	0x00d0
                    00D8    320 _EICON	=	0x00d8
                    00E0    321 _ACC	=	0x00e0
                    00E8    322 _EIE	=	0x00e8
                    00F0    323 _B	=	0x00f0
                    00F8    324 _EIP	=	0x00f8
                            325 ;--------------------------------------------------------
                            326 ; special function bits
                            327 ;--------------------------------------------------------
                            328 	.area RSEG    (ABS,DATA)
   0000                     329 	.org 0x0000
                            330 ;--------------------------------------------------------
                            331 ; overlayable register banks
                            332 ;--------------------------------------------------------
                            333 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     334 	.ds 8
                            335 ;--------------------------------------------------------
                            336 ; internal ram data
                            337 ;--------------------------------------------------------
                            338 	.area DSEG    (DATA)
   0022                     339 _FWmark::
   0022                     340 	.ds 3
   0025                     341 _err::
   0025                     342 	.ds 2
   0027                     343 _dat::
   0027                     344 	.ds 2
   0029                     345 _jump_table::
   0029                     346 	.ds 2
   002B                     347 _command::
   002B                     348 	.ds 2
   002D                     349 _HWmark::
   002D                     350 	.ds 2
   002F                     351 _writemarkeeprom_mark_1_1:
   002F                     352 	.ds 3
   0032                     353 _writemarkeeprom_sloc0_1_0:
   0032                     354 	.ds 2
   0034                     355 _writemarkeeprom_sloc1_1_0:
   0034                     356 	.ds 2
   0036                     357 _main_mark_1_1:
   0036                     358 	.ds 16
   0046                     359 _hostreadmarkep1poll_ep1outbc_1_1:
   0046                     360 	.ds 1
   0047                     361 _hostreadmarkep1poll_n_1_1:
   0047                     362 	.ds 2
                            363 ;--------------------------------------------------------
                            364 ; overlayable items in internal ram 
                            365 ;--------------------------------------------------------
                            366 	.area	OSEG    (OVR,DATA)
                            367 	.area	OSEG    (OVR,DATA)
   0010                     368 _EEWrite_PARM_2:
   0010                     369 	.ds 1
                            370 	.area	OSEG    (OVR,DATA)
   0010                     371 _EERead_PARM_2:
   0010                     372 	.ds 3
   0013                     373 _EERead_n_1_1:
   0013                     374 	.ds 2
                            375 ;--------------------------------------------------------
                            376 ; Stack segment in internal ram 
                            377 ;--------------------------------------------------------
                            378 	.area	SSEG	(DATA)
   0063                     379 __start__stack:
   0063                     380 	.ds	1
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
                            395 ;--------------------------------------------------------
                            396 ; paged external ram data
                            397 ;--------------------------------------------------------
                            398 	.area PSEG    (PAG,XDATA)
                            399 ;--------------------------------------------------------
                            400 ; external ram data
                            401 ;--------------------------------------------------------
                            402 	.area XSEG    (XDATA)
                    E400    403 _GPIF_WAVE_DATA	=	0xe400
                    E480    404 _RES_WAVEDATA_END	=	0xe480
                    E600    405 _CPUCS	=	0xe600
                    E601    406 _IFCONFIG	=	0xe601
                    E602    407 _PINFLAGSAB	=	0xe602
                    E603    408 _PINFLAGSCD	=	0xe603
                    E604    409 _FIFORESET	=	0xe604
                    E605    410 _BREAKPT	=	0xe605
                    E606    411 _BPADDRH	=	0xe606
                    E607    412 _BPADDRL	=	0xe607
                    E608    413 _UART230	=	0xe608
                    E609    414 _FIFOPINPOLAR	=	0xe609
                    E60A    415 _REVID	=	0xe60a
                    E60B    416 _REVCTL	=	0xe60b
                    E610    417 _EP1OUTCFG	=	0xe610
                    E611    418 _EP1INCFG	=	0xe611
                    E612    419 _EP2CFG	=	0xe612
                    E613    420 _EP4CFG	=	0xe613
                    E614    421 _EP6CFG	=	0xe614
                    E615    422 _EP8CFG	=	0xe615
                    E618    423 _EP2FIFOCFG	=	0xe618
                    E619    424 _EP4FIFOCFG	=	0xe619
                    E61A    425 _EP6FIFOCFG	=	0xe61a
                    E61B    426 _EP8FIFOCFG	=	0xe61b
                    E620    427 _EP2AUTOINLENH	=	0xe620
                    E621    428 _EP2AUTOINLENL	=	0xe621
                    E622    429 _EP4AUTOINLENH	=	0xe622
                    E623    430 _EP4AUTOINLENL	=	0xe623
                    E624    431 _EP6AUTOINLENH	=	0xe624
                    E625    432 _EP6AUTOINLENL	=	0xe625
                    E626    433 _EP8AUTOINLENH	=	0xe626
                    E627    434 _EP8AUTOINLENL	=	0xe627
                    E630    435 _EP2FIFOPFH	=	0xe630
                    E631    436 _EP2FIFOPFL	=	0xe631
                    E632    437 _EP4FIFOPFH	=	0xe632
                    E633    438 _EP4FIFOPFL	=	0xe633
                    E634    439 _EP6FIFOPFH	=	0xe634
                    E635    440 _EP6FIFOPFL	=	0xe635
                    E636    441 _EP8FIFOPFH	=	0xe636
                    E637    442 _EP8FIFOPFL	=	0xe637
                    E640    443 _EP2ISOINPKTS	=	0xe640
                    E641    444 _EP4ISOINPKTS	=	0xe641
                    E642    445 _EP6ISOINPKTS	=	0xe642
                    E643    446 _EP8ISOINPKTS	=	0xe643
                    E648    447 _INPKTEND	=	0xe648
                    E649    448 _OUTPKTEND	=	0xe649
                    E650    449 _EP2FIFOIE	=	0xe650
                    E651    450 _EP2FIFOIRQ	=	0xe651
                    E652    451 _EP4FIFOIE	=	0xe652
                    E653    452 _EP4FIFOIRQ	=	0xe653
                    E654    453 _EP6FIFOIE	=	0xe654
                    E655    454 _EP6FIFOIRQ	=	0xe655
                    E656    455 _EP8FIFOIE	=	0xe656
                    E657    456 _EP8FIFOIRQ	=	0xe657
                    E658    457 _IBNIE	=	0xe658
                    E659    458 _IBNIRQ	=	0xe659
                    E65A    459 _NAKIE	=	0xe65a
                    E65B    460 _NAKIRQ	=	0xe65b
                    E65C    461 _USBIE	=	0xe65c
                    E65D    462 _USBIRQ	=	0xe65d
                    E65E    463 _EPIE	=	0xe65e
                    E65F    464 _EPIRQ	=	0xe65f
                    E660    465 _GPIFIE	=	0xe660
                    E661    466 _GPIFIRQ	=	0xe661
                    E662    467 _USBERRIE	=	0xe662
                    E663    468 _USBERRIRQ	=	0xe663
                    E664    469 _ERRCNTLIM	=	0xe664
                    E665    470 _CLRERRCNT	=	0xe665
                    E666    471 _INT2IVEC	=	0xe666
                    E667    472 _INT4IVEC	=	0xe667
                    E668    473 _INTSETUP	=	0xe668
                    E670    474 _PORTACFG	=	0xe670
                    E671    475 _PORTCCFG	=	0xe671
                    E672    476 _PORTECFG	=	0xe672
                    E678    477 _I2CS	=	0xe678
                    E679    478 _I2DAT	=	0xe679
                    E67A    479 _I2CTL	=	0xe67a
                    E67B    480 _XAUTODAT1	=	0xe67b
                    E67C    481 _XAUTODAT2	=	0xe67c
                    E680    482 _USBCS	=	0xe680
                    E681    483 _SUSPEND	=	0xe681
                    E682    484 _WAKEUPCS	=	0xe682
                    E683    485 _TOGCTL	=	0xe683
                    E684    486 _USBFRAMEH	=	0xe684
                    E685    487 _USBFRAMEL	=	0xe685
                    E686    488 _MICROFRAME	=	0xe686
                    E687    489 _FNADDR	=	0xe687
                    E68A    490 _EP0BCH	=	0xe68a
                    E68B    491 _EP0BCL	=	0xe68b
                    E68D    492 _EP1OUTBC	=	0xe68d
                    E68F    493 _EP1INBC	=	0xe68f
                    E690    494 _EP2BCH	=	0xe690
                    E691    495 _EP2BCL	=	0xe691
                    E694    496 _EP4BCH	=	0xe694
                    E695    497 _EP4BCL	=	0xe695
                    E698    498 _EP6BCH	=	0xe698
                    E699    499 _EP6BCL	=	0xe699
                    E69C    500 _EP8BCH	=	0xe69c
                    E69D    501 _EP8BCL	=	0xe69d
                    E6A0    502 _EP0CS	=	0xe6a0
                    E6A1    503 _EP1OUTCS	=	0xe6a1
                    E6A2    504 _EP1INCS	=	0xe6a2
                    E6A3    505 _EP2CS	=	0xe6a3
                    E6A4    506 _EP4CS	=	0xe6a4
                    E6A5    507 _EP6CS	=	0xe6a5
                    E6A6    508 _EP8CS	=	0xe6a6
                    E6A7    509 _EP2FIFOFLGS	=	0xe6a7
                    E6A8    510 _EP4FIFOFLGS	=	0xe6a8
                    E6A9    511 _EP6FIFOFLGS	=	0xe6a9
                    E6AA    512 _EP8FIFOFLGS	=	0xe6aa
                    E6AB    513 _EP2FIFOBCH	=	0xe6ab
                    E6AC    514 _EP2FIFOBCL	=	0xe6ac
                    E6AD    515 _EP4FIFOBCH	=	0xe6ad
                    E6AE    516 _EP4FIFOBCL	=	0xe6ae
                    E6AF    517 _EP6FIFOBCH	=	0xe6af
                    E6B0    518 _EP6FIFOBCL	=	0xe6b0
                    E6B1    519 _EP8FIFOBCH	=	0xe6b1
                    E6B2    520 _EP8FIFOBCL	=	0xe6b2
                    E6B3    521 _SUDPTRH	=	0xe6b3
                    E6B4    522 _SUDPTRL	=	0xe6b4
                    E6B5    523 _SUDPTRCTL	=	0xe6b5
                    E6B8    524 _SETUPDAT	=	0xe6b8
                    E6C0    525 _GPIFWFSELECT	=	0xe6c0
                    E6C1    526 _GPIFIDLECS	=	0xe6c1
                    E6C2    527 _GPIFIDLECTL	=	0xe6c2
                    E6C3    528 _GPIFCTLCFG	=	0xe6c3
                    E6C4    529 _GPIFADRH	=	0xe6c4
                    E6C5    530 _GPIFADRL	=	0xe6c5
                    E6CE    531 _GPIFTCB3	=	0xe6ce
                    E6CF    532 _GPIFTCB2	=	0xe6cf
                    E6D0    533 _GPIFTCB1	=	0xe6d0
                    E6D1    534 _GPIFTCB0	=	0xe6d1
                    E6D2    535 _EP2GPIFFLGSEL	=	0xe6d2
                    E6D3    536 _EP2GPIFPFSTOP	=	0xe6d3
                    E6D4    537 _EP2GPIFTRIG	=	0xe6d4
                    E6DA    538 _EP4GPIFFLGSEL	=	0xe6da
                    E6DB    539 _EP4GPIFPFSTOP	=	0xe6db
                    E6DC    540 _EP4GPIFTRIG	=	0xe6dc
                    E6E2    541 _EP6GPIFFLGSEL	=	0xe6e2
                    E6E3    542 _EP6GPIFPFSTOP	=	0xe6e3
                    E6E4    543 _EP6GPIFTRIG	=	0xe6e4
                    E6EA    544 _EP8GPIFFLGSEL	=	0xe6ea
                    E6EB    545 _EP8GPIFPFSTOP	=	0xe6eb
                    E6EC    546 _EP8GPIFTRIG	=	0xe6ec
                    E6F0    547 _XGPIFSGLDATH	=	0xe6f0
                    E6F1    548 _XGPIFSGLDATLX	=	0xe6f1
                    E6F2    549 _XGPIFSGLDATLNOX	=	0xe6f2
                    E6F3    550 _GPIFREADYCFG	=	0xe6f3
                    E6F4    551 _GPIFREADYSTAT	=	0xe6f4
                    E6F5    552 _GPIFABORT	=	0xe6f5
                    E6C6    553 _FLOWSTATE	=	0xe6c6
                    E6C7    554 _FLOWLOGIC	=	0xe6c7
                    E6C8    555 _FLOWEQ0CTL	=	0xe6c8
                    E6C9    556 _FLOWEQ1CTL	=	0xe6c9
                    E6CA    557 _FLOWHOLDOFF	=	0xe6ca
                    E6CB    558 _FLOWSTB	=	0xe6cb
                    E6CC    559 _FLOWSTBEDGE	=	0xe6cc
                    E6CD    560 _FLOWSTBHPERIOD	=	0xe6cd
                    E60C    561 _GPIFHOLDAMOUNT	=	0xe60c
                    E67D    562 _UDMACRCH	=	0xe67d
                    E67E    563 _UDMACRCL	=	0xe67e
                    E67F    564 _UDMACRCQUAL	=	0xe67f
                    E6F8    565 _DBUG	=	0xe6f8
                    E6F9    566 _TESTCFG	=	0xe6f9
                    E6FA    567 _USBTEST	=	0xe6fa
                    E6FB    568 _CT1	=	0xe6fb
                    E6FC    569 _CT2	=	0xe6fc
                    E6FD    570 _CT3	=	0xe6fd
                    E6FE    571 _CT4	=	0xe6fe
                    E740    572 _EP0BUF	=	0xe740
                    E780    573 _EP1OUTBUF	=	0xe780
                    E7C0    574 _EP1INBUF	=	0xe7c0
                    F000    575 _EP2FIFOBUF	=	0xf000
                    F400    576 _EP4FIFOBUF	=	0xf400
                    F800    577 _EP6FIFOBUF	=	0xf800
                    FC00    578 _EP8FIFOBUF	=	0xfc00
                            579 ;--------------------------------------------------------
                            580 ; absolute external ram data
                            581 ;--------------------------------------------------------
                            582 	.area XABS    (ABS,XDATA)
                            583 ;--------------------------------------------------------
                            584 ; external initialized ram data
                            585 ;--------------------------------------------------------
                            586 	.area XISEG   (XDATA)
                            587 	.area HOME    (CODE)
                            588 	.area GSINIT0 (CODE)
                            589 	.area GSINIT1 (CODE)
                            590 	.area GSINIT2 (CODE)
                            591 	.area GSINIT3 (CODE)
                            592 	.area GSINIT4 (CODE)
                            593 	.area GSINIT5 (CODE)
                            594 	.area GSINIT  (CODE)
                            595 	.area GSFINAL (CODE)
                            596 	.area CSEG    (CODE)
                            597 ;--------------------------------------------------------
                            598 ; interrupt vector 
                            599 ;--------------------------------------------------------
                            600 	.area HOME    (CODE)
   0000                     601 __interrupt_vect:
   0000 02 00 08            602 	ljmp	__sdcc_gsinit_startup
                            603 ;--------------------------------------------------------
                            604 ; global & static initialisations
                            605 ;--------------------------------------------------------
                            606 	.area HOME    (CODE)
                            607 	.area GSINIT  (CODE)
                            608 	.area GSFINAL (CODE)
                            609 	.area GSINIT  (CODE)
                            610 	.globl __sdcc_gsinit_startup
                            611 	.globl __sdcc_program_startup
                            612 	.globl __start__stack
                            613 	.globl __mcs51_genXINIT
                            614 	.globl __mcs51_genXRAMCLEAR
                            615 	.globl __mcs51_genRAMCLEAR
                            616 ;	eeprom_mark.c:19: char *FWmark = "FWEEPRv000.001";
   0061 75 22 6A            617 	mov	_FWmark,#__str_5
   0064 75 23 0F            618 	mov	(_FWmark + 1),#(__str_5 >> 8)
   0067 75 24 80            619 	mov	(_FWmark + 2),#0x80
                            620 ;	eeprom_mark.c:21: xdata unsigned char *err =(xdata char*)0x1200;
   006A 75 25 00            621 	mov	_err,#0x00
   006D 75 26 12            622 	mov	(_err + 1),#0x12
                            623 ;	eeprom_mark.c:22: xdata unsigned char *dat =(xdata char*)0x1000;
   0070 75 27 00            624 	mov	_dat,#0x00
   0073 75 28 10            625 	mov	(_dat + 1),#0x10
                            626 ;	eeprom_mark.c:23: xdata unsigned char *jump_table =(xdata char*)0x1400;
   0076 75 29 00            627 	mov	_jump_table,#0x00
   0079 75 2A 14            628 	mov	(_jump_table + 1),#0x14
                            629 ;	eeprom_mark.c:234: xdata unsigned char *command = (xdata unsigned char *)0x1100;
   007C 75 2B 00            630 	mov	_command,#0x00
   007F 75 2C 11            631 	mov	(_command + 1),#0x11
                            632 ;	eeprom_mark.c:235: xdata unsigned char *HWmark = (xdata unsigned char *)0x1140;
   0082 75 2D 40            633 	mov	_HWmark,#0x40
   0085 75 2E 11            634 	mov	(_HWmark + 1),#0x11
                            635 	.area GSFINAL (CODE)
   0088 02 00 03            636 	ljmp	__sdcc_program_startup
                            637 ;--------------------------------------------------------
                            638 ; Home
                            639 ;--------------------------------------------------------
                            640 	.area HOME    (CODE)
                            641 	.area HOME    (CODE)
   0003                     642 __sdcc_program_startup:
   0003 12 05 34            643 	lcall	_main
                            644 ;	return from main will lock up
   0006 80 FE               645 	sjmp .
                            646 ;--------------------------------------------------------
                            647 ; code
                            648 ;--------------------------------------------------------
                            649 	.area CSEG    (CODE)
                            650 ;------------------------------------------------------------
                            651 ;Allocation info for local variables in function 'EEErase'
                            652 ;------------------------------------------------------------
                            653 ;ee_adr                    Allocated to registers r6 r7 
                            654 ;------------------------------------------------------------
                            655 ;	eeprom_mark.c:43: static uint8 EEErase(uint16 ee_adr)
                            656 ;	-----------------------------------------
                            657 ;	 function EEErase
                            658 ;	-----------------------------------------
   008B                     659 _EEErase:
                    0007    660 	ar7 = 0x07
                    0006    661 	ar6 = 0x06
                    0005    662 	ar5 = 0x05
                    0004    663 	ar4 = 0x04
                    0003    664 	ar3 = 0x03
                    0002    665 	ar2 = 0x02
                    0001    666 	ar1 = 0x01
                    0000    667 	ar0 = 0x00
   008B AE 82               668 	mov	r6,dpl
   008D AF 83               669 	mov	r7,dph
                            670 ;	eeprom_mark.c:45: I2CS = I2CS_START;
   008F 90 E6 78            671 	mov	dptr,#_I2CS
   0092 74 80               672 	mov	a,#0x80
   0094 F0                  673 	movx	@dptr,a
                            674 ;	eeprom_mark.c:46: I2DAT = EEPROM_ADR | I2CWRITE;
   0095 90 E6 79            675 	mov	dptr,#_I2DAT
   0098 74 A2               676 	mov	a,#0xA2
   009A F0                  677 	movx	@dptr,a
                            678 ;	eeprom_mark.c:47: while(!(I2CS & I2CS_DONE));
   009B                     679 00101$:
   009B 90 E6 78            680 	mov	dptr,#_I2CS
   009E E0                  681 	movx	a,@dptr
   009F FD                  682 	mov	r5,a
   00A0 30 E0 F8            683 	jnb	acc.0,00101$
                            684 ;	eeprom_mark.c:50: if(!(I2CS & I2CS_ACK)) return(1);
   00A3 90 E6 78            685 	mov	dptr,#_I2CS
   00A6 E0                  686 	movx	a,@dptr
   00A7 FD                  687 	mov	r5,a
   00A8 20 E1 04            688 	jb	acc.1,00105$
   00AB 75 82 01            689 	mov	dpl,#0x01
   00AE 22                  690 	ret
   00AF                     691 00105$:
                            692 ;	eeprom_mark.c:53: I2DAT = (ee_adr>>8);
   00AF 90 E6 79            693 	mov	dptr,#_I2DAT
   00B2 EF                  694 	mov	a,r7
   00B3 F0                  695 	movx	@dptr,a
                            696 ;	eeprom_mark.c:54: while(!(I2CS & I2CS_DONE));
   00B4                     697 00106$:
   00B4 90 E6 78            698 	mov	dptr,#_I2CS
   00B7 E0                  699 	movx	a,@dptr
   00B8 FD                  700 	mov	r5,a
   00B9 30 E0 F8            701 	jnb	acc.0,00106$
                            702 ;	eeprom_mark.c:57: if(!(I2CS & I2CS_ACK)) return(2);
   00BC 90 E6 78            703 	mov	dptr,#_I2CS
   00BF E0                  704 	movx	a,@dptr
   00C0 FD                  705 	mov	r5,a
   00C1 20 E1 04            706 	jb	acc.1,00110$
   00C4 75 82 02            707 	mov	dpl,#0x02
   00C7 22                  708 	ret
   00C8                     709 00110$:
                            710 ;	eeprom_mark.c:60: I2DAT = (ee_adr & 0xff);
   00C8 7F 00               711 	mov	r7,#0x00
   00CA 90 E6 79            712 	mov	dptr,#_I2DAT
   00CD EE                  713 	mov	a,r6
   00CE F0                  714 	movx	@dptr,a
                            715 ;	eeprom_mark.c:61: while(!(I2CS & I2CS_DONE));
   00CF                     716 00111$:
   00CF 90 E6 78            717 	mov	dptr,#_I2CS
   00D2 E0                  718 	movx	a,@dptr
   00D3 FF                  719 	mov	r7,a
   00D4 30 E0 F8            720 	jnb	acc.0,00111$
                            721 ;	eeprom_mark.c:64: if(!(I2CS & I2CS_ACK)) return(3);
   00D7 90 E6 78            722 	mov	dptr,#_I2CS
   00DA E0                  723 	movx	a,@dptr
   00DB FF                  724 	mov	r7,a
   00DC 20 E1 04            725 	jb	acc.1,00115$
   00DF 75 82 03            726 	mov	dpl,#0x03
   00E2 22                  727 	ret
   00E3                     728 00115$:
                            729 ;	eeprom_mark.c:67: I2DAT = 0xff;
   00E3 90 E6 79            730 	mov	dptr,#_I2DAT
   00E6 74 FF               731 	mov	a,#0xFF
   00E8 F0                  732 	movx	@dptr,a
                            733 ;	eeprom_mark.c:68: while(!(I2CS & I2CS_DONE));
   00E9                     734 00116$:
   00E9 90 E6 78            735 	mov	dptr,#_I2CS
   00EC E0                  736 	movx	a,@dptr
   00ED FF                  737 	mov	r7,a
   00EE 30 E0 F8            738 	jnb	acc.0,00116$
                            739 ;	eeprom_mark.c:70: I2CS = I2CS_STOP;
                            740 ;	eeprom_mark.c:72: if(!(I2CS & I2CS_ACK)) return(4);
   00F1 90 E6 78            741 	mov	dptr,#_I2CS
   00F4 74 40               742 	mov	a,#0x40
   00F6 F0                  743 	movx	@dptr,a
   00F7 E0                  744 	movx	a,@dptr
   00F8 FF                  745 	mov	r7,a
   00F9 20 E1 04            746 	jb	acc.1,00127$
   00FC 75 82 04            747 	mov	dpl,#0x04
   00FF 22                  748 	ret
   0100                     749 00127$:
                            750 ;	eeprom_mark.c:77: I2CS = I2CS_START;
   0100 90 E6 78            751 	mov	dptr,#_I2CS
   0103 74 80               752 	mov	a,#0x80
   0105 F0                  753 	movx	@dptr,a
                            754 ;	eeprom_mark.c:78: I2DAT = EEPROM_ADR | I2CWRITE;
   0106 90 E6 79            755 	mov	dptr,#_I2DAT
   0109 74 A2               756 	mov	a,#0xA2
   010B F0                  757 	movx	@dptr,a
                            758 ;	eeprom_mark.c:79: while(!(I2CS & I2CS_DONE));
   010C                     759 00121$:
   010C 90 E6 78            760 	mov	dptr,#_I2CS
   010F E0                  761 	movx	a,@dptr
   0110 FF                  762 	mov	r7,a
   0111 30 E0 F8            763 	jnb	acc.0,00121$
                            764 ;	eeprom_mark.c:81: if((I2CS & I2CS_ACK)) break;
   0114 90 E6 78            765 	mov	dptr,#_I2CS
   0117 E0                  766 	movx	a,@dptr
   0118 FF                  767 	mov	r7,a
   0119 30 E1 E4            768 	jnb	acc.1,00127$
                            769 ;	eeprom_mark.c:84: return(64);
   011C 75 82 40            770 	mov	dpl,#0x40
   011F 22                  771 	ret
                            772 ;------------------------------------------------------------
                            773 ;Allocation info for local variables in function 'EEWrite'
                            774 ;------------------------------------------------------------
                            775 ;a                         Allocated with name '_EEWrite_PARM_2'
                            776 ;ee_adr                    Allocated to registers r6 r7 
                            777 ;------------------------------------------------------------
                            778 ;	eeprom_mark.c:92: static uint8 EEWrite(uint16 ee_adr, unsigned char a)
                            779 ;	-----------------------------------------
                            780 ;	 function EEWrite
                            781 ;	-----------------------------------------
   0120                     782 _EEWrite:
   0120 AE 82               783 	mov	r6,dpl
   0122 AF 83               784 	mov	r7,dph
                            785 ;	eeprom_mark.c:94: I2CS = I2CS_START;
   0124 90 E6 78            786 	mov	dptr,#_I2CS
   0127 74 80               787 	mov	a,#0x80
   0129 F0                  788 	movx	@dptr,a
                            789 ;	eeprom_mark.c:95: I2DAT = EEPROM_ADR | I2CWRITE;
   012A 90 E6 79            790 	mov	dptr,#_I2DAT
   012D 74 A2               791 	mov	a,#0xA2
   012F F0                  792 	movx	@dptr,a
                            793 ;	eeprom_mark.c:96: while(!(I2CS & I2CS_DONE));
   0130                     794 00101$:
   0130 90 E6 78            795 	mov	dptr,#_I2CS
   0133 E0                  796 	movx	a,@dptr
   0134 FD                  797 	mov	r5,a
   0135 30 E0 F8            798 	jnb	acc.0,00101$
                            799 ;	eeprom_mark.c:99: if(!(I2CS & I2CS_ACK)) return(1);
   0138 90 E6 78            800 	mov	dptr,#_I2CS
   013B E0                  801 	movx	a,@dptr
   013C FD                  802 	mov	r5,a
   013D 20 E1 04            803 	jb	acc.1,00105$
   0140 75 82 01            804 	mov	dpl,#0x01
   0143 22                  805 	ret
   0144                     806 00105$:
                            807 ;	eeprom_mark.c:102: I2DAT = (ee_adr>>8);
   0144 90 E6 79            808 	mov	dptr,#_I2DAT
   0147 EF                  809 	mov	a,r7
   0148 F0                  810 	movx	@dptr,a
                            811 ;	eeprom_mark.c:103: while(!(I2CS & I2CS_DONE));
   0149                     812 00106$:
   0149 90 E6 78            813 	mov	dptr,#_I2CS
   014C E0                  814 	movx	a,@dptr
   014D FD                  815 	mov	r5,a
   014E 30 E0 F8            816 	jnb	acc.0,00106$
                            817 ;	eeprom_mark.c:106: if(!(I2CS & I2CS_ACK)) return(2);
   0151 90 E6 78            818 	mov	dptr,#_I2CS
   0154 E0                  819 	movx	a,@dptr
   0155 FD                  820 	mov	r5,a
   0156 20 E1 04            821 	jb	acc.1,00110$
   0159 75 82 02            822 	mov	dpl,#0x02
   015C 22                  823 	ret
   015D                     824 00110$:
                            825 ;	eeprom_mark.c:109: I2DAT = (ee_adr & 0xff);
   015D 7F 00               826 	mov	r7,#0x00
   015F 90 E6 79            827 	mov	dptr,#_I2DAT
   0162 EE                  828 	mov	a,r6
   0163 F0                  829 	movx	@dptr,a
                            830 ;	eeprom_mark.c:110: while(!(I2CS & I2CS_DONE));
   0164                     831 00111$:
   0164 90 E6 78            832 	mov	dptr,#_I2CS
   0167 E0                  833 	movx	a,@dptr
   0168 FF                  834 	mov	r7,a
   0169 30 E0 F8            835 	jnb	acc.0,00111$
                            836 ;	eeprom_mark.c:113: if(!(I2CS & I2CS_ACK)) return(3);
   016C 90 E6 78            837 	mov	dptr,#_I2CS
   016F E0                  838 	movx	a,@dptr
   0170 FF                  839 	mov	r7,a
   0171 20 E1 04            840 	jb	acc.1,00115$
   0174 75 82 03            841 	mov	dpl,#0x03
   0177 22                  842 	ret
   0178                     843 00115$:
                            844 ;	eeprom_mark.c:116: I2DAT = a;
   0178 90 E6 79            845 	mov	dptr,#_I2DAT
   017B E5 10               846 	mov	a,_EEWrite_PARM_2
   017D F0                  847 	movx	@dptr,a
                            848 ;	eeprom_mark.c:117: while(!(I2CS & I2CS_DONE));
   017E                     849 00116$:
   017E 90 E6 78            850 	mov	dptr,#_I2CS
   0181 E0                  851 	movx	a,@dptr
   0182 FF                  852 	mov	r7,a
   0183 30 E0 F8            853 	jnb	acc.0,00116$
                            854 ;	eeprom_mark.c:119: I2CS = I2CS_STOP;
                            855 ;	eeprom_mark.c:121: if(!(I2CS & I2CS_ACK)) return(4);
   0186 90 E6 78            856 	mov	dptr,#_I2CS
   0189 74 40               857 	mov	a,#0x40
   018B F0                  858 	movx	@dptr,a
   018C E0                  859 	movx	a,@dptr
   018D FF                  860 	mov	r7,a
   018E 20 E1 04            861 	jb	acc.1,00127$
   0191 75 82 04            862 	mov	dpl,#0x04
   0194 22                  863 	ret
   0195                     864 00127$:
                            865 ;	eeprom_mark.c:126: I2CS = I2CS_START;
   0195 90 E6 78            866 	mov	dptr,#_I2CS
   0198 74 80               867 	mov	a,#0x80
   019A F0                  868 	movx	@dptr,a
                            869 ;	eeprom_mark.c:127: I2DAT = EEPROM_ADR | I2CWRITE;
   019B 90 E6 79            870 	mov	dptr,#_I2DAT
   019E 74 A2               871 	mov	a,#0xA2
   01A0 F0                  872 	movx	@dptr,a
                            873 ;	eeprom_mark.c:128: while(!(I2CS & I2CS_DONE));
   01A1                     874 00121$:
   01A1 90 E6 78            875 	mov	dptr,#_I2CS
   01A4 E0                  876 	movx	a,@dptr
   01A5 FF                  877 	mov	r7,a
   01A6 30 E0 F8            878 	jnb	acc.0,00121$
                            879 ;	eeprom_mark.c:130: if((I2CS & I2CS_ACK)) break;
   01A9 90 E6 78            880 	mov	dptr,#_I2CS
   01AC E0                  881 	movx	a,@dptr
   01AD FF                  882 	mov	r7,a
   01AE 30 E1 E4            883 	jnb	acc.1,00127$
                            884 ;	eeprom_mark.c:132: return(64);
   01B1 75 82 40            885 	mov	dpl,#0x40
   01B4 22                  886 	ret
                            887 ;------------------------------------------------------------
                            888 ;Allocation info for local variables in function 'EERead'
                            889 ;------------------------------------------------------------
                            890 ;HWmark                    Allocated with name '_EERead_PARM_2'
                            891 ;ee_adr                    Allocated to registers r6 r7 
                            892 ;n                         Allocated with name '_EERead_n_1_1'
                            893 ;------------------------------------------------------------
                            894 ;	eeprom_mark.c:140: static uint8 EERead(uint16 ee_adr, 	unsigned char HWmark[32])
                            895 ;	-----------------------------------------
                            896 ;	 function EERead
                            897 ;	-----------------------------------------
   01B5                     898 _EERead:
   01B5 AE 82               899 	mov	r6,dpl
   01B7 AF 83               900 	mov	r7,dph
                            901 ;	eeprom_mark.c:145: I2CS = I2CS_START;
   01B9 90 E6 78            902 	mov	dptr,#_I2CS
   01BC 74 80               903 	mov	a,#0x80
   01BE F0                  904 	movx	@dptr,a
                            905 ;	eeprom_mark.c:146: I2DAT = EEPROM_ADR | I2CWRITE;
   01BF 90 E6 79            906 	mov	dptr,#_I2DAT
   01C2 74 A2               907 	mov	a,#0xA2
   01C4 F0                  908 	movx	@dptr,a
                            909 ;	eeprom_mark.c:147: while(!(I2CS & I2CS_DONE));
   01C5                     910 00101$:
   01C5 90 E6 78            911 	mov	dptr,#_I2CS
   01C8 E0                  912 	movx	a,@dptr
   01C9 FD                  913 	mov	r5,a
   01CA 30 E0 F8            914 	jnb	acc.0,00101$
                            915 ;	eeprom_mark.c:150: if(!(I2CS & I2CS_ACK)) return(1);
   01CD 90 E6 78            916 	mov	dptr,#_I2CS
   01D0 E0                  917 	movx	a,@dptr
   01D1 FD                  918 	mov	r5,a
   01D2 20 E1 04            919 	jb	acc.1,00105$
   01D5 75 82 01            920 	mov	dpl,#0x01
   01D8 22                  921 	ret
   01D9                     922 00105$:
                            923 ;	eeprom_mark.c:153: I2DAT = (ee_adr>>8);
   01D9 90 E6 79            924 	mov	dptr,#_I2DAT
   01DC EF                  925 	mov	a,r7
   01DD F0                  926 	movx	@dptr,a
                            927 ;	eeprom_mark.c:154: while(!(I2CS & I2CS_DONE));
   01DE                     928 00106$:
   01DE 90 E6 78            929 	mov	dptr,#_I2CS
   01E1 E0                  930 	movx	a,@dptr
   01E2 FD                  931 	mov	r5,a
   01E3 30 E0 F8            932 	jnb	acc.0,00106$
                            933 ;	eeprom_mark.c:157: if(!(I2CS & I2CS_ACK)) return(2);
   01E6 90 E6 78            934 	mov	dptr,#_I2CS
   01E9 E0                  935 	movx	a,@dptr
   01EA FD                  936 	mov	r5,a
   01EB 20 E1 04            937 	jb	acc.1,00110$
   01EE 75 82 02            938 	mov	dpl,#0x02
   01F1 22                  939 	ret
   01F2                     940 00110$:
                            941 ;	eeprom_mark.c:160: I2DAT = (ee_adr & 0xff);
   01F2 7F 00               942 	mov	r7,#0x00
   01F4 90 E6 79            943 	mov	dptr,#_I2DAT
   01F7 EE                  944 	mov	a,r6
   01F8 F0                  945 	movx	@dptr,a
                            946 ;	eeprom_mark.c:161: while(!(I2CS & I2CS_DONE));
   01F9                     947 00111$:
   01F9 90 E6 78            948 	mov	dptr,#_I2CS
   01FC E0                  949 	movx	a,@dptr
   01FD FF                  950 	mov	r7,a
   01FE 30 E0 F8            951 	jnb	acc.0,00111$
                            952 ;	eeprom_mark.c:164: if(!(I2CS & I2CS_ACK)) return(3);
   0201 90 E6 78            953 	mov	dptr,#_I2CS
   0204 E0                  954 	movx	a,@dptr
   0205 FF                  955 	mov	r7,a
   0206 20 E1 04            956 	jb	acc.1,00115$
   0209 75 82 03            957 	mov	dpl,#0x03
   020C 22                  958 	ret
   020D                     959 00115$:
                            960 ;	eeprom_mark.c:167: I2CS = I2CS_START;
   020D 90 E6 78            961 	mov	dptr,#_I2CS
   0210 74 80               962 	mov	a,#0x80
   0212 F0                  963 	movx	@dptr,a
                            964 ;	eeprom_mark.c:168: I2DAT = EEPROM_ADR | I2CREAD;
   0213 90 E6 79            965 	mov	dptr,#_I2DAT
   0216 74 A3               966 	mov	a,#0xA3
   0218 F0                  967 	movx	@dptr,a
                            968 ;	eeprom_mark.c:169: while(!(I2CS & I2CS_DONE));
   0219                     969 00116$:
   0219 90 E6 78            970 	mov	dptr,#_I2CS
   021C E0                  971 	movx	a,@dptr
   021D FF                  972 	mov	r7,a
   021E 30 E0 F8            973 	jnb	acc.0,00116$
                            974 ;	eeprom_mark.c:172: if(!(I2CS & I2CS_ACK)) return(5);
   0221 90 E6 78            975 	mov	dptr,#_I2CS
   0224 E0                  976 	movx	a,@dptr
   0225 FF                  977 	mov	r7,a
   0226 20 E1 04            978 	jb	acc.1,00120$
   0229 75 82 05            979 	mov	dpl,#0x05
   022C 22                  980 	ret
   022D                     981 00120$:
                            982 ;	eeprom_mark.c:175: HWmark[0] = I2DAT;
   022D AD 10               983 	mov	r5,_EERead_PARM_2
   022F AE 11               984 	mov	r6,(_EERead_PARM_2 + 1)
   0231 AF 12               985 	mov	r7,(_EERead_PARM_2 + 2)
   0233 90 E6 79            986 	mov	dptr,#_I2DAT
   0236 E0                  987 	movx	a,@dptr
   0237 FC                  988 	mov	r4,a
   0238 8D 82               989 	mov	dpl,r5
   023A 8E 83               990 	mov	dph,r6
   023C 8F F0               991 	mov	b,r7
   023E 12 08 2D            992 	lcall	__gptrput
                            993 ;	eeprom_mark.c:176: while(!(I2CS & I2CS_DONE));
   0241                     994 00121$:
   0241 90 E6 78            995 	mov	dptr,#_I2CS
   0244 E0                  996 	movx	a,@dptr
   0245 FC                  997 	mov	r4,a
   0246 30 E0 F8            998 	jnb	acc.0,00121$
                            999 ;	eeprom_mark.c:177: if(!(I2CS & I2CS_ACK)) return(6);
   0249 90 E6 78           1000 	mov	dptr,#_I2CS
   024C E0                 1001 	movx	a,@dptr
   024D FC                 1002 	mov	r4,a
   024E 20 E1 04           1003 	jb	acc.1,00126$
   0251 75 82 06           1004 	mov	dpl,#0x06
   0254 22                 1005 	ret
                           1006 ;	eeprom_mark.c:180: while(!(I2CS & I2CS_DONE));
   0255                    1007 00126$:
   0255 90 E6 78           1008 	mov	dptr,#_I2CS
   0258 E0                 1009 	movx	a,@dptr
   0259 FC                 1010 	mov	r4,a
   025A 30 E0 F8           1011 	jnb	acc.0,00126$
                           1012 ;	eeprom_mark.c:181: if(!(I2CS & I2CS_ACK)) return(7);
   025D 90 E6 78           1013 	mov	dptr,#_I2CS
   0260 E0                 1014 	movx	a,@dptr
   0261 FC                 1015 	mov	r4,a
   0262 20 E1 04           1016 	jb	acc.1,00130$
   0265 75 82 07           1017 	mov	dpl,#0x07
   0268 22                 1018 	ret
   0269                    1019 00130$:
                           1020 ;	eeprom_mark.c:183: HWmark[0] = I2DAT;
   0269 90 E6 79           1021 	mov	dptr,#_I2DAT
   026C E0                 1022 	movx	a,@dptr
   026D FC                 1023 	mov	r4,a
   026E 8D 82              1024 	mov	dpl,r5
   0270 8E 83              1025 	mov	dph,r6
   0272 8F F0              1026 	mov	b,r7
   0274 12 08 2D           1027 	lcall	__gptrput
                           1028 ;	eeprom_mark.c:184: while(!(I2CS & I2CS_DONE));
   0277                    1029 00131$:
   0277 90 E6 78           1030 	mov	dptr,#_I2CS
   027A E0                 1031 	movx	a,@dptr
   027B FC                 1032 	mov	r4,a
   027C 30 E0 F8           1033 	jnb	acc.0,00131$
                           1034 ;	eeprom_mark.c:185: if(!(I2CS & I2CS_ACK)) return(8);
   027F 90 E6 78           1035 	mov	dptr,#_I2CS
   0282 E0                 1036 	movx	a,@dptr
   0283 FC                 1037 	mov	r4,a
   0284 20 E1 04           1038 	jb	acc.1,00135$
   0287 75 82 08           1039 	mov	dpl,#0x08
   028A 22                 1040 	ret
   028B                    1041 00135$:
                           1042 ;	eeprom_mark.c:187: HWmark[1] = I2DAT;
   028B 74 01              1043 	mov	a,#0x01
   028D 2D                 1044 	add	a,r5
   028E FA                 1045 	mov	r2,a
   028F E4                 1046 	clr	a
   0290 3E                 1047 	addc	a,r6
   0291 FB                 1048 	mov	r3,a
   0292 8F 04              1049 	mov	ar4,r7
   0294 90 E6 79           1050 	mov	dptr,#_I2DAT
   0297 E0                 1051 	movx	a,@dptr
   0298 F9                 1052 	mov	r1,a
   0299 8A 82              1053 	mov	dpl,r2
   029B 8B 83              1054 	mov	dph,r3
   029D 8C F0              1055 	mov	b,r4
   029F 12 08 2D           1056 	lcall	__gptrput
                           1057 ;	eeprom_mark.c:188: while(!(I2CS & I2CS_DONE));
   02A2                    1058 00136$:
   02A2 90 E6 78           1059 	mov	dptr,#_I2CS
   02A5 E0                 1060 	movx	a,@dptr
   02A6 FC                 1061 	mov	r4,a
   02A7 30 E0 F8           1062 	jnb	acc.0,00136$
                           1063 ;	eeprom_mark.c:189: if(!(I2CS & I2CS_ACK)) return(8);
   02AA 90 E6 78           1064 	mov	dptr,#_I2CS
   02AD E0                 1065 	movx	a,@dptr
   02AE FC                 1066 	mov	r4,a
   02AF 20 E1 04           1067 	jb	acc.1,00193$
   02B2 75 82 08           1068 	mov	dpl,#0x08
   02B5 22                 1069 	ret
                           1070 ;	eeprom_mark.c:191: for(n = 2;n<31;n++) {
   02B6                    1071 00193$:
   02B6 75 13 02           1072 	mov	_EERead_n_1_1,#0x02
   02B9 75 14 00           1073 	mov	(_EERead_n_1_1 + 1),#0x00
   02BC                    1074 00159$:
   02BC C3                 1075 	clr	c
   02BD E5 13              1076 	mov	a,_EERead_n_1_1
   02BF 94 1F              1077 	subb	a,#0x1F
   02C1 E5 14              1078 	mov	a,(_EERead_n_1_1 + 1)
   02C3 64 80              1079 	xrl	a,#0x80
   02C5 94 80              1080 	subb	a,#0x80
   02C7 50 36              1081 	jnc	00162$
                           1082 ;	eeprom_mark.c:192: HWmark[n] = I2DAT;
   02C9 E5 13              1083 	mov	a,_EERead_n_1_1
   02CB 2D                 1084 	add	a,r5
   02CC F8                 1085 	mov	r0,a
   02CD E5 14              1086 	mov	a,(_EERead_n_1_1 + 1)
   02CF 3E                 1087 	addc	a,r6
   02D0 F9                 1088 	mov	r1,a
   02D1 8F 02              1089 	mov	ar2,r7
   02D3 90 E6 79           1090 	mov	dptr,#_I2DAT
   02D6 E0                 1091 	movx	a,@dptr
   02D7 FC                 1092 	mov	r4,a
   02D8 88 82              1093 	mov	dpl,r0
   02DA 89 83              1094 	mov	dph,r1
   02DC 8A F0              1095 	mov	b,r2
   02DE 12 08 2D           1096 	lcall	__gptrput
                           1097 ;	eeprom_mark.c:193: while(!(I2CS & I2CS_DONE));
   02E1                    1098 00141$:
   02E1 90 E6 78           1099 	mov	dptr,#_I2CS
   02E4 E0                 1100 	movx	a,@dptr
   02E5 FC                 1101 	mov	r4,a
   02E6 30 E0 F8           1102 	jnb	acc.0,00141$
                           1103 ;	eeprom_mark.c:194: if(!(I2CS & I2CS_ACK)) return(9);
   02E9 90 E6 78           1104 	mov	dptr,#_I2CS
   02EC E0                 1105 	movx	a,@dptr
   02ED FC                 1106 	mov	r4,a
   02EE 20 E1 04           1107 	jb	acc.1,00161$
   02F1 75 82 09           1108 	mov	dpl,#0x09
   02F4 22                 1109 	ret
   02F5                    1110 00161$:
                           1111 ;	eeprom_mark.c:191: for(n = 2;n<31;n++) {
   02F5 05 13              1112 	inc	_EERead_n_1_1
   02F7 E4                 1113 	clr	a
   02F8 B5 13 C1           1114 	cjne	a,_EERead_n_1_1,00159$
   02FB 05 14              1115 	inc	(_EERead_n_1_1 + 1)
   02FD 80 BD              1116 	sjmp	00159$
   02FF                    1117 00162$:
                           1118 ;	eeprom_mark.c:197: I2CS = I2CS_LASTRD;
   02FF 90 E6 78           1119 	mov	dptr,#_I2CS
   0302 74 20              1120 	mov	a,#0x20
   0304 F0                 1121 	movx	@dptr,a
                           1122 ;	eeprom_mark.c:198: HWmark[31] = I2DAT;
   0305 74 1F              1123 	mov	a,#0x1F
   0307 2D                 1124 	add	a,r5
   0308 FD                 1125 	mov	r5,a
   0309 E4                 1126 	clr	a
   030A 3E                 1127 	addc	a,r6
   030B FE                 1128 	mov	r6,a
   030C 90 E6 79           1129 	mov	dptr,#_I2DAT
   030F E0                 1130 	movx	a,@dptr
   0310 FC                 1131 	mov	r4,a
   0311 8D 82              1132 	mov	dpl,r5
   0313 8E 83              1133 	mov	dph,r6
   0315 8F F0              1134 	mov	b,r7
   0317 12 08 2D           1135 	lcall	__gptrput
                           1136 ;	eeprom_mark.c:199: while(!(I2CS & I2CS_DONE));
   031A                    1137 00146$:
   031A 90 E6 78           1138 	mov	dptr,#_I2CS
   031D E0                 1139 	movx	a,@dptr
   031E FC                 1140 	mov	r4,a
   031F 30 E0 F8           1141 	jnb	acc.0,00146$
                           1142 ;	eeprom_mark.c:200: HWmark[31] = I2DAT;
   0322 90 E6 79           1143 	mov	dptr,#_I2DAT
   0325 E0                 1144 	movx	a,@dptr
   0326 FC                 1145 	mov	r4,a
   0327 8D 82              1146 	mov	dpl,r5
   0329 8E 83              1147 	mov	dph,r6
   032B 8F F0              1148 	mov	b,r7
   032D 12 08 2D           1149 	lcall	__gptrput
                           1150 ;	eeprom_mark.c:201: while(!(I2CS & I2CS_DONE));
   0330                    1151 00149$:
   0330 90 E6 78           1152 	mov	dptr,#_I2CS
   0333 E0                 1153 	movx	a,@dptr
   0334 FF                 1154 	mov	r7,a
   0335 30 E0 F8           1155 	jnb	acc.0,00149$
                           1156 ;	eeprom_mark.c:202: if(!(I2CS & I2CS_ACK)) return(10);
   0338 90 E6 78           1157 	mov	dptr,#_I2CS
   033B E0                 1158 	movx	a,@dptr
   033C FF                 1159 	mov	r7,a
   033D 20 E1 04           1160 	jb	acc.1,00153$
   0340 75 82 0A           1161 	mov	dpl,#0x0A
   0343 22                 1162 	ret
   0344                    1163 00153$:
                           1164 ;	eeprom_mark.c:213: I2CS = I2CS_STOP;
   0344 90 E6 78           1165 	mov	dptr,#_I2CS
   0347 74 40              1166 	mov	a,#0x40
   0349 F0                 1167 	movx	@dptr,a
                           1168 ;	eeprom_mark.c:214: while(!(I2CS & I2CS_DONE));
   034A                    1169 00154$:
   034A 90 E6 78           1170 	mov	dptr,#_I2CS
   034D E0                 1171 	movx	a,@dptr
   034E FF                 1172 	mov	r7,a
   034F 30 E0 F8           1173 	jnb	acc.0,00154$
                           1174 ;	eeprom_mark.c:216: if(!(I2CS & I2CS_ACK)) return(11);
   0352 90 E6 78           1175 	mov	dptr,#_I2CS
   0355 E0                 1176 	movx	a,@dptr
   0356 FF                 1177 	mov	r7,a
   0357 20 E1 04           1178 	jb	acc.1,00158$
   035A 75 82 0B           1179 	mov	dpl,#0x0B
   035D 22                 1180 	ret
   035E                    1181 00158$:
                           1182 ;	eeprom_mark.c:218: return(64);
   035E 75 82 40           1183 	mov	dpl,#0x40
   0361 22                 1184 	ret
                           1185 ;------------------------------------------------------------
                           1186 ;Allocation info for local variables in function 'readmarkeeprom'
                           1187 ;------------------------------------------------------------
                           1188 ;n                         Allocated to registers r6 r7 
                           1189 ;------------------------------------------------------------
                           1190 ;	eeprom_mark.c:238: static uint8 readmarkeeprom(void) {
                           1191 ;	-----------------------------------------
                           1192 ;	 function readmarkeeprom
                           1193 ;	-----------------------------------------
   0362                    1194 _readmarkeeprom:
                           1195 ;	eeprom_mark.c:242: I2CTL = 0x01;	// Set 400kHz:
   0362 90 E6 7A           1196 	mov	dptr,#_I2CTL
   0365 74 01              1197 	mov	a,#0x01
   0367 F0                 1198 	movx	@dptr,a
                           1199 ;	eeprom_mark.c:243: SYNCDELAY;
   0368 00                 1200 	 nop; 
                           1201 ;	eeprom_mark.c:245: for(n=0;n<128;n++) HWmark[n] = 0x00;
   0369 7E 00              1202 	mov	r6,#0x00
   036B 7F 00              1203 	mov	r7,#0x00
   036D                    1204 00101$:
   036D C3                 1205 	clr	c
   036E EE                 1206 	mov	a,r6
   036F 94 80              1207 	subb	a,#0x80
   0371 EF                 1208 	mov	a,r7
   0372 64 80              1209 	xrl	a,#0x80
   0374 94 80              1210 	subb	a,#0x80
   0376 50 13              1211 	jnc	00104$
   0378 EE                 1212 	mov	a,r6
   0379 25 2D              1213 	add	a,_HWmark
   037B F5 82              1214 	mov	dpl,a
   037D EF                 1215 	mov	a,r7
   037E 35 2E              1216 	addc	a,(_HWmark + 1)
   0380 F5 83              1217 	mov	dph,a
   0382 E4                 1218 	clr	a
   0383 F0                 1219 	movx	@dptr,a
   0384 0E                 1220 	inc	r6
   0385 BE 00 E5           1221 	cjne	r6,#0x00,00101$
   0388 0F                 1222 	inc	r7
   0389 80 E2              1223 	sjmp	00101$
   038B                    1224 00104$:
                           1225 ;	eeprom_mark.c:246: err[32+3] = EERead( 0x0400,HWmark);
   038B 74 23              1226 	mov	a,#0x23
   038D 25 25              1227 	add	a,_err
   038F FE                 1228 	mov	r6,a
   0390 E4                 1229 	clr	a
   0391 35 26              1230 	addc	a,(_err + 1)
   0393 FF                 1231 	mov	r7,a
   0394 85 2D 10           1232 	mov	_EERead_PARM_2,_HWmark
   0397 85 2E 11           1233 	mov	(_EERead_PARM_2 + 1),(_HWmark + 1)
   039A 75 12 00           1234 	mov	(_EERead_PARM_2 + 2),#0x00
   039D 90 04 00           1235 	mov	dptr,#0x0400
   03A0 C0 07              1236 	push	ar7
   03A2 C0 06              1237 	push	ar6
   03A4 12 01 B5           1238 	lcall	_EERead
   03A7 AD 82              1239 	mov	r5,dpl
   03A9 D0 06              1240 	pop	ar6
   03AB D0 07              1241 	pop	ar7
   03AD 8E 82              1242 	mov	dpl,r6
   03AF 8F 83              1243 	mov	dph,r7
   03B1 ED                 1244 	mov	a,r5
   03B2 F0                 1245 	movx	@dptr,a
                           1246 ;	eeprom_mark.c:247: return(0);
   03B3 75 82 00           1247 	mov	dpl,#0x00
   03B6 22                 1248 	ret
                           1249 ;------------------------------------------------------------
                           1250 ;Allocation info for local variables in function 'writemarkeeprom'
                           1251 ;------------------------------------------------------------
                           1252 ;mark                      Allocated with name '_writemarkeeprom_mark_1_1'
                           1253 ;n                         Allocated to registers r3 r4 
                           1254 ;sloc0                     Allocated with name '_writemarkeeprom_sloc0_1_0'
                           1255 ;sloc1                     Allocated with name '_writemarkeeprom_sloc1_1_0'
                           1256 ;------------------------------------------------------------
                           1257 ;	eeprom_mark.c:251: static uint8 writemarkeeprom(struct mark *mark) {
                           1258 ;	-----------------------------------------
                           1259 ;	 function writemarkeeprom
                           1260 ;	-----------------------------------------
   03B7                    1261 _writemarkeeprom:
   03B7 85 82 2F           1262 	mov	_writemarkeeprom_mark_1_1,dpl
   03BA 85 83 30           1263 	mov	(_writemarkeeprom_mark_1_1 + 1),dph
   03BD 85 F0 31           1264 	mov	(_writemarkeeprom_mark_1_1 + 2),b
                           1265 ;	eeprom_mark.c:255: I2CTL = 0x01;	// Set 400kHz:
   03C0 90 E6 7A           1266 	mov	dptr,#_I2CTL
   03C3 74 01              1267 	mov	a,#0x01
   03C5 F0                 1268 	movx	@dptr,a
                           1269 ;	eeprom_mark.c:256: SYNCDELAY;
   03C6 00                 1270 	 nop; 
                           1271 ;	eeprom_mark.c:258: for(n=0;n<128;n++) HWmark[n] = 0x00;
   03C7 7B 00              1272 	mov	r3,#0x00
   03C9 7C 00              1273 	mov	r4,#0x00
   03CB                    1274 00101$:
   03CB C3                 1275 	clr	c
   03CC EB                 1276 	mov	a,r3
   03CD 94 80              1277 	subb	a,#0x80
   03CF EC                 1278 	mov	a,r4
   03D0 64 80              1279 	xrl	a,#0x80
   03D2 94 80              1280 	subb	a,#0x80
   03D4 50 13              1281 	jnc	00104$
   03D6 EB                 1282 	mov	a,r3
   03D7 25 2D              1283 	add	a,_HWmark
   03D9 F5 82              1284 	mov	dpl,a
   03DB EC                 1285 	mov	a,r4
   03DC 35 2E              1286 	addc	a,(_HWmark + 1)
   03DE F5 83              1287 	mov	dph,a
   03E0 E4                 1288 	clr	a
   03E1 F0                 1289 	movx	@dptr,a
   03E2 0B                 1290 	inc	r3
   03E3 BB 00 E5           1291 	cjne	r3,#0x00,00101$
   03E6 0C                 1292 	inc	r4
   03E7 80 E2              1293 	sjmp	00101$
   03E9                    1294 00104$:
                           1295 ;	eeprom_mark.c:262: mark->serial_no_high,mark->serial_no_low);
   03E9 74 0E              1296 	mov	a,#0x0E
   03EB 25 2F              1297 	add	a,_writemarkeeprom_mark_1_1
   03ED FA                 1298 	mov	r2,a
   03EE E4                 1299 	clr	a
   03EF 35 30              1300 	addc	a,(_writemarkeeprom_mark_1_1 + 1)
   03F1 FB                 1301 	mov	r3,a
   03F2 AC 31              1302 	mov	r4,(_writemarkeeprom_mark_1_1 + 2)
   03F4 8A 82              1303 	mov	dpl,r2
   03F6 8B 83              1304 	mov	dph,r3
   03F8 8C F0              1305 	mov	b,r4
   03FA 12 0F 1B           1306 	lcall	__gptrget
   03FD FA                 1307 	mov	r2,a
   03FE A3                 1308 	inc	dptr
   03FF 12 0F 1B           1309 	lcall	__gptrget
   0402 FB                 1310 	mov	r3,a
   0403 74 0C              1311 	mov	a,#0x0C
   0405 25 2F              1312 	add	a,_writemarkeeprom_mark_1_1
   0407 F8                 1313 	mov	r0,a
   0408 E4                 1314 	clr	a
   0409 35 30              1315 	addc	a,(_writemarkeeprom_mark_1_1 + 1)
   040B F9                 1316 	mov	r1,a
   040C AC 31              1317 	mov	r4,(_writemarkeeprom_mark_1_1 + 2)
   040E 88 82              1318 	mov	dpl,r0
   0410 89 83              1319 	mov	dph,r1
   0412 8C F0              1320 	mov	b,r4
   0414 12 0F 1B           1321 	lcall	__gptrget
   0417 F8                 1322 	mov	r0,a
   0418 A3                 1323 	inc	dptr
   0419 12 0F 1B           1324 	lcall	__gptrget
   041C F9                 1325 	mov	r1,a
                           1326 ;	eeprom_mark.c:261: mark->type,mark->major_version, mark->minor_version,
   041D 74 0A              1327 	mov	a,#0x0A
   041F 25 2F              1328 	add	a,_writemarkeeprom_mark_1_1
   0421 FC                 1329 	mov	r4,a
   0422 E4                 1330 	clr	a
   0423 35 30              1331 	addc	a,(_writemarkeeprom_mark_1_1 + 1)
   0425 FE                 1332 	mov	r6,a
   0426 AF 31              1333 	mov	r7,(_writemarkeeprom_mark_1_1 + 2)
   0428 8C 82              1334 	mov	dpl,r4
   042A 8E 83              1335 	mov	dph,r6
   042C 8F F0              1336 	mov	b,r7
   042E 12 0F 1B           1337 	lcall	__gptrget
   0431 F5 32              1338 	mov	_writemarkeeprom_sloc0_1_0,a
   0433 A3                 1339 	inc	dptr
   0434 12 0F 1B           1340 	lcall	__gptrget
   0437 F5 33              1341 	mov	(_writemarkeeprom_sloc0_1_0 + 1),a
   0439 74 08              1342 	mov	a,#0x08
   043B 25 2F              1343 	add	a,_writemarkeeprom_mark_1_1
   043D FD                 1344 	mov	r5,a
   043E E4                 1345 	clr	a
   043F 35 30              1346 	addc	a,(_writemarkeeprom_mark_1_1 + 1)
   0441 FE                 1347 	mov	r6,a
   0442 AF 31              1348 	mov	r7,(_writemarkeeprom_mark_1_1 + 2)
   0444 8D 82              1349 	mov	dpl,r5
   0446 8E 83              1350 	mov	dph,r6
   0448 8F F0              1351 	mov	b,r7
   044A 12 0F 1B           1352 	lcall	__gptrget
   044D F5 34              1353 	mov	_writemarkeeprom_sloc1_1_0,a
   044F A3                 1354 	inc	dptr
   0450 12 0F 1B           1355 	lcall	__gptrget
   0453 F5 35              1356 	mov	(_writemarkeeprom_sloc1_1_0 + 1),a
                           1357 ;	eeprom_mark.c:260: sprintf(HWmark,"HW%sv%03x.%03xs%04x.%04x",
   0455 AC 2D              1358 	mov	r4,_HWmark
   0457 AE 2E              1359 	mov	r6,(_HWmark + 1)
   0459 7F 00              1360 	mov	r7,#0x00
   045B C0 02              1361 	push	ar2
   045D C0 03              1362 	push	ar3
   045F C0 00              1363 	push	ar0
   0461 C0 01              1364 	push	ar1
   0463 C0 32              1365 	push	_writemarkeeprom_sloc0_1_0
   0465 C0 33              1366 	push	(_writemarkeeprom_sloc0_1_0 + 1)
   0467 C0 34              1367 	push	_writemarkeeprom_sloc1_1_0
   0469 C0 35              1368 	push	(_writemarkeeprom_sloc1_1_0 + 1)
   046B C0 2F              1369 	push	_writemarkeeprom_mark_1_1
   046D C0 30              1370 	push	(_writemarkeeprom_mark_1_1 + 1)
   046F C0 31              1371 	push	(_writemarkeeprom_mark_1_1 + 2)
   0471 74 3B              1372 	mov	a,#__str_0
   0473 C0 E0              1373 	push	acc
   0475 74 0F              1374 	mov	a,#(__str_0 >> 8)
   0477 C0 E0              1375 	push	acc
   0479 74 80              1376 	mov	a,#0x80
   047B C0 E0              1377 	push	acc
   047D C0 04              1378 	push	ar4
   047F C0 06              1379 	push	ar6
   0481 C0 07              1380 	push	ar7
   0483 12 08 F3           1381 	lcall	_sprintf
   0486 E5 81              1382 	mov	a,sp
   0488 24 EF              1383 	add	a,#0xef
   048A F5 81              1384 	mov	sp,a
                           1385 ;	eeprom_mark.c:263: for(n=0;n<32;n++) err[n+2] = EEWrite(0x0400+n,0x00);
   048C 7E 00              1386 	mov	r6,#0x00
   048E 7F 00              1387 	mov	r7,#0x00
   0490                    1388 00105$:
   0490 C3                 1389 	clr	c
   0491 EE                 1390 	mov	a,r6
   0492 94 20              1391 	subb	a,#0x20
   0494 EF                 1392 	mov	a,r7
   0495 64 80              1393 	xrl	a,#0x80
   0497 94 80              1394 	subb	a,#0x80
   0499 50 3E              1395 	jnc	00108$
   049B 74 02              1396 	mov	a,#0x02
   049D 2E                 1397 	add	a,r6
   049E FC                 1398 	mov	r4,a
   049F E4                 1399 	clr	a
   04A0 3F                 1400 	addc	a,r7
   04A1 FD                 1401 	mov	r5,a
   04A2 EC                 1402 	mov	a,r4
   04A3 25 25              1403 	add	a,_err
   04A5 FC                 1404 	mov	r4,a
   04A6 ED                 1405 	mov	a,r5
   04A7 35 26              1406 	addc	a,(_err + 1)
   04A9 FD                 1407 	mov	r5,a
   04AA 8E 02              1408 	mov	ar2,r6
   04AC 74 04              1409 	mov	a,#0x04
   04AE 2F                 1410 	add	a,r7
   04AF FB                 1411 	mov	r3,a
   04B0 8A 82              1412 	mov	dpl,r2
   04B2 8B 83              1413 	mov	dph,r3
   04B4 75 10 00           1414 	mov	_EEWrite_PARM_2,#0x00
   04B7 C0 07              1415 	push	ar7
   04B9 C0 06              1416 	push	ar6
   04BB C0 05              1417 	push	ar5
   04BD C0 04              1418 	push	ar4
   04BF 12 01 20           1419 	lcall	_EEWrite
   04C2 AB 82              1420 	mov	r3,dpl
   04C4 D0 04              1421 	pop	ar4
   04C6 D0 05              1422 	pop	ar5
   04C8 D0 06              1423 	pop	ar6
   04CA D0 07              1424 	pop	ar7
   04CC 8C 82              1425 	mov	dpl,r4
   04CE 8D 83              1426 	mov	dph,r5
   04D0 EB                 1427 	mov	a,r3
   04D1 F0                 1428 	movx	@dptr,a
   04D2 0E                 1429 	inc	r6
   04D3 BE 00 BA           1430 	cjne	r6,#0x00,00105$
   04D6 0F                 1431 	inc	r7
   04D7 80 B7              1432 	sjmp	00105$
   04D9                    1433 00108$:
                           1434 ;	eeprom_mark.c:264: for(n=0;n<32;n++) err[n+2] = EEWrite(0x0400+n,HWmark[n]);
   04D9 7E 00              1435 	mov	r6,#0x00
   04DB 7F 00              1436 	mov	r7,#0x00
   04DD                    1437 00109$:
   04DD C3                 1438 	clr	c
   04DE EE                 1439 	mov	a,r6
   04DF 94 20              1440 	subb	a,#0x20
   04E1 EF                 1441 	mov	a,r7
   04E2 64 80              1442 	xrl	a,#0x80
   04E4 94 80              1443 	subb	a,#0x80
   04E6 50 48              1444 	jnc	00112$
   04E8 74 02              1445 	mov	a,#0x02
   04EA 2E                 1446 	add	a,r6
   04EB FC                 1447 	mov	r4,a
   04EC E4                 1448 	clr	a
   04ED 3F                 1449 	addc	a,r7
   04EE FD                 1450 	mov	r5,a
   04EF EC                 1451 	mov	a,r4
   04F0 25 25              1452 	add	a,_err
   04F2 FC                 1453 	mov	r4,a
   04F3 ED                 1454 	mov	a,r5
   04F4 35 26              1455 	addc	a,(_err + 1)
   04F6 FD                 1456 	mov	r5,a
   04F7 8E 02              1457 	mov	ar2,r6
   04F9 74 04              1458 	mov	a,#0x04
   04FB 2F                 1459 	add	a,r7
   04FC FB                 1460 	mov	r3,a
   04FD EE                 1461 	mov	a,r6
   04FE 25 2D              1462 	add	a,_HWmark
   0500 F5 82              1463 	mov	dpl,a
   0502 EF                 1464 	mov	a,r7
   0503 35 2E              1465 	addc	a,(_HWmark + 1)
   0505 F5 83              1466 	mov	dph,a
   0507 E0                 1467 	movx	a,@dptr
   0508 F5 10              1468 	mov	_EEWrite_PARM_2,a
   050A 8A 82              1469 	mov	dpl,r2
   050C 8B 83              1470 	mov	dph,r3
   050E C0 07              1471 	push	ar7
   0510 C0 06              1472 	push	ar6
   0512 C0 05              1473 	push	ar5
   0514 C0 04              1474 	push	ar4
   0516 12 01 20           1475 	lcall	_EEWrite
   0519 AB 82              1476 	mov	r3,dpl
   051B D0 04              1477 	pop	ar4
   051D D0 05              1478 	pop	ar5
   051F D0 06              1479 	pop	ar6
   0521 D0 07              1480 	pop	ar7
   0523 8C 82              1481 	mov	dpl,r4
   0525 8D 83              1482 	mov	dph,r5
   0527 EB                 1483 	mov	a,r3
   0528 F0                 1484 	movx	@dptr,a
   0529 0E                 1485 	inc	r6
   052A BE 00 B0           1486 	cjne	r6,#0x00,00109$
   052D 0F                 1487 	inc	r7
   052E 80 AD              1488 	sjmp	00109$
   0530                    1489 00112$:
                           1490 ;	eeprom_mark.c:266: return(0);
   0530 75 82 00           1491 	mov	dpl,#0x00
   0533 22                 1492 	ret
                           1493 ;------------------------------------------------------------
                           1494 ;Allocation info for local variables in function 'main'
                           1495 ;------------------------------------------------------------
                           1496 ;n                         Allocated to registers r6 r7 
                           1497 ;eeprom_mark_adr           Allocated to registers 
                           1498 ;adr                       Allocated to registers 
                           1499 ;mark                      Allocated with name '_main_mark_1_1'
                           1500 ;------------------------------------------------------------
                           1501 ;	eeprom_mark.c:269: void main(void)
                           1502 ;	-----------------------------------------
                           1503 ;	 function main
                           1504 ;	-----------------------------------------
   0534                    1505 _main:
                           1506 ;	eeprom_mark.c:276: err = (xdata unsigned char *) 0x1200;	
   0534 75 25 00           1507 	mov	_err,#0x00
   0537 75 26 12           1508 	mov	(_err + 1),#0x12
                           1509 ;	eeprom_mark.c:287: strcpy(mark.type,"TEST");
   053A 75 10 54           1510 	mov	_strcpy_PARM_2,#__str_1
   053D 75 11 0F           1511 	mov	(_strcpy_PARM_2 + 1),#(__str_1 >> 8)
   0540 75 12 80           1512 	mov	(_strcpy_PARM_2 + 2),#0x80
   0543 90 00 36           1513 	mov	dptr,#_main_mark_1_1
   0546 75 F0 40           1514 	mov	b,#0x40
   0549 12 07 6E           1515 	lcall	_strcpy
                           1516 ;	eeprom_mark.c:288: strcpy(mark.type,"ADC_");
   054C 75 10 59           1517 	mov	_strcpy_PARM_2,#__str_2
   054F 75 11 0F           1518 	mov	(_strcpy_PARM_2 + 1),#(__str_2 >> 8)
   0552 75 12 80           1519 	mov	(_strcpy_PARM_2 + 2),#0x80
   0555 90 00 36           1520 	mov	dptr,#_main_mark_1_1
   0558 75 F0 40           1521 	mov	b,#0x40
   055B 12 07 6E           1522 	lcall	_strcpy
                           1523 ;	eeprom_mark.c:290: mark.major_version = 0x0;
   055E E4                 1524 	clr	a
   055F F5 3E              1525 	mov	((_main_mark_1_1 + 0x0008) + 0),a
   0561 F5 3F              1526 	mov	((_main_mark_1_1 + 0x0008) + 1),a
                           1527 ;	eeprom_mark.c:291: mark.minor_version = 0x1;
   0563 75 40 01           1528 	mov	((_main_mark_1_1 + 0x000a) + 0),#0x01
                           1529 ;	eeprom_mark.c:293: mark.serial_no_high = 0x0;
   0566 E4                 1530 	clr	a
   0567 F5 41              1531 	mov	((_main_mark_1_1 + 0x000a) + 1),a
   0569 F5 42              1532 	mov	((_main_mark_1_1 + 0x000c) + 0),a
   056B F5 43              1533 	mov	((_main_mark_1_1 + 0x000c) + 1),a
                           1534 ;	eeprom_mark.c:294: mark.serial_no_low  = 0x1;
   056D 75 44 01           1535 	mov	((_main_mark_1_1 + 0x000e) + 0),#0x01
   0570 75 45 00           1536 	mov	((_main_mark_1_1 + 0x000e) + 1),#0x00
                           1537 ;	eeprom_mark.c:298: for(n = 0;n < 200;n++);
   0573 7E C8              1538 	mov	r6,#0xC8
   0575 7F 00              1539 	mov	r7,#0x00
   0577                    1540 00103$:
   0577 1E                 1541 	dec	r6
   0578 BE FF 01           1542 	cjne	r6,#0xFF,00120$
   057B 1F                 1543 	dec	r7
   057C                    1544 00120$:
   057C EE                 1545 	mov	a,r6
   057D 4F                 1546 	orl	a,r7
   057E 70 F7              1547 	jnz	00103$
                           1548 ;	eeprom_mark.c:299: readmarkeeprom();
   0580 12 03 62           1549 	lcall	_readmarkeeprom
                           1550 ;	eeprom_mark.c:300: for(n=0;n<32;n++) dat[n] = (xdata char)HWmark[n];
   0583 7E 00              1551 	mov	r6,#0x00
   0585 7F 00              1552 	mov	r7,#0x00
   0587                    1553 00104$:
   0587 C3                 1554 	clr	c
   0588 EE                 1555 	mov	a,r6
   0589 94 20              1556 	subb	a,#0x20
   058B EF                 1557 	mov	a,r7
   058C 64 80              1558 	xrl	a,#0x80
   058E 94 80              1559 	subb	a,#0x80
   0590 50 20              1560 	jnc	00107$
   0592 EE                 1561 	mov	a,r6
   0593 25 27              1562 	add	a,_dat
   0595 FC                 1563 	mov	r4,a
   0596 EF                 1564 	mov	a,r7
   0597 35 28              1565 	addc	a,(_dat + 1)
   0599 FD                 1566 	mov	r5,a
   059A EE                 1567 	mov	a,r6
   059B 25 2D              1568 	add	a,_HWmark
   059D F5 82              1569 	mov	dpl,a
   059F EF                 1570 	mov	a,r7
   05A0 35 2E              1571 	addc	a,(_HWmark + 1)
   05A2 F5 83              1572 	mov	dph,a
   05A4 E0                 1573 	movx	a,@dptr
   05A5 FB                 1574 	mov	r3,a
   05A6 8C 82              1575 	mov	dpl,r4
   05A8 8D 83              1576 	mov	dph,r5
   05AA F0                 1577 	movx	@dptr,a
   05AB 0E                 1578 	inc	r6
   05AC BE 00 D8           1579 	cjne	r6,#0x00,00104$
   05AF 0F                 1580 	inc	r7
   05B0 80 D5              1581 	sjmp	00104$
   05B2                    1582 00107$:
                           1583 ;	eeprom_mark.c:302: hostreadmarkep1init();
   05B2 12 05 BA           1584 	lcall	_hostreadmarkep1init
   05B5                    1585 00109$:
                           1586 ;	eeprom_mark.c:303: for(;;) hostreadmarkep1poll();	
   05B5 12 05 D1           1587 	lcall	_hostreadmarkep1poll
   05B8 80 FB              1588 	sjmp	00109$
                           1589 ;------------------------------------------------------------
                           1590 ;Allocation info for local variables in function 'hostreadmarkep1init'
                           1591 ;------------------------------------------------------------
                           1592 ;	eeprom_mark.c:308: static uint8 hostreadmarkep1init(void) {
                           1593 ;	-----------------------------------------
                           1594 ;	 function hostreadmarkep1init
                           1595 ;	-----------------------------------------
   05BA                    1596 _hostreadmarkep1init:
                           1597 ;	eeprom_mark.c:310: EP1OUTCFG=0xa0;
   05BA 90 E6 10           1598 	mov	dptr,#_EP1OUTCFG
   05BD 74 A0              1599 	mov	a,#0xA0
   05BF F0                 1600 	movx	@dptr,a
                           1601 ;	eeprom_mark.c:311: EP1INCFG=0xa0;
   05C0 90 E6 11           1602 	mov	dptr,#_EP1INCFG
   05C3 74 A0              1603 	mov	a,#0xA0
   05C5 F0                 1604 	movx	@dptr,a
                           1605 ;	eeprom_mark.c:313: SYNCDELAY;
   05C6 00                 1606 	 nop; 
                           1607 ;	eeprom_mark.c:314: EP1OUTBC=0xff; // Arm endpoint 1 for OUT (host->device) transfers
   05C7 90 E6 8D           1608 	mov	dptr,#_EP1OUTBC
   05CA 74 FF              1609 	mov	a,#0xFF
   05CC F0                 1610 	movx	@dptr,a
                           1611 ;	eeprom_mark.c:316: return(0);
   05CD 75 82 00           1612 	mov	dpl,#0x00
   05D0 22                 1613 	ret
                           1614 ;------------------------------------------------------------
                           1615 ;Allocation info for local variables in function 'hostreadmarkep1poll'
                           1616 ;------------------------------------------------------------
                           1617 ;src                       Allocated to registers 
                           1618 ;dest                      Allocated to registers r5 r6 
                           1619 ;ep1outbc                  Allocated with name '_hostreadmarkep1poll_ep1outbc_1_1'
                           1620 ;n                         Allocated with name '_hostreadmarkep1poll_n_1_1'
                           1621 ;------------------------------------------------------------
                           1622 ;	eeprom_mark.c:319: static uint8 hostreadmarkep1poll(void) {
                           1623 ;	-----------------------------------------
                           1624 ;	 function hostreadmarkep1poll
                           1625 ;	-----------------------------------------
   05D1                    1626 _hostreadmarkep1poll:
                           1627 ;	eeprom_mark.c:325: if(!(EP1OUTCS & bmEPBUSY)) {
   05D1 90 E6 A1           1628 	mov	dptr,#_EP1OUTCS
   05D4 E0                 1629 	movx	a,@dptr
   05D5 FF                 1630 	mov	r7,a
   05D6 30 E1 03           1631 	jnb	acc.1,00153$
   05D9 02 07 6A           1632 	ljmp	00114$
   05DC                    1633 00153$:
                           1634 ;	eeprom_mark.c:326: ep1outbc = EP1OUTBC;
   05DC 90 E6 8D           1635 	mov	dptr,#_EP1OUTBC
   05DF E0                 1636 	movx	a,@dptr
   05E0 F5 46              1637 	mov	_hostreadmarkep1poll_ep1outbc_1_1,a
                           1638 ;	eeprom_mark.c:327: if(ep1outbc != 0xff ) {
   05E2 74 FF              1639 	mov	a,#0xFF
   05E4 B5 46 03           1640 	cjne	a,_hostreadmarkep1poll_ep1outbc_1_1,00154$
   05E7 02 07 6A           1641 	ljmp	00114$
   05EA                    1642 00154$:
                           1643 ;	eeprom_mark.c:328: src = EP1OUTBUF;
                           1644 ;	eeprom_mark.c:329: dest = EP1INBUF;
   05EA 7D C0              1645 	mov	r5,#_EP1INBUF
   05EC 7E E7              1646 	mov	r6,#(_EP1INBUF >> 8)
                           1647 ;	eeprom_mark.c:330: while (EP1INCS & 0x02);
   05EE                    1648 00101$:
   05EE 90 E6 A2           1649 	mov	dptr,#_EP1INCS
   05F1 E0                 1650 	movx	a,@dptr
   05F2 FC                 1651 	mov	r4,a
   05F3 20 E1 F8           1652 	jb	acc.1,00101$
                           1653 ;	eeprom_mark.c:331: for(n=0; n<32; n++) command[n] = src[n];
   05F6 7B 00              1654 	mov	r3,#0x00
   05F8 7C 00              1655 	mov	r4,#0x00
   05FA                    1656 00115$:
   05FA C3                 1657 	clr	c
   05FB EB                 1658 	mov	a,r3
   05FC 94 20              1659 	subb	a,#0x20
   05FE EC                 1660 	mov	a,r4
   05FF 64 80              1661 	xrl	a,#0x80
   0601 94 80              1662 	subb	a,#0x80
   0603 50 20              1663 	jnc	00118$
   0605 EB                 1664 	mov	a,r3
   0606 25 2B              1665 	add	a,_command
   0608 F9                 1666 	mov	r1,a
   0609 EC                 1667 	mov	a,r4
   060A 35 2C              1668 	addc	a,(_command + 1)
   060C FA                 1669 	mov	r2,a
   060D EB                 1670 	mov	a,r3
   060E 24 80              1671 	add	a,#_EP1OUTBUF
   0610 F5 82              1672 	mov	dpl,a
   0612 EC                 1673 	mov	a,r4
   0613 34 E7              1674 	addc	a,#(_EP1OUTBUF >> 8)
   0615 F5 83              1675 	mov	dph,a
   0617 E0                 1676 	movx	a,@dptr
   0618 F8                 1677 	mov	r0,a
   0619 89 82              1678 	mov	dpl,r1
   061B 8A 83              1679 	mov	dph,r2
   061D F0                 1680 	movx	@dptr,a
   061E 0B                 1681 	inc	r3
   061F BB 00 D8           1682 	cjne	r3,#0x00,00115$
   0622 0C                 1683 	inc	r4
   0623 80 D5              1684 	sjmp	00115$
   0625                    1685 00118$:
                           1686 ;	eeprom_mark.c:332: for( n=0; n < ep1outbc ; n++ ) { 
   0625 8D 03              1687 	mov	ar3,r5
   0627 8E 04              1688 	mov	ar4,r6
   0629 79 00              1689 	mov	r1,#0x00
   062B 7A 00              1690 	mov	r2,#0x00
   062D                    1691 00119$:
   062D A8 46              1692 	mov	r0,_hostreadmarkep1poll_ep1outbc_1_1
   062F 7F 00              1693 	mov	r7,#0x00
   0631 C3                 1694 	clr	c
   0632 E9                 1695 	mov	a,r1
   0633 98                 1696 	subb	a,r0
   0634 EA                 1697 	mov	a,r2
   0635 64 80              1698 	xrl	a,#0x80
   0637 8F F0              1699 	mov	b,r7
   0639 63 F0 80           1700 	xrl	b,#0x80
   063C 95 F0              1701 	subb	a,b
   063E 50 1D              1702 	jnc	00122$
                           1703 ;	eeprom_mark.c:333: *dest++ = command[n];
   0640 E9                 1704 	mov	a,r1
   0641 25 2B              1705 	add	a,_command
   0643 F5 82              1706 	mov	dpl,a
   0645 EA                 1707 	mov	a,r2
   0646 35 2C              1708 	addc	a,(_command + 1)
   0648 F5 83              1709 	mov	dph,a
   064A E0                 1710 	movx	a,@dptr
   064B FF                 1711 	mov	r7,a
   064C 8B 82              1712 	mov	dpl,r3
   064E 8C 83              1713 	mov	dph,r4
   0650 F0                 1714 	movx	@dptr,a
   0651 A3                 1715 	inc	dptr
   0652 AB 82              1716 	mov	r3,dpl
   0654 AC 83              1717 	mov	r4,dph
                           1718 ;	eeprom_mark.c:332: for( n=0; n < ep1outbc ; n++ ) { 
   0656 09                 1719 	inc	r1
   0657 B9 00 D3           1720 	cjne	r1,#0x00,00119$
   065A 0A                 1721 	inc	r2
   065B 80 D0              1722 	sjmp	00119$
   065D                    1723 00122$:
                           1724 ;	eeprom_mark.c:335: *err++ = 0x5a;
   065D 85 25 82           1725 	mov	dpl,_err
   0660 85 26 83           1726 	mov	dph,(_err + 1)
   0663 74 5A              1727 	mov	a,#0x5A
   0665 F0                 1728 	movx	@dptr,a
   0666 05 25              1729 	inc	_err
   0668 E4                 1730 	clr	a
   0669 B5 25 02           1731 	cjne	a,_err,00160$
   066C 05 26              1732 	inc	(_err + 1)
   066E                    1733 00160$:
                           1734 ;	eeprom_mark.c:336: EP1INBC = ep1outbc;
   066E 90 E6 8F           1735 	mov	dptr,#_EP1INBC
   0671 E5 46              1736 	mov	a,_hostreadmarkep1poll_ep1outbc_1_1
   0673 F0                 1737 	movx	@dptr,a
                           1738 ;	eeprom_mark.c:337: while (EP1INCS & 0x02);
   0674                    1739 00104$:
   0674 90 E6 A2           1740 	mov	dptr,#_EP1INCS
   0677 E0                 1741 	movx	a,@dptr
   0678 FF                 1742 	mov	r7,a
   0679 20 E1 F8           1743 	jb	acc.1,00104$
                           1744 ;	eeprom_mark.c:338: dest = EP1INBUF;
   067C 7D C0              1745 	mov	r5,#_EP1INBUF
   067E 7E E7              1746 	mov	r6,#(_EP1INBUF >> 8)
                           1747 ;	eeprom_mark.c:339: if(!strncmp(command,"getHW",5)) {
   0680 AB 2B              1748 	mov	r3,_command
   0682 AC 2C              1749 	mov	r4,(_command + 1)
   0684 7F 00              1750 	mov	r7,#0x00
   0686 75 10 5E           1751 	mov	_strncmp_PARM_2,#__str_3
   0689 75 11 0F           1752 	mov	(_strncmp_PARM_2 + 1),#(__str_3 >> 8)
   068C 75 12 80           1753 	mov	(_strncmp_PARM_2 + 2),#0x80
   068F 75 13 05           1754 	mov	_strncmp_PARM_3,#0x05
   0692 75 14 00           1755 	mov	(_strncmp_PARM_3 + 1),#0x00
   0695 8B 82              1756 	mov	dpl,r3
   0697 8C 83              1757 	mov	dph,r4
   0699 8F F0              1758 	mov	b,r7
   069B C0 06              1759 	push	ar6
   069D C0 05              1760 	push	ar5
   069F 12 07 AE           1761 	lcall	_strncmp
   06A2 E5 82              1762 	mov	a,dpl
   06A4 85 83 F0           1763 	mov	b,dph
   06A7 D0 05              1764 	pop	ar5
   06A9 D0 06              1765 	pop	ar6
   06AB 45 F0              1766 	orl	a,b
                           1767 ;	eeprom_mark.c:340: for( n=0; HWmark[n] != '\0' ; n++ )  
   06AD 70 40              1768 	jnz	00108$
   06AF 8D 04              1769 	mov	ar4,r5
   06B1 8E 07              1770 	mov	ar7,r6
   06B3 FA                 1771 	mov	r2,a
   06B4 FB                 1772 	mov	r3,a
   06B5                    1773 00123$:
   06B5 EA                 1774 	mov	a,r2
   06B6 25 2D              1775 	add	a,_HWmark
   06B8 F5 82              1776 	mov	dpl,a
   06BA EB                 1777 	mov	a,r3
   06BB 35 2E              1778 	addc	a,(_HWmark + 1)
   06BD F5 83              1779 	mov	dph,a
   06BF E0                 1780 	movx	a,@dptr
   06C0 F9                 1781 	mov	r1,a
   06C1 60 12              1782 	jz	00126$
                           1783 ;	eeprom_mark.c:341: *dest++ = (xdata unsigned char) HWmark[n];					
   06C3 8C 82              1784 	mov	dpl,r4
   06C5 8F 83              1785 	mov	dph,r7
   06C7 E9                 1786 	mov	a,r1
   06C8 F0                 1787 	movx	@dptr,a
   06C9 A3                 1788 	inc	dptr
   06CA AC 82              1789 	mov	r4,dpl
   06CC AF 83              1790 	mov	r7,dph
                           1791 ;	eeprom_mark.c:340: for( n=0; HWmark[n] != '\0' ; n++ )  
   06CE 0A                 1792 	inc	r2
   06CF BA 00 E3           1793 	cjne	r2,#0x00,00123$
   06D2 0B                 1794 	inc	r3
   06D3 80 E0              1795 	sjmp	00123$
   06D5                    1796 00126$:
                           1797 ;	eeprom_mark.c:342: *dest++ = '\0';
   06D5 8C 82              1798 	mov	dpl,r4
   06D7 8F 83              1799 	mov	dph,r7
   06D9 E4                 1800 	clr	a
   06DA F0                 1801 	movx	@dptr,a
   06DB 74 01              1802 	mov	a,#0x01
   06DD 2C                 1803 	add	a,r4
   06DE FD                 1804 	mov	r5,a
   06DF E4                 1805 	clr	a
   06E0 3F                 1806 	addc	a,r7
   06E1 FE                 1807 	mov	r6,a
                           1808 ;	eeprom_mark.c:343: n++;
   06E2 74 01              1809 	mov	a,#0x01
   06E4 2A                 1810 	add	a,r2
   06E5 FC                 1811 	mov	r4,a
   06E6 E4                 1812 	clr	a
   06E7 3B                 1813 	addc	a,r3
   06E8 FF                 1814 	mov	r7,a
                           1815 ;	eeprom_mark.c:344: EP1INBC = n;
   06E9 90 E6 8F           1816 	mov	dptr,#_EP1INBC
   06EC EC                 1817 	mov	a,r4
   06ED F0                 1818 	movx	@dptr,a
                           1819 ;	eeprom_mark.c:345: SYNCDELAY;
   06EE 00                 1820 	 nop; 
   06EF                    1821 00108$:
                           1822 ;	eeprom_mark.c:347: if(!strncmp(command,"getFW",5)) {
   06EF A9 2B              1823 	mov	r1,_command
   06F1 AA 2C              1824 	mov	r2,(_command + 1)
   06F3 7B 00              1825 	mov	r3,#0x00
   06F5 75 10 64           1826 	mov	_strncmp_PARM_2,#__str_4
   06F8 75 11 0F           1827 	mov	(_strncmp_PARM_2 + 1),#(__str_4 >> 8)
   06FB 75 12 80           1828 	mov	(_strncmp_PARM_2 + 2),#0x80
   06FE 75 13 05           1829 	mov	_strncmp_PARM_3,#0x05
   0701 75 14 00           1830 	mov	(_strncmp_PARM_3 + 1),#0x00
   0704 89 82              1831 	mov	dpl,r1
   0706 8A 83              1832 	mov	dph,r2
   0708 8B F0              1833 	mov	b,r3
   070A C0 06              1834 	push	ar6
   070C C0 05              1835 	push	ar5
   070E 12 07 AE           1836 	lcall	_strncmp
   0711 E5 82              1837 	mov	a,dpl
   0713 85 83 F0           1838 	mov	b,dph
   0716 D0 05              1839 	pop	ar5
   0718 D0 06              1840 	pop	ar6
   071A 45 F0              1841 	orl	a,b
                           1842 ;	eeprom_mark.c:348: for( n=0; FWmark[n] != '\0' ; n++ )  
   071C 70 46              1843 	jnz	00110$
   071E F5 47              1844 	mov	_hostreadmarkep1poll_n_1_1,a
   0720 F5 48              1845 	mov	(_hostreadmarkep1poll_n_1_1 + 1),a
   0722                    1846 00127$:
   0722 E5 47              1847 	mov	a,_hostreadmarkep1poll_n_1_1
   0724 25 22              1848 	add	a,_FWmark
   0726 F8                 1849 	mov	r0,a
   0727 E5 48              1850 	mov	a,(_hostreadmarkep1poll_n_1_1 + 1)
   0729 35 23              1851 	addc	a,(_FWmark + 1)
   072B F9                 1852 	mov	r1,a
   072C AB 24              1853 	mov	r3,(_FWmark + 2)
   072E 88 82              1854 	mov	dpl,r0
   0730 89 83              1855 	mov	dph,r1
   0732 8B F0              1856 	mov	b,r3
   0734 12 0F 1B           1857 	lcall	__gptrget
   0737 FB                 1858 	mov	r3,a
   0738 60 15              1859 	jz	00130$
                           1860 ;	eeprom_mark.c:349: *dest++ = (xdata unsigned char) FWmark[n];					
   073A 8D 82              1861 	mov	dpl,r5
   073C 8E 83              1862 	mov	dph,r6
   073E EB                 1863 	mov	a,r3
   073F F0                 1864 	movx	@dptr,a
   0740 A3                 1865 	inc	dptr
   0741 AD 82              1866 	mov	r5,dpl
   0743 AE 83              1867 	mov	r6,dph
                           1868 ;	eeprom_mark.c:348: for( n=0; FWmark[n] != '\0' ; n++ )  
   0745 05 47              1869 	inc	_hostreadmarkep1poll_n_1_1
   0747 E4                 1870 	clr	a
   0748 B5 47 D7           1871 	cjne	a,_hostreadmarkep1poll_n_1_1,00127$
   074B 05 48              1872 	inc	(_hostreadmarkep1poll_n_1_1 + 1)
   074D 80 D3              1873 	sjmp	00127$
   074F                    1874 00130$:
                           1875 ;	eeprom_mark.c:350: *dest++ = '\0';
   074F 8D 82              1876 	mov	dpl,r5
   0751 8E 83              1877 	mov	dph,r6
   0753 E4                 1878 	clr	a
   0754 F0                 1879 	movx	@dptr,a
                           1880 ;	eeprom_mark.c:351: n++;
   0755 74 01              1881 	mov	a,#0x01
   0757 25 47              1882 	add	a,_hostreadmarkep1poll_n_1_1
   0759 FC                 1883 	mov	r4,a
   075A E4                 1884 	clr	a
   075B 35 48              1885 	addc	a,(_hostreadmarkep1poll_n_1_1 + 1)
   075D FF                 1886 	mov	r7,a
                           1887 ;	eeprom_mark.c:352: EP1INBC = n;
   075E 90 E6 8F           1888 	mov	dptr,#_EP1INBC
   0761 EC                 1889 	mov	a,r4
   0762 F0                 1890 	movx	@dptr,a
                           1891 ;	eeprom_mark.c:353: SYNCDELAY;
   0763 00                 1892 	 nop; 
   0764                    1893 00110$:
                           1894 ;	eeprom_mark.c:355: EP1OUTBC = 0xff;
   0764 90 E6 8D           1895 	mov	dptr,#_EP1OUTBC
   0767 74 FF              1896 	mov	a,#0xFF
   0769 F0                 1897 	movx	@dptr,a
   076A                    1898 00114$:
                           1899 ;	eeprom_mark.c:358: return(0);
   076A 75 82 00           1900 	mov	dpl,#0x00
   076D 22                 1901 	ret
                           1902 	.area CSEG    (CODE)
                           1903 	.area CONST   (CODE)
   0F3B                    1904 __str_0:
   0F3B 48 57 25 73 76 25  1905 	.ascii "HW%sv%03x.%03xs%04x.%04x"
        30 33 78 2E 25 30
        33 78 73 25 30 34
        78 2E 25 30 34 78
   0F53 00                 1906 	.db 0x00
   0F54                    1907 __str_1:
   0F54 54 45 53 54        1908 	.ascii "TEST"
   0F58 00                 1909 	.db 0x00
   0F59                    1910 __str_2:
   0F59 41 44 43 5F        1911 	.ascii "ADC_"
   0F5D 00                 1912 	.db 0x00
   0F5E                    1913 __str_3:
   0F5E 67 65 74 48 57     1914 	.ascii "getHW"
   0F63 00                 1915 	.db 0x00
   0F64                    1916 __str_4:
   0F64 67 65 74 46 57     1917 	.ascii "getFW"
   0F69 00                 1918 	.db 0x00
   0F6A                    1919 __str_5:
   0F6A 46 57 45 45 50 52  1920 	.ascii "FWEEPRv000.001"
        76 30 30 30 2E 30
        30 31
   0F78 00                 1921 	.db 0x00
                           1922 	.area XINIT   (CODE)
                           1923 	.area CABS    (ABS,CODE)
