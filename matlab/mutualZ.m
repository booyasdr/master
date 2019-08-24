dD = .05;
D = (dD/5:dD:5);
H = .001;
dH = H/20;
h = (dH/2:dH:H)';
r0 = sqrt(repmat(D,length(h),1).^2 + repmat(h,1,length(D)).^2 ) ;
r1 = sqrt(repmat(D,length(h),1).^2 + (H-repmat(h,1,length(D))).^2 ) ;
r2 = sqrt(repmat(D,length(h),1).^2 + (H+repmat(h,1,length(D))).^2 ) ;

Z = -j*exp(j*D'*2*pi)./D';
Z1 = exp(-j*r1*2*pi)./r1;
Z2 = exp(-j*r2*2*pi)./r2;
Z0 = exp(-j*r0*2*pi)./r0;
Za = -j*( -Z1 -Z2 +2*cos(H*2*pi)*Z0).'*sin(2*pi*(H-h))*dH
Zar =  (-Z1 -Z2 +2*cos(H*2*pi)*Z0).'*sin(2*pi*(H-h))*dH
% Za = sum(-j*( -Z1 -Z2 +2*cos(H*2*pi)*Z0))';
No = max(real(Z));
Noa = max(real(Za))*1.5;

plot(D,[real(Z)/No imag(Z)/No real(Za)/Noa imag(Za)/Noa]);
plot(D,[real(Z)/No  real(Za)/Noa ]);
shg
grid