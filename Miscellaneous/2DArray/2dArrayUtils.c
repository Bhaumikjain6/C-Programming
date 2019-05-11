#include "2dArrayUitls.h"

void createArray(int*** a , int rows , int cols){
    (*a) = (int**) malloc( rows * sizeof(int*));
    for(int i = 0; i < rows; ++i){
        ((*a)[i]) = (int*) malloc(cols * sizeof(int));
    }
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
        a[i][j] = 0;
      }
    }
}

void freeArray(int*** a, int rows, int cols){
  for( int i = 0; i < cols; ++i){
    free((*a)[i]);
  }
  free(*a);
}

void print(int** , int rows, int cols){
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      printf("a[%d][%d] : %d\n", i, j, a[i][j]);
    }
  }
}

int determinant(int** matrix, int size){
  	int det;
  	int **minor = NULL;

  	if(size == 1){
  		det = matrix[0][0];
  		return det;
  	}

  	else if(size == 2){
  		det = (matrix[0][0]*matrix[1][1]) - (matrix[1][0]*matrix[0][1]);
  		return det;
  	}

  	else{
      det = 0;
  		for(int i = 0 ; i < size; ++i){
  			createArray(&minor,size - 1,size - 1);
  			int c1 = 0;
  			for(int j = 1; j < size;++j){
  				c1 = 0;
  				for(int k = 0; k < size; ++k){
  					if(k == i){
  						continue;
  					}
  					minor[j - 1][c1] = matrix[j][k];
  					c1++;
  				}
  			}
  			det += pow(-1.0,(float)i) * matrix[0][i] * determinant(minor,size - 1);
  			freeArray(&minor, size-1, size-1);
  		}
  	}
  	return det;
}

void transpose(int** inputMatrix , int** outputMatrix, int rows , int cols){
    for(int i = 0; i < cols; ++i){
      for(int j = 0; j < rows; ++j){
        outputMatrix[i][j] = inputMatrix[j][i];
      }
    }
}

int** matrixMul(int** Matrix1, int** Matrix2, int rows1, int cols1, int cols2){
    int sum = 0;
    int** outputMatrix = NULL;
    if((rows2 != cols1)){
      printf("The dimensions of Matrix are not proper");
      return 0;
    }
    createArray(&outputMatrix,rows1,cols2);
    for(int i = 0; i < rows1; ++i){
      for(int j = 0; j < cols2; ++j){
        for(int l = 0; l < cols1; ++l){
            sum += Matrix1[i][l] * Matrix2[l][j];
          //printf("%d ",Matrix1[j][l] * Matrix2[l][j]);
        }
        outputMatrix[i][j] = sum;
        sum = 0;
      }
    }
    return outputMatrix;
}

void addToMatrix(int** inputMatrix , int rows ,int cols , int value) {
    for(int i = 0; i < rows; ++i){
      for(int j = 0; j < cols; ++j){
        inputMatrix[i][j] += value;
      }
    }
}

void subtractFromMatrix(int** inputMatrix , int rows, int cols, int value){
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      inputMatrix[i][j] -= value;
    }
  }
}

void divideFromMatrix(int** inputMatrix, int rows, int cols, int value){
  if( value != 0 ){
    for(int i = 0; i < rows; ++i){
      for(int j = 0; j < cols; ++j){
        inputMatrix[i][j] /= value;
      }
    }
  }
}

void multiplyToMatrix (int** inputMatrix, int rows, int cols, int value){
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      inputMatrix *= value;
    }
  }
}

int** matrixInverse(int** inputMatrix , size_t size){
    int det = 0 ;
    int** minor = NULL;
    int** outputMatrix = NULL;

    createArray(&outputMatrix,size,size);
    if(intputMatrix[0][0] != 1){
      divideFromMatrix(inputMatrix,size,size,inputMatrix[0][0]);
    }
    
    det = determinant(inputMatrix , size);
}
