#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10

typedef struct{
	int dia;
	int mes;
	int ano;
}DATA;


typedef struct pessoa{
	char nome[50];
	float altura;
	DATA data;
}PESSOA;

void CriaData(DATA *D);

void inserir_pessoa(PESSOA *pes);

void listar_pessoa(PESSOA pes);

void buscar_data(DATA data, PESSOA pes[], int qtd);