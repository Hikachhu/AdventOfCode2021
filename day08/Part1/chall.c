#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 10000

int position(char *tab){
	int i=0;
	while(tab[i++]!=0);
	return i-1;
}

int main(){
	int pos=0,max=0;
	char listInput[15];
	FILE *fichier=fopen("Input/Day8.txt","r");
	while(fscanf(fichier,"%s", listInput)==1){
		if(pos>10&&(position(listInput)==2||position(listInput)==3||position(listInput)==4||position(listInput)==7)){max++;
		pos=(pos+1)%15;
	}
	printf("%d\n",max);
	fclose(fichier);
}