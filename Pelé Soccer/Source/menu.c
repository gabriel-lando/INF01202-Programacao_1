#include "menu.h"

// Menu principal
// menu_x: 16
// menu_y: 15

//#define menu_x 21
//#define menu_y 17

int menu_curs(int menu_x, int menu_y, int qtd){
	int ft = 0;
	hideCursor();
	fflush(stdin);
	do{
		fflush(stdin);
		GetAsyncKeyState(VK_OEM_CLEAR);
		setCursor(menu_x, menu_y + ft);
		printf("%c", 175);
		sys_pause();
		if(GetAsyncKeyState(VK_DOWN)){
			if(ft < (qtd-1)){
				setCursor(menu_x, menu_y + ft);
				puts(" ");
				ft++;
			}
		}
		else if(GetAsyncKeyState(VK_UP)){
			if(ft>0){
				setCursor(menu_x, menu_y + ft);
				puts(" ");
				ft--;
			}
		}
		else if((GetAsyncKeyState(VK_ESCAPE) & 0x8000)){
			return -1;
		}
	}while(!(GetAsyncKeyState(VK_RETURN) & 0x8000));
	return ft;
}