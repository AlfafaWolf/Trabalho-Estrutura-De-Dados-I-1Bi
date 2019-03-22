#ifndef LISTADE_H_INCLUDED
#define LISTADE_H_INCLUDED

#define MAX 100

typedef struct ListaNoDE
{
    char info[MAX];
    struct ListaNoDE *ant, *prox;
} *pListaNoDE;

typedef struct TListaDE
{
    pListaNoDE primeiro, ultimo, iterador;
    int longitude;
} *ListaDE;

#endif // LISTADE_H_INCLUDED
