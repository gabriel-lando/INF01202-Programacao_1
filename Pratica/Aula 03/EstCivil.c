//O algoritmo le um caractre e retorna o sexo correspondente

#include <stdio.h>

int main(){
	char est_civil;
	printf("Entre com um caractere para o estado civil (S,C,D,V,O): ");
	scanf("%c", &est_civil);

	switch (est_civil){
		case 's':
		case 'S':
			printf("Solteiro\n");
			break;
		case 'c':
		case 'C':
			printf("Casado\n");
			break;
		case 'd':
		case 'D':
			printf("Divorciado\n");
			break;
		case 'v':
		case 'V':
			printf("Viuvo\n");
			break;
		case 'o':
		case 'O':
			printf("Outro\n");
			break;
		default:
			printf("Caractere invalido!\n");
	}


	return 0;
}