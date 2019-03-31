#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#include "listaDE.c"
#include "listaSE.c"

void testListaDE();
void testListaSE();

int main()
{
    printf("Hello world!\n\n");

    testListaDE();
    testListaSE();

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
    printListaDE(listaDE);
    free(listaDE);
    printf("==============================================\n\n");
}

void testListaSE()
{
    printf("=============== TESTE LISTA_SE ===============\n");
    ListaSE listaSE = inicListaSE();

    // ANEXAR RODOVIAS E CIDADES
    InfoRodovia infoR1;
    strcpy(infoR1.rodovia, "BR101");
    infoR1.cidades = inicListaDE();
    anxListaDE(infoR1.cidades, "Viana");
    anxListaSE(listaSE, infoR1);

    InfoRodovia infoR2;
    strcpy(infoR2.rodovia, "BR166");
    infoR2.cidades = inicListaDE();
    anxListaDE(infoR2.cidades, "Guarapari");
    anxListaSE(listaSE, infoR2);

    InfoRodovia infoR3;
    strcpy(infoR3.rodovia, "BR107");
    infoR3.cidades = inicListaDE();
    anxListaSE(listaSE, infoR3);

    ListaDE listaCidades = listaSE->iterador->info.cidades;
    anxListaDE(listaCidades, "VIX");
    insListaDE(listaCidades, "Vila Velha");
    insListaDE(listaCidades, "Vitoria");

    // IMPRIMIR LISTAS
    printf("> Lista de Rodovias:\n");
    printListaSE(listaSE);

    printf("> Lista de Rodovias com o terceiro elemento eliminado:\n");
    primListaSE(listaSE); segListaSE(listaSE); elimListaSE(listaSE);
    printListaSE(listaSE);

    printf("> Lista de Rodovias com o cidades eliminadas:\n");
    primListaSE(listaSE); segListaSE(listaSE);
    listaCidades = listaSE->iterador->info.cidades;
    elimListaDE(listaCidades); //elimListaDE(listaCidades);
    printListaSE(listaSE);

    printf("> Lista de Rodovias eliminando e anexando/inserindo cidades:\n");
    primListaSE(listaSE);
    listaCidades = listaSE->iterador->info.cidades;
    primListaDE(listaCidades);
    elimListaDE(listaCidades); elimListaDE(listaCidades); segListaDE(listaCidades);
    anxListaDE(listaCidades, "ANX");
    insListaDE(listaCidades, "INS");
    printListaSE(listaSE);

    free(listaSE);
    printf("==============================================\n\n");
}
