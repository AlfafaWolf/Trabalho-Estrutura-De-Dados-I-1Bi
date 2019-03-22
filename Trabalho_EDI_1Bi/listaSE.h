#ifndef LISTASE_H_INCLUDED
#define LISTASE_H_INCLUDED

#define MAX 100

typedef struct TinfoRodovia{

    char rodovia[MAX];
    ListaDE cidades;
} InfoRodovia;

typedef struct ListaNoSE
{
    InfoRodovia info;
    struct ListaNoSE *prox;
} *pListaNoSE;

typedef struct TListaSE
{
    pListaNoSE primeiro, ultimo, iterador;
    int longitude;
} *ListaSE;

#endif // LISTASE_H_INCLUDED
