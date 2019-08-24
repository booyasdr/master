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
% fid = fopen('c:\gnuradio\bench_test.dat');
fid = fopen('c:\sdr\data\rfstatic.dat');
% fids = fopen('c:\sdr\data\sndB.dat');
% ss = fread(fids,'short','ieee-le');

% sound(ss/max(ss),22050)
% plot(ss),shg


x3 = [];
tic
x = zeros(2*fftHalf,cols-1);
disp(sprintf('x allocate time %f\n',toc))
    
stationAM = 1500*1000;
stationAM = 900*1000;
stationAM = 780*1000;
stationAM = 1050*1000;
stationAM = 1040*1000;
stationAM = 800*1000;
stationAM = 640*1000;
stationAM = 950*1000;
stationAM = 1210*1000;

fs = 4e6;
fs = 10e6;
fs = 64e6;
df1 = fs/fftHalf/2;     % frequency increment of the first fft
fbin = round(stationAM/df1 + 1); % station index into the first fft
fc2= (fbin-1)*df1; % center frequency of the indexed station

fs2 = fs/fftHalf;   % second fft sample rate
Nfft2 = cols;     % length of the second fft
df2 = fs2/Nfft2;    % second fft frequency increment
fbin2 = mod(round((fc2-stationAM)/df2+1),Nfft2); % second fft
fbin2 = Nfft2 - fbin2;
if(fbin2 == 0) fbin2 = Nfft2; end
% fbin2 = 124;
BW = 6e3;
BW = 4096;
vr = round(BW/df2);
range2 = (-vr:vr ) + fbin2;
range2 = mod(range2,Nfft2);
range2(range2==0) = Nfft2;

X_dB = [];
msave = 1i*ones(1000,1);
an = 0;
dmc0 = exp(-j*rem(stationAM/fs*fftHalf,1));

df = fs2/Nfft2;
f2 =0:df:(fs2-df);
    
tic
x = zeros(2*fftHalf,cols);
hamMat = repmat(ham',1,cols);
t = (1:(fftHalf*cols))/fs;
mis = [];
tmax = max(t);
% for n = 1:10000
% for n = 1:512
for n = 1:2000
 	[data,count] = fread(fid,[ fftHalf cols ],'ushort','ieee-le');
 	if count <=20
         break
     end

%     data = 2000*sin(t*2*pi*stationAM).*(1+.2*cos(t*2*pi*880));
%     data = reshape(data,fftHalf,cols);
%     t = t + tmax;
	
 	data = data - 32768;

    x(1:fftHalf,2:cols) = data(:,1:(cols-1));
    x((fftHalf+1):2*fftHalf,1:cols) =  data;
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
	% clear X X_dB data 
 	X2 = fft(x2,Nfft2);
%  	X2_dB = 20*log10(abs(X2));
 	X2_dB = abs(X2);
    
%    	figure
%    	plot(X2_dB),shg
		
    [m,mi] = max(X2_dB(range2));
    mis =[mis mi];
    mi = range2(mi);
    mm = X2(mi);
    
% 	range3 = (-vr:(vr+1) ) + mi;
	range3 = (-vr:(vr) ) + mi;
	range3 = mod(range3,Nfft2);
	range3(range3==0) = Nfft2;
	X3= X2(range3);
  	f3=(0:(length(X3)-1))*df1;
%  	X3_dB = 20*log10(abs(X3));
% 	X3_dB = abs(X3);
	
%    	figure(1)
%    	plot(X3_dB),shg
	
	[m,mi] = max(abs(X3));
    ix = mod([-1 1] +mi-1,length(X3))+1;
 	[m2,mi2] = max(abs(X3(ix)));
	mi2 = ix(mi2);
	m = X3(mi) + X3(mi2);
	m = m/abs(m);
%      if n == 1
%          mc = m;
%          dmc = dmc0;
%          mm1 = m;
%      else
%          dmc = dmc + .01*(m/mm1 - dmc);
%          mc = dmc*mc;
%          mc = mc + .01*(m - mc);
%          mm1 = m;
%     end
    
    phs(n) = m;
%     phsc(n) = mc;
     mc = m;
	X3 = X3*conj(mc);
% 	msave(n) = m;
%     an = angle(m)*.1 + .9*an;
%     m = exp(j*an);
%  	figure
%  	plot(f3,[real(X3)' imag(X3)' abs(X3)']),shg
	
	N = length(X3);
	X4 = [X3(mi:N) X3(1:(mi-1)) ];
	
% 	 figure
% 	 plot(f3,20*log10(abs(X4)))
	
	Nlow = round(70/df2);
    if Nlow < 1 Nlow =1; end
    X5 = X4;
%  	X5(1:Nlow) = 0;
%  	X5((end-Nlow+2):end) = 0;
	
% 	figure
% 	plot(f3,20*log10(abs([X3' X4' X5']))),shg
	
	y5 =  ifft(X5);
	x3 = [x3 y5];
if mod(n,10) == 0, n, end
    x(1:fftHalf,1) = data(:,end);

end
toc
xs = abs(x3);
xs = 2*xs/max(xs)-1;
%  	figure
%  	plot(f3,[real(X4)' imag(X4)' abs(X4)']),shg
fclose(fid);
% sound(real(x3)/max(real(x3)),2*BW)
sound(xs,2*BW)
% sound(abs(x3)/max(abs(x3)),2*BW)
tone = sin((1:length(x3))'*2*pi/BW/2*880);
plot(xs),shg
% plot([ real(x3)'/max(abs(real(x3))) ]),shg
figure
plot(20*log10(abs(fft([ real(x3)'/max(abs(real(x3))) tone],8192)))),shg
pause(.2)
% sound(tone,2*BW)
