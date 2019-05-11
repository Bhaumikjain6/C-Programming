#include "2dArrayUitls.h"

void createArray(int*** a , int rows , int cols){
    (*a) = (int**) malloc( rows * sizeof(int*));
    for(int i = 0; i < rows; ++i){
        ((*a)[i]) = (int*) malloc(cols * sizeof(int));
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

int determinant(int** matrix, int rows, int cols){
  	int det;
  	int mul =  -1;
  	int **minor = NULL;

  	if(size == 1){
  		det = inputMatrix[0][0];
  		return det;
  	}

  	else if(size == 2){
  		det = (a[0][0]*a[1][1]) - (a[1][0]*a[0][1]);
  		return det;
  	}

  	else if{
  		for(int i = 0 ; i < size; ++i){
  			createArray(&minor,size - 1,size - 1);
  			int r1 = 0 ;
  			int c1 = 0;
  			for(int j = 1; j < size;++j){
  				c1 = 0;
  				for(int k = 0; k < size; ++k){
  					if(k == i){
  						continue;
  					}
  					minor[r1][c1] = inputMatrix[j][k];
  					r1++;
  				}
  			}
  			det = det + mul * inputMatrix[0][i] * determinant(&minor[0][0],size - 1);
  			mul *= mul;
  			free(&minor, size-1, size-1);
  		}
  	}
  	return det;
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
