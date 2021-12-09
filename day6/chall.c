#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 10000

int main(){
	int *lecture=(int*)malloc(1000*sizeof(int)),i=0;
	char listInput[size];
	FILE *fichier=fopen("Source.txt","r");
	fscanf(fichier,"%s", listInput);
	char *lu = strtok(listInput, ",");
	while(lu!=NULL){
		lecture[i]=atoi(lu);
		lu = strtok(NULL, ",");
		if(lu!=NULL)lecture=(int *) realloc( lecture, (sizeof(lecture)+10*i) * sizeof(int) );
		i++;
	}
	for(int a=0;a<80;a++){
		for(int j=0;j<i;j++){
		}
		for(int j=0;j<i;j++){
			if(lecture[j]==0){
				lecture[j]=7;
				lecture=(int*)realloc(lecture,(i+1)*sizeof(int));
				lecture[i]=9;
				i++;
			}
			lecture[j]--;
		}
	}
	printf("%d\n",i);
	fclose(fichier);
}