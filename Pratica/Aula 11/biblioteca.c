#include "biblioteca.h"

LIVRO cadastraLivro(){
	LIVRO liv;
	printf("Codigo: ");
	scanf("%d", &liv.cod);
	fflush(stdin);
	printf("Titulo: ");
	gets(liv.titulo);
	printf("Preco: ");
	scanf("%f", &liv.preco);
	printf("Numero de pags: ");
	scanf("%d", &liv.n_paginas);

	return liv;
}

void print_livro(LIVRO liv){
	if(liv.cod != -1){
		printf("Codigo: %d\n", liv.cod);
		printf("Titulo: %s\n", liv.titulo);
		printf("Preco: %.2f\n", liv.preco);
		printf("Numero de pags: %d\n\n", liv.n_paginas);
	}
	else
		printf("Livro nao encontrado!\n");
}

float calcMediaPreco(LIVRO livros[], int nlvs){
	int i;
	float media = 0;
	for (i = 0; i < nlvs; ++i)
		media += livros[i].preco/nlvs;
	return (media);
}

LIVRO procuraLivro(LIVRO livros[], int nlvs, int cod){
	int i;
	LIVRO proc;
	for (i = 0; i < nlvs; ++i)
		if(livros[i].cod==cod)
			return livros[i];
	proc.cod = -1;
	return proc;
}

void altera_preco(LIVRO *liv){
	printf("Novo preco: ");
	scanf("%f", &liv->preco);
}
