#ifndef _BST
#define _BST

#include "arvore.h"
#include <stdio.h>
#include <stdbool.h>


void inserir(Nodo **raiz, long int valor);
void inserirB(Nodo **raiz, long int valor);
Nodo * buscar(Nodo * raiz, long int chave);
void remover(Nodo **raiz, long int chave);
bool balanceada(Nodo *raiz);
void atualizaAltura(Nodo *raiz);
void imprimir_InO(Nodo *raiz);

#endif
