#include "arquivos.h"

int formacao(int **form1, int **form2, char arq[]){
	int aux[100][100] = {0};
	char dir[20]={"Formacoes/"};
	COORD cd;

	char linha[64];
	int i = 0, j = 0, flag = 0, flag2, x1, x2, x3, aux2, aux3, aux4, dist = 0, count = 0;

	strcat(dir, arq);
	strcat(dir, ".txt");
	FILE *txt;
	if(!(txt = fopen(dir, "r"))){
		sys_red();
		puts(dir);
		printf("Erro ao abrir o arquivo de formacao!\n");
		sys_exit();
	}

	while(fgets(linha, 64, txt)){ //Procura o primeiro jogador da formacao e a distancia entre os mais distantes
		j = 0;
		flag2 = 0;
		x2 = 0;
		do{
			if(linha[j]=='X' && !flag){
				cd.X = j-1;
				cd.Y = i;
				flag++;
			}
			if(linha[j]=='X' && !flag2){
				x1 = j-1;
				flag2++;
			}
			else if(linha[j]=='X'){
				x2 = j-1;
			}
			j++;
		}while(linha[j]!='\0');
		if(dist < (x2 - x1)){
			dist = (x2 - x1);
			x3 = x1;
		}
		i++;
	}

	fseek(txt, 0, SEEK_SET);

	i = 0;
	while(fgets(linha, 64, txt)){ //Armazena os jogadores em uma matris auxiliar, para centralizar depois
		j = x3;
		do{
			if(linha[j]=='X'){
				aux[i-cd.Y][j-x3]=1;
				count++;
			}
			j++;
		}while(linha[j]!='\0');
		i++;
	}

	aux2 = (M_COL - 1 - dist)/2 - 3;
	aux3 = M_LIN/2 + 14; 	//distancia do primeiro jogador azul à bola
	aux4 = M_LIN/2 + 7;		//distancia do primeiro jogador vermelho à bola

	for (int k = 0; k < i-cd.Y; ++k) //AQUI
		for (int l = 0; l < j-x3; ++l)
			if(aux[k][l])
				form1[k+aux3][l+aux2] = aux[k][l];

	for (int k = i-cd.Y; k >= 0; --k) //AQUI
		for (int l = j-x3; l >= 0; --l)
			if(aux[k][l])
				form2[M_LIN-(k+aux4)][l+aux2] = aux[k][l];

	fclose(txt);

	return count;
}

void recordes(SCORE score){
	FILE *arq1;
	SCORE lido;
	int inseriu=0;

	if(!(arq1 = fopen("record.bin", "r+b"))){
		if(!(arq1 = fopen("record.bin", "w+b"))){
			sys_red();
			printf("Erro ao criar o arquivo de recordes!\n");
			sys_exit();
		}
	}

	fseek(arq1, 0*sizeof(SCORE), SEEK_END);
	while (!feof(arq1) && !inseriu ){
		fseek(arq1, -1*sizeof(SCORE), SEEK_CUR);
		if (fread(&lido, 1, sizeof(SCORE), arq1)){
			if((score.placar.X + score.placar.Y) < (lido.placar.X + lido.placar.Y)){
				fseek(arq1, 0*sizeof(SCORE), SEEK_CUR);
				fwrite(&score, 1, sizeof(SCORE), arq1);
				inseriu = 1;
			}
			else{
				fseek(arq1, 0*sizeof(SCORE), SEEK_CUR);
				fwrite(&lido, 1, sizeof(SCORE), arq1);
				fseek(arq1, -2*sizeof(SCORE), SEEK_CUR);
				
				if(ftell(arq1) == 0){
					fwrite(&score, 1, sizeof(SCORE), arq1);
					inseriu = 1;
				}
			}
		}
		else if(!inseriu){
			fseek(arq1, -1*sizeof(SCORE), SEEK_CUR);
			fwrite(&score, 1, sizeof(SCORE), arq1);
			inseriu = 1;
		}
	}
	fclose(arq1);
}
