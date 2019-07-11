#ifndef _CURSOR_H_
#define _CURSOR_H_

#include "lib.h"

void charCursor(int x, int y, char *letter);

void hideCursor();

void setCursor(int x, int y);

void showCursor();

#endif