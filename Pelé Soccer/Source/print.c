#include "print.h"

void print_form(int **mat){
	int i, j;
	for (i = 0; i < M_LIN; ++i){
		for (j = 0; j < M_COL; ++j)
			if((mat[i][j])){
				setCursor(j, i);
				textbackground(0x2);
				textcolor(0x9);
				printf("%c", PERS);
			}
		//printf("\n");
	}
}

void print_form2(int **mat){
	int i, j;
	for (i = 0; i < M_LIN; ++i){
		for (j = 0; j < M_COL; ++j)
			if((mat[i][j])){
				setCursor(j, i);
				textbackground(0x2);
				textcolor(0xC);
				printf("%c", PERS);
			}
		//printf("\n");
	}
}

void print_logo(){
	char logo[20]={"Menu/Logo.txt"};

	char linha[64];
	int i = 0, j = 0;

	FILE *intro;
	if(!(intro = fopen(logo, "r"))){
		sys_red();
		puts(logo);
		printf("Erro ao abrir o arquivo do logotipo!\n");
		sys_exit();
	}

	hideCursor();
	sys_green();
	sys_screen(124, 38);

	while(fgets(linha, 64, intro)){
		printf("%s", linha);
	}

	fclose(intro);
	
	sys_pause();
}


void print_menu(char sMenu[]){
	char menu2[20]={"Menu/"};
	strcat(menu2, sMenu);

	char linha[64];
	int i = 0, j = 0;

	FILE *menu;
	if(!(menu = fopen(menu2, "r"))){
		sys_red();
		puts(menu2);
		printf("Erro ao abrir o arquivo do menu!\n");
		sys_exit();
	}

	sys_blue();

	while(fgets(linha, 64, menu)){
		printf("%s", linha);
	}

	fclose(menu);
}

void print_mapa(int **mapa){
	int i, j, k;

	mapa[L_SUP][L_ESQ] = 201;
	mapa[M_LIN - L_INF - 1][L_ESQ] = 200;
	mapa[L_SUP][M_COL - L_DIR - 1] = 187;
	mapa[M_LIN - L_INF - 1][M_COL - L_DIR - 1] = 188;

	for (j = L_ESQ + 1; j < (M_COL - L_DIR - 1); ++j){
		mapa[L_SUP][j] = 205;
		mapa[M_LIN - L_INF - 1][j] = 205;
	}

	for (i = L_SUP + 1; i < (M_LIN - L_INF - 1); ++i){
		mapa[i][L_ESQ] = 186;
		mapa[i][M_COL - L_DIR - 1] = 186;
	}

	for (i = 0; i < M_LIN; ++i){
		for (j = 0; j < M_COL; ++j)
			if(!(mapa[i][j])){
				textbackground(0x2);
				printf(" ");
			}
			else{
				textbackground(0x2);
				textcolor(0x9);
				printf("%c", mapa[i][j]);
			}
		printf("\n");
	}
	sys_pause();

}

void print_quadra(int dif, COORD_BOLA *bola){
	char buf[68];
	int i, j;
	FILE *mapa;

	switch(dif){
		case 1:
			strcpy(buf, "Mapa/MapaG.txt");
			bola->vel = 2;
			bola->trave1 = 24;
			bola->trave2 = 41;
			break;
		case 2:
			strcpy(buf, "Mapa/MapaM.txt");
			bola->vel = 2;
			bola->trave1 = 26;
			bola->trave2 = 39;
			break;
		case 3:
			strcpy(buf, "Mapa/MapaM.txt");
			bola->vel = 4;
			bola->trave1 = 26;
			bola->trave2 = 39;
			break;
		case 4:
			strcpy(buf, "Mapa/MapaP.txt");
			bola->vel = 4;
			bola->trave1 = 28;
			bola->trave2 = 37;
			break;
		case 5:
			strcpy(buf, "Mapa/MapaP.txt");
			bola->vel = 6;
			bola->trave1 = 28;
			bola->trave2 = 37;
			break;
		default:
			strcpy(buf, "Mapa/MapaM.txt");
			bola->vel = 4;
			bola->trave1 = 26;
			bola->trave2 = 39;
			break;
	}

	if(!(mapa = fopen(buf, "r"))){
		sys_red();
		puts(buf);
		printf("Erro ao abrir o arquivo da quadra!\n");
		sys_exit();
	}

	sys_green();
	setCursor(0, 3);

	while(fgets(buf,66, mapa)){
		for (i = 0; i < 64; ++i)
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

	fseek(mapa, 0, SEEK_SET);

	j = 3;
	while(fgets(buf,66, mapa)){
		for (i = 0; i < 64; ++i)
			if(buf[i]=='2' || buf[i]=='3' || buf[i]=='4' || buf[i]=='5' || buf[i]=='7' || buf[i]=='8')
				bola->campo[j][i] = 1;
			//if(buf[i]=='1' || buf[i]=='2' || buf[i]=='3' || buf[i]=='4' || buf[i]=='5' || buf[i]=='7' || buf[i]=='8' || buf[i]=='9' || buf[i]=='0' || buf[i]=='a' || buf[i]=='b' || buf[i]=='c' || buf[i]=='d')
		j++;
	}

	fclose(mapa);
}

void print_placar(COORD placar){
	setCursor(19, 1);
	textbackground(0x0);
	textcolor(0x9);
	printf("%d", placar.X);
	setCursor(44, 1);
	textcolor(0xC);
	printf("%d", placar.Y);
	textbackground(0x2);
}

void print_time(int seg){
	int min = seg/60;
	seg -= (min*60);

	setCursor(30, 1);
	textbackground(0x0);
	textcolor(0xF);
	printf("%d:%02d", min, seg);
	textbackground(0x2);

}

void print_tarja(int tam, int qtd, int pos){

	setCursor(0, pos);
	for (int i = 0; i < tam; ++i){
		for (int j = 0; j < qtd; ++j){
			textbackground(0x0);
			printf(" ");
		}
		printf("\n");
	}
	textbackground(0x2);
			
}

void print_bola(COORD_BOLA bola){
	setCursor(bola.X, bola.Y);
	textbackground(0x2);
	textcolor(0x0);
	printf("%c\n", BOLA);
}

void print_ball(COORD_BOLA *bola){
	setCursor((*bola).xo, (*bola).yo);
	textcolor(0x0);
	if((*bola).pos[0] == -37)
		printf(" ");
	else
		printf("%c", (*bola).pos[0]);
	charCursor((*bola).X, (*bola).Y, bola->pos);
	setCursor((*bola).X, (*bola).Y);
	textcolor(0x0);
	printf("%c\n", BOLA);
}

void print_gol(){
	char linha[64];
	int i = 0, j = 0, x = 0;

	FILE *gol;
	if(!(gol = fopen("Menu/Gol.txt", "r"))){
		sys_red();
		printf("Erro ao abrir o arquivo do gol!\n");
		sys_exit();
	}

	do{
		if(!(x%2)){
			sys_color("07");
			sys_clear();
			sys_screen(64, 59);
			setCursor(0, 4);
			textbackground(0x0);
		}
		else{
			sys_color("F0");
			sys_clear();
			sys_screen(64, 59);
			setCursor(0, 4);
			textbackground(0xF);
		}

		i = 0;

		fseek(gol, 0, SEEK_SET);

		while(fgets(linha, 64, gol)){
			j = i/10;
			i++;
			switch(j){
				case 0:
					textcolor(0xA);
					printf("%s", linha);
					break;
				case 1:
					textcolor(0xE);
					printf("%s", linha);
					break;
				case 2:
					textcolor(0x9);
					printf("%s", linha);
					break;
				case 3:
					textcolor(0xE);
					printf("%s", linha);
					break;
				case 4:
					textcolor(0xA);
					printf("%s", linha);
					break;
			}
		}
		x++;
		Sleep(500);
	}while(x!=7);

	fclose(gol);
}

void print_score(SCORE score, COORD placar){
		sys_clear();
		sys_color("0F");
		sys_screen(36, 8);
		sys_pause();
		showCursor();
		setCursor(1, 1);
		printf("Entre com o nome das equipes:\n");
		printf(" Azul: ");
		fflush(stdin);
		gets(score.timeA);
		printf(" Vermelho: ");
		fflush(stdin);
		gets(score.timeV);
		score.placar = placar;
		recordes(score);
}
void print_recordes(){
	SCORE buff;
	char buf[68];
	FILE *record, *top;
	int aux = 0;
	if(!(record = fopen("record.bin", "r+b"))){
		sys_red();
		printf("Erro ao abrir o arquivo de recordes!\n");
		sys_exit();
	}

	if(!(top = fopen("Menu/Top10.txt", "r+"))){
		sys_red();
		printf("Erro ao abrir o arquivo de menu!\n");
		sys_exit();
	}
	sys_screen(64, 36);
	while(fgets(buf, 66, top)){
		printf("%s", buf);
	}
	printf("\n\n\n\n\n");

	while(!(feof(record)) && fread(&buff, sizeof(SCORE), 1, record) && aux < 10){
		printf("%28s  %dx%d  %s\n\n", buff.timeA, buff.placar.X, buff.placar.Y, buff.timeV);
		aux++;
	}
	if(!aux){
		printf("\n\n\n Nao ha recordes disponiveis!\n Jogue uma partida e tente novamente!\n");
	}
	
	fclose(record);
	fclose(top);
	sys_pause();
}
