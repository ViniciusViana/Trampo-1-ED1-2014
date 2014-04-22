#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>

int main(){ setvbuf(stdout, NULL, _IONBF, 0);
	Lista L_1, L_2;
	Lista add; //recebe a lista vinda da adição, imprim e libera os nós da lista
	int escolha = 1, num;

	criaLista(&L_1);
	criaLista(&L_2);

	while(escolha){

		printf("\n 0 - sair / 1 - insere lista 1 / 2 - insere lista 2 / 3 - soma / 4 - subtrai / 5 - multiplica) \n");
		scanf("%d", &escolha);

		switch(escolha){
			case 1: printf("digite um digito\n");
					scanf("%d", &num);
					insereLista(&L_1, num);
					L_1.tam++;
					printLista(L_1);
				break;
			case 2: printf("digite um digito\n");
					scanf("%d", &num);
					insereLista(&L_2, num);
					L_2.tam++;
					printLista(L_2);
				break;
			case 3: add = soma(&L_1, &L_2);
					printLista(add);
					liberaLista(&add);
				break;
			case 4: subtrai(&L_1, &L_2);
				break;
			case 5: multiplica(&L_1, &L_2);
				break;
		}
	}

	liberaLista(&L_1);
	liberaLista(&L_2);

	printf("BYE-BYE");

	return 0;
}
