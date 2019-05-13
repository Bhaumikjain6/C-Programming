#include "Adc.h"

void adcWrite2op(uint8_t op1, uint8_t op2, uint8_t txd)
{
    int l;
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN6);

    send_data_SPI_B3(op1);
    send_data_SPI_B3(op2);
    send_data_SPI_B3(txd);

    for (l = 0; l < 800; l++);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN6);
    for (l = 0; l < 800; l++);
}

void resetAdc(void){
  int i;
  i = 100000;
  while (i){
      i--;
  }
  GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN7);
  GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN7);
  i = 10000;
  while (i){
      i--;
  }
  GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN7);
}

void sdatac(void)
{
    uint8_t txd;
    int l;

    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN6);
    txd = 0x11;
    send_data_SPI_B3(txd);
    for (l = 0; l < 800; l++);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN6);
    for (l = 0; l < 800; l++);
}
