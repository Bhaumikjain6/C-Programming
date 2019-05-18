#ifndef lcd_H
#define lcs_H
/* Includes the required files for following functions*/
#include "deviceInit.h"
/*
   * The functions associated with the LCD are dependent on other functions
     such as:
     -> send_data_SPI_A3();
     -> delay_us();
*/
//*****************************************************************************
//! Is Used to clear the contents of the LCD.
//!
//! \param None
//  \return None
//*****************************************************************************
extern void clrscr(void);
#endif
