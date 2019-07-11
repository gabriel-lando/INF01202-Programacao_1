#include "mover.h"

void mov_left(int **form, char *old, int cor, int pl, COORD_BOLA *bola){
	int i, j, k=0, ok=1;
	for (i = 0; i < M_COL; ++i)
		if(form[i][L_ESQ])
			ok=0;
	if(ok)
		for (i = 0; i < M_COL; ++i){
			for (j = 0; j < M_COL; ++j)
				if(form[i][j]){
					if((i == (*bola).Y) && ((j-1) == (*bola).X))
						bola_esq(bola);
					form[i][j-1]=form[i][j];
					form[i][j]=0;
					setCursor(j,i);
					textcolor(0x0);
					if(old[k] == -37)
						printf(" ");
					else
						printf("%c", old[k]);
					charCursor(j-1,i, old+k);
					setCursor(j-1,i);
					textcolor(cor);
					printf("%c", PERS);
					k++;
				}
		}
	old[k]='\0';
}

void mov_right(int **form, char *old, int cor, int pl, COORD_BOLA *bola){
	int i, j, k=pl, ok=1;
	for (i = 0; i < M_COL; ++i)
		if(form[i][M_COL-1-L_DIR])
			ok=0;
	if(ok)
		for (i = (M_COL-1); i >= 0; --i){
			for (j = (M_COL-1); j >= 0; --j)
				if(form[i][j]){
					if((i == (*bola).Y) && ((j+1) == (*bola).X))
						bola_dir(bola);
					k--;
					form[i][j+1]=form[i][j];
					form[i][j]=0;
					setCursor(j,i);
					textcolor(0x0);
					if(old[k] == -37)
						printf(" ");
					else
						printf("%c", old[k]);
					charCursor(j+1,i, old+k);
					setCursor(j+1,i);
					textcolor(cor);
					printf("%c", PERS);
				}
		}
}

void mov_up(int **form, char *old, int cor, int pl, COORD_BOLA *bola){
	int i, j, k=0, ok=1;
	for (j = 0; j < M_COL; ++j)
		if(form[L_SUP][j])
			ok=0;
	if(ok)
		for (i = 0; i < (M_COL); ++i){
			for (j = 0; j < (M_COL); ++j)
				if(form[i][j]){
					if(((i-1) == (*bola).Y) && (j == (*bola).X))
						bola_up(bola);
					form[i-1][j]=form[i][j];
					form[i][j]=0;
					setCursor(j,i);
					textcolor(0x0);
					if(old[k] == -37)
						printf(" ");
					else
						printf("%c", old[k]);
					charCursor(j,i-1, old+k);
					setCursor(j,i-1);
					textcolor(cor);
					printf("%c", PERS);
					k++;
				}
		}
	old[k]='\0';
}

void mov_down(int **form, char *old, int cor, int pl, COORD_BOLA *bola){
	int i, j, k=pl, ok=1;
	for (j = 0; j < M_COL; ++j)
		if(form[M_COL-1-L_INF][j])
			ok=0;
	if(ok)
		for (i = (M_COL-1); i >= 0; --i){
			for (j = (M_COL-1); j >= 0; --j)
				if(form[i][j]){
					if(((i+1) == (*bola).Y) && (j == (*bola).X))
						bola_down(bola);
					k--;
					form[i+1][j]=form[i][j];
					form[i][j]=0;
					setCursor(j,i);
					textcolor(0x0);
					if(old[k] == -37)
						printf(" ");
					else
						printf("%c", old[k]);
					charCursor(j,i+1, old+k);
					setCursor(j,i+1);
					textcolor(cor);
					printf("%c", PERS);
				}
		}
}

void mov_up_left(int **form, char *old, int cor, int pl, COORD_BOLA *bola){
	mov_left(form, old, cor, pl, bola);
	mov_up(form, old, cor, pl, bola);
}

void mov_up_right(int **form, char *old, int cor, int pl, COORD_BOLA *bola){
	mov_right(form, old, cor, pl, bola);
	mov_up(form, old, cor, pl, bola);	
}


void mov_down_left(int **form, char *old, int cor, int pl, COORD_BOLA *bola){
	mov_left(form, old, cor, pl, bola);
	mov_down(form, old, cor, pl, bola);
}

void mov_down_right(int **form, char *old, int cor, int pl, COORD_BOLA *bola){
	mov_right(form, old, cor, pl, bola);
	mov_down(form, old, cor, pl, bola);
}

void move(int **mat1, int **mat2, char *old1, char *old2, int pl, TEMPO *tempo, COORD_BOLA *bola){
	int time_rest;
	mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
	
	//while((!(GetAsyncKeyState(VK_ESCAPE) & 0x8000))){
	do{
		timer_jogo(tempo);
		print_time((*tempo).left);
		print_placar((*bola).placar);
		time_rest = (*tempo).left;
		if(time_rest > 0 && !(*bola).gol){
			sys_pause();
			if((GetAsyncKeyState(VK_UP) & 0x8000) && (GetAsyncKeyState(VK_LEFT) & 0x8000)){
				mov_up_left(mat1, old1, 9, pl, bola);
				mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
			}
			else if((GetAsyncKeyState(VK_UP) & 0x8000) && (GetAsyncKeyState(VK_RIGHT) & 0x8000)){
				mov_up_right(mat1, old1, 9, pl, bola);
				mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
			}
			else if((GetAsyncKeyState(VK_DOWN) & 0x8000) && (GetAsyncKeyState(VK_LEFT) & 0x8000)){
				mov_down_left(mat1, old1, 9, pl, bola);
				mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
			}
			else if((GetAsyncKeyState(VK_DOWN) & 0x8000) && (GetAsyncKeyState(VK_RIGHT) & 0x8000)){
				mov_down_right(mat1, old1, 9, pl, bola);
				mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
			}
			else if(GetAsyncKeyState(VK_LEFT) & 0x8000){
				mov_left(mat1, old1, 9, pl, bola);
				mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
			}
			else if(GetAsyncKeyState(VK_RIGHT) & 0x8000){
				mov_right(mat1, old1, 9, pl, bola);
				mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
			}
			else if(GetAsyncKeyState(VK_UP) & 0x8000){
				mov_up(mat1, old1, 9, pl, bola);
				mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
			}
			else if(GetAsyncKeyState(VK_DOWN) & 0x8000){
				mov_down(mat1, old1, 9, pl, bola);
				mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
			}
			if((GetAsyncKeyState(0x57) & 0x8000) && (GetAsyncKeyState(0x41) & 0x8000)){
				mov_up_left(mat2, old2, 0xC, pl, bola);
				mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
			}
			else if((GetAsyncKeyState(0x57) & 0x8000) && (GetAsyncKeyState(0x44) & 0x8000)){
				mov_up_right(mat2, old2, 0xC, pl, bola);
				mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
			}
			else if((GetAsyncKeyState(0x53) & 0x8000) && (GetAsyncKeyState(0x41) & 0x8000)){
				mov_down_left(mat2, old2, 0xC, pl, bola);
				mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
			}
			else if((GetAsyncKeyState(0x53) & 0x8000) && (GetAsyncKeyState(0x44) & 0x8000)){
				mov_down_right(mat2, old2, 0xC, pl, bola);
				mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
			}
			else if(GetAsyncKeyState(0x41) & 0x8000){
				mov_left(mat2, old2, 0xC, pl, bola);
				mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
			}
			else if(GetAsyncKeyState(0x44) & 0x8000){
				mov_right(mat2, old2, 0xC, pl, bola);
				mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
			}
			else if(GetAsyncKeyState(0x57) & 0x8000){
				mov_up(mat2, old2, 0xC, pl, bola);
				mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
			}
			else if(GetAsyncKeyState(0x53) & 0x8000){
				mov_down(mat2, old2, 0xC, pl, bola);
				mov_goleiros(&(*bola).valG, &(*bola).posGol, (*bola).campo);
			}
		}
	}while(time_rest > 0 && !(*bola).gol);
}

void mov_goleiros(int *val, int *pos, int **campo){
	if(!(*val)){
		setCursor(*pos, 5);
		printf(" ");
		textcolor(0xC);
		printf("%c", PERS);

		setCursor(*pos, M_COL-L_INF);
		printf(" ");
		textcolor(0x9);
		printf("%c", PERS);
		(*pos)++;
		*val = 1;
	}
	else if((*val)==1){ //Desloca o goleiro para a direita
		if(campo[5][(*pos)+1]==1){
			*val=-1;
			(*pos)--;
			mov_goleiros(val, pos, campo);
		}
		else{
			setCursor(*pos, 5);
			printf(" ");
			textcolor(0xC);
			printf("%c", PERS);

			setCursor(*pos, M_COL-L_INF);
			printf(" ");
			textcolor(0x9);
			printf("%c", PERS);
			(*pos)++;
		}
	}
	else{ //Desloca o goleiro para a esquerda
		if(campo[5][(*pos)-1]==1){
			*val=1;
			(*pos)++;
			mov_goleiros(val, pos, campo);
		}
		else{
			setCursor(*pos, 5);
			textcolor(0xC);
			printf("%c", PERS);
			printf(" ");

			setCursor(*pos, M_COL-L_INF);
			textcolor(0x9);
			printf("%c", PERS);
			printf(" ");
			(*pos)--;
		}
	}

}