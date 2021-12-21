#include <stdio.h>
#include <string.h>

int main(){
	int forward=0,depth=0,len=0;
	char *direction;
	FILE *fichier=fopen("Input/Day2.txt","r");
	
	while(fscanf(fichier,"%s", direction)==1){
		fscanf(fichier,"%d", &len);
		if(strcmp(direction,"forward")==0) {printf("forward %d",len);forward+=len;}
		else if (strcmp(direction,"down")==0){ printf("down %d",len);depth+=len;}
		else if (strcmp(direction,"up")==0){printf("up %d",len); depth-=len;}
		printf("\n");
	}	
	printf("%d\n",depth);
	printf("%d\n",forward);
	printf("%d\n",forward*depth);
	fclose(fichier);
}