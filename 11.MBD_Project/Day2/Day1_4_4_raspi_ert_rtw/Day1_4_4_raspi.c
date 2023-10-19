/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Day1_4_4_raspi.c
 *
 * Code generated for Simulink model 'Day1_4_4_raspi'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Oct 19 14:45:25 2023
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
  real_T rtb_TSamp;
  real_T rtb_TSamp_c;
  real_T y;

  /* MATLABSystem: '<Root>/M2 Encoder' */
  if (Day1_4_4_raspi_DW.obj.SampleTime != Day1_4_4_raspi_P.M2Encoder_SampleTime)
  {
    Day1_4_4_raspi_DW.obj.SampleTime = Day1_4_4_raspi_P.M2Encoder_SampleTime;
  }

  if (Day1_4_4_raspi_DW.obj.TunablePropsChanged) {
    Day1_4_4_raspi_DW.obj.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<Root>/M2 Encoder' */
  MW_RaspiEncoderRead(Day1_4_4_raspi_DW.obj.Index, &Day1_4_4_raspi_B.M2Encoder);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  Day1_4_4_raspi_B.DataTypeConversion1 = Day1_4_4_raspi_B.M2Encoder;

  /* SampleTimeMath: '<S2>/TSamp' incorporates:
   *  Gain: '<Root>/M2 Calibration Gain'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp = Day1_4_4_raspi_P.M2CalibrationGain_Gain *
    Day1_4_4_raspi_B.DataTypeConversion1 * Day1_4_4_raspi_P.TSamp_WtEt;

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
  Day1_4_4_raspi_B.Diff = rtb_TSamp - Day1_4_4_raspi_DW.UD_DSTATE;

  /* Constant: '<Root>/Speed Control (deg//s)' */
  Day1_4_4_raspi_B.SpeedControldegs = Day1_4_4_raspi_P.SpeedControldegs_Value;

  /* MATLABSystem: '<Root>/M1 Encoder' */
  if (Day1_4_4_raspi_DW.obj_d.SampleTime !=
      Day1_4_4_raspi_P.M1Encoder_SampleTime) {
    Day1_4_4_raspi_DW.obj_d.SampleTime = Day1_4_4_raspi_P.M1Encoder_SampleTime;
  }

  if (Day1_4_4_raspi_DW.obj_d.TunablePropsChanged) {
    Day1_4_4_raspi_DW.obj_d.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<Root>/M1 Encoder' */
  MW_RaspiEncoderRead(Day1_4_4_raspi_DW.obj_d.Index, &Day1_4_4_raspi_B.M1Encoder);

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  Day1_4_4_raspi_B.DataTypeConversion = Day1_4_4_raspi_B.M1Encoder;

  /* SampleTimeMath: '<S1>/TSamp' incorporates:
   *  Gain: '<Root>/M1 Calibration Gain'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_c = Day1_4_4_raspi_P.M1CalibrationGain_Gain *
    Day1_4_4_raspi_B.DataTypeConversion * Day1_4_4_raspi_P.TSamp_WtEt_d;

  /* Sum: '<S1>/Diff' incorporates:
   *  UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  Day1_4_4_raspi_B.Diff_a = rtb_TSamp_c - Day1_4_4_raspi_DW.UD_DSTATE_f;

  /* Sum: '<Root>/Add' */
  rtb_Add = Day1_4_4_raspi_B.SpeedControldegs - Day1_4_4_raspi_B.Diff_a;

  /* Sum: '<Root>/Add1' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
   *  Gain: '<Root>/I Gain'
   *  Gain: '<Root>/P Gain'
   */
  Day1_4_4_raspi_B.Add1 = Day1_4_4_raspi_P.PGain_Gain * rtb_Add +
    Day1_4_4_raspi_P.IGain_Gain *
    Day1_4_4_raspi_DW.DiscreteTimeIntegrator1_DSTATE;

  /* MATLABSystem: '<S3>/PWM' */
  if (Day1_4_4_raspi_B.Add1 <= 1.0) {
    y = Day1_4_4_raspi_B.Add1;
  } else {
    y = 1.0;
  }

  if (!(y >= 0.0)) {
    y = 0.0;
  }

  EXT_PWMBlock_setDutyCycle(Day1_4_4_raspi_DW.obj_e.PinNumber, y);

  /* End of MATLABSystem: '<S3>/PWM' */

  /* Sum: '<Root>/Add2' */
  rtb_Add2 = Day1_4_4_raspi_B.SpeedControldegs - Day1_4_4_raspi_B.Diff;

  /* Sum: '<Root>/Add3' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  Gain: '<Root>/I Gain1'
   *  Gain: '<Root>/P Gain1'
   */
  Day1_4_4_raspi_B.Add3 = Day1_4_4_raspi_P.PGain1_Gain * rtb_Add2 +
    Day1_4_4_raspi_P.IGain1_Gain *
    Day1_4_4_raspi_DW.DiscreteTimeIntegrator_DSTATE;

  /* MATLABSystem: '<S4>/PWM1' */
  if (Day1_4_4_raspi_B.Add3 <= 1.0) {
    y = Day1_4_4_raspi_B.Add3;
  } else {
    y = 1.0;
  }

  if (!(y >= 0.0)) {
    y = 0.0;
  }

  EXT_PWMBlock_setDutyCycle(Day1_4_4_raspi_DW.obj_a.PinNumber, y);

  /* End of MATLABSystem: '<S4>/PWM1' */
  /* MATLABSystem: '<S5>/Digital Write' incorporates:
   *  Constant: '<Root>/Motor Direction'
   *  Constant: '<Root>/Motor Start'
   *  Logic: '<S3>/AND'
   */
  EXT_GPIO_write(15U, (uint8_T)((Day1_4_4_raspi_P.MotorStart_Value != 0.0) &&
    (Day1_4_4_raspi_P.MotorDirection_Value != 0.0)));

  /* MATLABSystem: '<S6>/Digital Write' incorporates:
   *  Constant: '<Root>/Motor Direction'
   *  Constant: '<Root>/Motor Start'
   *  Logic: '<S3>/AND1'
   *  Logic: '<S3>/NOT'
   */
  EXT_GPIO_write(14U, (uint8_T)((Day1_4_4_raspi_P.MotorStart_Value != 0.0) &&
    (!(Day1_4_4_raspi_P.MotorDirection_Value != 0.0))));

  /* MATLABSystem: '<S7>/Digital Write' incorporates:
   *  Constant: '<Root>/Motor Direction'
   *  Constant: '<Root>/Motor Start'
   *  Logic: '<S4>/AND2'
   */
  EXT_GPIO_write(13U, (uint8_T)((Day1_4_4_raspi_P.MotorStart_Value != 0.0) &&
    (Day1_4_4_raspi_P.MotorDirection_Value != 0.0)));

  /* MATLABSystem: '<S8>/Digital Write' incorporates:
   *  Constant: '<Root>/Motor Direction'
   *  Constant: '<Root>/Motor Start'
   *  Logic: '<S4>/AND3'
   *  Logic: '<S4>/NOT1'
   */
  EXT_GPIO_write(6U, (uint8_T)((Day1_4_4_raspi_P.MotorStart_Value != 0.0) &&
    (!(Day1_4_4_raspi_P.MotorDirection_Value != 0.0))));

  /* Update for UnitDelay: '<S2>/UD'
   *
   * Block description for '<S2>/UD':
   *
   *  Store in Global RAM
   */
  Day1_4_4_raspi_DW.UD_DSTATE = rtb_TSamp;

  /* Update for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  Day1_4_4_raspi_DW.UD_DSTATE_f = rtb_TSamp_c;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  Day1_4_4_raspi_DW.DiscreteTimeIntegrator1_DSTATE +=
    Day1_4_4_raspi_P.DiscreteTimeIntegrator1_gainval * rtb_Add;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  Day1_4_4_raspi_DW.DiscreteTimeIntegrator_DSTATE +=
    Day1_4_4_raspi_P.DiscreteTimeIntegrator_gainval * rtb_Add2;

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
  Day1_4_4_raspi_M->Sizes.checksums[0] = (288934314U);
  Day1_4_4_raspi_M->Sizes.checksums[1] = (2301899141U);
  Day1_4_4_raspi_M->Sizes.checksums[2] = (1025889796U);
  Day1_4_4_raspi_M->Sizes.checksums[3] = (3277216104U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
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
      Day1_4_4_raspi_P.DiscreteDerivative1_ICPrevScale;

    /* InitializeConditions for UnitDelay: '<S1>/UD'
     *
     * Block description for '<S1>/UD':
     *
     *  Store in Global RAM
     */
    Day1_4_4_raspi_DW.UD_DSTATE_f =
      Day1_4_4_raspi_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
    Day1_4_4_raspi_DW.DiscreteTimeIntegrator1_DSTATE =
      Day1_4_4_raspi_P.DiscreteTimeIntegrator1_IC;

    /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
    Day1_4_4_raspi_DW.DiscreteTimeIntegrator_DSTATE =
      Day1_4_4_raspi_P.DiscreteTimeIntegrator_IC;

    /* Start for MATLABSystem: '<Root>/M2 Encoder' */
    Day1_4_4_raspi_DW.obj.Index = 0U;
    Day1_4_4_raspi_DW.obj.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj.SampleTime = Day1_4_4_raspi_P.M2Encoder_SampleTime;
    Day1_4_4_raspi_DW.obj.isInitialized = 1;
    MW_RaspiEncoderSetup(27, 17, &Day1_4_4_raspi_DW.obj.Index);
    Day1_4_4_raspi_DW.obj.isSetupComplete = true;
    Day1_4_4_raspi_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<Root>/M2 Encoder' */
    MW_RaspiEncoderReset(Day1_4_4_raspi_DW.obj.Index);

    /* Start for MATLABSystem: '<Root>/M1 Encoder' */
    Day1_4_4_raspi_DW.obj_d.Index = 0U;
    Day1_4_4_raspi_DW.obj_d.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj_d.SampleTime = Day1_4_4_raspi_P.M1Encoder_SampleTime;
    Day1_4_4_raspi_DW.obj_d.isInitialized = 1;
    MW_RaspiEncoderSetup(10, 20, &Day1_4_4_raspi_DW.obj_d.Index);
    Day1_4_4_raspi_DW.obj_d.isSetupComplete = true;
    Day1_4_4_raspi_DW.obj_d.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<Root>/M1 Encoder' */
    MW_RaspiEncoderReset(Day1_4_4_raspi_DW.obj_d.Index);

    /* Start for MATLABSystem: '<S3>/PWM' */
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

    /* End of Start for MATLABSystem: '<S3>/PWM' */

    /* Start for MATLABSystem: '<S4>/PWM1' */
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

    /* End of Start for MATLABSystem: '<S4>/PWM1' */

    /* Start for MATLABSystem: '<S5>/Digital Write' */
    Day1_4_4_raspi_DW.obj_a1.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj_a1.isInitialized = 1;
    EXT_GPIO_init(15U, true);
    Day1_4_4_raspi_DW.obj_a1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write' */
    Day1_4_4_raspi_DW.obj_l.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj_l.isInitialized = 1;
    EXT_GPIO_init(14U, true);
    Day1_4_4_raspi_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S7>/Digital Write' */
    Day1_4_4_raspi_DW.obj_oo.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj_oo.isInitialized = 1;
    EXT_GPIO_init(13U, true);
    Day1_4_4_raspi_DW.obj_oo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S8>/Digital Write' */
    Day1_4_4_raspi_DW.obj_o.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj_o.isInitialized = 1;
    EXT_GPIO_init(6U, true);
    Day1_4_4_raspi_DW.obj_o.isSetupComplete = true;
  }
}

/* Model terminate function */
void Day1_4_4_raspi_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/M2 Encoder' */
  if (!Day1_4_4_raspi_DW.obj.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj.isSetupComplete) {
      MW_RaspiEncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/M2 Encoder' */

  /* Terminate for MATLABSystem: '<Root>/M1 Encoder' */
  if (!Day1_4_4_raspi_DW.obj_d.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_d.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_d.isSetupComplete) {
      MW_RaspiEncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/M1 Encoder' */
  /* Terminate for MATLABSystem: '<S3>/PWM' */
  if (!Day1_4_4_raspi_DW.obj_e.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_e.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_e.isSetupComplete) {
      EXT_PWMBlock_terminate(Day1_4_4_raspi_DW.obj_e.PinNumber);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/PWM' */

  /* Terminate for MATLABSystem: '<S4>/PWM1' */
  if (!Day1_4_4_raspi_DW.obj_a.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_a.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_a.isSetupComplete) {
      EXT_PWMBlock_terminate(Day1_4_4_raspi_DW.obj_a.PinNumber);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM1' */
  /* Terminate for MATLABSystem: '<S5>/Digital Write' */
  if (!Day1_4_4_raspi_DW.obj_a1.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_a1.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_a1.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_a1.isSetupComplete) {
      EXT_GPIO_terminate(15U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write' */
  if (!Day1_4_4_raspi_DW.obj_l.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_l.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_l.isSetupComplete) {
      EXT_GPIO_terminate(14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write' */

  /* Terminate for MATLABSystem: '<S7>/Digital Write' */
  if (!Day1_4_4_raspi_DW.obj_oo.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_oo.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_oo.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_oo.isSetupComplete) {
      EXT_GPIO_terminate(13U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Write' */

  /* Terminate for MATLABSystem: '<S8>/Digital Write' */
  if (!Day1_4_4_raspi_DW.obj_o.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_o.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_o.isSetupComplete) {
      EXT_GPIO_terminate(6U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
