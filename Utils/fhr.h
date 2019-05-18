#ifndef fhr_H
#define fhr_H

/* Includes the required files for following functions*/
#include "pantompkins.h"
//*****************************************************************************
//! The following functions contains the Algorithm to calculate the
//! Maternal and the Fetal Heart Rate.
//! \param V1n: The signal acquired after subtracting V2 - V1 which acts as a
//!     maternal Input to the function.
//! \param V4n: The signal acquired after subtracting V4 - V1 which acts as a
//!     fetal Input to the function.
//! The algorithm stores the Fetal and Maternal heart rates in a static array.
//  \return None
//*****************************************************************************
extern void algorithmFhr(float* , float*);

#endif
