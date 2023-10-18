/*
 * Day3_2_private.h
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

#ifndef RTW_HEADER_Day3_2_private_h_
#define RTW_HEADER_Day3_2_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "Day3_2.h"
#include "Day3_2_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void Day3_2_findnode_Init(B_findnode_Day3_2_T *localB,
  DW_findnode_Day3_2_T *localDW, P_findnode_Day3_2_T *localP);
extern void Day3_2_findnode_Reset(DW_findnode_Day3_2_T *localDW,
  P_findnode_Day3_2_T *localP);
extern void Day3_2_findnode(const real_T rtu_X[5], B_findnode_Day3_2_T *localB,
  DW_findnode_Day3_2_T *localDW, P_findnode_Day3_2_T *localP);

#endif                                 /* RTW_HEADER_Day3_2_private_h_ */
