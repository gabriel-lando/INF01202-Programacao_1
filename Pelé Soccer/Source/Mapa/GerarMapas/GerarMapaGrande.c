#include <stdio.h>

int main()
{
	FILE *mapa;
	char str1[65]={"                                                                "};
	char str2[65]={"                       422222222222222225                       "};
	char str3[65]={" 42222222222222222222227                82222222222222222222225 "};
	char str4[65]={" 3                                                            3 "};
	char str8[65]={" 3                            9110                            3 "};
	char str5[65]={" 31111111111111111111111111111c  d11111111111111111111111111113 "};
	char str9[65]={" 3                            a11b                            3 "};
	char str6[65]={" 82222222222222222222225                42222222222222222222227 "};
	char str7[65]={"                       822222222222222227                       "};

	mapa = fopen("MapaG.txt", "w");

	fprintf(mapa, "%s\n", str1);
	fprintf(mapa, "%s\n", str2);
	fprintf(mapa, "%s\n", str3);
	for (int i = 0; i < 23; ++i)
		fprintf(mapa, "%s\n", str4);
	fprintf(mapa, "%s\n", str8);
	fprintf(mapa, "%s\n", str5);
	fprintf(mapa, "%s\n", str9);
	for (int i = 0; i < 23; ++i)
		fprintf(mapa, "%s\n", str4);
	fprintf(mapa, "%s\n", str6);
	fprintf(mapa, "%s\n", str7);
	fprintf(mapa, "%s\n", str1);
	fclose(mapa);

	return 0;
}