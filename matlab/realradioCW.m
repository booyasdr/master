close all
clear 
format compact
% system('make run')

fftHalf = 4*1024; % half length of the first fft
fftHalf = 256; % half length of the first fft
cols = 2^9;

idx = (0:(2*fftHalf-1))/(2*fftHalf -1);
ham = .54 - .46*cos(idx*2*pi);
black = .42-.5*cos(2*pi*idx)+.08*cos(4*pi*idx);

% plot(20*log10(abs(fft(black,4096*2)))),shg
ham = ham;
ham = black;

tic
% if(~exist('data'))
fid = fopen('c:\gnuradio\bench_test2.dat');
x3 = [];
tic
x = zeros(2*fftHalf,cols-1);
disp(sprintf('x allocate time %f\n',toc))
    
stationAM = 1802.5*1000;

fs = 4e6;
fs = 10e6;
df1 = fs/fftHalf/2;     % frequency increment of the first fft
fbin = round(stationAM/df1 + 1); % station index into the first fft
fc2= (fbin-1)*df1; % center frequency of the indexed station

fs2 = fs/fftHalf;   % second fft sample rate
Nfft2 = cols;     % length of the second fft
df2 = fs2/Nfft2;    % second fft frequency increment
fbin2 = mod(round((fc2-stationAM)/df2+1),Nfft2); % second fft
fbin2 = Nfft2 - fbin2;
if(fbin2 == 0) fbin2 = Nfft2; end

BW = 4096;
vr = round(BW/df2);
range2 = (-vr:vr ) + fbin2;
range2 = mod(range2,Nfft2);
range2(range2==0) = Nfft2;

df = fs2/Nfft2;
f2 =0:df:(fs2-df);
    
tic
x = zeros(2*fftHalf,cols);
hamMat = repmat(ham',1,cols);
t = (1:(fftHalf*cols))/fs;
tmax = max(t);

T = fftHalf*cols/fs;
l4 = round(2*BW*T+1);
X4 = zeros(1,l4);
st = round(fbin2 - 700/df2);
en = round(fbin2 + 600/df2);
N = 140;
x3 = zeros(1,N*l4);
for n = 1:140
% for n = 1:1024
 	[data,count] = fread(fid,[ fftHalf cols ],'ushort','ieee-le');
 	if count <=20
         break
     end

 	data = data - mean(mean(data));

    x(1:fftHalf,2:cols) = data(:,1:(cols-1));
    x((fftHalf+1):2*fftHalf,:) =  data;
    x = x.*hamMat;

    X = fft(x);
		
%  	X_dB = 20*log10(abs(X));
%  	X_dB(X_dB < 70) = 70;
%   df = fs/fftHalf/2;
% 	f =0:df:(fs/2-df);
% 	dt = fftHalf/fs;
% 	T = fftHalf/fs;
% 	t = (0:(size(X_dB,2)-1))*dt;
% 	figure
% 	imagesc(t,f,X_dB(1:fftHalf,:)),shg
% return	
	x2 = X(fbin,:);
    if mod(fbin,2) == 0
        x2 = x2 .*(-1).^(0:length(x2)-1);
    end
 	X2 = fft(x2,Nfft2);
    
%  	X2_dB = 20*log10(abs(X2));    
%  	figure
%  	plot(X2_dB),shg
		    
    X4(1:(en-st+1)) = X2(st:en);
    X4(l4/2+2:end) = conj(X4(l4/2:-1:2)); 
    X4(1:2) = 0;
    X4(end) = 0;
		
	y5 =  real(ifft(X4));
% 	x3 = [x3 y5];
	x3((1:l4) + (n-1)*l4) = y5;
n
    x(1:fftHalf,1) = data(:,end);

end
toc
%  	figure
%  	plot(f3,[real(X4)' imag(X4)' abs(X4)']),shg
fclose(fid);
sound(real(x3)/max(real(x3)),2*BW)
tone = sin((1:length(x3))'*2*pi/BW/2*880);
plot([ real(x3)'/max(abs(real(x3))) ]),shg
figure
plot(20*log10(abs(fft([ real(x3)'/max(abs(real(x3))) tone],8192)))),shg
pause(.2)
% sound(tone,2*BW)
