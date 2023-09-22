/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: toy_car.h
 *
 * Code generated for Simulink model 'toy_car'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Aug 31 14:30:01 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_toy_car_h_
#define RTW_HEADER_toy_car_h_
#ifndef toy_car_COMMON_INCLUDES_
#define toy_car_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* toy_car_COMMON_INCLUDES_ */

#include "toy_car_types.h"
#include "rt_zcfcn.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_c3_toy_car;               /* '<Root>/Chart' */
  uint8_T is_DIRECTION;                /* '<Root>/Chart' */
  uint8_T is_SPEED;                    /* '<Root>/Chart' */
  uint8_T was_DIRECTION;               /* '<Root>/Chart' */
  uint8_T was_SPEED;                   /* '<Root>/Chart' */
} DW_toy_car_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Chart_Trig_ZCE[3];        /* '<Root>/Chart' */
} PrevZCX_toy_car_T;

/* Real-time Model Data Structure */
struct tag_RTM_toy_car_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_toy_car_T toy_car_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_toy_car_T toy_car_PrevZCX;

/* Model entry point functions */
extern void toy_car_initialize(void);
extern void toy_car_step(void);
extern void toy_car_terminate(void);

/* Real-time Model object */
extern RT_MODEL_toy_car_T *const toy_car_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'toy_car'
 * '<S1>'   : 'toy_car/Chart'
 * '<S2>'   : 'toy_car/DIR'
 * '<S3>'   : 'toy_car/SPD'
 * '<S4>'   : 'toy_car/SW'
 */
#endif                                 /* RTW_HEADER_toy_car_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
