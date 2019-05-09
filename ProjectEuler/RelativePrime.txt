#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b){
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
}

float relativePrime(float a){
    int noOfRelativePrimes = 0;     
    for(float i = 1; i < a; i++){
        if((float)gcd(a,i) == 1.0){
            noOfRelativePrimes++; 
        }
    }
    return noOfRelativePrimes; 
}
int main(void) {
	// your code goes here
	float maxRelativeRatio = 0; 
	float currentRelativeRatio = 0; 
	for(float i = 2; i <= 1000000; i++){
	    currentRelativeRatio = (i /relativePrime(i));
	    if(currentRelativeRatio > maxRelativeRatio){
	       maxRelativeRatio = currentRelativeRatio;    
	    }
	}
	printf("%f",maxRelativeRatio); 
	return 0;
}

