#include "BST.h"

Nodo *_buscaBin(Nodo *raiz, long int valor, char *direcao);

void inserir(Nodo **raiz, long int valor){
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    char direcao;
    (*novo) = (Nodo){NULL, NULL, NULL, valor, 1};

    if((*raiz) != NULL){
        Nodo *pai = _buscaBin((*raiz),valor, &direcao);
        switch(direcao){
            case 'e':
                novo->pai = pai;
                pai->esq = novo;
            break;
            case 'd':
                novo->pai = pai;
                pai->dir = novo;
        }
        printf("inserido %ld, filho de %ld\n",novo->chave, novo->pai->chave);
    }
    else{
        (*raiz) = novo;
        printf("inserido %ld\n", novo->chave);
    }
}

Nodo * _buscaBin(Nodo *raiz, long int valor, char *direcao){
    if(raiz->chave > valor){
        if(raiz->esq == NULL){
            (*direcao) = 'e';
            return raiz;
        }
        return _buscaBin(raiz->esq, valor, direcao);
    }
    if(raiz->dir == NULL){
        (*direcao) = 'd';
        return raiz;
    }
    return _buscaBin(raiz->dir, valor, direcao);
}

void imprimir_InO(Nodo *raiz){
    if(raiz != NULL){
        imprimir_InO(raiz->esq);
        printf("%ld ", raiz->chave);
        imprimir_InO(raiz->dir);
    }
}
