#include "deviceInit.h"

void clockInit(void)
{
    /* Configuring pins for peripheral/crystal usage and LED for output */
    GPIO_setAsPeripheralModuleFunctionOutputPin(
            GPIO_PORT_PJ,
            GPIO_PIN3 | GPIO_PIN2,
            GPIO_PRIMARY_MODULE_FUNCTION);

    /* Just in case the user wants to use the getACLK, getMCLK, etc. functions,
     * let's set the clock frequency in the code.
     */
    CS_setExternalClockSourceFrequency(32000, 48000000);

    /* Starting HFXT in non-bypass mode without a timeout. Before we start
     * we have to change VCORE to 1 to support the 48MHz frequency */
    PCM_setCoreVoltageLevel(PCM_VCORE1);
    FlashCtl_A_setWaitState(FLASH_A_BANK0, 3);
    FlashCtl_A_setWaitState(FLASH_A_BANK1, 3);
    CS_startHFXT(false);

    /* Initializing MCLK to HFXT (effectively 48MHz) */
    CS_initClockSignal(CS_MCLK, CS_HFXTCLK_SELECT, CS_CLOCK_DIVIDER_1);
    CS_initClockSignal(CS_SMCLK, CS_HFXTCLK_SELECT, CS_CLOCK_DIVIDER_2);
}

void portInit(void)
{
    //PORT 1
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1);
    GPIO_setAsInputPin(GPIO_PORT_P1, GPIO_PIN4);

    //PORT 2
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0);
    GPIO_setAsInputPin(GPIO_PORT_P2, GPIO_PIN4);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P2, GPIO_PIN5);
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P2, GPIO_PIN7);

    //PORT 3
    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN0);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN0);
    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN1);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN1);
    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN4);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN4);
    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN5);
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN5);
    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN6);
    GPIO_setOutputHighOnPin(GPIO_PORT_P3, GPIO_PIN6);
    GPIO_setAsInputPin(GPIO_PORT_P3, GPIO_PIN7);

    //PORT 4
    P4->OUT = 0xFF;

    //PORT 5
    GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN0);
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN0);
    GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN1);
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN1);
    GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN2);
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN2);
    GPIO_setAsInputPin(GPIO_PORT_P5, GPIO_PIN6);
    GPIO_setAsInputPin(GPIO_PORT_P5, GPIO_PIN7);

    //PORT 6
    GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN0);
    GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN0);
    GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN1);
    GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN1);
    GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN6);
    GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN6);
    GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN7);
    GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN7);

    //PORT 7
    GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN0);
    GPIO_setOutputHighOnPin(GPIO_PORT_P7, GPIO_PIN0);
    GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN2);
    GPIO_setOutputHighOnPin(GPIO_PORT_P7, GPIO_PIN2);
    GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN3);
    GPIO_setOutputHighOnPin(GPIO_PORT_P7, GPIO_PIN3);
    GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN4);
    GPIO_setOutputLowOnPin(GPIO_PORT_P7, GPIO_PIN4);
    GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P7, GPIO_PIN7);

    //PORT 8
    GPIO_setAsOutputPin(GPIO_PORT_P8, GPIO_PIN0);
    GPIO_setOutputHighOnPin(GPIO_PORT_P8, GPIO_PIN0);
    GPIO_setAsOutputPin(GPIO_PORT_P8, GPIO_PIN1);   //BACKLIGHT
    GPIO_setOutputLowOnPin(GPIO_PORT_P8, GPIO_PIN1);
    GPIO_setAsOutputPin(GPIO_PORT_P8, GPIO_PIN5);
    GPIO_setOutputHighOnPin(GPIO_PORT_P8, GPIO_PIN5);
    GPIO_setAsOutputPin(GPIO_PORT_P8, GPIO_PIN6);
    GPIO_setOutputHighOnPin(GPIO_PORT_P8, GPIO_PIN6);

    //PORT 9
    GPIO_setAsOutputPin(GPIO_PORT_P9, GPIO_PIN0);
    GPIO_setOutputLowOnPin(GPIO_PORT_P9, GPIO_PIN0);
    GPIO_setAsOutputPin(GPIO_PORT_P9, GPIO_PIN2);
    GPIO_setOutputLowOnPin(GPIO_PORT_P9, GPIO_PIN2);
    GPIO_setAsOutputPin(GPIO_PORT_P9, GPIO_PIN4);
    GPIO_setOutputHighOnPin(GPIO_PORT_P9, GPIO_PIN4);

    //PORT 10
    GPIO_setAsOutputPin(GPIO_PORT_P10, GPIO_PIN0);
    GPIO_setOutputHighOnPin(GPIO_PORT_P10, GPIO_PIN0);
}

void spiInitA1(void){
  // Selecting P1.5 P1.6 and P1.7 in SPI mode
  GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P2,
  GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3,
                                           GPIO_PRIMARY_MODULE_FUNCTION);
  // Configuring SPI in 3wire master mode
  SPI_initMaster(EUSCI_A1_BASE, &spiMasterConfigA);
  // Enable SPI module
  SPI_enableModule(EUSCI_A1_BASE);
}

void spiInitA3(void){
  // Selecting P1.5 P1.6 and P1.7 in SPI mode
  GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P9,
  GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7,
                                           GPIO_PRIMARY_MODULE_FUNCTION);
  // Configuring SPI in 3wire master mode
  SPI_initMaster(EUSCI_A3_BASE, &spiMasterConfigA);

  // Enable SPI module
  SPI_enableModule(EUSCI_A3_BASE);
}

void spiInitB3(void){
  // Selecting P1.5 P1.6 and P1.7 in SPI mode
  GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P10,
  GPIO_PIN1 | GPIO_PIN2 | GPIO_PIN3,
                                           GPIO_PRIMARY_MODULE_FUNCTION);
  // Configuring SPI in 3wire master mode
  SPI_initMaster(EUSCI_B3_BASE, &spiMasterConfigB);

  // Enable SPI module
  SPI_enableModule(EUSCI_B3_BASE);
}

void uartInitA2(void){
  /* Selecting P1.2 and P1.3 in UART mode and P1.0 as output (LED) */
  MAP_GPIO_setAsPeripheralModuleFunctionInputPin(
          GPIO_PORT_P3,
          GPIO_PIN2 | GPIO_PIN3,
          GPIO_PRIMARY_MODULE_FUNCTION);
  //MAP_GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN0);
  //MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN0);

  /* Configuring UART Module */
  MAP_UART_initModule(EUSCI_A2_BASE, &uartConfig2);

  /* Enable UART module */
  MAP_UART_enableModule(EUSCI_A2_BASE);
}

void LCDInit(void){
    uint8_t txd;

    GPIO_setOutputLowOnPin(GPIO_PORT_P9, GPIO_PIN2);
    delay_us(500);
    GPIO_setOutputHighOnPin(GPIO_PORT_P9, GPIO_PIN2);
    delay_us(500);
    GPIO_setOutputLowOnPin(GPIO_PORT_P9, GPIO_PIN4);    //Pulling CS low

    delay_us(100);
    txd = 0x40;            //Display start line 0
    send_data_SPI_A3(txd);

    txd = 0xA0;            //ADC reverse
    send_data_SPI_A3(txd);

    txd = 0xC8;            //normal COM0-COM63
    send_data_SPI_A3(txd);

    txd = 0xA6;            //Display Normal, changing to A7 inverts all the pixels i.e. the entire screen
    send_data_SPI_A3(txd);

    txd = 0xA2;            //Set bias 1/9 (Duty 1/65)
    send_data_SPI_A3(txd);

    txd = 0x2F;            //Booster, Regulator and Follower
    send_data_SPI_A3(txd);

    txd = 0xF8;            //Set internal booster to 4x
    send_data_SPI_A3(txd);
    txd = 0x00;
    send_data_SPI_A3(txd);

    txd = 0x27;            //Contrast set
    send_data_SPI_A3(txd);
    txd = 0x81;
    send_data_SPI_A3(txd);
    txd = 0x16;
    send_data_SPI_A3(txd);

    txd = 0xAC;            //No indicator
    send_data_SPI_A3(txd);
    txd = 0x00;
    send_data_SPI_A3(txd);

    txd = 0xAF;            //Display on
    send_data_SPI_A3(txd);

    delay_us(50);

    GPIO_setOutputHighOnPin(GPIO_PORT_P9, GPIO_PIN4);

    delay_us(50);
    clrscr();
}

void AdcInit(void){
    resetAdc();

    delay_us(2000);
    send_sdatac();
    delay_us(2000);

    //Writing into registers
    //op1, op2, data-to-be-written
    //When changing to ECG application the following registers need to be changed:
    //CONGIG3 -> 0xDC
    //CHnSET  -> 0x60
    adcWrite2op(0x41, 0x00, 0xC6);   //Writing into CONFIG1
    adcWrite2op(0x42, 0x00, 0x33);   //Writing into CONFIG2    //0x10
    adcWrite2op(0x43, 0x00, 0xDC);   //Writing into CONFIG3 //0xC0
    adcWrite2op(0x57, 0x00, 0x00);   //Writing into CONFIG4

    adcWrite2op(0x45, 0x00, 0x60);   //Writing into CH1SET
    adcWrite2op(0x46, 0x00, 0x60);   //Writing into CH2SET
    adcWrite2op(0x47, 0x00, 0x60);   //Writing into CH3SET
    adcWrite2op(0x48, 0x00, 0x60);   //Writing into CH4SET
    adcWrite2op(0x49, 0x00, 0x60);   //Writing into CH5SET
    adcWrite2op(0x4A, 0x00, 0x60);   //Writing into CH6SET
    adcWrite2op(0x4B, 0x00, 0x60);   //Writing into CH7SET
    adcWrite2op(0x4C, 0x00, 0x60);   //Writing into CH8SET
}

void delay_us(unsigned long timeInMicroSeconds){
  timeInMicroSeconds = (timeInMicroSeconds * 298 * 5 *27) / 1000;
  while(i)
    i--;
}
