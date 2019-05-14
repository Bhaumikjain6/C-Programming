#include "MathUtils.h"
#include "DspInit.h"

/*
  This function is dependent on the following functions:
  -> mean();                     -> convolution();
  -> subtractElement();          -> findPeaks();
  -> MhrPtBpf();                 -> sortI();
  -> absf();                     -> computeHeartRate();
  -> divideElement();            -> moving_window_average();
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
void pantompkinsMhr(const float* mhrInputToPt, const size_t sizeOfArray,
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
void pantompkinsFhr(const float* fhrInputToPt, size_t sizeOfArray,
                int* fhrLocs, size_t* fhrCount);
