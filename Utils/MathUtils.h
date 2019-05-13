#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swapElement(float* , float* );                 // verified
void sortD(float* , int);                           //verified
void sortI(float* , int);                           //verified

void addElement( float* , size_t size, float);      //verified
void subtractElement( float* , size_t size, float); //verified
void divideElement(float* , size_t size, float);   //verified
void multiplyElement(float* , size_t size, float);

void arraysum(const float* , const float* ,const size_t, float*);
void arraySubtract(float*,float*,size_t);
void arrayMultiply(float*, float*, size_t);

void absf(float*, size_t);
float findMax(const float* , size_t size);         //verified
float findMin(const float* , size_t size);
float mean(const float*, const size_t);            //verified

void upSample(const float* , float* , size_t, size_t);        //verified
void downSample(const float* , float* , size_t, size_t);      //verified

float dotProduct(const float* , const float*, size_t );         //verified
void reverseArray(float* , size_t );
void squareArray(float* , size_t )
void createArray(float* , const float, size_t);

void meanImputation(float* , float* , float* , size_t* );
void smoothing(float* , float* , size_t , size_t);
void appendArray(float* , float*, size_t);
