#include <stdio.h>
#include <string.h>
#include <math.h>
#define size 12
int main(){
	int counter[size]={0},number1=0,number2=0;
	char direction[size];
	FILE *fichier=fopen("Input/Day3.txt","r");
	
	while(fscanf(fichier,"%s", direction)==1){
		for(int i=0;i<size;i++){	
			counter[i]=(direction[i]=='1')?counter[i]+1:counter[i]-1; 
		}
	}	
	for(int i=0;i<size;i++){
		if(counter[i]>0)number1+=pow(2,size-1-i);
		else number2+=pow(2,size-1-i);
	}
	printf("%d\n",number1*number2);
	fclose(fichier);
}