/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Day1_4_1_raspi.h
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

#ifndef RTW_HEADER_Day1_4_1_raspi_h_
#define RTW_HEADER_Day1_4_1_raspi_h_
#ifndef Day1_4_1_raspi_COMMON_INCLUDES_
#define Day1_4_1_raspi_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_RaspiEncoder.h"
#include "MW_gpio.h"
#include "MW_pigs.h"
#endif                                 /* Day1_4_1_raspi_COMMON_INCLUDES_ */

#include "Day1_4_1_raspi_types.h"
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
  int32_T Encoder1;                    /* '<Root>/Encoder1' */
  int32_T Encoder;                     /* '<Root>/Encoder' */
} B_Day1_4_1_raspi_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_raspi_internal_Ro_T obj; /* '<Root>/Encoder1' */
  codertarget_raspi_internal_Ro_T obj_d;/* '<Root>/Encoder' */
  raspi_internal_PWMBlock_Day1__T obj_a;/* '<Root>/PWM1' */
  raspi_internal_PWMBlock_Day1__T obj_e;/* '<Root>/PWM' */
  codertarget_raspi_internal_Ra_T obj_o;/* '<S4>/Digital Write' */
  codertarget_raspi_internal_Ra_T obj_oo;/* '<S3>/Digital Write' */
  codertarget_raspi_internal_Ra_T obj_l;/* '<S2>/Digital Write' */
  codertarget_raspi_internal_Ra_T obj_a1;/* '<S1>/Digital Write' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */
} DW_Day1_4_1_raspi_T;

/* Parameters (default storage) */
struct P_Day1_4_1_raspi_T_ {
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<Root>/Encoder'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: -1
                                        * Referenced by: '<Root>/Encoder1'
                                        */
  real_T M1_Start_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/M1_Start'
                                        */
  real_T M1_Direction_Value;           /* Expression: 1
                                        * Referenced by: '<Root>/M1_Direction'
                                        */
  real_T M2_Start_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/M2_Start'
                                        */
  real_T M2_Direction_Value;           /* Expression: 1
                                        * Referenced by: '<Root>/M2_Direction'
                                        */
  real_T Power_Value;                  /* Expression: 0.3
                                        * Referenced by: '<Root>/Power'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Day1_4_1_raspi_T {
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
extern P_Day1_4_1_raspi_T Day1_4_1_raspi_P;

/* Block signals (default storage) */
extern B_Day1_4_1_raspi_T Day1_4_1_raspi_B;

/* Block states (default storage) */
extern DW_Day1_4_1_raspi_T Day1_4_1_raspi_DW;

/* Model entry point functions */
extern void Day1_4_1_raspi_initialize(void);
extern void Day1_4_1_raspi_step(void);
extern void Day1_4_1_raspi_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Day1_4_1_raspi_T *const Day1_4_1_raspi_M;
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
 * '<Root>' : 'Day1_4_1_raspi'
 * '<S1>'   : 'Day1_4_1_raspi/GPIO Write'
 * '<S2>'   : 'Day1_4_1_raspi/GPIO Write1'
 * '<S3>'   : 'Day1_4_1_raspi/GPIO Write2'
 * '<S4>'   : 'Day1_4_1_raspi/GPIO Write3'
 */
#endif                                 /* RTW_HEADER_Day1_4_1_raspi_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
