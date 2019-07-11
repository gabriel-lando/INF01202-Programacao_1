//Calcula se a pascoa esta antes ou depois de uma data

#include <stdio.h>

int main(){

	int dia, mes, a, c, n, k, i, j, l, m, d; 

	do{
		printf("Entre com uma data (DD MM AAAA): ");
		scanf("%d %d %d", &dia, &mes, &a);

		c = a/100;
		n = a - (19*(a/19));
		k = (c - 17)/25;
		i = c - c/4 - ((c-k)/3) +(19*n) + 15;
		i = i - (30*(i/30));
		i = i - ((i/28)*(1-(i/28))*(29/(i+1))*((21-n)/11));
		j = a + a/4 + i + 2 -c + c/4;
		j = j - (7*(j/7));
		l = i - j;
		m = 3 + ((l+40)/44);
		d = l + 28 - (31*(m/4));

		if (mes == m)
			if(dia > d)
				printf("A data eh apos a pascoa!\n");
			else if (dia < d)
				printf("A data eh antes da pascoa!\n");
			else
				printf("A data coincide com a pascoa!\n");
		else if (mes > m)
			printf("A data eh apos a pascoa!\n");
		else
			printf("A data eh antes a pascoa!\n");

		printf("Pascoa: %d/%d/%d\n\n", d, m, a);
	}while(mes!=m || dia!=d);

}