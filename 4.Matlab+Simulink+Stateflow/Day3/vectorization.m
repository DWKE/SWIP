clear; clc;

M = rand(5, 1000);
W = rand(5, 1000);
L = rand(5, 1000);
H = rand(5, 1000);

tic                     % tic: 연산 시간 카운트 시작
[rows, cols] = size(M);
for I = 1:rows
    for J = 1:cols
        Density(I,J) = M(I,J)/(L(I,J)*W(I,J)*H(I,J));
    end
end
time_spend_1 = toc      % toc: 연산 시간 카운트 종료

tic
Density = M ./ (L .* W .* H);
time_spend_2 = toc