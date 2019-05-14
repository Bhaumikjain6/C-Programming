#include "commProto.h"

uint8_t sendDataSpi(uint32_t moduleInstance, uint8_t txd){
  while(!(moduleInstance->IFG));
  SPI_transmitData(moduleInstance,txd);
  return SPI_receieveData(moduleInstance);
}

void sendDataUart(uint32_t moduleInstance, uint8_t txd){
  while(!(moduleInstance->IFG));
  UART_transmitData(moduleInstance,txd);
}
