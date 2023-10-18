/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * edgeDetection_types.h
 *
 * Code generation for function 'edgeDetection'
 *
 */

#ifndef EDGEDETECTION_TYPES_H
#define EDGEDETECTION_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Custom Header Code */
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"
/* Type Definitions */
#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T
struct emxArray_uint8_T {
  unsigned char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  bool canFreeData;
};
#endif /* struct_emxArray_uint8_T */
#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T
typedef struct emxArray_uint8_T emxArray_uint8_T;
#endif /* typedef_emxArray_uint8_T */

#endif
/* End of code generation (edgeDetection_types.h) */
