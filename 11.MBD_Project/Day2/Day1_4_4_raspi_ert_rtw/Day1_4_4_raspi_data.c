/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Day1_4_4_raspi_data.c
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

#include "Day1_4_4_raspi.h"

/* Block parameters (default storage) */
P_Day1_4_4_raspi_T Day1_4_4_raspi_P = {
  /* Mask Parameter: DiscreteDerivative1_ICPrevScale
   * Referenced by: '<S2>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S1>/UD'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/M1 Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/M2 Encoder'
   */
  -1.0,

  /* Expression: 360/975
   * Referenced by: '<Root>/M2 Calibration Gain'
   */
  0.36923076923076925,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S2>/TSamp'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<Root>/Speed Control (deg//s)'
   */
  0.0,

  /* Expression: 360/975
   * Referenced by: '<Root>/M1 Calibration Gain'
   */
  0.36923076923076925,

  /* Computed Parameter: TSamp_WtEt_d
   * Referenced by: '<S1>/TSamp'
   */
  1000.0,

  /* Expression: 0.001
   * Referenced by: '<Root>/P Gain'
   */
  0.001,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/I Gain'
   */
  0.0,

  /* Expression: 0.001
   * Referenced by: '<Root>/P Gain1'
   */
  0.001,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/I Gain1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Motor Start'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Motor Direction'
   */
  1.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
