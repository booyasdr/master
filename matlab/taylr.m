function [wts,nbar,coef]=taylr(ne, sldb);
%function [wts,nbar,coef]=taylr(ne, sldb);
%
% Taylor weightings
%
%	Inputs:	ne   = number of elements in antenna
%			sldB = sidelobe level in dB

%
%	Outputs: wts = Taylor weights
%			 nar = nbar, for Taylor weighting
%            coef(nbar-1) = coefficients
%
%   Author:     A. Jahns
%   Date:       July 3, 2007

if nargin == 0
 SLL = 40; % sidelobe level in dB
 M = 25; % window length
 sldb = 40; % sidelobe level in dB
 ne = 25; % window length
end

if abs(sldb)<14
   wts = ones(ne,1);
   return
end

r=10^(abs(sldb)/20);
a=acosh(r)/pi;
nbar=max(fix(2*a^2+1),2);
n=1:nbar-1;
sn = (a^2+(nbar-0.5)^2)/nbar^2 * n.^2;

yi = a^2+(n-0.5).^2;
y=1./yi;
z = 1-sn'*y;
p = prod(z');

coef=ones(nbar-1,1);
fd=1;
for i=1:nbar-1
    fd=fd*(nbar-i)/(nbar-1+i);
    coef(i)=p(i)*fd;
end

k=[1:ne]';

arg=pi/ne*(2*k-ne-1);
w=1+2*cos(arg*n)*coef;
pk = 1 +2*sum(coef);
wts = w/pk;

if nargin == 0
    R = 20*log10(abs(fft(w,length(w)*8)));
    plot(R),shg, grid
    axis tight
    ax = axis;
    ax(3) = max(R) -SLL - 20;
    axis(ax)
end