/*
Algoritmo que calcula o IMC e retorna a situação do usuario
*/

#include <stdio.h>

int main()
{
	float massa, altura, imc;

	printf("Informe a massa e altura da pessoa: "); 
	scanf("%f %f", &massa, &altura);

	imc = massa / (altura * altura);

	if (imc < 18.5)
		printf("Abaixo do peso ideal\n");
	else if (imc < 25)
		printf("Peso normal\n");
	else if (imc < 30)
		printf("Sobrepeso\n");
	else if (imc < 35)
		printf("Obesidade grau I\n");
	else if (imc < 40)
		printf("Obesidade grau II\n");
	else
		printf("Obesidade grau III\n");

	return 0;
}