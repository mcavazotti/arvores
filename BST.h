#ifndef _BST
#define _BST

#include "arvore.h"
#include <stdio.h>
#include <stdbool.h>


void inserir(Nodo **raiz, long int valor);
Nodo * buscar(Nodo * raiz, long int chave);
void imprimir_InO(Nodo *raiz);
void atualizaAltura(Nodo *raiz);
bool balanceada(Nodo *raiz);

#endif
