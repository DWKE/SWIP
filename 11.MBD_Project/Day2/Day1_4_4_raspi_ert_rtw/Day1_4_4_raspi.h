/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Day1_4_4_raspi.h
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

#ifndef RTW_HEADER_Day1_4_4_raspi_h_
#define RTW_HEADER_Day1_4_4_raspi_h_
#ifndef Day1_4_4_raspi_COMMON_INCLUDES_
#define Day1_4_4_raspi_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_gpio.h"
#include "MW_pigs.h"
#include "MW_RaspiEncoder.h"
#endif                                 /* Day1_4_4_raspi_COMMON_INCLUDES_ */

#include "Day1_4_4_raspi_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T DataTypeConversion1;          /* '<Root>/Data Type Conversion1' */
  real_T Diff;                         /* '<S2>/Diff' */
  real_T SpeedControldegs;             /* '<Root>/Speed Control (deg//s)' */
  real_T DataTypeConversion;           /* '<Root>/Data Type Conversion' */
  real_T Diff_a;                       /* '<S1>/Diff' */
  real_T Add1;                         /* '<Root>/Add1' */
  real_T Add3;                         /* '<Root>/Add3' */
  int32_T M2Encoder;                   /* '<Root>/M2 Encoder' */
  int32_T M1Encoder;                   /* '<Root>/M1 Encoder' */
} B_Day1_4_4_raspi_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_raspi_internal_Ro_T obj; /* '<Root>/M2 Encoder' */
  codertarget_raspi_internal_Ro_T obj_d;/* '<Root>/M1 Encoder' */
  raspi_internal_PWMBlock_Day1__T obj_a;/* '<S4>/PWM1' */
  raspi_internal_PWMBlock_Day1__T obj_e;/* '<S3>/PWM' */
  codertarget_raspi_internal_Ra_T obj_o;/* '<S8>/Digital Write' */
  codertarget_raspi_internal_Ra_T obj_oo;/* '<S7>/Digital Write' */
  codertarget_raspi_internal_Ra_T obj_l;/* '<S6>/Digital Write' */
  codertarget_raspi_internal_Ra_T obj_a1;/* '<S5>/Digital Write' */
  real_T UD_DSTATE;                    /* '<S2>/UD' */
  real_T UD_DSTATE_f;                  /* '<S1>/UD' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<Root>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      /* '<Root>/Scope2' */
} DW_Day1_4_4_raspi_T;

/* Parameters (default storage) */
struct P_Day1_4_4_raspi_T_ {
  real_T DiscreteDerivative1_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative1_ICPrevScale
                               * Referenced by: '<S2>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S1>/UD'
                               */
  real_T M1Encoder_SampleTime;         /* Expression: -1
                                        * Referenced by: '<Root>/M1 Encoder'
                                        */
  real_T M2Encoder_SampleTime;         /* Expression: -1
                                        * Referenced by: '<Root>/M2 Encoder'
                                        */
  real_T M2CalibrationGain_Gain;       /* Expression: 360/975
                                        * Referenced by: '<Root>/M2 Calibration Gain'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S2>/TSamp'
                                        */
  real_T SpeedControldegs_Value;       /* Expression: 0
                                        * Referenced by: '<Root>/Speed Control (deg//s)'
                                        */
  real_T M1CalibrationGain_Gain;       /* Expression: 360/975
                                        * Referenced by: '<Root>/M1 Calibration Gain'
                                        */
  real_T TSamp_WtEt_d;                 /* Computed Parameter: TSamp_WtEt_d
                                        * Referenced by: '<S1>/TSamp'
                                        */
  real_T PGain_Gain;                   /* Expression: 0.001
                                        * Referenced by: '<Root>/P Gain'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<Root>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator1'
                                        */
  real_T IGain_Gain;                   /* Expression: 0
                                        * Referenced by: '<Root>/I Gain'
                                        */
  real_T PGain1_Gain;                  /* Expression: 0.001
                                        * Referenced by: '<Root>/P Gain1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<Root>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T IGain1_Gain;                  /* Expression: 0
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

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
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
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Day1_4_4_raspi_T Day1_4_4_raspi_P;

/* Block signals (default storage) */
extern B_Day1_4_4_raspi_T Day1_4_4_raspi_B;

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
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Data Type Duplicate' : Unused code path elimination
 */

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
 * '<S1>'   : 'Day1_4_4_raspi/Discrete Derivative'
 * '<S2>'   : 'Day1_4_4_raspi/Discrete Derivative1'
 * '<S3>'   : 'Day1_4_4_raspi/M1'
 * '<S4>'   : 'Day1_4_4_raspi/M2'
 * '<S5>'   : 'Day1_4_4_raspi/M1/GPIO Write'
 * '<S6>'   : 'Day1_4_4_raspi/M1/GPIO Write1'
 * '<S7>'   : 'Day1_4_4_raspi/M2/GPIO Write2'
 * '<S8>'   : 'Day1_4_4_raspi/M2/GPIO Write3'
 */
#endif                                 /* RTW_HEADER_Day1_4_4_raspi_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
