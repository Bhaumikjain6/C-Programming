#include <stdio.h>
#include <stdlib.h>

void swapElement(float* , float* );                 // verified
void sortD(float* , int);                           //verified
void sortI(float* , int);                           //verified

void addElement( float* , size_t size, float);      //verified
void subtractElement( float* , size_t size, float); //verified
void divideElement( float* , size_t size, float);   //verified
void arraysum(const float* , const float* ,const size_t, float*);

void absf(float*, size_t);
float findMax(const float* , size_t size);         //verified
float mean(const float*, const size_t);            //verified

void upSampling(const float* , float* , size_t, size_t);        //verified
void downSampling(const float* , float* , size_t, size_t);      //verified

float dotProduct(const float* , const float*, size_t );         //verified
