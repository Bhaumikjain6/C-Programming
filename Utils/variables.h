#ifndef variables_H
#define variables_H

/* Includes the required files for following functions*/
/******************************************************************************/
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <spi.h>
#include <uart.h>
#include <gpio.h>
#include <pcm.h>
#include <cs.h>
#include <flash_a.h>
#include <interrupt.h>
#include <rom_map.h>
#include <arm_math.h>
#include <msp432p4111.h>
#include <arm_const_structs.h>
#include <arm_common_tables.h>
/******************************************************************************/
/********Constants*************************************************************/
#define blockLength                         516
#define IPSIZE                              500
/********Constants related to UC algorithm*************************************/
#define blockSizeOfUcThkInterp              181
#define ucThkUpsampleFactor                 35
#define numTapsOfUcThkInterp                245
#define blockSizeOfUcRmsInterp              181
#define ucRmsUpsampleFactor                 20
#define numTapsOfUcRmsInterp                260
#define sizeOfInputRms                      1080
#define numTapsOfUcNotch                    21
#define blockSizeOfUcNotch                  550
#define numTapsOfUcLpf                      51
#define blockSizeOfUcLpf                    550
#define numTapsOfUcBpf                      16
#define blockSizeofUcBpf                    54\

/********Constants related to FHR algorithm*************************************/
#define blockSizeOfFhrPtDf                  516
#define numTapsOfFhrPtDf                    13
#define blockSizeOfFhrPtBpf                 516
#define numTapsOfFhrPtBpf                   51
#define blockSizeOfMatchFilt                516
#define numTapsOfMatchFilter                516
#define blockSizeOfAdaptFiltUS              516
#define numTapsOfAdaptFiltUS                27
#define blockSizeOfAdaptFiltDS              258
#define numTapsOfAdaptFiltDS                11
#define numTapsOfMhrPtDf                    13
#define blockSizeOfMhrPtDf                  516
#define numTapsOfMhrPtBpf                   21
#define blockSizeOfMhrPtBpf                 516
#define numTapsOfBpf1045                    48
#define blockSizeOfFhr1045                  500
#define blockSizeOfFhrPtDf                  516
#define numTapsOfFhrPtDf                    13
#define numTapsOfFhrConvolution             10

#define NEWQRSRANGE                         39
#define mhrMinPeakDistance                  250
#define fhrMinPeakDistance                  158

//// Variables related to FHR and Uc algorithm
/********Constants related to Communication Protocols *************************/
extern const eUSCI_SPI_MasterConfig spiMasterConfigA;
extern const eUSCI_SPI_MasterConfig spiMasterConfigB;
extern const eUSCI_UART_Config uartConfig2;
/****************************** Filter instances *****************************/
extern arm_fir_instance_f32 InstanceforMhrBpf1045, InstanceforFhrBpf1045;
extern arm_fir_instance_f32 InstanceforMhrPtBpf;
extern arm_fir_instance_f32 InstanceforMhrPtDf;
extern arm_fir_instance_f32 InstanceforMhrAdaptFiltDS;
extern arm_fir_instance_f32 InstanceforFhrAdaptFiltDS;
extern arm_fir_instance_f32 InstanceforMhrAdaptFiltUS;
extern arm_fir_instance_f32 InstanceforFhrMatchFilt;
extern arm_fir_instance_f32 InstanceForFhrPtBpf;
extern arm_fir_instance_f32 InstanceForFhrPtDf;
extern arm_fir_instance_f32 InstanceForUcLpf;
extern arm_fir_instance_f32 instanceForUcNotch;
extern arm_fir_instance_f32 instanceForUcBpf;
extern arm_fir_instance_f32 InstanceForUcRmsInterp;
extern arm_fir_instance_f32 instanceForUcThkInterp;

/****************************************************************************/
/**************************** Filter StateArrays ****************************/
extern float mhrBpf1045Statearr[blockSizeOfFhr1045 + numTapsOfBpf1045 - 1];
extern float fhrBpf1045Statearr[blockSizeOfFhr1045 + numTapsOfBpf1045 - 1];
extern float mhrPtBpfStatearr[blockSizeOfMhrPtBpf + numTapsOfMhrPtBpf - 1];
extern float mhrPtDfStatearr[blockSizeOfMhrPtDf + numTapsOfMhrPtDf - 1];
extern float mhrAdaptFiltDSStatearr[blockSizeOfAdaptFiltDS + numTapsOfAdaptFiltDS - 1];
extern float fhrAdaptFiltDSStatearr [blockSizeOfAdaptFiltDS + numTapsOfAdaptFiltDS - 1];
extern float mhrAdaptFiltUSStatearr[blockSizeOfAdaptFiltUS + numTapsOfAdaptFiltUS - 1];
extern float fhrMatchFiltStatearr[blockSizeOfMatchFilt + numTapsOfMatchFilter - 1];
extern float fhrPtBpfStatearr[blockSizeOfFhrPtBpf + numTapsOfFhrPtBpf - 1];
extern float fhrPtDfStatearr[blockSizeOfFhrPtDf + numTapsOfFhrPtDf - 1];
extern float ucLpfStatearr[blockSizeOfUcLpf + numTapsOfUcLpf - 1];
extern float UcNotchStatearr[blockSizeOfUcNotch + numTapsOfUcNotch - 1];
extern float ucBpfStateArr[blockSizeofUcBpf + numTapsOfUcBpf - 1];
extern float ucRmsInterpStatearr[blockSizeOfUcRmsInterp + numTapsOfUcRmsInterp - 1];
extern float ucThkInterpStatearr[blockSizeOfUcThkInterp + numTapsOfUcThkInterp - 1];

/****************************************************************************/
/**************************** Filter coefficients **************************/
extern const float CoeffOfFhr1045Bpf[numTapsOfBpf1045];
extern const float CoeffOfMhrPtBpf[numTapsOfMhrPtBpf];
extern const float CoeffOfMhrPtDf[numTapsOfMhrPtDf];
extern const float coeffOfAdaptFiltDS[numTapsOfAdaptFiltDS];
extern const float coeffOfAdaptFiltUS[numTapsOfAdaptFiltUS];
extern const float coeffOfFhrPtBpf[numTapsOfFhrPtBpf];
extern const float coeffOfFhrPtDf[numTapsOfFhrPtDf];
extern const float coeffOfUcLpf[numTapsOfUcLpf];
extern const float coeffOfUcNotch[numTapsOfUcNotch];
extern const float coeffOfUcBpf[numTapsOfUcBpf];
extern const float coeffOfUcRmsInterp[numTapsOfUcRmsInterp];
extern const float coeffOfUcThkInterp[numTapsOfUcThkInterp];
extern const float coeffOfFhrConvolution[numTapsOfFhrConvolution];
/****************************************************************************/

#endif
