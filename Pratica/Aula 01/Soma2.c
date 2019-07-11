/*
Este programa lê dois inteiros entrados pelo usuário, os soma
e exibe o resultado na tela
*/
#include <stdio.h>
void main(void)
{
	int val1, val2; //Declaração da variáveis de entrada
	int soma; //Declaração da variável com o resultado
	printf("Valor do primeiro termo da soma:\n");
	scanf("%d", &val1);

	printf("Valor do segundo termo da soma:\n");
	scanf("%d", &val2);
	soma = val1 + val2;
	printf("Resultado da soma: %d", soma);
} 