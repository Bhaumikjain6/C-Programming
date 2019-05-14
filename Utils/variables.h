#include <stdio.h>
#include <arm_math.h>
#include <arm_const_structs.h>
#include <arm_common_tables.h>

//// Constants /////

//// Constants related to UC algorithm

#define blockSizeOfUcThkInterp              181
#define ucThkUpsampleFactor                 35
#define numTapsOfUcThkInterp                245
#define blockSizeOfUcRmsInterp              181
#define ucRmsUpsampleFactor                 20
#define numTapsOfUcRmsInterp                260
#define sizeOfInputRms                      1080
#define numTapsOfUcNotch                    21
#define blockSizeOfUcNotch                  550
#define numTapsOfUcLpf                      51
#define blockSizeOfUcLpf                    550
#define numTapsOfUcBpf                      16
#define blockSizeofUcBpf                    54

//// Constants related to FHR algorithm
#define blockSizeOfFhrPtDf                  516
#define numTapsOfFhrPtDf                    13
#define blockSizeOfFhrPtBpf                 516
#define numTapsOfFhrPtBpf                   21
#define blockSizeOfMatchFilt                516
#define numTapsOfMatchFilter                516
#define blockSizeOfAdaptFiltUS              516
#define numTapsOfAdaptFiltUS                27
#define blockSizeOfAdaptFiltDS              258
#define numTapsOfAdaptFiltDS                11
#define numTapsOfMhrPtDf                    13
#define blockSizeOfMhrPtDf                  516
#define numTapsOfMhrPtBpf                   21
#define blockSizeOfMhrPtBpf                 516
#define numTapsOfBpf1045                    48
#define blockSizeOfFhr1045                  500

#define IPSIZE                              500
#define NEWQRSRANGE                         39
#define mhrMinPeakDistance                  250
#define fhrMinPeakDistance                  158

//// Variables related to FHR and Uc algorithm
const eUSCI_SPI_MasterConfig spiMasterConfigA = {
EUSCI_A_SPI_CLOCKSOURCE_SMCLK,             // SMCLK Clock Source
        24000000,                                     // SMCLK = DCO = 3MHZ
         8000000,                                    // SPICLK = 500khz
        EUSCI_A_SPI_MSB_FIRST,                     // MSB First
        EUSCI_A_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT,    // Phase
        EUSCI_A_SPI_CLOCKPOLARITY_INACTIVITY_HIGH, // High polarity
        EUSCI_A_SPI_3PIN                           // 3Wire SPI Mode
        };

const eUSCI_SPI_MasterConfig spiMasterConfigB = {
EUSCI_B_SPI_CLOCKSOURCE_SMCLK,             // SMCLK Clock Source
        24000000,                                     // SMCLK = DCO = 3MHZ
        800000,                                    // SPICLK = 500khz
        EUSCI_B_SPI_MSB_FIRST,                     // MSB First
        EUSCI_B_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT,    // Phase
        EUSCI_B_SPI_CLOCKPOLARITY_INACTIVITY_HIGH, // High polarity
        EUSCI_B_SPI_3PIN                           // 3Wire SPI Mode
        };

const eUSCI_UART_Config uartConfig2 = {
EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
        13,                                     // BRDIV = 78
        0,                                       // UCxBRF = 2
        37,                                       // UCxBRS = 0
        EUSCI_A_UART_NO_PARITY,                  // No Parity
        EUSCI_A_UART_LSB_FIRST,                  // LSB First
        EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
        EUSCI_A_UART_MODE,                       // UART mode
        EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
        };
