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
	int x=0,y=0,max=0,a=0,now=0,total=0,voisins=0;;
	char lu,listInput[1000][1000];
	FILE *fichier=fopen("Input/Day9.txt","r");
	while(fscanf(fichier,"%c", &lu)==1){
		a++;
		if(lu==10||lu==13){
			max=max>x?max:x;
			y++;
			x=0;
		}else{
			listInput[x][y]=lu;
			x++;
		}
	}
	for(int i=0;i<=y;i+=2){
		for(int j=0;j<max;j++){
		}
	}
	for(int i=0;i<=y;i+=2){
		for(int j=0;j<max;j++){
	/*haut*/	if(i>0){
					voisins++;
					if(listInput[j][i-2]>listInput[j][i]){
						now++;
					}
				}
	/*bas*/		if(i<y){
					voisins++;
					if(listInput[j][i+2]>listInput[j][i]){
						now++;
					}
				}
	/*droite*/	if(j+1<max){
					voisins++;
					if(listInput[j+1][i]>listInput[j][i]){
						now++;
					}
				}
	/*gauche*/	if(j>0){
					voisins++;
					if(listInput[j-1][i]>listInput[j][i]){
						now++;
					}
				}
			if(now==voisins){
				total+=listInput[j][i]-'0'+1;
			}
			now=0;
			voisins=0;
		}
	}
	printf("%d\n",total);
	fclose(fichier);
}