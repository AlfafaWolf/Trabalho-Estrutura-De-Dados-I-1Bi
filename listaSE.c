#ifndef ListaSESE_H_INCLUDED
    #include "ListaSE.h"
#endif

//void anxListaSE(ListaSE lst, InfoRodovia elem);
//void insListaSE(ListaSE lst, InfoRodovia elem);
//void elimListaSE(ListaSE lst);
void primListaSE(ListaSE lst)
{
    lst->iterador = lst->primeiro;
}
void ultListaSE(ListaSE lst)
{
    lst->iterador = lst->ultimo;
}
void segListaSE(ListaSE lst)
{
    lst->iterador = lst->iterador->prox;
}
void posListaSE(ListaSE lst, int pos)
{
    // CASO A POSIÇCÃO FOR MAIOR QUE A LONGITUDE
    if(pos > lst->longitude || pos == 0)
    {
        lst->iterador = NULL;
        return;
    }

    int i;
    for(primListaSE(lst), i = 1; !fimListaSE(lst) && i < pos; segListaSE(lst), i++)
    {
    }
}
InfoRodovia infoListaSE(ListaSE lst)
{
    if(lst->iterador == NULL)
    {
        printf("ERRO, interador nao definido\n");
        exit(1);
    }
    return lst->iterador->info;
}
int longListaSE(ListaSE lst)
{
    if(lst->longitude < 0)
    {
        printf("ERRO, longitude negativa\n");
    }
    return lst->longitude;
}
int fimListaSE(ListaSE lst)
{
    if(lst->iterador == NULL)
        return 1;
    else
        return 0;
}
