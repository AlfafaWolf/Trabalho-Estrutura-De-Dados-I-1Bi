#ifndef LISTASE_H_INCLUDED
#define LISTASE_H_INCLUDED

//#define MAX 100

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

ListaSE inicListaSE(void);
void anxListaSE(ListaSE lst, InfoRodovia elem);
void insListaSE(ListaSE lst, InfoRodovia elem);
void elimListaSE(ListaSE lst);
void primListaSE(ListaSE lst);
void ultListaSE(ListaSE lst);
void segListaSE(ListaSE lst);
void posListaSE(ListaSE lst, int pos);
InfoRodovia infoListaSE(ListaSE lst);
int longListaSE(ListaSE lst);
int fimListaSE(ListaSE lst);
void printListaSE(ListaSE listaSE);

#endif // LISTASE_H_INCLUDED
