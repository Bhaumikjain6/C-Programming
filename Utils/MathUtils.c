#include "MathUtils.h"

float mean(const float* signal, const size_t size){
  float average = 0;
  int i = 0;
  for(i = 0; i < size; ++i){
    average += signal[i];
  }
  return average/(float)size ;
}

float meanInt(const int* signal, const size_t size){
  int average = 0;
  int i = 0;
  for(i = 0; i < size; ++i){
    average += signal[i];
  }
  return (float)average/(float)size ;
}


void swapElement(float* input1 , float* input2 ){
  float temp = *input1;
  *input1 = *input2;
  *input2 = temp ;
}

void sortD(float* signal, int size){
    int i = 0;
    int j = 0;
    for(i = 0; i < size - 1; ++i){
        for(j = 0; j < size - i - 1; ++j){
            if(signal[j] < signal[j+1]){
                swapElement(&signal[j],&signal[j+1]);
            }
        }
    }
}

void sortI(float* signal, int size){
    int i,j = 0;
    for(i = 0; i < size - 1; i++){
        for(j = 0; j < size - i - 1; j++){
            if(signal[j] > signal[j+1]){
                swapElement(&signal[j],&signal[j+1]);
            }
        }
    }
}

void addElement(float* signal, size_t size, float value){
    int i;
    for(i = 0; i < size; ++i){
      signal[i] += value;
    }
}

void subtractElement(float* signal, size_t size, float value){
    int i;
    for(i = 0; i < size; ++i){
      signal[i] -= value;
    }
}

void divideElement(float* signal, size_t size, float value){
    int i;
    if(value != 0){
      for(i = 0; i < size; ++i){
        signal[i] /= value;
      }
    }
}

void multiplyElement(float* signal, size_t size, float value){
  int i;
  for(i = 0; i < size; ++i){
    signal[i] *= value;
  }
}

void absf(float* signal, size_t size){
    int i;
    for(i = 0; i < size; ++i){
      if(signal[i] < 0){
        signal[i] *= -1;
      }
    }
}

float findMax(const float* signal, size_t size){
    int i;
    int maxValue = signal[0];
    for(i = 1; i < size; ++i){
      if(signal[i] > maxValue){
        maxValue = signal[i];
      }
    }
    return maxValue;
}

float findMin(const float* signal, size_t size){
    int i;
    int minValue = signal[0];
    for(i = 1; i < size; ++i){
      if(signal[i] < minValue){
        minValue = signal[i];
      }
    }
    return minValue;
}

void upSample(const float* signal, float* outputSignal ,size_t rate, size_t size){
    int i,j;
    for(i = 0 ; i < (size*rate); ){
        outputSignal[i] = signal[i / rate];
        for(j = 1; j < rate; ++j){
            outputSignal[i + j] = 0;
        }
        i += rate;
    }
}

void downSample(const float* signal, float* outputSignal, size_t rate,size_t size){
    int i;
    for (i = 0; i < size; i++) {
    /* code */
     if(i % rate == 0){
       outputSignal[i/rate] = signal[i];
     }
  }
}

float dotProduct(const float* signal1, const float* signal2, size_t size){
  int sum = 0;
  int i;
  for (i = 0; i < size; ++i) {
    /* code */
    sum += signal1[i]*signal2[i];
  }
  return sum;
}

void reverseArray(float* inputArray, size_t size){
  int i = 0;
  for(i = 0; i < size; ++i){
    inputArray[i] = inputArray[size - 1];
  }
}

void squareArray(float* inputArray, size_t size){
  int i = 0;
  for(i = 0; i < size; ++i){
    inputArray[i] *= inputArray[i];
  }
}

void createArray(float* inputArray, const float value, size_t size){
  int i = 0;
  for(i = 0; i < size; ++i){
    inputArray[i] = value;
  }
}

void meanImputation(float* input1, float* input2, int* mhrLocs, size_t* mhrCount){
  int i = 0;
  for(i = 0; i < (*mhrCount); ++i){
    memcpy(input1 + mhrLocs[i] - 19, input2, NEWQRSRANGE * sizeof(float));
  }
}

void smoothing(float* inputToSmoothing, float* outputOfSmoothing, size_t size , size_t windowSize){
    int i = 0, j;
    int midPoint = windowSize / 2 ;
    float sum = 0;

    for(i = 0; i < size; ++i){
      if(i < midPoint){
        for(j = 0; j < windowSize - midPoint + i; ++j){
          sum += inputToSmoothing[j];
        }
        outputOfSmoothing[i] = sum / (windowSize - midPoint + i);
      }
      else if((i >= midPoint) && (i < IPSIZE - midPoint)){
        for(j = i - midPoint ; j < windowSize - midPoint + i; ++j){
          sum += inputToSmoothing[j];
        }
        outputOfSmoothing[i] = sum / windowSize;
      }
      else if((i >= IPSIZE - midPoint) && (i < 500)){
        for(j = i - 2; j < IPSIZE ; ++j){
          sum += inputToSmoothing[j];
        }
        outputOfSmoothing[i] = sum / (float)(IPSIZE + midPoint - i);
      }
      sum = 0;
    }
}

void appendArray(float* input1, float* input2, size_t size){
    memcpy(input1, input2 , size * sizeof(float));
}

void appendArray(int* input1, int* input2, size_t size){
    memcpy(input1, input2, size * sizeof(int));
}
void arraysum(const float* a, const float* b, const size_t n, float* result)
{
    size_t idx;
    for (idx = 0; idx < n; ++idx){
        result[idx] = a[idx] + b[idx];
    }
}

void arrayMultiply(float* input1, float* input2, size_t size){
  int i = 0;
  for( i = 0; i < size; ++i){
    input1[i] *= input2[i];
  }
}

void arraySubtract(float* input1, float* input2, size_t size){
    int i = 0;
    for(i = 0; i < size; ++i){
      input1[i] -= input2[i];
    }
}

void findSlopeChange(float* inputToInternalDiff, float* outputOfInternalDiff, size_t size){
  int i = 0;
  for(i = 0; i < size; ++i){
      if(1){}
  }
}
