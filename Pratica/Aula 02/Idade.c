/*

Esse algoritmo le a idade em anos, meses e dias e retorna em dias

*/


#include <stdio.h>

int main()
{
	int anos, meses, dias;

	printf("Entre com a idade em anos, meses e dias: ");
	scanf("%i %i %i", &anos, &meses, &dias);

	printf("Idade em dias: %d\n", (anos * 365 + meses * 30 + dias));

	return 0;
}