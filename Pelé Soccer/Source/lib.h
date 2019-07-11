#pragma once

#include <conio2.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

#define M_LIN 53
#define M_COL 67

#define	L_DIR 5
#define	L_ESQ 2
#define L_SUP 6
#define L_INF 12

#define LIN 70
#define COL 84

#define PERS 219
#define BOLA 254

typedef struct score{
	char timeA[50];
	char timeV[50];
	COORD placar;
}SCORE;

typedef struct countdown{
	int lido;					//Tempo lido
	unsigned int in_time;		//Tempo inicial = tempo * 60
	unsigned int min;			//x_minutes
	unsigned int seg;			//x_seconds
	unsigned int mili;			//x_milliseconds
	unsigned int c_time;		//countdown_time
	int left;					//time_left
	clock_t sTime;				//x_startTime
	clock_t cTime;				//x_countTime
}TEMPO;

typedef struct coord_bola{
	int X, Y, vel;
	int xo, yo;
	int **campo;
	int toque;
	char pos[2];
	int posGol;
	int valG;
	int trave1, trave2;
	COORD placar;
	int gol;
}COORD_BOLA;

#include "arquivos.h"
#include "mover.h"
#include "cursor.h"
#include "print.h"
#include "jogo.h"
#include "sys.h"
#include "menu.h"
#include "bola.h"

