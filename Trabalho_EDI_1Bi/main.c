#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#include "listaDE.c"
#include "listaSE.c"

void testListaDE();
void testListaSE();
ListaSE LerDados(char* nomeArquivoRodovia, char* nomeArquivoCidades);
ListaSE rodoviasCidade(char* nomeCidade, ListaSE lstRodovia);

int main()
{
    // TESTES
    //testListaDE();
    //testListaSE();

    // ARQUIVO
    ListaSE lstSE = LerDados("listaRodovias.txt", "listaCidades.txt");
    printf("\nListaSE:\n");
    printListaSE(lstSE);
    ListaSE lstvix;
    lstvix = rodoviasCidade("vix", lstSE);
    printf("Rodovias que passam por vix: \n\n");
    printListaSE(lstvix);
    return 0;
}

ListaSE LerDados(char* nomeArquivoRodovia, char* nomeArquivoCidades)
{
    ListaSE lstRodovias = inicListaSE();
    int i;
    char CR, CC; // CR = char Rodovia | CC = char Cidade
    char auxiliar[MAX];
    FILE *arquivoRodovia;
    arquivoRodovia = fopen(nomeArquivoRodovia, "r");
    if(arquivoRodovia == 0)
    {
        printf("Erro ao tentar abrir o arquivo de Rodovias\n");
        fclose(arquivoRodovia);
    }
    else
    {
        int j;
        FILE* arquivoCidade;
        arquivoCidade = fopen(nomeArquivoCidades, "r");
        if(arquivoCidade == 0)
        {
            printf("Erro ao tentar abrir o arquivo de Cidades\n");
            fclose(arquivoCidade);
        }
        else
        {
            i = 0;
            do
            {
                CR = getc(arquivoRodovia);
                // CASO FOR UMA LETRA
                if(CR != '\n' && CR != EOF)
                {
                    auxiliar[i] = CR;
                    i++;
                }
                else
                {
                    auxiliar[i] = '\0';
                    // IMPEDIR LINHAS VAZIAS NO ARQUIVO DA CIDADE
                    if(auxiliar[0] != '\0')
                    {
                        printf("> %s\n", auxiliar); // DEBUG RODOVIA //

                        // CRIAR INFO RODOVIA E ADICIONAR INFO NO NÓ DA RODOVIA ATUAL
                        InfoRodovia infoRodovia;
                        infoRodovia.cidades = inicListaDE();   // INICIAR LISTA
                        strcpy(infoRodovia.rodovia, auxiliar); // ADICIONAR O NOME DA RODOVIA
                        anxListaSE(lstRodovias, infoRodovia);  // ANEXAR INFO RODOVIA
                        ultListaSE(lstRodovias);

                        // ANEXAR CIDADES NA RODOVIA
                        ListaDE lstCidades = infoRodovia.cidades;
                        j = 0;
                        do
                        {
                            CC = getc(arquivoCidade);
                            // CASO FOR UMA LETRA
                            if(CC != '\n' && CC != EOF && CC != ' ')
                            {
                                auxiliar[j] = CC;
                                j++;
                            }
                            else
                            {
                                auxiliar[j] = '\0';
                                if(auxiliar[0] != '\0')
                                {
                                    printf("\t%s\n", auxiliar); // DEBUG CIDADE //

                                    // ANEXAR CIDADE E DEIXAR O ITERADOR NO ULTIMO ELEMENTO
                                    anxListaDE(lstCidades, auxiliar);
                                    ultListaDE(lstCidades);
                                }
                                j = 0;
                            }
                        }while(CC != '\n' && CC != EOF); // CIDADES //
                    }
                    i = 0;
                }
            }while(CR != EOF); // RODOVIAS //

            // FECHAR ARQUIVOS
            fclose(arquivoRodovia);
            fclose(arquivoCidade);
        }
    }
    return lstRodovias;
}

ListaSE rodoviasCidade(char* nomeCidade, ListaSE lstRodovia)
{
    ListaSE rodovias = NULL;
    rodovias = inicListaSE();
    for(primListaSE(lstRodovia); !fimListaSE(lstRodovia); segListaSE(lstRodovia))
    {
        for(primListaDE(lstRodovia->iterador->info.cidades); !fimListaDE(lstRodovia->iterador->info.cidades); segListaDE(lstRodovia->iterador->info.cidades))
        {
            if(strcmp(nomeCidade, lstRodovia->iterador->info.cidades->iterador->info) == 0)
            {
                anxListaSE(rodovias, lstRodovia->iterador->info);
                break;
            }
        }
    }
    return rodovias;
}

void testListaDE()
{
    printf("=============== TESTE LISTA_DE ===============\n");
    ListaDE listaDE = inicListaDE();
    anxListaDE(listaDE,"Cidade 1"); ultListaDE(listaDE);
    anxListaDE(listaDE,"Cidade 2"); ultListaDE(listaDE);
    anxListaDE(listaDE,"Cidade 3"); ultListaDE(listaDE);

    printf("> Lista de Cidades:\n");
    printListaDE(listaDE);

    printf("\n> Inserindo Cidade:\n");
    primListaDE(listaDE);
    insListaDE(listaDE, "INS - Com Iterador no Prim");

    ultListaDE(listaDE);
    insListaDE(listaDE, "INS - Com Iterador no Ult");

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

    printf("> Lista de Rodovias com o segundo elemento eliminado:\n");
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

    // INSERINDO CIDADES
    printf("> Inserindo Cidades:\n");
    ListaSE listaSE_2 = inicListaSE();

    InfoRodovia infoRod1;
    strcpy(infoRod1.rodovia, "INS_1");
    infoRod1.cidades = inicListaDE();

    InfoRodovia infoRod2;
    strcpy(infoRod2.rodovia, "INS_2");
    infoRod2.cidades = inicListaDE();

    InfoRodovia infoRod3;
    strcpy(infoRod3.rodovia, "INS_3");
    infoRod3.cidades = inicListaDE();

    insListaSE(listaSE_2, infoRod1);
    insListaSE(listaSE_2, infoRod2);
    insListaSE(listaSE_2, infoRod3);

    printListaSE(listaSE_2);

    // FREE
    free(listaSE_2);
    free(listaSE);
    printf("==============================================\n\n");
}
