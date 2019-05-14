#include "DspInit.h"

void FhrBpf1045Init(void){
    //10-45 BPF MHR
    arm_fir_init_f32(&InstanceforMhrBpf1045, numTapsOfBpf1045, (float32_t *) CoeffOfFhr1045Bpf,
                   mhrBpf1045Statearr, blockSizeOfFhr1045);
    //10-45 BPF FHR
    arm_fir_init_f32(&InstanceforFhrBpf1045, numTapsOfBpf1045, (float32_t *) CoeffOfFhr1045Bpf,
                   fhrBpf1045Statearr, blockSizeOfFhr1045);
}

void FhrBpf1045(const float* inputToBpf1, const float* inputToBpf2, float outputBpf1, float outputBpf2){
    FhrBpf1045Init();
    arm_fir_f32(&InstanceforMhrBpf1045, inputToBpf1, outputBpf1, blockSizeOfFhr1045);
    arm_fir_f32(&InstanceforFhrBpf1045, inputToBpf2,outputBpf2, blockSizeOfFhr1045);
}

void MhrPtBpfInit(){
  arm_fir_init_f32(&InstanceforMhrPtBpf, numTapsOfMhrPtBpf, (float32_t *) CoeffOfMhrPtBpf,
                 mhrPtBpfStatearr, blockSizeOfMhrPtBpf);
}


void MhrPtBpf(const float* inputToBpf, float* outputOfBpf){
    MhrBpfPtInit();
    arm_fir_f32(&InstanceforMhrPtBpf, inputToBpf, outputOfBpf,
    blockSizeOfMhrPtBpf);
}

void MhrPtDfInit(void){
  arm_fir_init_f32(&InstanceforMhrPtDf, numTapsOfMhrPtDf, (float32_t *) CoeffOfMhrPtDf,
                    &mhrPtDfStatearr, blockSizeOfMhrPtDf);
}

void MhrPtDf(const float* inputToMhrPtDf, float* outputOfMhrPtDf){
  MhrDfPtInit();
  arm_fir_f32(&InstanceforMhrPtDf, inputToMhrPtDf, outputOfMhrPtDf,
              blockSizeOfMhrPtDf);
}

void convolution(const float* input, size_t inputSize, const float* coeff, size_t coeffSize, float* output){
  arm_conv_f32(input, inputSize, coeff, coeffSize, output);
}

void adaptFiltDownsampleInit(void){
  //Resample-Downsample
  arm_fir_init_f32(&InstanceforMhrAdaptFiltDS, numTapsOfAdaptFiltDS, (float32_t *) coeffOfAdaptFiltDS,
                 &mhrAdaptFiltDSStatearr, blockSizeOfAdaptFiltDS);

  //Resample-Downsample-FHR
  arm_fir_init_f32(&InstanceforFhrAdaptFiltDS, numTapsOfAdaptFiltDS, (float32_t *) &coeffOfAdaptFiltDS,
                 &fhrAdaptFiltDSStatearr, blockSizeOfAdaptFiltDS);
}

void adaptFiltDownsampleFhr(const float* mhrInputToAdaptDS,const float* fhrInputToAdaptDS, float* mhrOutputOfAdaptDS, float* fhrOutputOfAdaptDS){
    adaptFiltDownsampleInit();
    //Downsample by a factor of 2
    arm_fir_f32(&InstanceforMhrAdaptFiltDS, mhrInputToAdaptDS, mhrOutputOfAdaptDS,
    blockSizeOfAdaptFiltDS);

    arm_fir_f32(&InstanceforFhrAdaptFiltDS, fhrInputToAdaptDS, fhrOutputOfAdaptDS,
    blockSizeOfAdaptFiltDS);
}

void adaptFiltUpsampleInit(void){
  //Resample-Upsample
  arm_fir_init_f32(&InstanceforMhrAdaptFiltUS, numTapsOfAdaptFiltUS, (float32_t *) coeffOfAdaptFiltUS,
                 &mhrAdaptFiltUSStatearr, blockSizeOfAdaptFiltUS);
}

void adaptFiltUpsampleFhr(const float* mhrInputToAdaptUS, float* mhrOutputOfAdaptUS){
    adaptFiltUpsampleInit();
    //Upsample by a factor of 2
    arm_fir_f32(&InstanceforMhrAdaptFiltUS, mhrInputToAdaptUS, mhrOutputOfAdaptUS,
    blockSizeOfAdaptFiltUS);
}

void matchFilterFhrInit(const float* coeffOfMatchFilt){
  int i = 0;
  for(i = 0; i < BLOCKSIZE; ++i){
     coeffOfMatchFilt[i] = coeffOfMatchFilt[BLOCKSIZE - i];
  }
  arm_fir_init_f32(&InstanceforFhrMatchFilt, numTapsOfMatchFilter, (float32_t *) coeffOfMatchFilt,
                   fhrMatchFiltStatearr, blockSizeOfMatchFilt);
}

void matchFilterFhr(const float* inputToMatch, float* outputOfMatch){
  int i = 0;
  matchFiltFhrInit(inputToMatch);
  arm_fir_f32(&InstanceforFhrMatchFilt, inputToMatch, outputOfMatch,
      blockSizeOfMatchFilt);
  revereseArray(outputOfMatch,blockSizeOfMatchFilt);
}

void FhrPtBpfInit(void){
  arm_fir_init_f32(&InstanceForFhrPtBpf, numTapsOfFhrPtBpf,
                 (float32_t *) coeffOfFhrPtBpf,
                 fhrPtBpfStatearr, blockSizeOfFhrPtBpf);
}

void FhrPtBpf(const float* inputToFhrPtBpf, float* outputOfFhrPtBpf){
  FhrPtBpfInit();
  arm_fir_f32(&InstanceForFhrPtBpf, inputToFhrPtBpf, outputOfFhrPtBpf,
          blockSizeOfFhrPtBpf);
}

void FhrPtDfInit(void){
  arm_fir_init_f32(&InstanceForFhrPtDf, numTapsOfFhrPtDf,
                 (float32_t *) coeffOfFhrPtDf,fhrPtDfStatearr, blockSizeofFhrPtDf);
}

void FhrPtDf(const float* inputToFhrPtDf, float* outputOfFhrPtDf){
    FhrPtDfInit();
    arm_fir_f32(&InstanceForFhrPtDf, inputToFhrPtDf,
                  outputOfFhrPtDf, blockSizeOfFhrPtDf);
}

void UcLpfInit(void){
  arm_fir_init_f32(&InstanceForUcLpf, numTapsOfUcLpf, (float32_t *) coeffOfUcLpf,
                ucLpfStatearr,blockSizeOfUcLpf);
}

void UcLpf(const float* inputToUcLpf, float* outputOfUcLpf){
  UcLpfInit();
  arm_fir_f32(&InstanceForUcLpf, inputToUcLpf, outputOfUcLpf,
    blockSizeOfUcLpf);
}

void UcNotchFiltInit(void){
  arm_fir_init_f32(&instanceForUcNotch, numTapsOfUcNotch, (float32_t*) coeffOfUcNotch,
                    &UcNotchStatearr, blockSizeOfUcNotch);
}

void UcNotchFilt(const float* inputToUcNotch, float* outputOfUcNotch){
  UcNotchFiltInit();
  arm_fir_f32(&instanceForUcNotch, inputToLpfNotch, outputOfUcNotch,
    blockSizeOfUcNotch);
}

void UcBpfInit(void){
  arm_fir_init_f32(&instanceForUcBpf, numTapsOfUcBpf, (float32_t *)
      coeffOfUcBpf,ucBpfStateArr,blockSizeofUcBpf);
}

void UcBpf(const float* inputToUcBpf, float* outputOfUcBpf){
  UcBpfInit();
  arm_fir_f32(&instanceForUcBpf,inputToUcBpf,outputOfUcBpf,
      blockSizeofUcBpf);
}

float UcRms(const float* inputToUcRms , size_t sizeOfInputRms){
  float outputOfUcRms = 0;
  arm_rms_f32(inputToUcRms, sizeOfInputRms, &outputOfUcRms);
  return outputOfUcRms;
}

void UcRmsInterpInit(int ucRmsUpsampleFactor){
  arm_fir_interpolate_init_f32(&InstanceForUcRmsInterp, ucUpsampleFactor, numTapsOfUcRmsInterp,
                      (float32_t *) coeffOfUcRmsInterp, ucRmsInterpStatearr, blockSizeOfUcRmsInterp);
}

void UcRmsInterp(const float* inputToUcRmsInterp, float* outputOfUcRmsInterp,
                int ucRmsUpsampleFactor){
  UcRmsInterpInit(ucRmsUpsampleFactor);
  arm_fir_interpolate_f32(&InstanceForUcRmsInterp,inputToUcRmsInterp,
                outputOfUcRmsInterp, blockSizeOfUcRmsInterp);
}

void UcThkInterpInit(int ucThkUpsampleFactor){
  arm_fir_interpolate_init_f32(&instanceForUcThkInterp, ucThkUpsampleFactor,
    numTapsOfUcThkInterp,(float32_t *) coeffOfUcThkInterp, ucThkInterpStatearr, blockSizeOfUcThkInterp);
}

void UcThkInterp(const float* inputToUcThkInterp, float* outputOfUcThkInterp,
          int ucThkUpsampleFactor){
  UcThkInterpInit(ucThkUpsampleFactor);
  arm_fir_interpolate_f32(&instanceForUcThkInterp, inputToThkInterp,
          outputOfUcThkInterp, blockSizeOfUcThkInterp);
}
