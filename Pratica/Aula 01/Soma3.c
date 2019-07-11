/*
Este programa lê dois inteiros entrados pelo usuário, os soma
e exibe o resultado na tela
*/
#include <stdio.h>
void main(void)
{
	float val1, val2; //Declaração da variáveis de entrada
	float soma; //Declaração da variável com o resultado
	printf("Valor do primeiro termo da soma:\n");
	scanf("%f", &val1);

	printf("Valor do segundo termo da soma:\n");
	scanf("%f", &val2);
	soma = val1 + val2;
	printf("Resultado da soma: %f", soma);
}