x = [1:1:100];
y = 4 * x;
z = sin(x);

test_cycle = 'example';

for i = x
    eval(['disp("Simulation_num_' num2str(i) '");'])
    % disp('Simulation_num_(i)');
    eval(['eval_example.result_' num2str(i) '.ramp = ' num2str(y(i)) ';'])
    % eval_example.result_(i).ramp = y(i);
    eval(['eval_example.result_' num2str(i) '.sin = ' num2str(z(i)) ';'])
    % eval_example.result_(i).sin = z(i);

    data = i:i+10;
    eval(['save("result_' num2str(i) '.mat", "data");'])
    % save('result_(i).mat', 'data');

end
eval(['save("result_' test_cycle '.mat", "eval_example");'])
% save('result_example.mat', 'eval_example');