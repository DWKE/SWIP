/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: PID_controller_codegen.h
 *
 * Code generated for Simulink model 'PID_controller_codegen'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Aug 30 15:16:46 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PID_controller_codegen_h_
#define RTW_HEADER_PID_controller_codegen_h_
#ifndef PID_controller_codegen_COMMON_INCLUDES_
#define PID_controller_codegen_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                             /* PID_controller_codegen_COMMON_INCLUDES_ */

#include "PID_controller_codegen_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_PID_controller_codege_T {
  const char_T * volatile errorStatus;
};

/* Model entry point functions */
extern void PID_controller_codegen_initialize(void);
extern void PID_controller_codegen_step(void);
extern void PID_controller_codegen_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PID_controller_codeg_T *const PID_controller_codegen_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Diff' : Unused code path elimination
 * Block '<S2>/TSamp' : Unused code path elimination
 * Block '<S2>/UD' : Unused code path elimination
 * Block '<S1>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<S1>/Gain' : Unused code path elimination
 * Block '<S1>/Gain1' : Unused code path elimination
 * Block '<S1>/Gain2' : Unused code path elimination
 * Block '<S1>/Sum1' : Unused code path elimination
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
 * '<Root>' : 'PID_controller_codegen'
 * '<S1>'   : 'PID_controller_codegen/Controller'
 * '<S2>'   : 'PID_controller_codegen/Controller/Discrete Derivative'
 */
#endif                                /* RTW_HEADER_PID_controller_codegen_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
