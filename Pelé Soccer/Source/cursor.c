#include "cursor.h"

void charCursor(int x, int y, char *letter){
	HANDLE hOut;
	char letters[5];
	DWORD numberRead;
	COORD where_;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	where_.X = x;
	where_.Y = y;
	ReadConsoleOutputCharacter(hOut, letter, 1, where_, &numberRead);
}

void hideCursor(){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void setCursor(int x, int y){		// coloca o cursor em algum lugar da tela
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(screen, coordinate);
}

void showCursor(){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}