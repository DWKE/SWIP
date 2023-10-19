/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Day1_2_2_raspi_data.c
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

#include "Day1_2_2_raspi.h"

/* Block parameters (default storage) */
P_Day1_2_2_raspi_T Day1_2_2_raspi_P = {
  /* Mask Parameter: RepeatingSequence_rep_seq_y
   * Referenced by: '<S1>/Look-Up Table1'
   */
  { 0.05, 0.1 },

  /* Expression: period
   * Referenced by: '<S1>/Constant'
   */
  2.0,

  /* Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S1>/Look-Up Table1'
   */
  { 0.0, 2.0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
