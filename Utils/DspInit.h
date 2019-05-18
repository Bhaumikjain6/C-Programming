#ifndef DspInit_H
#define DspInit_H

/* Includes the required header files for the folllowing function */
#include "variables.h"
#include "MathUtils.h"
#incldue "includeFiles.h"
//*****************************************************************************
// Initializing Filter Functions
//*****************************************************************************
//! Intializes the following filter module required for both algorithms.
//! <br> The filter modules are intialized with their respective configurations
//! The configuration parameters are in "variables.h".
//! \param one parameter to matched Filter is the reverse Input array.
//  \return None
/******************************************************************************/
extern void FhrBpf1045Init(void);
extern void MhrPtBpfInit(void);
extern void MhrPtDfInit(void);
extern void  adaptFiltDownsampleInit(void);
extern void  adaptFiltUpsampleInit(void);
extern void  matchFilterFhrInit(const float*);
extern void  FhrPtBpfInit(void);
extern void  FhrPtDfInit(void);
extern void  UcLpfInit(void);
extern void  UcNotchFiltInit(void);
extern void  UcBpfInit(void);
extern void  UcRmsInterpInit(void);
extern void  UcThkInterpInit(void);
/******************************************************************************/
//! Definition of Filter Functions
//*****************************************************************************
//! This function generates a band pass filter of 10hz to 45hz.
//! /param The mhr input to the filter
//! /param The fhr input to the filter
//! /param The pointer to the destination array of Mhr
//! /param The pointer to the destination array of Fhr
//! <br> define the following variables globally before using the funtion.
//!  -> numTapsOfBpf1045  ->InstanceforFhrBpf1045 -> blockSizeOfFhr1045
//!  -> mhrBpf1045Statearr  -> CoeffOfFhr1045Bpf
//  \return None
//*****************************************************************************
extern void  FhrBpf1045(const float* sourceArray1 , const float* sourceArray2
            ,float* destinationArray1, float* destinationArray2);
//*****************************************************************************
//! This function generates a band pass filter for Pantompkins Mhr
//! /param The mhr input to the filter
//! /param The pointer to the destination array of ptbpf output array
//! <br> define the following variables globally before using the funtion.
//!  -> numTapsOfMhrPtBpf  ->InstanceforMhrPtBpf -> blockSizeOfMhrPtBpf
//!  -> mhrPtBpfStatearr  -> CoeffOfMhrPtBpf
//  \return None
//*****************************************************************************
extern void  MhrPtBpf(const float* sourceArray1 , float* destinationArray1 );
//*****************************************************************************
//! This function generates a derivative filter for Pantompkins Mhr
//! /param The df input to the filter
//! /param The pointer to the destination array of derivative filter output
//! <br> define the following variables globally before using the funtion.
//!  -> numTapsOfMhrPtDf  ->InstanceforMhrPtDf -> blockSizeOfMhrPtDf
//!  -> mhrPtDfStatearr  -> CoeffOfMhrPtDf
//  \return None
//*****************************************************************************
extern void  MhrPtDf(const float* sourceArray1, float* destinationArray1);
//*****************************************************************************
//! This function generates a Adapt filter for processing downsampled
//! mhr and fhr signal
//! /param The mhr input to the filter
//! /param The fhr input to the filter
//! /param The pointer to the destination array of mhr
//! /param The pointer to the destination array of Fhr
//! <br> define the following variables globally befor  e using the funtion.
//!  -> numTapsOfAdaptFiltDS  ->InstanceforFhrAdaptFiltDS -> InstanceforMhrAdaptFiltDS
//!  -> blockSizeOfAdaptFiltDS -> fhrAdaptFiltDSStatearr
//!  -> mhrAdaptFiltUSStatearr  -> coeffOfAdaptFiltDS
//  \return None
//*****************************************************************************
extern void  adaptFiltDownsampleFhr(const float* sourceArray1, const float* sourceArray2
                      ,float* destinationArray1, float* destinationArray2);
//*****************************************************************************
//! This function generates a Adapt filter for filtering the LMS output and
//! upsampling it by 2.
//! /param The mhr input to the filter
//! /param The pointer to the destination array of Fhr
//! <br> define the following variables globally befor  e using the funtion.
//!  -> numTapsOfAdaptFiltUS  -> InstanceforMhrAdaptFiltUS
//!  -> blockSizeOfAdaptFiltUS
//!  -> mhrAdaptFiltUSStatearr  -> coeffOfAdaptFiltUS
//  \return None
//*****************************************************************************
extern void  adaptFiltUpsampleFhr(const float* sourceArray1, float* destinationArray1);
//*****************************************************************************
//! This function generates a Match filter for filtering the output of
//! Adapt filter.
//! /param The memory address of the source array that has to be filtered
//! /param The pointer to the destination array of the filtered array.
//! <br> define the following variables globally before using the funtion.
//!  -> numTapsOfMatchFilter  ->InstanceforFhrMatchFilt -> blockSizeOfMatchFilt
//!  -> fhrMatchFiltStatearr  -> coeffOfMatchFilt
//  \return None
//*****************************************************************************
extern void  matchFilterFhr(const float* sourceArray1, float* sourceArray2);
//*****************************************************************************
//! This function generates a band pass filter for Pantompkins Fhr
//! /param The mhr input to the filter
//! /param The pointer to the destination array of ptbpf output array
//! <br> define the following variables globally before using the funtion.
//!  -> numTapsOfFhrPtBpf  ->InstanceforFhrPtBpf -> blockSizeOfFhrPtBpf
//!  -> fhrPtBpfStatearr  -> CoeffOfFhrPtBpf
//  \return None
//*****************************************************************************
extern void  FhrPtBpf(const float* sourceArray1, float* destinationArray1);
//*****************************************************************************
//! This function generates a derivative filter for Pantompkins Fhr
//! /param The df input to the filter
//! /param The pointer to the destination array of derivative filter output
//! <br> define the following variables globally before using the funtion.
//!  -> numTapsOfFhrPtDf  ->InstanceforFhrPtDf -> blockSizeOfFhrPtDf
//!  -> fhrPtDfStatearr  -> CoeffOfFhrPtDf
//  \return None
//*****************************************************************************
extern void  FhrPtDf(const float* sourceArray1, float* destinationArray1);
//*****************************************************************************
//! This function generates a Low pass filter.
//! /param The memory address of the source array that has to be filtered.
//! /param The pointer to the destination array.
//! <br> define the following variables globally before using the funtion.
//!  -> numTapsOfUcLpf  ->InstanceforUcLpf -> blockSizeOfUcLpf
//!  -> ucLpfStatearr  -> CoeffOfUcLpf
//  \return None
//*****************************************************************************
extern void  UcLpf(const float* sourceArray1, float* destinationArray1);
//*****************************************************************************
//! This function generates a Notch filter.
//! /param The memory address of the source array that has to be filtered.
//! /param The pointer to the destination array.
//! <br> define the following variables globally before using the funtion.
//!  -> numTapsOfUcNotch  ->InstanceforUcNotch -> blockSizeOfUcNotch
//!  -> UcNotchStatearr  -> CoeffOfUcNotch
//  \return None
//*****************************************************************************
extern void  UcNotchFilt(const float* sourceArray1, float* destinationArray1);
//*****************************************************************************
//! This function calculates the RMS value of the source array.
//! /param The memory address of the source array.
//! /param size of the source array.
//  \return The RMS value of the source Array.
//*****************************************************************************
extern float UcRms(const float* sourceArray1, size_t sizeOfArray);
//*****************************************************************************
//! This function generates a Band pass filter.
//! /param The memory address of the source array that has to be filtered.
//! /param The pointer to the destination array.
//! <br> define the following variables globally before using the funtion.
//!  -> numTapsOfUcBpf  ->InstanceforUcBpf -> blockSizeOfUcBpf
//!  -> ucBpfStatearr  -> CoeffOfUcBpf
//  \return None
//*****************************************************************************
extern void  UcBpf(const float* sourceArray1, float* destinationArray1);
//*****************************************************************************
//! This function generates a interpolation filter for Threshold calculation
//! in UC Algorithm
//! /param The memory address of the source array that has to be interpolated.
//! /param The pointer to the destination array of interpolated filter.
//! /param The interpolating factor
//! <br> define the following variables globally before using the funtion.
//!  -> numTapsOfUcRmsInterp  ->InstanceForUcRmsInterp -> blockSizeOfUcRmsInterp
//!  -> ucRmsInterpStatearr  -> coeffOfUcRmsInterp
//! <br> Note that the size of the destination array is size of the source
//!      array times the interpolating factor.
//  \return None
//*****************************************************************************
extern void  UcRmsInterp(const float* sourceArray1 , float* destinationArray,
            int interpolatingFactor);
//*****************************************************************************
//! This function generates a interpolation filter for Threshold calculation
//! in UC Algorithm
//! /param The memory address of the source array that has to be interpolated.
//! /param The pointer to the destination array of interpolated filter.
//! /param The interpolating factor
//! <br> define the following variables globally before using the funtion.
//!  -> numTapsOfUcThkInterp  ->InstanceForUcThkInterp -> blockSizeOfUcThkInterp
//!  -> ucThkInterpStatearr  -> coeffOfUcThkInterp
//! <br> Note that the size of the destination array is size of the source
//!      array times the interpolating factor.
//  \return None
//*****************************************************************************
extern void  UcThkInterp(const float* sourceArray1, float* destinationArray1,
            int interpolatingFactor);
//*****************************************************************************
//! This function calculates the convolution of given source Array.
//! /param The memory address of source Array1.
//! /param The size of the sourceArray.
//! /param The coefficient array
//! /param The size of the coefficient Array
//! /param The pointer to the destination array of mhr
//! <br> Note that the size of destination array is the size of source array +
//!      size of the coefficient array - 1;
//  \return None
//*****************************************************************************
extern void  convolution(const float* sourceArray1, size_t sizeOfSourceArray,
          const float* coeffArray, size_t sizeOfCoeffArray, float* destinationArray1);

#endif
