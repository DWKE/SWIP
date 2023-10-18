/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * webcam.h
 *
 * Code generation for function 'webcam'
 *
 */

#ifndef WEBCAM_H
#define WEBCAM_H

/* Include files */
#include "edgeDetection_internal_types.h"
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
void webcam_snapshot(raspi_internal_codegen_webcam *obj,
                     emxArray_uint8_T *image);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (webcam.h) */
