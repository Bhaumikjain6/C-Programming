#include "fhr.c"

static int mhrLocs[3] = {0,0,0};
static int fhrLocs[4] = {0,0,0,0};

static int mhrCount = 0;
static int fhrCount = 0;

void algorithmFhr(float* V1n, float* V4n){
  float mhrOutputOfBpf1045[IPSIZE];
  float fhrOutputOfBpf1045[IPSIZE];
  float newQrsMhr[NEWQRSRANGE], newQrsFhr[NEWQRSRANGE];
  float ref[blockLength];
  float F[blockLength];
  float fhrInputToAdaptDS[blockLength/2];
  float mhrInputToAdaptDS[blockLength/2];
  float fhrOutputOfAdaptUS[blockLength];
  float outputOfLms[blockLength/2];
  float fhrOutputOfMatchFilter[blockLength];

  float A;
  float meanOfMhrInput = 0;
  float meanOfFhrInput = 0;

  FhrBpf1045(V1n, V4n, mhrOutputOfBpf1045, fhrOutputOfBpf1045);

  memcpy(inputToMhrPt, mhrOutputOfBpf1045, IPSIZE * sizeof(float));
  memcpy(inputToMhrPt + IPSIZE, mhrOutputOfBpf1045 + 49, 16 * sizeof(float));

  memcpy(inputToFhrPt, fhrOutputOfBpf1045, IPSIZE * sizeof(float));
  memcpy(inputToFhrPt + IPSIZE, fhrOutputOfBpf1045 + 49, 16 * sizeof(float));

  pantompkinsMhr(inputToMhrPt,blockLength,mhrLocs, &mhrCount);

  memcpy(newQrsMhr, inputToMhrPt + mhrLocs[0], NEWQRSRANGE * sizeof(float));

  A = mean(inputToMhrPt + 49,467);
  createArray(ref,A,blockLength);
  meanImputation(ref,newQrsMhr,mhrLocs,&mhrCount);

  meanOfMhrInput = mean(mhrOutputOfBpf1045 + 49, 450);
  meanOfFhrInput = mean(fhrOutputOfBpf1045 + 49, 450);

  createArray(F,(meanOfMhrInput - meanOfFhrInput),blockLength);
  arraysum(F, ref, blockLength, F);

  createArray(newQrsFhr,meanOfFhrInput,NEWQRSRANGE);
  meanImputation(inputToFhrPt, newQrsFhr, mhrLocs, &mhrCount);

  downSample(F,mhrInputToAdaptDS,2,blockLength);
  downSample(inputToFhrPt,fhrInputToAdaptDS,2,blockLength);

  adaptFiltDownsampleFhr(mhrInputToAdaptDS,fhrInputToAdaptDS,mhrOutputOfAdaptDS,
           fhrOutputOfAdaptDS);
  lms(mhrOutputOfAdaptDS,fhrOutputOfAdaptDS);
  adaptFiltUpsampleFhr(outputOfLms, fhrOutputOfAdaptUS);

  matchFilterFhr(fhrOutputOfAdaptUS,fhrOutputOfMatchFilter);
  pantompkinsFhr(fhrOutputOfMatchFilter, blockLength, fhrLocs, &fhrCount);
}
