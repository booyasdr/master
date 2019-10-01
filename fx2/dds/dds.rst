                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Sun Oct 26 13:42:35 2014
                              5 ;--------------------------------------------------------
                              6 	.module dds
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
                            250 	.globl _dat
                            251 ;--------------------------------------------------------
                            252 ; special function registers
                            253 ;--------------------------------------------------------
                            254 	.area RSEG    (ABS,DATA)
   0000                     255 	.org 0x0000
                    0080    256 _IOA	=	0x0080
                    0081    257 _SP	=	0x0081
                    0082    258 _DPL	=	0x0082
                    0083    259 _DPH	=	0x0083
                    0084    260 _DPL1	=	0x0084
                    0085    261 _DPH1	=	0x0085
                    0086    262 _DPS	=	0x0086
                    0087    263 _PCON	=	0x0087
                    0088    264 _TCON	=	0x0088
                    0089    265 _TMOD	=	0x0089
                    008A    266 _TL0	=	0x008a
                    008B    267 _TL1	=	0x008b
                    008C    268 _TH0	=	0x008c
                    008D    269 _TH1	=	0x008d
                    008E    270 _CKCO	=	0x008e
                    008F    271 _SPC_	=	0x008f
                    0090    272 _IOB	=	0x0090
                    0091    273 _EXIF	=	0x0091
                    0092    274 _MPA	=	0x0092
                    0098    275 _SCO	=	0x0098
                    0099    276 _SBU	=	0x0099
                    009A    277 _APTR1H	=	0x009a
                    009B    278 _APTR1L	=	0x009b
                    009C    279 _AUTODAT1	=	0x009c
                    009D    280 _AUTOPTRH2	=	0x009d
                    009E    281 _AUTOPTRL2	=	0x009e
                    009F    282 _AUTODAT2	=	0x009f
                    00A0    283 _IOC	=	0x00a0
                    00A1    284 _INT2CLR	=	0x00a1
                    00A2    285 _INT4CLR	=	0x00a2
                    00A8    286 _IE	=	0x00a8
                    00AA    287 _EP2468STAT	=	0x00aa
                    00AB    288 _EP24FIFOFLGS	=	0x00ab
                    00AC    289 _EP68FIFOFLGS	=	0x00ac
                    00AF    290 _AUTOPTRSETUP	=	0x00af
                    00B0    291 _IOD	=	0x00b0
                    00B1    292 _IOE	=	0x00b1
                    00B2    293 _OEA	=	0x00b2
                    00B3    294 _OEB	=	0x00b3
                    00B4    295 _OEC	=	0x00b4
                    00B5    296 _OED	=	0x00b5
                    00B6    297 _OEE	=	0x00b6
                    00B8    298 _IP	=	0x00b8
                    00BA    299 _EP01STAT	=	0x00ba
                    00BB    300 _GPIFTRIG	=	0x00bb
                    00BD    301 _GPIFSGLDATH	=	0x00bd
                    00BE    302 _GPIFSGLDATLX	=	0x00be
                    00BF    303 _GPIFSGLDATLNOX	=	0x00bf
                    00C0    304 _SCON1	=	0x00c0
                    00C1    305 _SBUF1	=	0x00c1
                    00C8    306 _T2CON	=	0x00c8
                    00CA    307 _RCAP2L	=	0x00ca
                    00CB    308 _RCAP2H	=	0x00cb
                    00CC    309 _TL2	=	0x00cc
                    00CD    310 _TH2	=	0x00cd
                    00D0    311 _PSW	=	0x00d0
                    00D8    312 _EICON	=	0x00d8
                    00E0    313 _ACC	=	0x00e0
                    00E8    314 _EIE	=	0x00e8
                    00F0    315 _B	=	0x00f0
                    00F8    316 _EIP	=	0x00f8
                            317 ;--------------------------------------------------------
                            318 ; special function bits
                            319 ;--------------------------------------------------------
                            320 	.area RSEG    (ABS,DATA)
   0000                     321 	.org 0x0000
                            322 ;--------------------------------------------------------
                            323 ; overlayable register banks
                            324 ;--------------------------------------------------------
                            325 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     326 	.ds 8
                            327 ;--------------------------------------------------------
                            328 ; internal ram data
                            329 ;--------------------------------------------------------
                            330 	.area DSEG    (DATA)
   0008                     331 _dat::
   0008                     332 	.ds 2
                            333 ;--------------------------------------------------------
                            334 ; overlayable items in internal ram 
                            335 ;--------------------------------------------------------
                            336 	.area	OSEG    (OVR,DATA)
                            337 	.area	OSEG    (OVR,DATA)
   000A                     338 _ProcessSendData_len_1_1:
   000A                     339 	.ds 2
   000C                     340 _ProcessSendData_i_1_1:
   000C                     341 	.ds 2
                            342 ;--------------------------------------------------------
                            343 ; Stack segment in internal ram 
                            344 ;--------------------------------------------------------
                            345 	.area	SSEG	(DATA)
   000E                     346 __start__stack:
   000E                     347 	.ds	1
                            348 
                            349 ;--------------------------------------------------------
                            350 ; indirectly addressable internal ram data
                            351 ;--------------------------------------------------------
                            352 	.area ISEG    (DATA)
                            353 ;--------------------------------------------------------
                            354 ; absolute internal ram data
                            355 ;--------------------------------------------------------
                            356 	.area IABS    (ABS,DATA)
                            357 	.area IABS    (ABS,DATA)
                            358 ;--------------------------------------------------------
                            359 ; bit data
                            360 ;--------------------------------------------------------
                            361 	.area BSEG    (BIT)
                            362 ;--------------------------------------------------------
                            363 ; paged external ram data
                            364 ;--------------------------------------------------------
                            365 	.area PSEG    (PAG,XDATA)
                            366 ;--------------------------------------------------------
                            367 ; external ram data
                            368 ;--------------------------------------------------------
                            369 	.area XSEG    (XDATA)
                    E400    370 _GPIF_WAVE_DATA	=	0xe400
                    E480    371 _RES_WAVEDATA_END	=	0xe480
                    E600    372 _CPUCS	=	0xe600
                    E601    373 _IFCONFIG	=	0xe601
                    E602    374 _PINFLAGSAB	=	0xe602
                    E603    375 _PINFLAGSCD	=	0xe603
                    E604    376 _FIFORESET	=	0xe604
                    E605    377 _BREAKPT	=	0xe605
                    E606    378 _BPADDRH	=	0xe606
                    E607    379 _BPADDRL	=	0xe607
                    E608    380 _UART230	=	0xe608
                    E609    381 _FIFOPINPOLAR	=	0xe609
                    E60A    382 _REVID	=	0xe60a
                    E60B    383 _REVCTL	=	0xe60b
                    E610    384 _EP1OUTCFG	=	0xe610
                    E611    385 _EP1INCFG	=	0xe611
                    E612    386 _EP2CFG	=	0xe612
                    E613    387 _EP4CFG	=	0xe613
                    E614    388 _EP6CFG	=	0xe614
                    E615    389 _EP8CFG	=	0xe615
                    E618    390 _EP2FIFOCFG	=	0xe618
                    E619    391 _EP4FIFOCFG	=	0xe619
                    E61A    392 _EP6FIFOCFG	=	0xe61a
                    E61B    393 _EP8FIFOCFG	=	0xe61b
                    E620    394 _EP2AUTOINLENH	=	0xe620
                    E621    395 _EP2AUTOINLENL	=	0xe621
                    E622    396 _EP4AUTOINLENH	=	0xe622
                    E623    397 _EP4AUTOINLENL	=	0xe623
                    E624    398 _EP6AUTOINLENH	=	0xe624
                    E625    399 _EP6AUTOINLENL	=	0xe625
                    E626    400 _EP8AUTOINLENH	=	0xe626
                    E627    401 _EP8AUTOINLENL	=	0xe627
                    E630    402 _EP2FIFOPFH	=	0xe630
                    E631    403 _EP2FIFOPFL	=	0xe631
                    E632    404 _EP4FIFOPFH	=	0xe632
                    E633    405 _EP4FIFOPFL	=	0xe633
                    E634    406 _EP6FIFOPFH	=	0xe634
                    E635    407 _EP6FIFOPFL	=	0xe635
                    E636    408 _EP8FIFOPFH	=	0xe636
                    E637    409 _EP8FIFOPFL	=	0xe637
                    E640    410 _EP2ISOINPKTS	=	0xe640
                    E641    411 _EP4ISOINPKTS	=	0xe641
                    E642    412 _EP6ISOINPKTS	=	0xe642
                    E643    413 _EP8ISOINPKTS	=	0xe643
                    E648    414 _INPKTEND	=	0xe648
                    E649    415 _OUTPKTEND	=	0xe649
                    E650    416 _EP2FIFOIE	=	0xe650
                    E651    417 _EP2FIFOIRQ	=	0xe651
                    E652    418 _EP4FIFOIE	=	0xe652
                    E653    419 _EP4FIFOIRQ	=	0xe653
                    E654    420 _EP6FIFOIE	=	0xe654
                    E655    421 _EP6FIFOIRQ	=	0xe655
                    E656    422 _EP8FIFOIE	=	0xe656
                    E657    423 _EP8FIFOIRQ	=	0xe657
                    E658    424 _IBNIE	=	0xe658
                    E659    425 _IBNIRQ	=	0xe659
                    E65A    426 _NAKIE	=	0xe65a
                    E65B    427 _NAKIRQ	=	0xe65b
                    E65C    428 _USBIE	=	0xe65c
                    E65D    429 _USBIRQ	=	0xe65d
                    E65E    430 _EPIE	=	0xe65e
                    E65F    431 _EPIRQ	=	0xe65f
                    E660    432 _GPIFIE	=	0xe660
                    E661    433 _GPIFIRQ	=	0xe661
                    E662    434 _USBERRIE	=	0xe662
                    E663    435 _USBERRIRQ	=	0xe663
                    E664    436 _ERRCNTLIM	=	0xe664
                    E665    437 _CLRERRCNT	=	0xe665
                    E666    438 _INT2IVEC	=	0xe666
                    E667    439 _INT4IVEC	=	0xe667
                    E668    440 _INTSETUP	=	0xe668
                    E670    441 _PORTACFG	=	0xe670
                    E671    442 _PORTCCFG	=	0xe671
                    E672    443 _PORTECFG	=	0xe672
                    E678    444 _I2CS	=	0xe678
                    E679    445 _I2DAT	=	0xe679
                    E67A    446 _I2CTL	=	0xe67a
                    E67B    447 _XAUTODAT1	=	0xe67b
                    E67C    448 _XAUTODAT2	=	0xe67c
                    E680    449 _USBCS	=	0xe680
                    E681    450 _SUSPEND	=	0xe681
                    E682    451 _WAKEUPCS	=	0xe682
                    E683    452 _TOGCTL	=	0xe683
                    E684    453 _USBFRAMEH	=	0xe684
                    E685    454 _USBFRAMEL	=	0xe685
                    E686    455 _MICROFRAME	=	0xe686
                    E687    456 _FNADDR	=	0xe687
                    E68A    457 _EP0BCH	=	0xe68a
                    E68B    458 _EP0BCL	=	0xe68b
                    E68D    459 _EP1OUTBC	=	0xe68d
                    E68F    460 _EP1INBC	=	0xe68f
                    E690    461 _EP2BCH	=	0xe690
                    E691    462 _EP2BCL	=	0xe691
                    E694    463 _EP4BCH	=	0xe694
                    E695    464 _EP4BCL	=	0xe695
                    E698    465 _EP6BCH	=	0xe698
                    E699    466 _EP6BCL	=	0xe699
                    E69C    467 _EP8BCH	=	0xe69c
                    E69D    468 _EP8BCL	=	0xe69d
                    E6A0    469 _EP0CS	=	0xe6a0
                    E6A1    470 _EP1OUTCS	=	0xe6a1
                    E6A2    471 _EP1INCS	=	0xe6a2
                    E6A3    472 _EP2CS	=	0xe6a3
                    E6A4    473 _EP4CS	=	0xe6a4
                    E6A5    474 _EP6CS	=	0xe6a5
                    E6A6    475 _EP8CS	=	0xe6a6
                    E6A7    476 _EP2FIFOFLGS	=	0xe6a7
                    E6A8    477 _EP4FIFOFLGS	=	0xe6a8
                    E6A9    478 _EP6FIFOFLGS	=	0xe6a9
                    E6AA    479 _EP8FIFOFLGS	=	0xe6aa
                    E6AB    480 _EP2FIFOBCH	=	0xe6ab
                    E6AC    481 _EP2FIFOBCL	=	0xe6ac
                    E6AD    482 _EP4FIFOBCH	=	0xe6ad
                    E6AE    483 _EP4FIFOBCL	=	0xe6ae
                    E6AF    484 _EP6FIFOBCH	=	0xe6af
                    E6B0    485 _EP6FIFOBCL	=	0xe6b0
                    E6B1    486 _EP8FIFOBCH	=	0xe6b1
                    E6B2    487 _EP8FIFOBCL	=	0xe6b2
                    E6B3    488 _SUDPTRH	=	0xe6b3
                    E6B4    489 _SUDPTRL	=	0xe6b4
                    E6B5    490 _SUDPTRCTL	=	0xe6b5
                    E6B8    491 _SETUPDAT	=	0xe6b8
                    E6C0    492 _GPIFWFSELECT	=	0xe6c0
                    E6C1    493 _GPIFIDLECS	=	0xe6c1
                    E6C2    494 _GPIFIDLECTL	=	0xe6c2
                    E6C3    495 _GPIFCTLCFG	=	0xe6c3
                    E6C4    496 _GPIFADRH	=	0xe6c4
                    E6C5    497 _GPIFADRL	=	0xe6c5
                    E6CE    498 _GPIFTCB3	=	0xe6ce
                    E6CF    499 _GPIFTCB2	=	0xe6cf
                    E6D0    500 _GPIFTCB1	=	0xe6d0
                    E6D1    501 _GPIFTCB0	=	0xe6d1
                    E6D2    502 _EP2GPIFFLGSEL	=	0xe6d2
                    E6D3    503 _EP2GPIFPFSTOP	=	0xe6d3
                    E6D4    504 _EP2GPIFTRIG	=	0xe6d4
                    E6DA    505 _EP4GPIFFLGSEL	=	0xe6da
                    E6DB    506 _EP4GPIFPFSTOP	=	0xe6db
                    E6DC    507 _EP4GPIFTRIG	=	0xe6dc
                    E6E2    508 _EP6GPIFFLGSEL	=	0xe6e2
                    E6E3    509 _EP6GPIFPFSTOP	=	0xe6e3
                    E6E4    510 _EP6GPIFTRIG	=	0xe6e4
                    E6EA    511 _EP8GPIFFLGSEL	=	0xe6ea
                    E6EB    512 _EP8GPIFPFSTOP	=	0xe6eb
                    E6EC    513 _EP8GPIFTRIG	=	0xe6ec
                    E6F0    514 _XGPIFSGLDATH	=	0xe6f0
                    E6F1    515 _XGPIFSGLDATLX	=	0xe6f1
                    E6F2    516 _XGPIFSGLDATLNOX	=	0xe6f2
                    E6F3    517 _GPIFREADYCFG	=	0xe6f3
                    E6F4    518 _GPIFREADYSTAT	=	0xe6f4
                    E6F5    519 _GPIFABORT	=	0xe6f5
                    E6C6    520 _FLOWSTATE	=	0xe6c6
                    E6C7    521 _FLOWLOGIC	=	0xe6c7
                    E6C8    522 _FLOWEQ0CTL	=	0xe6c8
                    E6C9    523 _FLOWEQ1CTL	=	0xe6c9
                    E6CA    524 _FLOWHOLDOFF	=	0xe6ca
                    E6CB    525 _FLOWSTB	=	0xe6cb
                    E6CC    526 _FLOWSTBEDGE	=	0xe6cc
                    E6CD    527 _FLOWSTBHPERIOD	=	0xe6cd
                    E60C    528 _GPIFHOLDAMOUNT	=	0xe60c
                    E67D    529 _UDMACRCH	=	0xe67d
                    E67E    530 _UDMACRCL	=	0xe67e
                    E67F    531 _UDMACRCQUAL	=	0xe67f
                    E6F8    532 _DBUG	=	0xe6f8
                    E6F9    533 _TESTCFG	=	0xe6f9
                    E6FA    534 _USBTEST	=	0xe6fa
                    E6FB    535 _CT1	=	0xe6fb
                    E6FC    536 _CT2	=	0xe6fc
                    E6FD    537 _CT3	=	0xe6fd
                    E6FE    538 _CT4	=	0xe6fe
                    E740    539 _EP0BUF	=	0xe740
                    E780    540 _EP1OUTBUF	=	0xe780
                    E7C0    541 _EP1INBUF	=	0xe7c0
                    F000    542 _EP2FIFOBUF	=	0xf000
                    F400    543 _EP4FIFOBUF	=	0xf400
                    F800    544 _EP6FIFOBUF	=	0xf800
                    FC00    545 _EP8FIFOBUF	=	0xfc00
                            546 ;--------------------------------------------------------
                            547 ; absolute external ram data
                            548 ;--------------------------------------------------------
                            549 	.area XABS    (ABS,XDATA)
                            550 ;--------------------------------------------------------
                            551 ; external initialized ram data
                            552 ;--------------------------------------------------------
                            553 	.area XISEG   (XDATA)
                            554 	.area HOME    (CODE)
                            555 	.area GSINIT0 (CODE)
                            556 	.area GSINIT1 (CODE)
                            557 	.area GSINIT2 (CODE)
                            558 	.area GSINIT3 (CODE)
                            559 	.area GSINIT4 (CODE)
                            560 	.area GSINIT5 (CODE)
                            561 	.area GSINIT  (CODE)
                            562 	.area GSFINAL (CODE)
                            563 	.area CSEG    (CODE)
                            564 ;--------------------------------------------------------
                            565 ; interrupt vector 
                            566 ;--------------------------------------------------------
                            567 	.area HOME    (CODE)
   0000                     568 __interrupt_vect:
   0000 02 00 08            569 	ljmp	__sdcc_gsinit_startup
                            570 ;--------------------------------------------------------
                            571 ; global & static initialisations
                            572 ;--------------------------------------------------------
                            573 	.area HOME    (CODE)
                            574 	.area GSINIT  (CODE)
                            575 	.area GSFINAL (CODE)
                            576 	.area GSINIT  (CODE)
                            577 	.globl __sdcc_gsinit_startup
                            578 	.globl __sdcc_program_startup
                            579 	.globl __start__stack
                            580 	.globl __mcs51_genXINIT
                            581 	.globl __mcs51_genXRAMCLEAR
                            582 	.globl __mcs51_genRAMCLEAR
                            583 ;	dds.c:24: xdata unsigned char *dat = (xdata unsigned char) 0xE000;
   0061 E4                  584 	clr	a
   0062 F5 08               585 	mov	_dat,a
   0064 F5 09               586 	mov	(_dat + 1),a
                            587 	.area GSFINAL (CODE)
   0066 02 00 03            588 	ljmp	__sdcc_program_startup
                            589 ;--------------------------------------------------------
                            590 ; Home
                            591 ;--------------------------------------------------------
                            592 	.area HOME    (CODE)
                            593 	.area HOME    (CODE)
   0003                     594 __sdcc_program_startup:
   0003 12 02 16            595 	lcall	_main
                            596 ;	return from main will lock up
   0006 80 FE               597 	sjmp .
                            598 ;--------------------------------------------------------
                            599 ; code
                            600 ;--------------------------------------------------------
                            601 	.area CSEG    (CODE)
                            602 ;------------------------------------------------------------
                            603 ;Allocation info for local variables in function 'Initialize'
                            604 ;------------------------------------------------------------
                            605 ;n                         Allocated to registers r6 r7 
                            606 ;------------------------------------------------------------
                            607 ;	dds.c:26: static void Initialize(void)
                            608 ;	-----------------------------------------
                            609 ;	 function Initialize
                            610 ;	-----------------------------------------
   0069                     611 _Initialize:
                    0007    612 	ar7 = 0x07
                    0006    613 	ar6 = 0x06
                    0005    614 	ar5 = 0x05
                    0004    615 	ar4 = 0x04
                    0003    616 	ar3 = 0x03
                    0002    617 	ar2 = 0x02
                    0001    618 	ar1 = 0x01
                    0000    619 	ar0 = 0x00
                            620 ;	dds.c:29: CPUCS=0x10;   // 48 MHz, CLKOUT output disabled. 
   0069 90 E6 00            621 	mov	dptr,#_CPUCS
   006C 74 10               622 	mov	a,#0x10
   006E F0                  623 	movx	@dptr,a
                            624 ;	dds.c:50: IFCONFIG=0x43;  // External IFCLK, 48MHz; slave FIFO. 
   006F 90 E6 01            625 	mov	dptr,#_IFCONFIG
   0072 74 43               626 	mov	a,#0x43
   0074 F0                  627 	movx	@dptr,a
                            628 ;	dds.c:51: SYNCDELAY;
   0075 00                  629 	 nop 
   0076 00                  630 	 nop 
   0077 00                  631 	 nop 
   0078 00                  632 	 nop 
   0079 00                  633 	 nop 
   007A 00                  634 	 nop 
   007B 00                  635 	 nop 
   007C 00                  636 	 nop 
                            637 ;	dds.c:53: IFCONFIG=0xC0;  // External IFCLK, 48MHz; slave FIFO. 
   007D 90 E6 01            638 	mov	dptr,#_IFCONFIG
   0080 74 C0               639 	mov	a,#0xC0
   0082 F0                  640 	movx	@dptr,a
                            641 ;	dds.c:54: SYNCDELAY;
   0083 00                  642 	 nop 
   0084 00                  643 	 nop 
   0085 00                  644 	 nop 
   0086 00                  645 	 nop 
   0087 00                  646 	 nop 
   0088 00                  647 	 nop 
   0089 00                  648 	 nop 
   008A 00                  649 	 nop 
                            650 ;	dds.c:80: FIFOPINPOLAR=0x00;
   008B 90 E6 09            651 	mov	dptr,#_FIFOPINPOLAR
   008E E4                  652 	clr	a
   008F F0                  653 	movx	@dptr,a
                            654 ;	dds.c:81: SYNCDELAY;
   0090 00                  655 	 nop 
   0091 00                  656 	 nop 
   0092 00                  657 	 nop 
   0093 00                  658 	 nop 
   0094 00                  659 	 nop 
   0095 00                  660 	 nop 
   0096 00                  661 	 nop 
   0097 00                  662 	 nop 
                            663 ;	dds.c:83: FIFOPINPOLAR=0x0c;
   0098 90 E6 09            664 	mov	dptr,#_FIFOPINPOLAR
   009B 74 0C               665 	mov	a,#0x0C
   009D F0                  666 	movx	@dptr,a
                            667 ;	dds.c:84: SYNCDELAY;
   009E 00                  668 	 nop 
   009F 00                  669 	 nop 
   00A0 00                  670 	 nop 
   00A1 00                  671 	 nop 
   00A2 00                  672 	 nop 
   00A3 00                  673 	 nop 
   00A4 00                  674 	 nop 
   00A5 00                  675 	 nop 
                            676 ;	dds.c:87: REVCTL=0x03;  // See TRM...
   00A6 90 E6 0B            677 	mov	dptr,#_REVCTL
   00A9 74 03               678 	mov	a,#0x03
   00AB F0                  679 	movx	@dptr,a
                            680 ;	dds.c:88: SYNCDELAY;
   00AC 00                  681 	 nop 
   00AD 00                  682 	 nop 
   00AE 00                  683 	 nop 
   00AF 00                  684 	 nop 
   00B0 00                  685 	 nop 
   00B1 00                  686 	 nop 
   00B2 00                  687 	 nop 
   00B3 00                  688 	 nop 
                            689 ;	dds.c:90: EP6CFG=0xe2;  // 1110 0010 (bulk IN, 512 bytes, double-buffered)
   00B4 90 E6 14            690 	mov	dptr,#_EP6CFG
   00B7 74 E2               691 	mov	a,#0xE2
   00B9 F0                  692 	movx	@dptr,a
                            693 ;	dds.c:91: SYNCDELAY;
   00BA 00                  694 	 nop 
   00BB 00                  695 	 nop 
   00BC 00                  696 	 nop 
   00BD 00                  697 	 nop 
   00BE 00                  698 	 nop 
   00BF 00                  699 	 nop 
   00C0 00                  700 	 nop 
   00C1 00                  701 	 nop 
                            702 ;	dds.c:93: EP2CFG=0xa2;  // 1010 0010 (bulk OUT, 512 bytes, double-buffered)
   00C2 90 E6 12            703 	mov	dptr,#_EP2CFG
   00C5 74 A2               704 	mov	a,#0xA2
   00C7 F0                  705 	movx	@dptr,a
                            706 ;	dds.c:94: SYNCDELAY;
   00C8 00                  707 	 nop 
   00C9 00                  708 	 nop 
   00CA 00                  709 	 nop 
   00CB 00                  710 	 nop 
   00CC 00                  711 	 nop 
   00CD 00                  712 	 nop 
   00CE 00                  713 	 nop 
   00CF 00                  714 	 nop 
                            715 ;	dds.c:96: FIFORESET = 0x80;  SYNCDELAY;  // NAK all requests from host. 
   00D0 90 E6 04            716 	mov	dptr,#_FIFORESET
   00D3 74 80               717 	mov	a,#0x80
   00D5 F0                  718 	movx	@dptr,a
   00D6 00                  719 	 nop 
   00D7 00                  720 	 nop 
   00D8 00                  721 	 nop 
   00D9 00                  722 	 nop 
   00DA 00                  723 	 nop 
   00DB 00                  724 	 nop 
   00DC 00                  725 	 nop 
   00DD 00                  726 	 nop 
                            727 ;	dds.c:97: FIFORESET = 0x82;  SYNCDELAY;  // Reset individual EP (2,4,6,8)
   00DE 90 E6 04            728 	mov	dptr,#_FIFORESET
   00E1 74 82               729 	mov	a,#0x82
   00E3 F0                  730 	movx	@dptr,a
   00E4 00                  731 	 nop 
   00E5 00                  732 	 nop 
   00E6 00                  733 	 nop 
   00E7 00                  734 	 nop 
   00E8 00                  735 	 nop 
   00E9 00                  736 	 nop 
   00EA 00                  737 	 nop 
   00EB 00                  738 	 nop 
                            739 ;	dds.c:98: FIFORESET = 0x84;  SYNCDELAY;
   00EC 90 E6 04            740 	mov	dptr,#_FIFORESET
   00EF 74 84               741 	mov	a,#0x84
   00F1 F0                  742 	movx	@dptr,a
   00F2 00                  743 	 nop 
   00F3 00                  744 	 nop 
   00F4 00                  745 	 nop 
   00F5 00                  746 	 nop 
   00F6 00                  747 	 nop 
   00F7 00                  748 	 nop 
   00F8 00                  749 	 nop 
   00F9 00                  750 	 nop 
                            751 ;	dds.c:99: FIFORESET = 0x86;  SYNCDELAY;
   00FA 90 E6 04            752 	mov	dptr,#_FIFORESET
   00FD 74 86               753 	mov	a,#0x86
   00FF F0                  754 	movx	@dptr,a
   0100 00                  755 	 nop 
   0101 00                  756 	 nop 
   0102 00                  757 	 nop 
   0103 00                  758 	 nop 
   0104 00                  759 	 nop 
   0105 00                  760 	 nop 
   0106 00                  761 	 nop 
   0107 00                  762 	 nop 
                            763 ;	dds.c:100: FIFORESET = 0x88;  SYNCDELAY;
   0108 90 E6 04            764 	mov	dptr,#_FIFORESET
   010B 74 88               765 	mov	a,#0x88
   010D F0                  766 	movx	@dptr,a
   010E 00                  767 	 nop 
   010F 00                  768 	 nop 
   0110 00                  769 	 nop 
   0111 00                  770 	 nop 
   0112 00                  771 	 nop 
   0113 00                  772 	 nop 
   0114 00                  773 	 nop 
   0115 00                  774 	 nop 
                            775 ;	dds.c:101: FIFORESET = 0x00;  SYNCDELAY;  // Resume normal operation. 
   0116 90 E6 04            776 	mov	dptr,#_FIFORESET
   0119 E4                  777 	clr	a
   011A F0                  778 	movx	@dptr,a
   011B 00                  779 	 nop 
   011C 00                  780 	 nop 
   011D 00                  781 	 nop 
   011E 00                  782 	 nop 
   011F 00                  783 	 nop 
   0120 00                  784 	 nop 
   0121 00                  785 	 nop 
   0122 00                  786 	 nop 
                            787 ;	dds.c:103: EP2FIFOCFG = 0x00;  // Make sure AUTOOUT=0. 
   0123 90 E6 18            788 	mov	dptr,#_EP2FIFOCFG
   0126 E4                  789 	clr	a
   0127 F0                  790 	movx	@dptr,a
                            791 ;	dds.c:104: SYNCDELAY;
   0128 00                  792 	 nop 
   0129 00                  793 	 nop 
   012A 00                  794 	 nop 
   012B 00                  795 	 nop 
   012C 00                  796 	 nop 
   012D 00                  797 	 nop 
   012E 00                  798 	 nop 
   012F 00                  799 	 nop 
                            800 ;	dds.c:109: OUTPKTEND = 0x82;  SYNCDELAY;
   0130 90 E6 49            801 	mov	dptr,#_OUTPKTEND
   0133 74 82               802 	mov	a,#0x82
   0135 F0                  803 	movx	@dptr,a
   0136 00                  804 	 nop 
   0137 00                  805 	 nop 
   0138 00                  806 	 nop 
   0139 00                  807 	 nop 
   013A 00                  808 	 nop 
   013B 00                  809 	 nop 
   013C 00                  810 	 nop 
   013D 00                  811 	 nop 
                            812 ;	dds.c:110: OUTPKTEND = 0x82;  SYNCDELAY;
   013E 90 E6 49            813 	mov	dptr,#_OUTPKTEND
   0141 74 82               814 	mov	a,#0x82
   0143 F0                  815 	movx	@dptr,a
   0144 00                  816 	 nop 
   0145 00                  817 	 nop 
   0146 00                  818 	 nop 
   0147 00                  819 	 nop 
   0148 00                  820 	 nop 
   0149 00                  821 	 nop 
   014A 00                  822 	 nop 
   014B 00                  823 	 nop 
                            824 ;	dds.c:114: PORTACFG = 0x00;
   014C 90 E6 70            825 	mov	dptr,#_PORTACFG
   014F E4                  826 	clr	a
   0150 F0                  827 	movx	@dptr,a
                            828 ;	dds.c:115: SYNCDELAY; // maybe not needed
   0151 00                  829 	 nop 
   0152 00                  830 	 nop 
   0153 00                  831 	 nop 
   0154 00                  832 	 nop 
   0155 00                  833 	 nop 
   0156 00                  834 	 nop 
   0157 00                  835 	 nop 
   0158 00                  836 	 nop 
                            837 ;	dds.c:118: OEA = 0x00;
   0159 75 B2 00            838 	mov	_OEA,#0x00
                            839 ;	dds.c:119: OEB = 0x00;
   015C 75 B3 00            840 	mov	_OEB,#0x00
                            841 ;	dds.c:120: OEC = 0x00;
   015F 75 B4 00            842 	mov	_OEC,#0x00
                            843 ;	dds.c:121: OED = 0x00;
   0162 75 B5 00            844 	mov	_OED,#0x00
                            845 ;	dds.c:123: OED = 0x0F;
   0165 75 B5 0F            846 	mov	_OED,#0x0F
                            847 ;	dds.c:125: for(n = 0; n < 100;n++) dat[n] = 0;
   0168 7E 00               848 	mov	r6,#0x00
   016A 7F 00               849 	mov	r7,#0x00
   016C                     850 00101$:
   016C C3                  851 	clr	c
   016D EE                  852 	mov	a,r6
   016E 94 64               853 	subb	a,#0x64
   0170 EF                  854 	mov	a,r7
   0171 64 80               855 	xrl	a,#0x80
   0173 94 80               856 	subb	a,#0x80
   0175 50 13               857 	jnc	00105$
   0177 EE                  858 	mov	a,r6
   0178 25 08               859 	add	a,_dat
   017A F5 82               860 	mov	dpl,a
   017C EF                  861 	mov	a,r7
   017D 35 09               862 	addc	a,(_dat + 1)
   017F F5 83               863 	mov	dph,a
   0181 E4                  864 	clr	a
   0182 F0                  865 	movx	@dptr,a
   0183 0E                  866 	inc	r6
   0184 BE 00 E5            867 	cjne	r6,#0x00,00101$
   0187 0F                  868 	inc	r7
   0188 80 E2               869 	sjmp	00101$
   018A                     870 00105$:
   018A 22                  871 	ret
                            872 ;------------------------------------------------------------
                            873 ;Allocation info for local variables in function 'ProcessSendData'
                            874 ;------------------------------------------------------------
                            875 ;src                       Allocated to registers 
                            876 ;dest                      Allocated to registers 
                            877 ;len                       Allocated with name '_ProcessSendData_len_1_1'
                            878 ;i                         Allocated with name '_ProcessSendData_i_1_1'
                            879 ;------------------------------------------------------------
                            880 ;	dds.c:130: static void ProcessSendData(void)
                            881 ;	-----------------------------------------
                            882 ;	 function ProcessSendData
                            883 ;	-----------------------------------------
   018B                     884 _ProcessSendData:
                            885 ;	dds.c:132: xdata const unsigned char *src=EP2FIFOBUF;
                            886 ;	dds.c:133: xdata unsigned char *dest=EP6FIFOBUF;
                            887 ;	dds.c:134: unsigned int len = (((int)EP2BCH)<<8 | EP2BCL);
   018B 90 E6 90            888 	mov	dptr,#_EP2BCH
   018E E0                  889 	movx	a,@dptr
   018F FE                  890 	mov	r6,a
   0190 7F 00               891 	mov	r7,#0x00
   0192 90 E6 91            892 	mov	dptr,#_EP2BCL
   0195 E0                  893 	movx	a,@dptr
   0196 FD                  894 	mov	r5,a
   0197 7C 00               895 	mov	r4,#0x00
   0199 42 07               896 	orl	ar7,a
   019B EC                  897 	mov	a,r4
   019C 42 06               898 	orl	ar6,a
   019E 8F 0A               899 	mov	_ProcessSendData_len_1_1,r7
   01A0 8E 0B               900 	mov	(_ProcessSendData_len_1_1 + 1),r6
                            901 ;	dds.c:136: for(i=0; i<len; i++,src++,dest++)
   01A2 E4                  902 	clr	a
   01A3 F5 0C               903 	mov	_ProcessSendData_i_1_1,a
   01A5 F5 0D               904 	mov	(_ProcessSendData_i_1_1 + 1),a
   01A7 7A 00               905 	mov	r2,#_EP2FIFOBUF
   01A9 7B F0               906 	mov	r3,#(_EP2FIFOBUF >> 8)
   01AB 78 00               907 	mov	r0,#_EP6FIFOBUF
   01AD 79 F8               908 	mov	r1,#(_EP6FIFOBUF >> 8)
   01AF                     909 00101$:
   01AF C3                  910 	clr	c
   01B0 E5 0C               911 	mov	a,_ProcessSendData_i_1_1
   01B2 95 0A               912 	subb	a,_ProcessSendData_len_1_1
   01B4 E5 0D               913 	mov	a,(_ProcessSendData_i_1_1 + 1)
   01B6 95 0B               914 	subb	a,(_ProcessSendData_len_1_1 + 1)
   01B8 50 30               915 	jnc	00104$
                            916 ;	dds.c:139: dat[i]=*src;
   01BA E5 0C               917 	mov	a,_ProcessSendData_i_1_1
   01BC 25 08               918 	add	a,_dat
   01BE FE                  919 	mov	r6,a
   01BF E5 0D               920 	mov	a,(_ProcessSendData_i_1_1 + 1)
   01C1 35 09               921 	addc	a,(_dat + 1)
   01C3 FF                  922 	mov	r7,a
   01C4 8A 82               923 	mov	dpl,r2
   01C6 8B 83               924 	mov	dph,r3
   01C8 E0                  925 	movx	a,@dptr
   01C9 FD                  926 	mov	r5,a
   01CA A3                  927 	inc	dptr
   01CB AA 82               928 	mov	r2,dpl
   01CD AB 83               929 	mov	r3,dph
   01CF 8E 82               930 	mov	dpl,r6
   01D1 8F 83               931 	mov	dph,r7
   01D3 ED                  932 	mov	a,r5
   01D4 F0                  933 	movx	@dptr,a
                            934 ;	dds.c:140: *dest = dat[i];
   01D5 88 82               935 	mov	dpl,r0
   01D7 89 83               936 	mov	dph,r1
   01D9 ED                  937 	mov	a,r5
   01DA F0                  938 	movx	@dptr,a
   01DB A3                  939 	inc	dptr
   01DC A8 82               940 	mov	r0,dpl
   01DE A9 83               941 	mov	r1,dph
                            942 ;	dds.c:136: for(i=0; i<len; i++,src++,dest++)
   01E0 05 0C               943 	inc	_ProcessSendData_i_1_1
   01E2 E4                  944 	clr	a
   01E3 B5 0C C9            945 	cjne	a,_ProcessSendData_i_1_1,00101$
   01E6 05 0D               946 	inc	(_ProcessSendData_i_1_1 + 1)
   01E8 80 C5               947 	sjmp	00101$
   01EA                     948 00104$:
                            949 ;	dds.c:144: SYNCDELAY;  OUTPKTEND=0x82;
   01EA 00                  950 	 nop 
   01EB 00                  951 	 nop 
   01EC 00                  952 	 nop 
   01ED 00                  953 	 nop 
   01EE 00                  954 	 nop 
   01EF 00                  955 	 nop 
   01F0 00                  956 	 nop 
   01F1 00                  957 	 nop 
   01F2 90 E6 49            958 	mov	dptr,#_OUTPKTEND
   01F5 74 82               959 	mov	a,#0x82
   01F7 F0                  960 	movx	@dptr,a
                            961 ;	dds.c:150: SYNCDELAY;  EP6BCH=len>>8;
   01F8 00                  962 	 nop 
   01F9 00                  963 	 nop 
   01FA 00                  964 	 nop 
   01FB 00                  965 	 nop 
   01FC 00                  966 	 nop 
   01FD 00                  967 	 nop 
   01FE 00                  968 	 nop 
   01FF 00                  969 	 nop 
   0200 90 E6 98            970 	mov	dptr,#_EP6BCH
   0203 E5 0B               971 	mov	a,(_ProcessSendData_len_1_1 + 1)
   0205 F0                  972 	movx	@dptr,a
                            973 ;	dds.c:151: SYNCDELAY;  EP6BCL=len&0xff;
   0206 00                  974 	 nop 
   0207 00                  975 	 nop 
   0208 00                  976 	 nop 
   0209 00                  977 	 nop 
   020A 00                  978 	 nop 
   020B 00                  979 	 nop 
   020C 00                  980 	 nop 
   020D 00                  981 	 nop 
   020E AE 0A               982 	mov	r6,_ProcessSendData_len_1_1
   0210 90 E6 99            983 	mov	dptr,#_EP6BCL
   0213 EE                  984 	mov	a,r6
   0214 F0                  985 	movx	@dptr,a
   0215 22                  986 	ret
                            987 ;------------------------------------------------------------
                            988 ;Allocation info for local variables in function 'main'
                            989 ;------------------------------------------------------------
                            990 ;n                         Allocated to registers r6 r7 
                            991 ;fu_udH                    Allocated to registers 
                            992 ;fu_udHC                   Allocated to registers 
                            993 ;fu_udL                    Allocated to registers 
                            994 ;dataH                     Allocated to registers 
                            995 ;dataL                     Allocated to registers 
                            996 ;resetH                    Allocated to registers 
                            997 ;resetL                    Allocated to registers 
                            998 ;triggerH                  Allocated to registers 
                            999 ;triggerL                  Allocated to registers 
                           1000 ;------------------------------------------------------------
                           1001 ;	dds.c:154: void main(void)
                           1002 ;	-----------------------------------------
                           1003 ;	 function main
                           1004 ;	-----------------------------------------
   0216                    1005 _main:
                           1006 ;	dds.c:160: Initialize();
   0216 12 00 69           1007 	lcall	_Initialize
                           1008 ;	dds.c:163: IOD = resetL;
   0219 75 B0 00           1009 	mov	_IOD,#0x00
                           1010 ;	dds.c:164: for(n = 0; n < 0xFFF; n ++ ) {
   021C 7E 00              1011 	mov	r6,#0x00
   021E 7F 00              1012 	mov	r7,#0x00
   0220                    1013 00106$:
   0220 C3                 1014 	clr	c
   0221 EE                 1015 	mov	a,r6
   0222 94 FF              1016 	subb	a,#0xFF
   0224 EF                 1017 	mov	a,r7
   0225 64 80              1018 	xrl	a,#0x80
   0227 94 8F              1019 	subb	a,#0x8f
   0229 50 0A              1020 	jnc	00109$
                           1021 ;	dds.c:165: IOD = resetH; }
   022B 75 B0 08           1022 	mov	_IOD,#0x08
                           1023 ;	dds.c:164: for(n = 0; n < 0xFFF; n ++ ) {
   022E 0E                 1024 	inc	r6
   022F BE 00 EE           1025 	cjne	r6,#0x00,00106$
   0232 0F                 1026 	inc	r7
   0233 80 EB              1027 	sjmp	00106$
   0235                    1028 00109$:
                           1029 ;	dds.c:166: IOD = resetL;
   0235 75 B0 00           1030 	mov	_IOD,#0x00
   0238                    1031 00123$:
                           1032 ;	dds.c:171: if(!(EP2CS & (1<<2)))
   0238 90 E6 A3           1033 	mov	dptr,#_EP2CS
   023B E0                 1034 	movx	a,@dptr
   023C FF                 1035 	mov	r7,a
   023D 20 E2 0B           1036 	jb	acc.2,00132$
                           1037 ;	dds.c:175: while(EP6CS & (1<<3));
   0240                    1038 00101$:
   0240 90 E6 A5           1039 	mov	dptr,#_EP6CS
   0243 E0                 1040 	movx	a,@dptr
   0244 FF                 1041 	mov	r7,a
   0245 20 E3 F8           1042 	jb	acc.3,00101$
                           1043 ;	dds.c:176: ProcessSendData();
   0248 12 01 8B           1044 	lcall	_ProcessSendData
                           1045 ;	dds.c:180: for(n = 0; n < 80; n ++ ) {
   024B                    1046 00132$:
   024B 7E 00              1047 	mov	r6,#0x00
   024D 7F 00              1048 	mov	r7,#0x00
   024F                    1049 00110$:
   024F C3                 1050 	clr	c
   0250 EE                 1051 	mov	a,r6
   0251 94 50              1052 	subb	a,#0x50
   0253 EF                 1053 	mov	a,r7
   0254 64 80              1054 	xrl	a,#0x80
   0256 94 80              1055 	subb	a,#0x80
   0258 50 17              1056 	jnc	00113$
                           1057 ;	dds.c:181: IOD = dat[n];
   025A EE                 1058 	mov	a,r6
   025B 25 08              1059 	add	a,_dat
   025D F5 82              1060 	mov	dpl,a
   025F EF                 1061 	mov	a,r7
   0260 35 09              1062 	addc	a,(_dat + 1)
   0262 F5 83              1063 	mov	dph,a
   0264 E0                 1064 	movx	a,@dptr
   0265 FD                 1065 	mov	r5,a
   0266 8D B0              1066 	mov	_IOD,r5
                           1067 ;	dds.c:182: IOD = dat[n];
   0268 8D B0              1068 	mov	_IOD,r5
                           1069 ;	dds.c:180: for(n = 0; n < 80; n ++ ) {
   026A 0E                 1070 	inc	r6
   026B BE 00 E1           1071 	cjne	r6,#0x00,00110$
   026E 0F                 1072 	inc	r7
   026F 80 DE              1073 	sjmp	00110$
   0271                    1074 00113$:
                           1075 ;	dds.c:186: IOD = fu_udL;
   0271 75 B0 00           1076 	mov	_IOD,#0x00
                           1077 ;	dds.c:187: for(n = 0; n < 0xF; n ++ ) {
   0274 7E 00              1078 	mov	r6,#0x00
   0276 7F 00              1079 	mov	r7,#0x00
   0278                    1080 00114$:
   0278 C3                 1081 	clr	c
   0279 EE                 1082 	mov	a,r6
   027A 94 0F              1083 	subb	a,#0x0F
   027C EF                 1084 	mov	a,r7
   027D 64 80              1085 	xrl	a,#0x80
   027F 94 80              1086 	subb	a,#0x80
   0281 50 0A              1087 	jnc	00117$
                           1088 ;	dds.c:188: IOD = fu_udH; }
   0283 75 B0 02           1089 	mov	_IOD,#0x02
                           1090 ;	dds.c:187: for(n = 0; n < 0xF; n ++ ) {
   0286 0E                 1091 	inc	r6
   0287 BE 00 EE           1092 	cjne	r6,#0x00,00114$
   028A 0F                 1093 	inc	r7
   028B 80 EB              1094 	sjmp	00114$
   028D                    1095 00117$:
                           1096 ;	dds.c:189: for(n = 0; n < 0xF; n ++ ) {
   028D 7E 00              1097 	mov	r6,#0x00
   028F 7F 00              1098 	mov	r7,#0x00
   0291                    1099 00118$:
   0291 C3                 1100 	clr	c
   0292 EE                 1101 	mov	a,r6
   0293 94 0F              1102 	subb	a,#0x0F
   0295 EF                 1103 	mov	a,r7
   0296 64 80              1104 	xrl	a,#0x80
   0298 94 80              1105 	subb	a,#0x80
   029A 50 0A              1106 	jnc	00121$
                           1107 ;	dds.c:190: IOD = fu_udHC; }
   029C 75 B0 03           1108 	mov	_IOD,#0x03
                           1109 ;	dds.c:189: for(n = 0; n < 0xF; n ++ ) {
   029F 0E                 1110 	inc	r6
   02A0 BE 00 EE           1111 	cjne	r6,#0x00,00118$
   02A3 0F                 1112 	inc	r7
   02A4 80 EB              1113 	sjmp	00118$
   02A6                    1114 00121$:
                           1115 ;	dds.c:191: IOD = fu_udL;
   02A6 75 B0 00           1116 	mov	_IOD,#0x00
   02A9 80 8D              1117 	sjmp	00123$
                           1118 	.area CSEG    (CODE)
                           1119 	.area CONST   (CODE)
                           1120 	.area XINIT   (CODE)
                           1121 	.area CABS    (ABS,CODE)
