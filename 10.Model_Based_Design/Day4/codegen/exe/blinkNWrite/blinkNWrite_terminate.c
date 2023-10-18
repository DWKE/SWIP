/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * blinkNWrite_terminate.c
 *
 * Code generation for function 'blinkNWrite_terminate'
 *
 */

/* Include files */
#include "blinkNWrite_terminate.h"
#include "blinkNWrite_data.h"

/* Function Definitions */
void blinkNWrite_terminate(void)
{
  /* user code (Terminate function Body) */
  {
    MW_killPyserver();
    mwRaspiTerminate();
  }

  isInitialized_blinkNWrite = false;
}

/* End of code generation (blinkNWrite_terminate.c) */
