//Calcula as raizes de uma equaçao de segundo grau

#include <stdio.h>
#include <math.h>

float f_delta(float a, float b, float c){
	return (b*b - 4*a*c);
}

void baskara(float a, float b, float c, float d, float *r1, float *r2){
	if (d){
		d = sqrt(d);
		*r1 = (-b + d) / (2*a);
		*r2 = (-b - d) / (2*a);
	}
	else
		*r1 = (-b) / (2*a);
}

float linear(float a,float b){
	return ((-b)/a);
}

int main(){

	float a, b, c;
	float raiz1, raiz2, delta;

	printf("Entre com os valores de A, B e C em Ax²+Bx+C=0: ");
	scanf("%f %f %f", &a, &b, &c);

	if (a){
		float delta = f_delta(a, b, c);
		if (delta < 0)
			printf("\nNao existem raizes reais (Delta < 0)!\n\n");
		else if (delta == 0){
			baskara(a, b, c, delta, &raiz1, &raiz2);
			printf("\nExiste 1 raiz real: %.3f\n\n", raiz1);
		}
		else{
			baskara(a, b, c, delta, &raiz1, &raiz2);
			printf("\nExistem 2 raizes reais:\nR1= %.3f\nR2= %.3f\n\n", raiz1, raiz2);
		}
	}
	else
		printf("\nA equacao nao eh quadratica!\nO ponto onde a reta corta o eixo X eh: %.3f\n\n", linear(b, c));

	return 0;
}