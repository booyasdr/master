clear
close all

fs = 4e6;
fs = 10e6;
fs = 64e6;

dirname = 'c:\jahns';
dirname = 'c:\sdr\data';
dataname = 'table.dat';
dataname = 'rfdata.dat';
filename = [dirname '\' dataname];
a = dir([dirname '\' dataname]);
s = a.date;
s = strrep(s,' ','')
s = strrep(s,':','')
N = 1;
fftfilename = ['fft' s '_' num2str(N) '.mat']
fftExist = exist([ dirname '\' fftfilename])
fftExist = false;
if ~fftExist
    fid = fopen(filename);
end

sndall = [];
tic
chunk = 16777216/2;
N = ceil(a.bytes/chunk/2);
% N = 1;
station = [ 1210e3 610e3 800e3 1060e3 770e3 ];
station = [ 1210e3 ];
stationS = [ 950e3 1210e3 ];
stationMD = [ 780e3 980e3 1050e3 1260e3 ];
stationNJ = [ 610 640 800 900 950 990 1060 1210 1680]*1e3;

stationS = stationNJ;
stationS = stationMD;
% for n = 1:N
for n = 1:1
    if feof(fid) break, end

    fftfilename = ['fft' s '_' num2str(n) '.mat']
    if fftExist
	    load([ dirname '\' fftfilename])
	else
        if feof(fid) break, end
		data = fread(fid,chunk,'ushort','ieee-le');
%         plot(data(:)),shg, axis tight
%         fclose(fid)
%         return
	
    	e = round(length(data));
     	y = (0:(e-1))*fs/e;
		
		f = fft(data(1:e));
    	F = 20*log10(abs(f));
	    save([ dirname '\' fftfilename],'f','e','y','F')
	end
	df = fs/length(data);
	BW=6e3;
    stationSnd = [];
    for m = 1:length(stationS)
        station = stationS(m);
		stationB = round((station - BW )/df);
		stationT = round((station + BW )/df);
		[m,mi] = max(abs(F(stationB:stationT)))
		stationN = stationB + mi -1;
		stationW = round(BW/df);
		amRange = (-stationW:stationW) + stationN;
		
	% 	stationF = F(amRange);
		
		inband = f(amRange);
		[m,mi] = max(abs(inband));
		[m2,mi2] = max(abs(inband([-1 1] +mi)));
		mi2 = mi+ (mi2-1.5)*2;
		m = inband(mi) + inband(mi2);
		m = m/abs(m);
		inband = inband*conj(m);,
		
		M = length(inband);
		demod = [inband((floor(M/2)+1):M).' inband(1:(floor(M/2))).' ];
		
		Nlow = round(70/df);
		demod(1:Nlow) = 0;
		demod((end-Nlow+1):end) = 0;
		
		snd = ifft(demod);
        stationSnd = [ stationSnd; snd];
		
	end
	sndall = [ sndall stationSnd];
	toc
end
save sndall sndall

for n = 1:size(sndall,1)
	stationS(n)/1000
	sound(real(sndall(n,:))/max(real(sndall(n,:))),2*BW)
	pause(size(sndall,2)/2/BW*1.1)
end
fclose(fid);

figure
plot(y(1:e/2),F(1:e/2)),shg
return
figure
plot((0:(length(inband)-1))*df,[real(inband) imag(inband)])
xlabel('Frequency (Hz)')
ylabel('Amplitude')
title('In Band Frequency Samples')
grid
axis tight

figure
plot((0:(length(demod)-1))*df,20*log10(abs(demod)))
xlabel('Frequency (Hz)')
ylabel('Magnitude (dB)')
title('In Band Frequency with Frequency Shift')
grid
axis tight

figure
plot((0:(length(demod)-1))*df,20*log10(abs(demod)))
plot((0:(length(demod)-1))*df,20*log10(abs(demod)))
xlabel('Frequency (Hz)')
ylabel('Magnitude (dB)')
title('In Band Frequency with Frequency Shift and DC Filter')
grid
axis tight

figure
plot([ real(snd)' imag(snd)'])
xlabel('Sound Samples')
ylabel('Signal')
title('In Band Frequency with Frequency Shift and DC Filter')
grid
axis tight
