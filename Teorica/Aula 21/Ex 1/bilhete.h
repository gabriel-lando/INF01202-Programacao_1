#include <stdio.h>

typedef struct{
	int dia;
	int mes;
	int ano;
}DATA;

typedef struct{
	int hora;
	int minuto;
}HORA;

typedef struct passagem{
	int cod;
	char nome[30];
	char origem[30];
	char destino[30];
	DATA data;
	HORA horario;
	int assento;
	float valor;
}PASSAGEM;

void ler_bilhete(PASSAGEM *pas);

void mostrar_bilhete(PASSAGEM pas);