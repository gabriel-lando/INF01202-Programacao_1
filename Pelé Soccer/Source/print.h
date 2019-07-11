#ifndef _PRINT_H_
#define _PRINT_H_

#include "lib.h"

void print_form(int **mat);

void print_form2(int **mat);

void print_logo();

void print_menu(char sMenu[]);

void print_mapa(int **mapa);

void print_quadra(int dif, COORD_BOLA *bola);

void print_placar(COORD placar);

void print_time(int seg);

void print_tarja(int tam, int qtd, int pos);

void print_bola(COORD_BOLA bola);

void print_ball(COORD_BOLA *bola);

void print_gol();

void print_score(SCORE score, COORD placar);

void print_recordes();

#endif