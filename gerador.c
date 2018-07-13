#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	srand(time(NULL));

	int i, j, linhas, colunas, resposta;

	while(1) {

		printf("\n------------------------------Gerar nova matriz (1 para sim, 0 para não)? ");
		scanf("%d", &resposta);

		switch (resposta) {

			case 1: {

				printf("\n\nNº de linhas: ");
				scanf("%d", &linhas);
				printf("\nNº de colunas: ");
				scanf("%d", &colunas);

				for (i = 0; i < linhas; i++) {
					printf("\n");
					for (j = 0; j < colunas; j++) 
						printf("%d\t", rand()%19 + 1);
				}

			}
			break;
			
			case 0: {
				
				exit(0);

			}
			break;

			default: {

				printf("\nNão entendi sua resposta. :(");
			}
			break;

		}
	}

	return 0;

}

			
						


