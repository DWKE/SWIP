/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * edgeDetection.c
 *
 * Code generation for function 'edgeDetection'
 *
 */

/* Include files */
#include "edgeDetection.h"
#include "edgeDetection_data.h"
#include "edgeDetection_emxutil.h"
#include "edgeDetection_initialize.h"
#include "edgeDetection_internal_types.h"
#include "edgeDetection_types.h"
#include "webcam.h"
#include "MW_v4l2_cam.h"

/* Function Definitions */
void edgeDetection(void)
{
  static const char cv[11] = {'/', 'd', 'e', 'v', '/', 'v',
                              'i', 'd', 'e', 'o', '0'};
  emxArray_uint8_T *b_w;
  raspi_internal_codegen_webcam w;
  int k;
  if (!isInitialized_edgeDetection) {
    edgeDetection_initialize();
  }
  w.Initialized = false;
  w.DeviceNumber = 0U;
  w.searchMode = 0.0;
  for (k = 0; k < 11; k++) {
    w.DeviceName[k] = cv[k];
  }
  w.isInitialized = 0;
  w.matlabCodegenIsDeleted = false;
  emxInit_uint8_T(&b_w);
  for (k = 0; k < 200; k++) {
    webcam_snapshot(&w, b_w);
  }
  emxFree_uint8_T(&b_w);
  if ((!w.matlabCodegenIsDeleted) && (w.isInitialized == 1) &&
      w.isSetupComplete && w.Initialized) {
    EXT_webcamTerminate(1, w.DeviceNumber);
  }
}

/* End of code generation (edgeDetection.c) */
