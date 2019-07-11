#include <stdio.h>
#define PI 3.14159

void areaTriangulo(double h, double b);
void areaCirculo(double raio);
void areaTrapezio(double h, double b, double B);
void areaQuadrado(double l);
void areaRetangulo(double h, double b);

int main()
{
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);

	areaTriangulo(c, a);
	areaCirculo(c);
	areaTrapezio(c, a, b);
	areaQuadrado(b);
	areaRetangulo(a, b);

	return 0;
}

void areaTriangulo(double h, double b){
	printf("TRIANGULO: %.3lf\n", ((b*h)/2));
}

void areaCirculo(double r){
	printf("CIRCULO: %.3lf\n", (PI*r*r));
}
void areaTrapezio(double h, double b, double B){
	printf("TRAPEZIO: %.3lf\n", ((b+B)*h/2));
}
void areaQuadrado(double l){
	printf("QUADRADO: %.3lf\n", (l*l));
}
void areaRetangulo(double h, double b){
	printf("RETANGULO: %.3lf\n", (b*h));
}
