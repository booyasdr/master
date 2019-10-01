%system('make','bench_dump')
fid = fopen('datadump.dat');
x = fread(fid,'ushort');

plot(x),shg