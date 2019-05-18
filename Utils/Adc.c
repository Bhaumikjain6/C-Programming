#include "Adc.h"

extern void adcWrite2op(uint8_t op1, uint8_t op2, uint8_t txd)
{
    int l;
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN6);

    sendDataSpi(EUSCI_B3_BASE,op1);
    sendDataSpi(EUSCI_B3_BASE,op2);
    sendDataSpi(EUSCI_B3_BASE,txd);

    for (l = 0; l < 800; l++);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN6);
    for (l = 0; l < 800; l++);
}

extern void resetAdc(void){
  int i;
  i = 100000;
  while (i){
      i--;
  }
  GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN0);
  GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN0);
  i = 10000;
  while (i){
      i--;
  }
  GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN0);
}

extern void sdatac(void)
{
    uint8_t txd;
    int l;

    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN6);
    txd = 0x11;
    sendDataSpi(EUSCI_B3_BASE,txd);
    for (l = 0; l < 800; l++);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN6);
    for (l = 0; l < 800; l++);
}
