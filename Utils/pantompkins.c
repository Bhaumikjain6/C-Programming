#include "pantompkins.h"

static int mhrRate = 0;
static int previousRate = 0;
static int idx1 = 0;
static int mhrLocs[3];
static int fhrLocs[4];
static int mhrMovingAverageArray[10];
static int fhrMovingAverageArray[20];

void pantompkinsMhr(const float* mhrInputToPt, const size_t sizeOfArray,
                    int* mhrLocs , size_t* mhrCount){
  float meanOfInput = 0;
  float outputOfMhrPtBpf[blockLength];
  float outputOfMhrPtDf[blockLength];
  float convolutedMatrix[blockLength + numTapsOfFhrConvolution - 1];
  float meanforFindPeaks = 0;
  float max = 0;
  int finalPeaks = 0;
  int qi1[3];
  int qi1_ind = 0;
  int average_mhr = 0;
  int i = 0;

  meanOfInput = mean(mhrInputToPt, blockLength);
  subtractElement(mhrInputToPt, blockLength, meanOfInput);
  MhrPtBpf(mhrInputToPt, outputOfMhrPtBpf);
  absf(outputOfMhrPtBpf, blockLength);
  divideElement(outputOfMhrPtBpf,blockLength,findMax(outputOfMhrPtBpf,blockLength));
  MhrPtDf(outputOfMhrPtBpf, outputOfMhrPtDf);
  divideElement(outputOfMhrPtDf,blockLength,findMax(outputOfMhrPtDf,blockLength));
  squareArray(outputOfMhrPtDf, blockLength);
  convolution(outputOfMhrPtDf, blockLength, coeffOfFhrConvolution,
          numTapsOfFhrConvolution, convolutedMatrix);
  meanforFindPeaks = mean(convolutedMatrix + 64, 436);
  finalPeaks = findPeaks(convolutedMatrix + 64, 436, mhrMinPeakDistance,0);
  (*mhrCount) = finalPeaks;

  for (i = 0; i < finalPeaks; i++){
    if (peaksAndLocs[i].key > 0){
        qi1[qi1_ind] = peaksAndLocs[i].key;
        qi1_ind++;
    }
  }
  sortI(mhrLocs,qi1_ind);
  mhrRate = computeHeartRate(mhrLocs, finalPeaks , qi1, 0);

  if((idx1 >= 1)){
    average_mhr = moving_window_average(mhrMovingAverageArray, mhrRate,0);
  }
}

void pantompkinsFhr(const float* outputOfMatchFilt, size_t sizeOfArray,
                    int* fhrLocs, size_t* fhrCount, size_t* mhrCount){
  float meanOfInput = 0;
  float outputOfFhrPtBpf[blockLength];
  float outputOfFhrPtDf[blockLength];
  float convolutedMatrix[blockLength + numTapsOfFhrConvolution - 1];
  float meanToFindPeaks = 0;
  float inputToFhrPtDf[blockLength];
  int rate;
  int finalPeaks = 0;
  int qi2[3];
  int qi2_ind = 0;
  int average_fhr = 0;
  int i = 0;

  meanOfInput = mean(outputOfMatchFilt, blockLength);
  subtractElement(outputOfMatchFilt,blockLength,meanOfInput);
  FhrPtBpf(outputOfMatchFilt,outputOfFhrPtBpf);
  memcpy(inputToFhrPtDf, outputOfFhrPtBpf, blockLength*sizeof(float));
  absf(outputOfFhrPtBpf,blockLength);
  divideElement(inputToFhrPtDf, blockLength, findMax(outputOfFhrPtBpf,blockLength));
  FhrPtDf(inputToFhrPtDf, outputOfFhrPtDf);
  divideElement(outputOfFhrPtDf,blockLength,findMax(outputOfFhrPtDf,blockLength));
  squareArray(outputOfFhrPtDf,blockLength);
  convolution(outputOfFhrPtDf,blockLength,coeffOfFhrConvolution,
          numTapsOfFhrConvolution, convolutedMatrix);
  meanToFindPeaks = mean(convolutedMatrix + 99, 381);
  findPeaks(convolutedMatrix+99,381,fhrMinPeakDistance,1);
  (*fhrCount) =  finalPeaks;

  for (i = 0; i < finalPeaks; i++){
      if (peaksAndLocs[i].key > 0){
          qi2[qi2_ind] = peaksAndLocs[i].key;
          qi2_ind++;
      }
  }

  sortI(fhrLocs, (*fhrCount));
  comparePeaks(mhrLocs, qi2, mhrCount, fhrCount);
  rate = computeHeartRate(fhrLocs, finalPeaks , qi2, 1);

  if(rate == 0 || (rate < mhrRate)){
      rate = previousRate;
  }
  previousRate = rate;

  if((idx1 >= 1)){
      average_fhr = moving_window_average(fhrMovingAverageArray, rate,1);
  }
  idx1++;
}
