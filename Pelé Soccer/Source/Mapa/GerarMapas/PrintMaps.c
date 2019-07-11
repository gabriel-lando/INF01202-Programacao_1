#include <stdio.h>
#include <stdlib.h>

int main(){
	char buf[66];
	FILE *mapa;

	fflush(stdin);
	gets(buf);

	system("cls");
	mapa = fopen(buf, "r");
	while(fgets(buf,66, mapa)){
		for (int i = 0; i < 64; ++i)
			if(buf[i]==' ')
				printf("%c", ' ');
			else if(buf[i]=='1')
				printf("%c", 196);
			else if(buf[i]=='2')
				printf("%c", 205);
			else if(buf[i]=='3')
				printf("%c", 186);
			else if(buf[i]=='4')
				printf("%c", 201);
			else if(buf[i]=='5')
				printf("%c", 187);
			else if(buf[i]=='7')
				printf("%c", 188);
			else if(buf[i]=='8')
				printf("%c", 200);
			else if(buf[i]=='9')
				printf("%c", 218);
			else if(buf[i]=='0')
				printf("%c", 191);
			else if(buf[i]=='a')
				printf("%c", 192);
			else if(buf[i]=='b')
				printf("%c", 217);
			else if(buf[i]=='c')
				printf("%c", 180);
			else if(buf[i]=='d')
				printf("%c", 195);
		printf("\n");
	}

	system("pause>nul");
	return 0;
}