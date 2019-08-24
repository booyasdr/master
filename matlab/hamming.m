function h = hamming(M)

N = M-1;

h = .54 - .46*cos((0:N)/N*2*pi);

return