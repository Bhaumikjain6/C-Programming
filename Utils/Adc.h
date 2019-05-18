#ifndef Adc_H
#define Adc_H
/*
    The Adc functions are dependent on the following functions:
    -> sendDataSpi;
*/
/* Including the required header files for following functions*/
#include "commProto.h"
#include "includeFiles.h"
//*****************************************************************************
//  The following function writes into the register of the ADC.
//  \param : The first parameter takes the starting address of the
//            register in the following format: 010r rrrr
//  \param: The second parameter takes the number of registers
//            to be written in the format : 000n nnnn
//  \param: The third parameter takes the value to be substituted
//            in the register.
//  \return None
//*****************************************************************************
extern void adcWrite2op(uint8_t, uint8_t , uint8_t);
//*****************************************************************************
//  Resets the ADC module
//  \param  None
//  \return None
//*****************************************************************************
extern void resetAdc(void);
//*****************************************************************************
//  Stops read Data Continous Mode.
//  \param None
//  \return None
//*****************************************************************************
extern void sdatac(void);

#endif
