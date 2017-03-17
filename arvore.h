#ifndef _ARVORE

#define _ARVORE

#include <stdlib.h>

typedef struct _nodo Nodo;

typedef struct _nodo {
    Nodo *pai;
    Nodo *esq;
    Nodo *dir;

    long int chave;
    long int h;

} Nodo;


#endif
