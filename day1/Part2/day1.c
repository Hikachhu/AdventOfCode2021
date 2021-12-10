#include <stdio.h>

int main(){
	int currentNumber=0,oldNumber=0,sum=0,hist[3]={0},lu=0;
	FILE *fichier=fopen("SourceDay1.txt","r");
	fscanf(fichier, "%d", &hist[0]);
	fscanf(fichier, "%d", &hist[1]);
	fscanf(fichier, "%d", &hist[2]);
	while(fscanf(fichier, "%d", &lu)==1){
		oldNumber=hist[0]+hist[1]+hist[2];
		hist[0]=hist[1];
		hist[1]=hist[2];
		hist[2]=lu;
		currentNumber=hist[0]+hist[1]+hist[2];
		if(currentNumber>oldNumber)sum++;
		oldNumber=currentNumber;
	}	
	printf("%d\n",sum);
	fclose(fichier);
}