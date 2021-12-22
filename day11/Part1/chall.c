#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 10000
#define RED "\033[0;31m"
#define NC "\033[0m"

void display(int listInput[10][10]){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(listInput[i][j]!=0)printf("%d ",listInput[i][j]);
			else printf("%s%d %s",RED,listInput[i][j],NC);
		}
		printf("\n");
	}
	printf("\n\n");
}

void inc(int listInput[10][10],int i,int j){
	if(listInput[i][j]==10){
	//	printf("-DEBUT-%d %d %d\n",i,j,listInput[i][j]);
		for(int a=-1;a<2;a++){
			for(int b=-1;b<2;b++){
				if(i+a<10&&i+a>=0&&j+b>=0&&j+b<10&&!(a==0&b==0)){
					listInput[i+a][j+b]++;
					if(listInput[i+a][j+b]==10){
		//				printf("PASSAGE\n");
						inc(listInput,i+a,j+b);
					}
		//			printf("__%d %d %d\n",i+a,j+b,listInput[i+a][j+b]);
				}
			}
		}
	//	printf("-FIN-%d %d %d\n",i,j,listInput[i][j]);
	}
}

int main(){
	int a=0,i=0,j=0,listInput[10][10],total=0;
	char lu;
	FILE *fichier=fopen("Input/Day11.txt","r");
	while(fscanf(fichier,"%c", &lu)==1){
		if(lu>='0'&&lu<='9'){
			listInput[j][i]=lu-'0';
			j=i==9?j+1:j;
			i=(i+1)%10;
		}
	}
	display(listInput);
	for(a=0;a<100;a++){		
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				listInput[i][j]++;
				inc(listInput,i,j);
			}
		}
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				if(listInput[i][j]>=10){
					listInput[i][j]=0;
					total++;
				}
			}
		}
	//	display(listInput);
	}
	printf("%d\n",total);
	return 0;
}