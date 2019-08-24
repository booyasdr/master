close all
clear
fs = 4e6;
fs = 10e6;
% fs = 16e6;

file = 'c:\gnuradio\bench_test.dat';
a = dir(file);

fid = fopen(file);

sndall = [];
tic
chunk = 16777216/2;
N = a.bytes/chunk/2;

stationARRL = [ 1802.5 3581.5]*1e3;
stationS = stationARRL(2);
stationS = stationARRL;

BWrf=1e3;
BWsnd=8e3;

for n = 1:N/2
    if feof(fid) break, end
	data = fread(fid,chunk,'ushort','ieee-le');

	e = round(length(data));
 	y = (0:(e-1))*fs/e;
	
	f = fft(data(1:e));
	F = 20*log10(abs(f));
	df = fs/length(data);
    stationSnd = [];
    for m = 1:length(stationS)
        station = stationS(m);
		stationB = round((station - BWrf )/df);
		stationT = round((station + BWrf )/df);
		[m,mi] = max(abs(F(stationB:stationT)))
		stationN = stationB + mi -1;
		stationW = round(BWrf/df);
		amRange = (-stationW:stationW) + stationN;
		
	% 	stationF = F(amRange);
		
		inband = f(stationB:stationT);
% 		inband = f(amRange);
% 		[m,mi] = max(abs(inband));
% 		[m2,mi2] = max(abs(inband([-1 1] +mi)));
% 		mi2 = mi+ (mi2-1.5)*2;
% 		m = inband(mi) + inband(mi2);
% 		m = m/abs(m);
% 		inband = inband*conj(m);,
		
		M = 2*chunk/fs*BWsnd -101 - 2*length(inband)
        
		demod = [zeros(51,1)
            inband(end:-1:1)
            zeros(M,1)
            conj((inband))
            zeros(50,1)];
        whos demod
        M 
        chunk/fs*BWsnd
				
		snd = ifft(demod)';
        stationSnd = [ stationSnd; snd];
        plot(real(snd))
		keyboard
	end
	
	sndall = [ sndall stationSnd];
	toc
end

for n = 1:size(sndall,1)
	sound(real(sndall(n,:))/max(real(sndall(n,:))),2*BWsnd)
	pause(size(sndall,2)/2/BWsnd*1.1)
	n
end
return
figure
plot(y(1:e/2),F(1:e/2)),shg

L = (y>3.5812e6) & (y<3.5818e6);
d = f(L);
figure
plot(y(L),20*log10(abs(d))),shg
sp = [ zeros(51,1); d; zeros(chunk/fs*2*BWrf-101,1); flipud(conj(d));zeros(50,1)]
figure
plot(20*log10(abs(sp))),shg

isp = real(ifft(sp));
plot(isp),shg
sound(isp/max(isp),2*BWrf*2),shg

return

save sndall sndall
fclose(fid);

figure
plot(y(1:e/2),F(1:e/2)),shg

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
