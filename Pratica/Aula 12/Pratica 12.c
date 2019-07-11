#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "le_texto.h"

#define TAM 100

typedef struct{
	char modelo[TAM];
	char marca[TAM];
	float pot;
}CARRO;

void criar_arq(char arquivo[]){
	if(fopen(arquivo, "wb")==NULL){
		printf("Erro ao criar o arquivo!\n");
		system("pause");
		exit(1);
	}
	printf("\nArquivo criado!\n");
}

void listar_car(char arquivo[]){
	FILE *arq;
	CARRO aux;
	int read = 0;

	arq = fopen(arquivo, "rb");

	if(arq==NULL){
		printf("Erro ao abrir o arquivo!\n\n");
		system("pause");
		exit(1);
	}

	while(fread(&aux, sizeof(CARRO), 1, arq)==1){
		printf("Modelo: %s\n", aux.modelo);
		printf("Marca: %s\n", aux.marca);
		printf("Potencia: %0.2f\n\n", aux.pot);
		read = 1;
	}

	if(!read)
		printf("Arquivo vazio!\n");

	fclose(arq);
}

void inserir_car(char arquivo[]){
	FILE *arq;
	CARRO carro;

	arq = fopen(arquivo, "ab");

	if(arq==NULL){
		printf("Erro ao abrir o arquivo!\n");
		system("pause");
		exit(1);
	}

	printf("Modelo: ");
	le_texto(carro.modelo, TAM);
	printf("Marca: ");
	le_texto(carro.marca, TAM);
	printf("Potencia: ");
	scanf("%f", &carro.pot);

	fwrite(&carro, sizeof(CARRO), 1, arq);
	fclose(arq);
}

void exibir_car(char arquivo[]){
	char modelo[TAM];
	FILE *arq;
	CARRO aux;
	int read = 0;

	printf("Entre com o modelo: ");
	le_texto(modelo, TAM);

	arq = fopen(arquivo, "rb");

	if(arq==NULL){
		printf("Erro ao abrir o arquivo!\n\n");
		system("pause");
		exit(1);
	}

	while(fread(&aux, sizeof(CARRO), 1, arq)==1 && read != 1){
		if(!(strcmp(aux.modelo, modelo))){
			printf("Marca: %s\n", aux.marca);
			printf("Potencia: %0.2f\n", aux.pot);
			read = 1;
		}
		else
			read = 2;
	}

	if(!read)
		printf("Arquivo vazio!\n");
	else if (read == 2)
		printf("Modelo nao encontrado!\n");

	fclose(arq);

}

int main(){
	int menu;
	char arquivo[TAM];
	printf("Entre com o nome do arquivo: ");
	le_texto(arquivo, TAM);
	do{
		system("cls");
		printf("\tMENU:\n");
		printf("1) Criar arquivo\n");
		printf("2) Listar sequencialmente\n");
		printf("3) Inserir carro\n");
		printf("4) Exibir carro\n");
		printf("5) SAIR\n");
		printf("\nOpcao: ");
		scanf("%d", &menu);

		switch(menu){
			case 1:
				criar_arq(arquivo);
				break;
			case 2:
				printf("\nListando carros:\n\n");
				listar_car(arquivo);
				break;
			case 3:
				printf("\nInserir carro:\n\n");
				inserir_car(arquivo);
				break;
			case 4:
				printf("\nExibir carro:\n\n");
				exibir_car(arquivo);
				break;
			case 5:
				break;
			default:
				printf("Opcao invalida!\n");
				break;
		}

		printf("\n");
		system("pause");
	}while(menu!=5);
	
	return 0;
}