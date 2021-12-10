#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 10000

typedef struct Element Element;
typedef struct Pile Pile;

struct Element{
    int nombre;
    Element *suivant;
};

struct Pile{
    Element *premier;
};

Pile *initialiser(){
    Pile *pile = malloc(sizeof(*pile));
    pile->premier = NULL;
}

void empiler(Pile *pile, int nvNombre){
    Element *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)    {
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nvNombre;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}

int depiler(Pile *pile){
    if (pile == NULL)    {
        exit(EXIT_FAILURE);
    }

    int nombreDepile = 0;
    Element *elementDepile = pile->premier;

    if (pile != NULL && pile->premier != NULL)    {
        nombreDepile = elementDepile->nombre;
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }

    return nombreDepile;
}

int main(){
	int a=0,len[4]={0},limited=0,sum=0,recup=0;
	char lu,listInput[1000][1000];
	Pile *maPile = initialiser();
	FILE *fichier=fopen("Source.txt","r");
	while(fscanf(fichier,"%c", &lu)==1){
		if(limited==0){
			printf("%c",lu);
			switch(lu){
				case '{':
					empiler(maPile,1197);
					break;
				case '}':
					recup=depiler(maPile);
					if(recup!=1197){
						sum+=1197;
						limited=1;
					}
					break;
				case '[':
					empiler(maPile,57);
					break;
				case ']':
					recup=depiler(maPile);
					if(recup!=57){
						sum+=57;
						limited=1;
					}
					break;
				case '(':
					empiler(maPile,3);
					break;
				case ')':
					recup=depiler(maPile);
					if(recup!=3){
						sum+=3;
						limited=1;
					}
					break;
				case '<':
					empiler(maPile,25137);
					break;
				case '>':
					recup=depiler(maPile);
					if(recup!=25137){
						sum+=25137;
						limited=1;
					}
					break;
			}
		}
		if(lu==10||lu==13){
			limited=0;
			printf("\n");
		}
	}
	printf("%d\n",sum);
	fclose(fichier);
}