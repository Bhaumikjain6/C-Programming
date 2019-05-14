#include "MathUtils.h"
#include "DspInit.h"

/*
  This function is dependent on the following functions:
  -> mean();                     -> convolution();
  -> subtractElement();          -> findPeaks();
  -> MhrPtBpf();                 -> sortI();
  -> absf();                     -> computeHeartRate();
  -> divideElement();            -> moving_window_average();
  -> findMax();
  -> MhrPtDf();
  -> squareArray();
*/

void pantompkinsMhr(const float*, const size_t, int* , size_t* );
void pantompkinsFhr(const float *, size_t , int* , size_t*);
