#include <stdio.h>

void mesclar(float a, float b, float *menor);
void imprimeVetor(float vetor[], int tamanho);

int main()
{
	float x[5], y[5], menor[5];

	printf("Entre cos os elementos do vetor 1:\n");
	for (int i = 0; i < 5; ++i)
		scanf("%f", &x[i]);

	printf("Entre cos os elementos do vetor 2:\n");
	for (int i = 0; i < 5; ++i)
		scanf("%f", &y[i]);

	for (int i = 0; i < 5; ++i)
		mesclar(x[i], y[i], &menor[i]);

	imprimeVetor(x, 5);
	imprimeVetor(y, 5);
	imprimeVetor(menor, 5);

	return 0;
}

void mesclar(float a, float b, float *menor){
	if (a < b)
		*menor = a;
	else
		*menor = b;
}

void imprimeVetor(float vetor[], int tamanho){
	for (int i = 0; i < tamanho; ++i)
		printf("%.3f\t", vetor[i]);
	printf("\n");
}