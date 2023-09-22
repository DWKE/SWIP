t0 = 0;
tfinal = 15;
p0 = [50; 50];

[t,p] = ode45(@lotkaODE,[t0 tfinal],p0);    % ode45: solver

figure();
plot(t,p);
title('Predator/Prey Populations Over Time');
xlabel('t');
ylabel('Population');
legend('Prey','Predators');

figure(2);
plot(p(:,1),p(:,2));
title('Phase Plot of Predator/Prey Populations');
xlabel('Prey')
ylabel('Predetors')