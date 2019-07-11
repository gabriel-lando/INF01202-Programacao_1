#include "pessoa.h"

int main()
{
	PESSOA pes[TAM];
	DATA data;
	int menu, qtd=0, i;
	do{
		system("cls");
		printf("\tMENU:\n");
		printf("1) Inserir pessoa\n");
		printf("2) Listar pessoas\n");
		printf("3) Pesquisar data\n");
		printf("4) Sair\n");
		printf("\nOpcao: ");
		scanf("%d", &menu);
		system("cls");

		switch(menu){
			case 1:
				printf("Inserir pessoa:\n");
				inserir_pessoa(&pes[qtd]);
				qtd++;
				break;
			case 2:
				printf("Listar pessoas: \n");
				for (i = 0; i < qtd; ++i)
					listar_pessoa(pes[i]);
				break;
			case 3:
				printf("Buscar data: \n");
				printf("Entre com a data: ");
				scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
				buscar_data(data, pes, qtd);
				break;
			case 4:
				break;
			default:
				printf("Opcao invalida\n");
		}
		printf("\n");
		system("pause");
	}while(menu!=4);
	return 0;
}