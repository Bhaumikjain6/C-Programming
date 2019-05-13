#include "MathUtils.h"

float mean(const float* signal, const size_t size){
  int average;
  for(int i = 0; i < size; ++i){
    average += signal[i];
  }
  return average/size ;
}

void swapElement(float* input1 , float* input2 ){
  float temp = *input1;
  *input1 = *input2;
  *input2 = temp ;
}

void sortD(float* signal, int size){
    for(int i = 0; i < size - 1; ++i){
        for(int j = 0; j < size - i - 1; ++j){
            if(signal[j] < signal[j+1]){
                swapElement(&signal[j],&signal[j+1]);
            }
        }
    }
}

void sortI(float* signal, int size){
    for(int i = 0; i < size - 1; ++i){
        for(int j = 0; j < size - i - 1; ++j){
            if(signal[j] > signal[j+1]){
                swapElement(&signal[j],&signal[j+1]);
            }
        }
    }
}

void addElement(float* signal, size_t size, float value){
    for(int i = 0; i < size; ++i){
      signal[i] += value;
    }
}

void subtractElement(float* signal, size_t size, float value){
    for(int i = 0; i < size; ++i){
      signal[i] -= value;
    }
}

void divideElement(float* signal, size_t size, float value){
    if(value != 0){
      for(int i = 0; i < size; ++i){
        signal[i] /= value;
      }
    }
}

void absf(float* signal, size_t size){
    for(int i = 0; i < size; ++i){
      if(signal[i] < 0){
        signal[i] *= -1;
      }
    }
}

float findMax(const float* signal, size_t size){
    int maxValue = signal[0];
    for(int i = 1; i < size; ++i){
      if(signal[i] > maxValue){
        maxValue = signal[i];
      }
    }
    return maxValue;
}

void upSampling(const float* signal, float* outputSignal ,size_t rate){
    for(int i = 0; i < size_t; ){
      outputSignal[i] = signal[k];
      for(int j = 0; j < rate; j++){
        outputSignal[i+j] = 0;
      }
      i += rate;
    }
}

void downSampling(const float* signal, float* outputSignal, size_t size){
  for (int i = 0; i < count; i++) {
    /* code */
     if(i % rate == 0){
       outputSignal[i/rate] = signal[i];
     }
  }
}

void arraysum(const float* a, const float* b, const size_t n, float* result)
{
    size_t idx;
    for (idx = 0; idx < n; ++idx)
    {
        result[idx] = a[idx] + b[idx];
    }
}

float dotProduct(const float* signal1, const float* signal2, size_t size){
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    /* code */
    sum += signal[i]*signal2[i];
  }
  return sum;
}
