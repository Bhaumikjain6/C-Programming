#include "variables.h"
#include "MathUtils.h"

//***********************************************************************/
int moving_window_average(int* moving_average_array, int rate, int fhrMhr);
int computeHeartRate(int* locs, int currentIndex, int* qi1, int fhrMhr);
void comparePeaks(int* mhr_locs, int* fhr_locs, int mhrCount, int fhrCount);
int heartRate(int n, int* locs, int fhrMhr);
int heartRateAverage(int* diff, int size);
