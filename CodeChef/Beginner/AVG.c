#include <stdio.h>

int main(void) {
    int noTestcase;
    int N,K,V; 
    int sumOfElements = 0;
    int allSum; 
    int alldif; 
    
    // No of Testcases
    scanf("%d",&noTestcase);
    int missingElement[noTestcase];
    for(int j = 0; j <noTestcase; j++){
    	// Value of N,K,V respectively 
    	scanf("%d %d %d", &N, &K, &V);
    	
    	int Nelements[N]; 
    	sumOfElements = 0; 
    	for(int i = 0; i < N; i++){
    	    scanf("%d", &Nelements[i]);
    	    sumOfElements += Nelements[i];
    	}
    	allSum = ((N+K)*V);     
    	alldif = allSum - sumOfElements; 
    
    	if((alldif > 0)&& (alldif % K == 0) ){
	        missingElement[j] = (alldif)/K ;
    	}
    	else{
    	    missingElement[j] = -1; 
    	}
    }
    for(int j =0; j < noTestcase;j++){
        printf("%d\n",missingElement[j]);
    }
	return 0;
}

