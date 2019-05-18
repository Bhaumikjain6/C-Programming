#include "variables.h"

/********Constants related to Communication Protocols *************************/
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

/****************************** Filter instances *****************************/
arm_fir_instance_f32 InstanceforMhrBpf1045, InstanceforFhrBpf1045;
arm_fir_instance_f32 InstanceforMhrPtBpf;
arm_fir_instance_f32 InstanceforMhrPtDf;
arm_fir_instance_f32 InstanceforMhrAdaptFiltDS;
arm_fir_instance_f32 InstanceforFhrAdaptFiltDS;
arm_fir_instance_f32 InstanceforMhrAdaptFiltUS;
arm_fir_instance_f32 InstanceforFhrMatchFilt;
arm_fir_instance_f32 InstanceForFhrPtBpf;
arm_fir_instance_f32 InstanceForFhrPtDf;
arm_fir_instance_f32 InstanceForUcLpf;
arm_fir_instance_f32 instanceForUcNotch;
arm_fir_instance_f32 instanceForUcBpf;
arm_fir_instance_f32 InstanceForUcRmsInterp;
arm_fir_instance_f32 instanceForUcThkInterp;

/****************************************************************************/
/**************************** Filter StateArrays ****************************/
float mhrBpf1045Statearr[blockSizeOfFhr1045 + numTapsOfBpf1045 - 1];
float fhrBpf1045Statearr[blockSizeOfFhr1045 + numTapsOfBpf1045 - 1];
float mhrPtBpfStatearr[blockSizeOfMhrPtBpf + numTapsOfMhrPtBpf - 1];
float mhrPtDfStatearr[blockSizeOfMhrPtDf + numTapsOfMhrPtDf - 1];
float mhrAdaptFiltDSStatearr[blockSizeOfAdaptFiltDS + numTapsOfAdaptFiltDS - 1];
float fhrAdaptFiltDSStatearr [blockSizeOfAdaptFiltDS + numTapsOfAdaptFiltDS - 1];
float mhrAdaptFiltUSStatearr[blockSizeOfAdaptFiltUS + numTapsOfAdaptFiltUS - 1];
float fhrMatchFiltStatearr[blockSizeOfMatchFilt + numTapsOfMatchFilter - 1];
float fhrPtBpfStatearr[blockSizeOfFhrPtBpf + numTapsOfFhrPtBpf - 1];
float fhrPtDfStatearr[blockSizeofFhrPtDf + numTapsOfFhrPtDf - 1];
float ucLpfStatearr[blockSizeOfUcLpf + numTapsOfUcLpf - 1];
float UcNotchStatearr[blockSizeOfUcNotch + numTapsOfUcNotch - 1];
float ucBpfStateArr[blockSizeofUcBpf + numTapsOfUcBpf - 1];
float ucRmsInterpStatearr[blockSizeOfUcRmsInterp + numTapsOfUcRmsInterp - 1];
float ucThkInterpStatearr[blockSizeOfUcThkInterp + numTapsOfUcThkInterp - 1];

/****************************************************************************/
/**************************** Filter coefficients **************************/
const float CoeffOfFhr1045Bpf[numTapsOfBpf1045] = {-0.00183621,-0.00232659,-0.00281714,-0.00315782,-0.003108,-0.0024614,-0.00122497,0.000229142,0.00112925,0.000449396,-0.00276563,-0.0089707,-0.0177223,-0.0274691,-0.0356554,-0.0391769,-0.0351186,-0.0215993,0.00151149,0.0322347,0.0666269,0.0994459,0.125206,0.139369,0.139369,0.125206,0.0994459,0.0666269,0.0322347,0.00151149,-0.0215993,-0.0351186,-0.0391769,-0.0356554,-0.0274691,-0.0177223,-0.0089707,-0.00276563,0.000449396,0.00112925,0.000229142,-0.00122497,-0.0024614,-0.003108,-0.00315782,-0.00281714,-0.00232659,-0.00183621
const float CoeffOfMhrPtBpf[numTapsOfMhrPtBpf] = { 0.00410914, 0.00629557,0.0118891, 0.0214315, 0.0347167, 0.0507797, 0.0680232, 0.0844633, 0.0980501, 0.107008, 0.110136, 0.107008, 0.0980501, 0.0844633,0.0680232, 0.0507797,0.0347167, 0.0214315,0.0118891, 0.00629557,0.00410914 };
const float CoeffOfMhrPtDf[numTapsOfMhrPtDf] = { -72.5,-92.5, -112.5, -110, -70, -30, 10, 50, 90, 122.5, 102.5, 82.5, 62.5 };
const float coeffOfAdaptFiltDS[numTapsOfAdaptFiltDS] = { -2.76208e-18, -0.0126325, 0.0513662,-0.113821, 0.174684, 0.800807, 0.174684, -0.113821, 0.0513662, -0.0126325,-2.76208e-18 };
const float coeffOfAdaptFiltUS[numTapsOfAdaptFiltUS] = {-0.00127568, -0.00232894, 0.00610461,-7.11936e-18, -0.0132793, 0.0114613,0.0156842, -0.0343721, 1.79981e-17,0.0641674, -0.0569278, -0.0899427,0.300179, 0.601061, 0.300179, -0.0899427,-0.0569278, 0.0641674, 1.79981e-17,-0.0343721, 0.0156842, 0.0114613,-0.0132793, -7.11936e-18, 0.00610461,-0.00232894, -0.00127568 };
const float coeffOfFhrPtBpf[numTapsOfFhrPtBpf] = { -2.95584e-19,-0.000306267,-0.000561524,-0.000603486,-0.000148737,0.00114979,0.00354537,0.00698236,0.0109089,0.014218,0.0153927,0.0128684,0.0055458,-0.00668698,-0.0225995,-0.0395879,-0.0540473,-0.0621141,-0.0606199,-0.0480142,-0.0249929,0.00537944,0.0381344,0.0673805,0.0875762,0.0947828,0.0875762,0.0673805,0.0381344,0.00537944,-0.0249929,-0.0480142,-0.0606199,-0.0621141,-0.0540473,-0.0395879,-0.0225995, 0.00668698,0.0055458,0.0128684,0.0153927,0.014218,0.0109089,0.00698236,0.00354537,0.00114979,-0.000148737,-0.000603486,-0.000561524,-0.000306267,-2.95584e-19};
const float coeffOfFhrPtDf[numTapsOfFhrPtDf] = { -72.5,-92.5,-112.5,-110,-70,-30,10,50,90,122.5,102.5,82.5,62.5};
const float coeffOfUcLpf[numTapsOfUcLpf] = {                                                    0.00112657,0.0015683,0.00208408,0.00267548,0.00334257,0.00408383,0.00489607,0.00577432,0.00671192,0.00770051,0.00873014,0.00978939,0.0108656,0.011945,0.0130131,0.0140549,0.0150552,0.015999,0.0168715,0.017659,0.0183489,0.0189298,0.019392,0.0197278,0.0199317,0.02,0.0199317,0.0197278,0.019392,0.0189298,0.0183489,0.017659,0.0168715,0.015999,0.0150552,0.0140549,0.0130131,0.011945,0.0108656,0.00978939,0.00873014,0.00770051,0.00671192,0.00577432,0.00489607,0.00408383,0.00334257,0.00267548,0.00208408,0.0015683,0.00112657
};
const float coeffOfUcNotch[numTapsOfUcNotch] = {-0.00140083,-0.00217711,-0.00132499,0.00189272,0.00655745,0.0101083,0.00970746,0.00421589,-0.00460964,-0.0127208,0.984,-0.0127208,-0.00460964,0.00421589,0.00970746,0.0101083,0.00655745,0.00189272,-0.00132499,-0.00217711,-0.00140083
};
const float coeffOfUcBpf[numTapsOfUcBpf] = {-4.56589e-18,-0.0284601,-0.0724254,-0.102017,-0.0814521,0,0.11012,0.188843,0.188843,0.11012,0,-0.0814521,-0.102017,-0.0724254,-0.0284601,-4.56589e-18,
};
const float coeffOfUcRmsInterp[numTapsOfUcRmsInterp] = {-0.000077,-0.000103,-0.000130,-0.000160,-0.000190,-0.000222,-0.000255,-0.000288,-0.000321,-0.000353,-0.000385,-0.000414,-0.000441,-0.000465,-0.000486,-0.000503,-0.000515,-0.000521,-0.000522,-0.000517,-0.000505,-0.000485,-0.000458,-0.000423,-0.000381,-0.000329,-0.000270,-0.000203,-0.000127,-0.000044,0.000046,0.000143,0.000246,0.000355,0.000468,0.000584,0.000703,0.000823,0.000944,0.001062,0.001178,0.001290,0.001396,0.001494,0.001583,0.001662,0.001728,0.001781,0.001819,0.001840,0.001843,0.001827,0.001791,0.001734,0.001656,0.001555,0.001431,0.001285,0.001116,0.000925,0.000712,0.000478,0.000225,-0.000046,-0.000335,-0.000638,-0.000953,-0.001279,-0.001612,-0.001949,-0.002288,-0.002625,-0.002956,-0.003279,-0.003588,-0.003882,-0.004154,-0.004402,-0.004622,-0.004810,-0.004961,-0.005073,-0.005141,-0.005162,-0.005133,-0.005051,-0.004914,-0.004718,-0.004462,-0.004144,-0.003763,-0.003318,-0.002809,-0.002235,-0.001597,-0.000896,-0.000133,0.000690,0.001570,0.002505,0.003491,0.004525,0.005602,0.006719,0.007869,0.009048,0.010251,0.011470,0.012701,0.013936,0.015170,0.016395,0.017605,0.018794,0.019954,0.021079,0.022163,0.023199,0.024181,0.025104,0.025962,0.026749,0.027462,0.028095,0.028645,0.029109,0.029484,0.029767,0.029956,0.030051,0.030051,0.029956,0.029767,0.029484,0.029109,0.028645,0.028095,0.027462,0.026749,0.025962,0.025104,0.024181,0.023199,0.022163,0.021079,0.019954,0.018794,0.017605,0.016395,0.015170,0.013936,0.012701,0.011470,0.010251,0.009048,0.007869,0.006719,0.005602,0.004525,0.003491,0.002505,0.001570,0.000690,-0.000133,-0.000896,-0.001597,-0.002235,-0.002809,-0.003318,-0.003763,-0.004144,-0.004462,-0.004718,-0.004914,-0.005051,-0.005133,-0.005162,-0.005141,-0.005073,-0.004961,-0.004810,-0.004622,-0.004402,-0.004154,-0.003882,-0.003588,-0.003279,-0.002956,-0.002625,-0.002288,-0.001949,-0.001612,-0.001279,-0.000953,-0.000638,-0.000335,-0.000046,0.000225,0.000478,0.000712,0.000925,0.001116,0.001285,0.001431,0.001555,0.001656,0.001734,0.001791,0.001827,0.001843,0.001840,0.001819,0.001781,0.001728,0.001662,0.001583,0.001494,0.001396,0.001290,0.001178,0.001062,0.000944,0.000823,0.000703,0.000584,0.000468,0.000355,0.000246,0.000143,0.000046,-0.000044,-0.000127,-0.000203,-0.000270,-0.000329,-0.000381,-0.000423,-0.000458,-0.000485,-0.000505,-0.000517,-0.000522,-0.000521,-0.000515,-0.000503,-0.000486,-0.000465,-0.000441,-0.000414,-0.000385,-0.000353,-0.000321,-0.000288,-0.000255,-0.000222,-0.000190,-0.000160,-0.000130,-0.000103,-0.000077
};
const float coeffOfUcThkInterp[numTapsOfUcThkInterp] = {                         -0.000169,-0.000176,-0.000182,-0.000188,-0.000193,-0.000197,-0.000201,-0.000203,-0.000205,-0.000205,-0.000204,-0.000202,-0.000199,-0.000194,-0.000188,-0.000180,-0.000170,-0.000159,-0.000146,-0.000131,-0.000113,-0.000094,-0.000072,-0.000048,-0.000022,0.000007,0.000038,0.000072,0.000108,0.000148,0.000190,0.000235,0.000283,0.000335,0.000389,0.000446,0.000507,0.000571,0.000638,0.000708,0.000782,0.000859,0.000940,0.001024,0.001111,0.001202,0.001297,0.001394,0.001495,0.001600,0.001708,0.001819,0.001933,0.002051,0.002172,0.002296,0.002423,0.002553,0.002686,0.002822,0.002961,0.003102,0.003246,0.003392,0.003541,0.003691,0.003844,0.003999,0.004155,0.004314,0.004473,0.004635,0.004797,0.004960,0.005124,0.005289,0.005455,0.005621,0.005787,0.005952,0.006118,0.006284,0.006448,0.006612,0.006775,0.006937,0.007097,0.007256,0.007413,0.007569,0.007722,0.007872,0.008020,0.008166,0.008308,0.008448,0.008584,0.008716,0.008845,0.008970,0.009092,0.009209,0.009321,0.009430,0.009533,0.009632,0.009726,0.009815,0.009899,0.009978,0.010051,0.010119,0.010181,0.010237,0.010288,0.010333,0.010372,0.010406,0.010433,0.010454,0.010469,0.010478,0.010481,0.010478,0.010469,0.010454,0.010433,0.010406,0.010372,0.010333,0.010288,0.010237,0.010181,0.010119,0.010051,0.009978,0.009899,0.009815,0.009726,0.009632,0.009533,0.009430,0.009321,0.009209,0.009092,0.008970,0.008845,0.008716,0.008584,0.008448,0.008308,0.008166,0.008020,0.007872,0.007722,0.007569,0.007413,0.007256,0.007097,0.006937,0.006775,0.006612,0.006448,0.006284,0.006118,0.005952,0.005787,0.005621,0.005455,0.005289,0.005124,0.004960,0.004797,0.004635,0.004473,0.004314,0.004155,0.003999,0.003844,0.003691,0.003541,0.003392,0.003246,0.003102,0.002961,0.002822,0.002686,0.002553,0.002423,0.002296,0.002172,0.002051,0.001933,0.001819,0.001708,0.001600,0.001495,0.001394,0.001297,0.001202,0.001111,0.001024,0.000940,0.000859,0.000782,0.000708,0.000638,0.000571,0.000507,0.000446,0.000389,0.000335,0.000283,0.000235,0.000190,0.000148,0.000108,0.000072,0.000038,0.000007,-0.000022,-0.000048,-0.000072,-0.000094,-0.000113,-0.000131,-0.000146,-0.000159,-0.000170,-0.000180,-0.000188,-0.000194,-0.000199,-0.000202,-0.000204,-0.000205,-0.000205,-0.000203,-0.000201,-0.000197,-0.000193,-0.000188,-0.000182,-0.000176,-0.000169
};

/****************************************************************************/
