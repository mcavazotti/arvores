#include "BST.h"
#include "arvore.h"
#include <stdio.h>
#include <stdbool.h>

int main(){

	Nodo *bst = NULL;
	char op = 'x';
	long int v;

	printf("Teste BST.\nDigite a operação: \n i - Inserir // s - buscar (search) // r - remover // b - balanceada //\n h - altura (height) // p - imprimir (print) // q - sair (quit)\n\n");
	printf(">> ");
	while(op != 'q'){
		scanf("%c",&op );
		switch (op) {
			case 'i':
				printf("Insira o valor (int): ");
				scanf("%ld", &v);
				inserir(&bst, v);
				printf(">> ");
			break;
			case 's':
				printf("Insira o valor (int): ");
				scanf("%ld", &v);
				if(buscar(bst, v) != NULL)
					printf("%ld encontrado\n", v);
				else
					printf("%ld não encontrado\n", v);
				printf(">> ");
			break;
			case 'r':
				printf("Insira o valor (int): ");
				scanf("%ld", &v);
				remover(&bst, v);
				printf("Feito\n");
				printf(">> ");
			break;
			case 'b':
				if(balanceada(bst))
					printf("Balanceada\n");
				else
					printf("Não balanceada\n");
				printf(">> ");
			break;
			case 'h':
				if(bst == NULL)
					printf("Árvore vazia\n");
				else{
                	atualizaAltura(bst);
	        		printf("Altura: %ld\n",bst->h );
				}
				printf(">> ");
			break;
			case 'p':
				imprimir_InO(bst);
				printf("\n");
				printf(">> ");
			break;
			case 'q':
				printf("Saindo.\n");
			break;
			case '\n':
			case ' ':
			break;
			default:
				printf("Operação inválida\n");
				printf(">> ");
			break;
		}
	}
	return 0;
}
