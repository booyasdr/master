% use ffts to modulate a ssb signal
% Fs - baseband sampling rate
% Frf - rf sampling rate

clear
close all

load handel
fs = 32e6;
fbb = 44100;

% find fs to fbb ratio in lowest terms
factorFs = factor(fs);
factorFbb = factor(fbb);

I = intersect(factorFs,factorFbb)
while ~isempty(I)
    factorFs(min(find(factorFs==I(1)))) = [];
    factorFbb(min(find(factorFbb==I(1)))) = [];
    I = intersect(factorFs,factorFbb);
end
lowTFs = prod(factorFs)
lowTFbb = prod(factorFbb)

ddf = 10;               % desired frequency resolution

mul = round(fs/lowTFs/ddf)
Nrf = mul*lowTFs
Nbb = mul*lowTFbb
df = fs/Nrf             % actual df

fckHz = 7251;

Tbb = 1/fbb;
dt = Nrf/fs;
rft = sin(((1:Nrf)-1)/Nrf*2*pi);
rfout = zeros(1,dt*fs);
mt = 1 + y;
%  for n = 1:dt*fbb
% tic
%  for n = 1:11025
%     bottom = round((n-1)*Tbb*fs)+1;
%     top = round(n*Tbb*fs);
%     rng = fckHz*(bottom:top);
%     idx = mod(rng,Nrf)+1;
%     rf = rft(idx);
%     rfout(bottom:top) = rf*mt(n);
%  end
% toc
% Nrf = 3.2e6;

rfall = rft(mod((1:Nrf)*fckHz*1000/df,Nrf)+1);
top = round((1:11025)*Tbb*fs);
bottom = [ 1 top(1:end-1)+1];
dif = unique(top - bottom);
len = dif + 1;
tic
mt = 1 + y;
rampUp1 = ((1:len(1))-1)/len(1);
rampDown1 = 1 - rampUp1;
rampUp2 = ((1:len(2))-1)/len(2);
rampDown2 = 1 - rampUp2;
dif1 = dif(1);
dif2 = dif(2);
for n = 1:4410
    bottom = round((n-1)*Tbb*fs)+1;
    top = round(n*Tbb*fs);
    df = top - bottom;
    rf = rfall(bottom:top);
    if df == dif1
        rfout(bottom:top) = rf.*(rampUp1*mt(n+1) + rampDown1*mt(n));
    elseif df == dif2
        rfout(bottom:top) = rf.*(rampUp2*mt(n+1) + rampDown2*mt(n));
    end
 end
toc

plot(rfout)
figure
R = 20*(abs(fft(rfout)));
    plot(R(1:end/2)),shg
return
format short

halfFft = 256;
fc = 2e6;
Tbb = 2*halfFft/Fs;
Nrf = Rfr*Tbb;
%sound(y,Fs)
h = hamming(2*halfFft);
tic
y = zeros(1,1e6);
for n = 1:1e6
    x = cos(n);
end
toc
tic
y = zeros(1,1e6);
for n = 1:1e6
    x = y(n);
end
toc
return

M = floor(length(y)/halfFft) -2;
Yin = zeros(M,2*halfFft);
yout = zeros(size(y));

for m = 1:M
    yin = y((1+(m-1)*halfFft):(m+1)*halfFft)'.*h;
%     Yin(m,:) = fft(yin);
    yout(((halfFft/2+1):3*halfFft/2)+(m-1)*halfFft) = ...
        yin(((halfFft/2+1):3*halfFft/2));
end

sound(yout/2)
imagesc(20*log10(abs(Yin)))

return

plot(20*(abs(Yin))),shg
