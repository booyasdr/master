clear 
close all
format compact
khzpp = [125 250 500 1000 2000];
df = khzpp*1e3/1024;
lens = 64e6./df;

sll_dB = 100;

for n =1:length(lens)
len = lens(n);
t = taylr(len,sll_dB);
T = (20*log10(abs(fft(t,len*4))));

fname = ['taylor' num2str(sll_dB) 'dBsll-' num2str(khzpp(n)) 'khzpp.dat']
fid = fopen(fname,'w');
ts = single(t);
fwrite(fid,ts,'float')
fclose(fid)
end

TS = (20*log10(abs(fft(ts,len*4))));

plot([ TS T]),shg
figure
plot([t ts]),shg
