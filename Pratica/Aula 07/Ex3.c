#include <stdio.h>
#include <string.h>

int main()
{
	char str[5][50];
	int i, j, x, y;
	char aux[50];
	int spc[5]={0};

	for (i = 0; i < 5; ++i)
	{
		printf("String %d: ", i+1);
		//scanf("%s", str[i]);
		gets(str[i]);
	}
	do{
		printf("Entre com as linhas para trocar: ");
		scanf("%d %d", &x, &y);
	}while(x>5||x<1||y>5||y<1||x==y);

	x--;
	y--;

	strcpy(aux, str[x]);
	strcpy(str[x], str[y]);
	strcpy(str[y], aux);

	for (i = 0; i < 5; ++i)
	{
		j=0;
		do{
			if (str[i][j]== ' ')
				spc[i]++;
			j++;
		} while (str[i][j]!='\0');
	}

	printf("\n");

	for (i = 0; i < 5; ++i)
	{
		printf("%s = %d espacos\n", str[i], spc[i]);
	}

	return 0;
}