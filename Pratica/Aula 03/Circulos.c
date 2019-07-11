//Algoritmo que informa se dois circulos se interceptam, se sobrepoem completamente ou nao se tocam

#include <stdio.h>
#include <math.h>

int main()
{
	
	float xc1, yc1, xc2, yc2, r1, r2;
	float dist, raio;

	printf("Entre com as coordenadas do centro do circulo 1: ");
	scanf("%f,%f", &xc1, &yc1);
	printf("Entre com o raio do circulo 1: ");
	scanf("%f", &r1);

	printf("Entre com as coordenadas do centro do circulo 1: ");
	scanf("%f,%f", &xc2, &yc2);
	printf("Entre com o raio do circulo 1: ");
	scanf("%f", &r2);

	dist = sqrt((xc2-xc1)*(xc2-xc1) + (yc2-yc1)*(yc2-yc1));

	if (dist > (r2 + r1))
		printf("\nOs circulos nao se interceptam!\n");
	else if (dist == (r1 + r2))
		printf("\nOs circulos tangenciam!\n");
	else{
		if (r2 > r1){
			if((dist + r1) < r2)
				printf("\nOs circulos se sobrepoem completamente!\n");
			else
				printf("\nOs circulos se interceptam!\n");
		}
		else if (r1 > r2){
			if((dist + r2) < r1)
				printf("\nOs circulos se sobrepoem completamente!\n");
			else
				printf("\nOs circulos se interceptam!\n");
		}
		else
			printf("\nOs circulos se interceptam!\n");
	}


	return 0;
}