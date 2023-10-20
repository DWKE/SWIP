/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: Day3_avoidance.c
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

#include "Day3_avoidance.h"
#include "rtwtypes.h"
#include "Day3_avoidance_private.h"

/* Block signals (default storage) */
B_Day3_avoidance_T Day3_avoidance_B;

/* Block states (default storage) */
DW_Day3_avoidance_T Day3_avoidance_DW;

/* Real-time model */
static RT_MODEL_Day3_avoidance_T Day3_avoidance_M_;
RT_MODEL_Day3_avoidance_T *const Day3_avoidance_M = &Day3_avoidance_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Day3_avoidance_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Day3_avoidance_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Day3_avoidance_M->Timing.TaskCounters.TID[1])++;
  if ((Day3_avoidance_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    Day3_avoidance_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void Day3_avoidance_step0(void)        /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Day3_avoidance_M->Timing.taskTime0 =
    ((time_T)(++Day3_avoidance_M->Timing.clockTick0)) *
    Day3_avoidance_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void Day3_avoidance_step1(void)        /* Sample time: [0.1s, 0.0s] */
{
  real_T rtb_Add;
  real_T rtb_Gain;
  real_T rtb_M2SpeedControl;
  real_T y;
  uint32_T duration;

  /* Logic: '<S4>/AND' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant5'
   */
  Day3_avoidance_B.AND = ((Day3_avoidance_P.Constant_Value != 0.0) &&
    (Day3_avoidance_P.Constant5_Value_j != 0.0));

  /* MATLABSystem: '<S12>/Digital Write' */
  EXT_GPIO_write(17U, (uint8_T)Day3_avoidance_B.AND);

  /* Logic: '<S4>/AND1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant5'
   *  Logic: '<S4>/NOT'
   */
  Day3_avoidance_B.AND1 = ((Day3_avoidance_P.Constant_Value != 0.0) &&
    (!(Day3_avoidance_P.Constant5_Value_j != 0.0)));

  /* MATLABSystem: '<S13>/Digital Write' */
  EXT_GPIO_write(27U, (uint8_T)Day3_avoidance_B.AND1);

  /* Logic: '<S4>/AND2' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Constant7'
   */
  Day3_avoidance_B.AND2 = ((Day3_avoidance_P.Constant6_Value != 0.0) &&
    (Day3_avoidance_P.Constant7_Value != 0.0));

  /* MATLABSystem: '<S14>/Digital Write' */
  EXT_GPIO_write(19U, (uint8_T)Day3_avoidance_B.AND2);

  /* Logic: '<S4>/AND3' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<Root>/Constant7'
   *  Logic: '<S4>/NOT1'
   */
  Day3_avoidance_B.AND3 = ((Day3_avoidance_P.Constant6_Value != 0.0) &&
    (!(Day3_avoidance_P.Constant7_Value != 0.0)));

  /* MATLABSystem: '<S15>/Digital Write' */
  EXT_GPIO_write(26U, (uint8_T)Day3_avoidance_B.AND3);

  /* MATLABSystem: '<S3>/Ultrasonic Sensor' */
  if (Day3_avoidance_DW.obj.SampleTime !=
      Day3_avoidance_P.UltrasonicSensor_SampleTime) {
    Day3_avoidance_DW.obj.SampleTime =
      Day3_avoidance_P.UltrasonicSensor_SampleTime;
  }

  MW_UltrasonicRead(&duration, 1, 23U, 24U, 10, 5);

  /* MATLABSystem: '<S3>/Ultrasonic Sensor' */
  Day3_avoidance_B.RawSignal = (real_T)duration * 0.000343 / 2.0;

  /* Switch: '<S3>/Switch' */
  if (Day3_avoidance_B.RawSignal > Day3_avoidance_P.Switch_Threshold_a) {
    rtb_M2SpeedControl = Day3_avoidance_B.RawSignal;
  } else {
    rtb_M2SpeedControl = Day3_avoidance_DW.Memory_PreviousInput_e;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Switch: '<S3>/Switch1' */
  if (rtb_M2SpeedControl > Day3_avoidance_P.Switch1_Threshold) {
    /* Switch: '<S3>/Switch1' */
    Day3_avoidance_B.OutlierRemover = Day3_avoidance_DW.Memory_PreviousInput_e;
  } else {
    /* Switch: '<S3>/Switch1' */
    Day3_avoidance_B.OutlierRemover = rtb_M2SpeedControl;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* Sum: '<S11>/Add' */
  rtb_Add = Day3_avoidance_B.OutlierRemover -
    Day3_avoidance_DW.Memory_PreviousInput;

  /* Switch: '<S11>/Switch1' incorporates:
   *  Gain: '<S11>/Gain1'
   *  Switch: '<S11>/Switch'
   */
  if (Day3_avoidance_P.Gain1_Gain * rtb_Add >
      Day3_avoidance_P.Switch1_Threshold_a) {
    /* Memory: '<S11>/Memory' incorporates:
     *  Constant: '<S11>/Constant2'
     *  Sum: '<S11>/Add4'
     *  Switch: '<S11>/Switch1'
     */
    Day3_avoidance_B.Switch1 = Day3_avoidance_DW.Memory_PreviousInput -
      Day3_avoidance_P.Constant2_Value;
  } else if (rtb_Add > Day3_avoidance_P.Switch_Threshold) {
    /* Memory: '<S11>/Memory' incorporates:
     *  Constant: '<S11>/Constant2'
     *  Sum: '<S11>/Add3'
     *  Switch: '<S11>/Switch'
     *  Switch: '<S11>/Switch1'
     */
    Day3_avoidance_B.Switch1 = Day3_avoidance_DW.Memory_PreviousInput +
      Day3_avoidance_P.Constant2_Value;
  } else {
    /* Memory: '<S11>/Memory' incorporates:
     *  Switch: '<S11>/Switch'
     *  Switch: '<S11>/Switch1'
     */
    Day3_avoidance_B.Switch1 = Day3_avoidance_B.OutlierRemover;
  }

  /* End of Switch: '<S11>/Switch1' */

  /* Switch: '<S3>/Switch2' incorporates:
   *  Constant: '<S3>/Object Detection Thresh'
   */
  if (Day3_avoidance_B.Switch1 >= Day3_avoidance_P.Switch2_Threshold) {
    rtb_M2SpeedControl = Day3_avoidance_P.ObjectDetectionThresh_Value;
  } else {
    rtb_M2SpeedControl = Day3_avoidance_B.Switch1;
  }

  /* End of Switch: '<S3>/Switch2' */

  /* Sum: '<S3>/Add2' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  rtb_Add = Day3_avoidance_P.Constant1_Value - rtb_M2SpeedControl;

  /* Switch: '<S9>/Switch1' incorporates:
   *  Switch: '<S9>/Switch'
   */
  if (rtb_Add > Day3_avoidance_P.Switch1_Threshold_n) {
    /* Switch: '<S9>/Switch1' incorporates:
     *  Gain: '<S3>/Differential Gain'
     *  Gain: '<S9>/Gain2'
     */
    Day3_avoidance_DW.Memory_PreviousInput_e =
      Day3_avoidance_P.DifferentialGain_Gain * rtb_Add *
      Day3_avoidance_P.Gain2_Gain;
  } else if (rtb_Add != 0.0) {
    /* Switch: '<S9>/Switch1' incorporates:
     *  Gain: '<S3>/Differential Gain'
     *  Switch: '<S9>/Switch'
     */
    Day3_avoidance_DW.Memory_PreviousInput_e =
      Day3_avoidance_P.DifferentialGain_Gain * rtb_Add;
  } else {
    /* Switch: '<S9>/Switch1' incorporates:
     *  Constant: '<S9>/Constant5'
     */
    Day3_avoidance_DW.Memory_PreviousInput_e = Day3_avoidance_P.Constant5_Value;
  }

  /* End of Switch: '<S9>/Switch1' */

  /* Sum: '<S3>/Add3' incorporates:
   *  Constant: '<S3>/Offset'
   */
  Day3_avoidance_B.Add3 = Day3_avoidance_P.Offset_Value +
    Day3_avoidance_DW.Memory_PreviousInput_e;

  /* Gain: '<S3>/Speed Gain' */
  rtb_M2SpeedControl *= Day3_avoidance_P.SpeedGain_Gain;

  /* Switch: '<S10>/Switch5' incorporates:
   *  Constant: '<S10>/Constant5'
   *  Sum: '<S3>/Add'
   */
  if (rtb_Add > Day3_avoidance_P.Switch5_Threshold) {
    y = Day3_avoidance_P.Constant5_Value_d;
  } else {
    y = Day3_avoidance_B.Add3 + rtb_M2SpeedControl;
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Gain: '<S3>/Gain2'
   *  Switch: '<S10>/Switch5'
   */
  rtb_Gain = Day3_avoidance_P.Gain2_Gain_k * y * Day3_avoidance_P.Gain_Gain;

  /* MATLABSystem: '<S4>/PWM' */
  if (rtb_Gain <= 1.0) {
    y = rtb_Gain;
  } else {
    y = 1.0;
  }

  if (!(y >= 0.0)) {
    y = 0.0;
  }

  EXT_PWMBlock_setDutyCycle(Day3_avoidance_DW.obj_m.PinNumber, y);

  /* End of MATLABSystem: '<S4>/PWM' */

  /* MATLABSystem: '<S1>/PWM' */
  if (!(rtb_Gain <= 1.0)) {
    rtb_Gain = 1.0;
  }

  if (!(rtb_Gain >= 0.0)) {
    rtb_Gain = 0.0;
  }

  EXT_PWMBlock_setDutyCycle(Day3_avoidance_DW.obj_f.PinNumber, rtb_Gain);

  /* End of MATLABSystem: '<S1>/PWM' */

  /* Sum: '<S3>/Add4' incorporates:
   *  Constant: '<S3>/Offset'
   *  Gain: '<S9>/Gain1'
   */
  Day3_avoidance_B.Add4 = Day3_avoidance_P.Gain1_Gain_e *
    Day3_avoidance_DW.Memory_PreviousInput_e + Day3_avoidance_P.Offset_Value;

  /* Switch: '<S10>/Switch6' incorporates:
   *  Constant: '<S10>/Constant5'
   *  Sum: '<S3>/Add1'
   */
  if (rtb_Add > Day3_avoidance_P.Switch6_Threshold) {
    y = Day3_avoidance_P.Constant5_Value_d;
  } else {
    y = Day3_avoidance_B.Add4 + rtb_M2SpeedControl;
  }

  /* Gain: '<Root>/Gain1' incorporates:
   *  Gain: '<S3>/Gain3'
   *  Switch: '<S10>/Switch6'
   */
  rtb_Add = Day3_avoidance_P.Gain3_Gain * y * Day3_avoidance_P.Gain1_Gain_f;

  /* MATLABSystem: '<S4>/PWM1' */
  if (rtb_Add <= 1.0) {
    y = rtb_Add;
  } else {
    y = 1.0;
  }

  if (!(y >= 0.0)) {
    y = 0.0;
  }

  EXT_PWMBlock_setDutyCycle(Day3_avoidance_DW.obj_l.PinNumber, y);

  /* End of MATLABSystem: '<S4>/PWM1' */

  /* MATLABSystem: '<S2>/PWM1' */
  if (!(rtb_Add <= 1.0)) {
    rtb_Add = 1.0;
  }

  if (!(rtb_Add >= 0.0)) {
    rtb_Add = 0.0;
  }

  EXT_PWMBlock_setDutyCycle(Day3_avoidance_DW.obj_e.PinNumber, rtb_Add);

  /* End of MATLABSystem: '<S2>/PWM1' */
  /* MATLABSystem: '<S5>/Digital Write' incorporates:
   *  Constant: '<Root>/Motor Direction'
   *  Constant: '<Root>/Motor Start'
   *  Logic: '<S1>/AND'
   */
  EXT_GPIO_write(15U, (uint8_T)((Day3_avoidance_P.MotorStart_Value != 0.0) &&
    (Day3_avoidance_P.MotorDirection_Value != 0.0)));

  /* MATLABSystem: '<S6>/Digital Write' incorporates:
   *  Constant: '<Root>/Motor Direction'
   *  Constant: '<Root>/Motor Start'
   *  Logic: '<S1>/AND1'
   *  Logic: '<S1>/NOT'
   */
  EXT_GPIO_write(14U, (uint8_T)((Day3_avoidance_P.MotorStart_Value != 0.0) &&
    (!(Day3_avoidance_P.MotorDirection_Value != 0.0))));

  /* MATLABSystem: '<S7>/Digital Write' incorporates:
   *  Constant: '<Root>/Motor Start'
   *  Logic: '<S2>/AND2'
   */
  EXT_GPIO_write(13U, (uint8_T)(Day3_avoidance_P.MotorStart_Value != 0.0));

  /* MATLABSystem: '<S8>/Digital Write' incorporates:
   *  Logic: '<S2>/AND3'
   */
  EXT_GPIO_write(6U, 0);

  /* Update for Memory: '<S11>/Memory' */
  Day3_avoidance_DW.Memory_PreviousInput = Day3_avoidance_B.Switch1;

  /* Update for Switch: '<S9>/Switch1' incorporates:
   *  Memory: '<S3>/Memory'
   */
  Day3_avoidance_DW.Memory_PreviousInput_e = Day3_avoidance_B.OutlierRemover;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Day3_avoidance_M->Timing.clockTick1++;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Day3_avoidance_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Day3_avoidance_step0();
    break;

   case 1 :
    Day3_avoidance_step1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Day3_avoidance_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Day3_avoidance_M, -1);
  Day3_avoidance_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Day3_avoidance_M->Sizes.checksums[0] = (3620231176U);
  Day3_avoidance_M->Sizes.checksums[1] = (2622633195U);
  Day3_avoidance_M->Sizes.checksums[2] = (1134081517U);
  Day3_avoidance_M->Sizes.checksums[3] = (1767278720U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[23];
    Day3_avoidance_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Day3_avoidance_M->extModeInfo,
      &Day3_avoidance_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Day3_avoidance_M->extModeInfo,
                        Day3_avoidance_M->Sizes.checksums);
    rteiSetTPtr(Day3_avoidance_M->extModeInfo, rtmGetTPtr(Day3_avoidance_M));
  }

  {
    int32_T ret;
    char_T b[45];
    static const char_T tmp[45] =
      "Unable to configure pin %u for PWM output.\\n";

    /* InitializeConditions for Memory: '<S11>/Memory' */
    Day3_avoidance_DW.Memory_PreviousInput =
      Day3_avoidance_P.Memory_InitialCondition;

    /* InitializeConditions for Switch: '<S9>/Switch1' incorporates:
     *  Memory: '<S3>/Memory'
     */
    Day3_avoidance_DW.Memory_PreviousInput_e =
      Day3_avoidance_P.Memory_InitialCondition_j;

    /* Start for MATLABSystem: '<S12>/Digital Write' */
    Day3_avoidance_DW.obj_gy.matlabCodegenIsDeleted = false;
    Day3_avoidance_DW.obj_gy.isInitialized = 1;
    EXT_GPIO_init(17U, true);
    Day3_avoidance_DW.obj_gy.isSetupComplete = true;

    /* Start for MATLABSystem: '<S13>/Digital Write' */
    Day3_avoidance_DW.obj_lq.matlabCodegenIsDeleted = false;
    Day3_avoidance_DW.obj_lq.isInitialized = 1;
    EXT_GPIO_init(27U, true);
    Day3_avoidance_DW.obj_lq.isSetupComplete = true;

    /* Start for MATLABSystem: '<S14>/Digital Write' */
    Day3_avoidance_DW.obj_g.matlabCodegenIsDeleted = false;
    Day3_avoidance_DW.obj_g.isInitialized = 1;
    EXT_GPIO_init(19U, true);
    Day3_avoidance_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S15>/Digital Write' */
    Day3_avoidance_DW.obj_j.matlabCodegenIsDeleted = false;
    Day3_avoidance_DW.obj_j.isInitialized = 1;
    EXT_GPIO_init(26U, true);
    Day3_avoidance_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Ultrasonic Sensor' */
    Day3_avoidance_DW.obj.matlabCodegenIsDeleted = false;
    Day3_avoidance_DW.obj.SampleTime =
      Day3_avoidance_P.UltrasonicSensor_SampleTime;
    Day3_avoidance_DW.obj.isInitialized = 1;
    EXT_GPIO_init(23U, 1);
    EXT_GPIO_init(24U, 0);
    Day3_avoidance_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM' */
    Day3_avoidance_DW.obj_m.matlabCodegenIsDeleted = false;
    Day3_avoidance_DW.obj_m.isInitialized = 1;
    Day3_avoidance_DW.obj_m.PinNumber = 25U;
    ret = EXT_PWMBlock_init(Day3_avoidance_DW.obj_m.PinNumber, 500U, 0.0);
    if (ret != 0) {
      for (ret = 0; ret < 45; ret++) {
        b[ret] = tmp[ret];
      }

      printf(&b[0], Day3_avoidance_DW.obj_m.PinNumber);
    }

    Day3_avoidance_DW.obj_m.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/PWM' */

    /* Start for MATLABSystem: '<S1>/PWM' */
    Day3_avoidance_DW.obj_f.matlabCodegenIsDeleted = false;
    Day3_avoidance_DW.obj_f.isInitialized = 1;
    Day3_avoidance_DW.obj_f.PinNumber = 18U;
    ret = EXT_PWMBlock_init(Day3_avoidance_DW.obj_f.PinNumber, 50U, 0.0);
    if (ret != 0) {
      for (ret = 0; ret < 45; ret++) {
        b[ret] = tmp[ret];
      }

      printf(&b[0], Day3_avoidance_DW.obj_f.PinNumber);
    }

    Day3_avoidance_DW.obj_f.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S1>/PWM' */

    /* Start for MATLABSystem: '<S4>/PWM1' */
    Day3_avoidance_DW.obj_l.matlabCodegenIsDeleted = false;
    Day3_avoidance_DW.obj_l.isInitialized = 1;
    Day3_avoidance_DW.obj_l.PinNumber = 22U;
    ret = EXT_PWMBlock_init(Day3_avoidance_DW.obj_l.PinNumber, 500U, 0.0);
    if (ret != 0) {
      for (ret = 0; ret < 45; ret++) {
        b[ret] = tmp[ret];
      }

      printf(&b[0], Day3_avoidance_DW.obj_l.PinNumber);
    }

    Day3_avoidance_DW.obj_l.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/PWM1' */

    /* Start for MATLABSystem: '<S2>/PWM1' */
    Day3_avoidance_DW.obj_e.matlabCodegenIsDeleted = false;
    Day3_avoidance_DW.obj_e.isInitialized = 1;
    Day3_avoidance_DW.obj_e.PinNumber = 9U;
    ret = EXT_PWMBlock_init(Day3_avoidance_DW.obj_e.PinNumber, 50U, 0.0);
    if (ret != 0) {
      for (ret = 0; ret < 45; ret++) {
        b[ret] = tmp[ret];
      }

      printf(&b[0], Day3_avoidance_DW.obj_e.PinNumber);
    }

    Day3_avoidance_DW.obj_e.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S2>/PWM1' */

    /* Start for MATLABSystem: '<S5>/Digital Write' */
    Day3_avoidance_DW.obj_mj.matlabCodegenIsDeleted = false;
    Day3_avoidance_DW.obj_mj.isInitialized = 1;
    EXT_GPIO_init(15U, true);
    Day3_avoidance_DW.obj_mj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write' */
    Day3_avoidance_DW.obj_n.matlabCodegenIsDeleted = false;
    Day3_avoidance_DW.obj_n.isInitialized = 1;
    EXT_GPIO_init(14U, true);
    Day3_avoidance_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S7>/Digital Write' */
    Day3_avoidance_DW.obj_i.matlabCodegenIsDeleted = false;
    Day3_avoidance_DW.obj_i.isInitialized = 1;
    EXT_GPIO_init(13U, true);
    Day3_avoidance_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S8>/Digital Write' */
    Day3_avoidance_DW.obj_m0.matlabCodegenIsDeleted = false;
    Day3_avoidance_DW.obj_m0.isInitialized = 1;
    EXT_GPIO_init(6U, true);
    Day3_avoidance_DW.obj_m0.isSetupComplete = true;
  }
}

/* Model terminate function */
void Day3_avoidance_terminate(void)
{
  /* Terminate for MATLABSystem: '<S12>/Digital Write' */
  if (!Day3_avoidance_DW.obj_gy.matlabCodegenIsDeleted) {
    Day3_avoidance_DW.obj_gy.matlabCodegenIsDeleted = true;
    if ((Day3_avoidance_DW.obj_gy.isInitialized == 1) &&
        Day3_avoidance_DW.obj_gy.isSetupComplete) {
      EXT_GPIO_terminate(17U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S12>/Digital Write' */
  /* Terminate for MATLABSystem: '<S13>/Digital Write' */
  if (!Day3_avoidance_DW.obj_lq.matlabCodegenIsDeleted) {
    Day3_avoidance_DW.obj_lq.matlabCodegenIsDeleted = true;
    if ((Day3_avoidance_DW.obj_lq.isInitialized == 1) &&
        Day3_avoidance_DW.obj_lq.isSetupComplete) {
      EXT_GPIO_terminate(27U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S13>/Digital Write' */
  /* Terminate for MATLABSystem: '<S14>/Digital Write' */
  if (!Day3_avoidance_DW.obj_g.matlabCodegenIsDeleted) {
    Day3_avoidance_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Day3_avoidance_DW.obj_g.isInitialized == 1) &&
        Day3_avoidance_DW.obj_g.isSetupComplete) {
      EXT_GPIO_terminate(19U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S14>/Digital Write' */
  /* Terminate for MATLABSystem: '<S15>/Digital Write' */
  if (!Day3_avoidance_DW.obj_j.matlabCodegenIsDeleted) {
    Day3_avoidance_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Day3_avoidance_DW.obj_j.isInitialized == 1) &&
        Day3_avoidance_DW.obj_j.isSetupComplete) {
      EXT_GPIO_terminate(26U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/Digital Write' */
  /* Terminate for MATLABSystem: '<S3>/Ultrasonic Sensor' */
  if (!Day3_avoidance_DW.obj.matlabCodegenIsDeleted) {
    Day3_avoidance_DW.obj.matlabCodegenIsDeleted = true;
    if ((Day3_avoidance_DW.obj.isInitialized == 1) &&
        Day3_avoidance_DW.obj.isSetupComplete) {
      EXT_GPIO_terminate(24U);
      EXT_GPIO_terminate(23U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Ultrasonic Sensor' */

  /* Terminate for MATLABSystem: '<S4>/PWM' */
  if (!Day3_avoidance_DW.obj_m.matlabCodegenIsDeleted) {
    Day3_avoidance_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Day3_avoidance_DW.obj_m.isInitialized == 1) &&
        Day3_avoidance_DW.obj_m.isSetupComplete) {
      EXT_PWMBlock_terminate(Day3_avoidance_DW.obj_m.PinNumber);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM' */

  /* Terminate for MATLABSystem: '<S1>/PWM' */
  if (!Day3_avoidance_DW.obj_f.matlabCodegenIsDeleted) {
    Day3_avoidance_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Day3_avoidance_DW.obj_f.isInitialized == 1) &&
        Day3_avoidance_DW.obj_f.isSetupComplete) {
      EXT_PWMBlock_terminate(Day3_avoidance_DW.obj_f.PinNumber);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PWM' */

  /* Terminate for MATLABSystem: '<S4>/PWM1' */
  if (!Day3_avoidance_DW.obj_l.matlabCodegenIsDeleted) {
    Day3_avoidance_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Day3_avoidance_DW.obj_l.isInitialized == 1) &&
        Day3_avoidance_DW.obj_l.isSetupComplete) {
      EXT_PWMBlock_terminate(Day3_avoidance_DW.obj_l.PinNumber);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM1' */

  /* Terminate for MATLABSystem: '<S2>/PWM1' */
  if (!Day3_avoidance_DW.obj_e.matlabCodegenIsDeleted) {
    Day3_avoidance_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Day3_avoidance_DW.obj_e.isInitialized == 1) &&
        Day3_avoidance_DW.obj_e.isSetupComplete) {
      EXT_PWMBlock_terminate(Day3_avoidance_DW.obj_e.PinNumber);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PWM1' */
  /* Terminate for MATLABSystem: '<S5>/Digital Write' */
  if (!Day3_avoidance_DW.obj_mj.matlabCodegenIsDeleted) {
    Day3_avoidance_DW.obj_mj.matlabCodegenIsDeleted = true;
    if ((Day3_avoidance_DW.obj_mj.isInitialized == 1) &&
        Day3_avoidance_DW.obj_mj.isSetupComplete) {
      EXT_GPIO_terminate(15U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Write' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write' */
  if (!Day3_avoidance_DW.obj_n.matlabCodegenIsDeleted) {
    Day3_avoidance_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Day3_avoidance_DW.obj_n.isInitialized == 1) &&
        Day3_avoidance_DW.obj_n.isSetupComplete) {
      EXT_GPIO_terminate(14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write' */

  /* Terminate for MATLABSystem: '<S7>/Digital Write' */
  if (!Day3_avoidance_DW.obj_i.matlabCodegenIsDeleted) {
    Day3_avoidance_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Day3_avoidance_DW.obj_i.isInitialized == 1) &&
        Day3_avoidance_DW.obj_i.isSetupComplete) {
      EXT_GPIO_terminate(13U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Write' */

  /* Terminate for MATLABSystem: '<S8>/Digital Write' */
  if (!Day3_avoidance_DW.obj_m0.matlabCodegenIsDeleted) {
    Day3_avoidance_DW.obj_m0.matlabCodegenIsDeleted = true;
    if ((Day3_avoidance_DW.obj_m0.isInitialized == 1) &&
        Day3_avoidance_DW.obj_m0.isSetupComplete) {
      EXT_GPIO_terminate(6U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/Digital Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
