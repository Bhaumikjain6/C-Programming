#ifndef commProto_H
#define commProto_H
/*
  The following Header files includes functions for the communication
  protocols.

  The function depends on following functions:
  -> SPI_receieveData();
  -> SPI_transmitData();
  -> UART_transmitData();
*/
/* Includes the header files required for the following functions */
#include <spi.h>
#include <uart.h>
#include "variables.h"
//*****************************************************************************
//! Can be used to send data over SPI.
//! Call spiInit functions respectively before calling this function.
//!
//! \param Module Instance on which the data has to be transmitted.
//!     EUSCI_A1_BASE               EUSCI_B1_BASE
//!     EUSCI_A2_BASE               EUSCI_B2_BASE
//!     EUSCI_A3_BASE               EUSCI_B3_BASE
//!     EUSCI_A4_BASE               EUSCI_B4_BASE
//!
//! \param TxD: The data which has to be transmitted. Type has to
//!             uint8_t;
//  \return : The data received to the SPI module
//*****************************************************************************
extern uint8_t sendDataSpi(uint32_t moduleInstance, uint8_t TxD);
//*****************************************************************************
//! Can be used to send data over UART.
//! Call UARTInit functions respectively before calling this function.
//!
//! \param Module Instance on which the data has to be transmitted.
//!     EUSCI_A1_BASE               EUSCI_B1_BASE
//!     EUSCI_A2_BASE               EUSCI_B2_BASE
//!     EUSCI_A3_BASE               EUSCI_B3_BASE
//!     EUSCI_A4_BASE               EUSCI_B4_BASE
//!
//! \param TxD: The data which has to be transmitted. Type has to
//!             uint8_t;
//  \return : None
//*****************************************************************************
extern void sendDataUart(uint32_t moduleInstance, uint8_t);

#endif
