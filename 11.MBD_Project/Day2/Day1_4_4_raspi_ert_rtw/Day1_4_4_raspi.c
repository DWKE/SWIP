/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Day1_4_4_raspi.c
 *
 * Code generated for Simulink model 'Day1_4_4_raspi'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Oct 20 13:15:55 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Day1_4_4_raspi.h"
#include "rtwtypes.h"
#include "Day1_4_4_raspi_private.h"

/* Block signals (default storage) */
B_Day1_4_4_raspi_T Day1_4_4_raspi_B;

/* Block states (default storage) */
DW_Day1_4_4_raspi_T Day1_4_4_raspi_DW;

/* Real-time model */
static RT_MODEL_Day1_4_4_raspi_T Day1_4_4_raspi_M_;
RT_MODEL_Day1_4_4_raspi_T *const Day1_4_4_raspi_M = &Day1_4_4_raspi_M_;

/* Model step function */
void Day1_4_4_raspi_step(void)
{
  real_T rtb_Add;
  real_T rtb_Add2;
  real_T rtb_DiscreteTimeIntegrator;
  real_T rtb_Switch;
  real_T rtb_TSamp_o;
  real_T u0;
  int32_T rtb_M1Encoder_0;

  /* Constant: '<Root>/M1 Speed Control (deg//s)' */
  Day1_4_4_raspi_B.M1SpeedControldegs =
    Day1_4_4_raspi_P.M1SpeedControldegs_Value;

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   */
  if (Day1_4_4_raspi_B.M1SpeedControldegs >= Day1_4_4_raspi_P.Switch_Threshold)
  {
    rtb_Switch = Day1_4_4_raspi_P.Constant_Value;
  } else {
    rtb_Switch = Day1_4_4_raspi_P.Constant1_Value;
  }

  /* End of Switch: '<S1>/Switch' */

  /* MATLABSystem: '<S6>/Digital Write' incorporates:
   *  Constant: '<S1>/Motor Start'
   *  Logic: '<S4>/AND'
   */
  EXT_GPIO_write(15U, (uint8_T)((Day1_4_4_raspi_P.MotorStart_Value != 0.0) &&
    (rtb_Switch != 0.0)));

  /* Constant: '<Root>/M2 Speed Control (deg//s)' */
  Day1_4_4_raspi_B.M2SpeedControldegs =
    Day1_4_4_raspi_P.M2SpeedControldegs_Value;

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   */
  if (Day1_4_4_raspi_B.M2SpeedControldegs >= Day1_4_4_raspi_P.Switch1_Threshold)
  {
    rtb_DiscreteTimeIntegrator = Day1_4_4_raspi_P.Constant2_Value;
  } else {
    rtb_DiscreteTimeIntegrator = Day1_4_4_raspi_P.Constant3_Value;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* MATLABSystem: '<S8>/Digital Write' incorporates:
   *  Constant: '<S1>/Motor Start'
   *  Logic: '<S5>/AND2'
   */
  EXT_GPIO_write(13U, (uint8_T)((Day1_4_4_raspi_P.MotorStart_Value != 0.0) &&
    (rtb_DiscreteTimeIntegrator != 0.0)));

  /* MATLABSystem: '<S9>/Digital Write' incorporates:
   *  Constant: '<S1>/Motor Start'
   *  Logic: '<S5>/AND3'
   *  Logic: '<S5>/NOT1'
   */
  EXT_GPIO_write(6U, (uint8_T)((Day1_4_4_raspi_P.MotorStart_Value != 0.0) &&
    (!(rtb_DiscreteTimeIntegrator != 0.0))));

  /* MATLABSystem: '<S1>/M1 Encoder' */
  if (Day1_4_4_raspi_DW.obj_d.SampleTime !=
      Day1_4_4_raspi_P.M1Encoder_SampleTime) {
    Day1_4_4_raspi_DW.obj_d.SampleTime = Day1_4_4_raspi_P.M1Encoder_SampleTime;
  }

  if (Day1_4_4_raspi_DW.obj_d.TunablePropsChanged) {
    Day1_4_4_raspi_DW.obj_d.TunablePropsChanged = false;
  }

  MW_RaspiEncoderRead(Day1_4_4_raspi_DW.obj_d.Index, &rtb_M1Encoder_0);

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  MATLABSystem: '<S1>/M1 Encoder'
   */
  Day1_4_4_raspi_B.DataTypeConversion = rtb_M1Encoder_0;

  /* SampleTimeMath: '<S2>/TSamp' incorporates:
   *  Gain: '<S1>/M1 Calibration Gain'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_DiscreteTimeIntegrator = Day1_4_4_raspi_P.M1CalibrationGain_Gain *
    Day1_4_4_raspi_B.DataTypeConversion * Day1_4_4_raspi_P.TSamp_WtEt;

  /* Sum: '<S2>/Diff' incorporates:
   *  UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  Day1_4_4_raspi_B.Diff = rtb_DiscreteTimeIntegrator -
    Day1_4_4_raspi_DW.UD_DSTATE;

  /* MATLABSystem: '<S1>/M2 Encoder' */
  if (Day1_4_4_raspi_DW.obj.SampleTime != Day1_4_4_raspi_P.M2Encoder_SampleTime)
  {
    Day1_4_4_raspi_DW.obj.SampleTime = Day1_4_4_raspi_P.M2Encoder_SampleTime;
  }

  if (Day1_4_4_raspi_DW.obj.TunablePropsChanged) {
    Day1_4_4_raspi_DW.obj.TunablePropsChanged = false;
  }

  MW_RaspiEncoderRead(Day1_4_4_raspi_DW.obj.Index, &rtb_M1Encoder_0);

  /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
   *  MATLABSystem: '<S1>/M2 Encoder'
   */
  Day1_4_4_raspi_B.DataTypeConversion1 = rtb_M1Encoder_0;

  /* SampleTimeMath: '<S3>/TSamp' incorporates:
   *  Gain: '<S1>/M2 Calibration Gain'
   *
   * About '<S3>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_o = Day1_4_4_raspi_P.M2CalibrationGain_Gain *
    Day1_4_4_raspi_B.DataTypeConversion1 * Day1_4_4_raspi_P.TSamp_WtEt_b;

  /* Sum: '<S3>/Diff' incorporates:
   *  UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  Day1_4_4_raspi_B.Diff_h = rtb_TSamp_o - Day1_4_4_raspi_DW.UD_DSTATE_a;

  /* Sum: '<S1>/Add2' */
  rtb_Add2 = Day1_4_4_raspi_B.M2SpeedControldegs - Day1_4_4_raspi_B.Diff_h;

  /* Sum: '<S1>/Add3' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Gain: '<S1>/I Gain1'
   *  Gain: '<S1>/P Gain1'
   */
  u0 = Day1_4_4_raspi_P.PGain1_Gain * rtb_Add2 + Day1_4_4_raspi_P.IGain1_Gain *
    Day1_4_4_raspi_DW.DiscreteTimeIntegrator_DSTATE;

  /* MATLABSystem: '<S5>/PWM1' */
  if (!(u0 <= 1.0)) {
    u0 = 1.0;
  }

  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  EXT_PWMBlock_setDutyCycle(Day1_4_4_raspi_DW.obj_a.PinNumber, u0);

  /* End of MATLABSystem: '<S5>/PWM1' */
  /* Sum: '<S1>/Add' */
  rtb_Add = Day1_4_4_raspi_B.M1SpeedControldegs - Day1_4_4_raspi_B.Diff;

  /* Sum: '<S1>/Add1' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
   *  Gain: '<S1>/I Gain'
   *  Gain: '<S1>/P Gain'
   */
  u0 = Day1_4_4_raspi_P.PGain_Gain * rtb_Add + Day1_4_4_raspi_P.IGain_Gain *
    Day1_4_4_raspi_DW.DiscreteTimeIntegrator1_DSTATE;

  /* MATLABSystem: '<S4>/PWM' */
  if (!(u0 <= 1.0)) {
    u0 = 1.0;
  }

  if (!(u0 >= 0.0)) {
    u0 = 0.0;
  }

  EXT_PWMBlock_setDutyCycle(Day1_4_4_raspi_DW.obj_e.PinNumber, u0);

  /* End of MATLABSystem: '<S4>/PWM' */
  /* MATLABSystem: '<S7>/Digital Write' incorporates:
   *  Constant: '<S1>/Motor Start'
   *  Logic: '<S4>/AND1'
   *  Logic: '<S4>/NOT'
   */
  EXT_GPIO_write(14U, (uint8_T)((Day1_4_4_raspi_P.MotorStart_Value != 0.0) &&
    (!(rtb_Switch != 0.0))));

  /* Update for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  Day1_4_4_raspi_DW.UD_DSTATE = rtb_DiscreteTimeIntegrator;

  /* Update for UnitDelay: '<S3>/UD'
   *
   * Block description for '<S3>/UD':
   *
   *  Store in Global RAM
   */
  Day1_4_4_raspi_DW.UD_DSTATE_a = rtb_TSamp_o;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
  Day1_4_4_raspi_DW.DiscreteTimeIntegrator_DSTATE +=
    Day1_4_4_raspi_P.DiscreteTimeIntegrator_gainval * rtb_Add2;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
  Day1_4_4_raspi_DW.DiscreteTimeIntegrator1_DSTATE +=
    Day1_4_4_raspi_P.DiscreteTimeIntegrator1_gainval * rtb_Add;

  {                                    /* Sample time: [0.001s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Day1_4_4_raspi_M->Timing.taskTime0 =
    ((time_T)(++Day1_4_4_raspi_M->Timing.clockTick0)) *
    Day1_4_4_raspi_M->Timing.stepSize0;
}

/* Model initialize function */
void Day1_4_4_raspi_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Day1_4_4_raspi_M, -1);
  Day1_4_4_raspi_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Day1_4_4_raspi_M->Sizes.checksums[0] = (3381262111U);
  Day1_4_4_raspi_M->Sizes.checksums[1] = (690393304U);
  Day1_4_4_raspi_M->Sizes.checksums[2] = (1333292539U);
  Day1_4_4_raspi_M->Sizes.checksums[3] = (3783589276U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    Day1_4_4_raspi_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Day1_4_4_raspi_M->extModeInfo,
      &Day1_4_4_raspi_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Day1_4_4_raspi_M->extModeInfo,
                        Day1_4_4_raspi_M->Sizes.checksums);
    rteiSetTPtr(Day1_4_4_raspi_M->extModeInfo, rtmGetTPtr(Day1_4_4_raspi_M));
  }

  {
    int32_T ret;
    char_T b[45];
    static const char_T tmp[45] =
      "Unable to configure pin %u for PWM output.\\n";

    /* InitializeConditions for UnitDelay: '<S2>/UD'
     *
     * Block description for '<S2>/UD':
     *
     *  Store in Global RAM
     */
    Day1_4_4_raspi_DW.UD_DSTATE =
      Day1_4_4_raspi_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for UnitDelay: '<S3>/UD'
     *
     * Block description for '<S3>/UD':
     *
     *  Store in Global RAM
     */
    Day1_4_4_raspi_DW.UD_DSTATE_a =
      Day1_4_4_raspi_P.DiscreteDerivative1_ICPrevScale;

    /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' */
    Day1_4_4_raspi_DW.DiscreteTimeIntegrator_DSTATE =
      Day1_4_4_raspi_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' */
    Day1_4_4_raspi_DW.DiscreteTimeIntegrator1_DSTATE =
      Day1_4_4_raspi_P.DiscreteTimeIntegrator1_IC;

    /* Start for MATLABSystem: '<S6>/Digital Write' */
    Day1_4_4_raspi_DW.obj_a1.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj_a1.isInitialized = 1;
    EXT_GPIO_init(15U, true);
    Day1_4_4_raspi_DW.obj_a1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S8>/Digital Write' */
    Day1_4_4_raspi_DW.obj_oo.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj_oo.isInitialized = 1;
    EXT_GPIO_init(13U, true);
    Day1_4_4_raspi_DW.obj_oo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/Digital Write' */
    Day1_4_4_raspi_DW.obj_o.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj_o.isInitialized = 1;
    EXT_GPIO_init(6U, true);
    Day1_4_4_raspi_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/M1 Encoder' */
    Day1_4_4_raspi_DW.obj_d.Index = 0U;
    Day1_4_4_raspi_DW.obj_d.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj_d.SampleTime = Day1_4_4_raspi_P.M1Encoder_SampleTime;
    Day1_4_4_raspi_DW.obj_d.isInitialized = 1;
    MW_RaspiEncoderSetup(10, 20, &Day1_4_4_raspi_DW.obj_d.Index);
    Day1_4_4_raspi_DW.obj_d.isSetupComplete = true;
    Day1_4_4_raspi_DW.obj_d.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S1>/M1 Encoder' */
    MW_RaspiEncoderReset(Day1_4_4_raspi_DW.obj_d.Index);

    /* Start for MATLABSystem: '<S1>/M2 Encoder' */
    Day1_4_4_raspi_DW.obj.Index = 0U;
    Day1_4_4_raspi_DW.obj.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj.SampleTime = Day1_4_4_raspi_P.M2Encoder_SampleTime;
    Day1_4_4_raspi_DW.obj.isInitialized = 1;
    MW_RaspiEncoderSetup(27, 17, &Day1_4_4_raspi_DW.obj.Index);
    Day1_4_4_raspi_DW.obj.isSetupComplete = true;
    Day1_4_4_raspi_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S1>/M2 Encoder' */
    MW_RaspiEncoderReset(Day1_4_4_raspi_DW.obj.Index);

    /* Start for MATLABSystem: '<S5>/PWM1' */
    Day1_4_4_raspi_DW.obj_a.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj_a.isInitialized = 1;
    Day1_4_4_raspi_DW.obj_a.PinNumber = 9U;
    ret = EXT_PWMBlock_init(Day1_4_4_raspi_DW.obj_a.PinNumber, 50U, 0.0);
    if (ret != 0) {
      for (ret = 0; ret < 45; ret++) {
        b[ret] = tmp[ret];
      }

      printf(&b[0], Day1_4_4_raspi_DW.obj_a.PinNumber);
    }

    Day1_4_4_raspi_DW.obj_a.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S5>/PWM1' */

    /* Start for MATLABSystem: '<S4>/PWM' */
    Day1_4_4_raspi_DW.obj_e.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj_e.isInitialized = 1;
    Day1_4_4_raspi_DW.obj_e.PinNumber = 18U;
    ret = EXT_PWMBlock_init(Day1_4_4_raspi_DW.obj_e.PinNumber, 50U, 0.0);
    if (ret != 0) {
      for (ret = 0; ret < 45; ret++) {
        b[ret] = tmp[ret];
      }

      printf(&b[0], Day1_4_4_raspi_DW.obj_e.PinNumber);
    }

    Day1_4_4_raspi_DW.obj_e.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/PWM' */

    /* Start for MATLABSystem: '<S7>/Digital Write' */
    Day1_4_4_raspi_DW.obj_l.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj_l.isInitialized = 1;
    EXT_GPIO_init(14U, true);
    Day1_4_4_raspi_DW.obj_l.isSetupComplete = true;
  }
}

/* Model terminate function */
void Day1_4_4_raspi_terminate(void)
{
  /* Terminate for MATLABSystem: '<S6>/Digital Write' */
  if (!Day1_4_4_raspi_DW.obj_a1.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_a1.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_a1.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_a1.isSetupComplete) {
      EXT_GPIO_terminate(15U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write' */

  /* Terminate for MATLABSystem: '<S8>/Digital Write' */
  if (!Day1_4_4_raspi_DW.obj_oo.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_oo.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_oo.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_oo.isSetupComplete) {
      EXT_GPIO_terminate(13U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Write' */

  /* Terminate for MATLABSystem: '<S9>/Digital Write' */
  if (!Day1_4_4_raspi_DW.obj_o.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_o.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_o.isSetupComplete) {
      EXT_GPIO_terminate(6U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/Digital Write' */
  /* Terminate for MATLABSystem: '<S1>/M1 Encoder' */
  if (!Day1_4_4_raspi_DW.obj_d.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_d.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_d.isSetupComplete) {
      MW_RaspiEncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/M1 Encoder' */

  /* Terminate for MATLABSystem: '<S1>/M2 Encoder' */
  if (!Day1_4_4_raspi_DW.obj.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj.isSetupComplete) {
      MW_RaspiEncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/M2 Encoder' */
  /* Terminate for MATLABSystem: '<S5>/PWM1' */
  if (!Day1_4_4_raspi_DW.obj_a.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_a.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_a.isSetupComplete) {
      EXT_PWMBlock_terminate(Day1_4_4_raspi_DW.obj_a.PinNumber);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM1' */
  /* Terminate for MATLABSystem: '<S4>/PWM' */
  if (!Day1_4_4_raspi_DW.obj_e.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_e.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_e.isSetupComplete) {
      EXT_PWMBlock_terminate(Day1_4_4_raspi_DW.obj_e.PinNumber);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM' */
  /* Terminate for MATLABSystem: '<S7>/Digital Write' */
  if (!Day1_4_4_raspi_DW.obj_l.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_l.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_l.isSetupComplete) {
      EXT_GPIO_terminate(14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
