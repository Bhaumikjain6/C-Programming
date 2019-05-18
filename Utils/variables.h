#ifndef variables_H
#define variables_H

/* Includes the required files for following functions*/
/******************************************************************************/
#include <stdio.h>
#include <arm_math.h>
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
#define blockSizeofUcBpf                    54
/********Constants related to FHR algorithm*************************************/
#define blockSizeOfFhrPtDf                  516
#define numTapsOfFhrPtDf                    13
#define blockSizeOfFhrPtBpf                 516
#define numTapsOfFhrPtBpf                   21
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
exterm float mhrBpf1045Statearr[blockSizeOfFhr1045 + numTapsOfBpf1045 - 1];
exterm float fhrBpf1045Statearr[blockSizeOfFhr1045 + numTapsOfBpf1045 - 1];
exterm float mhrPtBpfStatearr[blockSizeOfMhrPtBpf + numTapsOfMhrPtBpf - 1];
exterm float mhrPtDfStatearr[blockSizeOfMhrPtDf + numTapsOfMhrPtDf - 1];
exterm float mhrAdaptFiltDSStatearr[blockSizeOfAdaptFiltDS + numTapsOfAdaptFiltDS - 1];
exterm float fhrAdaptFiltDSStatearr [blockSizeOfAdaptFiltDS + numTapsOfAdaptFiltDS - 1];
exterm float mhrAdaptFiltUSStatearr[blockSizeOfAdaptFiltUS + numTapsOfAdaptFiltUS - 1];
exterm float fhrMatchFiltStatearr[blockSizeOfMatchFilt + numTapsOfMatchFilter - 1];
exterm float fhrPtBpfStatearr[blockSizeOfFhrPtBpf + numTapsOfFhrPtBpf - 1];
exterm float fhrPtDfStatearr[blockSizeofFhrPtDf + numTapsOfFhrPtDf - 1];
exterm float ucLpfStatearr[blockSizeOfUcLpf + numTapsOfUcLpf - 1];
exterm float UcNotchStatearr[blockSizeOfUcNotch + numTapsOfUcNotch - 1];
exterm float ucBpfStateArr[blockSizeofUcBpf + numTapsOfUcBpf - 1];
exterm float ucRmsInterpStatearr[blockSizeOfUcRmsInterp + numTapsOfUcRmsInterp - 1];
exterm float ucThkInterpStatearr[blockSizeOfUcThkInterp + numTapsOfUcThkInterp - 1];

/****************************************************************************/
/**************************** Filter coefficients **************************/
exterm const float CoeffOfFhr1045Bpf[numTapsOfBpf1045] = {-0.00183621,-0.00232659,-0.00281714,-0.00315782,-0.003108,-0.0024614,-0.00122497,0.000229142,0.00112925,0.000449396,-0.00276563,-0.0089707,-0.0177223,-0.0274691,-0.0356554,-0.0391769,-0.0351186,-0.0215993,0.00151149,0.0322347,0.0666269,0.0994459,0.125206,0.139369,0.139369,0.125206,0.0994459,0.0666269,0.0322347,0.00151149,-0.0215993,-0.0351186,-0.0391769,-0.0356554,-0.0274691,-0.0177223,-0.0089707,-0.00276563,0.000449396,0.00112925,0.000229142,-0.00122497,-0.0024614,-0.003108,-0.00315782,-0.00281714,-0.00232659,-0.00183621
exterm const float CoeffOfMhrPtBpf[numTapsOfMhrPtBpf] = { 0.00410914, 0.00629557,0.0118891, 0.0214315, 0.0347167, 0.0507797, 0.0680232, 0.0844633, 0.0980501, 0.107008, 0.110136, 0.107008, 0.0980501, 0.0844633,0.0680232, 0.0507797,0.0347167, 0.0214315,0.0118891, 0.00629557,0.00410914 };
exterm const float CoeffOfMhrPtDf[numTapsOfMhrPtDf] = { -72.5,-92.5, -112.5, -110, -70, -30, 10, 50, 90, 122.5, 102.5, 82.5, 62.5 };
exterm const float coeffOfAdaptFiltUS[numTapsOfAdaptFiltUS];
exterm const float coeffOfFhrPtBpf[numTapsOfFhrPtBpf];
exterm const float coeffOfFhrPtDf[numTapsOfFhrPtDf];
exterm const float coeffOfUcLpf[numTapsOfUcLpf];
exterm const float coeffOfUcNotch[numTapsOfUcNotch];
exterm const float coeffOfUcBpf[numTapsOfUcBpf];
exterm const float coeffOfUcRmsInterp[numTapsOfUcRmsInterp];
exterm const float coeffOfUcThkInterp[numTapsOfUcThkInterp];
/****************************************************************************/

#endif
