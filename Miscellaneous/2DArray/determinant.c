#include<stdio.h>
#include<stdlib.h>

#define	A[i][j] 				*(*(A+i)+ j)

void createArray(int*** a, int rows, int cols){
    *a = malloc(rows*sizeof(int));
    for(int i = 0; i < rows; ++i){
        (*a)[i] = malloc(cols*sizeof(int));
    }
}

void free(int*** a, int rows, int cols){
	for(int i = 0; i < cols; ++i){
		free((*a)[i]);
	}
	free((*a));
}

int determinant(int** inputMatrix, size_t size){
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
