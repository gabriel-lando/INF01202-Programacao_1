#include <stdio.h>
#include <stdlib.h>

#define TAM 3

float somaLinha(float matrix[][TAM], int L){
	float soma = 0;
	int i;

	for (i=0; i<(TAM); i++)
		soma += matrix[L][i];

	return soma;
}

float mediaLinha(float matrix[][TAM], int L){
	float media = 0;
	int i;

	for (i=0; i<(TAM); i++)
		media += *(*(matrix+L)+i);

	return (media/TAM);
}

int main()
{
	char funcao;
	float result, matriz[TAM][TAM];
	int L, i, j;

	scanf("%d %c", &L, &funcao);
	for (i = 0; i < TAM; ++i)
		for (j = 0; j < TAM; ++j)
			scanf("%f", &matriz[i][j]);

	if (funcao == 'S')
		result = somaLinha(matriz, L);
	else if(funcao == 'M')
		result = mediaLinha(matriz, L);

	printf("%.1f\n", result);

	return 0;
}