INCLUDES=-Iinclude
PROGRAM=fx2pipe
BENCHAPP = ../benchsubreap.exe

CC=sdcc -mmcs51

#fx2pipe_static.cc: fx2pipe.ihx
#	@echo "#include <stdio.h>  /* For NULL... */" > fx2pipe_static.cc
#	@echo >> fx2pipe_static.cc
#	@echo "const char *fx2pipe_static_firmware[]={" >> fx2pipe_static.cc
#	@bash -c 'while read line ; do echo -e "\t\"$$line\"," >> fx2pipe_static.cc ; done < fx2pipe.ihx'
#	@echo -e "\tNULL" >> fx2pipe_static.cc
#	@echo "};" >> fx2pipe_static.cc
#	@echo "Created fx2pipe_static.cc"

$(PROGRAM).ihx: $(PROGRAM).c
	$(CC) $(INCLUDES) $(PROGRAM).c
	ls -l $(PROGRAM).ihx

clean:
	rm -f fx2pipe.{asm,ihx,lnk,lst,map,mem,rel,rst,sym}
	rm -f $(PROGRAM).asm $(PROGRAM).ihx $(PROGRAM).lnk $(PROGRAM).lst $(PROGRAM).map
	rm -f $(PROGRAM).mem $(PROGRAM).rel $(PROGRAM).rst $(PROGRAM).sym $(PROGRAM).lk
	dir

run: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square100kHz1Atten10D.dat,16384,2
runramp: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\dadat\ramp10D.dat,16384,20

sine100k1A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\sine100kHz1Atten10D.dat,16384,10
sine100k2A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\sine100kHz2Atten10D.dat,16384,10
sine103k2A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\sine103kHz2Atten10D.dat,16384,10
sine500k2A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\sine500kHz2Atten10D.dat,16384,10
sine500k1A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\sine500kHz1Atten10D.dat,16384,10
sine1000k2A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\sine1000kHz2Atten10D.dat,16384,10
sine1000k1A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\sine1000kHz1Atten10D.dat,16384,10
sine1860k1A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\sine1860kHz1Atten10D.dat,16384,10
sine2000k2A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\sine2000kHz2Atten10D.dat,16384,10
sine2000k1A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\sine2000kHz1Atten10D.dat,16384,10
sine4000k2A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\sine4000kHz2Atten10D.dat,16384,10
sine4000k1A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\sine4000kHz1Atten10D.dat,16384,10
square1k1A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square1kHz1Atten10D.dat,16384,10
square5k1A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square5kHz1Atten10D.dat,16384,10
square20k1A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square20kHz1Atten10D.dat,16384,10
square20k2A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square20kHz2Atten10D.dat,16384,10
square20k4A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square20kHz4Atten10D.dat,16384,10
square100k1A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square100kHz1Atten10D.dat,16384,10
square100k2A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square100kHz2Atten10D.dat,16384,10
square100k4A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square100kHz4Atten10D.dat,16384,10
square250k1A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square250kHz1Atten10D.dat,16384,10
square250k2A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square250kHz2Atten10D.dat,16384,10
square250k4A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square250kHz4Atten10D.dat,16384,10
square500k1A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square500kHz1Atten10D.dat,16384,10
square500k2A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square500kHz2Atten10D.dat,16384,10
square500k4A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square500kHz4Atten10D.dat,16384,10
square1000k1A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square1000kHz1Atten10D.dat,16384,10
square1000k2A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square1000kHz2Atten10D.dat,16384,10
square1000k4A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square1000kHz4Atten10D.dat,16384,10
square2500k1A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square2500kHz1Atten10D.dat,16384,10
square2500k2A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square2500kHz2Atten10D.dat,16384,10
square2500k4A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square2500kHz4Atten10D.dat,16384,10
square5000k1A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square5000kHz1Atten10D.dat,16384,10
square5000k2A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square5000kHz2Atten10D.dat,16384,10
square5000k4A: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\square5000kHz4Atten10D.dat,16384,10
runFFconstant: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\constantFFD10.dat,16384,10
run00constant: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\constant00D10.dat,16384,10
run7Fconstant: $(PROGRAM).ihx
	$(BENCHAPP) prg:$(PROGRAM).ihx run delay:10 bench_bulk_write:2,c:\sdr\dadat\constant7FD10.dat,16384,10
