/*
 * File: test_control_temperatura_arduino.c
 *
 * Code generated for Simulink model 'test_control_temperatura_arduino'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Tue Jan 20 11:19:03 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_control_temperatura_arduino.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "test_control_temperatura_arduino_private.h"

/* Block signals (default storage) */
B_test_control_temperatura_ar_T test_control_temperatura_ardu_B;

/* Block states (default storage) */
DW_test_control_temperatura_a_T test_control_temperatura_ard_DW;

/* Real-time model */
static RT_MODEL_test_control_tempera_T test_control_temperatura_ard_M_;
RT_MODEL_test_control_tempera_T *const test_control_temperatura_ard_M =
  &test_control_temperatura_ard_M_;

/* Forward declaration for local functions */
static real_T test_control_temperatura_trapmf(real_T x, const real_T params[4]);
static real_T test_control_temperatura__trimf(real_T x, const real_T params[3]);
static void test_control_temperatu_trapmf_g(const real_T x[101], const real_T
  params[4], real_T y[101]);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void test_control_temperatura_arduino_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(test_control_temperatura_ard_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (test_control_temperatura_ard_M->Timing.TaskCounters.TID[1])++;
  if ((test_control_temperatura_ard_M->Timing.TaskCounters.TID[1]) > 39) {/* Sample time: [2.0s, 0.0s] */
    test_control_temperatura_ard_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Function for MATLAB Function: '<S2>/Evaluate Rule Antecedents' */
static real_T test_control_temperatura_trapmf(real_T x, const real_T params[4])
{
  real_T b_x;
  real_T y;
  b_x = 0.0;
  y = 0.0;
  if (x >= params[1]) {
    b_x = 1.0;
  }

  if (x < params[0]) {
    b_x = 0.0;
  }

  if ((params[0] <= x) && (x < params[1]) && (params[0] != params[1])) {
    b_x = 1.0 / (params[1] - params[0]) * (x - params[0]);
  }

  if (x <= params[2]) {
    y = 1.0;
  }

  if (x > params[3]) {
    y = 0.0;
  }

  if ((params[2] < x) && (x <= params[3]) && (params[2] != params[3])) {
    y = 1.0 / (params[3] - params[2]) * (params[3] - x);
  }

  if ((b_x <= y) || rtIsNaN(y)) {
    y = b_x;
  }

  return y;
}

/* Function for MATLAB Function: '<S2>/Evaluate Rule Antecedents' */
static real_T test_control_temperatura__trimf(real_T x, const real_T params[3])
{
  real_T y;
  y = 0.0;
  if ((params[0] != params[1]) && (params[0] < x) && (x < params[1])) {
    y = 1.0 / (params[1] - params[0]) * (x - params[0]);
  }

  if ((params[1] != params[2]) && (params[1] < x) && (x < params[2])) {
    y = 1.0 / (params[2] - params[1]) * (params[2] - x);
  }

  if (x == params[1]) {
    y = 1.0;
  }

  return y;
}

/* Function for MATLAB Function: '<S2>/Evaluate Rule Consequents' */
static void test_control_temperatu_trapmf_g(const real_T x[101], const real_T
  params[4], real_T y[101])
{
  real_T a;
  real_T b;
  real_T b_y1;
  real_T c;
  real_T d;
  real_T x_0;
  real_T y2;
  int16_T i;
  a = params[0];
  b = params[1];
  c = params[2];
  d = params[3];
  for (i = 0; i < 101; i++) {
    b_y1 = 0.0;
    y2 = 0.0;
    x_0 = x[i];
    if (x_0 >= b) {
      b_y1 = 1.0;
    }

    if (x_0 < a) {
      b_y1 = 0.0;
    }

    if ((a <= x_0) && (x_0 < b) && (a != b)) {
      b_y1 = 1.0 / (b - a) * (x_0 - a);
    }

    if (x_0 <= c) {
      y2 = 1.0;
    }

    if (x_0 > d) {
      y2 = 0.0;
    }

    if ((c < x_0) && (x_0 <= d) && (c != d)) {
      y2 = 1.0 / (d - c) * (d - x_0);
    }

    if ((b_y1 <= y2) || rtIsNaN(y2)) {
      y[i] = b_y1;
    } else {
      y[i] = y2;
    }
  }
}

/* Model step function for TID0 */
void test_control_temperatura_arduino_step0(void) /* Sample time: [0.05s, 0.0s] */
{
  {                                    /* Sample time: [0.05s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void test_control_temperatura_arduino_step1(void) /* Sample time: [2.0s, 0.0s] */
{
  int16_T ruleID;
  int16_T sampleID;
  uint16_T b_varargout_1;
  static const real_T b[4] = { -10.0, -10.0, -5.0, 2.5 };

  static const real_T c[4] = { 30.0, 35.0, 40.0, 40.0 };

  static const real_T d[4] = { 0.0, 0.0, 10.0, 30.0 };

  static const real_T e[4] = { 70.0, 90.0, 100.0, 100.0 };

  static const real_T b_0[4] = { 0.0, 0.0, 10.0, 20.0 };

  static const int8_T f[30] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1,
    1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3 };

  static const real_T c_0[4] = { 10.0, 25.0, 35.0, 50.0 };

  static const real_T d_0[4] = { 40.0, 50.0, 60.0, 60.0 };

  static const int8_T e_0[15] = { 1, 1, 2, 3, 3, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1 };

  /* MATLABSystem: '<Root>/Analog Input' */
  test_control_temperatura_ard_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(14UL);
  MW_AnalogInSingle_ReadResult
    (test_control_temperatura_ard_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  MATLABSystem: '<Root>/Analog Input'
   *  Product: '<Root>/Product'
   * */
  test_control_temperatura_ardu_B.Sum = (real_T)b_varargout_1 *
    test_control_temperatura_ardu_P.Constant_Value -
    test_control_temperatura_ardu_P.Constant1_Value;

  /* MATLABSystem: '<Root>/Analog Input1' */
  test_control_temperatura_ard_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(15UL);
  MW_AnalogInSingle_ReadResult
    (test_control_temperatura_ard_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Product: '<Root>/Product1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  MATLABSystem: '<Root>/Analog Input1'
   * */
  test_control_temperatura_ardu_B.Product1 = (real_T)b_varargout_1 *
    test_control_temperatura_ardu_P.Constant2_Value;

  /* SignalConversion generated from: '<S1>/Level-2 MATLAB S-Function' */
  test_control_temperatura_ardu_B.TmpSignalConversionAtLevel2MATL[0] =
    test_control_temperatura_ardu_B.Sum;
  test_control_temperatura_ardu_B.TmpSignalConversionAtLevel2MATL[1] =
    test_control_temperatura_ardu_B.Product1;

  /* Outputs for Atomic SubSystem: '<S1>/Fuzzy Logic Controller' */
  /* MATLAB Function: '<S2>/Evaluate Rule Antecedents' incorporates:
   *  SignalConversion generated from: '<S4>/ SFunction '
   */
  test_control_temperatura_ardu_B.defuzzifiedOutputs = 0.0;
  test_control_temperatura_ardu_B.inputMFCache[0] =
    test_control_temperatura_trapmf(test_control_temperatura_ardu_B.Sum, b);
  test_control_temperatura_ardu_B.dv3[0] = -5.0;
  test_control_temperatura_ardu_B.dv3[1] = 2.5;
  test_control_temperatura_ardu_B.dv3[2] = 10.0;
  test_control_temperatura_ardu_B.inputMFCache[1] =
    test_control_temperatura__trimf(test_control_temperatura_ardu_B.Sum,
    test_control_temperatura_ardu_B.dv3);
  test_control_temperatura_ardu_B.dv3[0] = 5.0;
  test_control_temperatura_ardu_B.dv3[1] = 15.0;
  test_control_temperatura_ardu_B.dv3[2] = 25.0;
  test_control_temperatura_ardu_B.inputMFCache[2] =
    test_control_temperatura__trimf(test_control_temperatura_ardu_B.Sum,
    test_control_temperatura_ardu_B.dv3);
  test_control_temperatura_ardu_B.dv3[0] = 15.0;
  test_control_temperatura_ardu_B.dv3[1] = 25.0;
  test_control_temperatura_ardu_B.dv3[2] = 35.0;
  test_control_temperatura_ardu_B.inputMFCache[3] =
    test_control_temperatura__trimf(test_control_temperatura_ardu_B.Sum,
    test_control_temperatura_ardu_B.dv3);
  test_control_temperatura_ardu_B.inputMFCache[4] =
    test_control_temperatura_trapmf(test_control_temperatura_ardu_B.Sum, c);
  test_control_temperatura_ardu_B.inputMFCache[5] =
    test_control_temperatura_trapmf(test_control_temperatura_ardu_B.Product1, d);
  test_control_temperatura_ardu_B.dv3[0] = 20.0;
  test_control_temperatura_ardu_B.dv3[1] = 50.0;
  test_control_temperatura_ardu_B.dv3[2] = 80.0;
  test_control_temperatura_ardu_B.inputMFCache[6] =
    test_control_temperatura__trimf(test_control_temperatura_ardu_B.Product1,
    test_control_temperatura_ardu_B.dv3);
  test_control_temperatura_ardu_B.inputMFCache[7] =
    test_control_temperatura_trapmf(test_control_temperatura_ardu_B.Product1, e);
  for (ruleID = 0; ruleID < 15; ruleID++) {
    test_control_temperatura_ardu_B.Product1 = 1.0;
    test_control_temperatura_ardu_B.Sum =
      test_control_temperatura_ardu_B.inputMFCache[f[ruleID] - 1];
    if (test_control_temperatura_ardu_B.Sum < 1.0) {
      test_control_temperatura_ardu_B.Product1 =
        test_control_temperatura_ardu_B.Sum;
    }

    test_control_temperatura_ardu_B.Sum =
      test_control_temperatura_ardu_B.inputMFCache[f[ruleID + 15] + 4];
    if (test_control_temperatura_ardu_B.Product1 >
        test_control_temperatura_ardu_B.Sum) {
      test_control_temperatura_ardu_B.Product1 =
        test_control_temperatura_ardu_B.Sum;
    }

    test_control_temperatura_ardu_B.antecedentOutputs[ruleID] =
      test_control_temperatura_ardu_B.Product1;
    test_control_temperatura_ardu_B.defuzzifiedOutputs +=
      test_control_temperatura_ardu_B.Product1;
  }

  /* MATLAB Function: '<S2>/Evaluate Rule Consequents' incorporates:
   *  Constant: '<S2>/Output Sample Points'
   */
  test_control_temperatu_trapmf_g
    (test_control_temperatura_ardu_P.OutputSamplePoints_Value, b_0,
     test_control_temperatura_ardu_B.dv);
  test_control_temperatu_trapmf_g
    (test_control_temperatura_ardu_P.OutputSamplePoints_Value, c_0,
     test_control_temperatura_ardu_B.dv1);
  test_control_temperatu_trapmf_g
    (test_control_temperatura_ardu_P.OutputSamplePoints_Value, d_0,
     test_control_temperatura_ardu_B.dv2);
  for (ruleID = 0; ruleID < 101; ruleID++) {
    test_control_temperatura_ardu_B.aggregatedOutputs[ruleID] = 0.0;
    test_control_temperatura_ardu_B.outputMFCache[3 * ruleID] =
      test_control_temperatura_ardu_B.dv[ruleID];
    test_control_temperatura_ardu_B.outputMFCache[3 * ruleID + 1] =
      test_control_temperatura_ardu_B.dv1[ruleID];
    test_control_temperatura_ardu_B.outputMFCache[3 * ruleID + 2] =
      test_control_temperatura_ardu_B.dv2[ruleID];
  }

  for (ruleID = 0; ruleID < 15; ruleID++) {
    test_control_temperatura_ardu_B.Sum =
      test_control_temperatura_ardu_B.antecedentOutputs[ruleID];
    for (sampleID = 0; sampleID < 101; sampleID++) {
      test_control_temperatura_ardu_B.Product1 =
        test_control_temperatura_ardu_B.outputMFCache[(3 * sampleID + e_0[ruleID])
        - 1];
      if (test_control_temperatura_ardu_B.Product1 >
          test_control_temperatura_ardu_B.Sum) {
        test_control_temperatura_ardu_B.Product1 =
          test_control_temperatura_ardu_B.Sum;
      } else if (rtIsNaN(test_control_temperatura_ardu_B.Product1)) {
        test_control_temperatura_ardu_B.Product1 =
          test_control_temperatura_ardu_B.Sum;
      }

      if (test_control_temperatura_ardu_B.aggregatedOutputs[sampleID] <
          test_control_temperatura_ardu_B.Product1) {
        test_control_temperatura_ardu_B.aggregatedOutputs[sampleID] =
          test_control_temperatura_ardu_B.Product1;
      }
    }
  }

  /* End of MATLAB Function: '<S2>/Evaluate Rule Consequents' */

  /* MATLAB Function: '<S2>/Defuzzify Outputs' incorporates:
   *  Constant: '<S2>/Output Sample Points'
   *  MATLAB Function: '<S2>/Evaluate Rule Antecedents'
   */
  if (test_control_temperatura_ardu_B.defuzzifiedOutputs == 0.0) {
    test_control_temperatura_ardu_B.defuzzifiedOutputs = 30.0;
  } else {
    test_control_temperatura_ardu_B.defuzzifiedOutputs = 0.0;
    test_control_temperatura_ardu_B.Sum = 0.0;
    for (ruleID = 0; ruleID < 101; ruleID++) {
      test_control_temperatura_ardu_B.Sum +=
        test_control_temperatura_ardu_B.aggregatedOutputs[ruleID];
    }

    if (test_control_temperatura_ardu_B.Sum == 0.0) {
      test_control_temperatura_ardu_B.defuzzifiedOutputs =
        (test_control_temperatura_ardu_P.OutputSamplePoints_Value[0] +
         test_control_temperatura_ardu_P.OutputSamplePoints_Value[100]) / 2.0;
    } else {
      for (ruleID = 0; ruleID < 101; ruleID++) {
        test_control_temperatura_ardu_B.defuzzifiedOutputs +=
          test_control_temperatura_ardu_P.OutputSamplePoints_Value[ruleID] *
          test_control_temperatura_ardu_B.aggregatedOutputs[ruleID];
      }

      test_control_temperatura_ardu_B.defuzzifiedOutputs *= 1.0 /
        test_control_temperatura_ardu_B.Sum;
    }
  }

  /* End of MATLAB Function: '<S2>/Defuzzify Outputs' */
  /* End of Outputs for SubSystem: '<S1>/Fuzzy Logic Controller' */

  /* MATLABSystem: '<Root>/PWM' */
  test_control_temperatura_ard_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(5UL);

  /* Product: '<Root>/Product2' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  test_control_temperatura_ardu_B.defuzzifiedOutputs *=
    test_control_temperatura_ardu_P.Constant3_Value;

  /* Start for MATLABSystem: '<Root>/PWM' */
  if (!(test_control_temperatura_ardu_B.defuzzifiedOutputs <= 255.0)) {
    test_control_temperatura_ardu_B.defuzzifiedOutputs = 255.0;
  }

  if (!(test_control_temperatura_ardu_B.defuzzifiedOutputs >= 0.0)) {
    test_control_temperatura_ardu_B.defuzzifiedOutputs = 0.0;
  }

  /* MATLABSystem: '<Root>/PWM' */
  MW_PWM_SetDutyCycle
    (test_control_temperatura_ard_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE,
     test_control_temperatura_ardu_B.defuzzifiedOutputs);
}

/* Model initialize function */
void test_control_temperatura_arduino_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  test_control_temperatura_ard_DW.obj_l.matlabCodegenIsDeleted = false;
  test_control_temperatura_ard_DW.obj_l.isInitialized = 1L;
  test_control_temperatura_ard_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(14UL);
  test_control_temperatura_ard_DW.obj_l.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  test_control_temperatura_ard_DW.obj.matlabCodegenIsDeleted = false;
  test_control_temperatura_ard_DW.obj.isInitialized = 1L;
  test_control_temperatura_ard_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(15UL);
  test_control_temperatura_ard_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  test_control_temperatura_ard_DW.obj_i.matlabCodegenIsDeleted = false;
  test_control_temperatura_ard_DW.obj_i.isInitialized = 1L;
  test_control_temperatura_ard_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open
    (5UL, 0.0, 0.0);
  test_control_temperatura_ard_DW.obj_i.isSetupComplete = true;
}

/* Model terminate function */
void test_control_temperatura_arduino_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  if (!test_control_temperatura_ard_DW.obj_l.matlabCodegenIsDeleted) {
    test_control_temperatura_ard_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((test_control_temperatura_ard_DW.obj_l.isInitialized == 1L) &&
        test_control_temperatura_ard_DW.obj_l.isSetupComplete) {
      test_control_temperatura_ard_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE
        = MW_AnalogIn_GetHandle(14UL);
      MW_AnalogIn_Close
        (test_control_temperatura_ard_DW.obj_l.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input' */

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  if (!test_control_temperatura_ard_DW.obj.matlabCodegenIsDeleted) {
    test_control_temperatura_ard_DW.obj.matlabCodegenIsDeleted = true;
    if ((test_control_temperatura_ard_DW.obj.isInitialized == 1L) &&
        test_control_temperatura_ard_DW.obj.isSetupComplete) {
      test_control_temperatura_ard_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(15UL);
      MW_AnalogIn_Close
        (test_control_temperatura_ard_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Analog Input1' */
  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!test_control_temperatura_ard_DW.obj_i.matlabCodegenIsDeleted) {
    test_control_temperatura_ard_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((test_control_temperatura_ard_DW.obj_i.isInitialized == 1L) &&
        test_control_temperatura_ard_DW.obj_i.isSetupComplete) {
      test_control_temperatura_ard_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle
        (test_control_temperatura_ard_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      test_control_temperatura_ard_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);
      MW_PWM_Close
        (test_control_temperatura_ard_DW.obj_i.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
