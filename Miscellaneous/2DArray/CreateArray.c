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
