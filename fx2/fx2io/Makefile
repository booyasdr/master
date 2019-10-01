INCLUDES = -I../include
CC = sdcc -mmcs51
BASENAME = portio
BENCHAPP = cycfx2prog.exe

$(BASENAME).ihx: $(BASENAME).c
	$(CC) $(INCLUDES) $(BASENAME).c

clean:
	rm -f $(BASENAME).asm $(BASENAME).ihx	$(BASENAME).ihx	$(BASENAME).lnk	
	rm -f $(BASENAME).lst	$(BASENAME).map	$(BASENAME).mem	$(BASENAME).rel	
	rm -f $(BASENAME).rst	$(BASENAME).sym	$(BASENAME).lk	$(BASENAME).omf
	rm -f $(BASENAME).cdb	$(BASENAME).dat
	rm -f $(BASENAME).{asm,ihx,lnk,lst,map,mem,rel,rst,sym,lk,omf,cdb,dat}

.PHONY:run
run: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run delay:10
