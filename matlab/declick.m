clear
close all

% N =32;
% lco = 1;
% uco = N/2;
% 
% w = 2*pi/N*1.1;
% x = cos(w*(0:(N-1)));
% plot(x),shg
% 
% X = fft(x(1:N/2));
% X([ 1 ]) = [];
% y = ifft(X)
% 
% X = fft(x(17:32));
% X([ 1 ]) = [];
% y = [ y ifft(X)];
% 
% plot((1:32)/2,x,(1:30)*16/15/2,y),shg
% grid
% return


halfFft = 256;
transferSize = 2^17;
fftPerBuf = transferSize/2/halfFft
fs = 64e6;
fc = 1210e3;
fb = 300;
K = .7;
T = 1/fs;
t = T:T:.5;

wc = 2*pi*fc;
wb = 2*pi*fb;

N = 2*halfFft - 1;
n = 0:halfFft-1;
wndw = .42-.5*cos(2*pi*n/N)+.08*cos(4*pi*n/N);
wndw = [ wndw fliplr(wndw) ]';
y = sin(wc*t).*(1 + .7*sin(wb*t));
yend = floor(length(y)/transferSize*2)*transferSize/2;
y= y(1:yend);
Y = reshape(y,halfFft,yend/halfFft);
Y = [Y(:,2:end); Y(:,1:end-1) ];
Yf = fft(Y);
df = fs/halfFft/2;
fbin = round(fc/df)
fs2 = fs/halfFft
tuneBuf = Yf(fbin,:);
fc2 = fbin*df
plot(20*log10(abs(fft(tuneBuf(1:end/2)))));shg

return
plot(y),shg

 