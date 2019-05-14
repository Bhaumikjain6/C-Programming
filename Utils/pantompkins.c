#include "pantompkins.h"

static int mhrRate = 0;
static int previousRate = 0;
static int idx1 = 0;

void pantompkinsMhr(const float* inputToMhrPt, const size_t blockLength, int* mhrLocs, size_t* mhrCount){
  float meanOfInput = 0;
  float outputOfMhrPtBpf[blockLength];
  float outputOfMhrPtDf[blockLength];
  float convolutedMatrix[blockLength + numTapsOfFhrConvolution - 1];
  float meanforFindPeaks = 0;
  int i = 0;

  meanOfInput = mean(inputToMhrPt, blockLength);
  subtractElement(inputToMhrPt, meanOfInput);
  MhrPtBpf(inputToMhrPt, outputOfMhrPtBpf);
  absf(outputOfMhrPtBpf, blockLength);
  divideElement(outputOfMhrPtBpf,blockLength, findMax(outputOfMhrPtBpf));
  MhrPtDf(outputOfMhrPtBpf, outputOfMhrPtDf);
  divideElement(outputOfMhrPtDf,findMax(outputOfMhrPtDf));
  squareArray(outputOfMhrPtDf, blockLength);
  convolution(outputOfMhrPtDf, blockLength, coeffOfFhrConvolution,
          numTapsOfFhrConvolution, convolutedMatrix);
  meanForFindPeaks = mean(convolutedMatrix + 64, 436);
  findPeaks(convolutedMatrix + 64, 436, mhrMinPeakDistance,0);
  (*mhrCount) = finalPeaks;

  for (i = 0; i < peaksCount; i++){
    if (peaksAndLocs[i].key > 0){
        qi1[qi1_ind] = peaksAndLocs[i].key;
        qi1_ind++;
    }
  }
  sortI(mhrLocs,qi1_ind);
  mhrRate = computeHeartRate(mhr_locs, k , qi1, 0);

  if((idx1 >= 1)){
    moving_average_counter++;
    average_mhr = moving_window_average(mhr_moving_average_array, mhrRate,0);
  }
}

void pantompkinsFhr(const float* outputOfMatchFilt, size_t blockLength, int* fhrLocs, size_t* fhrCount){
  float meanOfInput = 0;
  float outputOfFhrPtBpf[blockLength];
  float outputOfFhrPtBpf[blockLength];
  float convolutedMatrix[blockLength + numTapsOfFhrConvolution - 1];
  float meanToFindPeaks = 0;
  int rate;

  meanOfInput = mean(outputOfMatchFilt, blockLength);
  subtractElement(outputOfMatchFilt, meanOfInput);
  FhrPtBpf(outputOfMatchFilt,outputOfFhrPtBpf);
  memcpy(inputToFhrPtDf, outputOfFhrPtBpf, blockLength);
  absf(outputOfFhrPtBpf,blockLength);
  divideElement(inputToFhrPtDf,findMax(outputOfFhrPtBpf));
  FhrPtDf(inputToFhrPtDf, outputOfFhrPtDf);
  divideElement(outputOfFhrPtDf,findMax(outputOfFhrPtDf));
  squareArray(outputOfFhrPtDf,blockLength);
  convolution(outputOfFhrPtDf,blockLength,coeffOfFhrConvolution,
          numTapsOfFhrConvolution, convolutedMatrix);
  meanToFindPeaks = mean(convolutedMatrix + 99, 381);
  findPeaks(convolutedMatrix+99,381,fhrMinPeakDistance,1);
  (*fhrCount) =  finalPeaks;

  for (i = 0; i < peaksCount; i++){
      if (peaksAndLocs[i].key > 0){
          qi2[qi2_ind] = peaksAndLocs[i].key;
          qi2_ind++;
      }
  }

  sortI(fhrLocs, (*fhrCount));
  comparePeaks(mhr_locs, qi2, mhrCount, fhrCount);
  rate = computeHeartRate(fhr_locs, k , qi2, 1);

  if(rate == 0 || (rate < mhrRate)){
      rate = previousRate;
  }
  previousRate = rate;

  if((idx1 >= 1)){
      average_fhr = moving_window_average(fhr_moving_average_array, rate,1);
  }
  idx1++;
}
