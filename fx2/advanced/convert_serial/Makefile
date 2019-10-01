INCLUDES = -I../../include
CC = sdcc -mmcs51
BASENAME = convert_serial
CYCFX2PROG = cycfx2prog

$(BASENAME).ihx: $(BASENAME).c
	$(CC) $(INCLUDES) $(BASENAME).c

clean:
	rm -f $(BASENAME).{asm,ihx,lnk,lst,map,mem,rel,rst,sym}

.PHONY:run
run: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run
	
run1: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:.2 sbulk:1,Hello_World dbulk:1,-512
	$(CYCFX2PROG) sbulk:1,"This is another test :)" dbulk:1,-512
	$(CYCFX2PROG) sbulk:1,"String one first" sbulk:1,"String two afterwards" dbulk:1,-512 dbulk:1,-512

