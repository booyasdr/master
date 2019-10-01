INCLUDES = -I../include
CC = sdcc -mmcs51
BASENAME = bench_test
CINVNAME = bench_cinv
NINVNAME = bench_ninv
BENCHAPP = ../benchsubreap.exe

$(BASENAME).ihx: $(BASENAME).c
	$(CC) $(INCLUDES) $(BASENAME).c

clean:
	rm -f $(BASENAME).{asm,ihx,lnk,lst,map,mem,rel,rst,sym,lk,omf,cdb,dat}

.PHONY:run

run: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,16777216,65536

runcinv: $(CINVNAME).ihx
	$(BENCHAPP) prg:$(CINVNAME).ihx run bench_bulk_file:6,16777216,65536

runninv: $(NINVNAME).ihx
	$(BENCHAPP) prg:$(NINVNAME).ihx run bench_bulk_file:6,16777216,65536

runa: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,33554432,65536

runb: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,67108864,65536

runc: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,67108864,131072

rund: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,134217728,131072

runz: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk:6,33554432,65536

rundump: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,33554432,65536
