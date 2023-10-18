/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * blinkNWrite_initialize.c
 *
 * Code generation for function 'blinkNWrite_initialize'
 *
 */

/* Include files */
#include "blinkNWrite_initialize.h"
#include "blinkNWrite_data.h"
#include "fileManager.h"
#include "pause.h"

/* Function Definitions */
void blinkNWrite_initialize(void)
{
  filedata_init();
  cpause_init();
  /* user code (Initialize function Body) */
  {
    mwRaspiInit();
    MW_launchPyserver();
  }

  isInitialized_blinkNWrite = true;
}

/* End of code generation (blinkNWrite_initialize.c) */
