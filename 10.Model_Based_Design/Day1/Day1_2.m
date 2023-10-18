%% 전기시스템의 수학적 모델 (시뮬링크 실습 #4)

clear all; clc;

R = 30;
L = 2;
C = 0.1;

freq = 1; % Hz

out = sim("Day1_model2.slx")

figure(1)
plot(out.voltage(:,1), out.voltage(:,2))
hold on
plot(out.voltage(:,1), out.voltage(:,3))
plot(out.voltage(:,1), out.voltage(:,4))
hold off
xlabel('time(sec)');
ylabel('y(m)');
title('System response')
legend('e_c(t)', 'e_R(t)', 'e_L(t)')
grid on