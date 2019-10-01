                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.2.0 #8008 (Jul  6 2012) (MINGW32)
                              4 ; This file was generated Thu Apr 23 07:09:04 2015
                              5 ;--------------------------------------------------------
                              6 	.module convert_serial
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
   0043 02 07 28            643 	ljmp	_USB_isr
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
                            657 ;	convert_serial.c:114: char * USB_strings[] = { "EN", "freesoft.org", "FX2 case converter" };
   00D2 75 0A 11            658 	mov	(_USB_strings + 0),#__str_0
   00D5 75 0B 09            659 	mov	(_USB_strings + 1),#(__str_0 >> 8)
   00D8 75 0C 80            660 	mov	(_USB_strings + 2),#0x80
   00DB 75 0D 14            661 	mov	((_USB_strings + 0x0003) + 0),#__str_1
   00DE 75 0E 09            662 	mov	((_USB_strings + 0x0003) + 1),#(__str_1 >> 8)
   00E1 75 0F 80            663 	mov	((_USB_strings + 0x0003) + 2),#0x80
   00E4 75 10 21            664 	mov	((_USB_strings + 0x0006) + 0),#__str_2
   00E7 75 11 09            665 	mov	((_USB_strings + 0x0006) + 1),#(__str_2 >> 8)
   00EA 75 12 80            666 	mov	((_USB_strings + 0x0006) + 2),#0x80
                            667 ;	convert_serial.c:498: unsigned int bytes_waiting_for_xmit = 0;
   00ED E4                  668 	clr	a
   00EE F5 15               669 	mov	_bytes_waiting_for_xmit,a
   00F0 F5 16               670 	mov	(_bytes_waiting_for_xmit + 1),a
                            671 ;	convert_serial.c:499: unsigned int latency_us = 40000;
   00F2 75 17 40            672 	mov	_latency_us,#0x40
   00F5 75 18 9C            673 	mov	(_latency_us + 1),#0x9C
                            674 ;	convert_serial.c:47: BOOL Rwuen_allowed = FALSE;	// Allow remote wakeup to be enabled
   00F8 C2 00               675 	clr	_Rwuen_allowed
                            676 ;	convert_serial.c:48: BOOL Rwuen = FALSE;		// Remote wakeup enable
   00FA C2 01               677 	clr	_Rwuen
                            678 ;	convert_serial.c:49: BOOL Selfpwr = FALSE;		// Device is (not) self-powered
   00FC C2 02               679 	clr	_Selfpwr
                            680 ;	convert_serial.c:132: DEVICEDSCR xdata at 0x3d00 myDeviceDscr = {
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
   0129 74 B4               704 	mov	a,#0xB4
   012B F0                  705 	movx	@dptr,a
   012C A3                  706 	inc	dptr
   012D 74 04               707 	mov	a,#0x04
   012F F0                  708 	movx	@dptr,a
   0130 90 3D 0A            709 	mov	dptr,#(_myDeviceDscr + 0x000a)
   0133 74 13               710 	mov	a,#0x13
   0135 F0                  711 	movx	@dptr,a
   0136 A3                  712 	inc	dptr
   0137 74 86               713 	mov	a,#0x86
   0139 F0                  714 	movx	@dptr,a
   013A 90 3D 0C            715 	mov	dptr,#(_myDeviceDscr + 0x000c)
   013D E4                  716 	clr	a
   013E F0                  717 	movx	@dptr,a
   013F A3                  718 	inc	dptr
   0140 74 01               719 	mov	a,#0x01
   0142 F0                  720 	movx	@dptr,a
   0143 90 3D 0E            721 	mov	dptr,#(_myDeviceDscr + 0x000e)
   0146 74 01               722 	mov	a,#0x01
   0148 F0                  723 	movx	@dptr,a
   0149 90 3D 0F            724 	mov	dptr,#(_myDeviceDscr + 0x000f)
   014C 74 02               725 	mov	a,#0x02
   014E F0                  726 	movx	@dptr,a
   014F 90 3D 10            727 	mov	dptr,#(_myDeviceDscr + 0x0010)
   0152 E4                  728 	clr	a
   0153 F0                  729 	movx	@dptr,a
   0154 90 3D 11            730 	mov	dptr,#(_myDeviceDscr + 0x0011)
   0157 74 01               731 	mov	a,#0x01
   0159 F0                  732 	movx	@dptr,a
                            733 ;	convert_serial.c:159: DEVICEQUALDSCR xdata at 0x3d20 myDeviceQualDscr = {
   015A 90 3D 20            734 	mov	dptr,#_myDeviceQualDscr
   015D 74 0A               735 	mov	a,#0x0A
   015F F0                  736 	movx	@dptr,a
   0160 90 3D 21            737 	mov	dptr,#(_myDeviceQualDscr + 0x0001)
   0163 74 06               738 	mov	a,#0x06
   0165 F0                  739 	movx	@dptr,a
   0166 90 3D 22            740 	mov	dptr,#(_myDeviceQualDscr + 0x0002)
   0169 E4                  741 	clr	a
   016A F0                  742 	movx	@dptr,a
   016B A3                  743 	inc	dptr
   016C 74 02               744 	mov	a,#0x02
   016E F0                  745 	movx	@dptr,a
   016F 90 3D 24            746 	mov	dptr,#(_myDeviceQualDscr + 0x0004)
   0172 E4                  747 	clr	a
   0173 F0                  748 	movx	@dptr,a
   0174 90 3D 25            749 	mov	dptr,#(_myDeviceQualDscr + 0x0005)
   0177 F0                  750 	movx	@dptr,a
   0178 90 3D 26            751 	mov	dptr,#(_myDeviceQualDscr + 0x0006)
   017B F0                  752 	movx	@dptr,a
   017C 90 3D 27            753 	mov	dptr,#(_myDeviceQualDscr + 0x0007)
   017F 74 40               754 	mov	a,#0x40
   0181 F0                  755 	movx	@dptr,a
   0182 90 3D 28            756 	mov	dptr,#(_myDeviceQualDscr + 0x0008)
   0185 74 01               757 	mov	a,#0x01
   0187 F0                  758 	movx	@dptr,a
                            759 ;	convert_serial.c:177: CONFIGDSCR xdata at 0x3d30 myConfigDscr = {
   0188 90 3D 30            760 	mov	dptr,#_myConfigDscr
   018B 74 09               761 	mov	a,#0x09
   018D F0                  762 	movx	@dptr,a
   018E 90 3D 31            763 	mov	dptr,#(_myConfigDscr + 0x0001)
   0191 74 02               764 	mov	a,#0x02
   0193 F0                  765 	movx	@dptr,a
   0194 90 3D 32            766 	mov	dptr,#(_myConfigDscr + 0x0002)
   0197 74 20               767 	mov	a,#0x20
   0199 F0                  768 	movx	@dptr,a
   019A A3                  769 	inc	dptr
   019B E4                  770 	clr	a
   019C F0                  771 	movx	@dptr,a
   019D 90 3D 34            772 	mov	dptr,#(_myConfigDscr + 0x0004)
   01A0 74 01               773 	mov	a,#0x01
   01A2 F0                  774 	movx	@dptr,a
   01A3 90 3D 35            775 	mov	dptr,#(_myConfigDscr + 0x0005)
   01A6 74 01               776 	mov	a,#0x01
   01A8 F0                  777 	movx	@dptr,a
   01A9 90 3D 36            778 	mov	dptr,#(_myConfigDscr + 0x0006)
   01AC E4                  779 	clr	a
   01AD F0                  780 	movx	@dptr,a
   01AE 90 3D 37            781 	mov	dptr,#(_myConfigDscr + 0x0007)
   01B1 74 A0               782 	mov	a,#0xA0
   01B3 F0                  783 	movx	@dptr,a
   01B4 90 3D 38            784 	mov	dptr,#(_myConfigDscr + 0x0008)
   01B7 74 1E               785 	mov	a,#0x1E
   01B9 F0                  786 	movx	@dptr,a
                            787 ;	convert_serial.c:188: INTRFCDSCR xdata at 0x3d30+DSCR_OFFSET(0,0) myIntrfcDscr = {
   01BA 90 3D 39            788 	mov	dptr,#_myIntrfcDscr
   01BD 74 09               789 	mov	a,#0x09
   01BF F0                  790 	movx	@dptr,a
   01C0 90 3D 3A            791 	mov	dptr,#(_myIntrfcDscr + 0x0001)
   01C3 74 04               792 	mov	a,#0x04
   01C5 F0                  793 	movx	@dptr,a
   01C6 90 3D 3B            794 	mov	dptr,#(_myIntrfcDscr + 0x0002)
   01C9 E4                  795 	clr	a
   01CA F0                  796 	movx	@dptr,a
   01CB 90 3D 3C            797 	mov	dptr,#(_myIntrfcDscr + 0x0003)
   01CE F0                  798 	movx	@dptr,a
   01CF 90 3D 3D            799 	mov	dptr,#(_myIntrfcDscr + 0x0004)
   01D2 74 02               800 	mov	a,#0x02
   01D4 F0                  801 	movx	@dptr,a
   01D5 90 3D 3E            802 	mov	dptr,#(_myIntrfcDscr + 0x0005)
   01D8 74 FF               803 	mov	a,#0xFF
   01DA F0                  804 	movx	@dptr,a
   01DB 90 3D 3F            805 	mov	dptr,#(_myIntrfcDscr + 0x0006)
   01DE 74 FF               806 	mov	a,#0xFF
   01E0 F0                  807 	movx	@dptr,a
   01E1 90 3D 40            808 	mov	dptr,#(_myIntrfcDscr + 0x0007)
   01E4 74 FF               809 	mov	a,#0xFF
   01E6 F0                  810 	movx	@dptr,a
   01E7 90 3D 41            811 	mov	dptr,#(_myIntrfcDscr + 0x0008)
   01EA E4                  812 	clr	a
   01EB F0                  813 	movx	@dptr,a
                            814 ;	convert_serial.c:200: ENDPNTDSCR xdata at 0x3d30+DSCR_OFFSET(1,0) myInEndpntDscr = {
   01EC 90 3D 42            815 	mov	dptr,#_myInEndpntDscr
   01EF 74 07               816 	mov	a,#0x07
   01F1 F0                  817 	movx	@dptr,a
   01F2 90 3D 43            818 	mov	dptr,#(_myInEndpntDscr + 0x0001)
   01F5 74 05               819 	mov	a,#0x05
   01F7 F0                  820 	movx	@dptr,a
   01F8 90 3D 44            821 	mov	dptr,#(_myInEndpntDscr + 0x0002)
   01FB 74 81               822 	mov	a,#0x81
   01FD F0                  823 	movx	@dptr,a
   01FE 90 3D 45            824 	mov	dptr,#(_myInEndpntDscr + 0x0003)
   0201 74 02               825 	mov	a,#0x02
   0203 F0                  826 	movx	@dptr,a
   0204 90 3D 46            827 	mov	dptr,#(_myInEndpntDscr + 0x0004)
   0207 E4                  828 	clr	a
   0208 F0                  829 	movx	@dptr,a
   0209 A3                  830 	inc	dptr
   020A 74 02               831 	mov	a,#0x02
   020C F0                  832 	movx	@dptr,a
   020D 90 3D 48            833 	mov	dptr,#(_myInEndpntDscr + 0x0006)
   0210 E4                  834 	clr	a
   0211 F0                  835 	movx	@dptr,a
                            836 ;	convert_serial.c:210: ENDPNTDSCR xdata at 0x3d30+DSCR_OFFSET(1,1) myOutEndpntDscr = {
   0212 90 3D 49            837 	mov	dptr,#_myOutEndpntDscr
   0215 74 07               838 	mov	a,#0x07
   0217 F0                  839 	movx	@dptr,a
   0218 90 3D 4A            840 	mov	dptr,#(_myOutEndpntDscr + 0x0001)
   021B 74 05               841 	mov	a,#0x05
   021D F0                  842 	movx	@dptr,a
   021E 90 3D 4B            843 	mov	dptr,#(_myOutEndpntDscr + 0x0002)
   0221 74 01               844 	mov	a,#0x01
   0223 F0                  845 	movx	@dptr,a
   0224 90 3D 4C            846 	mov	dptr,#(_myOutEndpntDscr + 0x0003)
   0227 74 02               847 	mov	a,#0x02
   0229 F0                  848 	movx	@dptr,a
   022A 90 3D 4D            849 	mov	dptr,#(_myOutEndpntDscr + 0x0004)
   022D E4                  850 	clr	a
   022E F0                  851 	movx	@dptr,a
   022F A3                  852 	inc	dptr
   0230 74 02               853 	mov	a,#0x02
   0232 F0                  854 	movx	@dptr,a
   0233 90 3D 4F            855 	mov	dptr,#(_myOutEndpntDscr + 0x0006)
   0236 E4                  856 	clr	a
   0237 F0                  857 	movx	@dptr,a
                            858 	.area GSFINAL (CODE)
   0238 02 00 46            859 	ljmp	__sdcc_program_startup
                            860 ;--------------------------------------------------------
                            861 ; Home
                            862 ;--------------------------------------------------------
                            863 	.area HOME    (CODE)
                            864 	.area HOME    (CODE)
   0046                     865 __sdcc_program_startup:
   0046 12 08 BE            866 	lcall	_main
                            867 ;	return from main will lock up
   0049 80 FE               868 	sjmp .
                            869 ;--------------------------------------------------------
                            870 ; code
                            871 ;--------------------------------------------------------
                            872 	.area CSEG    (CODE)
                            873 ;------------------------------------------------------------
                            874 ;Allocation info for local variables in function 'count_array_size'
                            875 ;------------------------------------------------------------
                            876 ;array                     Allocated to registers 
                            877 ;size                      Allocated to registers r3 r4 
                            878 ;------------------------------------------------------------
                            879 ;	convert_serial.c:224: static int count_array_size(void ** array)
                            880 ;	-----------------------------------------
                            881 ;	 function count_array_size
                            882 ;	-----------------------------------------
   023B                     883 _count_array_size:
                    0007    884 	ar7 = 0x07
                    0006    885 	ar6 = 0x06
                    0005    886 	ar5 = 0x05
                    0004    887 	ar4 = 0x04
                    0003    888 	ar3 = 0x03
                    0002    889 	ar2 = 0x02
                    0001    890 	ar1 = 0x01
                    0000    891 	ar0 = 0x00
   023B AD 82               892 	mov	r5,dpl
   023D AE 83               893 	mov	r6,dph
   023F AF F0               894 	mov	r7,b
                            895 ;	convert_serial.c:227: for (size=0; *array != 0; array++, size++);
   0241 7B 00               896 	mov	r3,#0x00
   0243 7C 00               897 	mov	r4,#0x00
   0245                     898 00101$:
   0245 8D 82               899 	mov	dpl,r5
   0247 8E 83               900 	mov	dph,r6
   0249 8F F0               901 	mov	b,r7
   024B 12 08 E7            902 	lcall	__gptrget
   024E F8                  903 	mov	r0,a
   024F A3                  904 	inc	dptr
   0250 12 08 E7            905 	lcall	__gptrget
   0253 F9                  906 	mov	r1,a
   0254 A3                  907 	inc	dptr
   0255 12 08 E7            908 	lcall	__gptrget
   0258 FA                  909 	mov	r2,a
   0259 E4                  910 	clr	a
   025A C0 E0               911 	push	acc
   025C E4                  912 	clr	a
   025D C0 E0               913 	push	acc
   025F E4                  914 	clr	a
   0260 C0 E0               915 	push	acc
   0262 88 82               916 	mov	dpl,r0
   0264 89 83               917 	mov	dph,r1
   0266 8A F0               918 	mov	b,r2
   0268 12 00 4B            919 	lcall	___gptr_cmp
   026B 15 81               920 	dec	sp
   026D 15 81               921 	dec	sp
   026F 15 81               922 	dec	sp
   0271 60 0E               923 	jz	00104$
   0273 74 03               924 	mov	a,#0x03
   0275 2D                  925 	add	a,r5
   0276 FD                  926 	mov	r5,a
   0277 E4                  927 	clr	a
   0278 3E                  928 	addc	a,r6
   0279 FE                  929 	mov	r6,a
   027A 0B                  930 	inc	r3
   027B BB 00 C7            931 	cjne	r3,#0x00,00101$
   027E 0C                  932 	inc	r4
   027F 80 C4               933 	sjmp	00101$
   0281                     934 00104$:
                            935 ;	convert_serial.c:228: return size;
   0281 8B 82               936 	mov	dpl,r3
   0283 8C 83               937 	mov	dph,r4
   0285 22                  938 	ret
                            939 ;------------------------------------------------------------
                            940 ;Allocation info for local variables in function 'SetupCommand'
                            941 ;------------------------------------------------------------
                            942 ;i                         Allocated with name '_SetupCommand_i_1_21'
                            943 ;interface                 Allocated to registers r6 r7 
                            944 ;------------------------------------------------------------
                            945 ;	convert_serial.c:231: static void SetupCommand(void)
                            946 ;	-----------------------------------------
                            947 ;	 function SetupCommand
                            948 ;	-----------------------------------------
   0286                     949 _SetupCommand:
                            950 ;	convert_serial.c:238: switch(SETUPDAT[0] & SETUP_MASK) {
   0286 90 E6 B8            951 	mov	dptr,#_SETUPDAT
   0289 E0                  952 	movx	a,@dptr
   028A FF                  953 	mov	r7,a
   028B 53 07 60            954 	anl	ar7,#0x60
   028E BF 00 02            955 	cjne	r7,#0x00,00222$
   0291 80 03               956 	sjmp	00223$
   0293                     957 00222$:
   0293 02 07 18            958 	ljmp	00163$
   0296                     959 00223$:
                            960 ;	convert_serial.c:241: switch(SETUPDAT[1])
   0296 90 E6 B9            961 	mov	dptr,#(_SETUPDAT + 0x0001)
   0299 E0                  962 	movx	a,@dptr
   029A FF                  963 	mov  r7,a
   029B 24 F4               964 	add	a,#0xff - 0x0B
   029D 50 03               965 	jnc	00224$
   029F 02 07 0E            966 	ljmp	00161$
   02A2                     967 00224$:
   02A2 EF                  968 	mov	a,r7
   02A3 2F                  969 	add	a,r7
   02A4 2F                  970 	add	a,r7
   02A5 90 02 A9            971 	mov	dptr,#00225$
   02A8 73                  972 	jmp	@a+dptr
   02A9                     973 00225$:
   02A9 02 05 1B            974 	ljmp	00133$
   02AC 02 05 BD            975 	ljmp	00139$
   02AF 02 07 0E            976 	ljmp	00161$
   02B2 02 06 74            977 	ljmp	00149$
   02B5 02 07 0E            978 	ljmp	00161$
   02B8 02 07 0E            979 	ljmp	00161$
   02BB 02 02 CD            980 	ljmp	00102$
   02BE 02 07 0E            981 	ljmp	00161$
   02C1 02 05 07            982 	ljmp	00132$
   02C4 02 04 FE            983 	ljmp	00131$
   02C7 02 04 AD            984 	ljmp	00125$
   02CA 02 04 DB            985 	ljmp	00128$
                            986 ;	convert_serial.c:243: case SC_GET_DESCRIPTOR:
   02CD                     987 00102$:
                            988 ;	convert_serial.c:244: switch(SETUPDAT[3])
   02CD 90 E6 BB            989 	mov	dptr,#(_SETUPDAT + 0x0003)
   02D0 E0                  990 	movx	a,@dptr
   02D1 FF                  991 	mov	r7,a
   02D2 BF 01 02            992 	cjne	r7,#0x01,00226$
   02D5 80 19               993 	sjmp	00103$
   02D7                     994 00226$:
   02D7 BF 02 02            995 	cjne	r7,#0x02,00227$
   02DA 80 46               996 	sjmp	00105$
   02DC                     997 00227$:
   02DC BF 03 03            998 	cjne	r7,#0x03,00228$
   02DF 02 03 BC            999 	ljmp	00113$
   02E2                    1000 00228$:
   02E2 BF 06 02           1001 	cjne	r7,#0x06,00229$
   02E5 80 22              1002 	sjmp	00104$
   02E7                    1003 00229$:
   02E7 BF 07 03           1004 	cjne	r7,#0x07,00230$
   02EA 02 03 6F           1005 	ljmp	00109$
   02ED                    1006 00230$:
   02ED 02 04 A2           1007 	ljmp	00123$
                           1008 ;	convert_serial.c:246: case GD_DEVICE:
   02F0                    1009 00103$:
                           1010 ;	convert_serial.c:247: SUDPTRH = MSB(&myDeviceDscr);
   02F0 7E 00              1011 	mov	r6,#_myDeviceDscr
   02F2 7F 3D              1012 	mov	r7,#(_myDeviceDscr >> 8)
   02F4 8F 06              1013 	mov	ar6,r7
   02F6 90 E6 B3           1014 	mov	dptr,#_SUDPTRH
   02F9 EE                 1015 	mov	a,r6
   02FA F0                 1016 	movx	@dptr,a
                           1017 ;	convert_serial.c:248: SUDPTRL = LSB(&myDeviceDscr);
   02FB 7E 00              1018 	mov	r6,#_myDeviceDscr
   02FD 7F 3D              1019 	mov	r7,#(_myDeviceDscr >> 8)
   02FF 7F 00              1020 	mov	r7,#0x00
   0301 90 E6 B4           1021 	mov	dptr,#_SUDPTRL
   0304 EE                 1022 	mov	a,r6
   0305 F0                 1023 	movx	@dptr,a
                           1024 ;	convert_serial.c:249: break;
   0306 02 07 20           1025 	ljmp	00164$
                           1026 ;	convert_serial.c:250: case GD_DEVICE_QUALIFIER:
   0309                    1027 00104$:
                           1028 ;	convert_serial.c:251: SUDPTRH = MSB(&myDeviceQualDscr);
   0309 7E 20              1029 	mov	r6,#_myDeviceQualDscr
   030B 7F 3D              1030 	mov	r7,#(_myDeviceQualDscr >> 8)
   030D 8F 06              1031 	mov	ar6,r7
   030F 90 E6 B3           1032 	mov	dptr,#_SUDPTRH
   0312 EE                 1033 	mov	a,r6
   0313 F0                 1034 	movx	@dptr,a
                           1035 ;	convert_serial.c:252: SUDPTRL = LSB(&myDeviceQualDscr);
   0314 7E 20              1036 	mov	r6,#_myDeviceQualDscr
   0316 7F 3D              1037 	mov	r7,#(_myDeviceQualDscr >> 8)
   0318 7F 00              1038 	mov	r7,#0x00
   031A 90 E6 B4           1039 	mov	dptr,#_SUDPTRL
   031D EE                 1040 	mov	a,r6
   031E F0                 1041 	movx	@dptr,a
                           1042 ;	convert_serial.c:253: break;
   031F 02 07 20           1043 	ljmp	00164$
                           1044 ;	convert_serial.c:254: case GD_CONFIGURATION:
   0322                    1045 00105$:
                           1046 ;	convert_serial.c:255: myConfigDscr.type = CONFIG_DSCR;
   0322 90 3D 31           1047 	mov	dptr,#(_myConfigDscr + 0x0001)
   0325 74 02              1048 	mov	a,#0x02
   0327 F0                 1049 	movx	@dptr,a
                           1050 ;	convert_serial.c:256: if (USBCS & bmHSM) {
   0328 90 E6 80           1051 	mov	dptr,#_USBCS
   032B E0                 1052 	movx	a,@dptr
   032C FF                 1053 	mov	r7,a
   032D 30 E7 14           1054 	jnb	acc.7,00107$
                           1055 ;	convert_serial.c:258: myInEndpntDscr.mp = 64;
   0330 90 3D 46           1056 	mov	dptr,#(_myInEndpntDscr + 0x0004)
   0333 74 40              1057 	mov	a,#0x40
   0335 F0                 1058 	movx	@dptr,a
   0336 A3                 1059 	inc	dptr
   0337 E4                 1060 	clr	a
   0338 F0                 1061 	movx	@dptr,a
                           1062 ;	convert_serial.c:259: myOutEndpntDscr.mp = 64;
   0339 90 3D 4D           1063 	mov	dptr,#(_myOutEndpntDscr + 0x0004)
   033C 74 40              1064 	mov	a,#0x40
   033E F0                 1065 	movx	@dptr,a
   033F A3                 1066 	inc	dptr
   0340 E4                 1067 	clr	a
   0341 F0                 1068 	movx	@dptr,a
   0342 80 12              1069 	sjmp	00108$
   0344                    1070 00107$:
                           1071 ;	convert_serial.c:262: myInEndpntDscr.mp = 64;
   0344 90 3D 46           1072 	mov	dptr,#(_myInEndpntDscr + 0x0004)
   0347 74 40              1073 	mov	a,#0x40
   0349 F0                 1074 	movx	@dptr,a
   034A A3                 1075 	inc	dptr
   034B E4                 1076 	clr	a
   034C F0                 1077 	movx	@dptr,a
                           1078 ;	convert_serial.c:263: myOutEndpntDscr.mp = 64;
   034D 90 3D 4D           1079 	mov	dptr,#(_myOutEndpntDscr + 0x0004)
   0350 74 40              1080 	mov	a,#0x40
   0352 F0                 1081 	movx	@dptr,a
   0353 A3                 1082 	inc	dptr
   0354 E4                 1083 	clr	a
   0355 F0                 1084 	movx	@dptr,a
   0356                    1085 00108$:
                           1086 ;	convert_serial.c:265: SUDPTRH = MSB(&myConfigDscr);
   0356 7E 30              1087 	mov	r6,#_myConfigDscr
   0358 7F 3D              1088 	mov	r7,#(_myConfigDscr >> 8)
   035A 8F 06              1089 	mov	ar6,r7
   035C 90 E6 B3           1090 	mov	dptr,#_SUDPTRH
   035F EE                 1091 	mov	a,r6
   0360 F0                 1092 	movx	@dptr,a
                           1093 ;	convert_serial.c:266: SUDPTRL = LSB(&myConfigDscr);
   0361 7E 30              1094 	mov	r6,#_myConfigDscr
   0363 7F 3D              1095 	mov	r7,#(_myConfigDscr >> 8)
   0365 7F 00              1096 	mov	r7,#0x00
   0367 90 E6 B4           1097 	mov	dptr,#_SUDPTRL
   036A EE                 1098 	mov	a,r6
   036B F0                 1099 	movx	@dptr,a
                           1100 ;	convert_serial.c:267: break;
   036C 02 07 20           1101 	ljmp	00164$
                           1102 ;	convert_serial.c:268: case GD_OTHER_SPEED_CONFIGURATION:
   036F                    1103 00109$:
                           1104 ;	convert_serial.c:269: myConfigDscr.type = OTHERSPEED_DSCR;
   036F 90 3D 31           1105 	mov	dptr,#(_myConfigDscr + 0x0001)
   0372 74 07              1106 	mov	a,#0x07
   0374 F0                 1107 	movx	@dptr,a
                           1108 ;	convert_serial.c:270: if (USBCS & bmHSM) {
   0375 90 E6 80           1109 	mov	dptr,#_USBCS
   0378 E0                 1110 	movx	a,@dptr
   0379 FF                 1111 	mov	r7,a
   037A 30 E7 14           1112 	jnb	acc.7,00111$
                           1113 ;	convert_serial.c:273: myInEndpntDscr.mp = 64;
   037D 90 3D 46           1114 	mov	dptr,#(_myInEndpntDscr + 0x0004)
   0380 74 40              1115 	mov	a,#0x40
   0382 F0                 1116 	movx	@dptr,a
   0383 A3                 1117 	inc	dptr
   0384 E4                 1118 	clr	a
   0385 F0                 1119 	movx	@dptr,a
                           1120 ;	convert_serial.c:274: myOutEndpntDscr.mp = 64;
   0386 90 3D 4D           1121 	mov	dptr,#(_myOutEndpntDscr + 0x0004)
   0389 74 40              1122 	mov	a,#0x40
   038B F0                 1123 	movx	@dptr,a
   038C A3                 1124 	inc	dptr
   038D E4                 1125 	clr	a
   038E F0                 1126 	movx	@dptr,a
   038F 80 12              1127 	sjmp	00112$
   0391                    1128 00111$:
                           1129 ;	convert_serial.c:278: myInEndpntDscr.mp = 64;
   0391 90 3D 46           1130 	mov	dptr,#(_myInEndpntDscr + 0x0004)
   0394 74 40              1131 	mov	a,#0x40
   0396 F0                 1132 	movx	@dptr,a
   0397 A3                 1133 	inc	dptr
   0398 E4                 1134 	clr	a
   0399 F0                 1135 	movx	@dptr,a
                           1136 ;	convert_serial.c:279: myOutEndpntDscr.mp = 64;
   039A 90 3D 4D           1137 	mov	dptr,#(_myOutEndpntDscr + 0x0004)
   039D 74 40              1138 	mov	a,#0x40
   039F F0                 1139 	movx	@dptr,a
   03A0 A3                 1140 	inc	dptr
   03A1 E4                 1141 	clr	a
   03A2 F0                 1142 	movx	@dptr,a
   03A3                    1143 00112$:
                           1144 ;	convert_serial.c:281: SUDPTRH = MSB(&myConfigDscr);
   03A3 7E 30              1145 	mov	r6,#_myConfigDscr
   03A5 7F 3D              1146 	mov	r7,#(_myConfigDscr >> 8)
   03A7 8F 06              1147 	mov	ar6,r7
   03A9 90 E6 B3           1148 	mov	dptr,#_SUDPTRH
   03AC EE                 1149 	mov	a,r6
   03AD F0                 1150 	movx	@dptr,a
                           1151 ;	convert_serial.c:282: SUDPTRL = LSB(&myConfigDscr);
   03AE 7E 30              1152 	mov	r6,#_myConfigDscr
   03B0 7F 3D              1153 	mov	r7,#(_myConfigDscr >> 8)
   03B2 7F 00              1154 	mov	r7,#0x00
   03B4 90 E6 B4           1155 	mov	dptr,#_SUDPTRL
   03B7 EE                 1156 	mov	a,r6
   03B8 F0                 1157 	movx	@dptr,a
                           1158 ;	convert_serial.c:283: break;
   03B9 02 07 20           1159 	ljmp	00164$
                           1160 ;	convert_serial.c:284: case GD_STRING:
   03BC                    1161 00113$:
                           1162 ;	convert_serial.c:285: if (SETUPDAT[2] >= count_array_size((void **) USB_strings)) {
   03BC 90 E6 BA           1163 	mov	dptr,#(_SETUPDAT + 0x0002)
   03BF E0                 1164 	movx	a,@dptr
   03C0 FF                 1165 	mov	r7,a
   03C1 90 00 0A           1166 	mov	dptr,#_USB_strings
   03C4 75 F0 40           1167 	mov	b,#0x40
   03C7 C0 07              1168 	push	ar7
   03C9 12 02 3B           1169 	lcall	_count_array_size
   03CC AD 82              1170 	mov	r5,dpl
   03CE AE 83              1171 	mov	r6,dph
   03D0 D0 07              1172 	pop	ar7
   03D2 7C 00              1173 	mov	r4,#0x00
   03D4 C3                 1174 	clr	c
   03D5 EF                 1175 	mov	a,r7
   03D6 9D                 1176 	subb	a,r5
   03D7 EC                 1177 	mov	a,r4
   03D8 64 80              1178 	xrl	a,#0x80
   03DA 8E F0              1179 	mov	b,r6
   03DC 63 F0 80           1180 	xrl	b,#0x80
   03DF 95 F0              1181 	subb	a,b
   03E1 40 0B              1182 	jc	00179$
                           1183 ;	convert_serial.c:286: EZUSB_STALL_EP0();
   03E3 90 E6 A0           1184 	mov	dptr,#_EP0CS
   03E6 E0                 1185 	movx	a,@dptr
   03E7 FF                 1186 	mov	r7,a
   03E8 44 01              1187 	orl	a,#0x01
   03EA F0                 1188 	movx	@dptr,a
   03EB 02 07 20           1189 	ljmp	00164$
                           1190 ;	convert_serial.c:288: for (i=0; i<31; i++) {
   03EE                    1191 00179$:
   03EE E4                 1192 	clr	a
   03EF F5 13              1193 	mov	_SetupCommand_i_1_21,a
   03F1 F5 14              1194 	mov	(_SetupCommand_i_1_21 + 1),a
   03F3                    1195 00116$:
   03F3 C3                 1196 	clr	c
   03F4 E5 13              1197 	mov	a,_SetupCommand_i_1_21
   03F6 94 1F              1198 	subb	a,#0x1F
   03F8 E5 14              1199 	mov	a,(_SetupCommand_i_1_21 + 1)
   03FA 64 80              1200 	xrl	a,#0x80
   03FC 94 80              1201 	subb	a,#0x80
   03FE 50 7B              1202 	jnc	00119$
                           1203 ;	convert_serial.c:289: if (USB_strings[SETUPDAT[2]][i] == '\0') break;
   0400 90 E6 BA           1204 	mov	dptr,#(_SETUPDAT + 0x0002)
   0403 E0                 1205 	movx	a,@dptr
   0404 75 F0 03           1206 	mov	b,#0x03
   0407 A4                 1207 	mul	ab
   0408 24 0A              1208 	add	a,#_USB_strings
   040A F9                 1209 	mov	r1,a
   040B 87 03              1210 	mov	ar3,@r1
   040D 09                 1211 	inc	r1
   040E 87 04              1212 	mov	ar4,@r1
   0410 09                 1213 	inc	r1
   0411 87 05              1214 	mov	ar5,@r1
   0413 19                 1215 	dec	r1
   0414 19                 1216 	dec	r1
   0415 E5 13              1217 	mov	a,_SetupCommand_i_1_21
   0417 2B                 1218 	add	a,r3
   0418 FB                 1219 	mov	r3,a
   0419 E5 14              1220 	mov	a,(_SetupCommand_i_1_21 + 1)
   041B 3C                 1221 	addc	a,r4
   041C FC                 1222 	mov	r4,a
   041D 8B 82              1223 	mov	dpl,r3
   041F 8C 83              1224 	mov	dph,r4
   0421 8D F0              1225 	mov	b,r5
   0423 12 08 E7           1226 	lcall	__gptrget
   0426 60 53              1227 	jz	00119$
                           1228 ;	convert_serial.c:290: EP0BUF[2*i+2] = USB_strings[SETUPDAT[2]][i];
   0428 E5 13              1229 	mov	a,_SetupCommand_i_1_21
   042A 25 E0              1230 	add	a,acc
   042C FD                 1231 	mov	r5,a
   042D 24 02              1232 	add	a,#0x02
   042F 24 40              1233 	add	a,#_EP0BUF
   0431 FB                 1234 	mov	r3,a
   0432 E4                 1235 	clr	a
   0433 34 E7              1236 	addc	a,#(_EP0BUF >> 8)
   0435 FC                 1237 	mov	r4,a
   0436 90 E6 BA           1238 	mov	dptr,#(_SETUPDAT + 0x0002)
   0439 E0                 1239 	movx	a,@dptr
   043A 75 F0 03           1240 	mov	b,#0x03
   043D A4                 1241 	mul	ab
   043E 24 0A              1242 	add	a,#_USB_strings
   0440 F9                 1243 	mov	r1,a
   0441 87 02              1244 	mov	ar2,@r1
   0443 09                 1245 	inc	r1
   0444 87 06              1246 	mov	ar6,@r1
   0446 09                 1247 	inc	r1
   0447 87 07              1248 	mov	ar7,@r1
   0449 19                 1249 	dec	r1
   044A 19                 1250 	dec	r1
   044B E5 13              1251 	mov	a,_SetupCommand_i_1_21
   044D 2A                 1252 	add	a,r2
   044E FA                 1253 	mov	r2,a
   044F E5 14              1254 	mov	a,(_SetupCommand_i_1_21 + 1)
   0451 3E                 1255 	addc	a,r6
   0452 FE                 1256 	mov	r6,a
   0453 8A 82              1257 	mov	dpl,r2
   0455 8E 83              1258 	mov	dph,r6
   0457 8F F0              1259 	mov	b,r7
   0459 12 08 E7           1260 	lcall	__gptrget
   045C FA                 1261 	mov	r2,a
   045D 8B 82              1262 	mov	dpl,r3
   045F 8C 83              1263 	mov	dph,r4
   0461 F0                 1264 	movx	@dptr,a
                           1265 ;	convert_serial.c:291: EP0BUF[2*i+3] = '\0';
   0462 74 03              1266 	mov	a,#0x03
   0464 2D                 1267 	add	a,r5
   0465 24 40              1268 	add	a,#_EP0BUF
   0467 F5 82              1269 	mov	dpl,a
   0469 E4                 1270 	clr	a
   046A 34 E7              1271 	addc	a,#(_EP0BUF >> 8)
   046C F5 83              1272 	mov	dph,a
   046E E4                 1273 	clr	a
   046F F0                 1274 	movx	@dptr,a
                           1275 ;	convert_serial.c:288: for (i=0; i<31; i++) {
   0470 05 13              1276 	inc	_SetupCommand_i_1_21
   0472 E4                 1277 	clr	a
   0473 B5 13 02           1278 	cjne	a,_SetupCommand_i_1_21,00236$
   0476 05 14              1279 	inc	(_SetupCommand_i_1_21 + 1)
   0478                    1280 00236$:
   0478 02 03 F3           1281 	ljmp	00116$
   047B                    1282 00119$:
                           1283 ;	convert_serial.c:293: EP0BUF[0] = 2*i+2;
   047B E5 13              1284 	mov	a,_SetupCommand_i_1_21
   047D 25 E0              1285 	add	a,acc
   047F FE                 1286 	mov	r6,a
   0480 0E                 1287 	inc	r6
   0481 0E                 1288 	inc	r6
   0482 90 E7 40           1289 	mov	dptr,#_EP0BUF
   0485 EE                 1290 	mov	a,r6
   0486 F0                 1291 	movx	@dptr,a
                           1292 ;	convert_serial.c:294: EP0BUF[1] = STRING_DSCR;
   0487 90 E7 41           1293 	mov	dptr,#(_EP0BUF + 0x0001)
   048A 74 03              1294 	mov	a,#0x03
   048C F0                 1295 	movx	@dptr,a
                           1296 ;	convert_serial.c:295: SYNCDELAY; EP0BCH = 0;
   048D 00                 1297 	nop 
   048E 00                 1298 	nop 
   048F 00                 1299 	nop 
   0490 00                 1300 	nop 
   0491 90 E6 8A           1301 	mov	dptr,#_EP0BCH
   0494 E4                 1302 	clr	a
   0495 F0                 1303 	movx	@dptr,a
                           1304 ;	convert_serial.c:296: SYNCDELAY; EP0BCL = 2*i+2;
   0496 00                 1305 	nop 
   0497 00                 1306 	nop 
   0498 00                 1307 	nop 
   0499 00                 1308 	nop 
   049A 90 E6 8B           1309 	mov	dptr,#_EP0BCL
   049D EE                 1310 	mov	a,r6
   049E F0                 1311 	movx	@dptr,a
                           1312 ;	convert_serial.c:298: break;
   049F 02 07 20           1313 	ljmp	00164$
                           1314 ;	convert_serial.c:299: default:            // Invalid request
   04A2                    1315 00123$:
                           1316 ;	convert_serial.c:300: EZUSB_STALL_EP0();
   04A2 90 E6 A0           1317 	mov	dptr,#_EP0CS
   04A5 E0                 1318 	movx	a,@dptr
   04A6 FF                 1319 	mov	r7,a
   04A7 44 01              1320 	orl	a,#0x01
   04A9 F0                 1321 	movx	@dptr,a
                           1322 ;	convert_serial.c:302: break;
   04AA 02 07 20           1323 	ljmp	00164$
                           1324 ;	convert_serial.c:303: case SC_GET_INTERFACE:
   04AD                    1325 00125$:
                           1326 ;	convert_serial.c:304: interface = SETUPDAT[4];
   04AD 90 E6 BC           1327 	mov	dptr,#(_SETUPDAT + 0x0004)
   04B0 E0                 1328 	movx	a,@dptr
   04B1 FE                 1329 	mov	r6,a
   04B2 7F 00              1330 	mov	r7,#0x00
                           1331 ;	convert_serial.c:305: if (interface < NUM_INTERFACES) {
   04B4 C3                 1332 	clr	c
   04B5 EE                 1333 	mov	a,r6
   04B6 94 01              1334 	subb	a,#0x01
   04B8 EF                 1335 	mov	a,r7
   04B9 64 80              1336 	xrl	a,#0x80
   04BB 94 80              1337 	subb	a,#0x80
   04BD 40 03              1338 	jc	00237$
   04BF 02 07 20           1339 	ljmp	00164$
   04C2                    1340 00237$:
                           1341 ;	convert_serial.c:306: EP0BUF[0] = InterfaceSetting[interface];
   04C2 EE                 1342 	mov	a,r6
   04C3 24 09              1343 	add	a,#_InterfaceSetting
   04C5 F9                 1344 	mov	r1,a
   04C6 87 05              1345 	mov	ar5,@r1
   04C8 90 E7 40           1346 	mov	dptr,#_EP0BUF
   04CB ED                 1347 	mov	a,r5
   04CC F0                 1348 	movx	@dptr,a
                           1349 ;	convert_serial.c:307: EP0BCH = 0;
   04CD 90 E6 8A           1350 	mov	dptr,#_EP0BCH
   04D0 E4                 1351 	clr	a
   04D1 F0                 1352 	movx	@dptr,a
                           1353 ;	convert_serial.c:308: EP0BCL = 1;
   04D2 90 E6 8B           1354 	mov	dptr,#_EP0BCL
   04D5 74 01              1355 	mov	a,#0x01
   04D7 F0                 1356 	movx	@dptr,a
                           1357 ;	convert_serial.c:310: break;
   04D8 02 07 20           1358 	ljmp	00164$
                           1359 ;	convert_serial.c:311: case SC_SET_INTERFACE:
   04DB                    1360 00128$:
                           1361 ;	convert_serial.c:312: interface = SETUPDAT[4];
   04DB 90 E6 BC           1362 	mov	dptr,#(_SETUPDAT + 0x0004)
   04DE E0                 1363 	movx	a,@dptr
   04DF FD                 1364 	mov	r5,a
   04E0 FE                 1365 	mov	r6,a
   04E1 7F 00              1366 	mov	r7,#0x00
                           1367 ;	convert_serial.c:313: if (interface < NUM_INTERFACES) {
   04E3 C3                 1368 	clr	c
   04E4 EE                 1369 	mov	a,r6
   04E5 94 01              1370 	subb	a,#0x01
   04E7 EF                 1371 	mov	a,r7
   04E8 64 80              1372 	xrl	a,#0x80
   04EA 94 80              1373 	subb	a,#0x80
   04EC 40 03              1374 	jc	00238$
   04EE 02 07 20           1375 	ljmp	00164$
   04F1                    1376 00238$:
                           1377 ;	convert_serial.c:314: InterfaceSetting[interface] = SETUPDAT[2];
   04F1 EE                 1378 	mov	a,r6
   04F2 24 09              1379 	add	a,#_InterfaceSetting
   04F4 F9                 1380 	mov	r1,a
   04F5 90 E6 BA           1381 	mov	dptr,#(_SETUPDAT + 0x0002)
   04F8 E0                 1382 	movx	a,@dptr
   04F9 FF                 1383 	mov	r7,a
   04FA F7                 1384 	mov	@r1,a
                           1385 ;	convert_serial.c:316: break;
   04FB 02 07 20           1386 	ljmp	00164$
                           1387 ;	convert_serial.c:317: case SC_SET_CONFIGURATION:
   04FE                    1388 00131$:
                           1389 ;	convert_serial.c:318: Configuration = SETUPDAT[2];
   04FE 90 E6 BA           1390 	mov	dptr,#(_SETUPDAT + 0x0002)
   0501 E0                 1391 	movx	a,@dptr
   0502 F5 08              1392 	mov	_Configuration,a
                           1393 ;	convert_serial.c:319: break;
   0504 02 07 20           1394 	ljmp	00164$
                           1395 ;	convert_serial.c:320: case SC_GET_CONFIGURATION:
   0507                    1396 00132$:
                           1397 ;	convert_serial.c:321: EP0BUF[0] = Configuration;
   0507 90 E7 40           1398 	mov	dptr,#_EP0BUF
   050A E5 08              1399 	mov	a,_Configuration
   050C F0                 1400 	movx	@dptr,a
                           1401 ;	convert_serial.c:322: EP0BCH = 0;
   050D 90 E6 8A           1402 	mov	dptr,#_EP0BCH
   0510 E4                 1403 	clr	a
   0511 F0                 1404 	movx	@dptr,a
                           1405 ;	convert_serial.c:323: EP0BCL = 1;
   0512 90 E6 8B           1406 	mov	dptr,#_EP0BCL
   0515 74 01              1407 	mov	a,#0x01
   0517 F0                 1408 	movx	@dptr,a
                           1409 ;	convert_serial.c:324: break;
   0518 02 07 20           1410 	ljmp	00164$
                           1411 ;	convert_serial.c:325: case SC_GET_STATUS:
   051B                    1412 00133$:
                           1413 ;	convert_serial.c:326: switch(SETUPDAT[0])
   051B 90 E6 B8           1414 	mov	dptr,#_SETUPDAT
   051E E0                 1415 	movx	a,@dptr
   051F FF                 1416 	mov	r7,a
   0520 BF 80 02           1417 	cjne	r7,#0x80,00239$
   0523 80 0D              1418 	sjmp	00134$
   0525                    1419 00239$:
   0525 BF 81 02           1420 	cjne	r7,#0x81,00240$
   0528 80 2D              1421 	sjmp	00135$
   052A                    1422 00240$:
   052A BF 82 02           1423 	cjne	r7,#0x82,00241$
   052D 80 3E              1424 	sjmp	00136$
   052F                    1425 00241$:
   052F 02 05 B2           1426 	ljmp	00137$
                           1427 ;	convert_serial.c:328: case GS_DEVICE:
   0532                    1428 00134$:
                           1429 ;	convert_serial.c:329: EP0BUF[0] = ((BYTE)Rwuen << 1) | (BYTE)Selfpwr;
   0532 A2 01              1430 	mov	c,_Rwuen
   0534 E4                 1431 	clr	a
   0535 33                 1432 	rlc	a
   0536 25 E0              1433 	add	a,acc
   0538 FF                 1434 	mov	r7,a
   0539 A2 02              1435 	mov	c,_Selfpwr
   053B E4                 1436 	clr	a
   053C 33                 1437 	rlc	a
   053D FE                 1438 	mov	r6,a
   053E 42 07              1439 	orl	ar7,a
   0540 90 E7 40           1440 	mov	dptr,#_EP0BUF
   0543 EF                 1441 	mov	a,r7
   0544 F0                 1442 	movx	@dptr,a
                           1443 ;	convert_serial.c:330: EP0BUF[1] = 0;
   0545 90 E7 41           1444 	mov	dptr,#(_EP0BUF + 0x0001)
                           1445 ;	convert_serial.c:331: EP0BCH = 0;
   0548 E4                 1446 	clr	a
   0549 F0                 1447 	movx	@dptr,a
   054A 90 E6 8A           1448 	mov	dptr,#_EP0BCH
   054D F0                 1449 	movx	@dptr,a
                           1450 ;	convert_serial.c:332: EP0BCL = 2;
   054E 90 E6 8B           1451 	mov	dptr,#_EP0BCL
   0551 74 02              1452 	mov	a,#0x02
   0553 F0                 1453 	movx	@dptr,a
                           1454 ;	convert_serial.c:333: break;
   0554 02 07 20           1455 	ljmp	00164$
                           1456 ;	convert_serial.c:334: case GS_INTERFACE:
   0557                    1457 00135$:
                           1458 ;	convert_serial.c:335: EP0BUF[0] = 0;
   0557 90 E7 40           1459 	mov	dptr,#_EP0BUF
                           1460 ;	convert_serial.c:336: EP0BUF[1] = 0;
                           1461 ;	convert_serial.c:337: EP0BCH = 0;
   055A E4                 1462 	clr	a
   055B F0                 1463 	movx	@dptr,a
   055C 90 E7 41           1464 	mov	dptr,#(_EP0BUF + 0x0001)
   055F F0                 1465 	movx	@dptr,a
   0560 90 E6 8A           1466 	mov	dptr,#_EP0BCH
   0563 F0                 1467 	movx	@dptr,a
                           1468 ;	convert_serial.c:338: EP0BCL = 2;
   0564 90 E6 8B           1469 	mov	dptr,#_EP0BCL
   0567 74 02              1470 	mov	a,#0x02
   0569 F0                 1471 	movx	@dptr,a
                           1472 ;	convert_serial.c:339: break;
   056A 02 07 20           1473 	ljmp	00164$
                           1474 ;	convert_serial.c:340: case GS_ENDPOINT:
   056D                    1475 00136$:
                           1476 ;	convert_serial.c:341: EP0BUF[0] = *(BYTE xdata *) epcs(SETUPDAT[4]) & bmEPSTALL;
   056D 90 E6 BC           1477 	mov	dptr,#(_SETUPDAT + 0x0004)
   0570 E0                 1478 	movx	a,@dptr
   0571 FF                 1479 	mov	r7,a
   0572 53 07 7E           1480 	anl	ar7,#0x7E
   0575 90 E6 BC           1481 	mov	dptr,#(_SETUPDAT + 0x0004)
   0578 E0                 1482 	movx	a,@dptr
   0579 FE                 1483 	mov	r6,a
   057A C3                 1484 	clr	c
   057B 74 80              1485 	mov	a,#0x80
   057D 9E                 1486 	subb	a,r6
   057E E4                 1487 	clr	a
   057F 33                 1488 	rlc	a
   0580 4F                 1489 	orl	a,r7
   0581 90 09 07           1490 	mov	dptr,#_EPCS_Offset_Lookup_Table
   0584 93                 1491 	movc	a,@a+dptr
   0585 FF                 1492 	mov	r7,a
   0586 33                 1493 	rlc	a
   0587 95 E0              1494 	subb	a,acc
   0589 FE                 1495 	mov	r6,a
   058A 74 A1              1496 	mov	a,#0xA1
   058C 2F                 1497 	add	a,r7
   058D FF                 1498 	mov	r7,a
   058E 74 E6              1499 	mov	a,#0xE6
   0590 3E                 1500 	addc	a,r6
   0591 FE                 1501 	mov	r6,a
   0592 8F 82              1502 	mov	dpl,r7
   0594 8E 83              1503 	mov	dph,r6
   0596 E0                 1504 	movx	a,@dptr
   0597 FF                 1505 	mov	r7,a
   0598 53 07 01           1506 	anl	ar7,#0x01
   059B 90 E7 40           1507 	mov	dptr,#_EP0BUF
   059E EF                 1508 	mov	a,r7
   059F F0                 1509 	movx	@dptr,a
                           1510 ;	convert_serial.c:342: EP0BUF[1] = 0;
   05A0 90 E7 41           1511 	mov	dptr,#(_EP0BUF + 0x0001)
                           1512 ;	convert_serial.c:343: EP0BCH = 0;
   05A3 E4                 1513 	clr	a
   05A4 F0                 1514 	movx	@dptr,a
   05A5 90 E6 8A           1515 	mov	dptr,#_EP0BCH
   05A8 F0                 1516 	movx	@dptr,a
                           1517 ;	convert_serial.c:344: EP0BCL = 2;
   05A9 90 E6 8B           1518 	mov	dptr,#_EP0BCL
   05AC 74 02              1519 	mov	a,#0x02
   05AE F0                 1520 	movx	@dptr,a
                           1521 ;	convert_serial.c:345: break;
   05AF 02 07 20           1522 	ljmp	00164$
                           1523 ;	convert_serial.c:346: default:            // Invalid Command
   05B2                    1524 00137$:
                           1525 ;	convert_serial.c:347: EZUSB_STALL_EP0();
   05B2 90 E6 A0           1526 	mov	dptr,#_EP0CS
   05B5 E0                 1527 	movx	a,@dptr
   05B6 FF                 1528 	mov	r7,a
   05B7 44 01              1529 	orl	a,#0x01
   05B9 F0                 1530 	movx	@dptr,a
                           1531 ;	convert_serial.c:349: break;
   05BA 02 07 20           1532 	ljmp	00164$
                           1533 ;	convert_serial.c:350: case SC_CLEAR_FEATURE:
   05BD                    1534 00139$:
                           1535 ;	convert_serial.c:351: switch(SETUPDAT[0])
   05BD 90 E6 B8           1536 	mov	dptr,#_SETUPDAT
   05C0 E0                 1537 	movx	a,@dptr
   05C1 FF                 1538 	mov	r7,a
   05C2 60 08              1539 	jz	00140$
   05C4 BF 02 02           1540 	cjne	r7,#0x02,00243$
   05C7 80 1B              1541 	sjmp	00144$
   05C9                    1542 00243$:
   05C9 02 07 20           1543 	ljmp	00164$
                           1544 ;	convert_serial.c:353: case FT_DEVICE:
   05CC                    1545 00140$:
                           1546 ;	convert_serial.c:354: if(SETUPDAT[2] == 1)
   05CC 90 E6 BA           1547 	mov	dptr,#(_SETUPDAT + 0x0002)
   05CF E0                 1548 	movx	a,@dptr
   05D0 FF                 1549 	mov	r7,a
   05D1 BF 01 05           1550 	cjne	r7,#0x01,00142$
                           1551 ;	convert_serial.c:355: Rwuen = FALSE;       // Disable Remote Wakeup
   05D4 C2 01              1552 	clr	_Rwuen
   05D6 02 07 20           1553 	ljmp	00164$
   05D9                    1554 00142$:
                           1555 ;	convert_serial.c:357: EZUSB_STALL_EP0();
   05D9 90 E6 A0           1556 	mov	dptr,#_EP0CS
   05DC E0                 1557 	movx	a,@dptr
   05DD FF                 1558 	mov	r7,a
   05DE 44 01              1559 	orl	a,#0x01
   05E0 F0                 1560 	movx	@dptr,a
                           1561 ;	convert_serial.c:358: break;
   05E1 02 07 20           1562 	ljmp	00164$
                           1563 ;	convert_serial.c:359: case FT_ENDPOINT:
   05E4                    1564 00144$:
                           1565 ;	convert_serial.c:360: if(SETUPDAT[2] == 0)
   05E4 90 E6 BA           1566 	mov	dptr,#(_SETUPDAT + 0x0002)
   05E7 E0                 1567 	movx	a,@dptr
   05E8 60 03              1568 	jz	00246$
   05EA 02 06 69           1569 	ljmp	00146$
   05ED                    1570 00246$:
                           1571 ;	convert_serial.c:362: *(BYTE xdata *) epcs(SETUPDAT[4]) &= ~bmEPSTALL;
   05ED 90 E6 BC           1572 	mov	dptr,#(_SETUPDAT + 0x0004)
   05F0 E0                 1573 	movx	a,@dptr
   05F1 FF                 1574 	mov	r7,a
   05F2 53 07 7E           1575 	anl	ar7,#0x7E
   05F5 90 E6 BC           1576 	mov	dptr,#(_SETUPDAT + 0x0004)
   05F8 E0                 1577 	movx	a,@dptr
   05F9 FE                 1578 	mov	r6,a
   05FA C3                 1579 	clr	c
   05FB 74 80              1580 	mov	a,#0x80
   05FD 9E                 1581 	subb	a,r6
   05FE E4                 1582 	clr	a
   05FF 33                 1583 	rlc	a
   0600 4F                 1584 	orl	a,r7
   0601 90 09 07           1585 	mov	dptr,#_EPCS_Offset_Lookup_Table
   0604 93                 1586 	movc	a,@a+dptr
   0605 FF                 1587 	mov	r7,a
   0606 33                 1588 	rlc	a
   0607 95 E0              1589 	subb	a,acc
   0609 FE                 1590 	mov	r6,a
   060A 74 A1              1591 	mov	a,#0xA1
   060C 2F                 1592 	add	a,r7
   060D FF                 1593 	mov	r7,a
   060E 74 E6              1594 	mov	a,#0xE6
   0610 3E                 1595 	addc	a,r6
   0611 FE                 1596 	mov	r6,a
   0612 90 E6 BC           1597 	mov	dptr,#(_SETUPDAT + 0x0004)
   0615 E0                 1598 	movx	a,@dptr
   0616 FD                 1599 	mov	r5,a
   0617 53 05 7E           1600 	anl	ar5,#0x7E
   061A 90 E6 BC           1601 	mov	dptr,#(_SETUPDAT + 0x0004)
   061D E0                 1602 	movx	a,@dptr
   061E FC                 1603 	mov	r4,a
   061F C3                 1604 	clr	c
   0620 74 80              1605 	mov	a,#0x80
   0622 9C                 1606 	subb	a,r4
   0623 E4                 1607 	clr	a
   0624 33                 1608 	rlc	a
   0625 4D                 1609 	orl	a,r5
   0626 90 09 07           1610 	mov	dptr,#_EPCS_Offset_Lookup_Table
   0629 93                 1611 	movc	a,@a+dptr
   062A FD                 1612 	mov	r5,a
   062B 33                 1613 	rlc	a
   062C 95 E0              1614 	subb	a,acc
   062E FC                 1615 	mov	r4,a
   062F 74 A1              1616 	mov	a,#0xA1
   0631 2D                 1617 	add	a,r5
   0632 FD                 1618 	mov	r5,a
   0633 74 E6              1619 	mov	a,#0xE6
   0635 3C                 1620 	addc	a,r4
   0636 FC                 1621 	mov	r4,a
   0637 8D 82              1622 	mov	dpl,r5
   0639 8C 83              1623 	mov	dph,r4
   063B E0                 1624 	movx	a,@dptr
   063C FD                 1625 	mov	r5,a
   063D 53 05 FE           1626 	anl	ar5,#0xFE
   0640 8F 82              1627 	mov	dpl,r7
   0642 8E 83              1628 	mov	dph,r6
   0644 ED                 1629 	mov	a,r5
   0645 F0                 1630 	movx	@dptr,a
                           1631 ;	convert_serial.c:363: EZUSB_RESET_DATA_TOGGLE( SETUPDAT[4] );
   0646 90 E6 BC           1632 	mov	dptr,#(_SETUPDAT + 0x0004)
   0649 E0                 1633 	movx	a,@dptr
   064A 54 80              1634 	anl	a,#0x80
   064C C4                 1635 	swap	a
   064D 23                 1636 	rl	a
   064E 54 1F              1637 	anl	a,#0x1F
   0650 FF                 1638 	mov	r7,a
   0651 90 E6 BC           1639 	mov	dptr,#(_SETUPDAT + 0x0004)
   0654 E0                 1640 	movx	a,@dptr
   0655 FE                 1641 	mov	r6,a
   0656 74 0F              1642 	mov	a,#0x0F
   0658 5E                 1643 	anl	a,r6
   0659 90 E6 83           1644 	mov	dptr,#_TOGCTL
   065C 2F                 1645 	add	a,r7
   065D F0                 1646 	movx	@dptr,a
   065E 90 E6 83           1647 	mov	dptr,#_TOGCTL
   0661 E0                 1648 	movx	a,@dptr
   0662 FF                 1649 	mov	r7,a
   0663 44 20              1650 	orl	a,#0x20
   0665 F0                 1651 	movx	@dptr,a
   0666 02 07 20           1652 	ljmp	00164$
   0669                    1653 00146$:
                           1654 ;	convert_serial.c:366: EZUSB_STALL_EP0();
   0669 90 E6 A0           1655 	mov	dptr,#_EP0CS
   066C E0                 1656 	movx	a,@dptr
   066D FF                 1657 	mov	r7,a
   066E 44 01              1658 	orl	a,#0x01
   0670 F0                 1659 	movx	@dptr,a
                           1660 ;	convert_serial.c:369: break;
   0671 02 07 20           1661 	ljmp	00164$
                           1662 ;	convert_serial.c:370: case SC_SET_FEATURE:
   0674                    1663 00149$:
                           1664 ;	convert_serial.c:371: switch(SETUPDAT[0])
   0674 90 E6 B8           1665 	mov	dptr,#_SETUPDAT
   0677 E0                 1666 	movx	a,@dptr
   0678 FF                 1667 	mov	r7,a
   0679 60 08              1668 	jz	00150$
   067B BF 02 02           1669 	cjne	r7,#0x02,00248$
   067E 80 29              1670 	sjmp	00158$
   0680                    1671 00248$:
   0680 02 07 04           1672 	ljmp	00159$
                           1673 ;	convert_serial.c:373: case FT_DEVICE:
   0683                    1674 00150$:
                           1675 ;	convert_serial.c:374: if((SETUPDAT[2] == 1) && Rwuen_allowed)
   0683 90 E6 BA           1676 	mov	dptr,#(_SETUPDAT + 0x0002)
   0686 E0                 1677 	movx	a,@dptr
   0687 FF                 1678 	mov	r7,a
   0688 BF 01 08           1679 	cjne	r7,#0x01,00155$
   068B 30 00 05           1680 	jnb	_Rwuen_allowed,00155$
                           1681 ;	convert_serial.c:375: Rwuen = TRUE;      // Enable Remote Wakeup
   068E D2 01              1682 	setb	_Rwuen
   0690 02 07 20           1683 	ljmp	00164$
   0693                    1684 00155$:
                           1685 ;	convert_serial.c:376: else if(SETUPDAT[2] == 2)
   0693 90 E6 BA           1686 	mov	dptr,#(_SETUPDAT + 0x0002)
   0696 E0                 1687 	movx	a,@dptr
   0697 FF                 1688 	mov	r7,a
   0698 BF 02 03           1689 	cjne	r7,#0x02,00252$
   069B 02 07 20           1690 	ljmp	00164$
   069E                    1691 00252$:
                           1692 ;	convert_serial.c:386: EZUSB_STALL_EP0();
   069E 90 E6 A0           1693 	mov	dptr,#_EP0CS
   06A1 E0                 1694 	movx	a,@dptr
   06A2 FF                 1695 	mov	r7,a
   06A3 44 01              1696 	orl	a,#0x01
   06A5 F0                 1697 	movx	@dptr,a
                           1698 ;	convert_serial.c:387: break;
   06A6 02 07 20           1699 	ljmp	00164$
                           1700 ;	convert_serial.c:388: case FT_ENDPOINT:
   06A9                    1701 00158$:
                           1702 ;	convert_serial.c:389: *(BYTE xdata *) epcs(SETUPDAT[4]) |= bmEPSTALL;
   06A9 90 E6 BC           1703 	mov	dptr,#(_SETUPDAT + 0x0004)
   06AC E0                 1704 	movx	a,@dptr
   06AD FF                 1705 	mov	r7,a
   06AE 53 07 7E           1706 	anl	ar7,#0x7E
   06B1 90 E6 BC           1707 	mov	dptr,#(_SETUPDAT + 0x0004)
   06B4 E0                 1708 	movx	a,@dptr
   06B5 FE                 1709 	mov	r6,a
   06B6 C3                 1710 	clr	c
   06B7 74 80              1711 	mov	a,#0x80
   06B9 9E                 1712 	subb	a,r6
   06BA E4                 1713 	clr	a
   06BB 33                 1714 	rlc	a
   06BC 4F                 1715 	orl	a,r7
   06BD 90 09 07           1716 	mov	dptr,#_EPCS_Offset_Lookup_Table
   06C0 93                 1717 	movc	a,@a+dptr
   06C1 FF                 1718 	mov	r7,a
   06C2 33                 1719 	rlc	a
   06C3 95 E0              1720 	subb	a,acc
   06C5 FE                 1721 	mov	r6,a
   06C6 74 A1              1722 	mov	a,#0xA1
   06C8 2F                 1723 	add	a,r7
   06C9 FF                 1724 	mov	r7,a
   06CA 74 E6              1725 	mov	a,#0xE6
   06CC 3E                 1726 	addc	a,r6
   06CD FE                 1727 	mov	r6,a
   06CE 90 E6 BC           1728 	mov	dptr,#(_SETUPDAT + 0x0004)
   06D1 E0                 1729 	movx	a,@dptr
   06D2 FD                 1730 	mov	r5,a
   06D3 53 05 7E           1731 	anl	ar5,#0x7E
   06D6 90 E6 BC           1732 	mov	dptr,#(_SETUPDAT + 0x0004)
   06D9 E0                 1733 	movx	a,@dptr
   06DA FC                 1734 	mov	r4,a
   06DB C3                 1735 	clr	c
   06DC 74 80              1736 	mov	a,#0x80
   06DE 9C                 1737 	subb	a,r4
   06DF E4                 1738 	clr	a
   06E0 33                 1739 	rlc	a
   06E1 4D                 1740 	orl	a,r5
   06E2 90 09 07           1741 	mov	dptr,#_EPCS_Offset_Lookup_Table
   06E5 93                 1742 	movc	a,@a+dptr
   06E6 FD                 1743 	mov	r5,a
   06E7 33                 1744 	rlc	a
   06E8 95 E0              1745 	subb	a,acc
   06EA FC                 1746 	mov	r4,a
   06EB 74 A1              1747 	mov	a,#0xA1
   06ED 2D                 1748 	add	a,r5
   06EE FD                 1749 	mov	r5,a
   06EF 74 E6              1750 	mov	a,#0xE6
   06F1 3C                 1751 	addc	a,r4
   06F2 FC                 1752 	mov	r4,a
   06F3 8D 82              1753 	mov	dpl,r5
   06F5 8C 83              1754 	mov	dph,r4
   06F7 E0                 1755 	movx	a,@dptr
   06F8 FD                 1756 	mov	r5,a
   06F9 43 05 01           1757 	orl	ar5,#0x01
   06FC 8F 82              1758 	mov	dpl,r7
   06FE 8E 83              1759 	mov	dph,r6
   0700 ED                 1760 	mov	a,r5
   0701 F0                 1761 	movx	@dptr,a
                           1762 ;	convert_serial.c:390: break;
                           1763 ;	convert_serial.c:391: default:
   0702 80 1C              1764 	sjmp	00164$
   0704                    1765 00159$:
                           1766 ;	convert_serial.c:392: EZUSB_STALL_EP0();
   0704 90 E6 A0           1767 	mov	dptr,#_EP0CS
   0707 E0                 1768 	movx	a,@dptr
   0708 FF                 1769 	mov	r7,a
   0709 44 01              1770 	orl	a,#0x01
   070B F0                 1771 	movx	@dptr,a
                           1772 ;	convert_serial.c:394: break;
                           1773 ;	convert_serial.c:395: default:                     // *** Invalid Command
   070C 80 12              1774 	sjmp	00164$
   070E                    1775 00161$:
                           1776 ;	convert_serial.c:396: EZUSB_STALL_EP0();
   070E 90 E6 A0           1777 	mov	dptr,#_EP0CS
   0711 E0                 1778 	movx	a,@dptr
   0712 FF                 1779 	mov	r7,a
   0713 44 01              1780 	orl	a,#0x01
   0715 F0                 1781 	movx	@dptr,a
                           1782 ;	convert_serial.c:399: break;
                           1783 ;	convert_serial.c:401: default:
   0716 80 08              1784 	sjmp	00164$
   0718                    1785 00163$:
                           1786 ;	convert_serial.c:402: EZUSB_STALL_EP0();
   0718 90 E6 A0           1787 	mov	dptr,#_EP0CS
   071B E0                 1788 	movx	a,@dptr
   071C FF                 1789 	mov	r7,a
   071D 44 01              1790 	orl	a,#0x01
   071F F0                 1791 	movx	@dptr,a
                           1792 ;	convert_serial.c:404: }
   0720                    1793 00164$:
                           1794 ;	convert_serial.c:407: EP0CS |= bmHSNAK;
   0720 90 E6 A0           1795 	mov	dptr,#_EP0CS
   0723 E0                 1796 	movx	a,@dptr
   0724 44 80              1797 	orl	a,#0x80
   0726 F0                 1798 	movx	@dptr,a
   0727 22                 1799 	ret
                           1800 ;------------------------------------------------------------
                           1801 ;Allocation info for local variables in function 'USB_isr'
                           1802 ;------------------------------------------------------------
                           1803 ;	convert_serial.c:410: static void USB_isr(void) __interrupt 8
                           1804 ;	-----------------------------------------
                           1805 ;	 function USB_isr
                           1806 ;	-----------------------------------------
   0728                    1807 _USB_isr:
   0728 C0 21              1808 	push	bits
   072A C0 E0              1809 	push	acc
   072C C0 F0              1810 	push	b
   072E C0 82              1811 	push	dpl
   0730 C0 83              1812 	push	dph
   0732 C0 07              1813 	push	(0+7)
   0734 C0 06              1814 	push	(0+6)
   0736 C0 05              1815 	push	(0+5)
   0738 C0 04              1816 	push	(0+4)
   073A C0 03              1817 	push	(0+3)
   073C C0 02              1818 	push	(0+2)
   073E C0 01              1819 	push	(0+1)
   0740 C0 00              1820 	push	(0+0)
   0742 C0 D0              1821 	push	psw
   0744 75 D0 00           1822 	mov	psw,#0x00
                           1823 ;	convert_serial.c:413: EXIF &= ~0x10;
   0747 AF 91              1824 	mov	r7,_EXIF
   0749 74 EF              1825 	mov	a,#0xEF
   074B 5F                 1826 	anl	a,r7
   074C F5 91              1827 	mov	_EXIF,a
                           1828 ;	convert_serial.c:416: USBIRQ = 0x01;
   074E 90 E6 5D           1829 	mov	dptr,#_USBIRQ
   0751 74 01              1830 	mov	a,#0x01
   0753 F0                 1831 	movx	@dptr,a
                           1832 ;	convert_serial.c:418: SetupCommand();
   0754 12 02 86           1833 	lcall	_SetupCommand
   0757 D0 D0              1834 	pop	psw
   0759 D0 00              1835 	pop	(0+0)
   075B D0 01              1836 	pop	(0+1)
   075D D0 02              1837 	pop	(0+2)
   075F D0 03              1838 	pop	(0+3)
   0761 D0 04              1839 	pop	(0+4)
   0763 D0 05              1840 	pop	(0+5)
   0765 D0 06              1841 	pop	(0+6)
   0767 D0 07              1842 	pop	(0+7)
   0769 D0 83              1843 	pop	dph
   076B D0 82              1844 	pop	dpl
   076D D0 F0              1845 	pop	b
   076F D0 E0              1846 	pop	acc
   0771 D0 21              1847 	pop	bits
   0773 32                 1848 	reti
                           1849 ;------------------------------------------------------------
                           1850 ;Allocation info for local variables in function 'Initialize'
                           1851 ;------------------------------------------------------------
                           1852 ;	convert_serial.c:425: static void Initialize(void)
                           1853 ;	-----------------------------------------
                           1854 ;	 function Initialize
                           1855 ;	-----------------------------------------
   0774                    1856 _Initialize:
                           1857 ;	convert_serial.c:435: SYNCDELAY;
   0774 00                 1858 	nop 
   0775 00                 1859 	nop 
   0776 00                 1860 	nop 
   0777 00                 1861 	nop 
                           1862 ;	convert_serial.c:437: REVCTL=0x03;  // See TRM...
   0778 90 E6 0B           1863 	mov	dptr,#_REVCTL
   077B 74 03              1864 	mov	a,#0x03
   077D F0                 1865 	movx	@dptr,a
                           1866 ;	convert_serial.c:438: SYNCDELAY;
   077E 00                 1867 	nop 
   077F 00                 1868 	nop 
   0780 00                 1869 	nop 
   0781 00                 1870 	nop 
                           1871 ;	convert_serial.c:443: EP1OUTCFG=0xa0;
   0782 90 E6 10           1872 	mov	dptr,#_EP1OUTCFG
   0785 74 A0              1873 	mov	a,#0xA0
   0787 F0                 1874 	movx	@dptr,a
                           1875 ;	convert_serial.c:444: EP1INCFG=0xa0;
   0788 90 E6 11           1876 	mov	dptr,#_EP1INCFG
   078B 74 A0              1877 	mov	a,#0xA0
   078D F0                 1878 	movx	@dptr,a
                           1879 ;	convert_serial.c:445: EP2CFG=0;
   078E 90 E6 12           1880 	mov	dptr,#_EP2CFG
                           1881 ;	convert_serial.c:446: EP4CFG=0;
                           1882 ;	convert_serial.c:447: EP6CFG=0;
                           1883 ;	convert_serial.c:448: EP8CFG=0;
   0791 E4                 1884 	clr	a
   0792 F0                 1885 	movx	@dptr,a
   0793 90 E6 13           1886 	mov	dptr,#_EP4CFG
   0796 F0                 1887 	movx	@dptr,a
   0797 90 E6 14           1888 	mov	dptr,#_EP6CFG
   079A F0                 1889 	movx	@dptr,a
   079B 90 E6 15           1890 	mov	dptr,#_EP8CFG
   079E F0                 1891 	movx	@dptr,a
                           1892 ;	convert_serial.c:450: SYNCDELAY;
   079F 00                 1893 	nop 
   07A0 00                 1894 	nop 
   07A1 00                 1895 	nop 
   07A2 00                 1896 	nop 
                           1897 ;	convert_serial.c:451: EP1OUTBC=0xff; // Arm endpoint 1 for OUT (host->device) transfers
   07A3 90 E6 8D           1898 	mov	dptr,#_EP1OUTBC
   07A6 74 FF              1899 	mov	a,#0xFF
   07A8 F0                 1900 	movx	@dptr,a
                           1901 ;	convert_serial.c:463: IE = 0x80;
   07A9 75 A8 80           1902 	mov	_IE,#0x80
                           1903 ;	convert_serial.c:464: EIE = 0x01;
   07AC 75 E8 01           1904 	mov	_EIE,#0x01
                           1905 ;	convert_serial.c:467: USBIE = 0x01;
   07AF 90 E6 5C           1906 	mov	dptr,#_USBIE
   07B2 74 01              1907 	mov	a,#0x01
   07B4 F0                 1908 	movx	@dptr,a
   07B5 22                 1909 	ret
                           1910 ;------------------------------------------------------------
                           1911 ;Allocation info for local variables in function 'ProcessXmitData'
                           1912 ;------------------------------------------------------------
                           1913 ;	convert_serial.c:501: static void ProcessXmitData(void)
                           1914 ;	-----------------------------------------
                           1915 ;	 function ProcessXmitData
                           1916 ;	-----------------------------------------
   07B6                    1917 _ProcessXmitData:
                           1918 ;	convert_serial.c:504: TCON &= ~0x30;
   07B6 AF 88              1919 	mov	r7,_TCON
   07B8 74 CF              1920 	mov	a,#0xCF
   07BA 5F                 1921 	anl	a,r7
   07BB F5 88              1922 	mov	_TCON,a
                           1923 ;	convert_serial.c:508: EP1INBUF[0] = FTDI_RS0_CTS | FTDI_RS0_DSR | 1;
   07BD 90 E7 C0           1924 	mov	dptr,#_EP1INBUF
   07C0 74 31              1925 	mov	a,#0x31
   07C2 F0                 1926 	movx	@dptr,a
                           1927 ;	convert_serial.c:509: EP1INBUF[1] = FTDI_RS_DR;
   07C3 90 E7 C1           1928 	mov	dptr,#(_EP1INBUF + 0x0001)
   07C6 74 01              1929 	mov	a,#0x01
   07C8 F0                 1930 	movx	@dptr,a
                           1931 ;	convert_serial.c:512: SYNCDELAY;
   07C9 00                 1932 	nop 
   07CA 00                 1933 	nop 
   07CB 00                 1934 	nop 
   07CC 00                 1935 	nop 
                           1936 ;	convert_serial.c:513: EP1INBC = bytes_waiting_for_xmit + 2;
   07CD AF 15              1937 	mov	r7,_bytes_waiting_for_xmit
   07CF 90 E6 8F           1938 	mov	dptr,#_EP1INBC
   07D2 74 02              1939 	mov	a,#0x02
   07D4 2F                 1940 	add	a,r7
   07D5 F0                 1941 	movx	@dptr,a
                           1942 ;	convert_serial.c:515: bytes_waiting_for_xmit = 0;
   07D6 E4                 1943 	clr	a
   07D7 F5 15              1944 	mov	_bytes_waiting_for_xmit,a
   07D9 F5 16              1945 	mov	(_bytes_waiting_for_xmit + 1),a
   07DB 22                 1946 	ret
                           1947 ;------------------------------------------------------------
                           1948 ;Allocation info for local variables in function 'putchar'
                           1949 ;------------------------------------------------------------
                           1950 ;c                         Allocated to registers r7 
                           1951 ;dest                      Allocated to registers r5 r6 
                           1952 ;------------------------------------------------------------
                           1953 ;	convert_serial.c:519: static void putchar(char c)
                           1954 ;	-----------------------------------------
                           1955 ;	 function putchar
                           1956 ;	-----------------------------------------
   07DC                    1957 _putchar:
   07DC AF 82              1958 	mov	r7,dpl
                           1959 ;	convert_serial.c:521: xdata unsigned char *dest=EP1INBUF + bytes_waiting_for_xmit + 2;
   07DE E5 15              1960 	mov	a,_bytes_waiting_for_xmit
   07E0 24 C0              1961 	add	a,#_EP1INBUF
   07E2 FD                 1962 	mov	r5,a
   07E3 E5 16              1963 	mov	a,(_bytes_waiting_for_xmit + 1)
   07E5 34 E7              1964 	addc	a,#(_EP1INBUF >> 8)
   07E7 FE                 1965 	mov	r6,a
   07E8 74 02              1966 	mov	a,#0x02
   07EA 2D                 1967 	add	a,r5
   07EB FD                 1968 	mov	r5,a
   07EC E4                 1969 	clr	a
   07ED 3E                 1970 	addc	a,r6
   07EE FE                 1971 	mov	r6,a
                           1972 ;	convert_serial.c:524: while (EP1INCS & 0x02);
   07EF                    1973 00101$:
   07EF 90 E6 A2           1974 	mov	dptr,#_EP1INCS
   07F2 E0                 1975 	movx	a,@dptr
   07F3 FC                 1976 	mov	r4,a
   07F4 20 E1 F8           1977 	jb	acc.1,00101$
                           1978 ;	convert_serial.c:526: *dest = c;
   07F7 8D 82              1979 	mov	dpl,r5
   07F9 8E 83              1980 	mov	dph,r6
   07FB EF                 1981 	mov	a,r7
   07FC F0                 1982 	movx	@dptr,a
                           1983 ;	convert_serial.c:528: if (++bytes_waiting_for_xmit >= 62) ProcessXmitData();
   07FD 05 15              1984 	inc	_bytes_waiting_for_xmit
   07FF E4                 1985 	clr	a
   0800 B5 15 02           1986 	cjne	a,_bytes_waiting_for_xmit,00122$
   0803 05 16              1987 	inc	(_bytes_waiting_for_xmit + 1)
   0805                    1988 00122$:
   0805 C3                 1989 	clr	c
   0806 E5 15              1990 	mov	a,_bytes_waiting_for_xmit
   0808 94 3E              1991 	subb	a,#0x3E
   080A E5 16              1992 	mov	a,(_bytes_waiting_for_xmit + 1)
   080C 94 00              1993 	subb	a,#0x00
   080E 40 03              1994 	jc	00105$
   0810 12 07 B6           1995 	lcall	_ProcessXmitData
   0813                    1996 00105$:
                           1997 ;	convert_serial.c:531: if (bytes_waiting_for_xmit && !(TCON & 0x10)) {
   0813 E5 15              1998 	mov	a,_bytes_waiting_for_xmit
   0815 45 16              1999 	orl	a,(_bytes_waiting_for_xmit + 1)
   0817 60 19              2000 	jz	00109$
   0819 E5 88              2001 	mov	a,_TCON
   081B 20 E4 14           2002 	jb	acc.4,00109$
                           2003 ;	convert_serial.c:532: TH0 = MSB(0xffff - latency_us);
   081E 74 FF              2004 	mov	a,#0xFF
   0820 C3                 2005 	clr	c
   0821 95 17              2006 	subb	a,_latency_us
   0823 FE                 2007 	mov	r6,a
   0824 74 FF              2008 	mov	a,#0xFF
   0826 95 18              2009 	subb	a,(_latency_us + 1)
   0828 FD                 2010 	mov	r5,a
   0829 8D 8C              2011 	mov	_TH0,r5
                           2012 ;	convert_serial.c:533: TL0 = LSB(0xffff - latency_us);
   082B 7F 00              2013 	mov	r7,#0x00
   082D 8E 8A              2014 	mov	_TL0,r6
                           2015 ;	convert_serial.c:534: TCON |= 0x10;
   082F 43 88 10           2016 	orl	_TCON,#0x10
   0832                    2017 00109$:
   0832 22                 2018 	ret
                           2019 ;------------------------------------------------------------
                           2020 ;Allocation info for local variables in function 'ProcessRecvData'
                           2021 ;------------------------------------------------------------
                           2022 ;src                       Allocated to registers 
                           2023 ;len                       Allocated to registers r6 r7 
                           2024 ;i                         Allocated to registers r2 r3 
                           2025 ;------------------------------------------------------------
                           2026 ;	convert_serial.c:538: static void ProcessRecvData(void)
                           2027 ;	-----------------------------------------
                           2028 ;	 function ProcessRecvData
                           2029 ;	-----------------------------------------
   0833                    2030 _ProcessRecvData:
                           2031 ;	convert_serial.c:540: xdata const unsigned char *src=EP1OUTBUF;
                           2032 ;	convert_serial.c:541: unsigned int len = EP1OUTBC;
   0833 90 E6 8D           2033 	mov	dptr,#_EP1OUTBC
   0836 E0                 2034 	movx	a,@dptr
   0837 FE                 2035 	mov	r6,a
   0838 7F 00              2036 	mov	r7,#0x00
                           2037 ;	convert_serial.c:546: src++; len--;
   083A 74 01              2038 	mov	a,#0x01
   083C 24 80              2039 	add	a,#_EP1OUTBUF
   083E FC                 2040 	mov	r4,a
   083F E4                 2041 	clr	a
   0840 34 E7              2042 	addc	a,#(_EP1OUTBUF >> 8)
   0842 FD                 2043 	mov	r5,a
   0843 1E                 2044 	dec	r6
   0844 BE FF 01           2045 	cjne	r6,#0xFF,00120$
   0847 1F                 2046 	dec	r7
   0848                    2047 00120$:
                           2048 ;	convert_serial.c:548: for(i=0; i<len; i++,src++)
   0848 7A 00              2049 	mov	r2,#0x00
   084A 7B 00              2050 	mov	r3,#0x00
   084C                    2051 00105$:
   084C C3                 2052 	clr	c
   084D EA                 2053 	mov	a,r2
   084E 9E                 2054 	subb	a,r6
   084F EB                 2055 	mov	a,r3
   0850 9F                 2056 	subb	a,r7
   0851 50 60              2057 	jnc	00108$
                           2058 ;	convert_serial.c:550: if(*src>='a' && *src<='z')
   0853 8C 82              2059 	mov	dpl,r4
   0855 8D 83              2060 	mov	dph,r5
   0857 E0                 2061 	movx	a,@dptr
   0858 F9                 2062 	mov	r1,a
   0859 B9 61 00           2063 	cjne	r1,#0x61,00122$
   085C                    2064 00122$:
   085C 40 27              2065 	jc	00102$
   085E E9                 2066 	mov	a,r1
   085F 24 85              2067 	add	a,#0xff - 0x7A
   0861 40 22              2068 	jc	00102$
                           2069 ;	convert_serial.c:551: {  putchar(*src-'a'+'A');  }
   0863 74 E0              2070 	mov	a,#0xE0
   0865 29                 2071 	add	a,r1
   0866 F5 82              2072 	mov	dpl,a
   0868 C0 07              2073 	push	ar7
   086A C0 06              2074 	push	ar6
   086C C0 05              2075 	push	ar5
   086E C0 04              2076 	push	ar4
   0870 C0 03              2077 	push	ar3
   0872 C0 02              2078 	push	ar2
   0874 12 07 DC           2079 	lcall	_putchar
   0877 D0 02              2080 	pop	ar2
   0879 D0 03              2081 	pop	ar3
   087B D0 04              2082 	pop	ar4
   087D D0 05              2083 	pop	ar5
   087F D0 06              2084 	pop	ar6
   0881 D0 07              2085 	pop	ar7
   0883 80 22              2086 	sjmp	00107$
   0885                    2087 00102$:
                           2088 ;	convert_serial.c:553: {  putchar(*src);  }
   0885 8C 82              2089 	mov	dpl,r4
   0887 8D 83              2090 	mov	dph,r5
   0889 E0                 2091 	movx	a,@dptr
   088A F5 82              2092 	mov	dpl,a
   088C C0 07              2093 	push	ar7
   088E C0 06              2094 	push	ar6
   0890 C0 05              2095 	push	ar5
   0892 C0 04              2096 	push	ar4
   0894 C0 03              2097 	push	ar3
   0896 C0 02              2098 	push	ar2
   0898 12 07 DC           2099 	lcall	_putchar
   089B D0 02              2100 	pop	ar2
   089D D0 03              2101 	pop	ar3
   089F D0 04              2102 	pop	ar4
   08A1 D0 05              2103 	pop	ar5
   08A3 D0 06              2104 	pop	ar6
   08A5 D0 07              2105 	pop	ar7
   08A7                    2106 00107$:
                           2107 ;	convert_serial.c:548: for(i=0; i<len; i++,src++)
   08A7 0A                 2108 	inc	r2
   08A8 BA 00 01           2109 	cjne	r2,#0x00,00125$
   08AB 0B                 2110 	inc	r3
   08AC                    2111 00125$:
   08AC 0C                 2112 	inc	r4
   08AD BC 00 9C           2113 	cjne	r4,#0x00,00105$
   08B0 0D                 2114 	inc	r5
   08B1 80 99              2115 	sjmp	00105$
   08B3                    2116 00108$:
                           2117 ;	convert_serial.c:556: EP1OUTBC=0xff; // re-arm endpoint 1 for OUT (host->device) transfers
   08B3 90 E6 8D           2118 	mov	dptr,#_EP1OUTBC
   08B6 74 FF              2119 	mov	a,#0xFF
   08B8 F0                 2120 	movx	@dptr,a
                           2121 ;	convert_serial.c:557: SYNCDELAY;
   08B9 00                 2122 	nop 
   08BA 00                 2123 	nop 
   08BB 00                 2124 	nop 
   08BC 00                 2125 	nop 
   08BD 22                 2126 	ret
                           2127 ;------------------------------------------------------------
                           2128 ;Allocation info for local variables in function 'main'
                           2129 ;------------------------------------------------------------
                           2130 ;	convert_serial.c:561: void main(void)
                           2131 ;	-----------------------------------------
                           2132 ;	 function main
                           2133 ;	-----------------------------------------
   08BE                    2134 _main:
                           2135 ;	convert_serial.c:565: Initialize();
   08BE 12 07 74           2136 	lcall	_Initialize
                           2137 ;	convert_serial.c:571: CKCO &= ~(0x08);
   08C1 AF 8E              2138 	mov	r7,_CKCO
   08C3 74 F7              2139 	mov	a,#0xF7
   08C5 5F                 2140 	anl	a,r7
   08C6 F5 8E              2141 	mov	_CKCO,a
                           2142 ;	convert_serial.c:572: TMOD = 0x01;
   08C8 75 89 01           2143 	mov	_TMOD,#0x01
                           2144 ;	convert_serial.c:573: TCON &= ~0x30;
   08CB AF 88              2145 	mov	r7,_TCON
   08CD 74 CF              2146 	mov	a,#0xCF
   08CF 5F                 2147 	anl	a,r7
   08D0 F5 88              2148 	mov	_TCON,a
   08D2                    2149 00106$:
                           2150 ;	convert_serial.c:578: if(!(EP1OUTCS & bmEPBUSY))
   08D2 90 E6 A1           2151 	mov	dptr,#_EP1OUTCS
   08D5 E0                 2152 	movx	a,@dptr
   08D6 FF                 2153 	mov	r7,a
   08D7 20 E1 03           2154 	jb	acc.1,00102$
                           2155 ;	convert_serial.c:580: ProcessRecvData();
   08DA 12 08 33           2156 	lcall	_ProcessRecvData
   08DD                    2157 00102$:
                           2158 ;	convert_serial.c:584: if((TCON & 0x20))
   08DD E5 88              2159 	mov	a,_TCON
   08DF 30 E5 F0           2160 	jnb	acc.5,00106$
                           2161 ;	convert_serial.c:586: ProcessXmitData();
   08E2 12 07 B6           2162 	lcall	_ProcessXmitData
   08E5 80 EB              2163 	sjmp	00106$
                           2164 	.area CSEG    (CODE)
                           2165 	.area CONST   (CODE)
   0907                    2166 _EPCS_Offset_Lookup_Table:
   0907 00                 2167 	.db #0x00	;  0
   0908 01                 2168 	.db #0x01	;  1
   0909 02                 2169 	.db #0x02	;  2
   090A 02                 2170 	.db #0x02	;  2
   090B 03                 2171 	.db #0x03	;  3
   090C 03                 2172 	.db #0x03	;  3
   090D 04                 2173 	.db #0x04	;  4
   090E 04                 2174 	.db #0x04	;  4
   090F 05                 2175 	.db #0x05	;  5
   0910 05                 2176 	.db #0x05	;  5
   0911                    2177 __str_0:
   0911 45 4E              2178 	.ascii "EN"
   0913 00                 2179 	.db 0x00
   0914                    2180 __str_1:
   0914 66 72 65 65 73 6F  2181 	.ascii "freesoft.org"
        66 74 2E 6F 72 67
   0920 00                 2182 	.db 0x00
   0921                    2183 __str_2:
   0921 46 58 32 20 63 61  2184 	.ascii "FX2 case converter"
        73 65 20 63 6F 6E
        76 65 72 74 65 72
   0933 00                 2185 	.db 0x00
                           2186 	.area XINIT   (CODE)
                           2187 	.area CABS    (ABS,CODE)
