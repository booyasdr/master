close all
clear
fs = 4e6;
fs = 10e6;
% fs = 16e6;

dirname = 'c:\gnuradio';
dataname = 'bench_test.dat'; 
datafilespec = [dirname '\' dataname];
a = dir(datafilespec);
s = a.date;
s = strrep(s,' ','')
s = strrep(s,':','') 
N = 8;
fftfilename = ['fft' s '_' num2str(N) '.mat']
fftExist = exist([ dirname '\' fftfilename])
if ~fftExist
    fid = fopen(datafilespec);
end

tic   
chunk = 16777216/2;
N = a.bytes/chunk/2;
N = 8;
stationARRL = [ 1802.5 3581.5]*1e3;
stationS = stationARRL;

BWrf=1e3;
BWsnd=5e3;

sndall = zeros(length(stationARRL),chunk/fs*BWsnd*N);
stationSnd = zeros(length(stationARRL),2*chunk/fs*BWsnd);

for n = 1:N

    fftfilename = ['fft' s '_' num2str(n) '.mat']
    fftfilespec = [dirname '\' fftfilename];
    if fftExist
	    load(fftfilespec)
% 	    clear('e','y')
      plot(y(1:e/2),F(1:e/2),[1.8025 3.5815; 1.8025 3.5815]*1e6,[60 60;140 140]),shg
      keyboard
	else
        if feof(fid) break, end
		data = fread(fid,chunk,'ushort','ieee-le');
	
    	e = round(length(data));
     	y = (0:(e-1))*fs/e;
		
		f = fft(data(1:e));
    	F = 20*log10(abs(f));
	    save([ dirname '\' fftfilename],'f','e','y','F')
	end
    toc
%      plot(y(1:e/2),F(1:e/2),[1.8025 3.5815; 1.8025 3.5815]*1e6,[60 60;140 140]),shg,
%      return
    df = fs/length(f);
%     stationSnd = [];
    for m = 1:1
        station = stationS(m);
		stationB = round((station - BWrf )/df);
		stationT = round((station + BWrf )/df);
		[ma,mi] = max(abs(F(stationB:stationT)));
		stationN = stationB + mi -1;
		stationW = round(BWrf/df);
		amRange = (-stationW:stationW) + stationN;
		
	% 	stationF = F(amRange);
		
% 		inband = f(stationB:stationT);
 		inband = f(amRange);
% 		[m,mi] = max(abs(inband));
% 		[m2,mi2] = max(abs(inband([-1 1] +mi)));
% 		mi2 = mi+ (mi2-1.5)*2;
% 		m = inband(mi) + inband(mi2);
% 		m = m/abs(m);
% 		inband = inband*conj(m);,
		nZero = round(100/df);
		M = 2*chunk/fs*BWsnd -2*nZero-1 - 2*length(inband);
        plot(20*log10(abs(ifft(inband))))
        
        
		demod = [zeros(nZero+1,1)
            inband(end:-1:1)
            zeros(M,1)
            conj((inband))
            zeros(nZero,1)];
%        chunk/fs*BWsnd
				
		snd = real(ifft(demod)');
%         stationSnd = [ stationSnd; snd];
        stationSnd(m,(1:length(snd))) = snd;
		
	end
	
% 	sndall = [ sndall stationSnd];
	sndall(:,(1:size(snd,2)) +(n-1)*size(snd,2)) = stationSnd;
	toc
end

for n = 1:size(sndall,1)
	n
	sound(real(sndall(n,:))/max(real(sndall(n,:))),2*BWsnd)
	pause(size(sndall,2)/2/BWsnd*1.1)
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
