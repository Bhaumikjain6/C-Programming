#include<stdio.h>

int main(void)
{
    char timeStampLSB = 97; 
    char timeStampMSB = 97; 
	int i = 2;
    while(i--){
        timeStampLSB++;
        if(timeStampLSB > 255){
            timeStampMSB++; 
            timeStampLSB = 0; 
            if(timeStampMSB > 255){
                timeStampMSB = 0; 
            }
		}
		printf("%c", timeStampLSB);     
		if(timeStampMSB == 65){
            if(timeStampLSB == 65){
                printf("%c %c", timeStampLSB, timeStampMSB);
            }
        }
    }
}
