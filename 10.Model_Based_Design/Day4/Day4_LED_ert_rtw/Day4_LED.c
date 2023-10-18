/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Day4_LED.c
 *
 * Code generated for Simulink model 'Day4_LED'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Oct 17 14:01:56 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Day4_LED.h"
#include "rtwtypes.h"
#include "Day4_LED_private.h"

/* Block signals (default storage) */
B_Day4_LED_T Day4_LED_B;

/* Block states (default storage) */
DW_Day4_LED_T Day4_LED_DW;

/* Real-time model */
static RT_MODEL_Day4_LED_T Day4_LED_M_;
RT_MODEL_Day4_LED_T *const Day4_LED_M = &Day4_LED_M_;

/* Model step function */
void Day4_LED_step(void)
{
  int32_T i;
  char_T b[5];
  static const char_T tmp[5] = "none";

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  Day4_LED_B.PulseGenerator = (Day4_LED_DW.clockTickCounter <
    Day4_LED_P.PulseGenerator_Duty) && (Day4_LED_DW.clockTickCounter >= 0) ?
    Day4_LED_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  if (Day4_LED_DW.clockTickCounter >= Day4_LED_P.PulseGenerator_Period - 1.0) {
    Day4_LED_DW.clockTickCounter = 0;
  } else {
    Day4_LED_DW.clockTickCounter++;
  }

  /* MATLABSystem: '<Root>/LED' incorporates:
   *  DataTypeConversion: '<Root>/Cast To Boolean'
   */
  for (i = 0; i < 5; i++) {
    b[i] = tmp[i];
  }

  EXT_LED_setTrigger(0U, &b[0]);
  EXT_LED_write(0U, (uint8_T)(Day4_LED_B.PulseGenerator != 0.0));

  /* End of MATLABSystem: '<Root>/LED' */
  {                                    /* Sample time: [0.5s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Day4_LED_M->Timing.taskTime0 =
    ((time_T)(++Day4_LED_M->Timing.clockTick0)) * Day4_LED_M->Timing.stepSize0;
}

/* Model initialize function */
void Day4_LED_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Day4_LED_M, 10.0);
  Day4_LED_M->Timing.stepSize0 = 0.5;

  /* External mode info */
  Day4_LED_M->Sizes.checksums[0] = (2900677188U);
  Day4_LED_M->Sizes.checksums[1] = (2951134350U);
  Day4_LED_M->Sizes.checksums[2] = (4191564855U);
  Day4_LED_M->Sizes.checksums[3] = (4274141700U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Day4_LED_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Day4_LED_M->extModeInfo,
      &Day4_LED_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Day4_LED_M->extModeInfo, Day4_LED_M->Sizes.checksums);
    rteiSetTPtr(Day4_LED_M->extModeInfo, rtmGetTPtr(Day4_LED_M));
  }

  {
    int32_T i;
    char_T b[5];
    static const char_T tmp[5] = "none";

    /* Start for MATLABSystem: '<Root>/LED' */
    Day4_LED_DW.obj.matlabCodegenIsDeleted = false;
    Day4_LED_DW.obj.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      b[i] = tmp[i];
    }

    EXT_LED_setTrigger(0U, &b[0]);
    Day4_LED_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/LED' */
  }
}

/* Model terminate function */
void Day4_LED_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/LED' */
  if (!Day4_LED_DW.obj.matlabCodegenIsDeleted) {
    Day4_LED_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/LED' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
