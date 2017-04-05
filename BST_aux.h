#ifndef _BST_aux
#define _BST_aux

#include "BST.h"

Nodo *_buscaInserir(Nodo *raiz, long int valor, char *direcao);
Nodo * _buscaRemover(Nodo *raiz, long int chave, char *direcao);
void _balanceamentoInserir(Nodo **raiz, Nodo *nodo);

#endif
