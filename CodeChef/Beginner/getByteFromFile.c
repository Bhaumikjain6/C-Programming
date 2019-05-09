#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdint.h>

char ping[6000];

int main(void){
	FILE *fptr;
	FILE *ptr2; 
	puts("AS"); 
	/**fptr = fopen("C:\\Users\\Lenovo\\Desktop\\ex.txt","r");
	for(int i = 0; i < 6000; i++){
		fread(ping + i,1,1,fptr);
	}
	fclose(fptr); 
	printf("W"); 
	ptr2 = fopen("C:\\Users\\Lenovo\\Desktop\\pro.txt","w");
	fwrite(ping,sizeof(char), sizeof(ping),ptr2);
	fclose(ptr2);*/	
	//printf("%c",ping[26]); 
}
