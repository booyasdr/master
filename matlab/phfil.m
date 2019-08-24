clear phe

phe0 = rem(stationAM/fs*fftHalf,1);
% dph = diff(unwrap(angle(phs)));

dphe(1) = exp(-j*phe0)
phe(1) = phs(1);
for n = 1:length(phs)-1
    dphe(n+ 1) = dphe(n) + .01*(phs(n+1)/phs(n) - dphe(n));
    phe(n+ 1) = dphe(n+1)*phe(n);
    phe(n+ 1) = phe(n+1) +.01*(phs(n+1)-phe(n+1));
    
end
% plot([-angle(phs(2:end)'./phs(1:end-1)') angle(phe(1:end-1))']),shg
plot(diff(unwrap([ angle(phs') angle(phe') ]))),shg
