#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#include "listaDE.c"
#include "listaSE.c"

void testListaDE();
int main()
{
    printf("Hello world!\n\n");

    testListaDE();

    return 0;
}

void testListaDE()
{
    printf("=============== TESTE LISTA_DE ===============\n");
    ListaDE listaDE = inicListaDE();
    anxListaDE(listaDE,"Cidade 1");
    anxListaDE(listaDE,"Cidade 2");
    anxListaDE(listaDE,"Cidade 3");

    printf("> Lista de Cidades:\n");
    printf("[|");
    for(primListaDE(listaDE); !fimListaDE(listaDE); segListaDE(listaDE))
    {
        printf(" %s |", listaDE->iterador->info);
    }
    printf("]\n");
    free(listaDE);
    printf("==============================================\n");
}
