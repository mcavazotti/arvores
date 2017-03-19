#include "BST.h"

Nodo *_buscaInserir(Nodo *raiz, long int valor, char *direcao);
Nodo * _buscaRemover(Nodo *raiz, long int chave, char *direcao);


void inserir(Nodo **raiz, long int valor){
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    char direcao;
    (*novo) = (Nodo){NULL, NULL, NULL, valor, 1};

    if((*raiz) != NULL){
        Nodo *pai = _buscaInserir((*raiz),valor, &direcao);
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

Nodo * buscar(Nodo *raiz, long int chave){
	if(raiz == NULL)
		return NULL;
	if(raiz->chave == chave)
		return raiz;
	if(raiz->chave > chave)
		return buscar(raiz->esq, chave);
	return buscar(raiz->dir, chave);
}

void remover(Nodo *raiz, long int chave){
	char dir;

	Nodo *aux = _buscaRemover(raiz, chave, &dir);
	Nodo *aux_filho;
	if(aux != NULL){
		//aux é folha
		if((aux->esq == NULL) && (aux->dir == NULL)){
			switch(dir){
				case 'd':
					aux->pai->dir = NULL;
				break;
				case 'e':
					aux->pai->esq = NULL;
				break;
			}
			free(aux);
		}
		else if(aux->dir == NULL){
			switch (dir) {
				case 'd':
					aux->pai->dir = aux->esq;
					aux->esq->pai = aux->pai;
					free(aux);
				break;
				case 'e':
					aux->pai->esq = aux->esq;
					aux->esq->pai = aux->pai;
					free(aux);
				break;
				case 'n':
					aux_filho = aux;
					aux_filho->pai = NULL;
					free(aux);
					aux = aux_filho;
				break;
			}
		}

		else if(aux->esq == NULL){
			switch (dir) {
				case 'd':
					aux->pai->dir = aux->dir;
					aux->dir->pai = aux->pai;
					free(aux);
				break;
				case 'e':
					aux->pai->esq = aux->dir;
					aux->dir->pai = aux->pai;
					free(aux);
				break;
				case 'n':
					aux_filho = aux;
					aux_filho->pai = NULL;
					free(aux);
					aux = aux_filho;
				break;
			}
		}
	}
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
		return buscar(raiz->esq, chave);
	return buscar(raiz->dir, chave);
}
