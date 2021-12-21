#include <stdio.h>

int main(){
	int currentNumber=0,oldNumber=0,sum=0;
	FILE *fichier=fopen("Input/Day1.txt","r");
	fscanf(fichier, "%d", &oldNumber);
	while(fscanf(fichier, "%d", &currentNumber)==1){
		if(currentNumber>oldNumber)sum++;
		oldNumber=currentNumber;
	}	
	printf("%d\n",sum);
	fclose(fichier);
}