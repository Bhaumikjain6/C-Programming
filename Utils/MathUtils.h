#ifndef MathUtils_H
#define MathUtils_H
/* Includes the required files for following functions*/
#include "variables.h"
//#include "includeFiles.h"
//*****************************************************************************
//! The function swap Elements by changing the pointers to the respective
//!     values
//!
//! \param: The variables to be swapped.
//!    <br> The memory address of the variable should be passed to the function
//!         For ex: swapElement(&A,&B);
//  \return None
//*****************************************************************************
extern void swapElement(float* inputA , float* inputB);                 // verified
//*****************************************************************************
//! The function sorts a given float array in Descending Order
//!extern void
//! \param: Array which has to be sorted
//!         For ex: sortD(A,516);
//  \return None
//*****************************************************************************
extern void sortD(float* ToBeSorted, int sizeOfArray);                           //verified
//*****************************************************************************
//! The function sorts a given float array in Ascending Order
//!
//! \param: Array which has to be sorted
//!         For ex: sortI(A,516);
//  \return None
//*****************************************************************************
extern void sortI(float* ToBeSorted, int sizeOfArray);                           //verified
//*****************************************************************************
//! The function adds the given Elements to the float array.
//!
//! \param: The float array to which the element has to be added.
//! \param: The size of the float Array.
//! \param: The value to be added. The value has to be float. if the variable
//!             is of other type. Consider typecasting.
//!         For ex: addElement(A,516,(float)5);
//  \return None
//*****************************************************************************
extern void addElement( float* inputArray, size_t sizeOfArray, float toBeAdded);      //verified
//*****************************************************************************
//! The function subtracts the given Elements to the float array.
//!
//! \param: The float array to which the element has to be subtracted.
//! \param: The size of the float Array.
//! \param: The value to be subtracted. The value has to be float. if the variable
//!             is of other type. Consider typecasting.
//!         For ex: subtractElement(A,516,(float)5);
//  \return None
//*****************************************************************************
extern void subtractElement( float* inputArray , size_t sizeOfArray, float toBeSubtracted); //verified
//*****************************************************************************
//! The function divides the given Elements to the float array.
//!
//! \param: The float array to which the element has to be divided.
//! \param: The size of the float Array.
//! \param: The value to be divided. The value has to be float. if the variable
//!             is of other type. Consider typecasting.
//!         For ex: divideElement(A,516,(float)5);
//  \return None
//*****************************************************************************
extern void divideElement(float* inputArray , size_t sizeOfArray, float tobeDivied);   //verified
//*****************************************************************************
//! The function multiplies the given Elements to the float array.
//!
//! \param: The float array to which the element has to be multplied.
//! \param: The size of the float
//! \param: The value to be multiplied. The value has to be float. if the variable
//!             is of other type. Consider typecasting.
//!         For ex: multiplyElement(A,516,(float)5);
//  \return None
//*****************************************************************************
extern void multiplyElement(float* inputArray, size_t sizeOfArray, float toBeMultiplied);
//*****************************************************************************
//! The function takes the sum of two arrays and puts into other array
//!
//! \param: The first and the second parameters are the arrays.
//! \param: The size of the float array.
//! \param: The destination array.
//  \return None
//*****************************************************************************
extern void arraysum(const float* sourceArray1, const float* sourceArray2 ,
                const size_t sizeOfArray, float* destionationArray);           //verified
//*****************************************************************************
//! The function takes the difference of two arrays and puts into other array
//!
//! \param: The first and the second parameters are the arrays.
//! \param: The size of the float array.
//! <br> The destination array is the first array itself.
//  \return None
//*****************************************************************************
extern void arraySubtract(float* sourceArray1,float* sourceArray2,size_t sizeOfArray);         //verified
//*****************************************************************************
//! The function takes the multplication of two arrays and puts into other array
//!
//! \param: The first and the second parameters are the arrays.
//! \param: The size of the float array.
//! <br> The destination array is the first array itself.
//  \return None
//*****************************************************************************
extern void arrayMultiply(float* sourceArray1, float* sourceArray2, size_t sizeOfArray);       //verified
//*****************************************************************************
//! The function takes the absolute of the float Array
//!
//! \param: The first is the float arrays.
//! \param: The size of the Float array.
//! <br> The destination array is the first array itself.
//  \return None
//*****************************************************************************
extern void absf(float* sourceArray1, size_t sizeOfArray);
//*****************************************************************************
//! The function finds the maximum element of the given array.
//!
//! \param: The input array of which the maximum has to be found
//! \param: The size of the Float array.
//  \return The maximum value in the float array.
//*****************************************************************************
float findMax(const float* sourceArray1 , size_t sizeOfArray);         //verified
//*****************************************************************************
//! The function finds the minimum element of the given array.
//!
//! \param: The input array of which the minimum has to be found
//! \param: The size of the Float array.
//  \return The minimum value in the float array.
//*****************************************************************************
float findMin(const float* sourceArray1, size_t sizeOfArray);
//*****************************************************************************
//! The function finds the mean of the following float array.
//!
//! \param: Array of which the mean has to be found.
//! \param: The size of the given float array.
//
//  \return The mean of the given array.
//*****************************************************************************
extern float mean(const float* sourceArray1, const size_t sizeOfArray);            //verified
//*****************************************************************************
//! The function finds the mean of the following int array.
//!
//! \param: Array of which the mean has to be found.
//! \param: The size of the given float array.
//
//  \return The mean of the given array.
//*****************************************************************************
extern float meanInt(const int* sourceArray1, const size_t sizeOfArray);            //verified
//*****************************************************************************
//! The function upsamples the source Array by appending zeroes.
//!
//! \param: The source Array.
//! \param: The destionation Array.
//!    <br> The memory alloted to the destination array should be atleast
//!         upsampleFactor times the sourceArray.
//! \param: The factor by which the array has to be upsampled.
//! \param: The size of the given source array.
//  \return None
//*****************************************************************************
extern void upSample(const float* sourceArray1, float* destionationArray
          ,size_t upsampleFactor, size_t sizeOfArray);        //verified
//*****************************************************************************
//! The function downsamples the source Array by appending zeroes.
//!
//! \param: The source Array.
//! \param: The destionation Array.
//!    <br> The memory alloted to the sourceArray should be atleast
//!         downSamples times the destionation array.
//! \param: The factor by which the array has to be downsampled.
//! \param: The size of the given source array.
//  \return None
//*****************************************************************************
extern void downSample(const float* sourceArray1, float* destionationArray,
            size_t downSampleFactor, size_t sizeOfArray);      //verified
//*****************************************************************************
//! The function takes the vector dot product of the two source Arrays/
//!
//! \param: The sourceArrays of which the dot Product has to be found.
//!    <br> Both the array should be of some datatype and same size.
//  \return The dot product of the given array.
//*****************************************************************************
extern float dotProduct(const float* sourceArray1, const float* sourceArray2,
            size_t sizeOfArray );         //verified
//*****************************************************************************
//! The function reverses Elements by reversing the index values.
//!
//! \param: The source Array which should be of float datatype.
//!    <br> The source Array and the destination array are the same.
//! \param: The size of the source array.
//  \return None
//*****************************************************************************
extern void reverseArray(float* sourceArray, size_t sizeOfArray);
//*****************************************************************************
//! The function squares Elements by squaring the individual values.
//!
//! \param: The source Array which should be of float datatype.
//!    <br> The source Array and the destination array are the same.
//! \param: The size of the source array.
//  \return None
//*****************************************************************************
extern void squareArray(float* sourceArray, size_t sizeOfArray);
//*****************************************************************************
//! The function configures all the elements of the source Array to a fixed
//! value.
//!
//! \param: The sourceArray.
//!    <br> Can start changing the values of the array anywhere in the array.
//!    <br> Can stop changing the values of the array by using the last parameter.
//! \param: The value to be put inside the array.
//! \param: The number of the elements that have to be altered.
//  \return None
//*******************************************************d**********************
extern void createArray(float* sourceArray, const float initialValue, size_t sizeOfArray);
//*****************************************************************************
//! The function substitutes the value of an array by 'n' times.
//!
//! \param: The destination array.
//! \param: The source array which is substituted in the destination array.
//! \param: This indicate the starting index of the substitution.
//! \param: The number of times the substitution occurs.
//  \return None
//*****************************************************************************
extern void meanImputation(float* destionationArray, float* ValuesToBeSubstitued
                ,int* IntialIndex, size_t* noOfSubstituition);
//*****************************************************************************
//! The function is a moving average function of window size.

//! \param: The input of smoothing filter.
//! \param: The output of smoothing filter.
//! \param: The size of the given source Array to the filter.
//! \param: The window size of the moving average filter
//  \return None
//*****************************************************************************
extern void smoothing(float* sourceArray, float* destionationArray,
            size_t sizeOfArray , size_t windowSize);
//*****************************************************************************
//! The function copies the data from the source Array to the destination array.
//!
//! \param: The source and Destination Arrays.
//! \paran: The size of the Array.
//  \return None
//*****************************************************************************
extern void appendArray(float* destinationArray, float* sourceArray, size_t sizeOfArray);
//*****************************************************************************
//! The function finds the slope change from the sourceArray by comparing The
//! difference of neighbouring values.
//!
//! \param: The source Array.
//! \param: The destination Array which stores the positive slope as 1 and
//!         the negative slopes as 0.
//! \param: The size of the sourceArray.
//  \return None
//*****************************************************************************
extern void findSlopeChange(float* sourceArray, float* destinationArray, size_t sizeOfArray);
//*****************************************************************************
//! The function does the 30s check between two simultaneous contraction
//! indexes.
//! /param: The sourceArray
//! /param: The size of the source Array
//! /param: The minimum difference beween the Contraction indexes.
//! \return None
//*****************************************************************************
extern void timeCheck(int*, size_t , size_t);
//*****************************************************************************
//! The function does the amplitude check between the Rms interpolation array
//! and Thresholding interpolation values respectively.
//!
//! \param: The Rms and thresholding interpolation vectors.
//! \param: The final contraction values.
//! \param: The size of the interpolation vectors.
//!  <br> For a given pair of contraction indexes if the amplitude condition
//!       doesn't satisfy, the respective indexes are replaced by 0.
//  \return None
//*****************************************************************************
void amplitudeCheck(float* , float* , int* );

#endif
