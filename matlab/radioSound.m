close all
clear all
format compact
system('make run')

fftHalf = 128; % half length of the first fft
cols = 2^8;

ham = (0:(2*fftHalf-1))/(2*fftHalf -1);
ham = .54 - .46*cos(ham*2*pi);
% plot(ham)

tic
% if(~exist('data'))
%fid = fopen('c:\sdr\data\fiveSecondSound.dat')
fid = fopen('c:\radio\c\bin\fiveSecondSound.dat')

[data,count] = fread(fid,200000,'short','ieee-le');
fclose(fid);

plot(data);
x = data - round(mean(data));
x = x / max(abs(x))/4;
sound(x,44100)
shg
 return
x3 = [];
tic
x = zeros(2*fftHalf,cols-1);
disp(sprintf('x allocate time %f\n',toc))
    
stationAM = 780*1000;
stationAM = 630*1000;
stationAM = 1500*1000;
stationAM = 1210*1000;
fs = 4e6;
df1 = fs/fftHalf/2;     % frequency increment of the first fft
fbin = round(stationAM/df1 + 1); % station index into the first fft
fc2= (fbin-1)*df1; % center frequency of the indexed station

fs2 = fs/fftHalf;   % second fft sample rate
Nfft2 = cols;     % length of the second fft
df2 = fs2/Nfft2;    % second fft frequency increment
fbin2 = mod(round((fc2-stationAM)/df2+1),Nfft2); % second fft
if(fbin2 == 0) fbin2 = Nfft2; end
BW = 5e3;
vr = round(BW/df2);
range2 = (-vr:vr ) + fbin2;
range2 = mod(range2,Nfft2);
range2(range2==0) = Nfft2;

for n = 1:500
	[data,count] = fread(fid,[ fftHalf cols ],'ushort','ieee-le');
% 	disp(sprintf('read file time %f\n',toc))
	if count <=0
        break
    end
	% 	fclose(fid);
	% end
	
 	data = data - mean(mean(data));
    x(1:fftHalf,:) = data(:,1:(cols-1)) ;
% 	disp(sprintf('reorder time %f\n',toc))
    x((fftHalf+1):2*fftHalf,:) =  data(:,2:cols);
% 	disp(sprintf('reorder time %f\n',toc))
    x = x.*repmat(ham',1,cols-1);
% 	disp(sprintf('ham time %f\n',toc))
% 	data = [data(:,1:(end-1)) ; data(:,2:end)].*repmat(ham',1,cols-1);
	X = fft(x);
% 	disp(sprintf('fft time %f\n',toc))
		
	X_dB = 20*log10(abs(X));
	X_dB(X_dB < 70) = 70;
     df = fs/fftHalf/2;
	f =0:df:(fs/2-df);
	dt = fftHalf/fs;
	T = fftHalf/fs;
	t = 0:dt:(T-2*dt);
	figure
	imagesc(t,f,X_dB(1:fftHalf,:)),shg
	
	x2 = X(fbin,:);
	
	% clear X X_dB data 
	X2 = fft(x2,Nfft2);
	X2_dB = 20*log10(abs(X2));
    
	len2 = length(X2);
	df = fs2/len2;
	f2 =0:df:(fs2-df);
  	figure
  	plot(X2_dB),shg
		
    [m,mi] = max(X2_dB(range2));
    mi = range2(mi)
    mm = X2(mi);
    
	range3 = (-vr:(vr+1) ) + mi;
	range3 = mod(range3,Nfft2);
	range3(range3==0) = Nfft2;
	X3= X2(range3);
	f3=(0:(length(X3)-1))*df1;
	X3_dB = 20*log10(abs(X3));
	
%  	figure
%  	plot(X3_dB),shg
	
	[m,mi] = max(abs(X3));
    ix = mod([-1 1] +mi,length(X3));
	[m2,mi2] = max(abs(X3(ix)));
	mi2 = ix(mi2);
	m = X3(mi) + X3(mi2);
	m = m/abs(m);
	X3 = X3*conj(m);
	
% 	figure
% 	plot(f3,[real(X3)' imag(X3)' abs(X3)']),shg
	
	N = length(X3);
	X4 = [X3(mi:N) X3(1:(mi-1)) ];
	
	% figure
	% plot(f3,20*log10(abs(X3)))
	
	Nlow = round(70/df2);
    X5 = X4;
	X5(1:Nlow) = 0;
	X5((end-Nlow+1):end) = 0;
	
	% figure
	% plot(f3,20*log10(abs(X3))),shg
	
	y5 =  ifft(X5);
	x3 = [x3 y5];
% sound(real(y5)/max(real(y5)),2*BW)
end
%  	figure
%  	plot(f3,[real(X4)' imag(X4)' abs(X4)']),shg
fclose(fid);
sound(real(x3)/max(real(x3)),2*BW)

