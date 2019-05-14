#include "uc.h"

static int timeCount = 0;
static int rmsCount = 0;
static int bpfCount = 0;

void amplitudeCheck(float*outputOfUcRmsInterp, float* outputOfUcThkInterp, int* finalIndex, size_t sizeOfFinalIndex){
  float maxInterpRms;
  float maxInterpThk;

  int i = 0;
  for(i = 0; i < sizeOfFinalIndex; i += 2){
    maxInterpRms = findMax(outputofUcRmsInterp + finalIndex[i], finalIndex[i+1]);
    maxInterpThk = findMax(outputOfUcThkInterp + finalIndex[i], finalIndex[i+1]);

    if(((maxInterpRms < 0) || (maxInterpThk < 0)) ||
        (maxInterpThk > (1.085 * maxInterpRms))){
      finalIndex[i] = 0;
      finalIndex[i+1] = 0;
    }
  }
}

void algorithmUc(const float* V1, const float* V2, const float* V3, const float* V4){
    float inputToSmoothfilter[IPSIZE+50];
    float outputOfSmoothFilter[IPSIZE];
    float inputToUcRmsUs[1350];
    float inputToUcBpf[54];
    float outputOfUcBpf[54];
    float inputToUcRms[1080];
    float outputOfUcRms[RMSPOINTS];
    float outputOfUcThkInterp[];

    float Btk[200];
    float Thk[200];

    int finalIndex[100];
    int i = 0;
    size_t intersectionSize = 0;

    for(i = 0; i < IPSIZE; ++i){
      inputToSmoothFilter[i] = V1[i] + V2[i] + V3[i] + V4[i];
    }
    smoothing(inputToSmoothFilter,outputOfSmoothFilter,IPSIZE,5);
    arraySubtract(inputToSmoothFilter,outputOfSmoothFilter,IPSIZE);
    createArray(inputToSmoothFilter + 500, 0, 50);

    UcLpf(inputToSmoothFilter, outputOfUcLpf);
    UcNotchFilt(outputOfUcLpf, outputOfUcNotchFilt);

    memcpy(inputToUcRmsUs + (timeCount * 450), outputOfUcNotchFilt + 75,
        450 * sizeof(float));
    timeCount++;

    if(timeCount >= 3){
        timeCount = 0;
        downSample(inputToUcRmsUs,inputToUcRmsDs,25,1350);
        ucBpf(inputToUcBpf, outputOfUcBpf);
        if(rmsCount < 20){
          appendArray(inputToUcRms + (rmsCount * blockSizeofUcBpf),
              outputOfUcBpf, blockSizeOfUcBpf);
          bpfCount++;
        }
        else{
          for(i = 0; i < 1026; ++i){
            inputToUcRms[i] = inputToUcRms[i+54];
          }
          for(i = 0; i < 54; ++i){
            inputToUcRms[i] = outputOfUcBpf[i];
          }
        }
        if((bpfCount == 20) && (timeCount == 3)){
          arrayMultiply(inputToUcRms, cosFile);
        }
        outputOfUcRms[rmsCount++] = UcRms(inputToUcRms, 1080);
        if(rmsCount > RMSPOINTS){
          UcRmsInterp(outputOfUcRms, outputOfUcRmsInterp, 20);
          for(i = 0; i < ((RMSPOINTS * 20) - 400); i += 30){
            float inputToThreshold[400];

            memcpy(inputToThreshold, outputOfUcRmsInterp + i , 400);
            sortI(inputToThreshold, 400);

            Btk[k] = mean(inputToThreshold, 40);
            Thk[k] = Btk[k] + (0.25)* (inputToThreshold[399] - inputToThreshold[0]);
            k++;
          }
          UcThkInterp(Thk,outputOfUcThkInterp,35);
          multiplyElement(outputOfUcThkInterp, 35);
          intersectionSize = (k * 35 > RMSPOINTS * 20) ? RMSPOINTS*20 : k * 35 ;
          arraySubtract(outputOfUcThkInterp, outputOfUcRmsInterp,intersectionSize);
          findSlopeChange(outputOfUcThkInterp,finalIndex,intersectionSize);
          timeCheck(finalIndex, sizeOfFinalIndex, ucMinPeakDistance);
          amplitudeCheck(outputOfUcRmsInterp, outputOfUcThkInterp, finalIndex, sizeOfFinalIndex);

        }
    }
}
