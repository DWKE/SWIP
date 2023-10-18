/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * blinkNWrite.c
 *
 * Code generation for function 'blinkNWrite'
 *
 */

/* Include files */
#include "blinkNWrite.h"
#include "blinkNWrite_data.h"
#include "blinkNWrite_initialize.h"
#include "fileManager.h"
#include "LED.h"
#include "coder_posix_time.h"
#include <stdio.h>

/* Function Definitions */
void blinkNWrite(void)
{
  static const char cv1[5] = "none";
  coderTimespec b_timespec;
  coderTimespec c_timespec;
  int b_i;
  int i;
  signed char fileid;
  if (!isInitialized_blinkNWrite) {
    blinkNWrite_initialize();
  }
  fileid = cfopen();
  for (i = 0; i < 7; i++) {
    FILE *filestar;
    char cv[5];
    signed char b_fileid;
    bool autoflush;
    for (b_i = 0; b_i < 5; b_i++) {
      cv[b_i] = cv1[b_i];
    }
    EXT_LED_setTrigger(0U, &cv[0]);
    EXT_LED_write(0U, 0);
    if (pauseState == 0) {
      b_timespec.tv_sec = 0.0;
      b_timespec.tv_nsec = 5.0E+8;
      coderTimeSleep(&b_timespec);
    }
    for (b_i = 0; b_i < 5; b_i++) {
      cv[b_i] = cv1[b_i];
    }
    EXT_LED_setTrigger(0U, &cv[0]);
    EXT_LED_write(0U, 1);
    if (pauseState == 0) {
      c_timespec.tv_sec = 0.0;
      c_timespec.tv_nsec = 5.0E+8;
      coderTimeSleep(&c_timespec);
    }
    b_fileid = fileid;
    if ((fileid > 22) || (fileid < 0)) {
      b_fileid = -1;
    }
    if (b_fileid >= 3) {
      filestar = eml_openfiles[b_fileid - 3];
      autoflush = eml_autoflush[b_fileid - 3];
    } else if (b_fileid == 0) {
      filestar = stdin;
      autoflush = true;
    } else if (b_fileid == 1) {
      filestar = stdout;
      autoflush = true;
    } else if (b_fileid == 2) {
      filestar = stderr;
      autoflush = true;
    } else {
      filestar = NULL;
      autoflush = true;
    }
    if (!(filestar == NULL)) {
      fprintf(filestar, "Blinking on-board LED for count = %d\n",
              (signed char)(i + 1));
      if (autoflush) {
        fflush(filestar);
      }
    }
  }
  cfclose(fileid);
}

/* End of code generation (blinkNWrite.c) */
