#include<stdio.h>
#include<stdlib.h>

int main(void){
	int sum = 0; 
	
	for(int i = 0; i < 10; i++){
		if(i % 3 == 0){
			sum += i; 
		}
		else if( i % 5 == 0){
			sum += i; 
		}
	}
	printf("%d",sum); 
}
