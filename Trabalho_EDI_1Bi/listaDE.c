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
void insListaDE(ListaDE lst, char elem[MAX])
{
    pListaNoDE novaCidade;
    novaCidade = (pListaNoDE) malloc(sizeof(struct ListaNoDE));
    strcpy(novaCidade->info, elem);
    novaCidade->ant = NULL;
    novaCidade->prox = NULL;
    if(lst->longitude == 0)
    {
        lst->primeiro = novaCidade;
        lst->iterador = novaCidade;
        lst->ultimo = novaCidade;
        lst->longitude++;
    }
    else if(lst->iterador == lst->primeiro)
    {
        novaCidade->prox = lst->iterador;
        lst->iterador->ant = novaCidade;
        lst->iterador = novaCidade;
        lst->primeiro = novaCidade;
        lst->longitude++;
    }
    else
    {
        novaCidade->prox = lst->iterador;
        novaCidade->ant = lst->iterador->ant;
        lst->iterador->ant = novaCidade;
        novaCidade->ant->prox = novaCidade;
        lst->iterador = novaCidade;
        lst->longitude++;
    }
}
void elimListaDE(ListaDE lst)
{
    if(lst->longitude == 0)
    {
        printf("ERRO! a lista esta vazia");
    }
    else if(lst->longitude == 1)
    {
        lst->longitude = 0;
        lst->iterador = NULL;
        lst->primeiro = NULL;
        lst->ultimo = NULL;
        free(lst->iterador);
    }
    else
    {
        if(lst->iterador == lst->primeiro)
        {
            lst->primeiro = lst->iterador->prox;
            lst->iterador = lst->primeiro;
            lst->longitude--;
            free(lst->primeiro->ant);
            lst->primeiro->ant = NULL;
        }
        else if(lst->iterador == lst->ultimo)
        {
            lst->ultimo = lst->iterador->ant;
            lst->iterador = lst->ultimo;
            lst->longitude--;
            free(lst->ultimo->prox);
            lst->ultimo->prox = NULL;
        }
        else
        {
            lst->iterador->ant->prox = lst->iterador->prox;
            lst->iterador->prox->ant = lst->iterador->ant;
            lst->iterador = lst->iterador->prox;
            lst->longitude--;
        }
    }

}
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
void printListaDE(ListaDE listaDE)
{
    printf("{|");
    for(primListaDE(listaDE); !fimListaDE(listaDE); segListaDE(listaDE))
    {
        printf(" %s |", listaDE->iterador->info);
    }
    printf("}\n");
}
