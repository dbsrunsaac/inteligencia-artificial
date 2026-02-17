/*
 * File: test_control_temperatura_arduino.h
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

#ifndef test_control_temperatura_arduino_h_
#define test_control_temperatura_arduino_h_
#ifndef test_control_temperatura_arduino_COMMON_INCLUDES_
#define test_control_temperatura_arduino_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#endif                   /* test_control_temperatura_arduino_COMMON_INCLUDES_ */

#include "test_control_temperatura_arduino_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define test_control_temperatura_arduino_M (test_control_temperatura_ard_M)

/* Block signals (default storage) */
typedef struct {
  real_T outputMFCache[303];
  real_T aggregatedOutputs[101];       /* '<S2>/Evaluate Rule Consequents' */
  real_T dv[101];
  real_T dv1[101];
  real_T dv2[101];
  real_T antecedentOutputs[15];        /* '<S2>/Evaluate Rule Antecedents' */
  real_T inputMFCache[8];
  real_T dv3[3];
  real_T TmpSignalConversionAtLevel2MATL[2];
  real_T Sum;                          /* '<Root>/Sum' */
  real_T Product1;                     /* '<Root>/Product1' */
  real_T defuzzifiedOutputs;           /* '<S2>/Defuzzify Outputs' */
} B_test_control_temperatura_ar_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Analog Input1' */
  codertarget_arduinobase_inter_T obj_l;/* '<Root>/Analog Input' */
  codertarget_arduinobase_int_o_T obj_i;/* '<Root>/PWM' */
} DW_test_control_temperatura_a_T;

/* Parameters (default storage) */
struct P_test_control_temperatura_ar_T_ {
  real_T OutputSamplePoints_Value[101];/* Expression: fis.outputSamplePoints
                                        * Referenced by: '<S2>/Output Sample Points'
                                        */
  real_T Constant_Value;               /* Expression: 0.04887
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 10
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0.0976
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 4.25
                                        * Referenced by: '<Root>/Constant3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test_control_temperat_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_test_control_temperatura_ar_T test_control_temperatura_ardu_P;

/* Block signals (default storage) */
extern B_test_control_temperatura_ar_T test_control_temperatura_ardu_B;

/* Block states (default storage) */
extern DW_test_control_temperatura_a_T test_control_temperatura_ard_DW;

/* External function called from main */
extern void test_control_temperatura_arduino_SetEventsForThisBaseStep(boolean_T *
  eventFlags);

/* Model entry point functions */
extern void test_control_temperatura_arduino_initialize(void);
extern void test_control_temperatura_arduino_step0(void);/* Sample time: [0.05s, 0.0s] */
extern void test_control_temperatura_arduino_step1(void);/* Sample time: [2.0s, 0.0s] */
extern void test_control_temperatura_arduino_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test_control_tempera_T *const test_control_temperatura_ard_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/InputConversion' : Eliminate redundant data type conversion
 * Block '<S1>/Zero-Order Hold' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'test_control_temperatura_arduino'
 * '<S1>'   : 'test_control_temperatura_arduino/Fuzzy Logic  Controller  with Ruleviewer'
 * '<S2>'   : 'test_control_temperatura_arduino/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller'
 * '<S3>'   : 'test_control_temperatura_arduino/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/Defuzzify Outputs'
 * '<S4>'   : 'test_control_temperatura_arduino/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/Evaluate Rule Antecedents'
 * '<S5>'   : 'test_control_temperatura_arduino/Fuzzy Logic  Controller  with Ruleviewer/Fuzzy Logic Controller/Evaluate Rule Consequents'
 */
#endif                                 /* test_control_temperatura_arduino_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
