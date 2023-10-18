/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * edgeDetection_initialize.c
 *
 * Code generation for function 'edgeDetection_initialize'
 *
 */

/* Include files */
#include "edgeDetection_initialize.h"
#include "edgeDetection_data.h"
#include "omp.h"

/* Function Definitions */
void edgeDetection_initialize(void)
{
  omp_init_nest_lock(&edgeDetection_nestLockGlobal);
  /* user code (Initialize function Body) */
  {
    mwRaspiInit();
    MW_launchPyserver();
  }

  isInitialized_edgeDetection = true;
}

/* End of code generation (edgeDetection_initialize.c) */
