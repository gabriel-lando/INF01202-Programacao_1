#include <stdio.h>

void mesclar(float a, float b, float *menor);

int main()
{
	float x, y, menor;

	scanf("%f %f", &x, &y);
	mesclar(x, y, &menor);

	printf("%.3f eh o menor\n", menor);
	return 0;
}

void mesclar(float a, float b, float *menor){
	if (a < b)
		*menor = a;
	else
		*menor = b;
}