function dpdt = lotkaODE(t,p)
    %Lotka - Volterra predator-prey model
    alpha = 0.02;
    beta = 0.01;
    dpdt = [p(1) .* (1 - beta*p(2));
            p(2) .* (-1 + alpha*p(1))];
end