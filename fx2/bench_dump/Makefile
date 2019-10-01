INCLUDES = -I../include
CC = sdcc -mmcs51
BASENAME = bench_dump
BENCHAPP = benchap
BENCHAPP =..\cycfx2prog.exe

$(BASENAME).ihx: $(BASENAME).c
	$(CC) $(INCLUDES) $(BASENAME).c

clean:
	rm -f $(BASENAME).{asm,ihx,lnk,lst,map,mem,rel,rst,sym,lk,omf,cdb,dat}
	rm -f $(BASENAME).asm
	rm -f $(BASENAME).ihx

.PHONY:run
run: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run delay:1000 reset dram:0x1000,0x1100

