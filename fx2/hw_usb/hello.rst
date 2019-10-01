                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Sun Nov 24 08:15:28 2013
                              5 ;--------------------------------------------------------
                              6 	.module hello
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
   0008                     330 _SetUpBufToTransfer_serial_1_1:
   0008                     331 	.ds 1
                            332 ;--------------------------------------------------------
                            333 ; overlayable items in internal ram 
                            334 ;--------------------------------------------------------
                            335 	.area	OSEG    (OVR,DATA)
   0009                     336 _SetUpBufToTransfer_len_1_1:
   0009                     337 	.ds 1
   000A                     338 _SetUpBufToTransfer_sloc0_1_0:
   000A                     339 	.ds 1
                            340 ;--------------------------------------------------------
                            341 ; Stack segment in internal ram 
                            342 ;--------------------------------------------------------
                            343 	.area	SSEG	(DATA)
   000B                     344 __start__stack:
   000B                     345 	.ds	1
                            346 
                            347 ;--------------------------------------------------------
                            348 ; indirectly addressable internal ram data
                            349 ;--------------------------------------------------------
                            350 	.area ISEG    (DATA)
                            351 ;--------------------------------------------------------
                            352 ; absolute internal ram data
                            353 ;--------------------------------------------------------
                            354 	.area IABS    (ABS,DATA)
                            355 	.area IABS    (ABS,DATA)
                            356 ;--------------------------------------------------------
                            357 ; bit data
                            358 ;--------------------------------------------------------
                            359 	.area BSEG    (BIT)
                            360 ;--------------------------------------------------------
                            361 ; paged external ram data
                            362 ;--------------------------------------------------------
                            363 	.area PSEG    (PAG,XDATA)
                            364 ;--------------------------------------------------------
                            365 ; external ram data
                            366 ;--------------------------------------------------------
                            367 	.area XSEG    (XDATA)
                    E400    368 _GPIF_WAVE_DATA	=	0xe400
                    E480    369 _RES_WAVEDATA_END	=	0xe480
                    E600    370 _CPUCS	=	0xe600
                    E601    371 _IFCONFIG	=	0xe601
                    E602    372 _PINFLAGSAB	=	0xe602
                    E603    373 _PINFLAGSCD	=	0xe603
                    E604    374 _FIFORESET	=	0xe604
                    E605    375 _BREAKPT	=	0xe605
                    E606    376 _BPADDRH	=	0xe606
                    E607    377 _BPADDRL	=	0xe607
                    E608    378 _UART230	=	0xe608
                    E609    379 _FIFOPINPOLAR	=	0xe609
                    E60A    380 _REVID	=	0xe60a
                    E60B    381 _REVCTL	=	0xe60b
                    E610    382 _EP1OUTCFG	=	0xe610
                    E611    383 _EP1INCFG	=	0xe611
                    E612    384 _EP2CFG	=	0xe612
                    E613    385 _EP4CFG	=	0xe613
                    E614    386 _EP6CFG	=	0xe614
                    E615    387 _EP8CFG	=	0xe615
                    E618    388 _EP2FIFOCFG	=	0xe618
                    E619    389 _EP4FIFOCFG	=	0xe619
                    E61A    390 _EP6FIFOCFG	=	0xe61a
                    E61B    391 _EP8FIFOCFG	=	0xe61b
                    E620    392 _EP2AUTOINLENH	=	0xe620
                    E621    393 _EP2AUTOINLENL	=	0xe621
                    E622    394 _EP4AUTOINLENH	=	0xe622
                    E623    395 _EP4AUTOINLENL	=	0xe623
                    E624    396 _EP6AUTOINLENH	=	0xe624
                    E625    397 _EP6AUTOINLENL	=	0xe625
                    E626    398 _EP8AUTOINLENH	=	0xe626
                    E627    399 _EP8AUTOINLENL	=	0xe627
                    E630    400 _EP2FIFOPFH	=	0xe630
                    E631    401 _EP2FIFOPFL	=	0xe631
                    E632    402 _EP4FIFOPFH	=	0xe632
                    E633    403 _EP4FIFOPFL	=	0xe633
                    E634    404 _EP6FIFOPFH	=	0xe634
                    E635    405 _EP6FIFOPFL	=	0xe635
                    E636    406 _EP8FIFOPFH	=	0xe636
                    E637    407 _EP8FIFOPFL	=	0xe637
                    E640    408 _EP2ISOINPKTS	=	0xe640
                    E641    409 _EP4ISOINPKTS	=	0xe641
                    E642    410 _EP6ISOINPKTS	=	0xe642
                    E643    411 _EP8ISOINPKTS	=	0xe643
                    E648    412 _INPKTEND	=	0xe648
                    E649    413 _OUTPKTEND	=	0xe649
                    E650    414 _EP2FIFOIE	=	0xe650
                    E651    415 _EP2FIFOIRQ	=	0xe651
                    E652    416 _EP4FIFOIE	=	0xe652
                    E653    417 _EP4FIFOIRQ	=	0xe653
                    E654    418 _EP6FIFOIE	=	0xe654
                    E655    419 _EP6FIFOIRQ	=	0xe655
                    E656    420 _EP8FIFOIE	=	0xe656
                    E657    421 _EP8FIFOIRQ	=	0xe657
                    E658    422 _IBNIE	=	0xe658
                    E659    423 _IBNIRQ	=	0xe659
                    E65A    424 _NAKIE	=	0xe65a
                    E65B    425 _NAKIRQ	=	0xe65b
                    E65C    426 _USBIE	=	0xe65c
                    E65D    427 _USBIRQ	=	0xe65d
                    E65E    428 _EPIE	=	0xe65e
                    E65F    429 _EPIRQ	=	0xe65f
                    E660    430 _GPIFIE	=	0xe660
                    E661    431 _GPIFIRQ	=	0xe661
                    E662    432 _USBERRIE	=	0xe662
                    E663    433 _USBERRIRQ	=	0xe663
                    E664    434 _ERRCNTLIM	=	0xe664
                    E665    435 _CLRERRCNT	=	0xe665
                    E666    436 _INT2IVEC	=	0xe666
                    E667    437 _INT4IVEC	=	0xe667
                    E668    438 _INTSETUP	=	0xe668
                    E670    439 _PORTACFG	=	0xe670
                    E671    440 _PORTCCFG	=	0xe671
                    E672    441 _PORTECFG	=	0xe672
                    E678    442 _I2CS	=	0xe678
                    E679    443 _I2DAT	=	0xe679
                    E67A    444 _I2CTL	=	0xe67a
                    E67B    445 _XAUTODAT1	=	0xe67b
                    E67C    446 _XAUTODAT2	=	0xe67c
                    E680    447 _USBCS	=	0xe680
                    E681    448 _SUSPEND	=	0xe681
                    E682    449 _WAKEUPCS	=	0xe682
                    E683    450 _TOGCTL	=	0xe683
                    E684    451 _USBFRAMEH	=	0xe684
                    E685    452 _USBFRAMEL	=	0xe685
                    E686    453 _MICROFRAME	=	0xe686
                    E687    454 _FNADDR	=	0xe687
                    E68A    455 _EP0BCH	=	0xe68a
                    E68B    456 _EP0BCL	=	0xe68b
                    E68D    457 _EP1OUTBC	=	0xe68d
                    E68F    458 _EP1INBC	=	0xe68f
                    E690    459 _EP2BCH	=	0xe690
                    E691    460 _EP2BCL	=	0xe691
                    E694    461 _EP4BCH	=	0xe694
                    E695    462 _EP4BCL	=	0xe695
                    E698    463 _EP6BCH	=	0xe698
                    E699    464 _EP6BCL	=	0xe699
                    E69C    465 _EP8BCH	=	0xe69c
                    E69D    466 _EP8BCL	=	0xe69d
                    E6A0    467 _EP0CS	=	0xe6a0
                    E6A1    468 _EP1OUTCS	=	0xe6a1
                    E6A2    469 _EP1INCS	=	0xe6a2
                    E6A3    470 _EP2CS	=	0xe6a3
                    E6A4    471 _EP4CS	=	0xe6a4
                    E6A5    472 _EP6CS	=	0xe6a5
                    E6A6    473 _EP8CS	=	0xe6a6
                    E6A7    474 _EP2FIFOFLGS	=	0xe6a7
                    E6A8    475 _EP4FIFOFLGS	=	0xe6a8
                    E6A9    476 _EP6FIFOFLGS	=	0xe6a9
                    E6AA    477 _EP8FIFOFLGS	=	0xe6aa
                    E6AB    478 _EP2FIFOBCH	=	0xe6ab
                    E6AC    479 _EP2FIFOBCL	=	0xe6ac
                    E6AD    480 _EP4FIFOBCH	=	0xe6ad
                    E6AE    481 _EP4FIFOBCL	=	0xe6ae
                    E6AF    482 _EP6FIFOBCH	=	0xe6af
                    E6B0    483 _EP6FIFOBCL	=	0xe6b0
                    E6B1    484 _EP8FIFOBCH	=	0xe6b1
                    E6B2    485 _EP8FIFOBCL	=	0xe6b2
                    E6B3    486 _SUDPTRH	=	0xe6b3
                    E6B4    487 _SUDPTRL	=	0xe6b4
                    E6B5    488 _SUDPTRCTL	=	0xe6b5
                    E6B8    489 _SETUPDAT	=	0xe6b8
                    E6C0    490 _GPIFWFSELECT	=	0xe6c0
                    E6C1    491 _GPIFIDLECS	=	0xe6c1
                    E6C2    492 _GPIFIDLECTL	=	0xe6c2
                    E6C3    493 _GPIFCTLCFG	=	0xe6c3
                    E6C4    494 _GPIFADRH	=	0xe6c4
                    E6C5    495 _GPIFADRL	=	0xe6c5
                    E6CE    496 _GPIFTCB3	=	0xe6ce
                    E6CF    497 _GPIFTCB2	=	0xe6cf
                    E6D0    498 _GPIFTCB1	=	0xe6d0
                    E6D1    499 _GPIFTCB0	=	0xe6d1
                    E6D2    500 _EP2GPIFFLGSEL	=	0xe6d2
                    E6D3    501 _EP2GPIFPFSTOP	=	0xe6d3
                    E6D4    502 _EP2GPIFTRIG	=	0xe6d4
                    E6DA    503 _EP4GPIFFLGSEL	=	0xe6da
                    E6DB    504 _EP4GPIFPFSTOP	=	0xe6db
                    E6DC    505 _EP4GPIFTRIG	=	0xe6dc
                    E6E2    506 _EP6GPIFFLGSEL	=	0xe6e2
                    E6E3    507 _EP6GPIFPFSTOP	=	0xe6e3
                    E6E4    508 _EP6GPIFTRIG	=	0xe6e4
                    E6EA    509 _EP8GPIFFLGSEL	=	0xe6ea
                    E6EB    510 _EP8GPIFPFSTOP	=	0xe6eb
                    E6EC    511 _EP8GPIFTRIG	=	0xe6ec
                    E6F0    512 _XGPIFSGLDATH	=	0xe6f0
                    E6F1    513 _XGPIFSGLDATLX	=	0xe6f1
                    E6F2    514 _XGPIFSGLDATLNOX	=	0xe6f2
                    E6F3    515 _GPIFREADYCFG	=	0xe6f3
                    E6F4    516 _GPIFREADYSTAT	=	0xe6f4
                    E6F5    517 _GPIFABORT	=	0xe6f5
                    E6C6    518 _FLOWSTATE	=	0xe6c6
                    E6C7    519 _FLOWLOGIC	=	0xe6c7
                    E6C8    520 _FLOWEQ0CTL	=	0xe6c8
                    E6C9    521 _FLOWEQ1CTL	=	0xe6c9
                    E6CA    522 _FLOWHOLDOFF	=	0xe6ca
                    E6CB    523 _FLOWSTB	=	0xe6cb
                    E6CC    524 _FLOWSTBEDGE	=	0xe6cc
                    E6CD    525 _FLOWSTBHPERIOD	=	0xe6cd
                    E60C    526 _GPIFHOLDAMOUNT	=	0xe60c
                    E67D    527 _UDMACRCH	=	0xe67d
                    E67E    528 _UDMACRCL	=	0xe67e
                    E67F    529 _UDMACRCQUAL	=	0xe67f
                    E6F8    530 _DBUG	=	0xe6f8
                    E6F9    531 _TESTCFG	=	0xe6f9
                    E6FA    532 _USBTEST	=	0xe6fa
                    E6FB    533 _CT1	=	0xe6fb
                    E6FC    534 _CT2	=	0xe6fc
                    E6FD    535 _CT3	=	0xe6fd
                    E6FE    536 _CT4	=	0xe6fe
                    E740    537 _EP0BUF	=	0xe740
                    E780    538 _EP1OUTBUF	=	0xe780
                    E7C0    539 _EP1INBUF	=	0xe7c0
                    F000    540 _EP2FIFOBUF	=	0xf000
                    F400    541 _EP4FIFOBUF	=	0xf400
                    F800    542 _EP6FIFOBUF	=	0xf800
                    FC00    543 _EP8FIFOBUF	=	0xfc00
                            544 ;--------------------------------------------------------
                            545 ; absolute external ram data
                            546 ;--------------------------------------------------------
                            547 	.area XABS    (ABS,XDATA)
                            548 ;--------------------------------------------------------
                            549 ; external initialized ram data
                            550 ;--------------------------------------------------------
                            551 	.area XISEG   (XDATA)
                            552 	.area HOME    (CODE)
                            553 	.area GSINIT0 (CODE)
                            554 	.area GSINIT1 (CODE)
                            555 	.area GSINIT2 (CODE)
                            556 	.area GSINIT3 (CODE)
                            557 	.area GSINIT4 (CODE)
                            558 	.area GSINIT5 (CODE)
                            559 	.area GSINIT  (CODE)
                            560 	.area GSFINAL (CODE)
                            561 	.area CSEG    (CODE)
                            562 ;--------------------------------------------------------
                            563 ; interrupt vector 
                            564 ;--------------------------------------------------------
                            565 	.area HOME    (CODE)
   0000                     566 __interrupt_vect:
   0000 02 00 08            567 	ljmp	__sdcc_gsinit_startup
                            568 ;--------------------------------------------------------
                            569 ; global & static initialisations
                            570 ;--------------------------------------------------------
                            571 	.area HOME    (CODE)
                            572 	.area GSINIT  (CODE)
                            573 	.area GSFINAL (CODE)
                            574 	.area GSINIT  (CODE)
                            575 	.globl __sdcc_gsinit_startup
                            576 	.globl __sdcc_program_startup
                            577 	.globl __start__stack
                            578 	.globl __mcs51_genXINIT
                            579 	.globl __mcs51_genXRAMCLEAR
                            580 	.globl __mcs51_genRAMCLEAR
                            581 ;------------------------------------------------------------
                            582 ;Allocation info for local variables in function 'SetUpBufToTransfer'
                            583 ;------------------------------------------------------------
                            584 ;serial                    Allocated with name '_SetUpBufToTransfer_serial_1_1'
                            585 ;dest                      Allocated to registers r6 r7 
                            586 ;src                       Allocated to registers 
                            587 ;len                       Allocated with name '_SetUpBufToTransfer_len_1_1'
                            588 ;sloc0                     Allocated with name '_SetUpBufToTransfer_sloc0_1_0'
                            589 ;------------------------------------------------------------
                            590 ;	hello.c:52: static unsigned char serial=0;
   0061 75 08 00            591 	mov	_SetUpBufToTransfer_serial_1_1,#0x00
                            592 	.area GSFINAL (CODE)
   0064 02 00 03            593 	ljmp	__sdcc_program_startup
                            594 ;--------------------------------------------------------
                            595 ; Home
                            596 ;--------------------------------------------------------
                            597 	.area HOME    (CODE)
                            598 	.area HOME    (CODE)
   0003                     599 __sdcc_program_startup:
   0003 12 01 6D            600 	lcall	_main
                            601 ;	return from main will lock up
   0006 80 FE               602 	sjmp .
                            603 ;--------------------------------------------------------
                            604 ; code
                            605 ;--------------------------------------------------------
                            606 	.area CSEG    (CODE)
                            607 ;------------------------------------------------------------
                            608 ;Allocation info for local variables in function 'Initialize'
                            609 ;------------------------------------------------------------
                            610 ;	hello.c:25: static void Initialize(void)
                            611 ;	-----------------------------------------
                            612 ;	 function Initialize
                            613 ;	-----------------------------------------
   0067                     614 _Initialize:
                    0007    615 	ar7 = 0x07
                    0006    616 	ar6 = 0x06
                    0005    617 	ar5 = 0x05
                    0004    618 	ar4 = 0x04
                    0003    619 	ar3 = 0x03
                    0002    620 	ar2 = 0x02
                    0001    621 	ar1 = 0x01
                    0000    622 	ar0 = 0x00
                            623 ;	hello.c:27: CPUCS=0x10;   // 48 MHz, CLKOUT output disabled. 
   0067 90 E6 00            624 	mov	dptr,#_CPUCS
   006A 74 10               625 	mov	a,#0x10
   006C F0                  626 	movx	@dptr,a
                            627 ;	hello.c:29: IFCONFIG=0xc0;  // Internal IFCLK, 48MHz; A,B as normal ports. 
   006D 90 E6 01            628 	mov	dptr,#_IFCONFIG
   0070 74 C0               629 	mov	a,#0xC0
   0072 F0                  630 	movx	@dptr,a
                            631 ;	hello.c:30: SYNCDELAY;
   0073 00                  632 	 nop 
   0074 00                  633 	 nop 
   0075 00                  634 	 nop 
   0076 00                  635 	 nop 
                            636 ;	hello.c:32: REVCTL=0x03;  // See TRM...
   0077 90 E6 0B            637 	mov	dptr,#_REVCTL
   007A 74 03               638 	mov	a,#0x03
   007C F0                  639 	movx	@dptr,a
                            640 ;	hello.c:33: SYNCDELAY;
   007D 00                  641 	 nop 
   007E 00                  642 	 nop 
   007F 00                  643 	 nop 
   0080 00                  644 	 nop 
                            645 ;	hello.c:35: EP6CFG=0xe2;  // 1110 0010 (bulk IN, 512 bytes, double-buffered)
   0081 90 E6 14            646 	mov	dptr,#_EP6CFG
   0084 74 E2               647 	mov	a,#0xE2
   0086 F0                  648 	movx	@dptr,a
                            649 ;	hello.c:36: SYNCDELAY;
   0087 00                  650 	 nop 
   0088 00                  651 	 nop 
   0089 00                  652 	 nop 
   008A 00                  653 	 nop 
                            654 ;	hello.c:38: FIFORESET = 0x80;  SYNCDELAY;  // NAK all requests from host. 
   008B 90 E6 04            655 	mov	dptr,#_FIFORESET
   008E 74 80               656 	mov	a,#0x80
   0090 F0                  657 	movx	@dptr,a
   0091 00                  658 	 nop 
   0092 00                  659 	 nop 
   0093 00                  660 	 nop 
   0094 00                  661 	 nop 
                            662 ;	hello.c:39: FIFORESET = 0x82;  SYNCDELAY;  // Reset individual EP (2,4,6,8)
   0095 90 E6 04            663 	mov	dptr,#_FIFORESET
   0098 74 82               664 	mov	a,#0x82
   009A F0                  665 	movx	@dptr,a
   009B 00                  666 	 nop 
   009C 00                  667 	 nop 
   009D 00                  668 	 nop 
   009E 00                  669 	 nop 
                            670 ;	hello.c:40: FIFORESET = 0x84;  SYNCDELAY;
   009F 90 E6 04            671 	mov	dptr,#_FIFORESET
   00A2 74 84               672 	mov	a,#0x84
   00A4 F0                  673 	movx	@dptr,a
   00A5 00                  674 	 nop 
   00A6 00                  675 	 nop 
   00A7 00                  676 	 nop 
   00A8 00                  677 	 nop 
                            678 ;	hello.c:41: FIFORESET = 0x86;  SYNCDELAY;
   00A9 90 E6 04            679 	mov	dptr,#_FIFORESET
   00AC 74 86               680 	mov	a,#0x86
   00AE F0                  681 	movx	@dptr,a
   00AF 00                  682 	 nop 
   00B0 00                  683 	 nop 
   00B1 00                  684 	 nop 
   00B2 00                  685 	 nop 
                            686 ;	hello.c:42: FIFORESET = 0x88;  SYNCDELAY;
   00B3 90 E6 04            687 	mov	dptr,#_FIFORESET
   00B6 74 88               688 	mov	a,#0x88
   00B8 F0                  689 	movx	@dptr,a
   00B9 00                  690 	 nop 
   00BA 00                  691 	 nop 
   00BB 00                  692 	 nop 
   00BC 00                  693 	 nop 
                            694 ;	hello.c:43: FIFORESET = 0x00;  SYNCDELAY;  // Resume normal operation. 
   00BD 90 E6 04            695 	mov	dptr,#_FIFORESET
   00C0 E4                  696 	clr	a
   00C1 F0                  697 	movx	@dptr,a
   00C2 00                  698 	 nop 
   00C3 00                  699 	 nop 
   00C4 00                  700 	 nop 
   00C5 00                  701 	 nop 
   00C6 22                  702 	ret
                            703 ;------------------------------------------------------------
                            704 ;Allocation info for local variables in function 'SetUpBufToTransfer'
                            705 ;------------------------------------------------------------
                            706 ;serial                    Allocated with name '_SetUpBufToTransfer_serial_1_1'
                            707 ;dest                      Allocated to registers r6 r7 
                            708 ;src                       Allocated to registers 
                            709 ;len                       Allocated with name '_SetUpBufToTransfer_len_1_1'
                            710 ;sloc0                     Allocated with name '_SetUpBufToTransfer_sloc0_1_0'
                            711 ;------------------------------------------------------------
                            712 ;	hello.c:49: static void SetUpBufToTransfer(void)
                            713 ;	-----------------------------------------
                            714 ;	 function SetUpBufToTransfer
                            715 ;	-----------------------------------------
   00C7                     716 _SetUpBufToTransfer:
                            717 ;	hello.c:55: xdata unsigned char *dest=EP6FIFOBUF;
   00C7 7E 00               718 	mov	r6,#_EP6FIFOBUF
   00C9 7F F8               719 	mov	r7,#(_EP6FIFOBUF >> 8)
                            720 ;	hello.c:56: const char *src=
                            721 ;	hello.c:59: while(*src)
   00CB 7B 9D               722 	mov	r3,#__str_0
   00CD 7C 01               723 	mov	r4,#(__str_0 >> 8)
   00CF 7D 80               724 	mov	r5,#0x80
   00D1 8E 01               725 	mov	ar1,r6
   00D3 8F 02               726 	mov	ar2,r7
   00D5 75 09 00            727 	mov	_SetUpBufToTransfer_len_1_1,#0x00
   00D8                     728 00101$:
   00D8 8B 82               729 	mov	dpl,r3
   00DA 8C 83               730 	mov	dph,r4
   00DC 8D F0               731 	mov	b,r5
   00DE 12 01 7D            732 	lcall	__gptrget
   00E1 F5 0A               733 	mov	_SetUpBufToTransfer_sloc0_1_0,a
   00E3 60 16               734 	jz	00103$
                            735 ;	hello.c:61: *dest++=*src++;
   00E5 A8 0A               736 	mov	r0,_SetUpBufToTransfer_sloc0_1_0
   00E7 0B                  737 	inc	r3
   00E8 BB 00 01            738 	cjne	r3,#0x00,00110$
   00EB 0C                  739 	inc	r4
   00EC                     740 00110$:
   00EC 89 82               741 	mov	dpl,r1
   00EE 8A 83               742 	mov	dph,r2
   00F0 E8                  743 	mov	a,r0
   00F1 F0                  744 	movx	@dptr,a
   00F2 A3                  745 	inc	dptr
   00F3 A9 82               746 	mov	r1,dpl
   00F5 AA 83               747 	mov	r2,dph
                            748 ;	hello.c:62: ++len;
   00F7 05 09               749 	inc	_SetUpBufToTransfer_len_1_1
   00F9 80 DD               750 	sjmp	00101$
   00FB                     751 00103$:
                            752 ;	hello.c:65: *dest++='(';                ++len;
   00FB 89 82               753 	mov	dpl,r1
   00FD 8A 83               754 	mov	dph,r2
   00FF 74 28               755 	mov	a,#0x28
   0101 F0                  756 	movx	@dptr,a
   0102 74 01               757 	mov	a,#0x01
   0104 29                  758 	add	a,r1
   0105 FE                  759 	mov	r6,a
   0106 E4                  760 	clr	a
   0107 3A                  761 	addc	a,r2
   0108 FF                  762 	mov	r7,a
   0109 E5 09               763 	mov	a,_SetUpBufToTransfer_len_1_1
   010B 04                  764 	inc	a
   010C FD                  765 	mov	r5,a
                            766 ;	hello.c:66: *dest++='0'+serial/100;     ++len;
   010D 75 F0 64            767 	mov	b,#0x64
   0110 E5 08               768 	mov	a,_SetUpBufToTransfer_serial_1_1
   0112 84                  769 	div	ab
   0113 24 30               770 	add	a,#0x30
   0115 8E 82               771 	mov	dpl,r6
   0117 8F 83               772 	mov	dph,r7
   0119 F0                  773 	movx	@dptr,a
   011A A3                  774 	inc	dptr
   011B AE 82               775 	mov	r6,dpl
   011D AF 83               776 	mov	r7,dph
   011F 0D                  777 	inc	r5
                            778 ;	hello.c:67: *dest++='0'+serial%100/10;  ++len;
   0120 75 F0 64            779 	mov	b,#0x64
   0123 E5 08               780 	mov	a,_SetUpBufToTransfer_serial_1_1
   0125 84                  781 	div	ab
   0126 E5 F0               782 	mov	a,b
   0128 75 F0 0A            783 	mov	b,#0x0A
   012B 84                  784 	div	ab
   012C 24 30               785 	add	a,#0x30
   012E 8E 82               786 	mov	dpl,r6
   0130 8F 83               787 	mov	dph,r7
   0132 F0                  788 	movx	@dptr,a
   0133 A3                  789 	inc	dptr
   0134 AE 82               790 	mov	r6,dpl
   0136 AF 83               791 	mov	r7,dph
   0138 0D                  792 	inc	r5
                            793 ;	hello.c:68: *dest++='0'+serial%10;      ++len;
   0139 75 F0 0A            794 	mov	b,#0x0A
   013C E5 08               795 	mov	a,_SetUpBufToTransfer_serial_1_1
   013E 84                  796 	div	ab
   013F AC F0               797 	mov	r4,b
   0141 74 30               798 	mov	a,#0x30
   0143 2C                  799 	add	a,r4
   0144 FC                  800 	mov	r4,a
   0145 8E 82               801 	mov	dpl,r6
   0147 8F 83               802 	mov	dph,r7
   0149 F0                  803 	movx	@dptr,a
   014A A3                  804 	inc	dptr
   014B AE 82               805 	mov	r6,dpl
   014D AF 83               806 	mov	r7,dph
   014F 0D                  807 	inc	r5
                            808 ;	hello.c:69: *dest++=')';                ++len;
   0150 8E 82               809 	mov	dpl,r6
   0152 8F 83               810 	mov	dph,r7
   0154 74 29               811 	mov	a,#0x29
   0156 F0                  812 	movx	@dptr,a
   0157 0D                  813 	inc	r5
                            814 ;	hello.c:70: ++serial;
   0158 05 08               815 	inc	_SetUpBufToTransfer_serial_1_1
                            816 ;	hello.c:74: SYNCDELAY;  EP6BCH=0;
   015A 00                  817 	 nop 
   015B 00                  818 	 nop 
   015C 00                  819 	 nop 
   015D 00                  820 	 nop 
   015E 90 E6 98            821 	mov	dptr,#_EP6BCH
   0161 E4                  822 	clr	a
   0162 F0                  823 	movx	@dptr,a
                            824 ;	hello.c:75: SYNCDELAY;  EP6BCL=len;
   0163 00                  825 	 nop 
   0164 00                  826 	 nop 
   0165 00                  827 	 nop 
   0166 00                  828 	 nop 
   0167 90 E6 99            829 	mov	dptr,#_EP6BCL
   016A ED                  830 	mov	a,r5
   016B F0                  831 	movx	@dptr,a
   016C 22                  832 	ret
                            833 ;------------------------------------------------------------
                            834 ;Allocation info for local variables in function 'main'
                            835 ;------------------------------------------------------------
                            836 ;	hello.c:82: void main(void)
                            837 ;	-----------------------------------------
                            838 ;	 function main
                            839 ;	-----------------------------------------
   016D                     840 _main:
                            841 ;	hello.c:84: Initialize();
   016D 12 00 67            842 	lcall	_Initialize
   0170                     843 00104$:
                            844 ;	hello.c:89: if(!(EP6CS & (1<<3)))
   0170 90 E6 A5            845 	mov	dptr,#_EP6CS
   0173 E0                  846 	movx	a,@dptr
   0174 FF                  847 	mov	r7,a
   0175 20 E3 F8            848 	jb	acc.3,00104$
                            849 ;	hello.c:90: {  SetUpBufToTransfer();  }
   0178 12 00 C7            850 	lcall	_SetUpBufToTransfer
   017B 80 F3               851 	sjmp	00104$
                            852 	.area CSEG    (CODE)
                            853 	.area CONST   (CODE)
   019D                     854 __str_0:
   019D 48 65 6C 6C 6F 20   855 	.ascii "Hello world! Your FX2 is talking to you via the USB line. "
        77 6F 72 6C 64 21
        20 59 6F 75 72 20
        46 58 32 20 69 73
        20 74 61 6C 6B 69
        6E 67 20 74 6F 20
        79 6F 75 20 76 69
        61 20 74 68 65 20
        55 53 42 20 6C 69
        6E 65 2E 20
   01D7 00                  856 	.db 0x00
                            857 	.area XINIT   (CODE)
                            858 	.area CABS    (ABS,CODE)
