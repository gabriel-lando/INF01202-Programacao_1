#include "bola.h"

void bola_up(COORD_BOLA *bola){
	bola->xo = (*bola).X;
	bola->yo = (*bola).Y;
	bola->toque ++;
	if((*bola).toque < 3){ //toque
		bola->Y -= (*bola).vel;
	}
	else{ //chute
		bola->toque = 0;
		bola->Y -= 2 * (*bola).vel;
	}
	if((*bola).Y <= L_SUP){ 
		if(((*bola).X > (*bola).trave1) && ((*bola).X < (*bola).trave2) && (*bola).posGol != (*bola).X){
			(*bola).placar.X++;
			(*bola).gol = 1;
		}
		else{
			bola->Y = L_SUP + (L_SUP - (*bola).Y);
		}
	}
	print_ball(bola);
}

void bola_down(COORD_BOLA *bola){
	bola->xo = (*bola).X;
	bola->yo = (*bola).Y;
	bola->toque +=1;
	if((*bola).toque < 3){ //toque
		bola->Y += (*bola).vel;
	}
	else{ //chute
		bola->toque = 0;
		bola->Y += 2 * (*bola).vel;	
	}
	if((*bola).Y >= M_COL-L_INF){
		if(((*bola).X > (*bola).trave1) && ((*bola).X < (*bola).trave2) && (*bola).posGol != (*bola).X){
			(*bola).placar.Y++;
			(*bola).gol = 2;
		}
		else{
			bola->Y -= L_INF;
		}
	}
	print_ball(bola);
}

void bola_dir(COORD_BOLA *bola){
	bola->xo = (*bola).X;
	bola->yo = (*bola).Y;
	bola->toque +=1;
	if((*bola).toque < 3){ //toque
		bola->X += (*bola).vel;
	}
	else{ //chute
		bola->toque = 0;
		bola->X += 2 * (*bola).vel;
	}
	if((*bola).X >= M_COL-L_DIR -1)
			bola->X -= L_DIR;
	print_ball(bola);
}

void bola_esq(COORD_BOLA *bola){
	bola->xo = (*bola).X;
	bola->yo = (*bola).Y;
	bola->toque +=1;
	if((*bola).toque < 3){ //toque
		bola->X -= (*bola).vel;
	}
	else{ //chute
		bola->toque = 0;
		bola->X -= 2 * (*bola).vel;
	}
	if((*bola).X <= L_ESQ)
			bola->X = L_ESQ + (L_ESQ - (*bola).X);
	print_ball(bola);
}