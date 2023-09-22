clear;clc;

tic
x = 0;
for k = 2:1000000
    x(k) = x(k-1) + 5;
end
time_spend_1 = toc

tic
x = zeros(1, 1000000);
for k = 2:1000000
    x(k) = x(k-1) + 5;
end
time_spend_2 = toc