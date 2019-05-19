#ifndef pantompkins_H
#define pantompkins_H

/* Includes the required files for following functions*/
#include "MathUtils.h"
#include "DspInit.h"
#include "heartRateUtils.h"
/*****************************************************************************/
/*
  This function is dependent on the following functions:
  -> mean();                     -> convolution();
  -> subtractElement();          -> findPeaks();
  -> MhrPtBpf();                 -> sortI();
  -> absf();                     -> computeHeartRate();
  -> diextern voidElement();            -> moving_window_average();
  -> findMax();
  -> MhrPtDf();
  -> squareArray();
*/
//*****************************************************************************
//! The pantompkins algorithm for calculating the maternal Peaks and
//! also the maternal heart Rate.

//! /param: The maternal source Array.
//! /param: The size of the source Array
//! /param: destination array to store the Maternal Locs.
//! /param: The memory address of the variable to store the number of
//!         maternal Peaks.
//! \return None
//*****************************************************************************
extern void pantompkinsMhr(const float* mhrInputToPt, const size_t sizeOfArray,
                int* mhrLocs , size_t* mhrCount);
//*****************************************************************************
//! The pantompkins algorithm for calculating the maternal Peaks and
//! also the fetal heart Rate.

//! /param: The maternal source Array.
//! /param: The size of the source Array
//! /param: destination array to store the Fetal Locs.
//! /param: The memory address of the variable to store the number of
//!         fetal Peaks.
//! \return None
//*****************************************************************************
extern void pantompkinsFhr(const float* fhrInputToPt, size_t sizeOfArray,
                int* fhrLocs, size_t* fhrCount, size_t* mhrCount);

#endif
