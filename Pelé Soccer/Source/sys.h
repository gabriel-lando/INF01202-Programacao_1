#ifndef _SYS_H_
#define _SYS_H_

#include "lib.h"

void sys_screen(int col, int lin);

void sys_pause();

void sys_color(char cor[]);

void sys_clear();

void sys_green();

void sys_red();

void sys_blue();

void sys_white();

void sys_exit();

void sys_sair();

void timer_jogo(TEMPO *tempo);

#endif