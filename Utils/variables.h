#include <stdio.h>
#include <arm_math.h>
#include <arm_const_structs.h>
#include <arm_common_tables.h>

//// Constants /////

//// Constants related to UC algorithm

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

//// Constants related to FHR algorithm
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
