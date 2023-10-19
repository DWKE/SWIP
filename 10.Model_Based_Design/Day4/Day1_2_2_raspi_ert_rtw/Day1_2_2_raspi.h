/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Day1_2_2_raspi.h
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

#ifndef RTW_HEADER_Day1_2_2_raspi_h_
#define RTW_HEADER_Day1_2_2_raspi_h_
#ifndef Day1_2_2_raspi_COMMON_INCLUDES_
#define Day1_2_2_raspi_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_pigs.h"
#endif                                 /* Day1_2_2_raspi_COMMON_INCLUDES_ */

#include "Day1_2_2_raspi_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
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
  real_T Output;                       /* '<S1>/Output' */
} B_Day1_2_2_raspi_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  raspi_internal_PWMBlock_Day1__T obj; /* '<Root>/PWM' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_Day1_2_2_raspi_T;

/* Parameters (default storage) */
struct P_Day1_2_2_raspi_T_ {
  real_T RepeatingSequence_rep_seq_y[2];
                                  /* Mask Parameter: RepeatingSequence_rep_seq_y
                                   * Referenced by: '<S1>/Look-Up Table1'
                                   */
  real_T Constant_Value;               /* Expression: period
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T LookUpTable1_bp01Data[2];     /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S1>/Look-Up Table1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Day1_2_2_raspi_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

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
extern P_Day1_2_2_raspi_T Day1_2_2_raspi_P;

/* Block signals (default storage) */
extern B_Day1_2_2_raspi_T Day1_2_2_raspi_B;

/* Block states (default storage) */
extern DW_Day1_2_2_raspi_T Day1_2_2_raspi_DW;

/* Model entry point functions */
extern void Day1_2_2_raspi_initialize(void);
extern void Day1_2_2_raspi_step(void);
extern void Day1_2_2_raspi_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Day1_2_2_raspi_T *const Day1_2_2_raspi_M;
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
 * '<Root>' : 'Day1_2_2_raspi'
 * '<S1>'   : 'Day1_2_2_raspi/Repeating Sequence'
 */
#endif                                 /* RTW_HEADER_Day1_2_2_raspi_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
