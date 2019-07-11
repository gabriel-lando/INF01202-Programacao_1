/* 
Esse algoritmo calcula a distancia entre 2 pontos no R²
*/

#include <stdio.h>
#include <math.h>

int main()
{
	float xA, yA, xB, yB, modulo;

	printf("Entre com os valores de X e Y para o primeiro ponto: ");
	scanf("%f,%f", &xA, &yA);

	printf("Entre com os valores de X e Y para o segundo ponto: ");
	scanf("%f,%f", &xB, &yB);

	modulo = sqrt((xB-xA)*(xB-xA) + (yB-yA)*(yB-yA));

	printf("Distancia entre os dois pontos: %.4f\n", modulo);

	return 0;
}