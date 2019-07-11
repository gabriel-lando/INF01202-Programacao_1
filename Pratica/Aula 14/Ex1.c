#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void descriptografar(char *entrada, char *saida, int chave){
	FILE *ent, *sai;
	int aux;

	if(!(ent = fopen(entrada, "r"))){
		printf("Erro na leitura do arquivo\n");
		exit(1);
	}
	sai = fopen(saida, "w");

	while(!feof(ent)){
		aux = fgetc(ent);
		if(aux >= 65 && aux <= 90){
			aux -= chave;
			if(aux < 65)
				aux += (90-64);
		}
		if(aux >= 97 && aux <= 122){
			aux -= chave;
			if(aux < 97)
				aux += (122-96);
		}
		if (aux != -1)
			fputc(aux, sai);
	}
	
	fclose(ent);
	fclose(sai);
	
}

void criptografar(char *entrada, char *saida, int chave){
	FILE *ent, *sai;
	int aux;

	if(!(ent = fopen(entrada, "r"))){
		printf("Erro na leitura do arquivo\n");
		exit(1);
	}
	sai = fopen(saida, "w");

	while(!feof(ent)){
		aux = fgetc(ent);
		if(aux >= 65 && aux <= 90){
			aux += chave;
			if(aux > 90)
				aux -= (90-64);
		}
		if(aux >= 97 && aux <= 122){
			aux += chave;
			if(aux > 122)
				aux -= (122-96);
		}
		if (aux != -1)
			fputc(aux, sai);
	}

	fclose(ent);
	fclose(sai);
	
}

int main(int argc, char *argv[]){
	if (argc == 4){
		criptografar(argv[1], argv[2], atoi(argv[3]));
	}

	else if (argc == 5 && !(strcmp(argv[4], "-d")))
		descriptografar(argv[1], argv[2], atoi(argv[3]));

	else{
		printf("Erro nas entradas!\nEsperava-se: entrada.txt saida.txt Chave \"-d\"\n");
		exit(1);
	}

	return 0;
}
