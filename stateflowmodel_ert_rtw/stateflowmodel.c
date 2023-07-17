/*
 * File: stateflowmodel.c
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

#include "stateflowmodel.h"

/* Named constants for Chart: '<Root>/Chart1' */
#define IN_Correct100_soc              ((uint8_T)1U)
#define IN_Correct91_0_1Ah             ((uint8_T)2U)
#define IN_Correct91_1_Ah              ((uint8_T)3U)
#define IN_Correct94_1_Ah              ((uint8_T)4U)
#define IN_Init                        ((uint8_T)5U)

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_roundd_snf(real_T u);
uint32_T plook_binx(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                    *fraction);
uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex);
extern void Cap_table(real_T rtu_T, real_T *rty_CAP);
extern void AH_calu1_Init(RT_MODEL * const rtM, DW_AH_calu1 *localDW);
extern void AH_calu1_Enable(DW_AH_calu1 *localDW);
extern void AH_calu1(RT_MODEL * const rtM, real_T rtu_T, real_T rtu_soc, real_T *
                     rty_BMS_SOC, DW_AH_calu1 *localDW);
extern void AH_calu_Init(RT_MODEL * const rtM, DW_AH_calu *localDW);
extern void AH_calu(RT_MODEL * const rtM, real_T rtu_T, real_T rtu_soc, real_T
                    *rty_BMS_SOC, DW_AH_calu *localDW);
uint32_T plook_binx(real_T u, const real_T bp[], uint32_T maxIndex, real_T
                    *fraction)
{
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
    *fraction = (u - bp[0U]) / (bp[1U] - bp[0U]);
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32d(u, bp, maxIndex >> 1U, maxIndex);
    *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = (u - bp[maxIndex - 1U]) / (bp[maxIndex] - bp[maxIndex - 1U]);
  }

  return bpIndex;
}

uint32_T binsearch_u32d(real_T u, const real_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIndex;
  uint32_T iRght;
  uint32_T bpIdx;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

/*
 * Output and update for atomic system:
 *    '<S3>/Cap_table'
 *    '<S2>/Cap_table'
 *    '<S4>/Cap_table'
 */
void Cap_table(real_T rtu_T, real_T *rty_CAP)
{
  int32_T i;
  static const int8_T b[8] = { -30, -20, -10, 0, 10, 25, 45, 55 };

  static const int8_T c[8] = { 70, 80, 85, 90, 92, 100, 99, 99 };

  boolean_T exitg1;

  /* MATLAB Function 'Chart1/AH_calu1/Cap_table': '<S6>:1' */
  /* '<S6>:1:2' t=[-30,-20,-10,0,10,25,45,55]; */
  /* '<S6>:1:3' CapPercent=[70,80,85,90,92,100,99,99]; */
  /* '<S6>:1:4' cap=142; */
  /* '<S6>:1:5' for i = 1:8 */
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 8)) {
    /* '<S6>:1:6' if T == t(i) */
    if (rtu_T == b[i]) {
      /* '<S6>:1:7' CAP = CapPercent(i)*0.01*cap; */
      *rty_CAP = (real_T)c[i] * 0.01 * 142.0;
      exitg1 = true;
    } else {
      /* '<S6>:1:9' else */
      /* '<S6>:1:10' if T>t(i)&&T<t(i+1) */
      if ((rtu_T > b[i]) && (rtu_T < b[i + 1])) {
        /* '<S6>:1:11' CAP=(0.1*(CapPercent(i+1)-CapPercent(i))*(T-t(i))+CapPercent(i))*0.01*cap; */
        *rty_CAP = ((real_T)(c[i + 1] - c[i]) * 0.1 * (rtu_T - (real_T)b[i]) +
                    (real_T)c[i]) * 0.01 * 142.0;
        exitg1 = true;
      } else {
        /* '<S6>:1:13' else */
        /* '<S6>:1:14' CAP =-1; */
        *rty_CAP = -1.0;
        i++;
      }
    }
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* System initialize for function-call system: '<S1>/AH_calu1' */
void AH_calu1_Init(RT_MODEL * const rtM, DW_AH_calu1 *localDW)
{
  localDW->AH_calu1_PREV_T = rtM->Timing.clockTick0;
}

/* Enable for function-call system: '<S1>/AH_calu1' */
void AH_calu1_Enable(DW_AH_calu1 *localDW)
{
  /* Enable for DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_SYSTEM_ = 1U;
}

/* Output and update for function-call system: '<S1>/AH_calu1' */
void AH_calu1(RT_MODEL * const rtM, real_T rtu_T, real_T rtu_soc, real_T
              *rty_BMS_SOC, DW_AH_calu1 *localDW)
{
  uint32_T rtb_SOC_table1_o1_dv;
  real_T rtb_SOC_table1_o2_i;
  uint32_T rtb_Temp_table1_o1_n;
  real_T rtb_CAP_i;
  uint32_T AH_calu1_ELAPS_T;
  real_T rtb_CAP_f;
  AH_calu1_ELAPS_T = rtM->Timing.clockTick0 - localDW->AH_calu1_PREV_T;
  localDW->AH_calu1_PREV_T = rtM->Timing.clockTick0;

  /* PreLookup: '<S3>/SOC_table1' incorporates:
   *  Delay: '<S3>/Delay'
   */
  rtb_SOC_table1_o1_dv = plook_binx(localDW->Delay_DSTATE, rtConstP.pooled6, 12U,
    &rtb_SOC_table1_o2_i);

  /* PreLookup: '<S3>/Temp_table1' */
  rtb_Temp_table1_o1_n = plook_binx(rtu_T, rtConstP.pooled7, 13U,
    &rtb_SOC_table1_o2_i);

  /* DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' incorporates:
   *  LookupNDDirect: '<S3>/Curr_table1'
   *
   * About '<S3>/Curr_table1':
   *  2-dimensional Direct Look-Up returning a Scalar
   */
  if (localDW->DiscreteTimeIntegrator1_SYSTEM_ != 0) {
    rtb_SOC_table1_o2_i = localDW->DiscreteTimeIntegrator1_DSTATE;
  } else {
    if (!(rtb_Temp_table1_o1_n < 12U)) {
      /* LookupNDDirect: '<S3>/Curr_table1'
       *
       * About '<S3>/Curr_table1':
       *  2-dimensional Direct Look-Up returning a Scalar
       */
      rtb_Temp_table1_o1_n = 12U;
    }

    /* LookupNDDirect: '<S3>/Curr_table1'
     *
     * About '<S3>/Curr_table1':
     *  2-dimensional Direct Look-Up returning a Scalar
     */
    if (!(rtb_SOC_table1_o1_dv < 11U)) {
      rtb_SOC_table1_o1_dv = 11U;
    }

    rtb_SOC_table1_o2_i = rtConstP.Curr_table1_table[(int32_T)
      rtb_Temp_table1_o1_n * 12 + (int32_T)rtb_SOC_table1_o1_dv] * (real_T)
      AH_calu1_ELAPS_T + localDW->DiscreteTimeIntegrator1_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' */

  /* MATLAB Function: '<S3>/Cap_table' */
  Cap_table(rtu_T, &rtb_CAP_i);

  /* Sum: '<S3>/Add' incorporates:
   *  Gain: '<S3>/Gain'
   *  Gain: '<S3>/Gain1'
   *  Product: '<S3>/Divide'
   */
  rtb_CAP_i = 0.00027777777777777778 * rtb_SOC_table1_o2_i / rtb_CAP_i * 100.0 +
    rtu_soc;

  /* Saturate: '<S3>/Saturation' */
  if (rtb_CAP_i > 100.0) {
    rtb_CAP_f = 100.0;
  } else if (rtb_CAP_i < 0.0) {
    rtb_CAP_f = 0.0;
  } else {
    rtb_CAP_f = rtb_CAP_i;
  }

  /* End of Saturate: '<S3>/Saturation' */

  /* Quantizer: '<S3>/Quantizer2' */
  *rty_BMS_SOC = rt_roundd_snf(rtb_CAP_f / 0.1) * 0.1;

  /* Update for Delay: '<S3>/Delay' */
  localDW->Delay_DSTATE = rtb_CAP_i;

  /* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator1' */
  localDW->DiscreteTimeIntegrator1_SYSTEM_ = 0U;
  localDW->DiscreteTimeIntegrator1_DSTATE = rtb_SOC_table1_o2_i;
}

/* System initialize for function-call system: '<S1>/AH_calu' */
void AH_calu_Init(RT_MODEL * const rtM, DW_AH_calu *localDW)
{
  localDW->AH_calu_PREV_T = rtM->Timing.clockTick0;
}

/* Output and update for function-call system: '<S1>/AH_calu' */
void AH_calu(RT_MODEL * const rtM, real_T rtu_T, real_T rtu_soc, real_T
             *rty_BMS_SOC, DW_AH_calu *localDW)
{
  uint32_T rtb_SOC_table1_o1_k;
  real_T rtb_SOC_table1_o2_i;
  uint32_T rtb_Temp_table1_o1_b;
  real_T rtb_CAP_g;
  uint32_T AH_calu_ELAPS_T;
  AH_calu_ELAPS_T = rtM->Timing.clockTick0 - localDW->AH_calu_PREV_T;
  localDW->AH_calu_PREV_T = rtM->Timing.clockTick0;

  /* MATLAB Function: '<S2>/Cap_table' */
  Cap_table(rtu_T, &rtb_CAP_g);

  /* Sum: '<S2>/Add' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator1'
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S2>/Gain2'
   *  Product: '<S2>/Divide'
   */
  rtb_CAP_g = 0.00027777777777777778 * localDW->DiscreteTimeIntegrator1_DSTATE /
    rtb_CAP_g * 100.0 * 0.1 + rtu_soc;

  /* PreLookup: '<S2>/SOC_table1' incorporates:
   *  Delay: '<S2>/Delay'
   */
  rtb_SOC_table1_o1_k = plook_binx(localDW->Delay_DSTATE, rtConstP.pooled6, 12U,
    &rtb_SOC_table1_o2_i);

  /* PreLookup: '<S2>/Temp_table1' */
  rtb_Temp_table1_o1_b = plook_binx(rtu_T, rtConstP.pooled7, 13U,
    &rtb_SOC_table1_o2_i);

  /* Saturate: '<S2>/Saturation' */
  if (rtb_CAP_g > 100.0) {
    rtb_SOC_table1_o2_i = 100.0;
  } else if (rtb_CAP_g < 0.0) {
    rtb_SOC_table1_o2_i = 0.0;
  } else {
    rtb_SOC_table1_o2_i = rtb_CAP_g;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Quantizer: '<S2>/Quantizer1' */
  *rty_BMS_SOC = rt_roundd_snf(rtb_SOC_table1_o2_i / 0.1) * 0.1;

  /* LookupNDDirect: '<S2>/Curr_table1'
   *
   * About '<S2>/Curr_table1':
   *  2-dimensional Direct Look-Up returning a Scalar
   */
  if (!(rtb_Temp_table1_o1_b < 12U)) {
    rtb_Temp_table1_o1_b = 12U;
  }

  if (!(rtb_SOC_table1_o1_k < 11U)) {
    rtb_SOC_table1_o1_k = 11U;
  }

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator1' incorporates:
   *  LookupNDDirect: '<S2>/Curr_table1'
   *
   * About '<S2>/Curr_table1':
   *  2-dimensional Direct Look-Up returning a Scalar
   */
  localDW->DiscreteTimeIntegrator1_DSTATE += rtConstP.Curr_table1_table_p
    [(int32_T)rtb_Temp_table1_o1_b * 12 + (int32_T)rtb_SOC_table1_o1_k] *
    (real_T)AH_calu_ELAPS_T;

  /* Update for Delay: '<S2>/Delay' */
  localDW->Delay_DSTATE = rtb_CAP_g;
}

/* Model step function */
void stateflowmodel_step(void)
{
  uint32_T rtb_SOC_table1_o1;
  real_T rtb_SOC_table1_o2;
  uint32_T rtb_Temp_table1_o1;
  real_T rtb_CAP;
  uint32_T Ah_calu_map_ELAPS_T;

  /* Chart: '<Root>/Chart1' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   *  Outport: '<Root>/Out1'
   *  Quantizer: '<S4>/Quantizer'
   */
  /* Gateway: Chart1 */
  /* During: Chart1 */
  if (rtDW.is_active_c2_stateflowmodel == 0U) {
    /* Entry: Chart1 */
    rtDW.is_active_c2_stateflowmodel = 1U;

    /* Entry Internal: Chart1 */
    /* Transition: '<S1>:507' */
    rtDW.is_c2_stateflowmodel = IN_Init;

    /* Outport: '<Root>/Out1' incorporates:
     *  Inport: '<Root>/In3'
     */
    /* Entry 'Init': '<S1>:428' */
    /* '<S1>:428:1' BMS_SOC=soc_init; */
    rtY.Out1 = rtU.In3;
  } else {
    switch (rtDW.is_c2_stateflowmodel) {
     case IN_Correct100_soc:
      /* Outport: '<Root>/Out1' */
      /* During 'Correct100_soc': '<S1>:441' */
      /* '<S1>:441:1' BMS_SOC=100; */
      rtY.Out1 = 100.0;
      break;

     case IN_Correct91_0_1Ah:
      /* During 'Correct91_0_1Ah': '<S1>:429' */
      /* '<S1>:433:1' sf_internal_predicateOutput = ... */
      /* '<S1>:433:1' CellMaxVolt>=3.413; */
      if (rtU.In2 >= 3.413) {
        /* Transition: '<S1>:433' */
        rtDW.is_c2_stateflowmodel = IN_Correct91_1_Ah;

        /* Outport: '<Root>/Out1' */
        /* Entry 'Correct91_1_Ah': '<S1>:438' */
        /* '<S1>:438:1' BMS_SOC=temp_soc; */
        rtY.Out1 = rtDW.temp_soc;
      } else {
        /* '<S1>:461:1' sf_internal_predicateOutput = ... */
        /* '<S1>:461:1' CellMaxVolt>=3.65; */
        if (rtU.In2 >= 3.65) {
          /* Transition: '<S1>:461' */
          rtDW.is_c2_stateflowmodel = IN_Correct100_soc;
        } else {
          /* Outputs for Function Call SubSystem: '<S1>/AH_calu' */

          /* '<S1>:429:1' BMS_SOC =AH_calu(Temp,91); */
          /* Simulink Function 'AH_calu': '<S1>:186' */
          AH_calu(rtM, rtU.In1, 91.0, &rtb_CAP, &rtDW.AH_calu_m);

          /* End of Outputs for SubSystem: '<S1>/AH_calu' */

          /* Outport: '<Root>/Out1' incorporates:
           *  Inport: '<Root>/In1'
           */
          rtY.Out1 = rtb_CAP;

          /* Outputs for Function Call SubSystem: '<S1>/AH_calu' */

          /* '<S1>:429:1' temp_soc=AH_calu(Temp,91); */
          /* Simulink Function 'AH_calu': '<S1>:186' */
          AH_calu(rtM, rtU.In1, 91.0, &rtb_CAP, &rtDW.AH_calu_m);

          /* End of Outputs for SubSystem: '<S1>/AH_calu' */
          rtDW.temp_soc = rtb_CAP;
        }
      }
      break;

     case IN_Correct91_1_Ah:
      /* During 'Correct91_1_Ah': '<S1>:438' */
      /* '<S1>:514:1' sf_internal_predicateOutput = ... */
      /* '<S1>:514:1' CellMaxVolt>=3.417; */
      if (rtU.In2 >= 3.417) {
        /* Transition: '<S1>:514' */
        rtDW.is_c2_stateflowmodel = IN_Correct94_1_Ah;
      } else {
        /* Outputs for Function Call SubSystem: '<S1>/AH_calu1' */

        /* '<S1>:438:1' BMS_SOC=AH_calu1(Temp,temp_soc) */
        /* Simulink Function 'AH_calu1': '<S1>:330' */
        AH_calu1(rtM, rtU.In1, rtDW.temp_soc, &rtb_CAP, &rtDW.AH_calu1_g);

        /* End of Outputs for SubSystem: '<S1>/AH_calu1' */

        /* Outport: '<Root>/Out1' incorporates:
         *  Inport: '<Root>/In1'
         */
        rtY.Out1 = rtb_CAP;
      }
      break;

     case IN_Correct94_1_Ah:
      /* During 'Correct94_1_Ah': '<S1>:513' */
      /* '<S1>:456:1' sf_internal_predicateOutput = ... */
      /* '<S1>:456:1' CellMaxVolt>=3.65; */
      if (rtU.In2 >= 3.65) {
        /* Transition: '<S1>:456' */
        rtDW.is_c2_stateflowmodel = IN_Correct100_soc;
      } else {
        /* Outputs for Function Call SubSystem: '<S1>/AH_calu1' */

        /* '<S1>:513:1' BMS_SOC=AH_calu1(Temp,94) */
        /* Simulink Function 'AH_calu1': '<S1>:330' */
        AH_calu1(rtM, rtU.In1, 94.0, &rtb_CAP, &rtDW.AH_calu1_g);

        /* End of Outputs for SubSystem: '<S1>/AH_calu1' */

        /* Outport: '<Root>/Out1' incorporates:
         *  Inport: '<Root>/In1'
         */
        rtY.Out1 = rtb_CAP;
      }
      break;

     default:
      /* During 'Init': '<S1>:428' */
      /* '<S1>:460:1' sf_internal_predicateOutput = ... */
      /* '<S1>:460:1' CellMaxVolt>=3.65; */
      if (rtU.In2 >= 3.65) {
        /* Transition: '<S1>:460' */
        rtDW.is_c2_stateflowmodel = IN_Correct100_soc;
      } else {
        /* '<S1>:430:1' sf_internal_predicateOutput = ... */
        /* '<S1>:430:1' BMS_SOC>=91&&CellMaxVolt<3.413; */
        if ((rtY.Out1 >= 91.0) && (rtU.In2 < 3.413)) {
          /* Transition: '<S1>:430' */
          rtDW.is_c2_stateflowmodel = IN_Correct91_0_1Ah;
        } else {
          /* Outputs for Function Call SubSystem: '<S1>/Ah_calu_map' */
          /* '<S1>:428:1' BMS_SOC=Ah_calu_map(Temp,soc_init ); */
          /* Simulink Function 'Ah_calu_map': '<S1>:191' */
          Ah_calu_map_ELAPS_T = rtM->Timing.clockTick0 - rtDW.Ah_calu_map_PREV_T;
          rtDW.Ah_calu_map_PREV_T = rtM->Timing.clockTick0;

          /* MATLAB Function: '<S4>/Cap_table' incorporates:
           *  Inport: '<Root>/In1'
           */
          Cap_table(rtU.In1, &rtb_CAP);

          /* Sum: '<S4>/Add' incorporates:
           *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator1'
           *  Gain: '<S4>/Gain'
           *  Gain: '<S4>/Gain1'
           *  Inport: '<Root>/In3'
           *  Product: '<S4>/Divide'
           */
          rtb_CAP = 0.00027777777777777778 * rtDW.DiscreteTimeIntegrator1_DSTATE
            / rtb_CAP * 100.0 + rtU.In3;

          /* PreLookup: '<S4>/SOC_table1' incorporates:
           *  Delay: '<S4>/Delay'
           */
          rtb_SOC_table1_o1 = plook_binx(rtDW.Delay_DSTATE, rtConstP.pooled6,
            12U, &rtb_SOC_table1_o2);

          /* PreLookup: '<S4>/Temp_table1' incorporates:
           *  Inport: '<Root>/In1'
           */
          rtb_Temp_table1_o1 = plook_binx(rtU.In1, rtConstP.pooled7, 13U,
            &rtb_SOC_table1_o2);

          /* LookupNDDirect: '<S4>/Curr_table1'
           *
           * About '<S4>/Curr_table1':
           *  2-dimensional Direct Look-Up returning a Scalar
           */
          if (!(rtb_Temp_table1_o1 < 12U)) {
            rtb_Temp_table1_o1 = 12U;
          }

          if (!(rtb_SOC_table1_o1 < 11U)) {
            rtb_SOC_table1_o1 = 11U;
          }

          /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator1' incorporates:
           *  LookupNDDirect: '<S4>/Curr_table1'
           *
           * About '<S4>/Curr_table1':
           *  2-dimensional Direct Look-Up returning a Scalar
           */
          rtDW.DiscreteTimeIntegrator1_DSTATE += rtConstP.Curr_table1_table_j
            [(int32_T)rtb_Temp_table1_o1 * 12 + (int32_T)rtb_SOC_table1_o1] *
            (real_T)Ah_calu_map_ELAPS_T;

          /* Update for Delay: '<S4>/Delay' */
          rtDW.Delay_DSTATE = rtb_CAP;

          /* Saturate: '<S4>/Saturation' */
          if (rtb_CAP > 100.0) {
            rtb_CAP = 100.0;
          } else {
            if (rtb_CAP < 0.0) {
              rtb_CAP = 0.0;
            }
          }

          /* End of Saturate: '<S4>/Saturation' */
          rtY.Out1 = rt_roundd_snf(rtb_CAP / 0.1) * 0.1;

          /* End of Outputs for SubSystem: '<S1>/Ah_calu_map' */
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart1' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  rtM->Timing.clockTick0++;
}

/* Model initialize function */
void stateflowmodel_initialize(void)
{
  /* SystemInitialize for Chart: '<Root>/Chart1' incorporates:
   *  SystemInitialize for SubSystem: '<S1>/AH_calu1'
   */
  AH_calu1_Init(rtM, &rtDW.AH_calu1_g);

  /* SystemInitialize for Chart: '<Root>/Chart1' incorporates:
   *  SystemInitialize for SubSystem: '<S1>/AH_calu'
   */
  AH_calu_Init(rtM, &rtDW.AH_calu_m);

  /* SystemInitialize for Chart: '<Root>/Chart1' incorporates:
   *  SystemInitialize for SubSystem: '<S1>/Ah_calu_map'
   */
  rtDW.Ah_calu_map_PREV_T = rtM->Timing.clockTick0;

  /* Enable for Chart: '<Root>/Chart1' incorporates:
   *  Enable for SubSystem: '<S1>/AH_calu1'
   */
  AH_calu1_Enable(&rtDW.AH_calu1_g);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
