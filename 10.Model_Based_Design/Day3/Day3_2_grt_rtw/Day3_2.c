/*
 * Day3_2.c
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

#include "Day3_2.h"
#include "rtwtypes.h"
#include "Day3_2_private.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Block signals (default storage) */
B_Day3_2_T Day3_2_B;

/* Block states (default storage) */
DW_Day3_2_T Day3_2_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Day3_2_T Day3_2_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Day3_2_T Day3_2_Y;

/* Real-time model */
static RT_MODEL_Day3_2_T Day3_2_M_;
RT_MODEL_Day3_2_T *const Day3_2_M = &Day3_2_M_;

/* System initialize for iterator system: '<S1>/findnode' */
void Day3_2_findnode_Init(B_findnode_Day3_2_T *localB, DW_findnode_Day3_2_T
  *localDW, P_findnode_Day3_2_T *localP)
{
  /* InitializeConditions for UnitDelay: '<S3>/Node variable m' */
  localDW->Nodevariablem_DSTATE = localP->Nodevariablem_InitialCondition;

  /* SystemInitialize for IfAction SubSystem: '<S3>/Update m' */
  /* SystemInitialize for Switch: '<S6>/Switch' incorporates:
   *  Outport: '<S6>/updated m'
   */
  localB->Switch = localP->updatedm_Y0;

  /* End of SystemInitialize for SubSystem: '<S3>/Update m' */

  /* SystemInitialize for IfAction SubSystem: '<S3>/Return m' */
  /* SystemInitialize for SignalConversion generated from: '<S5>/In1' incorporates:
   *  Outport: '<S5>/Out1'
   */
  localB->In1 = localP->Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S3>/Return m' */
}

/* System reset for iterator system: '<S1>/findnode' */
void Day3_2_findnode_Reset(DW_findnode_Day3_2_T *localDW, P_findnode_Day3_2_T
  *localP)
{
  /* InitializeConditions for UnitDelay: '<S3>/Node variable m' */
  localDW->Nodevariablem_DSTATE = localP->Nodevariablem_InitialCondition;
}

/* Output and update for iterator system: '<S1>/findnode' */
void Day3_2_findnode(const real_T rtu_X[5], B_findnode_Day3_2_T *localB,
                     DW_findnode_Day3_2_T *localDW, P_findnode_Day3_2_T *localP)
{
  /* Outputs for Iterator SubSystem: '<S1>/findnode' incorporates:
   *  WhileIterator: '<S3>/While Iterator'
   */
  Day3_2_findnode_Reset(localDW, localP);

  /* End of Outputs for SubSystem: '<S1>/findnode' */
  boolean_T rtb_Switch1;
  do {
    int32_T tmp_0;
    uint8_T tmp;
    if (localP->IsPruneListEmpty_Value) {
      rtb_Switch1 = (localP->CutVar_Value[localDW->Nodevariablem_DSTATE - 1] !=
                     localP->Constant_Value);
    } else {
      rtb_Switch1 = localP->Constant4_Value;
    }

    tmp_0 = localP->CutVar_Value[localDW->Nodevariablem_DSTATE - 1];
    if (tmp_0 > localP->Switch_Threshold) {
      tmp = localP->CutVar_Value[localDW->Nodevariablem_DSTATE - 1];
    } else {
      tmp = localP->Constant3_Value;
    }

    rtb_Switch1 = ((!rtIsNaN(rtu_X[tmp - 1])) && (!localP->
      NanCutPoints_Value[localDW->Nodevariablem_DSTATE - 1]) && rtb_Switch1);
    if (rtb_Switch1) {
      if (rtu_X[tmp_0 - 1] < localP->CutPoint_Value
          [localDW->Nodevariablem_DSTATE - 1]) {
        localB->Switch = localP->Children_Value[localDW->Nodevariablem_DSTATE -
          1];
      } else {
        localB->Switch = localP->Children_Value[localDW->Nodevariablem_DSTATE +
          326];
      }
    } else {
      localB->In1 = localDW->Nodevariablem_DSTATE;
    }

    localDW->Nodevariablem_DSTATE = localB->Switch;
  } while (rtb_Switch1);
}

/* Model step function */
void Day3_2_step(void)
{
  real_T rtb_VectorConcatenate[5];

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Inport: '<Root>/Input'
   */
  rtb_VectorConcatenate[0] = Day3_2_U.Input;

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Inport: '<Root>/Input1'
   */
  rtb_VectorConcatenate[1] = Day3_2_U.Input1;

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Inport: '<Root>/Input2'
   */
  rtb_VectorConcatenate[2] = Day3_2_U.Input2;

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Inport: '<Root>/Input3'
   */
  rtb_VectorConcatenate[3] = Day3_2_U.Input3;

  /* SignalConversion generated from: '<Root>/Vector Concatenate' incorporates:
   *  Inport: '<Root>/Input4'
   */
  rtb_VectorConcatenate[4] = Day3_2_U.Input4;

  /* Outputs for Atomic SubSystem: '<Root>/RegressionTree Predict' */
  /* Outputs for Iterator SubSystem: '<S1>/findnode' */
  /* Reshape: '<S1>/Reshape' */
  Day3_2_findnode(rtb_VectorConcatenate, &Day3_2_B.findnode, &Day3_2_DW.findnode,
                  &Day3_2_P.findnode);

  /* End of Outputs for SubSystem: '<S1>/findnode' */

  /* Outport: '<Root>/Output' incorporates:
   *  Constant: '<S2>/Constant6'
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   *  Selector: '<S2>/Selector'
   */
  Day3_2_Y.Output = (real32_T)Day3_2_P.Constant6_Value[Day3_2_B.findnode.In1 - 1];

  /* End of Outputs for SubSystem: '<Root>/RegressionTree Predict' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(Day3_2_M->rtwLogInfo, (&Day3_2_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(Day3_2_M)!=-1) &&
        !((rtmGetTFinal(Day3_2_M)-Day3_2_M->Timing.taskTime0) >
          Day3_2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Day3_2_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Day3_2_M->Timing.clockTick0)) {
    ++Day3_2_M->Timing.clockTickH0;
  }

  Day3_2_M->Timing.taskTime0 = Day3_2_M->Timing.clockTick0 *
    Day3_2_M->Timing.stepSize0 + Day3_2_M->Timing.clockTickH0 *
    Day3_2_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Day3_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  Day3_2_P.findnode.CutPoint_Value[33] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[55] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[56] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[67] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[68] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[88] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[109] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[110] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[111] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[112] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[113] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[114] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[115] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[116] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[117] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[118] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[119] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[120] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[175] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[176] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[177] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[178] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[179] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[180] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[181] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[182] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[183] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[184] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[185] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[186] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[187] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[188] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[189] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[190] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[191] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[192] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[193] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[194] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[195] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[196] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[197] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[198] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[199] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[200] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[201] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[202] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[203] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[204] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[205] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[206] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[207] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[208] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[209] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[210] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[211] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[212] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[213] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[215] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[217] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[218] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[219] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[220] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[221] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[222] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[223] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[224] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[225] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[226] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[227] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[228] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[229] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[230] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[231] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[232] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[233] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[234] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[235] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[236] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[237] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[238] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[239] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[240] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[241] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[242] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[243] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[244] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[245] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[246] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[247] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[248] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[249] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[250] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[251] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[252] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[253] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[254] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[255] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[256] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[257] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[258] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[259] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[260] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[261] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[262] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[263] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[264] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[265] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[266] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[267] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[268] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[269] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[270] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[271] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[272] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[273] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[274] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[275] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[276] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[277] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[278] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[279] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[280] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[281] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[282] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[283] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[284] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[285] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[286] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[287] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[288] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[289] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[290] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[291] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[292] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[293] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[294] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[299] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[300] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[301] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[302] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[303] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[304] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[305] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[306] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[307] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[308] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[309] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[310] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[311] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[312] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[313] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[314] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[315] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[316] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[317] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[318] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[319] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[320] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[321] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[322] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[323] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[324] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[325] = rtNaN;
  Day3_2_P.findnode.CutPoint_Value[326] = rtNaN;

  /* initialize real-time model */
  (void) memset((void *)Day3_2_M, 0,
                sizeof(RT_MODEL_Day3_2_T));
  rtmSetTFinal(Day3_2_M, -1);
  Day3_2_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Day3_2_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Day3_2_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Day3_2_M->rtwLogInfo, (NULL));
    rtliSetLogT(Day3_2_M->rtwLogInfo, "tout");
    rtliSetLogX(Day3_2_M->rtwLogInfo, "");
    rtliSetLogXFinal(Day3_2_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Day3_2_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Day3_2_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Day3_2_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Day3_2_M->rtwLogInfo, 1);
    rtliSetLogY(Day3_2_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Day3_2_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Day3_2_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &Day3_2_B), 0,
                sizeof(B_Day3_2_T));

  /* states (dwork) */
  (void) memset((void *)&Day3_2_DW, 0,
                sizeof(DW_Day3_2_T));

  /* external inputs */
  (void)memset(&Day3_2_U, 0, sizeof(ExtU_Day3_2_T));

  /* external outputs */
  Day3_2_Y.Output = 0.0F;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Day3_2_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Day3_2_M), Day3_2_M->Timing.stepSize0, (&rtmGetErrorStatus(Day3_2_M)));

  /* SystemInitialize for Atomic SubSystem: '<Root>/RegressionTree Predict' */
  /* SystemInitialize for Iterator SubSystem: '<S1>/findnode' */
  Day3_2_findnode_Init(&Day3_2_B.findnode, &Day3_2_DW.findnode,
                       &Day3_2_P.findnode);

  /* End of SystemInitialize for SubSystem: '<S1>/findnode' */
  /* End of SystemInitialize for SubSystem: '<Root>/RegressionTree Predict' */
}

/* Model terminate function */
void Day3_2_terminate(void)
{
  /* (no terminate code required) */
}
