close all
clear

halfFft = 512;
fs =64e6;
transferSize = 2^16;
T = 1/fs;
N = 256;
w = j*2*pi*fs/32*1.7;
t = T:T:T*transferSize;

s = reshape(exp(w*t),halfFft,transferSize/halfFft);
x =[ zeros(halfFft,1) s(:,2:end)];
h = repmat(hamming(2*halfFft)',1,transferSize/halfFft);
x= [x;s];
X = fft(x.*h);
imagesc(20*log10(abs(X(1:halfFft,:)))),shg
return
plot([real(s)' imag(s)']),shg
plot(abs(fft(s))),shg

