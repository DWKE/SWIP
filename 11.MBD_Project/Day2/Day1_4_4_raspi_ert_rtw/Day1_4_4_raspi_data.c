/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Day1_4_4_raspi_data.c
 *
 * Code generated for Simulink model 'Day1_4_4_raspi'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Oct 20 13:15:55 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Day1_4_4_raspi.h"

/* Block parameters (default storage) */
P_Day1_4_4_raspi_T Day1_4_4_raspi_P = {
  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S2>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative1_ICPrevScale
   * Referenced by: '<S3>/UD'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1>/M1 Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S1>/M2 Encoder'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant3'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/M1 Speed Control (deg//s)'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Switch'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Motor Start'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/M2 Speed Control (deg//s)'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Switch1'
   */
  0.0,

  /* Expression: 360/950
   * Referenced by: '<S1>/M1 Calibration Gain'
   */
  0.37894736842105264,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S2>/TSamp'
   */
  1000.0,

  /* Expression: 360/990
   * Referenced by: '<S1>/M2 Calibration Gain'
   */
  0.36363636363636365,

  /* Computed Parameter: TSamp_WtEt_b
   * Referenced by: '<S3>/TSamp'
   */
  1000.0,

  /* Expression: 100
   * Referenced by: '<S1>/P Gain1'
   */
  100.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S1>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/I Gain1'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S1>/P Gain'
   */
  100.0,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<S1>/Discrete-Time Integrator1'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S1>/Discrete-Time Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/I Gain'
   */
  0.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
