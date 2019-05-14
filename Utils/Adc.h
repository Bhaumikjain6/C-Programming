#include "commProto.h"
#include "includeFiles.h"

/*
    The Adc functions are dependent on the following functions:
    -> send_data_SPI_B3;

*/
void adcWrite2op(uint8_t, uint8_t , uint8_t);
void resetAdc(void);
void sdatac(void);
