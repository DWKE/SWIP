/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * edgeDetection_emxutil.h
 *
 * Code generation for function 'edgeDetection_emxutil'
 *
 */

#ifndef EDGEDETECTION_EMXUTIL_H
#define EDGEDETECTION_EMXUTIL_H

/* Include files */
#include "edgeDetection_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

/* Custom Header Code */
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray, int oldNumel);

extern void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);

extern void emxInit_uint8_T(emxArray_uint8_T **pEmxArray);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (edgeDetection_emxutil.h) */
