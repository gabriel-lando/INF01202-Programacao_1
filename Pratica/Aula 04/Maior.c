#include <stdio.h>

int main(){
	int num, i, maior, pos;

	for (i = 1; i <=100; ++i)
	{
		scanf("%d", &num);
		if(i==1){
			maior=num;
			pos=i;
		}
		else if(num>maior){
				maior = num;
				pos = i;
		}
	}
	printf("%d\n%d\n", maior, pos);

	return 0;
}