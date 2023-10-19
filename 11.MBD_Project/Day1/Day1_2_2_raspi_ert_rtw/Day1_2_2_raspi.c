/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Day1_2_2_raspi.c
 *
 * Code generated for Simulink model 'Day1_2_2_raspi'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Oct 18 11:30:58 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Day1_2_2_raspi.h"
#include "rtwtypes.h"
#include <math.h>
#include "Day1_2_2_raspi_private.h"
#include <string.h>

/* Block signals (default storage) */
B_Day1_2_2_raspi_T Day1_2_2_raspi_B;

/* Block states (default storage) */
DW_Day1_2_2_raspi_T Day1_2_2_raspi_DW;

/* Real-time model */
static RT_MODEL_Day1_2_2_raspi_T Day1_2_2_raspi_M_;
RT_MODEL_Day1_2_2_raspi_T *const Day1_2_2_raspi_M = &Day1_2_2_raspi_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void Day1_2_2_raspi_step(void)
{
  real_T lastSin_tmp;
  int32_T i;
  char_T d[5];
  uint8_T tmp;
  static const char_T tmp_0[69] = { 'I', 'n', 'v', 'a', 'l', 'i', 'd', ' ', 'L',
    'E', 'D', ' ', 'v', 'a', 'l', 'u', 'e', '.', ' ', 'L', 'E', 'D', ' ', 'v',
    'a', 'l', 'u', 'e', ' ', 'm', 'u', 's', 't', ' ', 'b', 'e', ' ', 'a', ' ',
    'l', 'o', 'g', 'i', 'c', 'a', 'l', ' ', 'v', 'a', 'l', 'u', 'e', ' ', '(',
    't', 'r', 'u', 'e', ' ', 'o', 'r', ' ', 'f', 'a', 'l', 's', 'e', ')', '.' };

  static const char_T tmp_1[5] = "none";

  /* Sin: '<Root>/Sine Wave' */
  if (Day1_2_2_raspi_DW.systemEnable != 0) {
    lastSin_tmp = Day1_2_2_raspi_P.SineWave_Freq *
      Day1_2_2_raspi_M->Timing.taskTime0;
    Day1_2_2_raspi_DW.lastSin = sin(lastSin_tmp);
    Day1_2_2_raspi_DW.lastCos = cos(lastSin_tmp);
    Day1_2_2_raspi_DW.systemEnable = 0;
  }

  /* Abs: '<Root>/Abs' incorporates:
   *  Sin: '<Root>/Sine Wave'
   */
  Day1_2_2_raspi_B.Abs = fabs(((Day1_2_2_raspi_DW.lastSin *
    Day1_2_2_raspi_P.SineWave_PCos + Day1_2_2_raspi_DW.lastCos *
    Day1_2_2_raspi_P.SineWave_PSin) * Day1_2_2_raspi_P.SineWave_HCos +
    (Day1_2_2_raspi_DW.lastCos * Day1_2_2_raspi_P.SineWave_PCos -
     Day1_2_2_raspi_DW.lastSin * Day1_2_2_raspi_P.SineWave_PSin) *
    Day1_2_2_raspi_P.SineWave_Hsin) * Day1_2_2_raspi_P.SineWave_Amp +
    Day1_2_2_raspi_P.SineWave_Bias);

  /* MATLABSystem: '<S1>/Digital Write' incorporates:
   *  MATLABSystem: '<Root>/LED'
   */
  lastSin_tmp = rt_roundd_snf(Day1_2_2_raspi_B.Abs);
  if (lastSin_tmp < 256.0) {
    if (lastSin_tmp >= 0.0) {
      tmp = (uint8_T)lastSin_tmp;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  EXT_GPIO_write(4U, tmp);

  /* End of MATLABSystem: '<S1>/Digital Write' */

  /* MATLABSystem: '<Root>/LED' */
  if ((Day1_2_2_raspi_B.Abs == 0.0) || (Day1_2_2_raspi_B.Abs == 1.0)) {
  } else {
    memcpy(&Day1_2_2_raspi_B.c[0], &tmp_0[0], 69U * sizeof(char_T));
    perror(&Day1_2_2_raspi_B.c[0]);
  }

  for (i = 0; i < 5; i++) {
    d[i] = tmp_1[i];
  }

  EXT_LED_setTrigger(0U, &d[0]);
  if (lastSin_tmp < 256.0) {
    if (lastSin_tmp >= 0.0) {
      tmp = (uint8_T)lastSin_tmp;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  EXT_LED_write(0U, tmp);

  /* Update for Sin: '<Root>/Sine Wave' */
  lastSin_tmp = Day1_2_2_raspi_DW.lastSin;
  Day1_2_2_raspi_DW.lastSin = Day1_2_2_raspi_DW.lastSin *
    Day1_2_2_raspi_P.SineWave_HCos + Day1_2_2_raspi_DW.lastCos *
    Day1_2_2_raspi_P.SineWave_Hsin;
  Day1_2_2_raspi_DW.lastCos = Day1_2_2_raspi_DW.lastCos *
    Day1_2_2_raspi_P.SineWave_HCos - lastSin_tmp *
    Day1_2_2_raspi_P.SineWave_Hsin;

  {                                    /* Sample time: [0.1s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Day1_2_2_raspi_M->Timing.taskTime0 =
    ((time_T)(++Day1_2_2_raspi_M->Timing.clockTick0)) *
    Day1_2_2_raspi_M->Timing.stepSize0;
}

/* Model initialize function */
void Day1_2_2_raspi_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Day1_2_2_raspi_M, 10.0);
  Day1_2_2_raspi_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  Day1_2_2_raspi_M->Sizes.checksums[0] = (2172938741U);
  Day1_2_2_raspi_M->Sizes.checksums[1] = (3555456863U);
  Day1_2_2_raspi_M->Sizes.checksums[2] = (3434133523U);
  Day1_2_2_raspi_M->Sizes.checksums[3] = (353830075U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Day1_2_2_raspi_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Day1_2_2_raspi_M->extModeInfo,
      &Day1_2_2_raspi_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Day1_2_2_raspi_M->extModeInfo,
                        Day1_2_2_raspi_M->Sizes.checksums);
    rteiSetTPtr(Day1_2_2_raspi_M->extModeInfo, rtmGetTPtr(Day1_2_2_raspi_M));
  }

  {
    int32_T i;
    char_T b[5];
    static const char_T tmp[5] = "none";

    /* Start for MATLABSystem: '<S1>/Digital Write' */
    Day1_2_2_raspi_DW.obj.matlabCodegenIsDeleted = false;
    Day1_2_2_raspi_DW.obj.isInitialized = 1;
    EXT_GPIO_init(4U, true);
    Day1_2_2_raspi_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/LED' */
    Day1_2_2_raspi_DW.obj_i.matlabCodegenIsDeleted = false;
    Day1_2_2_raspi_DW.obj_i.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      b[i] = tmp[i];
    }

    EXT_LED_setTrigger(0U, &b[0]);
    Day1_2_2_raspi_DW.obj_i.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/LED' */

    /* Enable for Sin: '<Root>/Sine Wave' */
    Day1_2_2_raspi_DW.systemEnable = 1;
  }
}

/* Model terminate function */
void Day1_2_2_raspi_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Digital Write' */
  if (!Day1_2_2_raspi_DW.obj.matlabCodegenIsDeleted) {
    Day1_2_2_raspi_DW.obj.matlabCodegenIsDeleted = true;
    if ((Day1_2_2_raspi_DW.obj.isInitialized == 1) &&
        Day1_2_2_raspi_DW.obj.isSetupComplete) {
      EXT_GPIO_terminate(4U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write' */

  /* Terminate for MATLABSystem: '<Root>/LED' */
  if (!Day1_2_2_raspi_DW.obj_i.matlabCodegenIsDeleted) {
    Day1_2_2_raspi_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
