/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Day1_4_4_raspi.c
 *
 * Code generated for Simulink model 'Day1_4_4_raspi'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Oct 19 10:22:55 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Day1_4_4_raspi.h"
#include "rtwtypes.h"
#include "Day1_4_4_raspi_private.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_Day1_4_4_raspi_T Day1_4_4_raspi_B;

/* Continuous states */
X_Day1_4_4_raspi_T Day1_4_4_raspi_X;

/* Block states (default storage) */
DW_Day1_4_4_raspi_T Day1_4_4_raspi_DW;

/* Real-time model */
static RT_MODEL_Day1_4_4_raspi_T Day1_4_4_raspi_M_;
RT_MODEL_Day1_4_4_raspi_T *const Day1_4_4_raspi_M = &Day1_4_4_raspi_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Day1_4_4_raspi_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Day1_4_4_raspi_step();
  Day1_4_4_raspi_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Day1_4_4_raspi_step();
  Day1_4_4_raspi_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void Day1_4_4_raspi_step(void)
{
  if (rtmIsMajorTimeStep(Day1_4_4_raspi_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Day1_4_4_raspi_M->solverInfo,
                          ((Day1_4_4_raspi_M->Timing.clockTick0+1)*
      Day1_4_4_raspi_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Day1_4_4_raspi_M)) {
    Day1_4_4_raspi_M->Timing.t[0] = rtsiGetT(&Day1_4_4_raspi_M->solverInfo);
  }

  {
    real_T lastTime;
    real_T y;
    real_T *lastU;
    int32_T rtb_M2Encoder_0;

    /* MATLABSystem: '<Root>/M2 Encoder' */
    if (Day1_4_4_raspi_DW.obj.SampleTime !=
        Day1_4_4_raspi_P.M2Encoder_SampleTime) {
      Day1_4_4_raspi_DW.obj.SampleTime = Day1_4_4_raspi_P.M2Encoder_SampleTime;
    }

    if (Day1_4_4_raspi_DW.obj.TunablePropsChanged) {
      Day1_4_4_raspi_DW.obj.TunablePropsChanged = false;
    }

    MW_RaspiEncoderRead(Day1_4_4_raspi_DW.obj.Index, &rtb_M2Encoder_0);

    /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
     *  MATLABSystem: '<Root>/M2 Encoder'
     */
    Day1_4_4_raspi_B.DataTypeConversion1 = rtb_M2Encoder_0;

    /* Gain: '<Root>/M2 Calibration Gain' */
    Day1_4_4_raspi_B.M2CalibrationGain = Day1_4_4_raspi_P.M2CalibrationGain_Gain
      * Day1_4_4_raspi_B.DataTypeConversion1;

    /* Derivative: '<Root>/Derivative1' incorporates:
     *  Derivative: '<Root>/Derivative'
     */
    y = Day1_4_4_raspi_M->Timing.t[0];
    if ((Day1_4_4_raspi_DW.TimeStampA >= y) && (Day1_4_4_raspi_DW.TimeStampB >=
         y)) {
      /* Derivative: '<Root>/Derivative1' */
      Day1_4_4_raspi_B.Derivative1 = 0.0;
    } else {
      lastTime = Day1_4_4_raspi_DW.TimeStampA;
      lastU = &Day1_4_4_raspi_DW.LastUAtTimeA;
      if (Day1_4_4_raspi_DW.TimeStampA < Day1_4_4_raspi_DW.TimeStampB) {
        if (Day1_4_4_raspi_DW.TimeStampB < y) {
          lastTime = Day1_4_4_raspi_DW.TimeStampB;
          lastU = &Day1_4_4_raspi_DW.LastUAtTimeB;
        }
      } else if (Day1_4_4_raspi_DW.TimeStampA >= y) {
        lastTime = Day1_4_4_raspi_DW.TimeStampB;
        lastU = &Day1_4_4_raspi_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative1' */
      Day1_4_4_raspi_B.Derivative1 = (Day1_4_4_raspi_B.M2CalibrationGain -
        *lastU) / (y - lastTime);
    }

    /* End of Derivative: '<Root>/Derivative1' */
    if (rtmIsMajorTimeStep(Day1_4_4_raspi_M)) {
      /* Constant: '<Root>/Speed Control (deg//s)' */
      Day1_4_4_raspi_B.SpeedControldegs =
        Day1_4_4_raspi_P.SpeedControldegs_Value;

      /* MATLABSystem: '<Root>/M1 Encoder' */
      if (Day1_4_4_raspi_DW.obj_d.SampleTime !=
          Day1_4_4_raspi_P.M1Encoder_SampleTime) {
        Day1_4_4_raspi_DW.obj_d.SampleTime =
          Day1_4_4_raspi_P.M1Encoder_SampleTime;
      }

      if (Day1_4_4_raspi_DW.obj_d.TunablePropsChanged) {
        Day1_4_4_raspi_DW.obj_d.TunablePropsChanged = false;
      }

      MW_RaspiEncoderRead(Day1_4_4_raspi_DW.obj_d.Index, &rtb_M2Encoder_0);
      MW_RaspiEncoderReset(Day1_4_4_raspi_DW.obj_d.Index);

      /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
       *  MATLABSystem: '<Root>/M1 Encoder'
       */
      Day1_4_4_raspi_B.DataTypeConversion = rtb_M2Encoder_0;

      /* Gain: '<Root>/M1 Calibration Gain' */
      Day1_4_4_raspi_B.M1CalibrationGain =
        Day1_4_4_raspi_P.M1CalibrationGain_Gain *
        Day1_4_4_raspi_B.DataTypeConversion;
    }

    /* Derivative: '<Root>/Derivative' */
    if ((Day1_4_4_raspi_DW.TimeStampA_n >= y) && (Day1_4_4_raspi_DW.TimeStampB_p
         >= y)) {
      /* Derivative: '<Root>/Derivative' */
      Day1_4_4_raspi_B.Derivative = 0.0;
    } else {
      lastTime = Day1_4_4_raspi_DW.TimeStampA_n;
      lastU = &Day1_4_4_raspi_DW.LastUAtTimeA_c;
      if (Day1_4_4_raspi_DW.TimeStampA_n < Day1_4_4_raspi_DW.TimeStampB_p) {
        if (Day1_4_4_raspi_DW.TimeStampB_p < y) {
          lastTime = Day1_4_4_raspi_DW.TimeStampB_p;
          lastU = &Day1_4_4_raspi_DW.LastUAtTimeB_c;
        }
      } else if (Day1_4_4_raspi_DW.TimeStampA_n >= y) {
        lastTime = Day1_4_4_raspi_DW.TimeStampB_p;
        lastU = &Day1_4_4_raspi_DW.LastUAtTimeB_c;
      }

      /* Derivative: '<Root>/Derivative' */
      Day1_4_4_raspi_B.Derivative = (Day1_4_4_raspi_B.M1CalibrationGain - *lastU)
        / (y - lastTime);
    }

    if (rtmIsMajorTimeStep(Day1_4_4_raspi_M)) {
    }

    /* Sum: '<Root>/Add' */
    Day1_4_4_raspi_B.Add = Day1_4_4_raspi_B.SpeedControldegs -
      Day1_4_4_raspi_B.Derivative;

    /* Sum: '<Root>/Add1' incorporates:
     *  Gain: '<Root>/I Gain'
     *  Gain: '<Root>/P Gain'
     *  Integrator: '<Root>/Integrator'
     */
    Day1_4_4_raspi_B.Add1 = Day1_4_4_raspi_P.PGain_Gain * Day1_4_4_raspi_B.Add +
      Day1_4_4_raspi_P.IGain_Gain * Day1_4_4_raspi_X.Integrator_CSTATE;

    /* MATLABSystem: '<S1>/PWM' */
    if (Day1_4_4_raspi_B.Add1 <= 1.0) {
      y = Day1_4_4_raspi_B.Add1;
    } else {
      y = 1.0;
    }

    if (!(y >= 0.0)) {
      y = 0.0;
    }

    EXT_PWMBlock_setDutyCycle(Day1_4_4_raspi_DW.obj_e.PinNumber, y);

    /* End of MATLABSystem: '<S1>/PWM' */

    /* Sum: '<Root>/Add2' */
    Day1_4_4_raspi_B.Add2 = Day1_4_4_raspi_B.SpeedControldegs -
      Day1_4_4_raspi_B.Derivative1;

    /* Sum: '<Root>/Add3' incorporates:
     *  Gain: '<Root>/I Gain1'
     *  Gain: '<Root>/P Gain1'
     *  Integrator: '<Root>/Integrator1'
     */
    Day1_4_4_raspi_B.Add3 = Day1_4_4_raspi_P.PGain1_Gain * Day1_4_4_raspi_B.Add2
      + Day1_4_4_raspi_P.IGain1_Gain * Day1_4_4_raspi_X.Integrator1_CSTATE;
    if (rtmIsMajorTimeStep(Day1_4_4_raspi_M)) {
    }

    /* MATLABSystem: '<S2>/PWM1' */
    if (Day1_4_4_raspi_B.Add3 <= 1.0) {
      y = Day1_4_4_raspi_B.Add3;
    } else {
      y = 1.0;
    }

    if (!(y >= 0.0)) {
      y = 0.0;
    }

    EXT_PWMBlock_setDutyCycle(Day1_4_4_raspi_DW.obj_a.PinNumber, y);

    /* End of MATLABSystem: '<S2>/PWM1' */
    if (rtmIsMajorTimeStep(Day1_4_4_raspi_M)) {
      /* MATLABSystem: '<S3>/Digital Write' incorporates:
       *  Constant: '<Root>/Motor Direction'
       *  Constant: '<Root>/Motor Start'
       *  Logic: '<S1>/AND'
       */
      EXT_GPIO_write(15U, (uint8_T)((Day1_4_4_raspi_P.MotorStart_Value != 0.0) &&
        (Day1_4_4_raspi_P.MotorDirection_Value != 0.0)));

      /* MATLABSystem: '<S4>/Digital Write' incorporates:
       *  Constant: '<Root>/Motor Direction'
       *  Constant: '<Root>/Motor Start'
       *  Logic: '<S1>/AND1'
       *  Logic: '<S1>/NOT'
       */
      EXT_GPIO_write(14U, (uint8_T)((Day1_4_4_raspi_P.MotorStart_Value != 0.0) &&
        (!(Day1_4_4_raspi_P.MotorDirection_Value != 0.0))));

      /* MATLABSystem: '<S5>/Digital Write' incorporates:
       *  Constant: '<Root>/Motor Direction'
       *  Constant: '<Root>/Motor Start'
       *  Logic: '<S2>/AND2'
       */
      EXT_GPIO_write(13U, (uint8_T)((Day1_4_4_raspi_P.MotorStart_Value != 0.0) &&
        (Day1_4_4_raspi_P.MotorDirection_Value != 0.0)));

      /* MATLABSystem: '<S6>/Digital Write' incorporates:
       *  Constant: '<Root>/Motor Direction'
       *  Constant: '<Root>/Motor Start'
       *  Logic: '<S2>/AND3'
       *  Logic: '<S2>/NOT1'
       */
      EXT_GPIO_write(6U, (uint8_T)((Day1_4_4_raspi_P.MotorStart_Value != 0.0) &&
        (!(Day1_4_4_raspi_P.MotorDirection_Value != 0.0))));
    }
  }

  if (rtmIsMajorTimeStep(Day1_4_4_raspi_M)) {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative1' */
    if (Day1_4_4_raspi_DW.TimeStampA == (rtInf)) {
      Day1_4_4_raspi_DW.TimeStampA = Day1_4_4_raspi_M->Timing.t[0];
      lastU = &Day1_4_4_raspi_DW.LastUAtTimeA;
    } else if (Day1_4_4_raspi_DW.TimeStampB == (rtInf)) {
      Day1_4_4_raspi_DW.TimeStampB = Day1_4_4_raspi_M->Timing.t[0];
      lastU = &Day1_4_4_raspi_DW.LastUAtTimeB;
    } else if (Day1_4_4_raspi_DW.TimeStampA < Day1_4_4_raspi_DW.TimeStampB) {
      Day1_4_4_raspi_DW.TimeStampA = Day1_4_4_raspi_M->Timing.t[0];
      lastU = &Day1_4_4_raspi_DW.LastUAtTimeA;
    } else {
      Day1_4_4_raspi_DW.TimeStampB = Day1_4_4_raspi_M->Timing.t[0];
      lastU = &Day1_4_4_raspi_DW.LastUAtTimeB;
    }

    *lastU = Day1_4_4_raspi_B.M2CalibrationGain;

    /* End of Update for Derivative: '<Root>/Derivative1' */

    /* Update for Derivative: '<Root>/Derivative' */
    if (Day1_4_4_raspi_DW.TimeStampA_n == (rtInf)) {
      Day1_4_4_raspi_DW.TimeStampA_n = Day1_4_4_raspi_M->Timing.t[0];
      lastU = &Day1_4_4_raspi_DW.LastUAtTimeA_c;
    } else if (Day1_4_4_raspi_DW.TimeStampB_p == (rtInf)) {
      Day1_4_4_raspi_DW.TimeStampB_p = Day1_4_4_raspi_M->Timing.t[0];
      lastU = &Day1_4_4_raspi_DW.LastUAtTimeB_c;
    } else if (Day1_4_4_raspi_DW.TimeStampA_n < Day1_4_4_raspi_DW.TimeStampB_p)
    {
      Day1_4_4_raspi_DW.TimeStampA_n = Day1_4_4_raspi_M->Timing.t[0];
      lastU = &Day1_4_4_raspi_DW.LastUAtTimeA_c;
    } else {
      Day1_4_4_raspi_DW.TimeStampB_p = Day1_4_4_raspi_M->Timing.t[0];
      lastU = &Day1_4_4_raspi_DW.LastUAtTimeB_c;
    }

    *lastU = Day1_4_4_raspi_B.M1CalibrationGain;

    /* End of Update for Derivative: '<Root>/Derivative' */
    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        Day1_4_4_raspi_M->Timing.t[0];

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(Day1_4_4_raspi_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        ((Day1_4_4_raspi_M->Timing.clockTick1) * 0.01);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Day1_4_4_raspi_M)) {
    rt_ertODEUpdateContinuousStates(&Day1_4_4_raspi_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++Day1_4_4_raspi_M->Timing.clockTick0;
    Day1_4_4_raspi_M->Timing.t[0] = rtsiGetSolverStopTime
      (&Day1_4_4_raspi_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      Day1_4_4_raspi_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Day1_4_4_raspi_derivatives(void)
{
  XDot_Day1_4_4_raspi_T *_rtXdot;
  _rtXdot = ((XDot_Day1_4_4_raspi_T *) Day1_4_4_raspi_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = Day1_4_4_raspi_B.Add;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Day1_4_4_raspi_B.Add2;
}

/* Model initialize function */
void Day1_4_4_raspi_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Day1_4_4_raspi_M->solverInfo,
                          &Day1_4_4_raspi_M->Timing.simTimeStep);
    rtsiSetTPtr(&Day1_4_4_raspi_M->solverInfo, &rtmGetTPtr(Day1_4_4_raspi_M));
    rtsiSetStepSizePtr(&Day1_4_4_raspi_M->solverInfo,
                       &Day1_4_4_raspi_M->Timing.stepSize0);
    rtsiSetdXPtr(&Day1_4_4_raspi_M->solverInfo, &Day1_4_4_raspi_M->derivs);
    rtsiSetContStatesPtr(&Day1_4_4_raspi_M->solverInfo, (real_T **)
                         &Day1_4_4_raspi_M->contStates);
    rtsiSetNumContStatesPtr(&Day1_4_4_raspi_M->solverInfo,
      &Day1_4_4_raspi_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Day1_4_4_raspi_M->solverInfo,
      &Day1_4_4_raspi_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Day1_4_4_raspi_M->solverInfo,
      &Day1_4_4_raspi_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Day1_4_4_raspi_M->solverInfo,
      &Day1_4_4_raspi_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Day1_4_4_raspi_M->solverInfo, (&rtmGetErrorStatus
      (Day1_4_4_raspi_M)));
    rtsiSetRTModelPtr(&Day1_4_4_raspi_M->solverInfo, Day1_4_4_raspi_M);
  }

  rtsiSetSimTimeStep(&Day1_4_4_raspi_M->solverInfo, MAJOR_TIME_STEP);
  Day1_4_4_raspi_M->intgData.y = Day1_4_4_raspi_M->odeY;
  Day1_4_4_raspi_M->intgData.f[0] = Day1_4_4_raspi_M->odeF[0];
  Day1_4_4_raspi_M->intgData.f[1] = Day1_4_4_raspi_M->odeF[1];
  Day1_4_4_raspi_M->intgData.f[2] = Day1_4_4_raspi_M->odeF[2];
  Day1_4_4_raspi_M->contStates = ((X_Day1_4_4_raspi_T *) &Day1_4_4_raspi_X);
  rtsiSetSolverData(&Day1_4_4_raspi_M->solverInfo, (void *)
                    &Day1_4_4_raspi_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&Day1_4_4_raspi_M->solverInfo, false);
  rtsiSetSolverName(&Day1_4_4_raspi_M->solverInfo,"ode3");
  rtmSetTPtr(Day1_4_4_raspi_M, &Day1_4_4_raspi_M->Timing.tArray[0]);
  rtmSetTFinal(Day1_4_4_raspi_M, -1);
  Day1_4_4_raspi_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Day1_4_4_raspi_M->Sizes.checksums[0] = (3130290851U);
  Day1_4_4_raspi_M->Sizes.checksums[1] = (71767718U);
  Day1_4_4_raspi_M->Sizes.checksums[2] = (369534762U);
  Day1_4_4_raspi_M->Sizes.checksums[3] = (1588550802U);

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

    /* InitializeConditions for Derivative: '<Root>/Derivative1' */
    Day1_4_4_raspi_DW.TimeStampA = (rtInf);
    Day1_4_4_raspi_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<Root>/Derivative' */
    Day1_4_4_raspi_DW.TimeStampA_n = (rtInf);
    Day1_4_4_raspi_DW.TimeStampB_p = (rtInf);

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    Day1_4_4_raspi_X.Integrator_CSTATE = Day1_4_4_raspi_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator1' */
    Day1_4_4_raspi_X.Integrator1_CSTATE = Day1_4_4_raspi_P.Integrator1_IC;

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

    /* Start for MATLABSystem: '<S1>/PWM' */
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

    /* End of Start for MATLABSystem: '<S1>/PWM' */

    /* Start for MATLABSystem: '<S2>/PWM1' */
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

    /* End of Start for MATLABSystem: '<S2>/PWM1' */

    /* Start for MATLABSystem: '<S3>/Digital Write' */
    Day1_4_4_raspi_DW.obj_a1.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj_a1.isInitialized = 1;
    EXT_GPIO_init(15U, true);
    Day1_4_4_raspi_DW.obj_a1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write' */
    Day1_4_4_raspi_DW.obj_l.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj_l.isInitialized = 1;
    EXT_GPIO_init(14U, true);
    Day1_4_4_raspi_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/Digital Write' */
    Day1_4_4_raspi_DW.obj_oo.matlabCodegenIsDeleted = false;
    Day1_4_4_raspi_DW.obj_oo.isInitialized = 1;
    EXT_GPIO_init(13U, true);
    Day1_4_4_raspi_DW.obj_oo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write' */
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
  /* Terminate for MATLABSystem: '<S1>/PWM' */
  if (!Day1_4_4_raspi_DW.obj_e.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_e.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_e.isSetupComplete) {
      EXT_PWMBlock_terminate(Day1_4_4_raspi_DW.obj_e.PinNumber);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */

  /* Terminate for MATLABSystem: '<S2>/PWM1' */
  if (!Day1_4_4_raspi_DW.obj_a.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_a.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_a.isSetupComplete) {
      EXT_PWMBlock_terminate(Day1_4_4_raspi_DW.obj_a.PinNumber);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM1' */
  /* Terminate for MATLABSystem: '<S3>/Digital Write' */
  if (!Day1_4_4_raspi_DW.obj_a1.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_a1.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_a1.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_a1.isSetupComplete) {
      EXT_GPIO_terminate(15U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Digital Write' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write' */
  if (!Day1_4_4_raspi_DW.obj_l.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_l.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_l.isSetupComplete) {
      EXT_GPIO_terminate(14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write' */

  /* Terminate for MATLABSystem: '<S5>/Digital Write' */
  if (!Day1_4_4_raspi_DW.obj_oo.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_oo.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_oo.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_oo.isSetupComplete) {
      EXT_GPIO_terminate(13U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write' */
  if (!Day1_4_4_raspi_DW.obj_o.matlabCodegenIsDeleted) {
    Day1_4_4_raspi_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Day1_4_4_raspi_DW.obj_o.isInitialized == 1) &&
        Day1_4_4_raspi_DW.obj_o.isSetupComplete) {
      EXT_GPIO_terminate(6U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
