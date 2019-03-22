#ifndef LISTADE_H_INCLUDED
    #include "listaDE.h"
#endif

//void anxListaDE(ListaDE lst, char elem[MAX]);
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
    // CASO A POSIÇCÃO FOR MAIOR QUE A LONGITUDE
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
