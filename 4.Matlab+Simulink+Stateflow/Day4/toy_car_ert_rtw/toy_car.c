/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: toy_car.c
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

#include "toy_car.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"

/* Named constants for Chart: '<Root>/Chart' */
#define toy_car_IN_BW                  ((uint8_T)1U)
#define toy_car_IN_FAST                ((uint8_T)1U)
#define toy_car_IN_FW                  ((uint8_T)2U)
#define toy_car_IN_NO_ACTIVE_CHILD     ((uint8_T)0U)
#define toy_car_IN_OFF                 ((uint8_T)1U)
#define toy_car_IN_ON                  ((uint8_T)2U)
#define toy_car_IN_SLOW                ((uint8_T)2U)
#define toy_car_event_DIR              (2)
#define toy_car_event_SPD              (1)
#define toy_car_event_SW               (0)

/* Block states (default storage) */
DW_toy_car_T toy_car_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_toy_car_T toy_car_PrevZCX;

/* Real-time model */
static RT_MODEL_toy_car_T toy_car_M_;
RT_MODEL_toy_car_T *const toy_car_M = &toy_car_M_;

/* Forward declaration for local functions */
static void toy_car_chartstep_c3_toy_car(const int32_T *sfEvent);

/* Function for Chart: '<Root>/Chart' */
static void toy_car_chartstep_c3_toy_car(const int32_T *sfEvent)
{
  if (toy_car_DW.is_c3_toy_car == toy_car_IN_OFF) {
    if (*sfEvent == toy_car_event_SW) {
      toy_car_DW.is_c3_toy_car = toy_car_IN_ON;
      switch (toy_car_DW.was_DIRECTION) {
       case toy_car_IN_BW:
        toy_car_DW.is_DIRECTION = toy_car_IN_BW;
        toy_car_DW.was_DIRECTION = toy_car_IN_BW;
        break;

       case toy_car_IN_FW:
        toy_car_DW.is_DIRECTION = toy_car_IN_FW;
        toy_car_DW.was_DIRECTION = toy_car_IN_FW;
        break;

       default:
        toy_car_DW.is_DIRECTION = toy_car_IN_FW;
        toy_car_DW.was_DIRECTION = toy_car_IN_FW;
        break;
      }

      switch (toy_car_DW.was_SPEED) {
       case toy_car_IN_FAST:
        toy_car_DW.is_SPEED = toy_car_IN_FAST;
        toy_car_DW.was_SPEED = toy_car_IN_FAST;
        break;

       case toy_car_IN_SLOW:
        toy_car_DW.is_SPEED = toy_car_IN_SLOW;
        toy_car_DW.was_SPEED = toy_car_IN_SLOW;
        break;

       default:
        toy_car_DW.is_SPEED = toy_car_IN_SLOW;
        toy_car_DW.was_SPEED = toy_car_IN_SLOW;
        break;
      }
    }

    /* case IN_ON: */
  } else if (*sfEvent == toy_car_event_SW) {
    toy_car_DW.is_SPEED = toy_car_IN_NO_ACTIVE_CHILD;
    toy_car_DW.is_DIRECTION = toy_car_IN_NO_ACTIVE_CHILD;
    toy_car_DW.is_c3_toy_car = toy_car_IN_OFF;
  } else {
    if (toy_car_DW.is_DIRECTION == toy_car_IN_BW) {
      if (*sfEvent == toy_car_event_DIR) {
        toy_car_DW.is_DIRECTION = toy_car_IN_FW;
        toy_car_DW.was_DIRECTION = toy_car_IN_FW;
      }

      /* case IN_FW: */
    } else if (*sfEvent == toy_car_event_DIR) {
      toy_car_DW.is_DIRECTION = toy_car_IN_BW;
      toy_car_DW.was_DIRECTION = toy_car_IN_BW;
    }

    if (toy_car_DW.is_SPEED == toy_car_IN_FAST) {
      if (*sfEvent == toy_car_event_SPD) {
        toy_car_DW.is_SPEED = toy_car_IN_SLOW;
        toy_car_DW.was_SPEED = toy_car_IN_SLOW;
      }

      /* case IN_SLOW: */
    } else if (*sfEvent == toy_car_event_SPD) {
      toy_car_DW.is_SPEED = toy_car_IN_FAST;
      toy_car_DW.was_SPEED = toy_car_IN_FAST;
    }
  }
}

/* Model step function */
void toy_car_step(void)
{
  int32_T sfEvent;
  ZCEventType zcEvent_idx_0;
  ZCEventType zcEvent_idx_1;
  ZCEventType zcEvent_idx_2;

  /* Chart: '<Root>/Chart' incorporates:
   *  TriggerPort: '<S1>/input events'
   */
  /* Constant: '<S4>/Constant' */
  zcEvent_idx_0 = rt_ZCFcn(ANY_ZERO_CROSSING,&toy_car_PrevZCX.Chart_Trig_ZCE[0],
    (1.0));

  /* Constant: '<S3>/Constant' */
  zcEvent_idx_1 = rt_ZCFcn(ANY_ZERO_CROSSING,&toy_car_PrevZCX.Chart_Trig_ZCE[1],
    (0.0));

  /* Constant: '<S2>/Constant' */
  zcEvent_idx_2 = rt_ZCFcn(ANY_ZERO_CROSSING,&toy_car_PrevZCX.Chart_Trig_ZCE[2],
    (0.0));
  if ((zcEvent_idx_0 != NO_ZCEVENT) || (zcEvent_idx_1 != NO_ZCEVENT) ||
      (zcEvent_idx_2 != NO_ZCEVENT)) {
    if ((int32_T)zcEvent_idx_0 != 0) {
      sfEvent = toy_car_event_SW;
      toy_car_chartstep_c3_toy_car(&sfEvent);
    }

    if ((int32_T)zcEvent_idx_1 != 0) {
      sfEvent = toy_car_event_SPD;
      toy_car_chartstep_c3_toy_car(&sfEvent);
    }

    if ((int32_T)zcEvent_idx_2 != 0) {
      sfEvent = toy_car_event_DIR;
      toy_car_chartstep_c3_toy_car(&sfEvent);
    }
  }
}

/* Model initialize function */
void toy_car_initialize(void)
{
  toy_car_PrevZCX.Chart_Trig_ZCE[0] = UNINITIALIZED_ZCSIG;
  toy_car_PrevZCX.Chart_Trig_ZCE[1] = UNINITIALIZED_ZCSIG;
  toy_car_PrevZCX.Chart_Trig_ZCE[2] = UNINITIALIZED_ZCSIG;

  /* Chart: '<Root>/Chart' */
  toy_car_DW.is_c3_toy_car = toy_car_IN_OFF;
}

/* Model terminate function */
void toy_car_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
