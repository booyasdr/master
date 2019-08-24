clear
close all

k = pi;

x = 1:10;
y = 1:10;

x = repmat(x',1,length(y));
y = repmat(y,length(x),1);
X = x(:);
Y = y(:);
X = repmat(X,1,length(Y));
Y = repmat(Y',length(Y),1);
d = sqrt((X-X').^2 + (Y-Y').^2);

mut = sin(k*d)./d/k;

mut(d==0)= 1;

length(X)/sum(sum(mut))