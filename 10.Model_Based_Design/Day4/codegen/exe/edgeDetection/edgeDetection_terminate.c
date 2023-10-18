/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * edgeDetection_terminate.c
 *
 * Code generation for function 'edgeDetection_terminate'
 *
 */

/* Include files */
#include "edgeDetection_terminate.h"
#include "edgeDetection_data.h"
#include "omp.h"

/* Function Definitions */
void edgeDetection_terminate(void)
{
  /* user code (Terminate function Body) */
  {
    MW_killPyserver();
    mwRaspiTerminate();
  }

  omp_destroy_nest_lock(&edgeDetection_nestLockGlobal);
  isInitialized_edgeDetection = false;
}

/* End of code generation (edgeDetection_terminate.c) */
