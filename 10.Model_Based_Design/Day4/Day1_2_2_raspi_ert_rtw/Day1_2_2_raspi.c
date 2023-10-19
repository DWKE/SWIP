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
 * C/C++ source code generated on : Wed Oct 18 13:28:04 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Day1_2_2_raspi.h"
#include "rtwtypes.h"
#include "Day1_2_2_raspi_private.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <float.h>

/* Block signals (default storage) */
B_Day1_2_2_raspi_T Day1_2_2_raspi_B;

/* Block states (default storage) */
DW_Day1_2_2_raspi_T Day1_2_2_raspi_DW;

/* Real-time model */
static RT_MODEL_Day1_2_2_raspi_T Day1_2_2_raspi_M_;
RT_MODEL_Day1_2_2_raspi_T *const Day1_2_2_raspi_M = &Day1_2_2_raspi_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      q = ceil(u1);
    } else {
      q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != q)) {
      q = fabs(u0 / u1);
      if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void Day1_2_2_raspi_step(void)
{
  real_T y;

  /* SignalConversion: '<S1>/Output' incorporates:
   *  Clock: '<S1>/Clock'
   *  Constant: '<S1>/Constant'
   *  Lookup_n-D: '<S1>/Look-Up Table1'
   *  Math: '<S1>/Math Function'
   */
  Day1_2_2_raspi_B.Output = look1_binlxpw(rt_remd_snf(Day1_2_2_raspi_M->
    Timing.t[0], Day1_2_2_raspi_P.Constant_Value),
    Day1_2_2_raspi_P.LookUpTable1_bp01Data,
    Day1_2_2_raspi_P.RepeatingSequence_rep_seq_y, 1U);

  /* MATLABSystem: '<Root>/PWM' */
  if (Day1_2_2_raspi_B.Output <= 1.0) {
    y = Day1_2_2_raspi_B.Output;
  } else {
    y = 1.0;
  }

  if (!(y >= 0.0)) {
    y = 0.0;
  }

  EXT_PWMBlock_setDutyCycle(Day1_2_2_raspi_DW.obj.PinNumber, y);

  /* End of MATLABSystem: '<Root>/PWM' */
  {                                    /* Sample time: [0.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      Day1_2_2_raspi_M->Timing.t[0];

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  {                                    /* Sample time: [0.2s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((Day1_2_2_raspi_M->Timing.clockTick1) * 0.2);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Day1_2_2_raspi_M->Timing.t[0] =
    ((time_T)(++Day1_2_2_raspi_M->Timing.clockTick0)) *
    Day1_2_2_raspi_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.2, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Day1_2_2_raspi_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Day1_2_2_raspi_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Day1_2_2_raspi_M->solverInfo,
                          &Day1_2_2_raspi_M->Timing.simTimeStep);
    rtsiSetTPtr(&Day1_2_2_raspi_M->solverInfo, &rtmGetTPtr(Day1_2_2_raspi_M));
    rtsiSetStepSizePtr(&Day1_2_2_raspi_M->solverInfo,
                       &Day1_2_2_raspi_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Day1_2_2_raspi_M->solverInfo, (&rtmGetErrorStatus
      (Day1_2_2_raspi_M)));
    rtsiSetRTModelPtr(&Day1_2_2_raspi_M->solverInfo, Day1_2_2_raspi_M);
  }

  rtsiSetSimTimeStep(&Day1_2_2_raspi_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Day1_2_2_raspi_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Day1_2_2_raspi_M, &Day1_2_2_raspi_M->Timing.tArray[0]);
  rtmSetTFinal(Day1_2_2_raspi_M, -1);
  Day1_2_2_raspi_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  Day1_2_2_raspi_M->Sizes.checksums[0] = (1717290089U);
  Day1_2_2_raspi_M->Sizes.checksums[1] = (3791224778U);
  Day1_2_2_raspi_M->Sizes.checksums[2] = (2056877958U);
  Day1_2_2_raspi_M->Sizes.checksums[3] = (1257892076U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Day1_2_2_raspi_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Day1_2_2_raspi_M->extModeInfo,
      &Day1_2_2_raspi_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Day1_2_2_raspi_M->extModeInfo,
                        Day1_2_2_raspi_M->Sizes.checksums);
    rteiSetTPtr(Day1_2_2_raspi_M->extModeInfo, rtmGetTPtr(Day1_2_2_raspi_M));
  }

  {
    int32_T ret;
    char_T b[45];
    static const char_T tmp[45] =
      "Unable to configure pin %u for PWM output.\\n";

    /* Start for MATLABSystem: '<Root>/PWM' */
    Day1_2_2_raspi_DW.obj.matlabCodegenIsDeleted = false;
    Day1_2_2_raspi_DW.obj.isInitialized = 1;
    Day1_2_2_raspi_DW.obj.PinNumber = 18U;
    ret = EXT_PWMBlock_init(Day1_2_2_raspi_DW.obj.PinNumber, 500U, 0.0);
    if (ret != 0) {
      for (ret = 0; ret < 45; ret++) {
        b[ret] = tmp[ret];
      }

      printf(&b[0], Day1_2_2_raspi_DW.obj.PinNumber);
    }

    Day1_2_2_raspi_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/PWM' */
  }
}

/* Model terminate function */
void Day1_2_2_raspi_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!Day1_2_2_raspi_DW.obj.matlabCodegenIsDeleted) {
    Day1_2_2_raspi_DW.obj.matlabCodegenIsDeleted = true;
    if ((Day1_2_2_raspi_DW.obj.isInitialized == 1) &&
        Day1_2_2_raspi_DW.obj.isSetupComplete) {
      EXT_PWMBlock_terminate(Day1_2_2_raspi_DW.obj.PinNumber);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
