/*
 * Day3_2.h
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "Day3_2".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Oct 16 14:49:30 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Day3_2_h_
#define RTW_HEADER_Day3_2_h_
#ifndef Day3_2_COMMON_INCLUDES_
#define Day3_2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Day3_2_COMMON_INCLUDES_ */

#include "Day3_2_types.h"
#include "rtGetNaN.h"
#include "rtGetInf.h"
#include <float.h>
#include <string.h>
#include <stddef.h>
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
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

/* Block signals for system '<S1>/findnode' */
typedef struct {
  uint16_T In1;                        /* '<S5>/In1' */
  uint16_T Switch;                     /* '<S6>/Switch' */
} B_findnode_Day3_2_T;

/* Block states (default storage) for system '<S1>/findnode' */
typedef struct {
  uint16_T Nodevariablem_DSTATE;       /* '<S3>/Node variable m' */
} DW_findnode_Day3_2_T;

/* Block signals (default storage) */
typedef struct {
  B_findnode_Day3_2_T findnode;        /* '<S1>/findnode' */
} B_Day3_2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_findnode_Day3_2_T findnode;       /* '<S1>/findnode' */
} DW_Day3_2_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Input;                        /* '<Root>/Input' */
  real_T Input1;                       /* '<Root>/Input1' */
  real_T Input2;                       /* '<Root>/Input2' */
  real_T Input3;                       /* '<Root>/Input3' */
  real_T Input4;                       /* '<Root>/Input4' */
} ExtU_Day3_2_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Output;                     /* '<Root>/Output' */
} ExtY_Day3_2_T;

/* Parameters for system: '<S1>/findnode' */
struct P_findnode_Day3_2_T_ {
  real_T CutPoint_Value[327];          /* Expression: learnerParams.CutPoint
                                        * Referenced by: '<S6>/CutPoint'
                                        */
  uint16_T updatedm_Y0;                /* Computed Parameter: updatedm_Y0
                                        * Referenced by: '<S6>/updated m'
                                        */
  uint16_T Children_Value[654];        /* Expression: learnerParams.Children
                                        * Referenced by: '<S6>/Children'
                                        */
  uint16_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S5>/Out1'
                                        */
  uint16_T Nodevariablem_InitialCondition;
                           /* Computed Parameter: Nodevariablem_InitialCondition
                            * Referenced by: '<S3>/Node variable m'
                            */
  boolean_T Constant4_Value;           /* Expression: true
                                        * Referenced by: '<S3>/Constant4'
                                        */
  boolean_T IsPruneListEmpty_Value;/* Expression: learnerParams.IsPruneListEmpty
                                    * Referenced by: '<S3>/IsPruneListEmpty'
                                    */
  boolean_T NanCutPoints_Value[327];   /* Expression: learnerParams.NanCutPoints
                                        * Referenced by: '<S3>/NanCutPoints'
                                        */
  uint8_T Constant3_Value;             /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S3>/Constant3'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S4>/Constant'
                                        */
  uint8_T CutVar_Value[327];           /* Expression: learnerParams.CutVar
                                        * Referenced by: '<S3>/CutVar'
                                        */
  uint8_T Switch_Threshold;            /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S3>/Switch'
                                        */
};

/* Parameters (default storage) */
struct P_Day3_2_T_ {
  real_T Constant6_Value[327];         /* Expression: learnerParams.NodeMean
                                        * Referenced by: '<S2>/Constant6'
                                        */
  P_findnode_Day3_2_T findnode;        /* '<S1>/findnode' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Day3_2_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Day3_2_T Day3_2_P;

/* Block signals (default storage) */
extern B_Day3_2_T Day3_2_B;

/* Block states (default storage) */
extern DW_Day3_2_T Day3_2_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Day3_2_T Day3_2_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Day3_2_T Day3_2_Y;

/* Model entry point functions */
extern void Day3_2_initialize(void);
extern void Day3_2_step(void);
extern void Day3_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Day3_2_T *const Day3_2_M;

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
 * '<Root>' : 'Day3_2'
 * '<S1>'   : 'Day3_2/RegressionTree Predict'
 * '<S2>'   : 'Day3_2/RegressionTree Predict/computeYfit'
 * '<S3>'   : 'Day3_2/RegressionTree Predict/findnode'
 * '<S4>'   : 'Day3_2/RegressionTree Predict/findnode/Compare To Zero'
 * '<S5>'   : 'Day3_2/RegressionTree Predict/findnode/Return m'
 * '<S6>'   : 'Day3_2/RegressionTree Predict/findnode/Update m'
 */
#endif                                 /* RTW_HEADER_Day3_2_h_ */
