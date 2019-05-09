#include <stdio.h>
int checkStatus(int A, int B, int N, int X){
    int ans;
    for(int i = 0; i < N; i++){
        if(X[0][i] == A+1){
            if((X[1][i] == B - 1 )||(X[1][i] == B + 1 )){
                ans = i; 
            }
        }
    }
    return ans; 
}

int main(void) {
	// your code goes here
	int noTestCase
	scanf("%d",&noTestCases);
	int ans[noTestCases];
	for(int i = 0; i < noTestCases; i++){
	    int N; 
	    scanf("%d", &N);
	    int X[2][N];
	    int A,B; 
	    for(int j = 0; j < N;j++){
	        scanf("%d",&X[0][j]);
	        scanf("%d",&X[1][j]);
	    }
	    scanf("%d",&A);
	    scanf("%d",&B);
		
		for(int j = 0; j < N; j++){
			switch(X[0][N]){
				case A-1:
			}	
		}//for (int j = A-1; j <= A+1; j++){
	        for(int k = B - 1; j <= B + 1; k++){
	            if( j > 0 && j < 8 ){
	                ans[i] = checkStatus(j,k,N,X); 
	            }
	        }
	    }
	}
	for( int i = 0; i < noTestCases; i++){
	    if(ans[i] > 0){
	        printf("YES\n");
	    }
	    else{
	        printf("NO\n");
	    }
	}
	return 0;
}

/*
Knight can only move cross: so X[i-1][j+1],X[i+1][j+1],X[i-1][j-1],X[i+1][j-1]; 
King can move any direction: K[i][j];
    The places he can move is : K[i-1][j]; K[i+1][j]; K[i][j]; K[i][j-1];
                                K[i][j+1]; K[i-1][j+1],K[i+1][j+1];K[i-1][j-1];K[i+1][j-1];*/