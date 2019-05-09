#include <stdio.h>

int main(void) {
    int  noTestcases;
    scanf("%d",&noTestcases);
    int totalMoves[noTestcases];
    
    for(int i = 0; i < noTestcases; i++){
        int R,C,K;
        int minR = 1;
        int maxR = 8; 
        int minC = 1; 
        int maxC = 8; 
        int noOfColumnMoves = 1; 
        
        scanf("%d %d %d",&R,&C,&K);
        
        if(R-K > 0){
            minR = R - K; 
        } 
        if(R+K <= 8){
            maxR = R + K;
        }
        if(C-K >0){
            minC = C - K;
        }
        if(C+K <= 8){
            maxC = C + K;
        }
        totalMoves[i] = (maxR - minR + 1) *(maxC - minC + 1);
    }
	for(int i = 0; i < noTestcases; i++){
        printf("%d\n",totalMoves[i]);
    }
	// your code goes here
	return 0;
}

