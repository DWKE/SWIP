/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * _coder_blinkNWrite_mex.c
 *
 * Code generation for function 'blinkNWrite'
 *
 */

/* Include files */
#include "_coder_blinkNWrite_mex.h"
#include "_coder_blinkNWrite_api.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  (void)plhs;
  (void)prhs;
  mexAtExit(&blinkNWrite_atexit);
  /* Module initialization. */
  blinkNWrite_initialize();
  /* Dispatch the entry-point. */
  unsafe_blinkNWrite_mexFunction(nlhs, nrhs);
  /* Module termination. */
  blinkNWrite_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-949", true);
  return emlrtRootTLSGlobal;
}

void unsafe_blinkNWrite_mexFunction(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        11, "blinkNWrite");
  }
  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "blinkNWrite");
  }
  /* Call the function. */
  blinkNWrite_api();
}

/* End of code generation (_coder_blinkNWrite_mex.c) */
