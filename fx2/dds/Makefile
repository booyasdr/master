INCLUDES = -I../include
INCLUDES = -I../include
CC = sdcc -mmcs51
BASENAME = dds
CYCFX2PROG =fx2prog.exe

$(BASENAME).ihx: $(BASENAME).c
	$(CC) $(INCLUDES) $(BASENAME).c

clean:
	rm -f $(BASENAME).{asm,ihx,lnk,lst,map,mem,rel,rst,sym,sym,lk,omf,cdb}

.PHONY:run
run: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,2.2 dbulk:6,-512
run11: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,7 dbulk:6,-512
runtwo: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,10 dbulk:6,-512
runtwop1: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,.1 dbulk:6,-512
runtwo1: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,1 dbulk:6,-512
runtwo2p5: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,2.5 dbulk:6,-512
runtwo5: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,5 dbulk:6,-512
runtwo7: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,7 dbulk:6,-512
runp005: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,.005 dbulk:6,-512
runp01: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,.01 dbulk:6,-512
runp02: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,.02 dbulk:6,-512
runp05: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,.05 dbulk:6,-512
runp1: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,.1 dbulk:6,-512
runp2: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,.2 dbulk:6,-512
runp5: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,.5 dbulk:6,-512
runp55: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,.55 dbulk:6,-512
runp8: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 dds:2,.8 dbulk:6,-512
run1: $(BASENAME).ihx
	$(CYCFX2PROG)  prg:$(BASENAME).ihx run delay:10 dds:2,1 dbulk:6,-512
run1p1: $(BASENAME).ihx
	$(CYCFX2PROG)  prg:$(BASENAME).ihx run delay:10 dds:2,1.1 dbulk:6,-512
run2: $(BASENAME).ihx
	$(CYCFX2PROG)  prg:$(BASENAME).ihx run delay:10 dds:2,2 dbulk:6,-512
run2p1: $(BASENAME).ihx
	$(CYCFX2PROG)  prg:$(BASENAME).ihx run delay:10 dds:2,2.1 dbulk:6,-512
run3: $(BASENAME).ihx
	$(CYCFX2PROG)  prg:$(BASENAME).ihx run delay:10 dds:2,3 dbulk:6,-512
run3p1: $(BASENAME).ihx
	$(CYCFX2PROG)  prg:$(BASENAME).ihx run delay:10 dds:2,3.1 dbulk:6,-512
run4: $(BASENAME).ihx
	$(CYCFX2PROG)  prg:$(BASENAME).ihx run delay:10 dds:2,4 dbulk:6,-512
run5: $(BASENAME).ihx
	$(CYCFX2PROG)  prg:$(BASENAME).ihx run delay:10 dds:2,5 dbulk:6,-512
run7: $(BASENAME).ihx
	$(CYCFX2PROG)  prg:$(BASENAME).ihx run delay:10 dds:2,7 dbulk:6,-512
run8: $(BASENAME).ihx
	$(CYCFX2PROG)  prg:$(BASENAME).ihx run delay:10 dds:2,8 dbulk:6,-512
run10: $(BASENAME).ihx
	$(CYCFX2PROG)  prg:$(BASENAME).ihx run delay:10 dds:2,10 dbulk:6,-512
run15p1: $(BASENAME).ihx
	$(CYCFX2PROG)  prg:$(BASENAME).ihx run delay:10 dds:2,13.1 dbulk:6,-512
run20: $(BASENAME).ihx
	$(CYCFX2PROG)  prg:$(BASENAME).ihx run delay:10 dds:2,20 dbulk:6,-512
runconvert: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:10 sbulk:2,Hello_World dbulk:6,-512
	$(CYCFX2PROG) sbulk:2,"This is another test :)" dbulk:6,-512
	$(CYCFX2PROG) sbulk:2,"String one first" sbulk:2,"String two afterwards" dbulk:6,-512 dbulk:6,-512
