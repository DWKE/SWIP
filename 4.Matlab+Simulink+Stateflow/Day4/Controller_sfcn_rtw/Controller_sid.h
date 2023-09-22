/*
 * Controller_sid.h
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "Controller_sf".
 *
 * Model version              : 1.1
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed Aug 30 15:30:27 2023
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: Controller_sf.c
 */

/* statically allocated instance data for model: Controller */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_Controller_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_Controller_T));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 763650684U);
    ssSetChecksumVal(rts, 1, 2512694527U);
    ssSetChecksumVal(rts, 2, 3947079430U);
    ssSetChecksumVal(rts, 3, 2370651937U);
  }
}
