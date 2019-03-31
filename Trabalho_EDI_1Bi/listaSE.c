#ifndef LISTASE_H_INCLUDED
    #include "listaSE.h"
#endif

ListaSE inicListaSE(void)
{
    // ALOCAR
    ListaSE lst = NULL;
    lst = (ListaSE) malloc(sizeof(struct TListaSE));
    if(lst == NULL)
    {
        printf("ERRO, nao foi possivel alocar a ListaSE\n");
        exit(1);
    }

    // VALORES INICIAIS
    lst->iterador  = NULL;
    lst->longitude = 0;
    lst->primeiro  = NULL;
    lst->ultimo    = NULL;

    return lst;
}
void anxListaSE(ListaSE lst, InfoRodovia elem)
{
    // CASO O INTERADOR FOR NULO
    if(lst->iterador == NULL && longListaSE(lst) > 0)
    {
        printf("ERRO, interador nao definido, nao foi possivel anexar elemento\n");
        return;
    }

    // ALOCAR
    pListaNoSE pLstNo = NULL;
    pLstNo = (pListaNoSE) malloc(sizeof(struct ListaNoSE));
    if(pLstNo == NULL)
    {
        printf("ERRO, nao foi possivel alocar o elemento\n");
        exit(1);
    }

    // VALORES INICIAIS
    strcpy(pLstNo->info.rodovia, elem.rodovia);
    pLstNo->info.cidades = elem.cidades;
    pLstNo->prox = NULL;

    // CASO A LISTA SEJA VAZIA
    if(longListaSE(lst) == 0)
    {
        lst->iterador = pLstNo;
        lst->primeiro = pLstNo;
        lst->ultimo   = pLstNo;
    }
    else
    {
        // CASO NÃO
        pLstNo->prox = lst->iterador->prox;
        lst->iterador->prox = pLstNo;
    }
    lst->longitude++;

    // CASO O NOVO BLOCO FOR O ÚLTIMO DA LISTA
    if(pLstNo->prox == NULL)
    {
        lst->ultimo = pLstNo;
    }
}
//void insListaSE(ListaSE lst, InfoRodovia elem);
void elimListaSE(ListaSE lst)
{
    if(lst->iterador == NULL)
    {
        printf("\nERRO. Interador indefinido, nao eh possivel eliminar da ListaSE\n\n");
        return;
    }
    else if(longListaSE(lst) == 0)
    {
        printf("\nERRO. Lista Vazia, nao eh possivel eliminar mais elementos.\n\n");
        return;
    }
    else if(longListaSE(lst) == 1)
    {
        pListaNoSE elim = lst->iterador;
        lst->iterador = NULL;
        lst->primeiro = NULL;
        lst->ultimo   = NULL;
        free(elim);
    }
    else
    {
        pListaNoSE elim = lst->iterador;
        if(lst->iterador == lst->primeiro)
        {
            lst->primeiro = lst->iterador->prox;
        }
        else if(lst->iterador == lst->ultimo)
        {
            for(primListaSE(lst); lst->iterador->prox != lst->ultimo; segListaSE(lst))
            {
            }
            lst->ultimo = lst->iterador;
            lst->iterador->prox = NULL;
        }
        else
        {
            for(primListaSE(lst); lst->iterador->prox != elim; segListaSE(lst))
            {
            }
            lst->iterador->prox = elim->prox;
        }
        segListaSE(lst);
        free(elim);
    }
    lst->longitude--;
}
void primListaSE(ListaSE lst)
{
    if(lst == NULL)
    {
        printf("ERRO. Iterador indefinido.");
        return;
    }
    lst->iterador = lst->primeiro;
}
void ultListaSE(ListaSE lst)
{
    if(lst == NULL)
    {
        printf("ERRO. Iterador indefinido.");
        return;
    }
    lst->iterador = lst->ultimo;
}
void segListaSE(ListaSE lst)
{
    if(lst == NULL)
    {
        printf("ERRO. Iterador indefinido.");
        return;
    }
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
void printListaSE(ListaSE listaSE)
{
    printf("{\n");
    for(primListaSE(listaSE); !fimListaSE(listaSE); segListaSE(listaSE))
    {
        printf("  %s ", listaSE->iterador->info.rodovia);
        printf(": ");

        printListaDE(listaSE->iterador->info.cidades);
    }
    printf("}\n\n");
}
