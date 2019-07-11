#include <stdio.h>

int main(){
	int n, i, x;
	int vet[2001]={0};

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		do{
			scanf("%d", &x);
		}while(x<1 || x>2000 || vet[x]==20);
		vet[x]++;
	}

	for (i = 1; i < 2001; ++i)
		if(vet[i])
			printf("%d aparece %d vez(es)\n", i, vet[i]);

	return 0;
}