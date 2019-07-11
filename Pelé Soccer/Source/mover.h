#ifndef _MOVER_H_
#define _MOVER_H_

#include "lib.h"

void mov_goleiros(int *val, int *pos, int **bola);

void mov_left(int **form, char *old, int cor, int pl, COORD_BOLA *bola);

void mov_right(int **form, char *old, int cor, int pl, COORD_BOLA *bola);

void mov_up(int **form, char *old, int cor, int pl, COORD_BOLA *bola);

void mov_down(int **form, char *old, int cor, int pl, COORD_BOLA *bola);

void mov_up_left(int **form, char *old, int cor, int pl, COORD_BOLA *bola);

void mov_up_right(int **form, char *old, int cor, int pl, COORD_BOLA *bola);

void mov_down_left(int **form, char *old, int cor, int pl, COORD_BOLA *bola);

void mov_down_right(int **form, char *old, int cor, int pl, COORD_BOLA *bola);

void move(int **mat1, int **mat2, char *old1, char *old2, int pl, TEMPO *tempo, COORD_BOLA *bola);

#endif