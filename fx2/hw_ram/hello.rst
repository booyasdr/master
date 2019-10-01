                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.1.0 #7066 (Nov 22 2011) (MINGW32)
                              4 ; This file was generated Sat Oct 27 17:07:32 2012
                              5 ;--------------------------------------------------------
                              6 	.module hello
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 ;--------------------------------------------------------
                             14 ; special function registers
                             15 ;--------------------------------------------------------
                             16 	.area RSEG    (ABS,DATA)
   0000                      17 	.org 0x0000
                             18 ;--------------------------------------------------------
                             19 ; special function bits
                             20 ;--------------------------------------------------------
                             21 	.area RSEG    (ABS,DATA)
   0000                      22 	.org 0x0000
                             23 ;--------------------------------------------------------
                             24 ; overlayable register banks
                             25 ;--------------------------------------------------------
                             26 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                      27 	.ds 8
                             28 ;--------------------------------------------------------
                             29 ; internal ram data
                             30 ;--------------------------------------------------------
                             31 	.area DSEG    (DATA)
                             32 ;--------------------------------------------------------
                             33 ; overlayable items in internal ram 
                             34 ;--------------------------------------------------------
                             35 	.area	OSEG    (OVR,DATA)
                             36 ;--------------------------------------------------------
                             37 ; Stack segment in internal ram 
                             38 ;--------------------------------------------------------
                             39 	.area	SSEG	(DATA)
   0008                      40 __start__stack:
   0008                      41 	.ds	1
                             42 
                             43 ;--------------------------------------------------------
                             44 ; indirectly addressable internal ram data
                             45 ;--------------------------------------------------------
                             46 	.area ISEG    (DATA)
                             47 ;--------------------------------------------------------
                             48 ; absolute internal ram data
                             49 ;--------------------------------------------------------
                             50 	.area IABS    (ABS,DATA)
                             51 	.area IABS    (ABS,DATA)
                             52 ;--------------------------------------------------------
                             53 ; bit data
                             54 ;--------------------------------------------------------
                             55 	.area BSEG    (BIT)
                             56 ;--------------------------------------------------------
                             57 ; paged external ram data
                             58 ;--------------------------------------------------------
                             59 	.area PSEG    (PAG,XDATA)
                             60 ;--------------------------------------------------------
                             61 ; external ram data
                             62 ;--------------------------------------------------------
                             63 	.area XSEG    (XDATA)
                             64 ;--------------------------------------------------------
                             65 ; absolute external ram data
                             66 ;--------------------------------------------------------
                             67 	.area XABS    (ABS,XDATA)
                             68 ;--------------------------------------------------------
                             69 ; external initialized ram data
                             70 ;--------------------------------------------------------
                             71 	.area XISEG   (XDATA)
                             72 	.area HOME    (CODE)
                             73 	.area GSINIT0 (CODE)
                             74 	.area GSINIT1 (CODE)
                             75 	.area GSINIT2 (CODE)
                             76 	.area GSINIT3 (CODE)
                             77 	.area GSINIT4 (CODE)
                             78 	.area GSINIT5 (CODE)
                             79 	.area GSINIT  (CODE)
                             80 	.area GSFINAL (CODE)
                             81 	.area CSEG    (CODE)
                             82 ;--------------------------------------------------------
                             83 ; interrupt vector 
                             84 ;--------------------------------------------------------
                             85 	.area HOME    (CODE)
   0000                      86 __interrupt_vect:
   0000 02 00 08             87 	ljmp	__sdcc_gsinit_startup
                             88 ;--------------------------------------------------------
                             89 ; global & static initialisations
                             90 ;--------------------------------------------------------
                             91 	.area HOME    (CODE)
                             92 	.area GSINIT  (CODE)
                             93 	.area GSFINAL (CODE)
                             94 	.area GSINIT  (CODE)
                             95 	.globl __sdcc_gsinit_startup
                             96 	.globl __sdcc_program_startup
                             97 	.globl __start__stack
                             98 	.globl __mcs51_genXINIT
                             99 	.globl __mcs51_genXRAMCLEAR
                            100 	.globl __mcs51_genRAMCLEAR
                            101 	.area GSFINAL (CODE)
   0061 02 00 03            102 	ljmp	__sdcc_program_startup
                            103 ;--------------------------------------------------------
                            104 ; Home
                            105 ;--------------------------------------------------------
                            106 	.area HOME    (CODE)
                            107 	.area HOME    (CODE)
   0003                     108 __sdcc_program_startup:
   0003 12 00 64            109 	lcall	_main
                            110 ;	return from main will lock up
   0006 80 FE               111 	sjmp .
                            112 ;--------------------------------------------------------
                            113 ; code
                            114 ;--------------------------------------------------------
                            115 	.area CSEG    (CODE)
                            116 ;------------------------------------------------------------
                            117 ;Allocation info for local variables in function 'main'
                            118 ;------------------------------------------------------------
                            119 ;dest                      Allocated to registers r3 r4 
                            120 ;src                       Allocated to registers 
                            121 ;------------------------------------------------------------
                            122 ;	hello.c:15: void main(void)
                            123 ;	-----------------------------------------
                            124 ;	 function main
                            125 ;	-----------------------------------------
   0064                     126 _main:
                    0007    127 	ar7 = 0x07
                    0006    128 	ar6 = 0x06
                    0005    129 	ar5 = 0x05
                    0004    130 	ar4 = 0x04
                    0003    131 	ar3 = 0x03
                    0002    132 	ar2 = 0x02
                    0001    133 	ar1 = 0x01
                    0000    134 	ar0 = 0x00
                            135 ;	hello.c:25: const char *src="Gdkkn+\x1fvnqkc \x1fSghr\x1fhr\x1fxntq\x1f"
                            136 ;	hello.c:27: while(*src)
   0064 7D AF               137 	mov	r5,#__str_0
   0066 7E 00               138 	mov	r6,#(__str_0 >> 8)
   0068 7F 80               139 	mov	r7,#0x80
   006A 7B 00               140 	mov	r3,#0x00
   006C 7C 10               141 	mov	r4,#0x10
   006E                     142 00101$:
   006E 8D 82               143 	mov	dpl,r5
   0070 8E 83               144 	mov	dph,r6
   0072 8F F0               145 	mov	b,r7
   0074 12 00 8F            146 	lcall	__gptrget
   0077 FA                  147 	mov	r2,a
   0078 60 13               148 	jz	00105$
                            149 ;	hello.c:28: {  *dest++ = *src++ + 1;  }
   007A 0D                  150 	inc	r5
   007B BD 00 01            151 	cjne	r5,#0x00,00114$
   007E 0E                  152 	inc	r6
   007F                     153 00114$:
   007F 0A                  154 	inc	r2
   0080 8B 82               155 	mov	dpl,r3
   0082 8C 83               156 	mov	dph,r4
   0084 EA                  157 	mov	a,r2
   0085 F0                  158 	movx	@dptr,a
   0086 A3                  159 	inc	dptr
   0087 AB 82               160 	mov	r3,dpl
   0089 AC 83               161 	mov	r4,dph
   008B 80 E1               162 	sjmp	00101$
   008D                     163 00105$:
   008D 80 FE               164 	sjmp	00105$
                            165 	.area CSEG    (CODE)
                            166 	.area CONST   (CODE)
   00AF                     167 __str_0:
   00AF 47 64 6B 6B 6E 2B   168 	.ascii "Gdkkn+"
   00B5 1F                  169 	.db 0x1F
   00B6 76 6E 71 6B 63 20   170 	.ascii "vnqkc "
   00BC 1F                  171 	.db 0x1F
   00BD 53 67 68 72         172 	.ascii "Sghr"
   00C1 1F                  173 	.db 0x1F
   00C2 68 72               174 	.ascii "hr"
   00C4 1F                  175 	.db 0x1F
   00C5 78 6E 74 71         176 	.ascii "xntq"
   00C9 1F                  177 	.db 0x1F
   00CA 45 57 31            178 	.ascii "EW1"
   00CD 1F                  179 	.db 0x1F
   00CE 61 6E 60 71 63 2D   180 	.ascii "an`qc-"
   00D4 00                  181 	.db 0x00
                            182 	.area XINIT   (CODE)
                            183 	.area CABS    (ABS,CODE)
