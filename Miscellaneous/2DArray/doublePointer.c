#include<stdio.h>
#include<stdlib.h> 

#define ROWS		5
#define COLS		4

int main(void){
	int **p; 
	p = (int **)malloc(sizeof(int*) * ROWS); 
	for(int i = 0; i < ROWS; i++){
		p[i] = (int *) malloc(sizeof(int) * COLS);		
	}
	
	for(int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
			p[i][j] = i+j; 
		}
	}
	printf("%d",p[2][3]); 
	//puts((char)p[2][3]); 
}