#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 1000

void displayMatrix(int listPos[size][size]){
	printf("___________________\n");
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(listPos[j][i]!=0)printf("%d ",listPos[j][i]);
			else printf(". ");
		}
		printf("\n");
	}
	printf("___________________\n");
	
}

int main(){
	int a=0,x1I,x2I,y1I,y2I,listPos[size][size]={0},maxX=0,minX=0,maxY=0,minY=0,compt=0;
	char listInput[size],current1[50],current2[50];
	FILE *fichier=fopen("Source.txt","r");
	
	while(fscanf(fichier,"%s", listInput)==1){
	//	printf("%s\n",listInput);
		if(a==0)memcpy(current1,listInput,sizeof(listInput));
		else if(a==2){
			memcpy(current2,listInput,sizeof(listInput));
			
			char *x1 = strtok(current1, ",");
			char *y1 = strtok(NULL, ",");
			char *x2 = strtok(current2, ",");
			char *y2 = strtok(NULL, ",");
			x1I=atoi(x1);
			x2I=atoi(x2);
			y1I=atoi(y1);
			y2I=atoi(y2);
			
			minY=y1I<y2I?y1I:y2I;
			maxY=y1I>y2I?y1I:y2I;
			minX=x1I<x2I?x1I:x2I;
			maxX=x1I>x2I?x1I:x2I;
			printf("X:%d->%d Y:%d->%d\n",maxX,minX,maxY,minY);
			if(x1I==x2I){
				for(int i=minY;i<=maxY;i++){
					if(listPos[x1I][i]==0)listPos[x1I][i]++;
					else if(listPos[x1I][i]==1){
						compt++;
						listPos[x1I][i]++;
					}
				}
			}
			else if(y1I==y2I){
				for(int i=minX;i<=maxX;i++){
					if(listPos[i][y1I]==0)listPos[i][y1I]++;
					else if(listPos[i][y1I]==1){
						compt++;
						listPos[i][y1I]++;
					}
				}
			}
			else{
				for(int i=0;i<=maxX-minX;i++){
					if(listPos[minX+i][minY+i]==0)listPos[minX+i][minY+i]++;
					else if(listPos[minX+i][minY+i]==1){
						compt++;
						listPos[minX+i][minY+i]++;
					}
				}
			}
			displayMatrix(listPos);
		}
		a=(a+1)%3;
		
	}
	
	printf("%d\n",compt);
	fclose(fichier);
}