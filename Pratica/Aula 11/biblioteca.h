#ifndef	_BIBLIOTECA_H_
#define _BIBLIOTECA_H_

#include <stdio.h>
#include <stdlib.h>
#define QTDE_LIVROS 5

typedef struct livro{
	int cod;
	char titulo[45];
	float preco;
	int n_paginas;
} LIVRO;

LIVRO cadastraLivro();

void print_livro(LIVRO liv);

float calcMediaPreco(LIVRO livros[], int nlvs);

LIVRO procuraLivro(LIVRO livros[], int nlvs, int cod);

void altera_preco(LIVRO *liv);

#endif