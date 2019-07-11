/*Esse algoritmo le duas string e junta elas em uma terceira*/

#include <stdio.h>
#include <string.h>

int main()
{
	char str1[50];
	char str2[50];
	char str3[100];
	char c;
	int i=0, q=0;

	gets(str1);
	gets(str2);
	//scanf("%s", str1);
	//scanf("%s", str2);
	strcpy(str3, str1);
	strcat(str3, str2);
	printf("%s\n", str3);

	scanf(" %c", &c);
	do
	{
		if (str3[i]== c )
			str3[i]=' ';
		i++;
	} while (str3[i]!='\0');

	printf("\n%s\n%s\n", str1, str2);
	printf("%s\n\n", str3);

	i=0;
	do
	{
		if (str3[i]== ' ')
			q++;
		i++;
	} while (str3[i]!='\0');
	printf("Qtde de espacos: %d\n", q);


	return 0;
}