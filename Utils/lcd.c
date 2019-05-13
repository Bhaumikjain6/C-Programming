#include "lcd.h"


void clrscr(void){
  uint8_t index, page, low, k, a, b;
  GPIO_setOutputLowOnPin(GPIO_PORT_P9, GPIO_PIN4);

  page = 0xB0;
  low = 0x04;
  for (index = 0; index < 8; index++){
    send_data_SPI_A3(page);    //Page address set
    for (k = 0; k < 128; k++){
        a = ((low >> 4) + 0x10);
        b = ((low & (0x0F)) + 0x00);
        send_data_SPI_A3(a);    //Sets MS 4 bits of the column address
        send_data_SPI_A3(b);    //Sets LS 4 bits of the column address
        GPIO_setOutputHighOnPin(GPIO_PORT_P9, GPIO_PIN0);
        delay_us(10);
        send_data_SPI_A3(0x00);
        delay_us(10);
        GPIO_setOutputLowOnPin(GPIO_PORT_P9, GPIO_PIN0);

        low += 1;
    }
    page += 1;
    low = 0x04;
  }
  GPIO_setOutputHighOnPin(GPIO_PORT_P9, GPIO_PIN4);
}
