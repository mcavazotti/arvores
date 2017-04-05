#include "BST_aux.h"


Nodo * _buscaInserir(Nodo *raiz, long int valor, char *direcao){
    if(raiz->chave > valor){
        if(raiz->esq == NULL){
            (*direcao) = 'e';
            return raiz;
        }
        return _buscaInserir(raiz->esq, valor, direcao);
    }
    if(raiz->dir == NULL){
        (*direcao) = 'd';
        return raiz;
    }
    return _buscaInserir(raiz->dir, valor, direcao);
}

Nodo * _buscaRemover(Nodo *raiz, long int chave, char *direcao){
	if(raiz == NULL)
		return NULL;
	if(raiz->chave == chave){
		if(raiz->pai == NULL)
			(*direcao) = 'n';
		else if(raiz->pai->esq == raiz)
			(*direcao) = 'e';
		else
			(*direcao) = 'd';
		return raiz;
	}
	if(raiz->chave > chave)
		return _buscaRemover(raiz->esq, chave,direcao);
	return _buscaRemover(raiz->dir, chave,direcao);
}
