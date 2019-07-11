/*Entra com as notas de X alunos,
calcula a media e mostra os alunos que estao acima da media */
#include <stdio.h>
#define AL 5

int main(int argc, char const *argv[])
{
	float notas[AL] = {0};
	float media = 0;

	for (int i = 0; i < AL; ++i)
	{
		printf("Entre com a nota do aluno %d: ", i+1);
		scanf("%f", &notas[i]);
		media += notas[i];
	}

	media /= AL;

	printf("\n\nMedia: %.3f\n\n", media);

	for (int j = 0; j < AL; ++j)
		if (notas[j]>=media)
			printf("Aluno: %d\tMedia: %.3f\n", j+1, notas[j]);

	return 0;
}