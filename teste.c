#include "BST.h"
#include "arvore.h"
#include <stdio.h>

int main(){

    printf("ok\n");
    Nodo *bst = NULL;

    inserir(&bst, 10);
    inserir(&bst, 1);
    inserir(&bst, 20);
    inserir(&bst, 2);
    inserir(&bst, 11);
    inserir(&bst, 21);
    inserir(&bst, 1);
    inserir(&bst, 10);
    inserir(&bst, 4);
    inserir(&bst, 12);

    imprimir_InO(bst);
    printf("\n");

    return 0;
}
