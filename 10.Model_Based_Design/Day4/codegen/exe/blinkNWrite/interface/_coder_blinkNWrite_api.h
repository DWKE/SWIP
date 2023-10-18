/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * _coder_blinkNWrite_api.h
 *
 * Code generation for function 'blinkNWrite'
 *
 */

#ifndef _CODER_BLINKNWRITE_API_H
#define _CODER_BLINKNWRITE_API_H

/* Include files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void blinkNWrite(void);

void blinkNWrite_api(void);

void blinkNWrite_atexit(void);

void blinkNWrite_initialize(void);

void blinkNWrite_terminate(void);

void blinkNWrite_xil_shutdown(void);

void blinkNWrite_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_blinkNWrite_api.h) */
