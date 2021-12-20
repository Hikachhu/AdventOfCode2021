#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 1000
int main(){
	int counter[size]={0},indexx=0,indexy=0,indexTab=0,current,sum1=0,sum2=0,total=0,end=0;
	char listInput[size],tabBingo[5][5][size];
	FILE *fichier=fopen("SourceDay4.txt","r");
	fscanf(fichier,"%s", listInput);
	
	while(fscanf(fichier,"%d", &current)==1){
		tabBingo[indexx][indexy][indexTab]=current;
		indexx=(indexx+1)%5;
		if(indexx==0)indexy=(indexy+1)%5;
		if(indexy==0&&indexx==0)indexTab++;
	}
	
	
	char *ligneSite = strtok(listInput, ",");
	while(ligneSite!=NULL){
		current=atoi(ligneSite);
		for(int i=0;i<indexTab;i++){
			for(int j=0;j<5;j++){
				for(int k=0;k<5;k++){
					if(tabBingo[k][j][i]==current&&end!=1){
						sum1=0;
						sum2=0;
						tabBingo[k][j][i]=0;
						for(int a=0;a<5;a++){
							sum1+=tabBingo[k][a][i];
							sum2+=tabBingo[a][j][i];
						}
						if(sum1==0||sum2==0){
							for(int y=0;y<5;y++){
								for(int z=0;z<5;z++){
									total+=tabBingo[y][z][i];
								}
							}
							printf("%d\n",total*current);
							end=1;
							break;
						}
					}
				}
			}
		}
		ligneSite = strtok(NULL, ",");
	}
	fclose(fichier);
}