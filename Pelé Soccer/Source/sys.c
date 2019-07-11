#include "sys.h"

void sys_screen(int col, int lin){
	//Default: 128 x 50
	char x[5], y[5], tam[30]={"mode con:cols="};;
	sprintf(x, "%d", col);
	sprintf(y, "%d", lin);
	strcat(tam, x);
	strcat(tam, " lines=");
	strcat(tam, y);
	system(tam);
}

void sys_pause(){
	system("pause>nul");
}

void sys_color(char cor[]){
	char color[10]={"color "};
	strcat(color, cor);
	system(color);
}

void sys_clear(){
	system("cls");
}

void sys_green(){
	sys_clear();
	sys_color("20");
}

void sys_red(){
	sys_clear();
	sys_color("40");
}

void sys_blue(){
	sys_clear();
	sys_color("1F");
}

void sys_white(){
	sys_clear();
	sys_color("F0");
}

void sys_exit(){
	sys_pause();
	sys_clear();
	sys_color("07");
	exit(1);
}

void sys_sair(){
	sys_clear();
	sys_color("07");
	exit(1);
}

void timer_jogo(TEMPO *tempo){

	tempo->min = 0;			//x_minutes
	tempo->seg = 0;			//x_seconds
	tempo->mili = 0;		//x_milliseconds
	tempo->c_time = 0;		//countdown_time
	tempo->left = 0;		//time_left

	tempo->c_time = (*tempo).in_time;
	
	tempo->left=(*tempo).c_time - (*tempo).seg;   //Atualiza o tempo

	tempo->cTime=clock(); //Atualiza a diferença de tempo
	tempo->mili=(*tempo).cTime - (*tempo).sTime;
	tempo->seg=((*tempo).mili/(CLOCKS_PER_SEC))-((*tempo).min*60);
	tempo->min=((*tempo).mili/(CLOCKS_PER_SEC))/60;

	tempo->left=(*tempo).c_time - (*tempo).seg; //Subtrai a diferença de tempo
}