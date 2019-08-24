N =64;
M = 32*N;
hu = ones(N,1);
hham = hamming(N)';
hblack = blackman(N);

Ru = 20*log10(abs(fft(hu,M)));
Rham = 20*log10(abs(fft(hham,M)));
Rblack = 20*log10(abs(fft(hblack,M)));
Ru = Ru -max(Ru);
Rham = Rham -max(Rham);
Rblack = Rblack -max(Rblack);
fa = (0:(M-1))*N/M;
plotFactor = 10;
shift = 2;

f   = fa(1:end/plotFactor);
R   =[ Ru Rham Rblack];
Rd  = R(1:end/plotFactor,:);
R2  =[ R((end-shift*32+1):end,:); R(1:(end-shift*32),:)];
R2d = R2(1:end/plotFactor,:);
U   = [Rd(:,1) R2d(:,1) ]; 
Ham = [Rd(:,2) R2d(:,2) ]; 
Blk = [Rd(:,3) R2d(:,3) ]; 

plot(f,U,'r',f,Ham,'b',f,Blk,'g',[1 1]/2,[0 -100])
grid,shg, axis tight
ax = axis;
ax(3) = -60;
axis(ax)
title(sprintf('Overlap = %.1f%%',(1-1/shift)*100))