#include "Biblioteca.h"

void criarBib(){
	FILE *livro;
	float preco = 0;

	if(!(livro = fopen("bib.dat", "r+b"))){
		if(!(livro = fopen("bib.dat", "w+b"))){
			printf("Erro na criacao do arquivo\n");
			system("pause");
			exit(1);
		}
		fwrite(&preco, sizeof(float), 1, livro);
	}

	fclose(livro);
}

void cadastrarLivro(){
	FILE *livro;
	LIVRO liv, buffer;
	float preco;

	if(!(livro = fopen("bib.dat", "r+b"))){
		printf("Erro na abertura do arquivo\n");
		system("pause");
		exit(1);
	}

	fread(&preco, sizeof(float), 1, livro);

	printf("Titulo: ");
	le_texto(liv.titulo, TIT);

	do{
		printf("Preco: ");
		scanf("%f", &liv.preco);
	}while(liv.preco < preco);

	printf("Num. de paginas: ");
	scanf("%d", &liv.n_paginas);

	while(!feof(livro)){
		fseek(livro, 0, SEEK_CUR);
		fread(&buffer, sizeof(LIVRO), 1, livro);
		if(buffer.preco == -1){
			fseek(livro, -1* sizeof(LIVRO), SEEK_CUR);
			break;
		}
	}

	fwrite(&liv, sizeof(LIVRO), 1, livro);

	fclose(livro);

}

void consultaLivro(char nome[]){
	FILE *livro;
	LIVRO buffer;
	int enc = 0;

	if(!(livro = fopen("bib.dat", "r+b"))){
		printf("Erro na abertura do arquivo\n");
		system("pause");
		exit(1);
	}

	fseek(livro, sizeof(float), SEEK_SET);

	while(!feof(livro) && !enc){
		fread(&buffer, sizeof(LIVRO), 1, livro);
		if(!strcmp(nome, buffer.titulo)){
			if(buffer.preco != -1){
				printf("Titulo: %s\n", buffer.titulo);
				printf("Preco: %.2f\n", buffer.preco);
				printf("Num. de paginas: %d\n", buffer.n_paginas);
				enc = 1;
			}
		}
	}
	if(!enc)
		printf("Livro nao encontrado!\n");

	fclose(livro);
}

void deletarLivro(int cod){
	FILE *livro;
	LIVRO liv;
	int tam;
	
	if(!(livro = fopen("bib.dat", "r+b"))){
		printf("Erro na abertura do arquivo\n");
		system("pause");
		exit(1);
	}

	fseek(livro, 0, SEEK_END);
	tam = ftell(livro);

	if(tam > (sizeof(float) + cod * sizeof(LIVRO))){
		fseek(livro, (sizeof(float) + cod * sizeof(LIVRO)), SEEK_SET);
		liv.preco = -1;
		fwrite(&liv, sizeof(LIVRO), 1, livro);
	}

	fclose(livro);
}

void precoMedio(){
	FILE *livro;
	LIVRO liv, buf;
	float preco = 0;
	int qtde = 0;
	
	if(!(livro = fopen("bib.dat", "r+b"))){
		printf("Erro na abertura do arquivo\n");
		system("pause");
		exit(1);
	}

	fseek(livro, sizeof(float), SEEK_SET);

	while(!feof(livro)){
		fread(&liv, sizeof(LIVRO), 1, livro);
		if(liv.preco != -1 && strcmp(liv.titulo, buf.titulo)){
			preco += liv.preco;
			qtde++;
			buf = liv;
		}
	}

	if(qtde){
		preco /= qtde;
	}

	printf("%.2f\n", preco);

	fclose(livro);
}

void precoMinimo(float minimo){
	FILE *livro;
	LIVRO liv;

	if(!(livro = fopen("bib.dat", "r+b"))){
		printf("Erro na abertura do arquivo\n");
		system("pause");
		exit(1);
	}

	fwrite(&minimo, sizeof(float), 1, livro);
	fseek(livro, sizeof(float), SEEK_SET);

	while(!feof(livro)){
		fseek(livro, 0, SEEK_CUR);
		if(fread(&liv, sizeof(LIVRO), 1, livro)){
			if((liv.preco != -1) && (liv.preco < minimo)){
				liv.preco = minimo;
				fseek(livro, (-1 * sizeof(LIVRO)), SEEK_CUR);
				fwrite(&liv, sizeof(LIVRO), 1, livro);
			}
		}
	}

	fclose(livro);
}

void listaLivros(){
	FILE *livro;
	LIVRO liv, buf;
	
	if(!(livro = fopen("bib.dat", "r+b"))){
		printf("Erro na abertura do arquivo\n");
		system("pause");
		exit(1);
	}

	fseek(livro, sizeof(float), SEEK_SET);

	while(!feof(livro)){
		fread(&liv, sizeof(LIVRO), 1, livro);
		if(liv.preco != -1 && strcmp(liv.titulo, buf.titulo)){
			printf("Titulo: %s\n", liv.titulo);
			printf("Preco: %.2f\n", liv.preco);
			printf("Num. de paginas: %d\n\n", liv.n_paginas);
			buf = liv;
		}
	}

	fclose(livro);

}