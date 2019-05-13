#include <stdio.h>
#include <stdlib.h>
#include "variables.h"
#include "MathUtils.h"

void FhrBpf1045Init(void);
void MhrPtBpfInit(void);
void MhrPtDfInit(void);
void adaptFiltDownsampleInit(void);
void adaptFiltUpsampleInit(void);
void matchFilterFhrInit(const float*);
void FhrPtBpfInit(void);
void FhrPtDfInit(void);
void UcLpfInit(void);
void UcNotchFiltInit(void);
void UcRmsInterpInit(void);
void UcThkInterpInit(void);

void FhrBpf1045(const float* , const float*, float*, float*);
void MhrBpfPt(const float* , float* );
void MhrPtDf(const float*, float*);
void adaptFiltDownsampleFhr(const float*, const float* , float*, float* );
void adaptFiltUpsampleFhr(const float*, const float* , float*, float* );
void matchFilterFhr(const float*, float*);
void FhrPtBpf(const float*, float*);
void FhrPtDf(const float* , float*);
void UcLpf(const float*, float*);
void UcNotchFilt(const float*, float*);
float UcRms(const float*, size_t );
void UcRmsInterp(const float*, float* , int);
void UcThkInterp(const float*, float* , int);

void convolution(const float* , size_t , const float* , size, float*);
