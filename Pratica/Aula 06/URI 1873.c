#include <stdio.h>
#include <string.h>

int comp(char *str){
	char la[10], pa[10], pe[10], sp[10], te[10];
	strcpy(la, "lagarto");
	strcpy(pa, "papel");
	strcpy(pe, "pedra");
	strcpy(sp, "spock");
	strcpy(te, "tesoura");

	if (!(strcmp(str, la)))
		return 1;
	else if (!(strcmp(str, pa)))
		return 2;
	else if (!(strcmp(str, pe)))
		return 3;
	else if (!(strcmp(str, sp)))
		return 4;
	else if (!(strcmp(str, te)))
		return 5;
	else
		return 0;

}

int main(){
	int i, t, v, r, s;
	char a[10], b[10];
	
	scanf("%d", &t);

	for (i = 0; i < t; ++i)
	{
		v=0;
		scanf("%s %s", a, b);
		
		r = comp(a);
		s = comp(b);

		if(r==5){
			if((s==3)||(s==4))
				v=2;
			else if((s==1)||(s==2))
				v=1;
		}
		else if(r==4){
			if((s==3)||(s==5))
				v=1;
			else if((s==2)||(s==1))
				v=2;
		}
		else if(r==3){
			if((s==1)||(s==5))
				v=1;
			else if((s==2)||(s==4))
				v=2;
		}
		else if(r==2){
			if((s==3)||(s==4))
				v=1;
			else if((s==1)||(s==5))
				v=2;
		}
		else if(r==1){
			if((s==2)||(s==4))
				v=1;
			else if((s==3)||(s==5))
				v=2;
		}

		if(!v)
			printf("empate\n");
		else if (v==1)
			printf("rajesh\n");
		else
			printf("sheldon\n");


	}
}