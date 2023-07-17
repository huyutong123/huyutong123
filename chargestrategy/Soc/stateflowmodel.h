/*
 * File: stateflowmodel.h
 *
 * Code generated for Simulink model 'stateflowmodel'.
 *
 * Model version                  : 1.28
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Tue Jun 13 19:35:25 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_stateflowmodel_h_
#define RTW_HEADER_stateflowmodel_h_
#include <math.h>
#ifndef stateflowmodel_COMMON_INCLUDES_
# define stateflowmodel_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* stateflowmodel_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (auto storage) for system '<S1>/AH_calu1' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S3>/Delay' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S3>/Discrete-Time Integrator1' */
  uint32_T AH_calu1_PREV_T;            /* '<S1>/AH_calu1' */
  uint8_T DiscreteTimeIntegrator1_SYSTEM_;/* '<S3>/Discrete-Time Integrator1' */
} DW_AH_calu1;

/* Block signals and states (auto storage) for system '<S1>/AH_calu' */
typedef struct {
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S2>/Discrete-Time Integrator1' */
  real_T Delay_DSTATE;                 /* '<S2>/Delay' */
  uint32_T AH_calu_PREV_T;             /* '<S1>/AH_calu' */
} DW_AH_calu;

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  DW_AH_calu AH_calu_m;                /* '<S1>/AH_calu' */
  DW_AH_calu1 AH_calu1_g;              /* '<S1>/AH_calu1' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S4>/Discrete-Time Integrator1' */
  real_T Delay_DSTATE;                 /* '<S4>/Delay' */
  real_T temp_soc;                     /* '<Root>/Chart1' */
  uint32_T Ah_calu_map_PREV_T;         /* '<S1>/Ah_calu_map' */
  uint8_T is_active_c2_stateflowmodel; /* '<Root>/Chart1' */
  uint8_T is_c2_stateflowmodel;        /* '<Root>/Chart1' */
} DW;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: [0 7 7 14 14 28 28 28 28 28 28 28 28
     ;0	7	18	42	42	71	71	71	71	56	42	42	28;0	18	28	71	113	142	170	170	170	113	85	85	56
     ;0	18	28	71	113	142	170	170	170	113	85	85	56
     ;0	14	18	42	85	113	142	142	142	85	71	71	42
     ;0	14	18	42	71	113	142	142	142	85	71	71	42
     ;0	14	18	42	71	113	142	142	142	85	56	56	28
     ;0	7	18	42	71	113	113	113	113	85	56	56	28
     ;0	7	18	42	71	113	113	113	113	85	42	42	28
     ;0	7	18	18	28	28	71	71	71	56	28	28	14
     ;0	7	7	7	28	28	42	42	42	56	28	28	14
     ;0	7	7	7	14	14	28	28	28	28	14	14	7
     ]
   * Referenced by: '<S3>/Curr_table1'
   */
  real_T Curr_table1_table[156];

  /* Pooled Parameter (Expression: [0,5,[10:10:90],95,100])
   * Referenced by:
   *   '<S2>/SOC_table1'
   *   '<S3>/SOC_table1'
   *   '<S4>/SOC_table1'
   */
  real_T pooled6[13];

  /* Pooled Parameter (Expression: [-30,[0:5:50],52,55])
   * Referenced by:
   *   '<S2>/Temp_table1'
   *   '<S3>/Temp_table1'
   *   '<S4>/Temp_table1'
   */
  real_T pooled7[14];

  /* Expression: reshape([0,0,0,0,0,0,0,0,0,0,0,0,7,7,18,18,14,14,14,7,7,7,7,7,7,18,28,28,18,18,18,18,18,18,7,7,14,42,71,71,42,42,42,42,42,18,7,7,14,42,113,113,85,71,71,71,42,28,28,14,28,71,142,142,113,113,113,113,113,28,28,14,28,71,170,170,142,142,142,113,113,71,42,28,28,71,170,170,142,142,142,113,113,71,42,28,28,71,170,170,142,142,142,113,113,71,42,28,28,56,113,113,85,85,85,85,85,56,56,28,28,42,85,85,71,71,56,56,42,28,28,14,28,42,85,85,71,71,56,56,42,28,28,14,28,28,56,56,42,42,28,28,28,14,14,7],12,13)
   * Referenced by: '<S2>/Curr_table1'
   */
  real_T Curr_table1_table_p[156];

  /* Expression: reshape([0,0,0,0,0,0,0,0,0,0,0,0,7,7,18,18,14,14,14,7,7,7,7,7,7,18,28,28,18,18,18,18,18,18,7,7,14,42,71,71,42,42,42,42,42,18,7,7,14,42,113,113,85,71,71,71,42,28,28,14,28,71,142,142,113,113,113,113,113,28,28,14,28,71,170,170,142,142,142,113,113,71,41,28,28,71,170,170,142,142,142,113,113,71,41,28,28,71,170,170,142,142,142,113,113,71,41,28,28,56,113,113,85,85,85,85,85,56,56,28,28,42,85,85,71,71,56,56,42,28,28,14,28,42,85,85,71,71,56,56,42,28,28,14,28,28,56,56,42,42,28,28,28,14,14,7],12,13)
   * Referenced by: '<S4>/Curr_table1'
   */
  real_T Curr_table1_table_j[156];
} ConstP;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
  real_T In2;                          /* '<Root>/In2' */
  real_T In3;                          /* '<Root>/In3' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block signals and states (auto storage) */
extern DW rtDW;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Constant parameters (auto storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void stateflowmodel_initialize(void);
extern void stateflowmodel_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * '<Root>' : 'stateflowmodel'
 * '<S1>'   : 'stateflowmodel/Chart1'
 * '<S2>'   : 'stateflowmodel/Chart1/AH_calu'
 * '<S3>'   : 'stateflowmodel/Chart1/AH_calu1'
 * '<S4>'   : 'stateflowmodel/Chart1/Ah_calu_map'
 * '<S5>'   : 'stateflowmodel/Chart1/AH_calu/Cap_table'
 * '<S6>'   : 'stateflowmodel/Chart1/AH_calu1/Cap_table'
 * '<S7>'   : 'stateflowmodel/Chart1/Ah_calu_map/Cap_table'
 */
#endif                                 /* RTW_HEADER_stateflowmodel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
