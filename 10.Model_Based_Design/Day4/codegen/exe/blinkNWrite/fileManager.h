/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * fileManager.h
 *
 * Code generation for function 'fileManager'
 *
 */

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

/* Include files */
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
int cfclose(double fid);

signed char cfopen(void);

void filedata_init(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (fileManager.h) */
