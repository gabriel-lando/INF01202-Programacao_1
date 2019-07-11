#include <stdio.h>
#include <string.h>

int main()
{
	float mat[4][3]={0};
	int i, j;
	float mult;
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 3; ++j)
		{
			printf("[%d][%d]: ", i, j);
			scanf("%f", &mat[i][j]);
			if(!mat[i][j])
				mat[i][j]=1.0;

		}

	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 3; ++j)
			printf("%.2f\t", mat[i][j]);
		mult=1;
		for (j = 0; j < 3; ++j)
			mult*=mat[i][j];
		printf(" = %.2f\n", mult);
	}

	return 0;
}