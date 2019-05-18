/* Including the header file require */
#include "commProto.h"

/* Function definitions */
extern uint8_t sendDataSpi(uint32_t moduleInstance, uint8_t txd){
  while(!(moduleInstance->IFG));
  SPI_transmitData(moduleInstance,txd);
  return SPI_receieveData(moduleInstance);
}

extern void sendDataUart(uint32_t moduleInstance, uint8_t txd){
  while(!(moduleInstance->IFG));
  UART_transmitData(moduleInstance,txd);
}
