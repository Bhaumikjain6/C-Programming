#include <stdio.h>

int main(void) {
    int noTestCases; 
    scanf("%d", &noTestCases);
    int final_ans[noTestCases];
    for(int i = 0; i < noTestCases; i++){
        int L,R; 
        int temp; 
        scanf("%d %d", &L, &R);
        final_ans[i] = R;
        temp = R - 1; 
        while(temp >= L){
            if(final_ans[i] == temp){
                final_ans[i] = 0; 
            }
            else{
                final_ans[i] = final_ans[i] ^ temp; 
                temp--;
            } 
        }
    }
	for(int i = 0; i < noTestCases; i++){
	    if(final_ans[i] % 2 == 0){
	        printf("EVEN\n");
	    }
	    else{
	        printf("ODD\n");
	    }
	}
	// your code goes here
}

