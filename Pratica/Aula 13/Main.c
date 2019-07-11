#include "Biblioteca.h"

int main(){
	int menu, cod;
	char nome[TIT];
	float minimo;

	criarBib();

	do{
		system("cls");
		printf("\tMENU:\n\n");
		printf("1) Cadastrar livro\n2) Consultar livro por nome\n3) Deletar livro por codigo\n");
		printf("4) Exibir preco medio dos livros\n5) Alterar preco minimo\n6) Imprime todos os livros validos\n7) Sair\n");
		printf("\nEscolha uma opcao: ");
		scanf("%d", &menu);
		system("cls");

		switch(menu){
			case 1:
				printf("Cadastrar livro:\n\n");
				cadastrarLivro();
				break;
			case 2:
				printf("Consultar livro:\n\nEntre com o nome: ");
				le_texto(nome, TIT);
				consultaLivro(nome);
				break;
			case 3:
				printf("Deletar livro:\n\nEntre com o codigo: ");
				scanf("%d", &cod);
				deletarLivro(cod);
				break;
			case 4:
				printf("Preco medio dos livros: ");
				precoMedio();
				break;
			case 5:
				printf("Alterar preco minimo:\n\nNovo preco minimo: ");
				scanf("%f", &minimo);
				precoMinimo(minimo);
				break;
			case 6:
				printf("Todos os livros:\n\n");
				listaLivros();
				break;
			case 7:
				break;
			default:
				printf("Opcao invalida!\n");
		}

		printf("\n\n");
		system("pause");

	}while(menu != 7);
	return 0;
}