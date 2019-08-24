function w = chebyshev(M,SLL)

% function w = chebyshev(M,SLL)
% M - number of point
% SLL - positive dB

if nargin == 0
 SLL = 40; % sidelobe level in dB
 M = 25; % window length
end

N = M -1;
% If the desired Chebyshev window sequence length is M, 
% then define integer N = M-1.
% 
% Define the window's sidelobe-level control parameter as g.
% The window's sidelobe levels, relative to the mainlobe peak, 
% will be -20g dB. 
% 

g = SLL/20;
%     Compute parameter a as
%     a = cosh[cosh-1(10g)/N].
a = cosh(acosh(10^g)/N);
% 
%     Compute the N-length sequence A(m) using
%     A(m) = |a cos(pi m/N)|
m = (0:(N-1));
A = a*cos(pi*m/N);
% 
% where the index m is 0 ? m ? (N-1).
% For each m, evaluate the Nth-degree Chebyshev polynomial whose argument 
% is A(m) to generate a frequency-domain sequence W(m). 
% There are many ways to evaluate Chebyshev polynomials. Due to its simplicity 
% of notation, I suggest the following:
% W(m) = (-1)m cosh{N cosh-1[A(m)]}, when |A(m)| > 1,
W = (-1).^m.*cosh(N*acosh(A));
% 
% or
% W(m) = (-1)m cos{N cos-1[A(m)]}, when |A(m)| ? 1.
L = A <=1;
W(L) = (-1).^m(L).*cos(N*acos(A(L)));
% 
% The W(m) sequence is real-only, although our software's computational 
% numerical errors may produce a complex-valued W(m) with very small 
% imaginary parts. Those imaginary parts, if they exist, should be ignored. 
% The above (-1)m factors are necessary because the frequency-domain index m 
% is never less than zero.
% Compute a preliminary time-domain window sequence, w(m), using
% w(m) = real part of the N-point inverse DFT of W(m).
% Replace w(0), the first w(m) time sample, with w(0)/2.
% Append that new w(0) sample value to the end of the N-point w(m) sequence, 
% w(M-1) = w(0), creating the desired M-length window sequence w(k) 
% where time index k is 0 ? k ? (M-1).
% Normalize the amplitude of w(k), to obtain a unity peak amplitude, 
% by dividing each sample of w(k) from Step 8 by the maximum sample value in w(k).
% 
w = real(ifft(W));
w = [w(1)/2 w(2:end) w(1)/2];
w = w'/max(w);
if nargin == 0
    R = 20*log10(abs(fft(w,length(w)*8)));
    plot(R),shg, grid
    axis tight
    ax = axis;
    ax(3) = max(R) -SLL - 20;
    axis(ax)
end