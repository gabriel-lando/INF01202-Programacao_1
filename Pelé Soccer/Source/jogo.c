#include "jogo.h"

void iniciar(){
	int fim;
	int **mat1, **mat2, **map;
	char arq[10], cTime[3], cForm[2];
	int i, j, iMenu, iDif, iForm, players;
	char pos1[20] = "                  ";
	char pos2[20] = "                  ";

	COORD_BOLA bola;

	SCORE score;
	
	TEMPO tempo;

	bola.placar.X = 0;
	bola.placar.Y = 0;

	bola.X = (M_COL-4)/2;
	bola.Y = (M_LIN+7)/2;
	strcpy(bola.pos, " ");
	bola.toque = 0;
	bola.posGol = (M_COL-4)/2;
	bola.valG = 0;

	mat1= malloc(M_COL * sizeof(int));
	mat2= malloc(M_COL * sizeof(int));
	bola.campo= malloc(M_COL * sizeof(int));
	for (i = 0; i < M_COL; ++i){
		mat1[i]= (int*)malloc(M_COL * sizeof(int));
		mat2[i]= (int*)malloc(M_COL * sizeof(int));
		bola.campo[i]= malloc(M_COL * sizeof(int));
	}

	//print_logo();
	do{
		fim = 0;
		bola.placar.X = 0;
		bola.placar.Y = 0;

		sys_screen(46, 20);

		fflush(stdin);
		print_menu("Menu.txt");
		iMenu = menu_curs(16, 15, 3);

		if(!iMenu){ //JOGAR

			sys_screen(46, 26);
			print_menu("MenuJogar.txt");
			iDif = menu_curs(16, 16, 5) + 1;
			
			if(iDif != 0){
				showCursor();
				setCursor(29, 22);
				gets(cTime);

				if(cTime[0] == '\0')
					tempo.lido = 1;
				else
					tempo.lido = atoi(cTime);

				hideCursor();

				sys_screen(46, 28);
				print_menu("MenuForm.txt");
				iForm = menu_curs(13, 16, 10);

				if(iForm != -1){
					sprintf(cForm, "%d", iForm);
					strcpy(arq, "ft");
					strcat(arq, cForm);

					tempo.sTime = clock();  //Inicia o relógio

					do{
						for (i = 0; i < M_COL; ++i){
							for (j = 0; j < M_COL; ++j){
								mat1[i][j]=0;
								mat2[i][j]=0;
								bola.campo[i][j] = 0;
							}
						}
						bola.X = (M_COL-4)/2;
						bola.Y = (M_LIN+7)/2;
						strcpy(bola.pos, " ");
						bola.toque = 0;
						bola.posGol = (M_COL-4)/2;
						bola.valG = 0;
						bola.gol = 0;
						sys_screen(64, 59);
						setCursor(0, 3);

						print_quadra(iDif, &bola);

						print_tarja(3, 64, 0);

						players = formacao(mat1, mat2, arq);

						print_form(mat1);
						print_form2(mat2);
						print_bola(bola);

						tempo.in_time = tempo.lido*60;

						move(mat1, mat2, pos1, pos2, players, &tempo, &bola);

						if(bola.gol){
							print_gol();
						}
						sys_clear();
						
					}while(tempo.left > 0);
					print_score(score, bola.placar);
				}
			}
		}

		else if(iMenu == 1){ //Ranking
			print_recordes();
		}

		else{ //Sair
			fim = 1;
		}

	}while(!fim);

	sys_sair();

}