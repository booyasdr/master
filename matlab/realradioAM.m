close all
clear 
format compact
% system('make run')

halfFft = 1024; % half length of the first fft
transferSize = 2^17;
sizeSample = 2;
cols = transferSize/sizeSample/halfFft;

tunePeriod_sec = .1;
fs = 64e6;
overlap = .5;
fs2 = fs/2/halfFft/overlap
tuneLength = fs2 * tunePeriod_sec
blockLength = tuneLength*overlap
fbb = 44100;
bbLength = fbb*tunePeriod_sec;

idx = (0:(2*halfFft-1))/(2*halfFft -1);
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
x = zeros(2*halfFft,cols-1);
disp(sprintf('x allocate time %f\n',toc))
    
stationAM = 1500*1000;
stationAM = 900*1000;
stationAM = 780*1000;
stationAM = 1050*1000;
stationAM = 1040*1000;
stationAM = 640*1000;
stationAM = 990*1000;
stationAM = 800*1000;
stationAM = 1210*1000;

df1 = fs/halfFft/2;     % frequency increment of the first fft
fbin = round(stationAM/df1)+1; % station index into the first fft
fc2= (fbin-1)*df1; % center frequency of the indexed station

fs2 = fs/halfFft;   % second fft sample rate
df2 = fs2/tuneLength;    % second fft frequency increment
fbin2 = mod(round((fc2-stationAM)/df2),tuneLength)+1; % second fft

% fbin2 = 124;
BW = 6e3;
BW = 4096;
vr = round(BW/df2);
% range2 = (-vr:vr ) + fbin2;
% range2 = mod(range2,Nfft2);
% range2(range2==0) = Nfft2;

X_dB = [];
msave = 1i*ones(1000,1);
an = 0;
dmc0 = exp(-j*rem(stationAM/fs*halfFft,1));

df2 = fs2/tuneLength;
f2 =0:df2:(fs2-df2);
    
tic
x = zeros(2*halfFft,cols);
hamMat = repmat(ham',1,cols);
t = (1:(halfFft*cols))/fs;
mis = [];
tmax = max(t);

overlapData = zeros(halfFft,1);
start0 = blockLength+1;
start1 = 1;
end0 = start0 + cols-1;
end1 = start1 + cols-1;
tbi0 =1;
tbi1 =2;
NIFbuf = 4;
x2 = zeros(tuneLength,NIFbuf);
X3 = zeros(bbLength,1);
wt = (0:(bbLength/2-1))/(bbLength/2-1);
wt = .5 - .5*cos(wt'*pi);
youtlast = zeros(bbLength,1);

for n = 1:2000
    
%  	[data,count] = fread(fid,[ halfFft cols ],'ushort','ieee-le');
%  	if count <=20
%          break
%      end

    data = 2000*sin(t*2*pi*stationAM).*(1+.2*cos(t*2*pi*440));
    data = reshape(data,halfFft,cols);
    t = t + tmax;
	
 	data = data - 32768;

    x(1:halfFft,:) = [ overlapData data(:,1:(cols-1)) ];
    x((halfFft+1):2*halfFft,1:cols) =  data;
    overlapData = data(:,end);
    x = x.*hamMat;

    X = fft(x);
    if(end0 > tuneLength)
        lim0 = cols +(tuneLength - end0);
        x2(start0:end,tbi0) = X(fbin,1:lim0)';
        IFbuf = tbi0;
        
        tbi0 = tbi1;
        tbi1 = tbi1+1;
        if tbi1 > NIFbuf, tbi1 = tbi1 - NIFbuf; end
        
        start0 = start1;
        end0 = end1;
        x2(start0:end0,tbi0) = X(fbin,:)';
        end1 = cols-lim0;
        x2(1:end1,tbi1) = X(fbin,(lim0+1):cols)';
        start0 = end0 + 1;
        end0 = end0 + cols;
        start1 = end1 + 1;
        end1 = end1 + cols;
    else
        x2(start0:end0,tbi0) = X(fbin,:)';
        x2(start1:end1,tbi1) = X(fbin,:)';

        start0 = start0 + cols;
        start1 = start1 + cols;
        end0 = end0 + cols;
        end1 = end1 + cols;
        continue;
    end
    
    if mod(fbin,2) == 0
        x2(:,IFbuf) = x2(:,IFbuf) .*(-1).^(0:length(x2)-1)';
    end
 	X2 = fft(x2(:,IFbuf));
	
 	X3(1:(vr+1)) = X2(mod(((0:vr)+fbin2-1),bbLength)+1);
 	X3(bbLength+((-vr+1):0)) = X2(mod(((-vr:-1)+fbin2-1),bbLength)+1);
	
	yout =  ifft(X3);
	x3 = [x3; yout(1:bbLength/2).*wt+youtlast((bbLength/2+1):end).*(1-wt)];
    youtlast = yout;
    
    if mod(n,10) == 0, n, end
    x(1:halfFft,1) = data(:,end);

end
toc
xs = abs(x3);
xs = 2*xs/max(xs)-1;
%  	figure
%  	plot(f3,[real(X4)' imag(X4)' abs(X4)']),shg
fclose(fid);
% sound(real(x3)/max(real(x3)),2*BW)
sound(xs,fbb)
% sound(abs(x3)/max(abs(x3)),2*BW)
tone = sin((1:length(x3))'*2*pi/BW/2*880);
plot(xs),shg
% plot([ real(x3)'/max(abs(real(x3))) ]),shg
figure
plot(20*log10(abs(fft([ real(x3)'/max(abs(real(x3))) tone],8192)))),shg
pause(.2)
% sound(tone,2*BW)
