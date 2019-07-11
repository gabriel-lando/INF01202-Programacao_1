//Este programa mostra na tela um menu de opçoes...

#include <stdio.h>
#include <stdlib.h>

void Peso(){
	char sexo;
	float altura;

	printf("Entre com o sexo (M ou F): ");
	scanf(" %c", &sexo);
	printf("Entre com a altura (metros): ");
	scanf("%f", &altura);
	system("cls");

	switch(sexo){
		case 'm':
		case 'M':
			printf("Peso ideal: %.2f\n", (altura * 72.7 - 58));
			break;
		case 'f':
		case 'F':
			printf("Peso ideal: %.2f\n", (altura * 62.1 - 44.7));
			break;
		default:
			printf("Sexo invalido!\n");
	}
}

void Calculadora(){
	float x, y;
	char op;

	printf("Entre com os valores e a operacao (Ex: x + y):\n");
	scanf("%f %c %f", &x, &op, &y);
	system("cls");

	switch(op){
		case '+':
			printf("%.2f %c %.2f = %.2f\n", x, op, y, x+y);
			break;
		case '-':
			printf("%.2f %c %.2f = %.2f\n", x, op, y, x-y);
			break;		
		case '*':
			printf("%.2f %c %.2f = %.4f\n", x, op, y, x*y);
			break;
		case '/':
			if (y)
				printf("%.2f %c %.2f = %.4f\n", x, op, y, x/y);
			else
				printf("Divisao por 0!\n");
			break;

	}

}

void Conceitos(){
	float nota;
	printf("Entre com uma nota: ");
	scanf("%f", &nota);
	system("cls");

	if (nota >= 0 && nota <= 10){
		if (nota < 6)
			printf("Reprovado!\n");
		else if (nota < 7.5)
			printf("Conceito: C\n");
		else if (nota < 9)
			printf("Conceito: B\n");
		else
			printf("Conceito: A\n");
	}
	else
		printf("Nota invalida!\n");
}

int Fib(int f){
	if (f==0)
		return 0;
	else if (f==1)
		return 1;
	else{
		return (Fib(f-1)+Fib(f-2));
	}
}

void Fibonacci(){

	int a, b, i;

	printf("Entre com o intervalo do Fibonacci: ");
	scanf("%i %i", &a, &b);
	system("cls");

	if(a>=0 && b>=0){
		for (i = a; i <= b; ++i)
			printf("%d ", Fib(i));
	}
	printf("\n");
}

void Turmas(){
	int alunos, i, j;
	float n1, n2, n3, m, media;

	for (i = 1; i <= 3; ++i){
		media = 0;
		printf("\nQuantidade de alunos da turma %d: ", i);
		scanf("%d", &alunos);
		for (j = 1; j <= alunos; ++j){
			printf("\nEntre com as notas do aluno %d: ", j);
			scanf("%f %f %f", &n1, &n2, &n3);
			m = (n1+n2+n3)/3;
			media += m;
			printf("Media: %.2f\n", m);
		}
		printf("\nMedia da turma: %.2f\n\n", media/alunos);
	}
}

int main()
{
	int menu;

	system("cls");
	printf("\tMENU\n");
	printf("1) Peso ideal\n");
	printf("2) Calculadora\n");
	printf("3) Conceitos\n");
	printf("4) Fibonacci\n");
	printf("5) Turmas e notas\n\n");
	printf("Entre com uma opcao: ");
	scanf("%d", &menu);

	system("cls");
	switch(menu){
		case 1:
			Peso();
			break;
		case 2:
			Calculadora();
			break;
		case 3:
			Conceitos();
			break;
		case 4:
			Fibonacci();
			break;
		case 5:
			Turmas();
			break;
		default:
			printf("Opcao invalida!!\n");
			break;
	}

	system("pause");
	return 0;
}