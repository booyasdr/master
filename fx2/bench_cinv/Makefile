INCLUDES = -I../include
CC = sdcc -mmcs51
BASENAME = bench_cinv
BENCHAPP = benchmin.exe

$(BASENAME).ihx: $(BASENAME).c
	$(CC) $(INCLUDES) $(BASENAME).c

clean:
	rm -f $(BASENAME).{asm,ihx,lnk,lst,map,mem,rel,rst,sym,lk,omf,cdb,dat}

.PHONY:run
run1: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,16777216,32768

run2: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,33554432,8192

run3: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,16777216,65536

run: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,16777216,65536

runa: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,16777216,131072

runb: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,16777216,262144

runc: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,16777216,524288

rund: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,16777216,1048576

rune: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,33554432,2097152

runf: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,33554432,4194304


runz: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk:6,33554432,65536

rundump: $(BASENAME).ihx
	$(BENCHAPP) prg:$(BASENAME).ihx run bench_bulk_file:6,33554432,65536
