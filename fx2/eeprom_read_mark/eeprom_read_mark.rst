                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Sun Apr 26 11:08:00 2015
                              5 ;--------------------------------------------------------
                              6 	.module eeprom_read_mark
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _strncmp
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
                             75 	.globl _EP8FIFOBUF
                             76 	.globl _EP6FIFOBUF
                             77 	.globl _EP4FIFOBUF
                             78 	.globl _EP2FIFOBUF
                             79 	.globl _EP1INBUF
                             80 	.globl _EP1OUTBUF
                             81 	.globl _EP0BUF
                             82 	.globl _CT4
                             83 	.globl _CT3
                             84 	.globl _CT2
                             85 	.globl _CT1
                             86 	.globl _USBTEST
                             87 	.globl _TESTCFG
                             88 	.globl _DBUG
                             89 	.globl _UDMACRCQUAL
                             90 	.globl _UDMACRCL
                             91 	.globl _UDMACRCH
                             92 	.globl _GPIFHOLDAMOUNT
                             93 	.globl _FLOWSTBHPERIOD
                             94 	.globl _FLOWSTBEDGE
                             95 	.globl _FLOWSTB
                             96 	.globl _FLOWHOLDOFF
                             97 	.globl _FLOWEQ1CTL
                             98 	.globl _FLOWEQ0CTL
                             99 	.globl _FLOWLOGIC
                            100 	.globl _FLOWSTATE
                            101 	.globl _GPIFABORT
                            102 	.globl _GPIFREADYSTAT
                            103 	.globl _GPIFREADYCFG
                            104 	.globl _XGPIFSGLDATLNOX
                            105 	.globl _XGPIFSGLDATLX
                            106 	.globl _XGPIFSGLDATH
                            107 	.globl _EP8GPIFTRIG
                            108 	.globl _EP8GPIFPFSTOP
                            109 	.globl _EP8GPIFFLGSEL
                            110 	.globl _EP6GPIFTRIG
                            111 	.globl _EP6GPIFPFSTOP
                            112 	.globl _EP6GPIFFLGSEL
                            113 	.globl _EP4GPIFTRIG
                            114 	.globl _EP4GPIFPFSTOP
                            115 	.globl _EP4GPIFFLGSEL
                            116 	.globl _EP2GPIFTRIG
                            117 	.globl _EP2GPIFPFSTOP
                            118 	.globl _EP2GPIFFLGSEL
                            119 	.globl _GPIFTCB0
                            120 	.globl _GPIFTCB1
                            121 	.globl _GPIFTCB2
                            122 	.globl _GPIFTCB3
                            123 	.globl _GPIFADRL
                            124 	.globl _GPIFADRH
                            125 	.globl _GPIFCTLCFG
                            126 	.globl _GPIFIDLECTL
                            127 	.globl _GPIFIDLECS
                            128 	.globl _GPIFWFSELECT
                            129 	.globl _SETUPDAT
                            130 	.globl _SUDPTRCTL
                            131 	.globl _SUDPTRL
                            132 	.globl _SUDPTRH
                            133 	.globl _EP8FIFOBCL
                            134 	.globl _EP8FIFOBCH
                            135 	.globl _EP6FIFOBCL
                            136 	.globl _EP6FIFOBCH
                            137 	.globl _EP4FIFOBCL
                            138 	.globl _EP4FIFOBCH
                            139 	.globl _EP2FIFOBCL
                            140 	.globl _EP2FIFOBCH
                            141 	.globl _EP8FIFOFLGS
                            142 	.globl _EP6FIFOFLGS
                            143 	.globl _EP4FIFOFLGS
                            144 	.globl _EP2FIFOFLGS
                            145 	.globl _EP8CS
                            146 	.globl _EP6CS
                            147 	.globl _EP4CS
                            148 	.globl _EP2CS
                            149 	.globl _EP1INCS
                            150 	.globl _EP1OUTCS
                            151 	.globl _EP0CS
                            152 	.globl _EP8BCL
                            153 	.globl _EP8BCH
                            154 	.globl _EP6BCL
                            155 	.globl _EP6BCH
                            156 	.globl _EP4BCL
                            157 	.globl _EP4BCH
                            158 	.globl _EP2BCL
                            159 	.globl _EP2BCH
                            160 	.globl _EP1INBC
                            161 	.globl _EP1OUTBC
                            162 	.globl _EP0BCL
                            163 	.globl _EP0BCH
                            164 	.globl _FNADDR
                            165 	.globl _MICROFRAME
                            166 	.globl _USBFRAMEL
                            167 	.globl _USBFRAMEH
                            168 	.globl _TOGCTL
                            169 	.globl _WAKEUPCS
                            170 	.globl _SUSPEND
                            171 	.globl _USBCS
                            172 	.globl _XAUTODAT2
                            173 	.globl _XAUTODAT1
                            174 	.globl _I2CTL
                            175 	.globl _I2DAT
                            176 	.globl _I2CS
                            177 	.globl _PORTECFG
                            178 	.globl _PORTCCFG
                            179 	.globl _PORTACFG
                            180 	.globl _INTSETUP
                            181 	.globl _INT4IVEC
                            182 	.globl _INT2IVEC
                            183 	.globl _CLRERRCNT
                            184 	.globl _ERRCNTLIM
                            185 	.globl _USBERRIRQ
                            186 	.globl _USBERRIE
                            187 	.globl _GPIFIRQ
                            188 	.globl _GPIFIE
                            189 	.globl _EPIRQ
                            190 	.globl _EPIE
                            191 	.globl _USBIRQ
                            192 	.globl _USBIE
                            193 	.globl _NAKIRQ
                            194 	.globl _NAKIE
                            195 	.globl _IBNIRQ
                            196 	.globl _IBNIE
                            197 	.globl _EP8FIFOIRQ
                            198 	.globl _EP8FIFOIE
                            199 	.globl _EP6FIFOIRQ
                            200 	.globl _EP6FIFOIE
                            201 	.globl _EP4FIFOIRQ
                            202 	.globl _EP4FIFOIE
                            203 	.globl _EP2FIFOIRQ
                            204 	.globl _EP2FIFOIE
                            205 	.globl _OUTPKTEND
                            206 	.globl _INPKTEND
                            207 	.globl _EP8ISOINPKTS
                            208 	.globl _EP6ISOINPKTS
                            209 	.globl _EP4ISOINPKTS
                            210 	.globl _EP2ISOINPKTS
                            211 	.globl _EP8FIFOPFL
                            212 	.globl _EP8FIFOPFH
                            213 	.globl _EP6FIFOPFL
                            214 	.globl _EP6FIFOPFH
                            215 	.globl _EP4FIFOPFL
                            216 	.globl _EP4FIFOPFH
                            217 	.globl _EP2FIFOPFL
                            218 	.globl _EP2FIFOPFH
                            219 	.globl _EP8AUTOINLENL
                            220 	.globl _EP8AUTOINLENH
                            221 	.globl _EP6AUTOINLENL
                            222 	.globl _EP6AUTOINLENH
                            223 	.globl _EP4AUTOINLENL
                            224 	.globl _EP4AUTOINLENH
                            225 	.globl _EP2AUTOINLENL
                            226 	.globl _EP2AUTOINLENH
                            227 	.globl _EP8FIFOCFG
                            228 	.globl _EP6FIFOCFG
                            229 	.globl _EP4FIFOCFG
                            230 	.globl _EP2FIFOCFG
                            231 	.globl _EP8CFG
                            232 	.globl _EP6CFG
                            233 	.globl _EP4CFG
                            234 	.globl _EP2CFG
                            235 	.globl _EP1INCFG
                            236 	.globl _EP1OUTCFG
                            237 	.globl _REVCTL
                            238 	.globl _REVID
                            239 	.globl _FIFOPINPOLAR
                            240 	.globl _UART230
                            241 	.globl _BPADDRL
                            242 	.globl _BPADDRH
                            243 	.globl _BREAKPT
                            244 	.globl _FIFORESET
                            245 	.globl _PINFLAGSCD
                            246 	.globl _PINFLAGSAB
                            247 	.globl _IFCONFIG
                            248 	.globl _CPUCS
                            249 	.globl _RES_WAVEDATA_END
                            250 	.globl _GPIF_WAVE_DATA
                            251 	.globl _FWmark
                            252 	.globl _HWmark
                            253 	.globl _command
                            254 	.globl _dat
                            255 	.globl _err
                            256 ;--------------------------------------------------------
                            257 ; special function registers
                            258 ;--------------------------------------------------------
                            259 	.area RSEG    (ABS,DATA)
   0000                     260 	.org 0x0000
                    0080    261 _IOA	=	0x0080
                    0081    262 _SP	=	0x0081
                    0082    263 _DPL	=	0x0082
                    0083    264 _DPH	=	0x0083
                    0084    265 _DPL1	=	0x0084
                    0085    266 _DPH1	=	0x0085
                    0086    267 _DPS	=	0x0086
                    0087    268 _PCON	=	0x0087
                    0088    269 _TCON	=	0x0088
                    0089    270 _TMOD	=	0x0089
                    008A    271 _TL0	=	0x008a
                    008B    272 _TL1	=	0x008b
                    008C    273 _TH0	=	0x008c
                    008D    274 _TH1	=	0x008d
                    008E    275 _CKCO	=	0x008e
                    008F    276 _SPC_	=	0x008f
                    0090    277 _IOB	=	0x0090
                    0091    278 _EXIF	=	0x0091
                    0092    279 _MPA	=	0x0092
                    0098    280 _SCO	=	0x0098
                    0099    281 _SBU	=	0x0099
                    009A    282 _APTR1H	=	0x009a
                    009B    283 _APTR1L	=	0x009b
                    009C    284 _AUTODAT1	=	0x009c
                    009D    285 _AUTOPTRH2	=	0x009d
                    009E    286 _AUTOPTRL2	=	0x009e
                    009F    287 _AUTODAT2	=	0x009f
                    00A0    288 _IOC	=	0x00a0
                    00A1    289 _INT2CLR	=	0x00a1
                    00A2    290 _INT4CLR	=	0x00a2
                    00A8    291 _IE	=	0x00a8
                    00AA    292 _EP2468STAT	=	0x00aa
                    00AB    293 _EP24FIFOFLGS	=	0x00ab
                    00AC    294 _EP68FIFOFLGS	=	0x00ac
                    00AF    295 _AUTOPTRSETUP	=	0x00af
                    00B0    296 _IOD	=	0x00b0
                    00B1    297 _IOE	=	0x00b1
                    00B2    298 _OEA	=	0x00b2
                    00B3    299 _OEB	=	0x00b3
                    00B4    300 _OEC	=	0x00b4
                    00B5    301 _OED	=	0x00b5
                    00B6    302 _OEE	=	0x00b6
                    00B8    303 _IP	=	0x00b8
                    00BA    304 _EP01STAT	=	0x00ba
                    00BB    305 _GPIFTRIG	=	0x00bb
                    00BD    306 _GPIFSGLDATH	=	0x00bd
                    00BE    307 _GPIFSGLDATLX	=	0x00be
                    00BF    308 _GPIFSGLDATLNOX	=	0x00bf
                    00C0    309 _SCON1	=	0x00c0
                    00C1    310 _SBUF1	=	0x00c1
                    00C8    311 _T2CON	=	0x00c8
                    00CA    312 _RCAP2L	=	0x00ca
                    00CB    313 _RCAP2H	=	0x00cb
                    00CC    314 _TL2	=	0x00cc
                    00CD    315 _TH2	=	0x00cd
                    00D0    316 _PSW	=	0x00d0
                    00D8    317 _EICON	=	0x00d8
                    00E0    318 _ACC	=	0x00e0
                    00E8    319 _EIE	=	0x00e8
                    00F0    320 _B	=	0x00f0
                    00F8    321 _EIP	=	0x00f8
                            322 ;--------------------------------------------------------
                            323 ; special function bits
                            324 ;--------------------------------------------------------
                            325 	.area RSEG    (ABS,DATA)
   0000                     326 	.org 0x0000
                            327 ;--------------------------------------------------------
                            328 ; overlayable register banks
                            329 ;--------------------------------------------------------
                            330 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     331 	.ds 8
                            332 ;--------------------------------------------------------
                            333 ; internal ram data
                            334 ;--------------------------------------------------------
                            335 	.area DSEG    (DATA)
   0008                     336 _err::
   0008                     337 	.ds 2
   000A                     338 _dat::
   000A                     339 	.ds 2
   000C                     340 _command::
   000C                     341 	.ds 2
   000E                     342 _HWmark::
   000E                     343 	.ds 2
   0010                     344 _hostreadmarkep1poll_ep1outbc_1_1:
   0010                     345 	.ds 1
   0011                     346 _hostreadmarkep1poll_n_1_1:
   0011                     347 	.ds 2
   0013                     348 _FWmark::
   0013                     349 	.ds 3
                            350 ;--------------------------------------------------------
                            351 ; overlayable items in internal ram 
                            352 ;--------------------------------------------------------
                            353 	.area	OSEG    (OVR,DATA)
   0016                     354 _EERead_PARM_2:
   0016                     355 	.ds 3
   0019                     356 _EERead_n_1_1:
   0019                     357 	.ds 2
                            358 ;--------------------------------------------------------
                            359 ; Stack segment in internal ram 
                            360 ;--------------------------------------------------------
                            361 	.area	SSEG	(DATA)
   001C                     362 __start__stack:
   001C                     363 	.ds	1
                            364 
                            365 ;--------------------------------------------------------
                            366 ; indirectly addressable internal ram data
                            367 ;--------------------------------------------------------
                            368 	.area ISEG    (DATA)
                            369 ;--------------------------------------------------------
                            370 ; absolute internal ram data
                            371 ;--------------------------------------------------------
                            372 	.area IABS    (ABS,DATA)
                            373 	.area IABS    (ABS,DATA)
                            374 ;--------------------------------------------------------
                            375 ; bit data
                            376 ;--------------------------------------------------------
                            377 	.area BSEG    (BIT)
                            378 ;--------------------------------------------------------
                            379 ; paged external ram data
                            380 ;--------------------------------------------------------
                            381 	.area PSEG    (PAG,XDATA)
                            382 ;--------------------------------------------------------
                            383 ; external ram data
                            384 ;--------------------------------------------------------
                            385 	.area XSEG    (XDATA)
                    E400    386 _GPIF_WAVE_DATA	=	0xe400
                    E480    387 _RES_WAVEDATA_END	=	0xe480
                    E600    388 _CPUCS	=	0xe600
                    E601    389 _IFCONFIG	=	0xe601
                    E602    390 _PINFLAGSAB	=	0xe602
                    E603    391 _PINFLAGSCD	=	0xe603
                    E604    392 _FIFORESET	=	0xe604
                    E605    393 _BREAKPT	=	0xe605
                    E606    394 _BPADDRH	=	0xe606
                    E607    395 _BPADDRL	=	0xe607
                    E608    396 _UART230	=	0xe608
                    E609    397 _FIFOPINPOLAR	=	0xe609
                    E60A    398 _REVID	=	0xe60a
                    E60B    399 _REVCTL	=	0xe60b
                    E610    400 _EP1OUTCFG	=	0xe610
                    E611    401 _EP1INCFG	=	0xe611
                    E612    402 _EP2CFG	=	0xe612
                    E613    403 _EP4CFG	=	0xe613
                    E614    404 _EP6CFG	=	0xe614
                    E615    405 _EP8CFG	=	0xe615
                    E618    406 _EP2FIFOCFG	=	0xe618
                    E619    407 _EP4FIFOCFG	=	0xe619
                    E61A    408 _EP6FIFOCFG	=	0xe61a
                    E61B    409 _EP8FIFOCFG	=	0xe61b
                    E620    410 _EP2AUTOINLENH	=	0xe620
                    E621    411 _EP2AUTOINLENL	=	0xe621
                    E622    412 _EP4AUTOINLENH	=	0xe622
                    E623    413 _EP4AUTOINLENL	=	0xe623
                    E624    414 _EP6AUTOINLENH	=	0xe624
                    E625    415 _EP6AUTOINLENL	=	0xe625
                    E626    416 _EP8AUTOINLENH	=	0xe626
                    E627    417 _EP8AUTOINLENL	=	0xe627
                    E630    418 _EP2FIFOPFH	=	0xe630
                    E631    419 _EP2FIFOPFL	=	0xe631
                    E632    420 _EP4FIFOPFH	=	0xe632
                    E633    421 _EP4FIFOPFL	=	0xe633
                    E634    422 _EP6FIFOPFH	=	0xe634
                    E635    423 _EP6FIFOPFL	=	0xe635
                    E636    424 _EP8FIFOPFH	=	0xe636
                    E637    425 _EP8FIFOPFL	=	0xe637
                    E640    426 _EP2ISOINPKTS	=	0xe640
                    E641    427 _EP4ISOINPKTS	=	0xe641
                    E642    428 _EP6ISOINPKTS	=	0xe642
                    E643    429 _EP8ISOINPKTS	=	0xe643
                    E648    430 _INPKTEND	=	0xe648
                    E649    431 _OUTPKTEND	=	0xe649
                    E650    432 _EP2FIFOIE	=	0xe650
                    E651    433 _EP2FIFOIRQ	=	0xe651
                    E652    434 _EP4FIFOIE	=	0xe652
                    E653    435 _EP4FIFOIRQ	=	0xe653
                    E654    436 _EP6FIFOIE	=	0xe654
                    E655    437 _EP6FIFOIRQ	=	0xe655
                    E656    438 _EP8FIFOIE	=	0xe656
                    E657    439 _EP8FIFOIRQ	=	0xe657
                    E658    440 _IBNIE	=	0xe658
                    E659    441 _IBNIRQ	=	0xe659
                    E65A    442 _NAKIE	=	0xe65a
                    E65B    443 _NAKIRQ	=	0xe65b
                    E65C    444 _USBIE	=	0xe65c
                    E65D    445 _USBIRQ	=	0xe65d
                    E65E    446 _EPIE	=	0xe65e
                    E65F    447 _EPIRQ	=	0xe65f
                    E660    448 _GPIFIE	=	0xe660
                    E661    449 _GPIFIRQ	=	0xe661
                    E662    450 _USBERRIE	=	0xe662
                    E663    451 _USBERRIRQ	=	0xe663
                    E664    452 _ERRCNTLIM	=	0xe664
                    E665    453 _CLRERRCNT	=	0xe665
                    E666    454 _INT2IVEC	=	0xe666
                    E667    455 _INT4IVEC	=	0xe667
                    E668    456 _INTSETUP	=	0xe668
                    E670    457 _PORTACFG	=	0xe670
                    E671    458 _PORTCCFG	=	0xe671
                    E672    459 _PORTECFG	=	0xe672
                    E678    460 _I2CS	=	0xe678
                    E679    461 _I2DAT	=	0xe679
                    E67A    462 _I2CTL	=	0xe67a
                    E67B    463 _XAUTODAT1	=	0xe67b
                    E67C    464 _XAUTODAT2	=	0xe67c
                    E680    465 _USBCS	=	0xe680
                    E681    466 _SUSPEND	=	0xe681
                    E682    467 _WAKEUPCS	=	0xe682
                    E683    468 _TOGCTL	=	0xe683
                    E684    469 _USBFRAMEH	=	0xe684
                    E685    470 _USBFRAMEL	=	0xe685
                    E686    471 _MICROFRAME	=	0xe686
                    E687    472 _FNADDR	=	0xe687
                    E68A    473 _EP0BCH	=	0xe68a
                    E68B    474 _EP0BCL	=	0xe68b
                    E68D    475 _EP1OUTBC	=	0xe68d
                    E68F    476 _EP1INBC	=	0xe68f
                    E690    477 _EP2BCH	=	0xe690
                    E691    478 _EP2BCL	=	0xe691
                    E694    479 _EP4BCH	=	0xe694
                    E695    480 _EP4BCL	=	0xe695
                    E698    481 _EP6BCH	=	0xe698
                    E699    482 _EP6BCL	=	0xe699
                    E69C    483 _EP8BCH	=	0xe69c
                    E69D    484 _EP8BCL	=	0xe69d
                    E6A0    485 _EP0CS	=	0xe6a0
                    E6A1    486 _EP1OUTCS	=	0xe6a1
                    E6A2    487 _EP1INCS	=	0xe6a2
                    E6A3    488 _EP2CS	=	0xe6a3
                    E6A4    489 _EP4CS	=	0xe6a4
                    E6A5    490 _EP6CS	=	0xe6a5
                    E6A6    491 _EP8CS	=	0xe6a6
                    E6A7    492 _EP2FIFOFLGS	=	0xe6a7
                    E6A8    493 _EP4FIFOFLGS	=	0xe6a8
                    E6A9    494 _EP6FIFOFLGS	=	0xe6a9
                    E6AA    495 _EP8FIFOFLGS	=	0xe6aa
                    E6AB    496 _EP2FIFOBCH	=	0xe6ab
                    E6AC    497 _EP2FIFOBCL	=	0xe6ac
                    E6AD    498 _EP4FIFOBCH	=	0xe6ad
                    E6AE    499 _EP4FIFOBCL	=	0xe6ae
                    E6AF    500 _EP6FIFOBCH	=	0xe6af
                    E6B0    501 _EP6FIFOBCL	=	0xe6b0
                    E6B1    502 _EP8FIFOBCH	=	0xe6b1
                    E6B2    503 _EP8FIFOBCL	=	0xe6b2
                    E6B3    504 _SUDPTRH	=	0xe6b3
                    E6B4    505 _SUDPTRL	=	0xe6b4
                    E6B5    506 _SUDPTRCTL	=	0xe6b5
                    E6B8    507 _SETUPDAT	=	0xe6b8
                    E6C0    508 _GPIFWFSELECT	=	0xe6c0
                    E6C1    509 _GPIFIDLECS	=	0xe6c1
                    E6C2    510 _GPIFIDLECTL	=	0xe6c2
                    E6C3    511 _GPIFCTLCFG	=	0xe6c3
                    E6C4    512 _GPIFADRH	=	0xe6c4
                    E6C5    513 _GPIFADRL	=	0xe6c5
                    E6CE    514 _GPIFTCB3	=	0xe6ce
                    E6CF    515 _GPIFTCB2	=	0xe6cf
                    E6D0    516 _GPIFTCB1	=	0xe6d0
                    E6D1    517 _GPIFTCB0	=	0xe6d1
                    E6D2    518 _EP2GPIFFLGSEL	=	0xe6d2
                    E6D3    519 _EP2GPIFPFSTOP	=	0xe6d3
                    E6D4    520 _EP2GPIFTRIG	=	0xe6d4
                    E6DA    521 _EP4GPIFFLGSEL	=	0xe6da
                    E6DB    522 _EP4GPIFPFSTOP	=	0xe6db
                    E6DC    523 _EP4GPIFTRIG	=	0xe6dc
                    E6E2    524 _EP6GPIFFLGSEL	=	0xe6e2
                    E6E3    525 _EP6GPIFPFSTOP	=	0xe6e3
                    E6E4    526 _EP6GPIFTRIG	=	0xe6e4
                    E6EA    527 _EP8GPIFFLGSEL	=	0xe6ea
                    E6EB    528 _EP8GPIFPFSTOP	=	0xe6eb
                    E6EC    529 _EP8GPIFTRIG	=	0xe6ec
                    E6F0    530 _XGPIFSGLDATH	=	0xe6f0
                    E6F1    531 _XGPIFSGLDATLX	=	0xe6f1
                    E6F2    532 _XGPIFSGLDATLNOX	=	0xe6f2
                    E6F3    533 _GPIFREADYCFG	=	0xe6f3
                    E6F4    534 _GPIFREADYSTAT	=	0xe6f4
                    E6F5    535 _GPIFABORT	=	0xe6f5
                    E6C6    536 _FLOWSTATE	=	0xe6c6
                    E6C7    537 _FLOWLOGIC	=	0xe6c7
                    E6C8    538 _FLOWEQ0CTL	=	0xe6c8
                    E6C9    539 _FLOWEQ1CTL	=	0xe6c9
                    E6CA    540 _FLOWHOLDOFF	=	0xe6ca
                    E6CB    541 _FLOWSTB	=	0xe6cb
                    E6CC    542 _FLOWSTBEDGE	=	0xe6cc
                    E6CD    543 _FLOWSTBHPERIOD	=	0xe6cd
                    E60C    544 _GPIFHOLDAMOUNT	=	0xe60c
                    E67D    545 _UDMACRCH	=	0xe67d
                    E67E    546 _UDMACRCL	=	0xe67e
                    E67F    547 _UDMACRCQUAL	=	0xe67f
                    E6F8    548 _DBUG	=	0xe6f8
                    E6F9    549 _TESTCFG	=	0xe6f9
                    E6FA    550 _USBTEST	=	0xe6fa
                    E6FB    551 _CT1	=	0xe6fb
                    E6FC    552 _CT2	=	0xe6fc
                    E6FD    553 _CT3	=	0xe6fd
                    E6FE    554 _CT4	=	0xe6fe
                    E740    555 _EP0BUF	=	0xe740
                    E780    556 _EP1OUTBUF	=	0xe780
                    E7C0    557 _EP1INBUF	=	0xe7c0
                    F000    558 _EP2FIFOBUF	=	0xf000
                    F400    559 _EP4FIFOBUF	=	0xf400
                    F800    560 _EP6FIFOBUF	=	0xf800
                    FC00    561 _EP8FIFOBUF	=	0xfc00
                            562 ;--------------------------------------------------------
                            563 ; absolute external ram data
                            564 ;--------------------------------------------------------
                            565 	.area XABS    (ABS,XDATA)
                            566 ;--------------------------------------------------------
                            567 ; external initialized ram data
                            568 ;--------------------------------------------------------
                            569 	.area XISEG   (XDATA)
                            570 	.area HOME    (CODE)
                            571 	.area GSINIT0 (CODE)
                            572 	.area GSINIT1 (CODE)
                            573 	.area GSINIT2 (CODE)
                            574 	.area GSINIT3 (CODE)
                            575 	.area GSINIT4 (CODE)
                            576 	.area GSINIT5 (CODE)
                            577 	.area GSINIT  (CODE)
                            578 	.area GSFINAL (CODE)
                            579 	.area CSEG    (CODE)
                            580 ;--------------------------------------------------------
                            581 ; interrupt vector 
                            582 ;--------------------------------------------------------
                            583 	.area HOME    (CODE)
   0000                     584 __interrupt_vect:
   0000 02 00 08            585 	ljmp	__sdcc_gsinit_startup
                            586 ;--------------------------------------------------------
                            587 ; global & static initialisations
                            588 ;--------------------------------------------------------
                            589 	.area HOME    (CODE)
                            590 	.area GSINIT  (CODE)
                            591 	.area GSFINAL (CODE)
                            592 	.area GSINIT  (CODE)
                            593 	.globl __sdcc_gsinit_startup
                            594 	.globl __sdcc_program_startup
                            595 	.globl __start__stack
                            596 	.globl __mcs51_genXINIT
                            597 	.globl __mcs51_genXRAMCLEAR
                            598 	.globl __mcs51_genRAMCLEAR
                            599 ;	eeprom_read.h:14: xdata unsigned char *err =(xdata char*)0x1200;
   0061 75 08 00            600 	mov	_err,#0x00
   0064 75 09 12            601 	mov	(_err + 1),#0x12
                            602 ;	eeprom_read.h:15: xdata unsigned char *dat =(xdata char*)0x1000;
   0067 75 0A 00            603 	mov	_dat,#0x00
   006A 75 0B 10            604 	mov	(_dat + 1),#0x10
                            605 ;	eeprom_read.h:119: xdata unsigned char *command = (xdata unsigned char *)0x1100;
   006D 75 0C 00            606 	mov	_command,#0x00
   0070 75 0D 11            607 	mov	(_command + 1),#0x11
                            608 ;	eeprom_read.h:120: xdata unsigned char *HWmark = (xdata unsigned char *)0x1140;
   0073 75 0E 40            609 	mov	_HWmark,#0x40
   0076 75 0F 11            610 	mov	(_HWmark + 1),#0x11
                            611 ;	eeprom_read_mark.c:19: char *FWmark = "FWEEPRv000.001";
   0079 75 13 4C            612 	mov	_FWmark,#__str_2
   007C 75 14 05            613 	mov	(_FWmark + 1),#(__str_2 >> 8)
   007F 75 15 80            614 	mov	(_FWmark + 2),#0x80
                            615 	.area GSFINAL (CODE)
   0082 02 00 03            616 	ljmp	__sdcc_program_startup
                            617 ;--------------------------------------------------------
                            618 ; Home
                            619 ;--------------------------------------------------------
                            620 	.area HOME    (CODE)
                            621 	.area HOME    (CODE)
   0003                     622 __sdcc_program_startup:
   0003 12 04 3B            623 	lcall	_main
                            624 ;	return from main will lock up
   0006 80 FE               625 	sjmp .
                            626 ;--------------------------------------------------------
                            627 ; code
                            628 ;--------------------------------------------------------
                            629 	.area CSEG    (CODE)
                            630 ;------------------------------------------------------------
                            631 ;Allocation info for local variables in function 'EERead'
                            632 ;------------------------------------------------------------
                            633 ;HWmark                    Allocated with name '_EERead_PARM_2'
                            634 ;ee_adr                    Allocated to registers r6 r7 
                            635 ;n                         Allocated with name '_EERead_n_1_1'
                            636 ;------------------------------------------------------------
                            637 ;	eeprom_read.h:34: static uint8 EERead(uint16 ee_adr, 	unsigned char HWmark[32])
                            638 ;	-----------------------------------------
                            639 ;	 function EERead
                            640 ;	-----------------------------------------
   0085                     641 _EERead:
                    0007    642 	ar7 = 0x07
                    0006    643 	ar6 = 0x06
                    0005    644 	ar5 = 0x05
                    0004    645 	ar4 = 0x04
                    0003    646 	ar3 = 0x03
                    0002    647 	ar2 = 0x02
                    0001    648 	ar1 = 0x01
                    0000    649 	ar0 = 0x00
   0085 AE 82               650 	mov	r6,dpl
   0087 AF 83               651 	mov	r7,dph
                            652 ;	eeprom_read.h:39: I2CS = I2CS_START;
   0089 90 E6 78            653 	mov	dptr,#_I2CS
   008C 74 80               654 	mov	a,#0x80
   008E F0                  655 	movx	@dptr,a
                            656 ;	eeprom_read.h:40: I2DAT = EEPROM_ADR | I2CWRITE;
   008F 90 E6 79            657 	mov	dptr,#_I2DAT
   0092 74 A2               658 	mov	a,#0xA2
   0094 F0                  659 	movx	@dptr,a
                            660 ;	eeprom_read.h:41: while(!(I2CS & I2CS_DONE));
   0095                     661 00101$:
   0095 90 E6 78            662 	mov	dptr,#_I2CS
   0098 E0                  663 	movx	a,@dptr
   0099 FD                  664 	mov	r5,a
   009A 30 E0 F8            665 	jnb	acc.0,00101$
                            666 ;	eeprom_read.h:44: if(!(I2CS & I2CS_ACK)) return(1);
   009D 90 E6 78            667 	mov	dptr,#_I2CS
   00A0 E0                  668 	movx	a,@dptr
   00A1 FD                  669 	mov	r5,a
   00A2 20 E1 04            670 	jb	acc.1,00105$
   00A5 75 82 01            671 	mov	dpl,#0x01
   00A8 22                  672 	ret
   00A9                     673 00105$:
                            674 ;	eeprom_read.h:47: I2DAT = (ee_adr>>8);
   00A9 90 E6 79            675 	mov	dptr,#_I2DAT
   00AC EF                  676 	mov	a,r7
   00AD F0                  677 	movx	@dptr,a
                            678 ;	eeprom_read.h:48: while(!(I2CS & I2CS_DONE));
   00AE                     679 00106$:
   00AE 90 E6 78            680 	mov	dptr,#_I2CS
   00B1 E0                  681 	movx	a,@dptr
   00B2 FD                  682 	mov	r5,a
   00B3 30 E0 F8            683 	jnb	acc.0,00106$
                            684 ;	eeprom_read.h:51: if(!(I2CS & I2CS_ACK)) return(2);
   00B6 90 E6 78            685 	mov	dptr,#_I2CS
   00B9 E0                  686 	movx	a,@dptr
   00BA FD                  687 	mov	r5,a
   00BB 20 E1 04            688 	jb	acc.1,00110$
   00BE 75 82 02            689 	mov	dpl,#0x02
   00C1 22                  690 	ret
   00C2                     691 00110$:
                            692 ;	eeprom_read.h:54: I2DAT = (ee_adr & 0xff);
   00C2 7F 00               693 	mov	r7,#0x00
   00C4 90 E6 79            694 	mov	dptr,#_I2DAT
   00C7 EE                  695 	mov	a,r6
   00C8 F0                  696 	movx	@dptr,a
                            697 ;	eeprom_read.h:55: while(!(I2CS & I2CS_DONE));
   00C9                     698 00111$:
   00C9 90 E6 78            699 	mov	dptr,#_I2CS
   00CC E0                  700 	movx	a,@dptr
   00CD FF                  701 	mov	r7,a
   00CE 30 E0 F8            702 	jnb	acc.0,00111$
                            703 ;	eeprom_read.h:58: if(!(I2CS & I2CS_ACK)) return(3);
   00D1 90 E6 78            704 	mov	dptr,#_I2CS
   00D4 E0                  705 	movx	a,@dptr
   00D5 FF                  706 	mov	r7,a
   00D6 20 E1 04            707 	jb	acc.1,00115$
   00D9 75 82 03            708 	mov	dpl,#0x03
   00DC 22                  709 	ret
   00DD                     710 00115$:
                            711 ;	eeprom_read.h:61: I2CS = I2CS_START;
   00DD 90 E6 78            712 	mov	dptr,#_I2CS
   00E0 74 80               713 	mov	a,#0x80
   00E2 F0                  714 	movx	@dptr,a
                            715 ;	eeprom_read.h:62: I2DAT = EEPROM_ADR | I2CREAD;
   00E3 90 E6 79            716 	mov	dptr,#_I2DAT
   00E6 74 A3               717 	mov	a,#0xA3
   00E8 F0                  718 	movx	@dptr,a
                            719 ;	eeprom_read.h:63: while(!(I2CS & I2CS_DONE));
   00E9                     720 00116$:
   00E9 90 E6 78            721 	mov	dptr,#_I2CS
   00EC E0                  722 	movx	a,@dptr
   00ED FF                  723 	mov	r7,a
   00EE 30 E0 F8            724 	jnb	acc.0,00116$
                            725 ;	eeprom_read.h:66: if(!(I2CS & I2CS_ACK)) return(5);
   00F1 90 E6 78            726 	mov	dptr,#_I2CS
   00F4 E0                  727 	movx	a,@dptr
   00F5 FF                  728 	mov	r7,a
   00F6 20 E1 04            729 	jb	acc.1,00120$
   00F9 75 82 05            730 	mov	dpl,#0x05
   00FC 22                  731 	ret
   00FD                     732 00120$:
                            733 ;	eeprom_read.h:69: HWmark[0] = I2DAT;
   00FD AD 16               734 	mov	r5,_EERead_PARM_2
   00FF AE 17               735 	mov	r6,(_EERead_PARM_2 + 1)
   0101 AF 18               736 	mov	r7,(_EERead_PARM_2 + 2)
   0103 90 E6 79            737 	mov	dptr,#_I2DAT
   0106 E0                  738 	movx	a,@dptr
   0107 FC                  739 	mov	r4,a
   0108 8D 82               740 	mov	dpl,r5
   010A 8E 83               741 	mov	dph,r6
   010C 8F F0               742 	mov	b,r7
   010E 12 05 07            743 	lcall	__gptrput
                            744 ;	eeprom_read.h:70: while(!(I2CS & I2CS_DONE));
   0111                     745 00121$:
   0111 90 E6 78            746 	mov	dptr,#_I2CS
   0114 E0                  747 	movx	a,@dptr
   0115 FC                  748 	mov	r4,a
   0116 30 E0 F8            749 	jnb	acc.0,00121$
                            750 ;	eeprom_read.h:71: if(!(I2CS & I2CS_ACK)) return(6);
   0119 90 E6 78            751 	mov	dptr,#_I2CS
   011C E0                  752 	movx	a,@dptr
   011D FC                  753 	mov	r4,a
   011E 20 E1 04            754 	jb	acc.1,00126$
   0121 75 82 06            755 	mov	dpl,#0x06
   0124 22                  756 	ret
                            757 ;	eeprom_read.h:74: while(!(I2CS & I2CS_DONE));
   0125                     758 00126$:
   0125 90 E6 78            759 	mov	dptr,#_I2CS
   0128 E0                  760 	movx	a,@dptr
   0129 FC                  761 	mov	r4,a
   012A 30 E0 F8            762 	jnb	acc.0,00126$
                            763 ;	eeprom_read.h:75: if(!(I2CS & I2CS_ACK)) return(7);
   012D 90 E6 78            764 	mov	dptr,#_I2CS
   0130 E0                  765 	movx	a,@dptr
   0131 FC                  766 	mov	r4,a
   0132 20 E1 04            767 	jb	acc.1,00130$
   0135 75 82 07            768 	mov	dpl,#0x07
   0138 22                  769 	ret
   0139                     770 00130$:
                            771 ;	eeprom_read.h:77: HWmark[0] = I2DAT;
   0139 90 E6 79            772 	mov	dptr,#_I2DAT
   013C E0                  773 	movx	a,@dptr
   013D FC                  774 	mov	r4,a
   013E 8D 82               775 	mov	dpl,r5
   0140 8E 83               776 	mov	dph,r6
   0142 8F F0               777 	mov	b,r7
   0144 12 05 07            778 	lcall	__gptrput
                            779 ;	eeprom_read.h:78: while(!(I2CS & I2CS_DONE));
   0147                     780 00131$:
   0147 90 E6 78            781 	mov	dptr,#_I2CS
   014A E0                  782 	movx	a,@dptr
   014B FC                  783 	mov	r4,a
   014C 30 E0 F8            784 	jnb	acc.0,00131$
                            785 ;	eeprom_read.h:79: if(!(I2CS & I2CS_ACK)) return(8);
   014F 90 E6 78            786 	mov	dptr,#_I2CS
   0152 E0                  787 	movx	a,@dptr
   0153 FC                  788 	mov	r4,a
   0154 20 E1 04            789 	jb	acc.1,00135$
   0157 75 82 08            790 	mov	dpl,#0x08
   015A 22                  791 	ret
   015B                     792 00135$:
                            793 ;	eeprom_read.h:81: HWmark[1] = I2DAT;
   015B 74 01               794 	mov	a,#0x01
   015D 2D                  795 	add	a,r5
   015E FA                  796 	mov	r2,a
   015F E4                  797 	clr	a
   0160 3E                  798 	addc	a,r6
   0161 FB                  799 	mov	r3,a
   0162 8F 04               800 	mov	ar4,r7
   0164 90 E6 79            801 	mov	dptr,#_I2DAT
   0167 E0                  802 	movx	a,@dptr
   0168 F9                  803 	mov	r1,a
   0169 8A 82               804 	mov	dpl,r2
   016B 8B 83               805 	mov	dph,r3
   016D 8C F0               806 	mov	b,r4
   016F 12 05 07            807 	lcall	__gptrput
                            808 ;	eeprom_read.h:82: while(!(I2CS & I2CS_DONE));
   0172                     809 00136$:
   0172 90 E6 78            810 	mov	dptr,#_I2CS
   0175 E0                  811 	movx	a,@dptr
   0176 FC                  812 	mov	r4,a
   0177 30 E0 F8            813 	jnb	acc.0,00136$
                            814 ;	eeprom_read.h:83: if(!(I2CS & I2CS_ACK)) return(8);
   017A 90 E6 78            815 	mov	dptr,#_I2CS
   017D E0                  816 	movx	a,@dptr
   017E FC                  817 	mov	r4,a
   017F 20 E1 04            818 	jb	acc.1,00193$
   0182 75 82 08            819 	mov	dpl,#0x08
   0185 22                  820 	ret
                            821 ;	eeprom_read.h:85: for(n = 2;n<31;n++) {
   0186                     822 00193$:
   0186 75 19 02            823 	mov	_EERead_n_1_1,#0x02
   0189 75 1A 00            824 	mov	(_EERead_n_1_1 + 1),#0x00
   018C                     825 00159$:
   018C C3                  826 	clr	c
   018D E5 19               827 	mov	a,_EERead_n_1_1
   018F 94 1F               828 	subb	a,#0x1F
   0191 E5 1A               829 	mov	a,(_EERead_n_1_1 + 1)
   0193 64 80               830 	xrl	a,#0x80
   0195 94 80               831 	subb	a,#0x80
   0197 50 36               832 	jnc	00162$
                            833 ;	eeprom_read.h:86: HWmark[n] = I2DAT;
   0199 E5 19               834 	mov	a,_EERead_n_1_1
   019B 2D                  835 	add	a,r5
   019C F8                  836 	mov	r0,a
   019D E5 1A               837 	mov	a,(_EERead_n_1_1 + 1)
   019F 3E                  838 	addc	a,r6
   01A0 F9                  839 	mov	r1,a
   01A1 8F 02               840 	mov	ar2,r7
   01A3 90 E6 79            841 	mov	dptr,#_I2DAT
   01A6 E0                  842 	movx	a,@dptr
   01A7 FC                  843 	mov	r4,a
   01A8 88 82               844 	mov	dpl,r0
   01AA 89 83               845 	mov	dph,r1
   01AC 8A F0               846 	mov	b,r2
   01AE 12 05 07            847 	lcall	__gptrput
                            848 ;	eeprom_read.h:87: while(!(I2CS & I2CS_DONE));
   01B1                     849 00141$:
   01B1 90 E6 78            850 	mov	dptr,#_I2CS
   01B4 E0                  851 	movx	a,@dptr
   01B5 FC                  852 	mov	r4,a
   01B6 30 E0 F8            853 	jnb	acc.0,00141$
                            854 ;	eeprom_read.h:88: if(!(I2CS & I2CS_ACK)) return(9);
   01B9 90 E6 78            855 	mov	dptr,#_I2CS
   01BC E0                  856 	movx	a,@dptr
   01BD FC                  857 	mov	r4,a
   01BE 20 E1 04            858 	jb	acc.1,00161$
   01C1 75 82 09            859 	mov	dpl,#0x09
   01C4 22                  860 	ret
   01C5                     861 00161$:
                            862 ;	eeprom_read.h:85: for(n = 2;n<31;n++) {
   01C5 05 19               863 	inc	_EERead_n_1_1
   01C7 E4                  864 	clr	a
   01C8 B5 19 C1            865 	cjne	a,_EERead_n_1_1,00159$
   01CB 05 1A               866 	inc	(_EERead_n_1_1 + 1)
   01CD 80 BD               867 	sjmp	00159$
   01CF                     868 00162$:
                            869 ;	eeprom_read.h:91: I2CS = I2CS_LASTRD;
   01CF 90 E6 78            870 	mov	dptr,#_I2CS
   01D2 74 20               871 	mov	a,#0x20
   01D4 F0                  872 	movx	@dptr,a
                            873 ;	eeprom_read.h:92: HWmark[31] = I2DAT;
   01D5 74 1F               874 	mov	a,#0x1F
   01D7 2D                  875 	add	a,r5
   01D8 FD                  876 	mov	r5,a
   01D9 E4                  877 	clr	a
   01DA 3E                  878 	addc	a,r6
   01DB FE                  879 	mov	r6,a
   01DC 90 E6 79            880 	mov	dptr,#_I2DAT
   01DF E0                  881 	movx	a,@dptr
   01E0 FC                  882 	mov	r4,a
   01E1 8D 82               883 	mov	dpl,r5
   01E3 8E 83               884 	mov	dph,r6
   01E5 8F F0               885 	mov	b,r7
   01E7 12 05 07            886 	lcall	__gptrput
                            887 ;	eeprom_read.h:93: while(!(I2CS & I2CS_DONE));
   01EA                     888 00146$:
   01EA 90 E6 78            889 	mov	dptr,#_I2CS
   01ED E0                  890 	movx	a,@dptr
   01EE FC                  891 	mov	r4,a
   01EF 30 E0 F8            892 	jnb	acc.0,00146$
                            893 ;	eeprom_read.h:94: HWmark[31] = I2DAT;
   01F2 90 E6 79            894 	mov	dptr,#_I2DAT
   01F5 E0                  895 	movx	a,@dptr
   01F6 FC                  896 	mov	r4,a
   01F7 8D 82               897 	mov	dpl,r5
   01F9 8E 83               898 	mov	dph,r6
   01FB 8F F0               899 	mov	b,r7
   01FD 12 05 07            900 	lcall	__gptrput
                            901 ;	eeprom_read.h:95: while(!(I2CS & I2CS_DONE));
   0200                     902 00149$:
   0200 90 E6 78            903 	mov	dptr,#_I2CS
   0203 E0                  904 	movx	a,@dptr
   0204 FF                  905 	mov	r7,a
   0205 30 E0 F8            906 	jnb	acc.0,00149$
                            907 ;	eeprom_read.h:96: if(!(I2CS & I2CS_ACK)) return(10);
   0208 90 E6 78            908 	mov	dptr,#_I2CS
   020B E0                  909 	movx	a,@dptr
   020C FF                  910 	mov	r7,a
   020D 20 E1 04            911 	jb	acc.1,00153$
   0210 75 82 0A            912 	mov	dpl,#0x0A
   0213 22                  913 	ret
   0214                     914 00153$:
                            915 ;	eeprom_read.h:107: I2CS = I2CS_STOP;
   0214 90 E6 78            916 	mov	dptr,#_I2CS
   0217 74 40               917 	mov	a,#0x40
   0219 F0                  918 	movx	@dptr,a
                            919 ;	eeprom_read.h:108: while(!(I2CS & I2CS_DONE));
   021A                     920 00154$:
   021A 90 E6 78            921 	mov	dptr,#_I2CS
   021D E0                  922 	movx	a,@dptr
   021E FF                  923 	mov	r7,a
   021F 30 E0 F8            924 	jnb	acc.0,00154$
                            925 ;	eeprom_read.h:110: if(!(I2CS & I2CS_ACK)) return(11);
   0222 90 E6 78            926 	mov	dptr,#_I2CS
   0225 E0                  927 	movx	a,@dptr
   0226 FF                  928 	mov	r7,a
   0227 20 E1 04            929 	jb	acc.1,00158$
   022A 75 82 0B            930 	mov	dpl,#0x0B
   022D 22                  931 	ret
   022E                     932 00158$:
                            933 ;	eeprom_read.h:112: return(64);
   022E 75 82 40            934 	mov	dpl,#0x40
   0231 22                  935 	ret
                            936 ;------------------------------------------------------------
                            937 ;Allocation info for local variables in function 'readmarkeeprom'
                            938 ;------------------------------------------------------------
                            939 ;n                         Allocated to registers r6 r7 
                            940 ;------------------------------------------------------------
                            941 ;	eeprom_read.h:123: static uint8 readmarkeeprom(void) {
                            942 ;	-----------------------------------------
                            943 ;	 function readmarkeeprom
                            944 ;	-----------------------------------------
   0232                     945 _readmarkeeprom:
                            946 ;	eeprom_read.h:127: I2CTL = 0x01;	// Set 400kHz:
   0232 90 E6 7A            947 	mov	dptr,#_I2CTL
   0235 74 01               948 	mov	a,#0x01
   0237 F0                  949 	movx	@dptr,a
                            950 ;	eeprom_read.h:128: SYNCDELAY;
   0238 00                  951 	 nop; 
                            952 ;	eeprom_read.h:130: for(n=0;n<128;n++) HWmark[n] = 0x00;
   0239 7E 00               953 	mov	r6,#0x00
   023B 7F 00               954 	mov	r7,#0x00
   023D                     955 00101$:
   023D C3                  956 	clr	c
   023E EE                  957 	mov	a,r6
   023F 94 80               958 	subb	a,#0x80
   0241 EF                  959 	mov	a,r7
   0242 64 80               960 	xrl	a,#0x80
   0244 94 80               961 	subb	a,#0x80
   0246 50 13               962 	jnc	00104$
   0248 EE                  963 	mov	a,r6
   0249 25 0E               964 	add	a,_HWmark
   024B F5 82               965 	mov	dpl,a
   024D EF                  966 	mov	a,r7
   024E 35 0F               967 	addc	a,(_HWmark + 1)
   0250 F5 83               968 	mov	dph,a
   0252 E4                  969 	clr	a
   0253 F0                  970 	movx	@dptr,a
   0254 0E                  971 	inc	r6
   0255 BE 00 E5            972 	cjne	r6,#0x00,00101$
   0258 0F                  973 	inc	r7
   0259 80 E2               974 	sjmp	00101$
   025B                     975 00104$:
                            976 ;	eeprom_read.h:131: err[32+3] = EERead( 0x0400,HWmark);
   025B 74 23               977 	mov	a,#0x23
   025D 25 08               978 	add	a,_err
   025F FE                  979 	mov	r6,a
   0260 E4                  980 	clr	a
   0261 35 09               981 	addc	a,(_err + 1)
   0263 FF                  982 	mov	r7,a
   0264 85 0E 16            983 	mov	_EERead_PARM_2,_HWmark
   0267 85 0F 17            984 	mov	(_EERead_PARM_2 + 1),(_HWmark + 1)
   026A 75 18 00            985 	mov	(_EERead_PARM_2 + 2),#0x00
   026D 90 04 00            986 	mov	dptr,#0x0400
   0270 C0 07               987 	push	ar7
   0272 C0 06               988 	push	ar6
   0274 12 00 85            989 	lcall	_EERead
   0277 AD 82               990 	mov	r5,dpl
   0279 D0 06               991 	pop	ar6
   027B D0 07               992 	pop	ar7
   027D 8E 82               993 	mov	dpl,r6
   027F 8F 83               994 	mov	dph,r7
   0281 ED                  995 	mov	a,r5
   0282 F0                  996 	movx	@dptr,a
                            997 ;	eeprom_read.h:132: return(0);
   0283 75 82 00            998 	mov	dpl,#0x00
   0286 22                  999 	ret
                           1000 ;------------------------------------------------------------
                           1001 ;Allocation info for local variables in function 'hostreadmarkep1init'
                           1002 ;------------------------------------------------------------
                           1003 ;	eeprom_read.h:136: static uint8 hostreadmarkep1init(void) {
                           1004 ;	-----------------------------------------
                           1005 ;	 function hostreadmarkep1init
                           1006 ;	-----------------------------------------
   0287                    1007 _hostreadmarkep1init:
                           1008 ;	eeprom_read.h:138: EP1OUTCFG=0xa0;
   0287 90 E6 10           1009 	mov	dptr,#_EP1OUTCFG
   028A 74 A0              1010 	mov	a,#0xA0
   028C F0                 1011 	movx	@dptr,a
                           1012 ;	eeprom_read.h:139: EP1INCFG=0xa0;
   028D 90 E6 11           1013 	mov	dptr,#_EP1INCFG
   0290 74 A0              1014 	mov	a,#0xA0
   0292 F0                 1015 	movx	@dptr,a
                           1016 ;	eeprom_read.h:141: SYNCDELAY;
   0293 00                 1017 	 nop; 
                           1018 ;	eeprom_read.h:142: EP1OUTBC=0xff; // Arm endpoint 1 for OUT (host->device) transfers
   0294 90 E6 8D           1019 	mov	dptr,#_EP1OUTBC
   0297 74 FF              1020 	mov	a,#0xFF
   0299 F0                 1021 	movx	@dptr,a
                           1022 ;	eeprom_read.h:144: return(0);
   029A 75 82 00           1023 	mov	dpl,#0x00
   029D 22                 1024 	ret
                           1025 ;------------------------------------------------------------
                           1026 ;Allocation info for local variables in function 'hostreadmarkep1poll'
                           1027 ;------------------------------------------------------------
                           1028 ;src                       Allocated to registers 
                           1029 ;dest                      Allocated to registers r5 r6 
                           1030 ;ep1outbc                  Allocated with name '_hostreadmarkep1poll_ep1outbc_1_1'
                           1031 ;n                         Allocated with name '_hostreadmarkep1poll_n_1_1'
                           1032 ;------------------------------------------------------------
                           1033 ;	eeprom_read.h:147: static uint8 hostreadmarkep1poll(void) {
                           1034 ;	-----------------------------------------
                           1035 ;	 function hostreadmarkep1poll
                           1036 ;	-----------------------------------------
   029E                    1037 _hostreadmarkep1poll:
                           1038 ;	eeprom_read.h:153: if(!(EP1OUTCS & bmEPBUSY)) {
   029E 90 E6 A1           1039 	mov	dptr,#_EP1OUTCS
   02A1 E0                 1040 	movx	a,@dptr
   02A2 FF                 1041 	mov	r7,a
   02A3 30 E1 03           1042 	jnb	acc.1,00153$
   02A6 02 04 37           1043 	ljmp	00114$
   02A9                    1044 00153$:
                           1045 ;	eeprom_read.h:154: ep1outbc = EP1OUTBC;
   02A9 90 E6 8D           1046 	mov	dptr,#_EP1OUTBC
   02AC E0                 1047 	movx	a,@dptr
   02AD F5 10              1048 	mov	_hostreadmarkep1poll_ep1outbc_1_1,a
                           1049 ;	eeprom_read.h:155: if(ep1outbc != 0xff ) {
   02AF 74 FF              1050 	mov	a,#0xFF
   02B1 B5 10 03           1051 	cjne	a,_hostreadmarkep1poll_ep1outbc_1_1,00154$
   02B4 02 04 37           1052 	ljmp	00114$
   02B7                    1053 00154$:
                           1054 ;	eeprom_read.h:156: src = EP1OUTBUF;
                           1055 ;	eeprom_read.h:157: dest = EP1INBUF;
   02B7 7D C0              1056 	mov	r5,#_EP1INBUF
   02B9 7E E7              1057 	mov	r6,#(_EP1INBUF >> 8)
                           1058 ;	eeprom_read.h:158: while (EP1INCS & 0x02);
   02BB                    1059 00101$:
   02BB 90 E6 A2           1060 	mov	dptr,#_EP1INCS
   02BE E0                 1061 	movx	a,@dptr
   02BF FC                 1062 	mov	r4,a
   02C0 20 E1 F8           1063 	jb	acc.1,00101$
                           1064 ;	eeprom_read.h:159: for(n=0; n<32; n++) command[n] = src[n];
   02C3 7B 00              1065 	mov	r3,#0x00
   02C5 7C 00              1066 	mov	r4,#0x00
   02C7                    1067 00115$:
   02C7 C3                 1068 	clr	c
   02C8 EB                 1069 	mov	a,r3
   02C9 94 20              1070 	subb	a,#0x20
   02CB EC                 1071 	mov	a,r4
   02CC 64 80              1072 	xrl	a,#0x80
   02CE 94 80              1073 	subb	a,#0x80
   02D0 50 20              1074 	jnc	00118$
   02D2 EB                 1075 	mov	a,r3
   02D3 25 0C              1076 	add	a,_command
   02D5 F9                 1077 	mov	r1,a
   02D6 EC                 1078 	mov	a,r4
   02D7 35 0D              1079 	addc	a,(_command + 1)
   02D9 FA                 1080 	mov	r2,a
   02DA EB                 1081 	mov	a,r3
   02DB 24 80              1082 	add	a,#_EP1OUTBUF
   02DD F5 82              1083 	mov	dpl,a
   02DF EC                 1084 	mov	a,r4
   02E0 34 E7              1085 	addc	a,#(_EP1OUTBUF >> 8)
   02E2 F5 83              1086 	mov	dph,a
   02E4 E0                 1087 	movx	a,@dptr
   02E5 F8                 1088 	mov	r0,a
   02E6 89 82              1089 	mov	dpl,r1
   02E8 8A 83              1090 	mov	dph,r2
   02EA F0                 1091 	movx	@dptr,a
   02EB 0B                 1092 	inc	r3
   02EC BB 00 D8           1093 	cjne	r3,#0x00,00115$
   02EF 0C                 1094 	inc	r4
   02F0 80 D5              1095 	sjmp	00115$
   02F2                    1096 00118$:
                           1097 ;	eeprom_read.h:160: for( n=0; n < ep1outbc ; n++ ) { 
   02F2 8D 03              1098 	mov	ar3,r5
   02F4 8E 04              1099 	mov	ar4,r6
   02F6 79 00              1100 	mov	r1,#0x00
   02F8 7A 00              1101 	mov	r2,#0x00
   02FA                    1102 00119$:
   02FA A8 10              1103 	mov	r0,_hostreadmarkep1poll_ep1outbc_1_1
   02FC 7F 00              1104 	mov	r7,#0x00
   02FE C3                 1105 	clr	c
   02FF E9                 1106 	mov	a,r1
   0300 98                 1107 	subb	a,r0
   0301 EA                 1108 	mov	a,r2
   0302 64 80              1109 	xrl	a,#0x80
   0304 8F F0              1110 	mov	b,r7
   0306 63 F0 80           1111 	xrl	b,#0x80
   0309 95 F0              1112 	subb	a,b
   030B 50 1D              1113 	jnc	00122$
                           1114 ;	eeprom_read.h:161: *dest++ = command[n];
   030D E9                 1115 	mov	a,r1
   030E 25 0C              1116 	add	a,_command
   0310 F5 82              1117 	mov	dpl,a
   0312 EA                 1118 	mov	a,r2
   0313 35 0D              1119 	addc	a,(_command + 1)
   0315 F5 83              1120 	mov	dph,a
   0317 E0                 1121 	movx	a,@dptr
   0318 FF                 1122 	mov	r7,a
   0319 8B 82              1123 	mov	dpl,r3
   031B 8C 83              1124 	mov	dph,r4
   031D F0                 1125 	movx	@dptr,a
   031E A3                 1126 	inc	dptr
   031F AB 82              1127 	mov	r3,dpl
   0321 AC 83              1128 	mov	r4,dph
                           1129 ;	eeprom_read.h:160: for( n=0; n < ep1outbc ; n++ ) { 
   0323 09                 1130 	inc	r1
   0324 B9 00 D3           1131 	cjne	r1,#0x00,00119$
   0327 0A                 1132 	inc	r2
   0328 80 D0              1133 	sjmp	00119$
   032A                    1134 00122$:
                           1135 ;	eeprom_read.h:163: *err++ = 0x5a;
   032A 85 08 82           1136 	mov	dpl,_err
   032D 85 09 83           1137 	mov	dph,(_err + 1)
   0330 74 5A              1138 	mov	a,#0x5A
   0332 F0                 1139 	movx	@dptr,a
   0333 05 08              1140 	inc	_err
   0335 E4                 1141 	clr	a
   0336 B5 08 02           1142 	cjne	a,_err,00160$
   0339 05 09              1143 	inc	(_err + 1)
   033B                    1144 00160$:
                           1145 ;	eeprom_read.h:164: EP1INBC = ep1outbc;
   033B 90 E6 8F           1146 	mov	dptr,#_EP1INBC
   033E E5 10              1147 	mov	a,_hostreadmarkep1poll_ep1outbc_1_1
   0340 F0                 1148 	movx	@dptr,a
                           1149 ;	eeprom_read.h:165: while (EP1INCS & 0x02);
   0341                    1150 00104$:
   0341 90 E6 A2           1151 	mov	dptr,#_EP1INCS
   0344 E0                 1152 	movx	a,@dptr
   0345 FF                 1153 	mov	r7,a
   0346 20 E1 F8           1154 	jb	acc.1,00104$
                           1155 ;	eeprom_read.h:166: dest = EP1INBUF;
   0349 7D C0              1156 	mov	r5,#_EP1INBUF
   034B 7E E7              1157 	mov	r6,#(_EP1INBUF >> 8)
                           1158 ;	eeprom_read.h:167: if(!strncmp(command,"getHW",5)) {
   034D AB 0C              1159 	mov	r3,_command
   034F AC 0D              1160 	mov	r4,(_command + 1)
   0351 7F 00              1161 	mov	r7,#0x00
   0353 75 16 40           1162 	mov	_strncmp_PARM_2,#__str_0
   0356 75 17 05           1163 	mov	(_strncmp_PARM_2 + 1),#(__str_0 >> 8)
   0359 75 18 80           1164 	mov	(_strncmp_PARM_2 + 2),#0x80
   035C 75 19 05           1165 	mov	_strncmp_PARM_3,#0x05
   035F 75 1A 00           1166 	mov	(_strncmp_PARM_3 + 1),#0x00
   0362 8B 82              1167 	mov	dpl,r3
   0364 8C 83              1168 	mov	dph,r4
   0366 8F F0              1169 	mov	b,r7
   0368 C0 06              1170 	push	ar6
   036A C0 05              1171 	push	ar5
   036C 12 04 88           1172 	lcall	_strncmp
   036F E5 82              1173 	mov	a,dpl
   0371 85 83 F0           1174 	mov	b,dph
   0374 D0 05              1175 	pop	ar5
   0376 D0 06              1176 	pop	ar6
   0378 45 F0              1177 	orl	a,b
                           1178 ;	eeprom_read.h:168: for( n=0; HWmark[n] != '\0' ; n++ )  
   037A 70 40              1179 	jnz	00108$
   037C 8D 04              1180 	mov	ar4,r5
   037E 8E 07              1181 	mov	ar7,r6
   0380 FA                 1182 	mov	r2,a
   0381 FB                 1183 	mov	r3,a
   0382                    1184 00123$:
   0382 EA                 1185 	mov	a,r2
   0383 25 0E              1186 	add	a,_HWmark
   0385 F5 82              1187 	mov	dpl,a
   0387 EB                 1188 	mov	a,r3
   0388 35 0F              1189 	addc	a,(_HWmark + 1)
   038A F5 83              1190 	mov	dph,a
   038C E0                 1191 	movx	a,@dptr
   038D F9                 1192 	mov	r1,a
   038E 60 12              1193 	jz	00126$
                           1194 ;	eeprom_read.h:169: *dest++ = (xdata unsigned char) HWmark[n];					
   0390 8C 82              1195 	mov	dpl,r4
   0392 8F 83              1196 	mov	dph,r7
   0394 E9                 1197 	mov	a,r1
   0395 F0                 1198 	movx	@dptr,a
   0396 A3                 1199 	inc	dptr
   0397 AC 82              1200 	mov	r4,dpl
   0399 AF 83              1201 	mov	r7,dph
                           1202 ;	eeprom_read.h:168: for( n=0; HWmark[n] != '\0' ; n++ )  
   039B 0A                 1203 	inc	r2
   039C BA 00 E3           1204 	cjne	r2,#0x00,00123$
   039F 0B                 1205 	inc	r3
   03A0 80 E0              1206 	sjmp	00123$
   03A2                    1207 00126$:
                           1208 ;	eeprom_read.h:170: *dest++ = '\0';
   03A2 8C 82              1209 	mov	dpl,r4
   03A4 8F 83              1210 	mov	dph,r7
   03A6 E4                 1211 	clr	a
   03A7 F0                 1212 	movx	@dptr,a
   03A8 74 01              1213 	mov	a,#0x01
   03AA 2C                 1214 	add	a,r4
   03AB FD                 1215 	mov	r5,a
   03AC E4                 1216 	clr	a
   03AD 3F                 1217 	addc	a,r7
   03AE FE                 1218 	mov	r6,a
                           1219 ;	eeprom_read.h:171: n++;
   03AF 74 01              1220 	mov	a,#0x01
   03B1 2A                 1221 	add	a,r2
   03B2 FC                 1222 	mov	r4,a
   03B3 E4                 1223 	clr	a
   03B4 3B                 1224 	addc	a,r3
   03B5 FF                 1225 	mov	r7,a
                           1226 ;	eeprom_read.h:172: EP1INBC = n;
   03B6 90 E6 8F           1227 	mov	dptr,#_EP1INBC
   03B9 EC                 1228 	mov	a,r4
   03BA F0                 1229 	movx	@dptr,a
                           1230 ;	eeprom_read.h:173: SYNCDELAY;
   03BB 00                 1231 	 nop; 
   03BC                    1232 00108$:
                           1233 ;	eeprom_read.h:175: if(!strncmp(command,"getFW",5)) {
   03BC A9 0C              1234 	mov	r1,_command
   03BE AA 0D              1235 	mov	r2,(_command + 1)
   03C0 7B 00              1236 	mov	r3,#0x00
   03C2 75 16 46           1237 	mov	_strncmp_PARM_2,#__str_1
   03C5 75 17 05           1238 	mov	(_strncmp_PARM_2 + 1),#(__str_1 >> 8)
   03C8 75 18 80           1239 	mov	(_strncmp_PARM_2 + 2),#0x80
   03CB 75 19 05           1240 	mov	_strncmp_PARM_3,#0x05
   03CE 75 1A 00           1241 	mov	(_strncmp_PARM_3 + 1),#0x00
   03D1 89 82              1242 	mov	dpl,r1
   03D3 8A 83              1243 	mov	dph,r2
   03D5 8B F0              1244 	mov	b,r3
   03D7 C0 06              1245 	push	ar6
   03D9 C0 05              1246 	push	ar5
   03DB 12 04 88           1247 	lcall	_strncmp
   03DE E5 82              1248 	mov	a,dpl
   03E0 85 83 F0           1249 	mov	b,dph
   03E3 D0 05              1250 	pop	ar5
   03E5 D0 06              1251 	pop	ar6
   03E7 45 F0              1252 	orl	a,b
                           1253 ;	eeprom_read.h:176: for( n=0; FWmark[n] != '\0' ; n++ )  
   03E9 70 46              1254 	jnz	00110$
   03EB F5 11              1255 	mov	_hostreadmarkep1poll_n_1_1,a
   03ED F5 12              1256 	mov	(_hostreadmarkep1poll_n_1_1 + 1),a
   03EF                    1257 00127$:
   03EF E5 11              1258 	mov	a,_hostreadmarkep1poll_n_1_1
   03F1 25 13              1259 	add	a,_FWmark
   03F3 F8                 1260 	mov	r0,a
   03F4 E5 12              1261 	mov	a,(_hostreadmarkep1poll_n_1_1 + 1)
   03F6 35 14              1262 	addc	a,(_FWmark + 1)
   03F8 F9                 1263 	mov	r1,a
   03F9 AB 15              1264 	mov	r3,(_FWmark + 2)
   03FB 88 82              1265 	mov	dpl,r0
   03FD 89 83              1266 	mov	dph,r1
   03FF 8B F0              1267 	mov	b,r3
   0401 12 05 20           1268 	lcall	__gptrget
   0404 FB                 1269 	mov	r3,a
   0405 60 15              1270 	jz	00130$
                           1271 ;	eeprom_read.h:177: *dest++ = (xdata unsigned char) FWmark[n];					
   0407 8D 82              1272 	mov	dpl,r5
   0409 8E 83              1273 	mov	dph,r6
   040B EB                 1274 	mov	a,r3
   040C F0                 1275 	movx	@dptr,a
   040D A3                 1276 	inc	dptr
   040E AD 82              1277 	mov	r5,dpl
   0410 AE 83              1278 	mov	r6,dph
                           1279 ;	eeprom_read.h:176: for( n=0; FWmark[n] != '\0' ; n++ )  
   0412 05 11              1280 	inc	_hostreadmarkep1poll_n_1_1
   0414 E4                 1281 	clr	a
   0415 B5 11 D7           1282 	cjne	a,_hostreadmarkep1poll_n_1_1,00127$
   0418 05 12              1283 	inc	(_hostreadmarkep1poll_n_1_1 + 1)
   041A 80 D3              1284 	sjmp	00127$
   041C                    1285 00130$:
                           1286 ;	eeprom_read.h:178: *dest++ = '\0';
   041C 8D 82              1287 	mov	dpl,r5
   041E 8E 83              1288 	mov	dph,r6
   0420 E4                 1289 	clr	a
   0421 F0                 1290 	movx	@dptr,a
                           1291 ;	eeprom_read.h:179: n++;
   0422 74 01              1292 	mov	a,#0x01
   0424 25 11              1293 	add	a,_hostreadmarkep1poll_n_1_1
   0426 FC                 1294 	mov	r4,a
   0427 E4                 1295 	clr	a
   0428 35 12              1296 	addc	a,(_hostreadmarkep1poll_n_1_1 + 1)
   042A FF                 1297 	mov	r7,a
                           1298 ;	eeprom_read.h:180: EP1INBC = n;
   042B 90 E6 8F           1299 	mov	dptr,#_EP1INBC
   042E EC                 1300 	mov	a,r4
   042F F0                 1301 	movx	@dptr,a
                           1302 ;	eeprom_read.h:181: SYNCDELAY;
   0430 00                 1303 	 nop; 
   0431                    1304 00110$:
                           1305 ;	eeprom_read.h:183: EP1OUTBC = 0xff;
   0431 90 E6 8D           1306 	mov	dptr,#_EP1OUTBC
   0434 74 FF              1307 	mov	a,#0xFF
   0436 F0                 1308 	movx	@dptr,a
   0437                    1309 00114$:
                           1310 ;	eeprom_read.h:186: return(0);
   0437 75 82 00           1311 	mov	dpl,#0x00
   043A 22                 1312 	ret
                           1313 ;------------------------------------------------------------
                           1314 ;Allocation info for local variables in function 'main'
                           1315 ;------------------------------------------------------------
                           1316 ;n                         Allocated to registers r6 r7 
                           1317 ;eeprom_mark_adr           Allocated to registers 
                           1318 ;adr                       Allocated to registers 
                           1319 ;------------------------------------------------------------
                           1320 ;	eeprom_read_mark.c:45: void main(void)
                           1321 ;	-----------------------------------------
                           1322 ;	 function main
                           1323 ;	-----------------------------------------
   043B                    1324 _main:
                           1325 ;	eeprom_read_mark.c:51: err = (xdata unsigned char *) 0x1200;	
   043B 75 08 00           1326 	mov	_err,#0x00
   043E 75 09 12           1327 	mov	(_err + 1),#0x12
                           1328 ;	eeprom_read_mark.c:53: for(n = 0;n < 200;n++);
   0441 7E C8              1329 	mov	r6,#0xC8
   0443 7F 00              1330 	mov	r7,#0x00
   0445                    1331 00103$:
   0445 1E                 1332 	dec	r6
   0446 BE FF 01           1333 	cjne	r6,#0xFF,00120$
   0449 1F                 1334 	dec	r7
   044A                    1335 00120$:
   044A EE                 1336 	mov	a,r6
   044B 4F                 1337 	orl	a,r7
   044C 70 F7              1338 	jnz	00103$
                           1339 ;	eeprom_read_mark.c:54: readmarkeeprom();
   044E 12 02 32           1340 	lcall	_readmarkeeprom
                           1341 ;	eeprom_read_mark.c:55: for(n=0;n<32;n++) dat[n] = (xdata char)HWmark[n];
   0451 7E 00              1342 	mov	r6,#0x00
   0453 7F 00              1343 	mov	r7,#0x00
   0455                    1344 00104$:
   0455 C3                 1345 	clr	c
   0456 EE                 1346 	mov	a,r6
   0457 94 20              1347 	subb	a,#0x20
   0459 EF                 1348 	mov	a,r7
   045A 64 80              1349 	xrl	a,#0x80
   045C 94 80              1350 	subb	a,#0x80
   045E 50 20              1351 	jnc	00107$
   0460 EE                 1352 	mov	a,r6
   0461 25 0A              1353 	add	a,_dat
   0463 FC                 1354 	mov	r4,a
   0464 EF                 1355 	mov	a,r7
   0465 35 0B              1356 	addc	a,(_dat + 1)
   0467 FD                 1357 	mov	r5,a
   0468 EE                 1358 	mov	a,r6
   0469 25 0E              1359 	add	a,_HWmark
   046B F5 82              1360 	mov	dpl,a
   046D EF                 1361 	mov	a,r7
   046E 35 0F              1362 	addc	a,(_HWmark + 1)
   0470 F5 83              1363 	mov	dph,a
   0472 E0                 1364 	movx	a,@dptr
   0473 FB                 1365 	mov	r3,a
   0474 8C 82              1366 	mov	dpl,r4
   0476 8D 83              1367 	mov	dph,r5
   0478 F0                 1368 	movx	@dptr,a
   0479 0E                 1369 	inc	r6
   047A BE 00 D8           1370 	cjne	r6,#0x00,00104$
   047D 0F                 1371 	inc	r7
   047E 80 D5              1372 	sjmp	00104$
   0480                    1373 00107$:
                           1374 ;	eeprom_read_mark.c:57: hostreadmarkep1init();
   0480 12 02 87           1375 	lcall	_hostreadmarkep1init
   0483                    1376 00109$:
                           1377 ;	eeprom_read_mark.c:58: for(;;) hostreadmarkep1poll();	
   0483 12 02 9E           1378 	lcall	_hostreadmarkep1poll
   0486 80 FB              1379 	sjmp	00109$
                           1380 	.area CSEG    (CODE)
                           1381 	.area CONST   (CODE)
   0540                    1382 __str_0:
   0540 67 65 74 48 57     1383 	.ascii "getHW"
   0545 00                 1384 	.db 0x00
   0546                    1385 __str_1:
   0546 67 65 74 46 57     1386 	.ascii "getFW"
   054B 00                 1387 	.db 0x00
   054C                    1388 __str_2:
   054C 46 57 45 45 50 52  1389 	.ascii "FWEEPRv000.001"
        76 30 30 30 2E 30
        30 31
   055A 00                 1390 	.db 0x00
                           1391 	.area XINIT   (CODE)
                           1392 	.area CABS    (ABS,CODE)
