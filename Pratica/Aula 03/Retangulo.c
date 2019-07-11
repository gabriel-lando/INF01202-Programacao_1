//Le 2 pontos de um retangulo e diz se o terceiro pertence ao retangulo

#include <stdio.h>

int main()
{
	float x1, y1, x2, y2, xp, yp;
	int xd=0, yd=0;

	printf("Entre com as coordenadas do primeiro vertice: ");
	scanf("%f,%f", &x1, &y1);

	printf("Entre com as coordenadas do segundo vertice: ");
	scanf("%f,%f", &x2, &y2);

	printf("Entre com as coordenadas do ponto: ");
	scanf("%f,%f", &xp, &yp);

	if ((x1 != x2) && (y1 != y2)){
		if (x1 > x2){
			if ((xp <= x1) && (xp >= x2))
				xd=1;
		}
		else{
			if ((xp <= x2) && (xp >= x1))
				xd=1;
		}

		if (y1 > y2){
			if ((yp <= y1) && (yp >= y2))
				yd=1;
		}
		else{
			if ((yp <= y2) && (yp >= y1))
				yd=1;
		}
		
		if (xd && yd)
			printf("\nO ponto esta dentro do retangulo!\n\n");
		else
			printf("\nO ponto NAO esta dentro do retangulo!\n\n");
	}
	else
		printf("\nOs pontos nao formam uma caixa!\n\n");

	return 0;
}