/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * edgeDetection_internal_types.h
 *
 * Code generation for function 'edgeDetection'
 *
 */

#ifndef EDGEDETECTION_INTERNAL_TYPES_H
#define EDGEDETECTION_INTERNAL_TYPES_H

/* Include files */
#include "edgeDetection_types.h"
#include "rtwtypes.h"

/* Custom Header Code */
#include "MW_raspi_init.h"
#include "MW_Pyserver_control.h"
/* Type Definitions */
#ifndef typedef_raspi_internal_codegen_webcam
#define typedef_raspi_internal_codegen_webcam
typedef struct {
  bool matlabCodegenIsDeleted;
  int isInitialized;
  bool isSetupComplete;
  bool Initialized;
  unsigned char DeviceNumber;
  double searchMode;
  char DeviceName[11];
  char MethodName[8];
  unsigned char Count;
} raspi_internal_codegen_webcam;
#endif /* typedef_raspi_internal_codegen_webcam */

#endif
/* End of code generation (edgeDetection_internal_types.h) */
