#include <stdio.h>
#include <stdlib.h>

void funcao(int a, int b, int c, char d);

int main()
{
	int x, y, z;
	char m;

	scanf("%d %d %d %c", &x, &y, &z, &m);

	funcao(x, y, z, m);

	return 0;
}

void funcao(int a, int b, int c, char d){
	int aux;
	if (d == 'M'){
		aux = (a + b + abs(a-b))/2;
		aux = (aux + c + abs(aux-c))/2;
		printf("%d eh o maior\n", aux);
	}
	else{
		aux = (a + b - abs(a-b))/2;
		aux = (aux + c - abs(aux-c))/2;
		printf("%d eh o menor\n", aux);
	}
}