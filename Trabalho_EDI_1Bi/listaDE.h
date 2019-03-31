#ifndef LISTADE_H_INCLUDED
#define LISTADE_H_INCLUDED

//#define MAX 100

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

ListaDE inicListaDE(void);
void anxListaDE(ListaDE lst, char elem[MAX]);
void insListaDE(ListaDE lst, char elem[MAX]);
void elimListaDE(ListaDE lst);
void primListaDE(ListaDE lst);
void ultListaDE(ListaDE lst);
void segListaDE(ListaDE lst);
void posListaDE(ListaDE lst, int pos);
char *infoListaDE(ListaDE lst);
int longListaDE(ListaDE lst);
int fimListaDE(ListaDE lst);
void printListaDE(ListaDE listaDE);

#endif // LISTADE_H_INCLUDED
