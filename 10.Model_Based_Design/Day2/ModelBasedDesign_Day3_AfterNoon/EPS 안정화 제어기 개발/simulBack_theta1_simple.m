
%% MDPS simulation, theta1 input

 % system parameter
J1=0.044;
C1=0.25;
J2=0.11;
C2=1.35;
K=142.24;

J1=0.033;
C1=0.23;
J2=0.085;
C2=2.4;
K=143.24;

% N=20.5;
% rp=0.008;
% rp=1;
delta = 0.1;
noise_var = 0;
% 차속 정보
Carspeed=100;

% tire 조건
tireangle_max=60;   % 정차 상태 특성
SAT_coefficient=0.00010011*Carspeed^2-0.00024672*Carspeed+0.04924;
SAT_coefficient=20/180*pi; 
alpha = SAT_coefficient*180/pi;
tire_stiffness=0.51;

% friction 조건 설정
friction_level=0;
		
% steering angle input
amp_input_theta1_deg=60;    % deg
amp_input_theta1=amp_input_theta1_deg*pi/180;    % rad
freq_input_theta1=10;  % rad/s
offset_input_theta1=0;  % Nm
opt = '-.';

% Controller
leadpole=100;
leadzero=10;
lagpole=50;
lagzero=15;

assist=9.3;
deadband=0; %Nm

% motor mode on/off
motor_onoff=1; % 1: on, 0: off
motordelay_onoff=0;
motorcutoff=100*2*3.14;
if motordelay_onoff == 1
    Gm = tf([motorcutoff],[1 motorcutoff]);
else
    Gm = 1;
end

Assistgain=assist;
% calculate H
lead=tf([1/leadzero 1],[1/leadpole 1]);
lag=tf([1/lagzero 1] ,[1/lagpole 1]);
H=(Assistgain)*lead*lag;       % original controller

% system transfer functions
% theta_1=(P1+P2*H)/(1+Peq*H)*tau_h - P3/(1+Peq*H)*(N*dm+dr)
% theta_2=(P4+P5*H)/(1+Peq*H)*tau_h - P6/(1+Peq*H)*(N*dm+dr)
% tau_measure=(P7)/(1+Peq*H)*tau_h - P8/(1+Peq*H)*(N*dm+dr)

dom=tf([J1*J2 J1*C2+J2*C1 C1*C2+J1*K+J2*K K*C1+K*C2 0 ],[1]);
Peq=tf([J1*K K*C1 0],[1])/dom;
P1=tf([J2 C2 K],[1])/dom;
P2=tf([K],[1])/dom;
P3=tf([K],[1])/dom;
P4=tf([K],[1])/dom;
P5=tf([K],[1])/dom;
P6=tf([J1 C1 K],[1])/dom;
P7=tf([J2*K C2*K 0],[1])/dom;
P8=tf([J1*K C1*K 0],[1])/dom;
% Peq2=tf([K*J1 K*C1 0],[J1*J2 J1*C2+J2*C1 K*J2+(K+Kr)*J1+C1*C2 K*C2+K*C1+Kr*C1 K*Kr]);

% linear system stability criterion (Hysteresis controller)
figure(1)
margin(H*Peq)
grid on



% legend('K_v = 1','K_v = 50')

% Controller bode plot of original and hysteresis controller
% figure(2)
% bode(lead*lag*lead2)
% grid on

% Nonlinear system stability criterion (Hysteresis controller)
% hmax=Assistgain;
% hmin=0;
% Tm2Tmeasure=tf([K*J1 K*C1],[J1*J2 J1*C2+J2*C1 K*(J1+J2)+C1*C2 K*(C1+C2)]);
% Tzw=(Tm2Tmeasure*lead*lag*lead2*(hmax-hmin)/2*Gm)/(1+Tm2Tmeasure*lead*lag*lead2*((hmax+hmin)/2)*Gm);
% figure(3)
% bode(Tzw)
% grid on
% h0=title('Tzw');
% set(h0,'FontSize',14,'FontName','Times New Roman');
% [Tzw_max Tzw_max_freq]=norm(Tzw,inf)

% figure(31)
% bode(Tm2Tmeasure*lead*lag*lead2*(hmax-hmin)/2*Gm)
% grid on

% Do simulation
sim('EPS_theta1input_simpletorquemap_simpletiremodel')
done=1



figure(4) % hysteresis curve
plot(theta1(2000:(2000+round(1000/freq_input_theta1*2*pi)),2)*180/pi,tau_measure(2000:(2000+round(1000/freq_input_theta1*2*pi)),2),opt)
% title('hysteresis curve, set 3, 90km/h, steering input=0.3Hz')
xlabel('Steering angle(degree)')
ylabel('Steering torque(Nm)')
grid on
hold on
legend('1 rad/s','5 rad/s','10 rad/s')
% legend('M=6.51','M=9.3','M=12.09')
ylim([-3 3])

% figure(5)
% plot(tau_measure(1501:end,1)-1.5,tau_measure(1501:end,2),'linewidth',1)
% % title('\tau_s','Fontsize',13)
% xlabel('Time (sec)','Fontsize',12)
% ylabel('\tau_s (Nm)','Fontsize',12)
% grid on

Gsys = K*tf([J2 C2 alpha],[1])/(tf([J2 C2 K],[1]) + K*H);

figure(6)
bode(Gsys)
grid on
hold on






