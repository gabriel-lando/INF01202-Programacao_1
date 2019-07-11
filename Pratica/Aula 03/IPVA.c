//Algoritmo que identifica o mes do pagamento do IPVA de um carro baseado nos numeros da placa

#include <stdio.h>

int main()
{
	int placa;

	printf("Entre com os numeros da placa do carro: ");
	scanf("%d", &placa);
	if((placa >= 1000) && (placa <= 9999)){

		placa = placa % 10;

		printf("Mes do pagamento: ");
		switch (placa){
			case 1:
				printf("Janeiro!\n");
				break;
			case 2:
				printf("Fevereiro!\n");
				break;
			case 3:
				printf("Março!\n");
				break;
			case 4:
				printf("Abril!\n");
				break;
			case 5:
				printf("Maio!\n");
				break;
			case 6:
				printf("Junho!\n");
				break;
			case 7:
				printf("Julho!\n");
				break;
			case 8:
			case 9:
			case 0:
				printf("Agosto!\n");
				break;
		}
	}

	return 0;
}