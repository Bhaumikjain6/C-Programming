#include<matrixPadding.h>
#define LEN(arr)            ((int)(sizeof(arr)/ sizeof(arr[0])))

static int rowsInput,columnsInput,rowskernel,columnskernel;
static int rowsOutput, columnsOutput;

int matrixPadding(int* inputMatrix, int* kernelMatrix, int* OutputMatrix, int* sizeMatrix, char paddingType){
    rowsInput = sizeMatrix[0];
    columnsInput = sizeMatrix[1];
    rowskernel = sizeMatrix[2];
    columnskernel = sizeMatrix[3];
    rowsOutput = sizeMatrix[4];
    columnsOutput = sizeMatrix[5];

    if((rowsOutput != (rowsInput + rowskernel -1)) ||
        (columnsOutput != (columnsInput + columnskernel - 1))){
          return -1;
    }

    switch(paddingType):{
      case('Z'):      zeroPadding(inputMatrix,kernelMatrix,OutputMatrix);
                      break;
      case('P'):      periodicPadding(inputMatrix, OutputMatrix, kernelMatrix);
                      break;
      case('S'):      symmetricPadding();
                      break;
      default:        break;
    }
}

void zeroPadding(int inputMatrix, int kernelMatrix, int OutputMatrix){
    static int paddedRows, paddedColumns;
    static int index;

    paddedRows = (rowsOutput - 1) ;
    paddedColumns = (columnsOutput - 1);

    for(int i = 0; i < rowsOutput; i++){
      for(int j = 0; j < columnsOutput; j++){
        if( (i < paddedRows) || (i > rowsOutput - paddedRows)){
          if((j < paddedColumns) || (j > columnsOutput - paddedColumns)){
            OutputMatrix[i+j] = 0;
          }
          else{
            OutputMatrix[i+j] = inputMatrix[index+1];
            index++; 
          }
        }
      }
    }
}

void periodicPadding(int inputMatrix,int kernelMatrix, int OutputMatrix){
  static int paddedRows, paddedColumns;
  static int index;

  paddedRows = (rowsOuput - 1);
  paddedColumns = (columnsOutput - 1);

  for(int i = 0; i < rowsOuput; i++){
    for(int j = 0; j < columnsOutput; j++){

    }
  }
}
