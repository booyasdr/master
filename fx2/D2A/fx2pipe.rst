                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.2.0 #8008 (Jul  6 2012) (MINGW32)
                              4 ; This file was generated Tue Apr 12 07:29:26 2016
                              5 ;--------------------------------------------------------
                              6 	.module fx2pipe
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _EIP
                             14 	.globl _B
                             15 	.globl _EIE
                             16 	.globl _ACC
                             17 	.globl _EICON
                             18 	.globl _PSW
                             19 	.globl _TH2
                             20 	.globl _TL2
                             21 	.globl _RCAP2H
                             22 	.globl _RCAP2L
                             23 	.globl _T2CON
                             24 	.globl _SBUF1
                             25 	.globl _SCON1
                             26 	.globl _GPIFSGLDATLNOX
                             27 	.globl _GPIFSGLDATLX
                             28 	.globl _GPIFSGLDATH
                             29 	.globl _GPIFTRIG
                             30 	.globl _EP01STAT
                             31 	.globl _IP
                             32 	.globl _OEE
                             33 	.globl _OED
                             34 	.globl _OEC
                             35 	.globl _OEB
                             36 	.globl _OEA
                             37 	.globl _IOE
                             38 	.globl _IOD
                             39 	.globl _AUTOPTRSETUP
                             40 	.globl _EP68FIFOFLGS
                             41 	.globl _EP24FIFOFLGS
                             42 	.globl _EP2468STAT
                             43 	.globl _IE
                             44 	.globl _INT4CLR
                             45 	.globl _INT2CLR
                             46 	.globl _IOC
                             47 	.globl _AUTODAT2
                             48 	.globl _AUTOPTRL2
                             49 	.globl _AUTOPTRH2
                             50 	.globl _AUTODAT1
                             51 	.globl _APTR1L
                             52 	.globl _APTR1H
                             53 	.globl _SBU
                             54 	.globl _SCO
                             55 	.globl _MPA
                             56 	.globl _EXIF
                             57 	.globl _IOB
                             58 	.globl _SPC_
                             59 	.globl _CKCO
                             60 	.globl _TH1
                             61 	.globl _TH0
                             62 	.globl _TL1
                             63 	.globl _TL0
                             64 	.globl _TMOD
                             65 	.globl _TCON
                             66 	.globl _PCON
                             67 	.globl _DPS
                             68 	.globl _DPH1
                             69 	.globl _DPL1
                             70 	.globl _DPH
                             71 	.globl _DPL
                             72 	.globl _SP
                             73 	.globl _IOA
                             74 	.globl _EP8FIFOBUF
                             75 	.globl _EP6FIFOBUF
                             76 	.globl _EP4FIFOBUF
                             77 	.globl _EP2FIFOBUF
                             78 	.globl _EP1INBUF
                             79 	.globl _EP1OUTBUF
                             80 	.globl _EP0BUF
                             81 	.globl _CT4
                             82 	.globl _CT3
                             83 	.globl _CT2
                             84 	.globl _CT1
                             85 	.globl _USBTEST
                             86 	.globl _TESTCFG
                             87 	.globl _DBUG
                             88 	.globl _UDMACRCQUAL
                             89 	.globl _UDMACRCL
                             90 	.globl _UDMACRCH
                             91 	.globl _GPIFHOLDAMOUNT
                             92 	.globl _FLOWSTBHPERIOD
                             93 	.globl _FLOWSTBEDGE
                             94 	.globl _FLOWSTB
                             95 	.globl _FLOWHOLDOFF
                             96 	.globl _FLOWEQ1CTL
                             97 	.globl _FLOWEQ0CTL
                             98 	.globl _FLOWLOGIC
                             99 	.globl _FLOWSTATE
                            100 	.globl _GPIFABORT
                            101 	.globl _GPIFREADYSTAT
                            102 	.globl _GPIFREADYCFG
                            103 	.globl _XGPIFSGLDATLNOX
                            104 	.globl _XGPIFSGLDATLX
                            105 	.globl _XGPIFSGLDATH
                            106 	.globl _EP8GPIFTRIG
                            107 	.globl _EP8GPIFPFSTOP
                            108 	.globl _EP8GPIFFLGSEL
                            109 	.globl _EP6GPIFTRIG
                            110 	.globl _EP6GPIFPFSTOP
                            111 	.globl _EP6GPIFFLGSEL
                            112 	.globl _EP4GPIFTRIG
                            113 	.globl _EP4GPIFPFSTOP
                            114 	.globl _EP4GPIFFLGSEL
                            115 	.globl _EP2GPIFTRIG
                            116 	.globl _EP2GPIFPFSTOP
                            117 	.globl _EP2GPIFFLGSEL
                            118 	.globl _GPIFTCB0
                            119 	.globl _GPIFTCB1
                            120 	.globl _GPIFTCB2
                            121 	.globl _GPIFTCB3
                            122 	.globl _GPIFADRL
                            123 	.globl _GPIFADRH
                            124 	.globl _GPIFCTLCFG
                            125 	.globl _GPIFIDLECTL
                            126 	.globl _GPIFIDLECS
                            127 	.globl _GPIFWFSELECT
                            128 	.globl _SETUPDAT
                            129 	.globl _SUDPTRCTL
                            130 	.globl _SUDPTRL
                            131 	.globl _SUDPTRH
                            132 	.globl _EP8FIFOBCL
                            133 	.globl _EP8FIFOBCH
                            134 	.globl _EP6FIFOBCL
                            135 	.globl _EP6FIFOBCH
                            136 	.globl _EP4FIFOBCL
                            137 	.globl _EP4FIFOBCH
                            138 	.globl _EP2FIFOBCL
                            139 	.globl _EP2FIFOBCH
                            140 	.globl _EP8FIFOFLGS
                            141 	.globl _EP6FIFOFLGS
                            142 	.globl _EP4FIFOFLGS
                            143 	.globl _EP2FIFOFLGS
                            144 	.globl _EP8CS
                            145 	.globl _EP6CS
                            146 	.globl _EP4CS
                            147 	.globl _EP2CS
                            148 	.globl _EP1INCS
                            149 	.globl _EP1OUTCS
                            150 	.globl _EP0CS
                            151 	.globl _EP8BCL
                            152 	.globl _EP8BCH
                            153 	.globl _EP6BCL
                            154 	.globl _EP6BCH
                            155 	.globl _EP4BCL
                            156 	.globl _EP4BCH
                            157 	.globl _EP2BCL
                            158 	.globl _EP2BCH
                            159 	.globl _EP1INBC
                            160 	.globl _EP1OUTBC
                            161 	.globl _EP0BCL
                            162 	.globl _EP0BCH
                            163 	.globl _FNADDR
                            164 	.globl _MICROFRAME
                            165 	.globl _USBFRAMEL
                            166 	.globl _USBFRAMEH
                            167 	.globl _TOGCTL
                            168 	.globl _WAKEUPCS
                            169 	.globl _SUSPEND
                            170 	.globl _USBCS
                            171 	.globl _XAUTODAT2
                            172 	.globl _XAUTODAT1
                            173 	.globl _I2CTL
                            174 	.globl _I2DAT
                            175 	.globl _I2CS
                            176 	.globl _PORTECFG
                            177 	.globl _PORTCCFG
                            178 	.globl _PORTACFG
                            179 	.globl _INTSETUP
                            180 	.globl _INT4IVEC
                            181 	.globl _INT2IVEC
                            182 	.globl _CLRERRCNT
                            183 	.globl _ERRCNTLIM
                            184 	.globl _USBERRIRQ
                            185 	.globl _USBERRIE
                            186 	.globl _GPIFIRQ
                            187 	.globl _GPIFIE
                            188 	.globl _EPIRQ
                            189 	.globl _EPIE
                            190 	.globl _USBIRQ
                            191 	.globl _USBIE
                            192 	.globl _NAKIRQ
                            193 	.globl _NAKIE
                            194 	.globl _IBNIRQ
                            195 	.globl _IBNIE
                            196 	.globl _EP8FIFOIRQ
                            197 	.globl _EP8FIFOIE
                            198 	.globl _EP6FIFOIRQ
                            199 	.globl _EP6FIFOIE
                            200 	.globl _EP4FIFOIRQ
                            201 	.globl _EP4FIFOIE
                            202 	.globl _EP2FIFOIRQ
                            203 	.globl _EP2FIFOIE
                            204 	.globl _OUTPKTEND
                            205 	.globl _INPKTEND
                            206 	.globl _EP8ISOINPKTS
                            207 	.globl _EP6ISOINPKTS
                            208 	.globl _EP4ISOINPKTS
                            209 	.globl _EP2ISOINPKTS
                            210 	.globl _EP8FIFOPFL
                            211 	.globl _EP8FIFOPFH
                            212 	.globl _EP6FIFOPFL
                            213 	.globl _EP6FIFOPFH
                            214 	.globl _EP4FIFOPFL
                            215 	.globl _EP4FIFOPFH
                            216 	.globl _EP2FIFOPFL
                            217 	.globl _EP2FIFOPFH
                            218 	.globl _EP8AUTOINLENL
                            219 	.globl _EP8AUTOINLENH
                            220 	.globl _EP6AUTOINLENL
                            221 	.globl _EP6AUTOINLENH
                            222 	.globl _EP4AUTOINLENL
                            223 	.globl _EP4AUTOINLENH
                            224 	.globl _EP2AUTOINLENL
                            225 	.globl _EP2AUTOINLENH
                            226 	.globl _EP8FIFOCFG
                            227 	.globl _EP6FIFOCFG
                            228 	.globl _EP4FIFOCFG
                            229 	.globl _EP2FIFOCFG
                            230 	.globl _EP8CFG
                            231 	.globl _EP6CFG
                            232 	.globl _EP4CFG
                            233 	.globl _EP2CFG
                            234 	.globl _EP1INCFG
                            235 	.globl _EP1OUTCFG
                            236 	.globl _REVCTL
                            237 	.globl _REVID
                            238 	.globl _FIFOPINPOLAR
                            239 	.globl _UART230
                            240 	.globl _BPADDRL
                            241 	.globl _BPADDRH
                            242 	.globl _BREAKPT
                            243 	.globl _FIFORESET
                            244 	.globl _PINFLAGSCD
                            245 	.globl _PINFLAGSAB
                            246 	.globl _IFCONFIG
                            247 	.globl _CPUCS
                            248 	.globl _RES_WAVEDATA_END
                            249 	.globl _GPIF_WAVE_DATA
                            250 ;--------------------------------------------------------
                            251 ; special function registers
                            252 ;--------------------------------------------------------
                            253 	.area RSEG    (ABS,DATA)
   0000                     254 	.org 0x0000
                    0080    255 _IOA	=	0x0080
                    0081    256 _SP	=	0x0081
                    0082    257 _DPL	=	0x0082
                    0083    258 _DPH	=	0x0083
                    0084    259 _DPL1	=	0x0084
                    0085    260 _DPH1	=	0x0085
                    0086    261 _DPS	=	0x0086
                    0087    262 _PCON	=	0x0087
                    0088    263 _TCON	=	0x0088
                    0089    264 _TMOD	=	0x0089
                    008A    265 _TL0	=	0x008a
                    008B    266 _TL1	=	0x008b
                    008C    267 _TH0	=	0x008c
                    008D    268 _TH1	=	0x008d
                    008E    269 _CKCO	=	0x008e
                    008F    270 _SPC_	=	0x008f
                    0090    271 _IOB	=	0x0090
                    0091    272 _EXIF	=	0x0091
                    0092    273 _MPA	=	0x0092
                    0098    274 _SCO	=	0x0098
                    0099    275 _SBU	=	0x0099
                    009A    276 _APTR1H	=	0x009a
                    009B    277 _APTR1L	=	0x009b
                    009C    278 _AUTODAT1	=	0x009c
                    009D    279 _AUTOPTRH2	=	0x009d
                    009E    280 _AUTOPTRL2	=	0x009e
                    009F    281 _AUTODAT2	=	0x009f
                    00A0    282 _IOC	=	0x00a0
                    00A1    283 _INT2CLR	=	0x00a1
                    00A2    284 _INT4CLR	=	0x00a2
                    00A8    285 _IE	=	0x00a8
                    00AA    286 _EP2468STAT	=	0x00aa
                    00AB    287 _EP24FIFOFLGS	=	0x00ab
                    00AC    288 _EP68FIFOFLGS	=	0x00ac
                    00AF    289 _AUTOPTRSETUP	=	0x00af
                    00B0    290 _IOD	=	0x00b0
                    00B1    291 _IOE	=	0x00b1
                    00B2    292 _OEA	=	0x00b2
                    00B3    293 _OEB	=	0x00b3
                    00B4    294 _OEC	=	0x00b4
                    00B5    295 _OED	=	0x00b5
                    00B6    296 _OEE	=	0x00b6
                    00B8    297 _IP	=	0x00b8
                    00BA    298 _EP01STAT	=	0x00ba
                    00BB    299 _GPIFTRIG	=	0x00bb
                    00BD    300 _GPIFSGLDATH	=	0x00bd
                    00BE    301 _GPIFSGLDATLX	=	0x00be
                    00BF    302 _GPIFSGLDATLNOX	=	0x00bf
                    00C0    303 _SCON1	=	0x00c0
                    00C1    304 _SBUF1	=	0x00c1
                    00C8    305 _T2CON	=	0x00c8
                    00CA    306 _RCAP2L	=	0x00ca
                    00CB    307 _RCAP2H	=	0x00cb
                    00CC    308 _TL2	=	0x00cc
                    00CD    309 _TH2	=	0x00cd
                    00D0    310 _PSW	=	0x00d0
                    00D8    311 _EICON	=	0x00d8
                    00E0    312 _ACC	=	0x00e0
                    00E8    313 _EIE	=	0x00e8
                    00F0    314 _B	=	0x00f0
                    00F8    315 _EIP	=	0x00f8
                            316 ;--------------------------------------------------------
                            317 ; special function bits
                            318 ;--------------------------------------------------------
                            319 	.area RSEG    (ABS,DATA)
   0000                     320 	.org 0x0000
                            321 ;--------------------------------------------------------
                            322 ; overlayable register banks
                            323 ;--------------------------------------------------------
                            324 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     325 	.ds 8
                            326 ;--------------------------------------------------------
                            327 ; internal ram data
                            328 ;--------------------------------------------------------
                            329 	.area DSEG    (DATA)
                            330 ;--------------------------------------------------------
                            331 ; overlayable items in internal ram 
                            332 ;--------------------------------------------------------
                            333 	.area	OSEG    (OVR,DATA)
                            334 ;--------------------------------------------------------
                            335 ; Stack segment in internal ram 
                            336 ;--------------------------------------------------------
                            337 	.area	SSEG	(DATA)
   0008                     338 __start__stack:
   0008                     339 	.ds	1
                            340 
                            341 ;--------------------------------------------------------
                            342 ; indirectly addressable internal ram data
                            343 ;--------------------------------------------------------
                            344 	.area ISEG    (DATA)
                            345 ;--------------------------------------------------------
                            346 ; absolute internal ram data
                            347 ;--------------------------------------------------------
                            348 	.area IABS    (ABS,DATA)
                            349 	.area IABS    (ABS,DATA)
                            350 ;--------------------------------------------------------
                            351 ; bit data
                            352 ;--------------------------------------------------------
                            353 	.area BSEG    (BIT)
                            354 ;--------------------------------------------------------
                            355 ; paged external ram data
                            356 ;--------------------------------------------------------
                            357 	.area PSEG    (PAG,XDATA)
                            358 ;--------------------------------------------------------
                            359 ; external ram data
                            360 ;--------------------------------------------------------
                            361 	.area XSEG    (XDATA)
                    E400    362 _GPIF_WAVE_DATA	=	0xe400
                    E480    363 _RES_WAVEDATA_END	=	0xe480
                    E600    364 _CPUCS	=	0xe600
                    E601    365 _IFCONFIG	=	0xe601
                    E602    366 _PINFLAGSAB	=	0xe602
                    E603    367 _PINFLAGSCD	=	0xe603
                    E604    368 _FIFORESET	=	0xe604
                    E605    369 _BREAKPT	=	0xe605
                    E606    370 _BPADDRH	=	0xe606
                    E607    371 _BPADDRL	=	0xe607
                    E608    372 _UART230	=	0xe608
                    E609    373 _FIFOPINPOLAR	=	0xe609
                    E60A    374 _REVID	=	0xe60a
                    E60B    375 _REVCTL	=	0xe60b
                    E610    376 _EP1OUTCFG	=	0xe610
                    E611    377 _EP1INCFG	=	0xe611
                    E612    378 _EP2CFG	=	0xe612
                    E613    379 _EP4CFG	=	0xe613
                    E614    380 _EP6CFG	=	0xe614
                    E615    381 _EP8CFG	=	0xe615
                    E618    382 _EP2FIFOCFG	=	0xe618
                    E619    383 _EP4FIFOCFG	=	0xe619
                    E61A    384 _EP6FIFOCFG	=	0xe61a
                    E61B    385 _EP8FIFOCFG	=	0xe61b
                    E620    386 _EP2AUTOINLENH	=	0xe620
                    E621    387 _EP2AUTOINLENL	=	0xe621
                    E622    388 _EP4AUTOINLENH	=	0xe622
                    E623    389 _EP4AUTOINLENL	=	0xe623
                    E624    390 _EP6AUTOINLENH	=	0xe624
                    E625    391 _EP6AUTOINLENL	=	0xe625
                    E626    392 _EP8AUTOINLENH	=	0xe626
                    E627    393 _EP8AUTOINLENL	=	0xe627
                    E630    394 _EP2FIFOPFH	=	0xe630
                    E631    395 _EP2FIFOPFL	=	0xe631
                    E632    396 _EP4FIFOPFH	=	0xe632
                    E633    397 _EP4FIFOPFL	=	0xe633
                    E634    398 _EP6FIFOPFH	=	0xe634
                    E635    399 _EP6FIFOPFL	=	0xe635
                    E636    400 _EP8FIFOPFH	=	0xe636
                    E637    401 _EP8FIFOPFL	=	0xe637
                    E640    402 _EP2ISOINPKTS	=	0xe640
                    E641    403 _EP4ISOINPKTS	=	0xe641
                    E642    404 _EP6ISOINPKTS	=	0xe642
                    E643    405 _EP8ISOINPKTS	=	0xe643
                    E648    406 _INPKTEND	=	0xe648
                    E649    407 _OUTPKTEND	=	0xe649
                    E650    408 _EP2FIFOIE	=	0xe650
                    E651    409 _EP2FIFOIRQ	=	0xe651
                    E652    410 _EP4FIFOIE	=	0xe652
                    E653    411 _EP4FIFOIRQ	=	0xe653
                    E654    412 _EP6FIFOIE	=	0xe654
                    E655    413 _EP6FIFOIRQ	=	0xe655
                    E656    414 _EP8FIFOIE	=	0xe656
                    E657    415 _EP8FIFOIRQ	=	0xe657
                    E658    416 _IBNIE	=	0xe658
                    E659    417 _IBNIRQ	=	0xe659
                    E65A    418 _NAKIE	=	0xe65a
                    E65B    419 _NAKIRQ	=	0xe65b
                    E65C    420 _USBIE	=	0xe65c
                    E65D    421 _USBIRQ	=	0xe65d
                    E65E    422 _EPIE	=	0xe65e
                    E65F    423 _EPIRQ	=	0xe65f
                    E660    424 _GPIFIE	=	0xe660
                    E661    425 _GPIFIRQ	=	0xe661
                    E662    426 _USBERRIE	=	0xe662
                    E663    427 _USBERRIRQ	=	0xe663
                    E664    428 _ERRCNTLIM	=	0xe664
                    E665    429 _CLRERRCNT	=	0xe665
                    E666    430 _INT2IVEC	=	0xe666
                    E667    431 _INT4IVEC	=	0xe667
                    E668    432 _INTSETUP	=	0xe668
                    E670    433 _PORTACFG	=	0xe670
                    E671    434 _PORTCCFG	=	0xe671
                    E672    435 _PORTECFG	=	0xe672
                    E678    436 _I2CS	=	0xe678
                    E679    437 _I2DAT	=	0xe679
                    E67A    438 _I2CTL	=	0xe67a
                    E67B    439 _XAUTODAT1	=	0xe67b
                    E67C    440 _XAUTODAT2	=	0xe67c
                    E680    441 _USBCS	=	0xe680
                    E681    442 _SUSPEND	=	0xe681
                    E682    443 _WAKEUPCS	=	0xe682
                    E683    444 _TOGCTL	=	0xe683
                    E684    445 _USBFRAMEH	=	0xe684
                    E685    446 _USBFRAMEL	=	0xe685
                    E686    447 _MICROFRAME	=	0xe686
                    E687    448 _FNADDR	=	0xe687
                    E68A    449 _EP0BCH	=	0xe68a
                    E68B    450 _EP0BCL	=	0xe68b
                    E68D    451 _EP1OUTBC	=	0xe68d
                    E68F    452 _EP1INBC	=	0xe68f
                    E690    453 _EP2BCH	=	0xe690
                    E691    454 _EP2BCL	=	0xe691
                    E694    455 _EP4BCH	=	0xe694
                    E695    456 _EP4BCL	=	0xe695
                    E698    457 _EP6BCH	=	0xe698
                    E699    458 _EP6BCL	=	0xe699
                    E69C    459 _EP8BCH	=	0xe69c
                    E69D    460 _EP8BCL	=	0xe69d
                    E6A0    461 _EP0CS	=	0xe6a0
                    E6A1    462 _EP1OUTCS	=	0xe6a1
                    E6A2    463 _EP1INCS	=	0xe6a2
                    E6A3    464 _EP2CS	=	0xe6a3
                    E6A4    465 _EP4CS	=	0xe6a4
                    E6A5    466 _EP6CS	=	0xe6a5
                    E6A6    467 _EP8CS	=	0xe6a6
                    E6A7    468 _EP2FIFOFLGS	=	0xe6a7
                    E6A8    469 _EP4FIFOFLGS	=	0xe6a8
                    E6A9    470 _EP6FIFOFLGS	=	0xe6a9
                    E6AA    471 _EP8FIFOFLGS	=	0xe6aa
                    E6AB    472 _EP2FIFOBCH	=	0xe6ab
                    E6AC    473 _EP2FIFOBCL	=	0xe6ac
                    E6AD    474 _EP4FIFOBCH	=	0xe6ad
                    E6AE    475 _EP4FIFOBCL	=	0xe6ae
                    E6AF    476 _EP6FIFOBCH	=	0xe6af
                    E6B0    477 _EP6FIFOBCL	=	0xe6b0
                    E6B1    478 _EP8FIFOBCH	=	0xe6b1
                    E6B2    479 _EP8FIFOBCL	=	0xe6b2
                    E6B3    480 _SUDPTRH	=	0xe6b3
                    E6B4    481 _SUDPTRL	=	0xe6b4
                    E6B5    482 _SUDPTRCTL	=	0xe6b5
                    E6B8    483 _SETUPDAT	=	0xe6b8
                    E6C0    484 _GPIFWFSELECT	=	0xe6c0
                    E6C1    485 _GPIFIDLECS	=	0xe6c1
                    E6C2    486 _GPIFIDLECTL	=	0xe6c2
                    E6C3    487 _GPIFCTLCFG	=	0xe6c3
                    E6C4    488 _GPIFADRH	=	0xe6c4
                    E6C5    489 _GPIFADRL	=	0xe6c5
                    E6CE    490 _GPIFTCB3	=	0xe6ce
                    E6CF    491 _GPIFTCB2	=	0xe6cf
                    E6D0    492 _GPIFTCB1	=	0xe6d0
                    E6D1    493 _GPIFTCB0	=	0xe6d1
                    E6D2    494 _EP2GPIFFLGSEL	=	0xe6d2
                    E6D3    495 _EP2GPIFPFSTOP	=	0xe6d3
                    E6D4    496 _EP2GPIFTRIG	=	0xe6d4
                    E6DA    497 _EP4GPIFFLGSEL	=	0xe6da
                    E6DB    498 _EP4GPIFPFSTOP	=	0xe6db
                    E6DC    499 _EP4GPIFTRIG	=	0xe6dc
                    E6E2    500 _EP6GPIFFLGSEL	=	0xe6e2
                    E6E3    501 _EP6GPIFPFSTOP	=	0xe6e3
                    E6E4    502 _EP6GPIFTRIG	=	0xe6e4
                    E6EA    503 _EP8GPIFFLGSEL	=	0xe6ea
                    E6EB    504 _EP8GPIFPFSTOP	=	0xe6eb
                    E6EC    505 _EP8GPIFTRIG	=	0xe6ec
                    E6F0    506 _XGPIFSGLDATH	=	0xe6f0
                    E6F1    507 _XGPIFSGLDATLX	=	0xe6f1
                    E6F2    508 _XGPIFSGLDATLNOX	=	0xe6f2
                    E6F3    509 _GPIFREADYCFG	=	0xe6f3
                    E6F4    510 _GPIFREADYSTAT	=	0xe6f4
                    E6F5    511 _GPIFABORT	=	0xe6f5
                    E6C6    512 _FLOWSTATE	=	0xe6c6
                    E6C7    513 _FLOWLOGIC	=	0xe6c7
                    E6C8    514 _FLOWEQ0CTL	=	0xe6c8
                    E6C9    515 _FLOWEQ1CTL	=	0xe6c9
                    E6CA    516 _FLOWHOLDOFF	=	0xe6ca
                    E6CB    517 _FLOWSTB	=	0xe6cb
                    E6CC    518 _FLOWSTBEDGE	=	0xe6cc
                    E6CD    519 _FLOWSTBHPERIOD	=	0xe6cd
                    E60C    520 _GPIFHOLDAMOUNT	=	0xe60c
                    E67D    521 _UDMACRCH	=	0xe67d
                    E67E    522 _UDMACRCL	=	0xe67e
                    E67F    523 _UDMACRCQUAL	=	0xe67f
                    E6F8    524 _DBUG	=	0xe6f8
                    E6F9    525 _TESTCFG	=	0xe6f9
                    E6FA    526 _USBTEST	=	0xe6fa
                    E6FB    527 _CT1	=	0xe6fb
                    E6FC    528 _CT2	=	0xe6fc
                    E6FD    529 _CT3	=	0xe6fd
                    E6FE    530 _CT4	=	0xe6fe
                    E740    531 _EP0BUF	=	0xe740
                    E780    532 _EP1OUTBUF	=	0xe780
                    E7C0    533 _EP1INBUF	=	0xe7c0
                    F000    534 _EP2FIFOBUF	=	0xf000
                    F400    535 _EP4FIFOBUF	=	0xf400
                    F800    536 _EP6FIFOBUF	=	0xf800
                    FC00    537 _EP8FIFOBUF	=	0xfc00
                            538 ;--------------------------------------------------------
                            539 ; absolute external ram data
                            540 ;--------------------------------------------------------
                            541 	.area XABS    (ABS,XDATA)
                            542 ;--------------------------------------------------------
                            543 ; external initialized ram data
                            544 ;--------------------------------------------------------
                            545 	.area XISEG   (XDATA)
                            546 	.area HOME    (CODE)
                            547 	.area GSINIT0 (CODE)
                            548 	.area GSINIT1 (CODE)
                            549 	.area GSINIT2 (CODE)
                            550 	.area GSINIT3 (CODE)
                            551 	.area GSINIT4 (CODE)
                            552 	.area GSINIT5 (CODE)
                            553 	.area GSINIT  (CODE)
                            554 	.area GSFINAL (CODE)
                            555 	.area CSEG    (CODE)
                            556 ;--------------------------------------------------------
                            557 ; interrupt vector 
                            558 ;--------------------------------------------------------
                            559 	.area HOME    (CODE)
   0000                     560 __interrupt_vect:
   0000 02 00 08            561 	ljmp	__sdcc_gsinit_startup
                            562 ;--------------------------------------------------------
                            563 ; global & static initialisations
                            564 ;--------------------------------------------------------
                            565 	.area HOME    (CODE)
                            566 	.area GSINIT  (CODE)
                            567 	.area GSFINAL (CODE)
                            568 	.area GSINIT  (CODE)
                            569 	.globl __sdcc_gsinit_startup
                            570 	.globl __sdcc_program_startup
                            571 	.globl __start__stack
                            572 	.globl __mcs51_genXINIT
                            573 	.globl __mcs51_genXRAMCLEAR
                            574 	.globl __mcs51_genRAMCLEAR
                            575 	.area GSFINAL (CODE)
   0061 02 00 03            576 	ljmp	__sdcc_program_startup
                            577 ;--------------------------------------------------------
                            578 ; Home
                            579 ;--------------------------------------------------------
                            580 	.area HOME    (CODE)
                            581 	.area HOME    (CODE)
   0003                     582 __sdcc_program_startup:
   0003 12 04 70            583 	lcall	_main
                            584 ;	return from main will lock up
   0006 80 FE               585 	sjmp .
                            586 ;--------------------------------------------------------
                            587 ; code
                            588 ;--------------------------------------------------------
                            589 	.area CSEG    (CODE)
                            590 ;------------------------------------------------------------
                            591 ;Allocation info for local variables in function 'Initialize'
                            592 ;------------------------------------------------------------
                            593 ;cfg_data                  Allocated to registers 
                            594 ;cfg_data_ok               Allocated to registers r7 
                            595 ;EP2FIFOPOLARITY           Allocated to registers 
                            596 ;------------------------------------------------------------
                            597 ;	fx2pipe.c:109: static void Initialize(void)
                            598 ;	-----------------------------------------
                            599 ;	 function Initialize
                            600 ;	-----------------------------------------
   0064                     601 _Initialize:
                    0007    602 	ar7 = 0x07
                    0006    603 	ar6 = 0x06
                    0005    604 	ar5 = 0x05
                    0004    605 	ar4 = 0x04
                    0003    606 	ar3 = 0x03
                    0002    607 	ar2 = 0x02
                    0001    608 	ar1 = 0x01
                    0000    609 	ar0 = 0x00
                            610 ;	fx2pipe.c:123: cfg_data[4] = 0x12;  // 0x12
   0064 90 10 08            611 	mov	dptr,#0x1008
   0067 74 12               612 	mov	a,#0x12
   0069 F0                  613 	movx	@dptr,a
                            614 ;	fx2pipe.c:126: cfg_data[1] = 0xc3;
                            615 ;	fx2pipe.c:128: cfg_data[1] = 0x43;
                            616 ;	fx2pipe.c:130: cfg_data[1] = 0x53;
   006A 90 10 05            617 	mov	dptr,#0x1005
   006D 74 C3               618 	mov	a,#0xC3
   006F F0                  619 	movx	@dptr,a
   0070 74 43               620 	mov	a,#0x43
   0072 F0                  621 	movx	@dptr,a
   0073 74 53               622 	mov	a,#0x53
   0075 F0                  623 	movx	@dptr,a
                            624 ;	fx2pipe.c:141: cfg_data[0] = 0x21U;
   0076 90 10 04            625 	mov	dptr,#0x1004
   0079 74 21               626 	mov	a,#0x21
   007B F0                  627 	movx	@dptr,a
                            628 ;	fx2pipe.c:145: cfg_data[2] = 0xa0;  // bulk: 0xa2 double-buffered; 0xa3 triple-; 0xa0 quad
   007C 90 10 06            629 	mov	dptr,#0x1006
   007F 74 A0               630 	mov	a,#0xA0
   0081 F0                  631 	movx	@dptr,a
                            632 ;	fx2pipe.c:148: cfg_data[3] = 0x11; // AUTOOUT, or Ox15
                            633 ;	fx2pipe.c:149: cfg_data[3] = 0x10; // AUTOOUT, or Ox15 width narrow
   0082 90 10 07            634 	mov	dptr,#0x1007
   0085 74 11               635 	mov	a,#0x11
   0087 F0                  636 	movx	@dptr,a
   0088 74 10               637 	mov	a,#0x10
   008A F0                  638 	movx	@dptr,a
                            639 ;	fx2pipe.c:154: cfg_data_ok = (cfg_data[0]==0x12U || cfg_data[0]==0x21U);
   008B 90 10 04            640 	mov	dptr,#0x1004
   008E E0                  641 	movx	a,@dptr
   008F FE                  642 	mov	r6,a
   0090 33                  643 	rlc	a
   0091 95 E0               644 	subb	a,acc
   0093 FF                  645 	mov	r7,a
   0094 BE 12 05            646 	cjne	r6,#0x12,00134$
   0097 BF 00 02            647 	cjne	r7,#0x00,00134$
   009A 80 0C               648 	sjmp	00112$
   009C                     649 00134$:
   009C BE 21 05            650 	cjne	r6,#0x21,00135$
   009F BF 00 02            651 	cjne	r7,#0x00,00135$
   00A2 80 04               652 	sjmp	00112$
   00A4                     653 00135$:
   00A4 7F 00               654 	mov	r7,#0x00
   00A6 80 02               655 	sjmp	00113$
   00A8                     656 00112$:
   00A8 7F 01               657 	mov	r7,#0x01
   00AA                     658 00113$:
                            659 ;	fx2pipe.c:156: SYNCDELAY;
   00AA 00                  660 	nop 
   00AB 00                  661 	nop 
   00AC 00                  662 	nop 
   00AD 00                  663 	nop 
   00AE 00                  664 	nop 
   00AF 00                  665 	nop 
   00B0 00                  666 	nop 
   00B1 00                  667 	nop 
   00B2 00                  668 	nop 
   00B3 00                  669 	nop 
   00B4 00                  670 	nop 
   00B5 00                  671 	nop 
   00B6 00                  672 	nop 
   00B7 00                  673 	nop 
   00B8 00                  674 	nop 
   00B9 00                  675 	nop 
   00BA 00                  676 	nop 
                            677 ;	fx2pipe.c:166: CPUCS = cfg_data_ok ? cfg_data[4] : 0x12;  // 0x12
   00BB EF                  678 	mov	a,r7
   00BC 60 07               679 	jz	00114$
   00BE 90 10 08            680 	mov	dptr,#0x1008
   00C1 E0                  681 	movx	a,@dptr
   00C2 FE                  682 	mov	r6,a
   00C3 80 02               683 	sjmp	00115$
   00C5                     684 00114$:
   00C5 7E 12               685 	mov	r6,#0x12
   00C7                     686 00115$:
   00C7 90 E6 00            687 	mov	dptr,#_CPUCS
   00CA EE                  688 	mov	a,r6
   00CB F0                  689 	movx	@dptr,a
                            690 ;	fx2pipe.c:167: SYNCDELAY;
   00CC 00                  691 	nop 
   00CD 00                  692 	nop 
   00CE 00                  693 	nop 
   00CF 00                  694 	nop 
   00D0 00                  695 	nop 
   00D1 00                  696 	nop 
   00D2 00                  697 	nop 
   00D3 00                  698 	nop 
   00D4 00                  699 	nop 
   00D5 00                  700 	nop 
   00D6 00                  701 	nop 
   00D7 00                  702 	nop 
   00D8 00                  703 	nop 
   00D9 00                  704 	nop 
   00DA 00                  705 	nop 
   00DB 00                  706 	nop 
   00DC 00                  707 	nop 
                            708 ;	fx2pipe.c:182: IFCONFIG = cfg_data_ok ? cfg_data[1] : 0xc3;
   00DD EF                  709 	mov	a,r7
   00DE 60 07               710 	jz	00116$
   00E0 90 10 05            711 	mov	dptr,#0x1005
   00E3 E0                  712 	movx	a,@dptr
   00E4 FF                  713 	mov	r7,a
   00E5 80 02               714 	sjmp	00117$
   00E7                     715 00116$:
   00E7 7F C3               716 	mov	r7,#0xC3
   00E9                     717 00117$:
   00E9 90 E6 01            718 	mov	dptr,#_IFCONFIG
   00EC EF                  719 	mov	a,r7
   00ED F0                  720 	movx	@dptr,a
                            721 ;	fx2pipe.c:183: SYNCDELAY;
   00EE 00                  722 	nop 
   00EF 00                  723 	nop 
   00F0 00                  724 	nop 
   00F1 00                  725 	nop 
   00F2 00                  726 	nop 
   00F3 00                  727 	nop 
   00F4 00                  728 	nop 
   00F5 00                  729 	nop 
   00F6 00                  730 	nop 
   00F7 00                  731 	nop 
   00F8 00                  732 	nop 
   00F9 00                  733 	nop 
   00FA 00                  734 	nop 
   00FB 00                  735 	nop 
   00FC 00                  736 	nop 
   00FD 00                  737 	nop 
   00FE 00                  738 	nop 
                            739 ;	fx2pipe.c:186: REVCTL = 0x03;  // See TRM...
   00FF 90 E6 0B            740 	mov	dptr,#_REVCTL
   0102 74 03               741 	mov	a,#0x03
   0104 F0                  742 	movx	@dptr,a
                            743 ;	fx2pipe.c:187: SYNCDELAY;
   0105 00                  744 	nop 
   0106 00                  745 	nop 
   0107 00                  746 	nop 
   0108 00                  747 	nop 
   0109 00                  748 	nop 
   010A 00                  749 	nop 
   010B 00                  750 	nop 
   010C 00                  751 	nop 
   010D 00                  752 	nop 
   010E 00                  753 	nop 
   010F 00                  754 	nop 
   0110 00                  755 	nop 
   0111 00                  756 	nop 
   0112 00                  757 	nop 
   0113 00                  758 	nop 
   0114 00                  759 	nop 
   0115 00                  760 	nop 
                            761 ;	fx2pipe.c:190: PORTACFG = 0x00;
   0116 90 E6 70            762 	mov	dptr,#_PORTACFG
   0119 E4                  763 	clr	a
   011A F0                  764 	movx	@dptr,a
                            765 ;	fx2pipe.c:191: SYNCDELAY; // maybe not needed
   011B 00                  766 	nop 
   011C 00                  767 	nop 
   011D 00                  768 	nop 
   011E 00                  769 	nop 
   011F 00                  770 	nop 
   0120 00                  771 	nop 
   0121 00                  772 	nop 
   0122 00                  773 	nop 
   0123 00                  774 	nop 
   0124 00                  775 	nop 
   0125 00                  776 	nop 
   0126 00                  777 	nop 
   0127 00                  778 	nop 
   0128 00                  779 	nop 
   0129 00                  780 	nop 
   012A 00                  781 	nop 
   012B 00                  782 	nop 
                            783 ;	fx2pipe.c:194: FIFOPINPOLAR=0x00;
   012C 90 E6 09            784 	mov	dptr,#_FIFOPINPOLAR
   012F E4                  785 	clr	a
   0130 F0                  786 	movx	@dptr,a
                            787 ;	fx2pipe.c:195: SYNCDELAY;
   0131 00                  788 	nop 
   0132 00                  789 	nop 
   0133 00                  790 	nop 
   0134 00                  791 	nop 
   0135 00                  792 	nop 
   0136 00                  793 	nop 
   0137 00                  794 	nop 
   0138 00                  795 	nop 
   0139 00                  796 	nop 
   013A 00                  797 	nop 
   013B 00                  798 	nop 
   013C 00                  799 	nop 
   013D 00                  800 	nop 
   013E 00                  801 	nop 
   013F 00                  802 	nop 
   0140 00                  803 	nop 
   0141 00                  804 	nop 
                            805 ;	fx2pipe.c:198: EP6CFG=0x00U;  SYNCDELAY;
   0142 90 E6 14            806 	mov	dptr,#_EP6CFG
   0145 E4                  807 	clr	a
   0146 F0                  808 	movx	@dptr,a
   0147 00                  809 	nop 
   0148 00                  810 	nop 
   0149 00                  811 	nop 
   014A 00                  812 	nop 
   014B 00                  813 	nop 
   014C 00                  814 	nop 
   014D 00                  815 	nop 
   014E 00                  816 	nop 
   014F 00                  817 	nop 
   0150 00                  818 	nop 
   0151 00                  819 	nop 
   0152 00                  820 	nop 
   0153 00                  821 	nop 
   0154 00                  822 	nop 
   0155 00                  823 	nop 
   0156 00                  824 	nop 
   0157 00                  825 	nop 
                            826 ;	fx2pipe.c:199: EP2CFG=0x00U;  SYNCDELAY;
   0158 90 E6 12            827 	mov	dptr,#_EP2CFG
   015B E4                  828 	clr	a
   015C F0                  829 	movx	@dptr,a
   015D 00                  830 	nop 
   015E 00                  831 	nop 
   015F 00                  832 	nop 
   0160 00                  833 	nop 
   0161 00                  834 	nop 
   0162 00                  835 	nop 
   0163 00                  836 	nop 
   0164 00                  837 	nop 
   0165 00                  838 	nop 
   0166 00                  839 	nop 
   0167 00                  840 	nop 
   0168 00                  841 	nop 
   0169 00                  842 	nop 
   016A 00                  843 	nop 
   016B 00                  844 	nop 
   016C 00                  845 	nop 
   016D 00                  846 	nop 
                            847 ;	fx2pipe.c:200: EP4CFG=0x00U;  SYNCDELAY;
   016E 90 E6 13            848 	mov	dptr,#_EP4CFG
   0171 E4                  849 	clr	a
   0172 F0                  850 	movx	@dptr,a
   0173 00                  851 	nop 
   0174 00                  852 	nop 
   0175 00                  853 	nop 
   0176 00                  854 	nop 
   0177 00                  855 	nop 
   0178 00                  856 	nop 
   0179 00                  857 	nop 
   017A 00                  858 	nop 
   017B 00                  859 	nop 
   017C 00                  860 	nop 
   017D 00                  861 	nop 
   017E 00                  862 	nop 
   017F 00                  863 	nop 
   0180 00                  864 	nop 
   0181 00                  865 	nop 
   0182 00                  866 	nop 
   0183 00                  867 	nop 
                            868 ;	fx2pipe.c:201: EP8CFG=0x00U;  SYNCDELAY;
   0184 90 E6 15            869 	mov	dptr,#_EP8CFG
   0187 E4                  870 	clr	a
   0188 F0                  871 	movx	@dptr,a
   0189 00                  872 	nop 
   018A 00                  873 	nop 
   018B 00                  874 	nop 
   018C 00                  875 	nop 
   018D 00                  876 	nop 
   018E 00                  877 	nop 
   018F 00                  878 	nop 
   0190 00                  879 	nop 
   0191 00                  880 	nop 
   0192 00                  881 	nop 
   0193 00                  882 	nop 
   0194 00                  883 	nop 
   0195 00                  884 	nop 
   0196 00                  885 	nop 
   0197 00                  886 	nop 
   0198 00                  887 	nop 
   0199 00                  888 	nop 
                            889 ;	fx2pipe.c:202: EP6FIFOCFG=0x00U;  SYNCDELAY;
   019A 90 E6 1A            890 	mov	dptr,#_EP6FIFOCFG
   019D E4                  891 	clr	a
   019E F0                  892 	movx	@dptr,a
   019F 00                  893 	nop 
   01A0 00                  894 	nop 
   01A1 00                  895 	nop 
   01A2 00                  896 	nop 
   01A3 00                  897 	nop 
   01A4 00                  898 	nop 
   01A5 00                  899 	nop 
   01A6 00                  900 	nop 
   01A7 00                  901 	nop 
   01A8 00                  902 	nop 
   01A9 00                  903 	nop 
   01AA 00                  904 	nop 
   01AB 00                  905 	nop 
   01AC 00                  906 	nop 
   01AD 00                  907 	nop 
   01AE 00                  908 	nop 
   01AF 00                  909 	nop 
                            910 ;	fx2pipe.c:203: EP2FIFOCFG=0x00U;  SYNCDELAY;
   01B0 90 E6 18            911 	mov	dptr,#_EP2FIFOCFG
   01B3 E4                  912 	clr	a
   01B4 F0                  913 	movx	@dptr,a
   01B5 00                  914 	nop 
   01B6 00                  915 	nop 
   01B7 00                  916 	nop 
   01B8 00                  917 	nop 
   01B9 00                  918 	nop 
   01BA 00                  919 	nop 
   01BB 00                  920 	nop 
   01BC 00                  921 	nop 
   01BD 00                  922 	nop 
   01BE 00                  923 	nop 
   01BF 00                  924 	nop 
   01C0 00                  925 	nop 
   01C1 00                  926 	nop 
   01C2 00                  927 	nop 
   01C3 00                  928 	nop 
   01C4 00                  929 	nop 
   01C5 00                  930 	nop 
                            931 ;	fx2pipe.c:204: EP8FIFOCFG=0x00U;  SYNCDELAY;
   01C6 90 E6 1B            932 	mov	dptr,#_EP8FIFOCFG
   01C9 E4                  933 	clr	a
   01CA F0                  934 	movx	@dptr,a
   01CB 00                  935 	nop 
   01CC 00                  936 	nop 
   01CD 00                  937 	nop 
   01CE 00                  938 	nop 
   01CF 00                  939 	nop 
   01D0 00                  940 	nop 
   01D1 00                  941 	nop 
   01D2 00                  942 	nop 
   01D3 00                  943 	nop 
   01D4 00                  944 	nop 
   01D5 00                  945 	nop 
   01D6 00                  946 	nop 
   01D7 00                  947 	nop 
   01D8 00                  948 	nop 
   01D9 00                  949 	nop 
   01DA 00                  950 	nop 
   01DB 00                  951 	nop 
                            952 ;	fx2pipe.c:205: EP4FIFOCFG=0x00U;  SYNCDELAY;
   01DC 90 E6 19            953 	mov	dptr,#_EP4FIFOCFG
   01DF E4                  954 	clr	a
   01E0 F0                  955 	movx	@dptr,a
   01E1 00                  956 	nop 
   01E2 00                  957 	nop 
   01E3 00                  958 	nop 
   01E4 00                  959 	nop 
   01E5 00                  960 	nop 
   01E6 00                  961 	nop 
   01E7 00                  962 	nop 
   01E8 00                  963 	nop 
   01E9 00                  964 	nop 
   01EA 00                  965 	nop 
   01EB 00                  966 	nop 
   01EC 00                  967 	nop 
   01ED 00                  968 	nop 
   01EE 00                  969 	nop 
   01EF 00                  970 	nop 
   01F0 00                  971 	nop 
   01F1 00                  972 	nop 
                            973 ;	fx2pipe.c:206: OEA=0x00U;  SYNCDELAY;
   01F2 75 B2 00            974 	mov	_OEA,#0x00
   01F5 00                  975 	nop 
   01F6 00                  976 	nop 
   01F7 00                  977 	nop 
   01F8 00                  978 	nop 
   01F9 00                  979 	nop 
   01FA 00                  980 	nop 
   01FB 00                  981 	nop 
   01FC 00                  982 	nop 
   01FD 00                  983 	nop 
   01FE 00                  984 	nop 
   01FF 00                  985 	nop 
   0200 00                  986 	nop 
   0201 00                  987 	nop 
   0202 00                  988 	nop 
   0203 00                  989 	nop 
   0204 00                  990 	nop 
   0205 00                  991 	nop 
                            992 ;	fx2pipe.c:207: OED=0x00U;  SYNCDELAY;
   0206 75 B5 00            993 	mov	_OED,#0x00
   0209 00                  994 	nop 
   020A 00                  995 	nop 
   020B 00                  996 	nop 
   020C 00                  997 	nop 
   020D 00                  998 	nop 
   020E 00                  999 	nop 
   020F 00                 1000 	nop 
   0210 00                 1001 	nop 
   0211 00                 1002 	nop 
   0212 00                 1003 	nop 
   0213 00                 1004 	nop 
   0214 00                 1005 	nop 
   0215 00                 1006 	nop 
   0216 00                 1007 	nop 
   0217 00                 1008 	nop 
   0218 00                 1009 	nop 
   0219 00                 1010 	nop 
                           1011 ;	fx2pipe.c:210: if(cfg_data[0]==0x12U) /* INPUT: USB->HOST */ // NOR FOR D2A
   021A 90 10 04           1012 	mov	dptr,#0x1004
   021D E0                 1013 	movx	a,@dptr
   021E FE                 1014 	mov	r6,a
   021F 33                 1015 	rlc	a
   0220 95 E0              1016 	subb	a,acc
   0222 FF                 1017 	mov	r7,a
   0223 BE 12 05           1018 	cjne	r6,#0x12,00138$
   0226 BF 00 02           1019 	cjne	r7,#0x00,00138$
   0229 80 03              1020 	sjmp	00139$
   022B                    1021 00138$:
   022B 02 03 19           1022 	ljmp	00107$
   022E                    1023 00139$:
                           1024 ;	fx2pipe.c:221: EP6CFG = cfg_data[2];  // bulk: 0xe2 double-buffered; 0xe3 triple-; 0xe0 quad
   022E 90 10 06           1025 	mov	dptr,#0x1006
   0231 E0                 1026 	movx	a,@dptr
   0232 FD                 1027 	mov	r5,a
   0233 90 E6 14           1028 	mov	dptr,#_EP6CFG
   0236 F0                 1029 	movx	@dptr,a
                           1030 ;	fx2pipe.c:222: SYNCDELAY;
   0237 00                 1031 	nop 
   0238 00                 1032 	nop 
   0239 00                 1033 	nop 
   023A 00                 1034 	nop 
   023B 00                 1035 	nop 
   023C 00                 1036 	nop 
   023D 00                 1037 	nop 
   023E 00                 1038 	nop 
   023F 00                 1039 	nop 
   0240 00                 1040 	nop 
   0241 00                 1041 	nop 
   0242 00                 1042 	nop 
   0243 00                 1043 	nop 
   0244 00                 1044 	nop 
   0245 00                 1045 	nop 
   0246 00                 1046 	nop 
   0247 00                 1047 	nop 
                           1048 ;	fx2pipe.c:226: FIFORESET = 0x80;  SYNCDELAY;  // NAK all requests from host.
   0248 90 E6 04           1049 	mov	dptr,#_FIFORESET
   024B 74 80              1050 	mov	a,#0x80
   024D F0                 1051 	movx	@dptr,a
   024E 00                 1052 	nop 
   024F 00                 1053 	nop 
   0250 00                 1054 	nop 
   0251 00                 1055 	nop 
   0252 00                 1056 	nop 
   0253 00                 1057 	nop 
   0254 00                 1058 	nop 
   0255 00                 1059 	nop 
   0256 00                 1060 	nop 
   0257 00                 1061 	nop 
   0258 00                 1062 	nop 
   0259 00                 1063 	nop 
   025A 00                 1064 	nop 
   025B 00                 1065 	nop 
   025C 00                 1066 	nop 
   025D 00                 1067 	nop 
   025E 00                 1068 	nop 
                           1069 ;	fx2pipe.c:227: FIFORESET = 0x82;  SYNCDELAY;  // Reset individual EP (2,4,6,8)
   025F 90 E6 04           1070 	mov	dptr,#_FIFORESET
   0262 74 82              1071 	mov	a,#0x82
   0264 F0                 1072 	movx	@dptr,a
   0265 00                 1073 	nop 
   0266 00                 1074 	nop 
   0267 00                 1075 	nop 
   0268 00                 1076 	nop 
   0269 00                 1077 	nop 
   026A 00                 1078 	nop 
   026B 00                 1079 	nop 
   026C 00                 1080 	nop 
   026D 00                 1081 	nop 
   026E 00                 1082 	nop 
   026F 00                 1083 	nop 
   0270 00                 1084 	nop 
   0271 00                 1085 	nop 
   0272 00                 1086 	nop 
   0273 00                 1087 	nop 
   0274 00                 1088 	nop 
   0275 00                 1089 	nop 
                           1090 ;	fx2pipe.c:228: FIFORESET = 0x84;  SYNCDELAY;
   0276 90 E6 04           1091 	mov	dptr,#_FIFORESET
   0279 74 84              1092 	mov	a,#0x84
   027B F0                 1093 	movx	@dptr,a
   027C 00                 1094 	nop 
   027D 00                 1095 	nop 
   027E 00                 1096 	nop 
   027F 00                 1097 	nop 
   0280 00                 1098 	nop 
   0281 00                 1099 	nop 
   0282 00                 1100 	nop 
   0283 00                 1101 	nop 
   0284 00                 1102 	nop 
   0285 00                 1103 	nop 
   0286 00                 1104 	nop 
   0287 00                 1105 	nop 
   0288 00                 1106 	nop 
   0289 00                 1107 	nop 
   028A 00                 1108 	nop 
   028B 00                 1109 	nop 
   028C 00                 1110 	nop 
                           1111 ;	fx2pipe.c:229: FIFORESET = 0x86;  SYNCDELAY;
   028D 90 E6 04           1112 	mov	dptr,#_FIFORESET
   0290 74 86              1113 	mov	a,#0x86
   0292 F0                 1114 	movx	@dptr,a
   0293 00                 1115 	nop 
   0294 00                 1116 	nop 
   0295 00                 1117 	nop 
   0296 00                 1118 	nop 
   0297 00                 1119 	nop 
   0298 00                 1120 	nop 
   0299 00                 1121 	nop 
   029A 00                 1122 	nop 
   029B 00                 1123 	nop 
   029C 00                 1124 	nop 
   029D 00                 1125 	nop 
   029E 00                 1126 	nop 
   029F 00                 1127 	nop 
   02A0 00                 1128 	nop 
   02A1 00                 1129 	nop 
   02A2 00                 1130 	nop 
   02A3 00                 1131 	nop 
                           1132 ;	fx2pipe.c:230: FIFORESET = 0x88;  SYNCDELAY;
   02A4 90 E6 04           1133 	mov	dptr,#_FIFORESET
   02A7 74 88              1134 	mov	a,#0x88
   02A9 F0                 1135 	movx	@dptr,a
   02AA 00                 1136 	nop 
   02AB 00                 1137 	nop 
   02AC 00                 1138 	nop 
   02AD 00                 1139 	nop 
   02AE 00                 1140 	nop 
   02AF 00                 1141 	nop 
   02B0 00                 1142 	nop 
   02B1 00                 1143 	nop 
   02B2 00                 1144 	nop 
   02B3 00                 1145 	nop 
   02B4 00                 1146 	nop 
   02B5 00                 1147 	nop 
   02B6 00                 1148 	nop 
   02B7 00                 1149 	nop 
   02B8 00                 1150 	nop 
   02B9 00                 1151 	nop 
   02BA 00                 1152 	nop 
                           1153 ;	fx2pipe.c:231: FIFORESET = 0x00;  SYNCDELAY;  // Resume normal operation.
   02BB 90 E6 04           1154 	mov	dptr,#_FIFORESET
   02BE E4                 1155 	clr	a
   02BF F0                 1156 	movx	@dptr,a
   02C0 00                 1157 	nop 
   02C1 00                 1158 	nop 
   02C2 00                 1159 	nop 
   02C3 00                 1160 	nop 
   02C4 00                 1161 	nop 
   02C5 00                 1162 	nop 
   02C6 00                 1163 	nop 
   02C7 00                 1164 	nop 
   02C8 00                 1165 	nop 
   02C9 00                 1166 	nop 
   02CA 00                 1167 	nop 
   02CB 00                 1168 	nop 
   02CC 00                 1169 	nop 
   02CD 00                 1170 	nop 
   02CE 00                 1171 	nop 
   02CF 00                 1172 	nop 
   02D0 00                 1173 	nop 
                           1174 ;	fx2pipe.c:243: EP6FIFOCFG = cfg_data[3]; /*0x0d //&0xfe*/;
   02D1 90 10 07           1175 	mov	dptr,#0x1007
   02D4 E0                 1176 	movx	a,@dptr
   02D5 FD                 1177 	mov	r5,a
   02D6 90 E6 1A           1178 	mov	dptr,#_EP6FIFOCFG
   02D9 F0                 1179 	movx	@dptr,a
                           1180 ;	fx2pipe.c:244: SYNCDELAY;
   02DA 00                 1181 	nop 
   02DB 00                 1182 	nop 
   02DC 00                 1183 	nop 
   02DD 00                 1184 	nop 
   02DE 00                 1185 	nop 
   02DF 00                 1186 	nop 
   02E0 00                 1187 	nop 
   02E1 00                 1188 	nop 
   02E2 00                 1189 	nop 
   02E3 00                 1190 	nop 
   02E4 00                 1191 	nop 
   02E5 00                 1192 	nop 
   02E6 00                 1193 	nop 
   02E7 00                 1194 	nop 
   02E8 00                 1195 	nop 
   02E9 00                 1196 	nop 
   02EA 00                 1197 	nop 
                           1198 ;	fx2pipe.c:249: EP6AUTOINLENH = 0x02; // MSB
   02EB 90 E6 24           1199 	mov	dptr,#_EP6AUTOINLENH
   02EE 74 02              1200 	mov	a,#0x02
   02F0 F0                 1201 	movx	@dptr,a
                           1202 ;	fx2pipe.c:250: SYNCDELAY;
   02F1 00                 1203 	nop 
   02F2 00                 1204 	nop 
   02F3 00                 1205 	nop 
   02F4 00                 1206 	nop 
   02F5 00                 1207 	nop 
   02F6 00                 1208 	nop 
   02F7 00                 1209 	nop 
   02F8 00                 1210 	nop 
   02F9 00                 1211 	nop 
   02FA 00                 1212 	nop 
   02FB 00                 1213 	nop 
   02FC 00                 1214 	nop 
   02FD 00                 1215 	nop 
   02FE 00                 1216 	nop 
   02FF 00                 1217 	nop 
   0300 00                 1218 	nop 
   0301 00                 1219 	nop 
                           1220 ;	fx2pipe.c:251: EP6AUTOINLENL = 0x00; // LSB
   0302 90 E6 25           1221 	mov	dptr,#_EP6AUTOINLENL
   0305 E4                 1222 	clr	a
   0306 F0                 1223 	movx	@dptr,a
                           1224 ;	fx2pipe.c:252: SYNCDELAY;
   0307 00                 1225 	nop 
   0308 00                 1226 	nop 
   0309 00                 1227 	nop 
   030A 00                 1228 	nop 
   030B 00                 1229 	nop 
   030C 00                 1230 	nop 
   030D 00                 1231 	nop 
   030E 00                 1232 	nop 
   030F 00                 1233 	nop 
   0310 00                 1234 	nop 
   0311 00                 1235 	nop 
   0312 00                 1236 	nop 
   0313 00                 1237 	nop 
   0314 00                 1238 	nop 
   0315 00                 1239 	nop 
   0316 00                 1240 	nop 
   0317 00                 1241 	nop 
   0318 22                 1242 	ret
   0319                    1243 00107$:
                           1244 ;	fx2pipe.c:255: else if(cfg_data[0]==0x21U) /* OUTPUT: HOST->USB */
   0319 BE 21 05           1245 	cjne	r6,#0x21,00140$
   031C BF 00 02           1246 	cjne	r7,#0x00,00140$
   031F 80 01              1247 	sjmp	00141$
   0321                    1248 00140$:
   0321 22                 1249 	ret
   0322                    1250 00141$:
                           1251 ;	fx2pipe.c:266: EP2CFG = cfg_data[2];  // bulk: 0xa2 double-buffered; 0xa3 triple-; 0xa0 quad
   0322 90 10 06           1252 	mov	dptr,#0x1006
   0325 E0                 1253 	movx	a,@dptr
   0326 FF                 1254 	mov	r7,a
   0327 90 E6 12           1255 	mov	dptr,#_EP2CFG
   032A F0                 1256 	movx	@dptr,a
                           1257 ;	fx2pipe.c:267: SYNCDELAY;
   032B 00                 1258 	nop 
   032C 00                 1259 	nop 
   032D 00                 1260 	nop 
   032E 00                 1261 	nop 
   032F 00                 1262 	nop 
   0330 00                 1263 	nop 
   0331 00                 1264 	nop 
   0332 00                 1265 	nop 
   0333 00                 1266 	nop 
   0334 00                 1267 	nop 
   0335 00                 1268 	nop 
   0336 00                 1269 	nop 
   0337 00                 1270 	nop 
   0338 00                 1271 	nop 
   0339 00                 1272 	nop 
   033A 00                 1273 	nop 
   033B 00                 1274 	nop 
                           1275 ;	fx2pipe.c:271: FIFOPINPOLAR=EP2FIFOPOLARITY; // 0 0 0 0 0 0 0 0
   033C 90 E6 09           1276 	mov	dptr,#_FIFOPINPOLAR
   033F 74 24              1277 	mov	a,#0x24
   0341 F0                 1278 	movx	@dptr,a
                           1279 ;	fx2pipe.c:272: SYNCDELAY;
   0342 00                 1280 	nop 
   0343 00                 1281 	nop 
   0344 00                 1282 	nop 
   0345 00                 1283 	nop 
   0346 00                 1284 	nop 
   0347 00                 1285 	nop 
   0348 00                 1286 	nop 
   0349 00                 1287 	nop 
   034A 00                 1288 	nop 
   034B 00                 1289 	nop 
   034C 00                 1290 	nop 
   034D 00                 1291 	nop 
   034E 00                 1292 	nop 
   034F 00                 1293 	nop 
   0350 00                 1294 	nop 
   0351 00                 1295 	nop 
   0352 00                 1296 	nop 
                           1297 ;	fx2pipe.c:276: FIFORESET = 0x80;  SYNCDELAY;  // NAK all requests from host.
   0353 90 E6 04           1298 	mov	dptr,#_FIFORESET
   0356 74 80              1299 	mov	a,#0x80
   0358 F0                 1300 	movx	@dptr,a
   0359 00                 1301 	nop 
   035A 00                 1302 	nop 
   035B 00                 1303 	nop 
   035C 00                 1304 	nop 
   035D 00                 1305 	nop 
   035E 00                 1306 	nop 
   035F 00                 1307 	nop 
   0360 00                 1308 	nop 
   0361 00                 1309 	nop 
   0362 00                 1310 	nop 
   0363 00                 1311 	nop 
   0364 00                 1312 	nop 
   0365 00                 1313 	nop 
   0366 00                 1314 	nop 
   0367 00                 1315 	nop 
   0368 00                 1316 	nop 
   0369 00                 1317 	nop 
                           1318 ;	fx2pipe.c:277: FIFORESET = 0x82;  SYNCDELAY;  // Reset individual EP (2,4,6,8)
   036A 90 E6 04           1319 	mov	dptr,#_FIFORESET
   036D 74 82              1320 	mov	a,#0x82
   036F F0                 1321 	movx	@dptr,a
   0370 00                 1322 	nop 
   0371 00                 1323 	nop 
   0372 00                 1324 	nop 
   0373 00                 1325 	nop 
   0374 00                 1326 	nop 
   0375 00                 1327 	nop 
   0376 00                 1328 	nop 
   0377 00                 1329 	nop 
   0378 00                 1330 	nop 
   0379 00                 1331 	nop 
   037A 00                 1332 	nop 
   037B 00                 1333 	nop 
   037C 00                 1334 	nop 
   037D 00                 1335 	nop 
   037E 00                 1336 	nop 
   037F 00                 1337 	nop 
   0380 00                 1338 	nop 
                           1339 ;	fx2pipe.c:278: FIFORESET = 0x84;  SYNCDELAY;
   0381 90 E6 04           1340 	mov	dptr,#_FIFORESET
   0384 74 84              1341 	mov	a,#0x84
   0386 F0                 1342 	movx	@dptr,a
   0387 00                 1343 	nop 
   0388 00                 1344 	nop 
   0389 00                 1345 	nop 
   038A 00                 1346 	nop 
   038B 00                 1347 	nop 
   038C 00                 1348 	nop 
   038D 00                 1349 	nop 
   038E 00                 1350 	nop 
   038F 00                 1351 	nop 
   0390 00                 1352 	nop 
   0391 00                 1353 	nop 
   0392 00                 1354 	nop 
   0393 00                 1355 	nop 
   0394 00                 1356 	nop 
   0395 00                 1357 	nop 
   0396 00                 1358 	nop 
   0397 00                 1359 	nop 
                           1360 ;	fx2pipe.c:279: FIFORESET = 0x86;  SYNCDELAY;
   0398 90 E6 04           1361 	mov	dptr,#_FIFORESET
   039B 74 86              1362 	mov	a,#0x86
   039D F0                 1363 	movx	@dptr,a
   039E 00                 1364 	nop 
   039F 00                 1365 	nop 
   03A0 00                 1366 	nop 
   03A1 00                 1367 	nop 
   03A2 00                 1368 	nop 
   03A3 00                 1369 	nop 
   03A4 00                 1370 	nop 
   03A5 00                 1371 	nop 
   03A6 00                 1372 	nop 
   03A7 00                 1373 	nop 
   03A8 00                 1374 	nop 
   03A9 00                 1375 	nop 
   03AA 00                 1376 	nop 
   03AB 00                 1377 	nop 
   03AC 00                 1378 	nop 
   03AD 00                 1379 	nop 
   03AE 00                 1380 	nop 
                           1381 ;	fx2pipe.c:280: FIFORESET = 0x88;  SYNCDELAY;
   03AF 90 E6 04           1382 	mov	dptr,#_FIFORESET
   03B2 74 88              1383 	mov	a,#0x88
   03B4 F0                 1384 	movx	@dptr,a
   03B5 00                 1385 	nop 
   03B6 00                 1386 	nop 
   03B7 00                 1387 	nop 
   03B8 00                 1388 	nop 
   03B9 00                 1389 	nop 
   03BA 00                 1390 	nop 
   03BB 00                 1391 	nop 
   03BC 00                 1392 	nop 
   03BD 00                 1393 	nop 
   03BE 00                 1394 	nop 
   03BF 00                 1395 	nop 
   03C0 00                 1396 	nop 
   03C1 00                 1397 	nop 
   03C2 00                 1398 	nop 
   03C3 00                 1399 	nop 
   03C4 00                 1400 	nop 
   03C5 00                 1401 	nop 
                           1402 ;	fx2pipe.c:281: FIFORESET = 0x00;  SYNCDELAY;  // Resume normal operation.
   03C6 90 E6 04           1403 	mov	dptr,#_FIFORESET
   03C9 E4                 1404 	clr	a
   03CA F0                 1405 	movx	@dptr,a
   03CB 00                 1406 	nop 
   03CC 00                 1407 	nop 
   03CD 00                 1408 	nop 
   03CE 00                 1409 	nop 
   03CF 00                 1410 	nop 
   03D0 00                 1411 	nop 
   03D1 00                 1412 	nop 
   03D2 00                 1413 	nop 
   03D3 00                 1414 	nop 
   03D4 00                 1415 	nop 
   03D5 00                 1416 	nop 
   03D6 00                 1417 	nop 
   03D7 00                 1418 	nop 
   03D8 00                 1419 	nop 
   03D9 00                 1420 	nop 
   03DA 00                 1421 	nop 
   03DB 00                 1422 	nop 
                           1423 ;	fx2pipe.c:284: OUTPKTEND = 0x82;  SYNCDELAY;
   03DC 90 E6 49           1424 	mov	dptr,#_OUTPKTEND
   03DF 74 82              1425 	mov	a,#0x82
   03E1 F0                 1426 	movx	@dptr,a
   03E2 00                 1427 	nop 
   03E3 00                 1428 	nop 
   03E4 00                 1429 	nop 
   03E5 00                 1430 	nop 
   03E6 00                 1431 	nop 
   03E7 00                 1432 	nop 
   03E8 00                 1433 	nop 
   03E9 00                 1434 	nop 
   03EA 00                 1435 	nop 
   03EB 00                 1436 	nop 
   03EC 00                 1437 	nop 
   03ED 00                 1438 	nop 
   03EE 00                 1439 	nop 
   03EF 00                 1440 	nop 
   03F0 00                 1441 	nop 
   03F1 00                 1442 	nop 
   03F2 00                 1443 	nop 
                           1444 ;	fx2pipe.c:285: OUTPKTEND = 0x82;  SYNCDELAY;
   03F3 90 E6 49           1445 	mov	dptr,#_OUTPKTEND
   03F6 74 82              1446 	mov	a,#0x82
   03F8 F0                 1447 	movx	@dptr,a
   03F9 00                 1448 	nop 
   03FA 00                 1449 	nop 
   03FB 00                 1450 	nop 
   03FC 00                 1451 	nop 
   03FD 00                 1452 	nop 
   03FE 00                 1453 	nop 
   03FF 00                 1454 	nop 
   0400 00                 1455 	nop 
   0401 00                 1456 	nop 
   0402 00                 1457 	nop 
   0403 00                 1458 	nop 
   0404 00                 1459 	nop 
   0405 00                 1460 	nop 
   0406 00                 1461 	nop 
   0407 00                 1462 	nop 
   0408 00                 1463 	nop 
   0409 00                 1464 	nop 
                           1465 ;	fx2pipe.c:286: switch(cfg_data[2]&0x03U)
   040A 90 10 06           1466 	mov	dptr,#0x1006
   040D E0                 1467 	movx	a,@dptr
   040E FF                 1468 	mov	r7,a
   040F 33                 1469 	rlc	a
   0410 95 E0              1470 	subb	a,acc
   0412 53 07 03           1471 	anl	ar7,#0x03
   0415 7E 00              1472 	mov	r6,#0x00
   0417 BF 00 05           1473 	cjne	r7,#0x00,00142$
   041A BE 00 02           1474 	cjne	r6,#0x00,00142$
   041D 80 08              1475 	sjmp	00101$
   041F                    1476 00142$:
                           1477 ;	fx2pipe.c:288: case 0x00U:  OUTPKTEND = 0x82;  SYNCDELAY;  // Quad-buffered.
   041F BF 03 33           1478 	cjne	r7,#0x03,00103$
   0422 BE 00 30           1479 	cjne	r6,#0x00,00103$
   0425 80 17              1480 	sjmp	00102$
   0427                    1481 00101$:
   0427 90 E6 49           1482 	mov	dptr,#_OUTPKTEND
   042A 74 82              1483 	mov	a,#0x82
   042C F0                 1484 	movx	@dptr,a
   042D 00                 1485 	nop 
   042E 00                 1486 	nop 
   042F 00                 1487 	nop 
   0430 00                 1488 	nop 
   0431 00                 1489 	nop 
   0432 00                 1490 	nop 
   0433 00                 1491 	nop 
   0434 00                 1492 	nop 
   0435 00                 1493 	nop 
   0436 00                 1494 	nop 
   0437 00                 1495 	nop 
   0438 00                 1496 	nop 
   0439 00                 1497 	nop 
   043A 00                 1498 	nop 
   043B 00                 1499 	nop 
   043C 00                 1500 	nop 
   043D 00                 1501 	nop 
                           1502 ;	fx2pipe.c:289: case 0x03U:  OUTPKTEND = 0x82;  SYNCDELAY;  // Triple-buffered.
   043E                    1503 00102$:
   043E 90 E6 49           1504 	mov	dptr,#_OUTPKTEND
   0441 74 82              1505 	mov	a,#0x82
   0443 F0                 1506 	movx	@dptr,a
   0444 00                 1507 	nop 
   0445 00                 1508 	nop 
   0446 00                 1509 	nop 
   0447 00                 1510 	nop 
   0448 00                 1511 	nop 
   0449 00                 1512 	nop 
   044A 00                 1513 	nop 
   044B 00                 1514 	nop 
   044C 00                 1515 	nop 
   044D 00                 1516 	nop 
   044E 00                 1517 	nop 
   044F 00                 1518 	nop 
   0450 00                 1519 	nop 
   0451 00                 1520 	nop 
   0452 00                 1521 	nop 
   0453 00                 1522 	nop 
   0454 00                 1523 	nop 
                           1524 ;	fx2pipe.c:290: }
   0455                    1525 00103$:
                           1526 ;	fx2pipe.c:302: EP2FIFOCFG = cfg_data[3]; /*0x11;*/
   0455 90 10 07           1527 	mov	dptr,#0x1007
   0458 E0                 1528 	movx	a,@dptr
   0459 FF                 1529 	mov	r7,a
   045A 90 E6 18           1530 	mov	dptr,#_EP2FIFOCFG
   045D F0                 1531 	movx	@dptr,a
                           1532 ;	fx2pipe.c:303: SYNCDELAY;
   045E 00                 1533 	nop 
   045F 00                 1534 	nop 
   0460 00                 1535 	nop 
   0461 00                 1536 	nop 
   0462 00                 1537 	nop 
   0463 00                 1538 	nop 
   0464 00                 1539 	nop 
   0465 00                 1540 	nop 
   0466 00                 1541 	nop 
   0467 00                 1542 	nop 
   0468 00                 1543 	nop 
   0469 00                 1544 	nop 
   046A 00                 1545 	nop 
   046B 00                 1546 	nop 
   046C 00                 1547 	nop 
   046D 00                 1548 	nop 
   046E 00                 1549 	nop 
   046F 22                 1550 	ret
                           1551 ;------------------------------------------------------------
                           1552 ;Allocation info for local variables in function 'main'
                           1553 ;------------------------------------------------------------
                           1554 ;	fx2pipe.c:314: void main()
                           1555 ;	-----------------------------------------
                           1556 ;	 function main
                           1557 ;	-----------------------------------------
   0470                    1558 _main:
                           1559 ;	fx2pipe.c:316: Initialize();
   0470 12 00 64           1560 	lcall	_Initialize
   0473                    1561 00102$:
   0473 80 FE              1562 	sjmp	00102$
                           1563 	.area CSEG    (CODE)
                           1564 	.area CONST   (CODE)
                           1565 	.area XINIT   (CODE)
                           1566 	.area CABS    (ABS,CODE)
