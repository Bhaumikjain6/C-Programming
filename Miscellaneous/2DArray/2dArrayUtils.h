/*
  This file contains functions which can be used to create 2 array using double
  pointers.
  The arugments to the create and free array functions has to be a double pointer.
  for eg:
  int** convolutedMatrix = NULL;
  createArray(convolutedMatrix,2,4);
  freeArray(convolutedMatrix,2,4);

  File author : Bhaumik Jain
  email : bhaumikjain6@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>

void createArray(int*** , int ,int);    //done and verified
void freeArray(int*** , int, int);      //done and verified
void addElements(int** , int , int);    // done and verified
void print(int** , int , int);          //done and verified
void transpose(int** , int** ,int ,int );       //done and verified
int** matrixMul(int** , int**, int , int , int);           //done and verified
void convolution(int** ,int** , int , int);     //done
int determinant(int** , int , int);     // done and verified
void inverse(int** , int** , int , int);
void eigenvalue();
void eigenvector();
void linearEquation();
void principalSubMatrix();
void padding();
