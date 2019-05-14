#include "includeFiles.h"
#include "adc.h"
#include "lcd.h"
#include "variables.h"

/*
  The functions in the following source file are dependent on several
  functions:
  -> delay_us();
  -> send_data_SPI_A3();
  -> send_sdatac();
  -> resetAdc();
  -> wreg_command_2op();
  -> clrscr();
*/

//*****************************************************************************
//! Is Used for Initializing the GPIO pins to their respective logic levels
//!
//! \param None
//  \return None
//*****************************************************************************
void portInit(void);
//*****************************************************************************
//! Is Used for Initializing the interrupt pins.
//! Enables the Interrupt on the respective PORT.
//! \param None
//  \return None
//*****************************************************************************
void interruptInit(void);
//*****************************************************************************
// Initializing Communication Procotols
//*****************************************************************************
//! Intializes and Enables the respective SPI module.
//! Before Initializing check if the SPI configuration is according to the use.
//! \param None
//  \return None
//*****************************************************************************
void spiInitA3(void);
//*****************************************************************************
//! Intializes and Enables the respective SPI module.
//! Before Initializing check if the SPI configuration is according to the use.
//! \param None
//  \return None
//*****************************************************************************
void spiInitA1(void);
//*****************************************************************************
//! Intializes and Enables the respective SPI module.
//! Before Initializing check if the SPI configuration is according to the use.
//! \param None
//  \return None
//*****************************************************************************
void spiInitB3(void);
//*****************************************************************************
//! Intializes and Enables the respective UART module.
//! Before Initializing check if the UART configuration is according to the use.
//! \param None
//  \return None
//*****************************************************************************
void uartInitA2(void);
//*****************************************************************************
// Initializing Peripherals
//*****************************************************************************
//! Intializes and Enables the LCD module.
// ! <br> The SPI module for the LCD module is enabled.
//! The registers of the LCD are configured in this function.
//! \param None
//  \return None
//*****************************************************************************
void LcdInit(void);
//*****************************************************************************
//! Intializes and Enables the ADC module.
// ! <br> The SPI module for the ADC module is enabled.
//! The registers of the ADC are configured in this function.
//! \param None
//  \return None
//*****************************************************************************
void AdcInit(void);
//*****************************************************************************
//!  A delay function in  Micro seconds
//! \param unsigned long Giving a delay of timeInMicroSeconds us.
//  \return None
//*****************************************************************************
void delay_us(unsigned long timeInMicroSeconds);
