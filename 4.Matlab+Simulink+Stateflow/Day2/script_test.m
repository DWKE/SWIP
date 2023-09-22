% Add up all the vector elements
y = sum(x);     % Use the sum function

% 주석 처리: ctrl + r
% 주석 해제: ctrl + t

a = magic(3);
% sum(a)
% diag(a)
% sum(diag(a))
sum(diag(fliplr(a)))