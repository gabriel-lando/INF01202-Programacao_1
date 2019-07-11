#include "bilhete.h"

int main()
{
	PASSAGEM bilhete;

	ler_bilhete(&bilhete);
	
	mostrar_bilhete(bilhete);

	return 0;
}