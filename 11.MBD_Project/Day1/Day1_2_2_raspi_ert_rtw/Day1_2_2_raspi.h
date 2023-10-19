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
 * C/C++ source code generated on : Wed Oct 18 11:30:58 2023
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
#include "MW_gpio.h"
#include "LED.h"
#endif                                 /* Day1_2_2_raspi_COMMON_INCLUDES_ */

#include "Day1_2_2_raspi_types.h"
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
  char_T c[69];
  real_T Abs;                          /* '<Root>/Abs' */
} B_Day1_2_2_raspi_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_raspi_internal_Ra_T obj; /* '<S1>/Digital Write' */
  codertarget_raspi_internal_LE_T obj_i;/* '<Root>/LED' */
  real_T lastSin;                      /* '<Root>/Sine Wave' */
  real_T lastCos;                      /* '<Root>/Sine Wave' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T systemEnable;                /* '<Root>/Sine Wave' */
} DW_Day1_2_2_raspi_T;

/* Parameters (default storage) */
struct P_Day1_2_2_raspi_T_ {
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Hsin;                /* Computed Parameter: SineWave_Hsin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_HCos;                /* Computed Parameter: SineWave_HCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PSin;                /* Computed Parameter: SineWave_PSin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PCos;                /* Computed Parameter: SineWave_PCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Day1_2_2_raspi_T {
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
 * '<S1>'   : 'Day1_2_2_raspi/GPIO Write'
 */
#endif                                 /* RTW_HEADER_Day1_2_2_raspi_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
