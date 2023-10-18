/*
 * Day3_4.c
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "Day3_4".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Oct 16 15:06:25 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Day3_4.h"
#include "rtwtypes.h"
#include "Day3_4_private.h"
#include <string.h>
#include "rt_nonfinite.h"

/* Block states (default storage) */
DW_Day3_4_T Day3_4_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Day3_4_T Day3_4_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Day3_4_T Day3_4_Y;

/* Real-time model */
static RT_MODEL_Day3_4_T Day3_4_M_;
RT_MODEL_Day3_4_T *const Day3_4_M = &Day3_4_M_;

/* Model step function */
void Day3_4_step(void)
{
  {
    real_T tmp;
    real_T *lastU;

    /* Derivative: '<Root>/Derivative' */
    tmp = Day3_4_M->Timing.t[0];
    if ((Day3_4_DW.TimeStampA >= tmp) && (Day3_4_DW.TimeStampB >= tmp)) {
      /* Outport: '<Root>/Output' */
      Day3_4_Y.Output = 0.0;
    } else {
      real_T lastTime;
      lastTime = Day3_4_DW.TimeStampA;
      lastU = &Day3_4_DW.LastUAtTimeA;
      if (Day3_4_DW.TimeStampA < Day3_4_DW.TimeStampB) {
        if (Day3_4_DW.TimeStampB < tmp) {
          lastTime = Day3_4_DW.TimeStampB;
          lastU = &Day3_4_DW.LastUAtTimeB;
        }
      } else if (Day3_4_DW.TimeStampA >= tmp) {
        lastTime = Day3_4_DW.TimeStampB;
        lastU = &Day3_4_DW.LastUAtTimeB;
      }

      /* Outport: '<Root>/Output' incorporates:
       *  Inport: '<Root>/Input'
       */
      Day3_4_Y.Output = (Day3_4_U.Input - *lastU) / (tmp - lastTime);
    }

    /* End of Derivative: '<Root>/Derivative' */
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(Day3_4_M->rtwLogInfo, (Day3_4_M->Timing.t));

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative' incorporates:
     *  Inport: '<Root>/Input'
     */
    if (Day3_4_DW.TimeStampA == (rtInf)) {
      Day3_4_DW.TimeStampA = Day3_4_M->Timing.t[0];
      lastU = &Day3_4_DW.LastUAtTimeA;
    } else if (Day3_4_DW.TimeStampB == (rtInf)) {
      Day3_4_DW.TimeStampB = Day3_4_M->Timing.t[0];
      lastU = &Day3_4_DW.LastUAtTimeB;
    } else if (Day3_4_DW.TimeStampA < Day3_4_DW.TimeStampB) {
      Day3_4_DW.TimeStampA = Day3_4_M->Timing.t[0];
      lastU = &Day3_4_DW.LastUAtTimeA;
    } else {
      Day3_4_DW.TimeStampB = Day3_4_M->Timing.t[0];
      lastU = &Day3_4_DW.LastUAtTimeB;
    }

    *lastU = Day3_4_U.Input;

    /* End of Update for Derivative: '<Root>/Derivative' */
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Day3_4_M)!=-1) &&
        !((rtmGetTFinal(Day3_4_M)-Day3_4_M->Timing.t[0]) > Day3_4_M->Timing.t[0]
          * (DBL_EPSILON))) {
      rtmSetErrorStatus(Day3_4_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Day3_4_M->Timing.clockTick0)) {
    ++Day3_4_M->Timing.clockTickH0;
  }

  Day3_4_M->Timing.t[0] = Day3_4_M->Timing.clockTick0 *
    Day3_4_M->Timing.stepSize0 + Day3_4_M->Timing.clockTickH0 *
    Day3_4_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    Day3_4_M->Timing.clockTick1++;
    if (!Day3_4_M->Timing.clockTick1) {
      Day3_4_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void Day3_4_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Day3_4_M, 0,
                sizeof(RT_MODEL_Day3_4_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Day3_4_M->solverInfo, &Day3_4_M->Timing.simTimeStep);
    rtsiSetTPtr(&Day3_4_M->solverInfo, &rtmGetTPtr(Day3_4_M));
    rtsiSetStepSizePtr(&Day3_4_M->solverInfo, &Day3_4_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Day3_4_M->solverInfo, (&rtmGetErrorStatus(Day3_4_M)));
    rtsiSetRTModelPtr(&Day3_4_M->solverInfo, Day3_4_M);
  }

  rtsiSetSimTimeStep(&Day3_4_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Day3_4_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Day3_4_M, &Day3_4_M->Timing.tArray[0]);
  rtmSetTFinal(Day3_4_M, -1);
  Day3_4_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Day3_4_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Day3_4_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Day3_4_M->rtwLogInfo, (NULL));
    rtliSetLogT(Day3_4_M->rtwLogInfo, "tout");
    rtliSetLogX(Day3_4_M->rtwLogInfo, "");
    rtliSetLogXFinal(Day3_4_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Day3_4_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Day3_4_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Day3_4_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Day3_4_M->rtwLogInfo, 1);
    rtliSetLogY(Day3_4_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Day3_4_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Day3_4_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&Day3_4_DW, 0,
                sizeof(DW_Day3_4_T));

  /* external inputs */
  Day3_4_U.Input = 0.0;

  /* external outputs */
  Day3_4_Y.Output = 0.0;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Day3_4_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Day3_4_M), Day3_4_M->Timing.stepSize0, (&rtmGetErrorStatus(Day3_4_M)));

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  Day3_4_DW.TimeStampA = (rtInf);
  Day3_4_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void Day3_4_terminate(void)
{
  /* (no terminate code required) */
}
