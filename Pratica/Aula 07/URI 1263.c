/*URI 1263*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char a, b;
	int qtd,j, h, i;
	char linha[100*50];
	char g[100];
	while(gets(linha)!=EOF){
		qtd = 0;
		j = 0;
		h=0;

		g[h]=linha[0];
		h++;
		do{
			if (linha[j]==' ')
			{
				g[h]=linha[j+1];
				h++;
			}
			j++;
			
		}while(linha[j]!= '\0');

		for (i = 1; i <= h; ++i)
			if(tolower(g[i-1])==tolower(g[i]))
				if(tolower(g[i-2])!=tolower(g[i]))
					qtd++;

		printf("%d\n", qtd);

	}

	return 0;
}