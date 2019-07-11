#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define PI 3.1415926

char s_n(){
	char c;

	do{	
		printf("Mais um (S/N)? ");
		scanf(" %c", &c);
		c=toupper(c);
		if ((c != 'N') && (c != 'S'))
		printf("\a");
	}while ((c != 'N') && (c != 'S'));
	return c;
} 

float radPgraus(float rad){
	return ((rad*180)/PI);
}

float escalar(float vx, float vy, float wx, float wy){
	return ((vx*wx)+(vy*wy));
}

float angulo(float vx, float vy, float wx, float wy){
	float mod_v, mod_w, ang;
	mod_v = sqrt(vx*vx + vy*vy);
	mod_w = sqrt(wx*wx + wy*wy);
	ang = acos(escalar(vx, vy, wx, wy)/(mod_v*mod_w));
	return (radPgraus(ang));
}

int main()
{
	float vx, vy, wx, wy, ang;

	do{
		printf("\n");
		printf("Digite as coordenadas de V: ");
		scanf("%f %f", &vx, &vy);

		printf("Digite as coordenadas de W: ");
		scanf("%f %f", &wx, &wy);

		ang = angulo(vx, vy, wx, wy);

		printf("\nO angulo entre V e W eh: %.2f graus\n\n", ang);

	}while(s_n() != 'N');

	
	return 0;
}