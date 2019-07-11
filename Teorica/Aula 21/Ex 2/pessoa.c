#include "pessoa.h"


void CriaData(DATA *d){
	srand(time(0));

	(*d).mes = 1 + (rand() % 12);
	(*d).ano = 1950 + (rand() % 49);
	(*d).dia = 1 + (rand() % 30);
}

void inserir_pessoa(PESSOA *pes){
	printf("Nome: ");
	fflush(stdin);
	gets(pes->nome);
	printf("Altura: ");
	scanf("%f", &pes->altura);
	CriaData(&pes->data);
}

void listar_pessoa(PESSOA pes){
	printf("\nNome: %s\n", pes.nome);
	printf("Altura: %.2f\n", pes.altura);
	printf("Data de nascimento: %02d/%02d/%02d\n", pes.data.dia, pes.data.mes, pes.data.ano);
}

void buscar_data(DATA data, PESSOA pes[], int qtd){
	int i;
	for (i = 0; i < qtd; ++i){
		if(data.ano > pes[i].data.ano)
			listar_pessoa(pes[i]);
		else if(data.ano == pes[i].data.ano){
			if(data.mes > pes[i].data.mes)
				listar_pessoa(pes[i]);
			else if(data.mes == pes[i].data.mes){
				if(data.dia > pes[i].data.dia)
					listar_pessoa(pes[i]);
			}
		}
	}
}