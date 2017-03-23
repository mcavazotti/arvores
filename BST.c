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

void remover(Nodo **raiz, long int chave){
	char dir;

	Nodo *aux = _buscaRemover((*raiz), chave, &dir);
	Nodo *aux_filho;

    if(aux != NULL){
        /*caso: folha*/
        if((aux->esq == NULL) && (aux->dir == NULL)){
            switch (dir) {
                case 'e':
                    aux->pai->esq = NULL;
                break;
                case 'd':
                    aux->pai->dir = NULL;
                break;
                case 'n':
                    (*raiz) = NULL;
                break;
            }
            free(aux);
        }
        /*caso: um filho na esquerda*/
        else if(aux->dir == NULL){
            switch (dir) {
                case 'e':
                    aux->pai->esq = aux->esq;
                break;
                case 'd':
                    aux->pai->dir = aux->esq;
                break;
                case 'n':
                    (*raiz) = aux->esq;
                break;
            }
            aux->esq->pai = aux->pai;
            free(aux);
        }
        /*caso: um filho na direita*/
        else if(aux->esq == NULL){
            switch (dir) {
                case 'e':
                    aux->pai->esq = aux->dir;
                break;
                case 'd':
                    aux->pai->dir = aux->dir;
                break;
                case 'n':
                    (*raiz) = aux->dir;
                break;
            }
            aux->dir->pai = aux->pai;
            free(aux);
        }
        /*caso: dois filhos*/
        else{
            //procurar antecessor
            aux_filho = aux->esq;
            while(aux_filho->dir != NULL)
                aux_filho = aux_filho->dir;

            //transplantar filhos do antecessor
            if(aux_filho->esq != NULL){
                aux_filho->pai->dir = aux_filho->esq;
                aux_filho->esq->pai = aux_filho->pai;
            }
            else
                aux_filho->pai->dir = NULL;

            //transplantar antecessor
            aux_filho->esq = aux->esq;
            aux->esq->pai = aux_filho;
            aux_filho->dir = aux->dir;
            aux->dir->pai = aux_filho;

            aux_filho->pai = aux->pai;

            switch (dir) {
                case 'e':
                    aux->pai->esq = aux_filho;
                break;
                case 'd':
                    aux->pai->dir = aux_filho;
                break;
                case 'n':
                    (*raiz) = aux_filho;
            }

            free(aux);
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
