/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Day1_4_1_raspi.c
 *
 * Code generated for Simulink model 'Day1_4_1_raspi'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Oct 18 16:10:42 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Day1_4_1_raspi.h"
#include "rtwtypes.h"
#include "Day1_4_1_raspi_private.h"

/* Block signals (default storage) */
B_Day1_4_1_raspi_T Day1_4_1_raspi_B;

/* Block states (default storage) */
DW_Day1_4_1_raspi_T Day1_4_1_raspi_DW;

/* Real-time model */
static RT_MODEL_Day1_4_1_raspi_T Day1_4_1_raspi_M_;
RT_MODEL_Day1_4_1_raspi_T *const Day1_4_1_raspi_M = &Day1_4_1_raspi_M_;

/* Model step function */
void Day1_4_1_raspi_step(void)
{
  real_T y;

  /* MATLABSystem: '<S1>/Digital Write' incorporates:
   *  Constant: '<Root>/M1_Direction'
   *  Constant: '<Root>/M1_Start'
   *  Logic: '<Root>/AND'
   */
  EXT_GPIO_write(15U, (uint8_T)((Day1_4_1_raspi_P.M1_Start_Value != 0.0) &&
    (Day1_4_1_raspi_P.M1_Direction_Value != 0.0)));

  /* MATLABSystem: '<S2>/Digital Write' incorporates:
   *  Constant: '<Root>/M1_Direction'
   *  Constant: '<Root>/M1_Start'
   *  Logic: '<Root>/AND1'
   *  Logic: '<Root>/NOT'
   */
  EXT_GPIO_write(14U, (uint8_T)((Day1_4_1_raspi_P.M1_Start_Value != 0.0) &&
    (!(Day1_4_1_raspi_P.M1_Direction_Value != 0.0))));

  /* MATLABSystem: '<S3>/Digital Write' incorporates:
   *  Constant: '<Root>/M2_Direction'
   *  Constant: '<Root>/M2_Start'
   *  Logic: '<Root>/AND2'
   */
  EXT_GPIO_write(13U, (uint8_T)((Day1_4_1_raspi_P.M2_Start_Value != 0.0) &&
    (Day1_4_1_raspi_P.M2_Direction_Value != 0.0)));

  /* MATLABSystem: '<S4>/Digital Write' incorporates:
   *  Constant: '<Root>/M2_Direction'
   *  Constant: '<Root>/M2_Start'
   *  Logic: '<Root>/AND3'
   *  Logic: '<Root>/NOT1'
   */
  EXT_GPIO_write(6U, (uint8_T)((Day1_4_1_raspi_P.M2_Start_Value != 0.0) &&
    (!(Day1_4_1_raspi_P.M2_Direction_Value != 0.0))));

  /* MATLABSystem: '<Root>/Encoder' */
  if (Day1_4_1_raspi_DW.obj_d.SampleTime != Day1_4_1_raspi_P.Encoder_SampleTime)
  {
    Day1_4_1_raspi_DW.obj_d.SampleTime = Day1_4_1_raspi_P.Encoder_SampleTime;
  }

  if (Day1_4_1_raspi_DW.obj_d.TunablePropsChanged) {
    Day1_4_1_raspi_DW.obj_d.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<Root>/Encoder' */
  MW_RaspiEncoderRead(Day1_4_1_raspi_DW.obj_d.Index, &Day1_4_1_raspi_B.Encoder);

  /* MATLABSystem: '<Root>/Encoder1' */
  if (Day1_4_1_raspi_DW.obj.SampleTime != Day1_4_1_raspi_P.Encoder1_SampleTime)
  {
    Day1_4_1_raspi_DW.obj.SampleTime = Day1_4_1_raspi_P.Encoder1_SampleTime;
  }

  if (Day1_4_1_raspi_DW.obj.TunablePropsChanged) {
    Day1_4_1_raspi_DW.obj.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<Root>/Encoder1' */
  MW_RaspiEncoderRead(Day1_4_1_raspi_DW.obj.Index, &Day1_4_1_raspi_B.Encoder1);

  /* MATLABSystem: '<Root>/PWM' incorporates:
   *  Constant: '<Root>/Power'
   */
  if (Day1_4_1_raspi_P.Power_Value <= 1.0) {
    y = Day1_4_1_raspi_P.Power_Value;
  } else {
    y = 1.0;
  }

  if (!(y >= 0.0)) {
    y = 0.0;
  }

  EXT_PWMBlock_setDutyCycle(Day1_4_1_raspi_DW.obj_e.PinNumber, y);

  /* End of MATLABSystem: '<Root>/PWM' */

  /* MATLABSystem: '<Root>/PWM1' incorporates:
   *  Constant: '<Root>/Power'
   */
  if (Day1_4_1_raspi_P.Power_Value <= 1.0) {
    y = Day1_4_1_raspi_P.Power_Value;
  } else {
    y = 1.0;
  }

  if (!(y >= 0.0)) {
    y = 0.0;
  }

  EXT_PWMBlock_setDutyCycle(Day1_4_1_raspi_DW.obj_a.PinNumber, y);

  /* End of MATLABSystem: '<Root>/PWM1' */
  {                                    /* Sample time: [0.2s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Day1_4_1_raspi_M->Timing.taskTime0 =
    ((time_T)(++Day1_4_1_raspi_M->Timing.clockTick0)) *
    Day1_4_1_raspi_M->Timing.stepSize0;
}

/* Model initialize function */
void Day1_4_1_raspi_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Day1_4_1_raspi_M, -1);
  Day1_4_1_raspi_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  Day1_4_1_raspi_M->Sizes.checksums[0] = (3703221136U);
  Day1_4_1_raspi_M->Sizes.checksums[1] = (2011166766U);
  Day1_4_1_raspi_M->Sizes.checksums[2] = (3165974125U);
  Day1_4_1_raspi_M->Sizes.checksums[3] = (2397421010U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    Day1_4_1_raspi_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(Day1_4_1_raspi_M->extModeInfo,
      &Day1_4_1_raspi_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Day1_4_1_raspi_M->extModeInfo,
                        Day1_4_1_raspi_M->Sizes.checksums);
    rteiSetTPtr(Day1_4_1_raspi_M->extModeInfo, rtmGetTPtr(Day1_4_1_raspi_M));
  }

  {
    int32_T ret;
    char_T b[45];
    static const char_T tmp[45] =
      "Unable to configure pin %u for PWM output.\\n";

    /* Start for MATLABSystem: '<S1>/Digital Write' */
    Day1_4_1_raspi_DW.obj_a1.matlabCodegenIsDeleted = false;
    Day1_4_1_raspi_DW.obj_a1.isInitialized = 1;
    EXT_GPIO_init(15U, true);
    Day1_4_1_raspi_DW.obj_a1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Digital Write' */
    Day1_4_1_raspi_DW.obj_l.matlabCodegenIsDeleted = false;
    Day1_4_1_raspi_DW.obj_l.isInitialized = 1;
    EXT_GPIO_init(14U, true);
    Day1_4_1_raspi_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Digital Write' */
    Day1_4_1_raspi_DW.obj_oo.matlabCodegenIsDeleted = false;
    Day1_4_1_raspi_DW.obj_oo.isInitialized = 1;
    EXT_GPIO_init(13U, true);
    Day1_4_1_raspi_DW.obj_oo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write' */
    Day1_4_1_raspi_DW.obj_o.matlabCodegenIsDeleted = false;
    Day1_4_1_raspi_DW.obj_o.isInitialized = 1;
    EXT_GPIO_init(6U, true);
    Day1_4_1_raspi_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Encoder' */
    Day1_4_1_raspi_DW.obj_d.Index = 0U;
    Day1_4_1_raspi_DW.obj_d.matlabCodegenIsDeleted = false;
    Day1_4_1_raspi_DW.obj_d.SampleTime = Day1_4_1_raspi_P.Encoder_SampleTime;
    Day1_4_1_raspi_DW.obj_d.isInitialized = 1;
    MW_RaspiEncoderSetup(10, 20, &Day1_4_1_raspi_DW.obj_d.Index);
    Day1_4_1_raspi_DW.obj_d.isSetupComplete = true;
    Day1_4_1_raspi_DW.obj_d.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<Root>/Encoder' */
    MW_RaspiEncoderReset(Day1_4_1_raspi_DW.obj_d.Index);

    /* Start for MATLABSystem: '<Root>/Encoder1' */
    Day1_4_1_raspi_DW.obj.Index = 0U;
    Day1_4_1_raspi_DW.obj.matlabCodegenIsDeleted = false;
    Day1_4_1_raspi_DW.obj.SampleTime = Day1_4_1_raspi_P.Encoder1_SampleTime;
    Day1_4_1_raspi_DW.obj.isInitialized = 1;
    MW_RaspiEncoderSetup(27, 17, &Day1_4_1_raspi_DW.obj.Index);
    Day1_4_1_raspi_DW.obj.isSetupComplete = true;
    Day1_4_1_raspi_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<Root>/Encoder1' */
    MW_RaspiEncoderReset(Day1_4_1_raspi_DW.obj.Index);

    /* Start for MATLABSystem: '<Root>/PWM' */
    Day1_4_1_raspi_DW.obj_e.matlabCodegenIsDeleted = false;
    Day1_4_1_raspi_DW.obj_e.isInitialized = 1;
    Day1_4_1_raspi_DW.obj_e.PinNumber = 18U;
    ret = EXT_PWMBlock_init(Day1_4_1_raspi_DW.obj_e.PinNumber, 50U, 0.0);
    if (ret != 0) {
      for (ret = 0; ret < 45; ret++) {
        b[ret] = tmp[ret];
      }

      printf(&b[0], Day1_4_1_raspi_DW.obj_e.PinNumber);
    }

    Day1_4_1_raspi_DW.obj_e.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/PWM' */

    /* Start for MATLABSystem: '<Root>/PWM1' */
    Day1_4_1_raspi_DW.obj_a.matlabCodegenIsDeleted = false;
    Day1_4_1_raspi_DW.obj_a.isInitialized = 1;
    Day1_4_1_raspi_DW.obj_a.PinNumber = 9U;
    ret = EXT_PWMBlock_init(Day1_4_1_raspi_DW.obj_a.PinNumber, 50U, 0.0);
    if (ret != 0) {
      for (ret = 0; ret < 45; ret++) {
        b[ret] = tmp[ret];
      }

      printf(&b[0], Day1_4_1_raspi_DW.obj_a.PinNumber);
    }

    Day1_4_1_raspi_DW.obj_a.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/PWM1' */
  }
}

/* Model terminate function */
void Day1_4_1_raspi_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Digital Write' */
  if (!Day1_4_1_raspi_DW.obj_a1.matlabCodegenIsDeleted) {
    Day1_4_1_raspi_DW.obj_a1.matlabCodegenIsDeleted = true;
    if ((Day1_4_1_raspi_DW.obj_a1.isInitialized == 1) &&
        Day1_4_1_raspi_DW.obj_a1.isSetupComplete) {
      EXT_GPIO_terminate(15U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write' */

  /* Terminate for MATLABSystem: '<S2>/Digital Write' */
  if (!Day1_4_1_raspi_DW.obj_l.matlabCodegenIsDeleted) {
    Day1_4_1_raspi_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Day1_4_1_raspi_DW.obj_l.isInitialized == 1) &&
        Day1_4_1_raspi_DW.obj_l.isSetupComplete) {
      EXT_GPIO_terminate(14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Digital Write' */

  /* Terminate for MATLABSystem: '<S3>/Digital Write' */
  if (!Day1_4_1_raspi_DW.obj_oo.matlabCodegenIsDeleted) {
    Day1_4_1_raspi_DW.obj_oo.matlabCodegenIsDeleted = true;
    if ((Day1_4_1_raspi_DW.obj_oo.isInitialized == 1) &&
        Day1_4_1_raspi_DW.obj_oo.isSetupComplete) {
      EXT_GPIO_terminate(13U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write' */
  if (!Day1_4_1_raspi_DW.obj_o.matlabCodegenIsDeleted) {
    Day1_4_1_raspi_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Day1_4_1_raspi_DW.obj_o.isInitialized == 1) &&
        Day1_4_1_raspi_DW.obj_o.isSetupComplete) {
      EXT_GPIO_terminate(6U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!Day1_4_1_raspi_DW.obj_d.matlabCodegenIsDeleted) {
    Day1_4_1_raspi_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Day1_4_1_raspi_DW.obj_d.isInitialized == 1) &&
        Day1_4_1_raspi_DW.obj_d.isSetupComplete) {
      MW_RaspiEncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/Encoder1' */
  if (!Day1_4_1_raspi_DW.obj.matlabCodegenIsDeleted) {
    Day1_4_1_raspi_DW.obj.matlabCodegenIsDeleted = true;
    if ((Day1_4_1_raspi_DW.obj.isInitialized == 1) &&
        Day1_4_1_raspi_DW.obj.isSetupComplete) {
      MW_RaspiEncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder1' */
  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!Day1_4_1_raspi_DW.obj_e.matlabCodegenIsDeleted) {
    Day1_4_1_raspi_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Day1_4_1_raspi_DW.obj_e.isInitialized == 1) &&
        Day1_4_1_raspi_DW.obj_e.isSetupComplete) {
      EXT_PWMBlock_terminate(Day1_4_1_raspi_DW.obj_e.PinNumber);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  if (!Day1_4_1_raspi_DW.obj_a.matlabCodegenIsDeleted) {
    Day1_4_1_raspi_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Day1_4_1_raspi_DW.obj_a.isInitialized == 1) &&
        Day1_4_1_raspi_DW.obj_a.isSetupComplete) {
      EXT_PWMBlock_terminate(Day1_4_1_raspi_DW.obj_a.PinNumber);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
