#include<stdio.h> 
#include<conio.h>
#include<stdlib.h>


int* Esieve(int upperLimit){
    static createArr[upperLimit]; 
    int* primeArray; 
    for(int i = 2; i*i <= upperLimit; i++){
        if(createArr[i] == 0){
            for(int j = i*i; j <= upperLimit; ){
                createArr[j] = 1; 
                j += i; 
            }
        }
    }
	int j = 0; 
    for(int i = 0; i < upperLimit; i++){
        if(createArr[i] == 1){
            primeArray[j] = i;
            j++;
        }
    }
    return primeArray; 
}

int main(void){
    int* p; 
	int upperLimit; 
    scanf("%d",&upperLimit);
    p = Esieve(upperLimit);
	for(int i = 0; i < sizeof(p); i++){
		printf("%d", *(p+i));
	}
}