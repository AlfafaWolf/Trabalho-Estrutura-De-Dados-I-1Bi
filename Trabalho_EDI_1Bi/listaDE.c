#ifndef LISTADE_H_INCLUDED
    #include "listaDE.h"
#endif

ListaDE inicListaDE(void)
{
    ListaDE lst = NULL;
    lst = (ListaDE) malloc(sizeof(struct TListaDE));
    if(lst == NULL)
    {
        printf("ERRO, nao foi possivel alocar a ListaDE\n");
        exit(1);
    }

    // VALORES INICIAIS
    lst->iterador  = NULL;
    lst->longitude = 0;
    lst->primeiro  = NULL;
    lst->ultimo    = NULL;

    return lst;
}
void anxListaDE(ListaDE lst, char elem[MAX])
{
    pListaNoDE novaCidade;
    novaCidade = (pListaNoDE) malloc(sizeof(struct ListaNoDE));
    if(novaCidade == NULL)
    {
        printf("ERRO, nao foi possivel alocar pListaNoDE\n");
        exit(1);
    }

    strcpy(novaCidade->info, elem);
    novaCidade->ant = NULL;
    novaCidade->prox = NULL;

    if(lst->longitude == 0)
    {
        lst->iterador = novaCidade;
        lst->primeiro = novaCidade;
        lst->ultimo = novaCidade;
        lst->longitude++;
    }
    else if(lst->iterador == lst->ultimo)
    {
        lst->iterador->prox = novaCidade;
        novaCidade->ant = lst->iterador;
        lst->ultimo = novaCidade;
        lst->longitude++;
    }
    else
    {
        novaCidade->prox = lst->iterador->prox;
        novaCidade->ant = lst->iterador;
        lst->iterador->prox->ant = novaCidade;
        lst->iterador->prox = novaCidade;
        lst->longitude++;
    }
}
//void insListaDE(ListaDE lst, char elem[MAX]);
//void elimListaDE(ListaDE lst);
void primListaDE(ListaDE lst)
{
    lst->iterador = lst->primeiro;
}
void ultListaDE(ListaDE lst)
{
    lst->iterador = lst->primeiro;
}
void segListaDE(ListaDE lst)
{
    lst->iterador = lst->iterador->prox;
}
void posListaDE(ListaDE lst, int pos)
{
    // CASO A POSI�C�O FOR MAIOR QUE A LONGITUDE
    if(pos > lst->longitude || pos == 0)
    {
        lst->iterador = NULL;
        return;
    }

    int i;
    for(primListaDE(lst), i = 1; !fimListaDE(lst) && i < pos; segListaDE(lst), i++)
    {
    }
}
char *infoListaDE(ListaDE lst)
{
    if(lst->iterador == NULL)
    {
        printf("ERRO, interador nao definido\n");
        exit(1);
    }
    return lst->iterador->info;
}
int longListaDE(ListaDE lst)
{
    if(lst->longitude < 0)
    {
        printf("ERRO, longitude negativa\n");
    }
    return lst->longitude;
}
int fimListaDE(ListaDE lst)
{
    if(lst->iterador == NULL)
        return 1;
    else
        return 0;
}
void printListaDE(ListaDE listaDE)
{
    printf("{|");
    for(primListaDE(listaDE); !fimListaDE(listaDE); segListaDE(listaDE))
    {
        printf(" %s |", listaDE->iterador->info);
    }
    printf("}\n");
}
