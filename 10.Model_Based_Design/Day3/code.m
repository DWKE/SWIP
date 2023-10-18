%% 학습된 강화학습 에이전트 실행시키기
clc; clear

Ts = 1.0;
Tf = 200;

load("WaterTankDDPG.mat","agent")


%% Auto code generation Step 1
generatePolicyFunction(agent)

cfg = coder.config("lib");
cfg.VerificationMode = "SIL";
cfg.TargetLang = "C";
cfg.GenerateExampleMain = 'GenerateCodeAndCompile';

cfg.DeepLearningConfig = coder.DeepLearningConfig(TargetLibrary='none');

argstr = '{ones(3,1)}';
%% Auto code generation Step 2
codegen('-config','cfg','evaluatePolicy','-args',argstr,'-report');

%% SIL
generatePolicyBlock(agent);
