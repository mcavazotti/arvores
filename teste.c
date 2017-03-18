#include "BST.h"
#include "arvore.h"
#include <stdio.h>
#include <stdbool.h>

int main(){

    printf("ok\n");
    Nodo *bst = NULL;

	inserir(&bst, 8);
	inserir(&bst, 4);
	inserir(&bst, 12);
	inserir(&bst, 2);
	inserir(&bst, 6);
	inserir(&bst, 10);
    inserir(&bst, 14);
	inserir(&bst, 2);

    imprimir_InO(bst);
    printf("\n");
	printf("H: %ld\n", bst->h);

	if(balanceada(bst))
		printf("Balanceda\n");
	else
		printf("Não balanceada\n");

	if(busca(bst,12) != NULL)
		printf("12 encontrado\n");
	else
		printf("12 não encontrado\n");

	if(busca(bst,6) != NULL)
		printf("6 encontrado\n");
	else
		printf("6 não encontrado\n");

	if(busca(bst,3) != NULL)
		printf("3 encontrado\n");
	else
		printf("3 não encontrado\n");

	if(busca(bst,2) != NULL)
		printf("2 encontrado\n");
	else
		printf("2 não encontrado\n");

	if(busca(bst,1) != NULL)
		printf("1 encontrado\n");
	else
		printf("1 não encontrado\n");
    return 0;
}
