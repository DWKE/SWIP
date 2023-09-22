clear; clc;

x = 1:100000;

tic
ylength = (length(x) - mod(length(x),5)) / 5;
y(1:ylength) = 0;
for n = 5:5:length(x)
    y(n/5) = sum(x(1:n));
end
time_spend_1 = toc

tic
xsums = cumsum(x);
y = xsums(5:5:length(x));
time_spend_2 = toc