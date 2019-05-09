#include <stdio.h>

int findSoldier(int *a,int *d, int N){
    int maxDef = -1;
    
    for(size_t i = 0; i < N; ++i){
        if(i == 0){
			if(d[i] > (a[1] + a[N-1])){
				maxDef = d[i];
			}
		}
		else if(i == N-1){
			if(d[i] > (a[0] + a[N-2])){
				maxDef = d[i];
			}
		}
		else if(i > 0 && i < N - 1){
			if(d[i] > (a[i-1] + a[i+1])){
				maxDef = d[i];
			}
		}
    }
    return maxDef; 
}

int main(void) {
	// your code goes here
    int N, noTestcase;
    // give number of Testcases 
    scanf("%d", &noTestcase);
    int result[noTestcase];
	
    for(size_t j = 0; j < noTestcase; j++){
        //printf("Enter the number of Soliders \n");
        scanf("%d", &N); 
        int a[N],d[N];
        
        //printf("Enter the attack values of solider \n");
        for(size_t i = 0; i < N; ++i){
            //printf("Attack of %d solider\n", i+1);
            scanf("%d", &a[i]);
        }
    	for(size_t i = 0; i < N; ++i){
    	    //printf("Defence of %d solider\n", i+1);
    	    scanf("%d", &d[i]);
    	}		
		int maxDef = -1; 
	    for(size_t i = 0; i < N; ++i){
			if(i == 0){
				if(d[i] > (a[1] + a[N-1])){
					maxDef = d[i];
				}
			}
			else if(i == N-1){
				if(d[i] > (a[0] + a[N-2])){
					maxDef = d[i];
				}
			}
			else if(i > 0 && i < N - 1){
				if(d[i] > (a[i-1] + a[i+1])){
					maxDef = d[i];
				}
			}
		}
		result[j] = maxDef; 
	}
	for( size_t j = 0; j < noTestcase; j++){
	    printf("%d\n",result[j]);
	}
	return 0;
}

