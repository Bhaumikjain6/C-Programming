#include "2dArrayUitls.h"

void createArray(int*** a , int rows , int cols){
    a = (int**)malloc(rows*sizeof(int*));
    for(int i = 0; i < cols; ++i){
      a[i] = (int*)malloc(cols*sizeof(int));
    }
    //*a = calloc(col, rows*sizeof(int));
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
        a[i][j] = 0;
      }
    }
}

void freeArray(int*** a, int rows, int cols){
  for( int i = 0; i < cols; ++i){
    free(a[i]);
  }
  free(a);
}

void print(int** , int rows, int cols){
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      printf("a[%d][%d] : %d\n", i, j, a[i][j]);
    }
  }
}

float determinant(int** matrix, int rows, int cols){
    int sum = 0;
    static int x ;
    x++;

    if(rows != cols){
      printf("Given matrix is not a square matrix");
      return 0.0;
    }
    for(int i = 0; i < rows; ++i){
      for(int j = 0; j < cols; ++j){
      sum += a[i][j] * (determinant(Minor(matrix, row, col),rows-1,cols-1);
      }
    }
}

int** Minor(int** matrix , int row, int col){
    createArray(int** matrix, int row, int col);
    for(int i = 0; i < row; ++i){
      for(int j = 0; j < col; ++j){

      }
    }
}

int** transpose(int** inputMatrix ,int rows , int cols){
    int** outputMatrix = NULL;
    createArray(&outputMatrix[0], cols, rows);
    for(int i = 0; i < cols; ++i){
      for(int j = 0; j < rows; ++j){
        outputMatrix[i][j] = inputMatrix[j][i];
      }
    }
    return outputMatrix;
}

int** matrixMul(int** Matrix1, int** Matrix2, int rows1, int cols1, int rows2, int cols2){
    int** outputMatrix = NULL;
    if((rows2 != cols1)){
      printf("The dimensions of Matrix are not proper");
      return 0;
    }
    createArray(&outputMatrix[0],rows1,cols2);
    for(int i = 0; i < rows1; ++i){
      for(int j = 0; j < cols2; ++j){
        for(int l = 0; l < cols1; ++l){
          sum += Matrix1[j][l] * Matrix2[l][j];
        }
        outputMatrix[i][j] = sum;
        sum = 0;
      }
    }
    return outputMatrix;
}
