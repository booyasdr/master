clear 
close all
format compact

fs = 64e6;
halfFft = 2^21;
fid = fopen('c:\gnuradio\data\rfdata.dat');
x = fread(fid,2^25,'ushort','ieee-le');
fclose(fid)

len = round(length(x))/4;
len = floor(len/halfFft/2)*halfFft;
x = x(1:len);
f = (0:(len-1))*fs/len;
y = reshape(x,halfFft,len/halfFft);
y =[y(:,2:end); y(:,1:end-1) ];
h = hamming(2*halfFft)';
for n = 1:size(y,2)
    y(:,n) = y(:,n).*h;
end
Y = fft(y);
YdB = 20*log10(abs(Y));
df = fs/halfFft/2;
f=(0:halfFft-1)*df;
dt = halfFft/fs;
t = (0:size(y,2)-1)*dt;
figure('windowstyle','docked')
% imagesc(t,f,YdB(1:end/2,:));
 plot(f,YdB(1:end/2,:));
return

plot(y(1:e/2),F(1:e/2)),shg
axis tight 
return

df = diff(y(1:2));
station = 1210e3;
am1500 = ((station - 15e3 )< y) &  ((station + 15e3)> y) ;
[m,mi] = max(am1500.*F')
stationN = mi;
stationW = round(15000/df);
amRange = (-stationW:stationW) + stationN;
figure
stationF = F(amRange);
plot(y(amRange),stationF),shg

demod = f(amRange);
N = length(demod);
Nlow = 40/df;
figure
plot(20*log10(abs(demod)))

demod = [demod(floor(N/2):N)' demod(1:(floor(N/2)-1))' ];
demod(1:Nlow) = 0;
demod((end-Nlow):end) = 0;

figure
plot(20*log10(abs(demod)))

% plot(abs(demod));

snd = ifft(demod);
figure
plot([ real(snd)' imag(snd)'])
sound(real(snd),24000)