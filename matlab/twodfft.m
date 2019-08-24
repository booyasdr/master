close all
clear
fs = 44100;
dt = 1/fs;
t = 0:dt:2;
y = chirp(t,100,2,2000);
y = [y y];
halfFft = 256;
N = floor(length(y)/halfFft)*halfFft;
y = y(1:N);
sound(y/40,fs)
x = reshape(y,halfFft,N/halfFft);
X = [zeros(halfFft,1) x ;x zeros(halfFft,1)  ];
h = hamming(2*halfFft);
H = repmat(h',1,N/halfFft +1);

Xf = fft(X.*H);
imagesc(20*log10(abs((Xf(halfFft/8*15+1:end,:)))))