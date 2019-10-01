INCLUDES = -I../include
CC = sdcc -mmcs51 -V
BASENAME = eeprom_mark
CYCFX2PROG = cycfx2prog

$(BASENAME).ihx: $(BASENAME).c
	$(CC) $(INCLUDES) $(BASENAME).c

clean:
	rm -f *.{asm,ihx,lnk,lst,map,mem,rel,rst,sym,cdb,omf}
	rm -f $(BASENAME).asm
	rm -f $(BASENAME).ihx
	rm -f $(BASENAME).lnk
	rm -f $(BASENAME).lk
	rm -f $(BASENAME).lst
	rm -f $(BASENAME).map
	rm -f $(BASENAME).mem
	rm -f $(BASENAME).rel
	rm -f $(BASENAME).rst
	rm -f $(BASENAME).sym

.PHONY:run
runw: $(BASENAME).ihx
	$(CYCFX2PROG) prg:$(BASENAME).ihx run delay:3 reset dram:0x1000,64 dram:0x1200,64 run
runr: $(BASENAME).ihx
	$(CYCFX2PROG) delay:.5  sbulk:1,"getHW" dbulk:1,-512 
	$(CYCFX2PROG) delay:.5  dbulk:1,-512
	$(CYCFX2PROG) delay:.5  sbulk:1,"getFW" dbulk:1,-512 
	$(CYCFX2PROG) delay:.5  dbulk:1,-512
#	$(CYCFX2PROG) delay:1 reset dram:0x1000,64 dram:0x1200,64

	