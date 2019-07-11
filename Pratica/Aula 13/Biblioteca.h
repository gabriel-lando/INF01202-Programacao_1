#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "le_texto.h"

#define TIT 45

typedef struct livro{
	char titulo[TIT];
	float preco;
	int n_paginas;
}LIVRO;

void criarBib();

void cadastrarLivro();

void consultaLivro(char nome[]);

void deletarLivro(int cod);

void precoMedio();

void precoMinimo(float minimo);

void listaLivros();