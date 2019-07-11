/*
Esse programa lê os lados de um paralelepipedo e
calcula a area da superficie e o volume
*/
#include <stdio.h>
void main(void)
{
	float base, comprimento, altura; //Declaração da variáveis de entrada
	float volume, area; //Declaração da variável com o resultado
	printf("\nValor da base: ");
	scanf("%f", &base);

	printf("\nValor da comprimento: ");
	scanf("%f", &comprimento);

	printf("\nValor da altura: ");
	scanf("%f", &altura);

	area = (base * altura * 2) + (base * comprimento * 2) + (comprimento * altura * 2);

	volume = base * altura * comprimento;

	printf("\nArea sa superficie do paralelepipedo: %f\n", area);
	printf("Volume do paralelepipedo: %f\n", volume);


	if (area > volume)
		printf("Area eh maior que o volume\n");
	else if (area == volume)
		printf("Area eh igual ao volume\n");
	else
		printf("Area eh menor que o volume\n");
} 