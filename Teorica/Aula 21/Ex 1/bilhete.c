#include "bilhete.h"

void ler_bilhete(PASSAGEM *pas){
	printf("Codigo da empresa: ");
	scanf("%d", &pas->cod);
	printf("Nome do passageiro: ");
	fflush(stdin);
	gets(pas->nome);
	printf("Origem: ");
	fflush(stdin);
	gets(pas->origem);
	printf("Destino: ");
	fflush(stdin);
	gets(pas->destino);
	printf("Data: ");
	scanf("%d/%d/%d", &pas->data.dia, &pas->data.mes, &pas->data.ano);
	printf("Horario: ");
	scanf("%d:%d", &pas->horario.hora, &pas->horario.minuto);
	printf("Assento: ");
	scanf("%d", &pas->assento);
	printf("Valor: ");
	scanf("%f", &pas->valor);
}

void mostrar_bilhete(PASSAGEM pas){
	printf("\n\nCodigo da empresa: %d\n", pas.cod);
	printf("Nome do passageiro: %s\n", pas.nome);
	printf("Origem: %s\n", pas.origem);
	printf("Destino: %s\n", pas.destino);
	printf("Data: %02d/%02d/%02d\n", pas.data.dia, pas.data.mes, pas.data.ano);
	printf("Horario: %02d:%02d\n", pas.horario.hora, pas.horario.minuto);
	printf("Assento: %d\n", pas.assento);
	printf("Valor: %.2f\n", pas.valor);
}