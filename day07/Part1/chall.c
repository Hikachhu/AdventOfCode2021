#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 10000

void swap(int *p,int *q) {
   int t;
   t=*p; 
   *p=*q; 
   *q=t;
}

void sort(int a[],int n) { 
   int i,j,temp;
   for(i = 0;i < n-1;i++) {
      for(j = 0;j < n-i-1;j++) {
         if(a[j] > a[j+1])
            swap(&a[j],&a[j+1]);
      }
   }
}

int main(){
	int *lecture=(int*)malloc(10*sizeof(int)),i=0,median=0,tailleMedian=0,total=0;
	char listInput[size];
	FILE *fichier=fopen("Input/Day7.txt","r");
	fscanf(fichier,"%s", listInput);
	char *lu = strtok(listInput, ",");
	while(lu!=NULL){
		lecture[i]=atoi(lu);
		lu = strtok(NULL, ",");
		i++;
		if(lu!=NULL)lecture=(int *) realloc( lecture, (2*i) * sizeof(int) );
	}
	sort(lecture,i);
	tailleMedian = (i+1) / 2 - 1; 
	median=lecture[tailleMedian];
	for(int a=0;a<i;a++){
		total+=abs(lecture[a]-median);
	}
	
	printf("%d\n",total);
	fclose(fichier);
}