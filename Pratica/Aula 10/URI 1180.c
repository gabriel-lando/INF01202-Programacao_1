#include <stdio.h>
#include <stdlib.h>

void menor_pos(int n, int *p){
	int i, menor_v, menor_p;
	for (i = 0; i < n; ++i){
		if(!i){
			menor_p = i;
			menor_v = *(p+i);
		}
		else if(menor_v > *(p+i)){
			menor_p = i;
			menor_v = *(p+i);
		}
	}
	printf("Menor valor: %d\nPosicao: %d\n", menor_v, menor_p);
}

int main()
{
	int n, *p, i;

	scanf("%d", &n);

	p = malloc(n* sizeof(int));

	for (i = 0; i < n; ++i)
		scanf("%d", (p+i));

	menor_pos(n, p);
	
	return 0;
}