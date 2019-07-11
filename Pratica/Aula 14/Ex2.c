#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct portaavioes{
	char serie[10];
	char nome[30];
	int ano;
	char classe[30];
	int lat;
	int lon;
}NAVIO;

void tobin(){
	char entrada[100], saida[50], aux[50];
	FILE *ent, *sai;
	NAVIO nav;

	strcpy(saida, entrada);
	strcat(entrada, ".txt");
	strcat(saida, ".bin");

	if(!(ent = fopen(entrada, "r"))){
		printf("Erro na abertura do arquivo %s\n", entrada);
		exit(1);
	}

	sai = fopen(saida, "w");

	while(!feof(ent)){
		fgets(entrada, 100, ent)
		strcmp(nav.serie, strtok(entrda, "$"));
		strcmp(nav.nome, strtok(NULL, "$"));
		strcmp(nav.ano, atoi(strtok(NULL, "$")));
		strcmp(nav.classe, strtok(NULL, "$"));
		strcmp(nav.lat, atoi(strtok(NULL, "$")));
		strcmp(nav.lon, atoi(strtok(NULL, "$")));
		fwrite(&nav, sizeof(NAVIO), 1, sai);
	}

}


int main(){

	tobin()
	return 0;
}