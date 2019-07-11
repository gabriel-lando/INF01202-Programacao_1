/*
Calcula os coeficientes X e Y de um sistema de equações lineares
*/

#include <stdio.h>

int main()
{
	float a, b, c, d, e, f, x, y;

	printf("Entre com os coeficientes A, B e C da equacao Ax + By = C: ");
	scanf("%f %f %f", &a, &b, &c);
	printf("Entre com os coeficientes D, E e F da equacao Dx + Ey = F: ");
	scanf("%f %f %f", &d, &e, &f);

	x = ((c*e) - (b*f)) / ((a*e) - (b*d));
	y = ((a*f) - (c*d)) / ((a*e) - (b*d));

	printf("\n\nX= %.3f\nY=%.3f\n", x, y);

	return 0;
}