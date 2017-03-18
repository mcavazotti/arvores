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
	atualizaAltura((*raiz));
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

void atualizaAltura(Nodo *raiz){
	if((raiz->esq == NULL) && (raiz->dir == NULL))
		raiz->h = 1;
	else{
		if(raiz->dir == NULL){
			atualizaAltura(raiz->esq);
			raiz->h = raiz->esq->h + 1;
		}
		else if(raiz->esq == NULL){
			atualizaAltura(raiz->dir);
			raiz->h = raiz->dir->h + 1;
		}
		else{
			atualizaAltura(raiz->esq);
			atualizaAltura(raiz->dir);
			raiz->h = ((raiz->esq->h > raiz->dir->h) ? raiz->esq->h : raiz->dir->h) + 1;
		}
	}
}

bool balanceada(Nodo *raiz){
	int aux;

	if((raiz->esq == NULL) && (raiz->dir == NULL))
		return true;
	if(raiz->esq == NULL){
		if(raiz->dir->h == 1)
			return true;
		else
			return false;
	}
	if(raiz->dir == NULL){
		if(raiz->esq->h == 1)
			return true;
		else
			return false;
	}

	aux = ((raiz->esq->h - raiz->dir->h) > 0) ? (raiz->esq->h - raiz->dir->h) : (raiz->dir->h - raiz->esq->h);
	if(balanceada(raiz->esq) && balanceada(raiz->dir) && (aux <= 1))
		return true;
	else
		return false;
}

Nodo * busca(Nodo *raiz, long int chave){
	if(raiz == NULL)
		return NULL;
	if(raiz->chave == chave)
		return raiz;
	if(raiz->chave > chave)
		return busca(raiz->esq, chave);
	return busca(raiz->dir, chave);
}
