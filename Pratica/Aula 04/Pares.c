#include <stdio.h>

int main(){
	int num, qtd=0, i;

	for (i = 1; i <= 5; ++i)
	{
		scanf("%i", &num);
		if(!(num%2))
			qtd++;
	}

	printf("%d valores pares\n", qtd);

	return 0;
}