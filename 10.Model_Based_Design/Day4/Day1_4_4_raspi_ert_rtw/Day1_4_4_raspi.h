/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Day1_4_4_raspi.h
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

#ifndef RTW_HEADER_Day1_4_4_raspi_h_
#define RTW_HEADER_Day1_4_4_raspi_h_
#ifndef Day1_4_4_raspi_COMMON_INCLUDES_
#define Day1_4_4_raspi_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_gpio.h"
#include "MW_pigs.h"
#include "MW_RaspiEncoder.h"
#endif                                 /* Day1_4_4_raspi_COMMON_INCLUDES_ */

#include "Day1_4_4_raspi_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T DataTypeConversion1;          /* '<Root>/Data Type Conversion1' */
  real_T M2CalibrationGain;            /* '<Root>/M2 Calibration Gain' */
  real_T Derivative1;                  /* '<Root>/Derivative1' */
  real_T SpeedControldegs;             /* '<Root>/Speed Control (deg//s)' */
  real_T DataTypeConversion;           /* '<Root>/Data Type Conversion' */
  real_T M1CalibrationGain;            /* '<Root>/M1 Calibration Gain' */
  real_T Derivative;                   /* '<Root>/Derivative' */
  real_T Add;                          /* '<Root>/Add' */
  real_T Add1;                         /* '<Root>/Add1' */
  real_T Add2;                         /* '<Root>/Add2' */
  real_T Add3;                         /* '<Root>/Add3' */
} B_Day1_4_4_raspi_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_raspi_internal_Ro_T obj; /* '<Root>/M2 Encoder' */
  codertarget_raspi_internal_Ro_T obj_d;/* '<Root>/M1 Encoder' */
  raspi_internal_PWMBlock_Day1__T obj_a;/* '<S2>/PWM1' */
  raspi_internal_PWMBlock_Day1__T obj_e;/* '<S1>/PWM' */
  codertarget_raspi_internal_Ra_T obj_o;/* '<S6>/Digital Write' */
  codertarget_raspi_internal_Ra_T obj_oo;/* '<S5>/Digital Write' */
  codertarget_raspi_internal_Ra_T obj_l;/* '<S4>/Digital Write' */
  codertarget_raspi_internal_Ra_T obj_a1;/* '<S3>/Digital Write' */
  real_T TimeStampA;                   /* '<Root>/Derivative1' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative1' */
  real_T TimeStampB;                   /* '<Root>/Derivative1' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative1' */
  real_T TimeStampA_n;                 /* '<Root>/Derivative' */
  real_T LastUAtTimeA_c;               /* '<Root>/Derivative' */
  real_T TimeStampB_p;                 /* '<Root>/Derivative' */
  real_T LastUAtTimeB_c;               /* '<Root>/Derivative' */
  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */
} DW_Day1_4_4_raspi_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
} X_Day1_4_4_raspi_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
} XDot_Day1_4_4_raspi_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
} XDis_Day1_4_4_raspi_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_Day1_4_4_raspi_T_ {
  real_T M1Encoder_SampleTime;         /* Expression: 0.01
                                        * Referenced by: '<Root>/M1 Encoder'
                                        */
  real_T M2Encoder_SampleTime;         /* Expression: -1
                                        * Referenced by: '<Root>/M2 Encoder'
                                        */
  real_T M2CalibrationGain_Gain;       /* Expression: 100*360/970
                                        * Referenced by: '<Root>/M2 Calibration Gain'
                                        */
  real_T SpeedControldegs_Value;       /* Expression: 0
                                        * Referenced by: '<Root>/Speed Control (deg//s)'
                                        */
  real_T M1CalibrationGain_Gain;       /* Expression: 100*360/975
                                        * Referenced by: '<Root>/M1 Calibration Gain'
                                        */
  real_T PGain_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/P Gain'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T IGain_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/I Gain'
                                        */
  real_T PGain1_Gain;                  /* Expression: 1
                                        * Referenced by: '<Root>/P Gain1'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T IGain1_Gain;                  /* Expression: 1
                                        * Referenced by: '<Root>/I Gain1'
                                        */
  real_T MotorStart_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Motor Start'
                                        */
  real_T MotorDirection_Value;         /* Expression: 1
                                        * Referenced by: '<Root>/Motor Direction'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Day1_4_4_raspi_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_Day1_4_4_raspi_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_Day1_4_4_raspi_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Day1_4_4_raspi_T Day1_4_4_raspi_P;

/* Block signals (default storage) */
extern B_Day1_4_4_raspi_T Day1_4_4_raspi_B;

/* Continuous states (default storage) */
extern X_Day1_4_4_raspi_T Day1_4_4_raspi_X;

/* Block states (default storage) */
extern DW_Day1_4_4_raspi_T Day1_4_4_raspi_DW;

/* Model entry point functions */
extern void Day1_4_4_raspi_initialize(void);
extern void Day1_4_4_raspi_step(void);
extern void Day1_4_4_raspi_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Day1_4_4_raspi_T *const Day1_4_4_raspi_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Day1_4_4_raspi'
 * '<S1>'   : 'Day1_4_4_raspi/M1'
 * '<S2>'   : 'Day1_4_4_raspi/M2'
 * '<S3>'   : 'Day1_4_4_raspi/M1/GPIO Write'
 * '<S4>'   : 'Day1_4_4_raspi/M1/GPIO Write1'
 * '<S5>'   : 'Day1_4_4_raspi/M2/GPIO Write2'
 * '<S6>'   : 'Day1_4_4_raspi/M2/GPIO Write3'
 */
#endif                                 /* RTW_HEADER_Day1_4_4_raspi_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
