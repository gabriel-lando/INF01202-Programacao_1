#include "biblioteca.h"


int main()
{
	int qtde_liv=0, menu, codigo, i;
	float med;
	LIVRO livros[QTDE_LIVROS];

	do{
		system("cls");
		printf("\n\tMENU:\n1) Cadastro de livro\n2) Consulta de livro\n");
		printf("3) Preco medio dos livros\n4) Imprime biblioteca\n5) Alterar preco\n6) Fim\n\n");
		printf("Entre com uma opcao: ");
		scanf("%d", &menu);
	
		system("cls");

		switch(menu){
			case 1:
				if(qtde_liv < QTDE_LIVROS){
					printf("Cadastro de Livro:\n\n");
					livros[qtde_liv] = cadastraLivro();
					qtde_liv++;
				}
				else
					printf("Quantidade maxima!\n");
				break;
			case 2:
				printf("Consulta de Livro:\n\nEntre com um codigo: ");
				scanf("%d", &codigo);
				printf("\n");
				print_livro(procuraLivro(livros, qtde_liv, codigo));
				break;
			case 3:
				med = calcMediaPreco(livros, qtde_liv);
				printf("Preco medio dos livros: %.2f\n", med);
				break;
			case 4:
				printf("Imprime biblioteca\n\n");
				for (i = 0; i < qtde_liv; ++i){
					print_livro(livros[i]);
				}
				break;
			case 5:
				printf("Alterar preco:\n\nEntre com um codigo: ");
				scanf("%d", &codigo);
				for (i = 0; i < qtde_liv; ++i)
					if(livros[i].cod==codigo)
						altera_preco(&livros[i]);
				break;
			case 6:
				break;
			default:
				printf("Entrada invalida!\n");
				break;
		}
		printf("\n");
		system("pause");
	}while(menu!=6);

	return 0;
}