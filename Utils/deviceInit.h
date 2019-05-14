#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

// Device Setup
void clockInit(void);
void portInit(void);
void interruptInit(void);

// Initializing Communication Procotols
void spiInitA3(void);
void spiInitA1(void);
void spiInitB3(void);

void uartInitA2(void);

// Initializing Peripherals
void LcdInit(void);
void AdcInit(void);
