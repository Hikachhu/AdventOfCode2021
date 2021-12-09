#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 1000

int main(){
	int i=0,x1I,x2I,y1I,y2I,listPos[size][size]={0},max=0,min=0,compt=0;
	char listInput[size],current1[50],current2[50];
	FILE *fichier=fopen("Source.txt","r");
	
	while(fscanf(fichier,"%s", listInput)==1){
	//	printf("%s\n",listInput);
		if(i==0)memcpy(current1,listInput,sizeof(listInput));
		else if(i==2){
			memcpy(current2,listInput,sizeof(listInput));
			
			char *x1 = strtok(current1, ",");
			char *y1 = strtok(NULL, ",");
			char *x2 = strtok(current2, ",");
			char *y2 = strtok(NULL, ",");
			x1I=atoi(x1);
			x2I=atoi(x2);
			y1I=atoi(y1);
			y2I=atoi(y2);
			if(x1I==x2I){
				min=y1I<y2I?y1I:y2I;
				max=y1I>y2I?y1I:y2I;
				for(int i=min;i<=max;i++){
					if(listPos[x1I][i]==0)listPos[x1I][i]++;
					else if(listPos[x1I][i]==1){
						compt++;
						listPos[x1I][i]++;
					}
				}
			}
			if(y1I==y2I){
				min=x1I<x2I?x1I:x2I;
				max=x1I>x2I?x1I:x2I;				
				for(int i=min;i<=max;i++){
					if(listPos[i][y1I]==0)listPos[i][y1I]++;
					else if(listPos[i][y1I]==1){
						compt++;
						listPos[i][y1I]++;
					}
				}
			}
			
		}
		i=(i+1)%3;
		
	}
	printf("%d\n",compt);
	fclose(fichier);
}