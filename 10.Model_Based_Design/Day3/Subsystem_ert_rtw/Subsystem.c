/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem.c
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Aug 16 16:30:37 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Subsystem.h"
#include "rtwtypes.h"

/* External inputs (root inport signals with default storage) */
ExtU_Subsystem_T Subsystem_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Subsystem_T Subsystem_Y;

/* Real-time model */
static RT_MODEL_Subsystem_T Subsystem_M_;
RT_MODEL_Subsystem_T *const Subsystem_M = &Subsystem_M_;

/* Model step function */
void Subsystem_step(void)
{
  real_T rtb_skyhook;

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem' */
  /* Gain: '<S1>/skyhook' incorporates:
   *  Inport: '<Root>/In1'
   */
  rtb_skyhook = -5000.0 * Subsystem_U.In1;

  /* Outport: '<Root>/Out1' incorporates:
   *  Gain: '<S1>/Gain4'
   */
  Subsystem_Y.Out1[0] = 0.0 * rtb_skyhook;
  Subsystem_Y.Out1[1] = 0.01 * rtb_skyhook;
  Subsystem_Y.Out1[2] = 0.0 * rtb_skyhook;
  Subsystem_Y.Out1[3] = -0.05 * rtb_skyhook;

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */
}

/* Model initialize function */
void Subsystem_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Subsystem_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
