#include <stdio.h>
#include <stdlib.h>

void swapElement(float* , float* );
void sortD(float* , int);
void sortI(float* , int);

void addElement(const float* , size_t size, float);
void subtractElement(const float* , size_t size, float);
void divideElement(const float* , size_t size, float);
void arraysum(const float* , const float* , size_t, float*);

void absf( float*, size_t);
void findMax(const float* , size_t size);
float mean(const float*, const size_t);

void upSampling(const float* , float* , size_t);
void downSampling(const float* , float* , size_t);

void dotProduct(const float* , const float*, size_t ); 
