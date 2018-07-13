#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	int cont;

	for (cont=0; cont<argc; cont++)
		printf("%d Parâmetro: %s\n", cont, argv[cont]);
	return 0;

}
