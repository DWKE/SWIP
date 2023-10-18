/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * webcam.c
 *
 * Code generation for function 'webcam'
 *
 */

/* Include files */
#include "webcam.h"
#include "edgeDetection_emxutil.h"
#include "edgeDetection_internal_types.h"
#include "edgeDetection_types.h"
#include "MW_availableWebcam.h"
#include "MW_v4l2_cam.h"
#include <stdio.h>
#include <string.h>

/* Function Definitions */
void webcam_snapshot(raspi_internal_codegen_webcam *obj,
                     emxArray_uint8_T *image)
{
  static const char cv4[128] = {
      '\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08',
      '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f', '\x10', '\x11',
      '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
      '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ',    '!',    '\"',   '#',
      '$',    '%',    '&',    '\'',   '(',    ')',    '*',    '+',    ',',
      '-',    '.',    '/',    '0',    '1',    '2',    '3',    '4',    '5',
      '6',    '7',    '8',    '9',    ':',    ';',    '<',    '=',    '>',
      '?',    '@',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
      'h',    'i',    'j',    'k',    'l',    'm',    'n',    'o',    'p',
      'q',    'r',    's',    't',    'u',    'v',    'w',    'x',    'y',
      'z',    '[',    '\\',   ']',    '^',    '_',    '`',    'a',    'b',
      'c',    'd',    'e',    'f',    'g',    'h',    'i',    'j',    'k',
      'l',    'm',    'n',    'o',    'p',    'q',    'r',    's',    't',
      'u',    'v',    'w',    'x',    'y',    'z',    '{',    '|',    '}',
      '~',    '\x7f'};
  static const char b_errorMessage[100] = {
      'W', 'e', 'b', 'c', 'a', 'm', ' ', 'c', 'a', 'n', 'n', 'o', 't', ' ', 'b',
      'e', ' ', 'i', 'n', 'i', 't', 'i', 'a', 'l', 'i', 'z', 'e', 'd', ' ', 'p',
      'r', 'o', 'p', 'e', 'r', 'l', 'y', '.', ' ', 'P', 'l', 'e', 'a', 's', 'e',
      ' ', 'c', 'h', 'e', 'c', 'k', ' ', 'i', 'f', ' ', 't', 'h', 'e', ' ', 'd',
      'e', 'v', 'i', 'c', 'e', ' ', 's', 'u', 'p', 'p', 'o', 'r', 't', 's', ' ',
      't', 'h', 'e', ' ', 's', 'p', 'e', 'c', 'i', 'f', 'i', 'e', 'd', ' ', 'r',
      'e', 's', 'o', 'l', 'u', 't', 'i', 'o', 'n', '.'};
  static const char cv3[22] = "Error opening camera.";
  static const char cv[8] = {'s', 'n', 'a', 'p', 's', 'h', 'o', 't'};
  static const char cv5[8] = {'s', 'n', 'a', 'p', 's', 'h', 'o', 't'};
  static unsigned char pln0[76800];
  double ts_data[255];
  int i;
  int i1;
  int i2;
  int idx;
  int status;
  char errorMessage[100];
  unsigned char *image_data;
  obj->Count = 1U;
  for (i = 0; i < 8; i++) {
    obj->MethodName[i] = cv[i];
  }
  if (obj->isInitialized != 1) {
    signed char resolutionStatus;
    obj->isInitialized = 1;
    getCameraList();
    if (obj->searchMode != 0.0) {
      char cv1[11];
      for (i = 0; i < 11; i++) {
        cv1[i] = obj->DeviceName[i];
      }
      obj->DeviceNumber = getCameraAddrIndex(&cv1[0], 11U);
    }
    resolutionStatus = validateResolution(obj->DeviceNumber, 320, 240);
    if (resolutionStatus >= 0) {
      status = EXT_webcamInit(1, obj->DeviceNumber, 0, 0, 0, 0, 320U, 240U, 2U,
                              2U, 1U, 0.033333333333333333);
      if (status == 0) {
        obj->Initialized = true;
      } else {
        char cv2[22];
        for (i = 0; i < 22; i++) {
          cv2[i] = cv3[i];
        }
        printf(&cv2[0]);
      }
    } else {
      memcpy(&errorMessage[0], &b_errorMessage[0], 100U * sizeof(char));
      perror(&errorMessage[0]);
      exit(0);
    }
    obj->isSetupComplete = true;
  }
  i = image->size[0] * image->size[1] * image->size[2] * image->size[3];
  image->size[0] = 240;
  image->size[1] = 320;
  image->size[2] = 3;
  image->size[3] = obj->Count;
  emxEnsureCapacity_uint8_T(image, i);
  image_data = image->data;
  status = obj->Count;
  if (status - 1 >= 0) {
    memset(&ts_data[0], 0, (unsigned int)status * sizeof(double));
  }
  i = obj->Count;
  for (idx = 0; idx < i; idx++) {
    if (obj->Initialized) {
      unsigned char pln1[76800];
      unsigned char pln2[76800];
      bool b_bool;
      b_bool = false;
      status = 0;
      int exitg1;
      do {
        exitg1 = 0;
        if (status < 8) {
          if (cv4[(unsigned char)obj->MethodName[status] & 127] !=
              cv4[(int)cv5[status]]) {
            exitg1 = 1;
          } else {
            status++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
      if (b_bool) {
        EXT_webcamCapture(1, obj->DeviceNumber, &ts_data[idx], &pln0[0],
                          &pln1[0], &pln2[0]);
      }
      for (i1 = 0; i1 < 320; i1++) {
        for (i2 = 0; i2 < 240; i2++) {
          int i3;
          status = i1 + 320 * i2;
          i3 = (i2 + 240 * i1) + 230400 * idx;
          image_data[i3] = pln0[status];
          image_data[i3 + 76800] = pln1[status];
          image_data[i3 + 153600] = pln2[status];
        }
      }
    }
  }
}

/* End of code generation (webcam.c) */
