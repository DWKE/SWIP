/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Day3_avoidance.h
 *
 * Code generated for Simulink model 'Day3_avoidance'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Oct 20 13:06:13 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Day3_avoidance_h_
#define RTW_HEADER_Day3_avoidance_h_
#ifndef Day3_avoidance_COMMON_INCLUDES_
#define Day3_avoidance_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_gpio.h"
#include "MW_pigs.h"
#include "MW_Raspi_PulseIn.h"
#include "linuxTimeLogger.h"
#endif                                 /* Day3_avoidance_COMMON_INCLUDES_ */

#include "Day3_avoidance_types.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T OutlierRemover;               /* '<S3>/Switch1' */
  real_T Switch1;                      /* '<S11>/Switch1' */
  real_T Add3;                         /* '<S3>/Add3' */
  real_T Add4;                         /* '<S3>/Add4' */
  real_T RawSignal;                    /* '<S3>/Ultrasonic Sensor' */
  boolean_T AND;                       /* '<S4>/AND' */
  boolean_T AND1;                      /* '<S4>/AND1' */
  boolean_T AND2;                      /* '<S4>/AND2' */
  boolean_T AND3;                      /* '<S4>/AND3' */
} B_Day3_avoidance_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  sensors_raspberrypi_Ultrasoni_T obj; /* '<S3>/Ultrasonic Sensor' */
  raspi_internal_PWMBlock_Day3__T obj_l;/* '<S4>/PWM1' */
  raspi_internal_PWMBlock_Day3__T obj_m;/* '<S4>/PWM' */
  raspi_internal_PWMBlock_Day3__T obj_e;/* '<S2>/PWM1' */
  raspi_internal_PWMBlock_Day3__T obj_f;/* '<S1>/PWM' */
  codertarget_raspi_internal_Ra_T obj_j;/* '<S15>/Digital Write' */
  codertarget_raspi_internal_Ra_T obj_g;/* '<S14>/Digital Write' */
  codertarget_raspi_internal_Ra_T obj_lq;/* '<S13>/Digital Write' */
  codertarget_raspi_internal_Ra_T obj_gy;/* '<S12>/Digital Write' */
  codertarget_raspi_internal_Ra_T obj_m0;/* '<S8>/Digital Write' */
  codertarget_raspi_internal_Ra_T obj_i;/* '<S7>/Digital Write' */
  codertarget_raspi_internal_Ra_T obj_n;/* '<S6>/Digital Write' */
  codertarget_raspi_internal_Ra_T obj_mj;/* '<S5>/Digital Write' */
  real_T Memory_PreviousInput;         /* '<S11>/Memory' */
  real_T Memory_PreviousInput_e;       /* '<S3>/Memory' */
  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      /* '<S4>/Scope4' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S4>/Scope1' */

  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<S3>/Scope' */
} DW_Day3_avoidance_T;

/* Parameters (default storage) */
struct P_Day3_avoidance_T_ {
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S9>/Constant5'
                                        */
  real_T Switch_Threshold;             /* Expression: 3*0.1
                                        * Referenced by: '<S11>/Switch'
                                        */
  real_T ObjectDetectionThresh_Value;  /* Expression: 1
                                        * Referenced by: '<S3>/Object Detection Thresh'
                                        */
  real_T UltrasonicSensor_SampleTime;  /* Expression: 0.1
                                        * Referenced by: '<S3>/Ultrasonic Sensor'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant5_Value_j;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant5_Value_d;            /* Expression: 0
                                        * Referenced by: '<S10>/Constant5'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S11>/Memory'
                                        */
  real_T Constant2_Value;              /* Expression: 3*0.1
                                        * Referenced by: '<S11>/Constant2'
                                        */
  real_T Memory_InitialCondition_j;    /* Expression: 0
                                        * Referenced by: '<S3>/Memory'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0
                                        * Referenced by: '<S3>/Switch'
                                        */
  real_T Switch1_Threshold;            /* Expression: 2
                                        * Referenced by: '<S3>/Switch1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T Switch1_Threshold_a;          /* Expression: 3*0.1
                                        * Referenced by: '<S11>/Switch1'
                                        */
  real_T Switch2_Threshold;            /* Expression: 1
                                        * Referenced by: '<S3>/Switch2'
                                        */
  real_T Offset_Value;                 /* Expression: 50
                                        * Referenced by: '<S3>/Offset'
                                        */
  real_T DifferentialGain_Gain;        /* Expression: 50
                                        * Referenced by: '<S3>/Differential Gain'
                                        */
  real_T Switch1_Threshold_n;          /* Expression: 0
                                        * Referenced by: '<S9>/Switch1'
                                        */
  real_T SpeedGain_Gain;               /* Expression: 260
                                        * Referenced by: '<S3>/Speed Gain'
                                        */
  real_T Switch5_Threshold;            /* Expression: 0.8
                                        * Referenced by: '<S10>/Switch5'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: 1/360
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T Gain_Gain;                    /* Expression: 0
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: -1
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Switch6_Threshold;            /* Expression: 0.8
                                        * Referenced by: '<S10>/Switch6'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/360
                                        * Referenced by: '<S3>/Gain3'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 0
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T MotorStart_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Motor Start'
                                        */
  real_T MotorDirection_Value;         /* Expression: 0
                                        * Referenced by: '<Root>/Motor Direction'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Day3_avoidance_T {
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
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Day3_avoidance_T Day3_avoidance_P;

/* Block signals (default storage) */
extern B_Day3_avoidance_T Day3_avoidance_B;

/* Block states (default storage) */
extern DW_Day3_avoidance_T Day3_avoidance_DW;

/* External function called from main */
extern void Day3_avoidance_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Day3_avoidance_initialize(void);
extern void Day3_avoidance_step0(void);
extern void Day3_avoidance_step1(void);
extern void Day3_avoidance_step(int_T tid);
extern void Day3_avoidance_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Day3_avoidance_T *const Day3_avoidance_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Constant' : Unused code path elimination
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
 * '<Root>' : 'Day3_avoidance'
 * '<S1>'   : 'Day3_avoidance/M1'
 * '<S2>'   : 'Day3_avoidance/M2'
 * '<S3>'   : 'Day3_avoidance/Subsystem2'
 * '<S4>'   : 'Day3_avoidance/모터'
 * '<S5>'   : 'Day3_avoidance/M1/GPIO Write'
 * '<S6>'   : 'Day3_avoidance/M1/GPIO Write1'
 * '<S7>'   : 'Day3_avoidance/M2/GPIO Write2'
 * '<S8>'   : 'Day3_avoidance/M2/GPIO Write3'
 * '<S9>'   : 'Day3_avoidance/Subsystem2/Differential Steering'
 * '<S10>'  : 'Day3_avoidance/Subsystem2/Emergency Stop'
 * '<S11>'  : 'Day3_avoidance/Subsystem2/Rate Limiter'
 * '<S12>'  : 'Day3_avoidance/모터/GPIO Write1'
 * '<S13>'  : 'Day3_avoidance/모터/GPIO Write2'
 * '<S14>'  : 'Day3_avoidance/모터/GPIO Write3'
 * '<S15>'  : 'Day3_avoidance/모터/GPIO Write4'
 */
#endif                                 /* RTW_HEADER_Day3_avoidance_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
