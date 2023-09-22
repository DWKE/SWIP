target_folder = 'Result';

eval(['mkdir("' target_folder '");'])
% mkdir('Result');

zip('Result_backup',{'*.mat'});

x = 1:100;
for i = x
    eval(['movefile("result_' num2str(i) ...
        '.mat", "C:\Users\user\Desktop\lke\4. Matlab + Simulink + Stateflow\Day3\' target_folder '");'])
    % movefile('result_(i).mat', 'path');
end