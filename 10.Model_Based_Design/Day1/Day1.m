%% MBD 1일차

clear all; clc;

M = 1;
K = 10;
D = 3;

% MATLAB에서 전달함수 표현하기
% G_sys = tf([1],[M D K])
% figure(1)
%step(G_sys)

% MATLAB에서 상태방정식 표현하기
A_ss = [0 1; -K/M -D/M];
B_ss = [0; 1/M];
C_ss = [1 0];
D_ss = [0];
% SS_sys = ss(A_ss,B_ss,C_ss,D_ss)
% figure(2)
% step(SS_sys)

out = sim("Day1_model.slx")

figure(1)
plot(out.response_equ(:,1), out.response_equ(:,2))
hold on
plot(out.response_tf(:,1), out.response_tf(:,2))
plot(out.response_ss(:,1), out.response_ss(:,2))
hold off
xlabel('time(sec)');
ylabel('y(m)');
title('System response')
legend('From equation of motion', 'From transfer function', 'From state space')
grid on