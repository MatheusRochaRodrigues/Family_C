#ifndef LISTAENCADEADA_C
#define LISTAENCADEADA_C

#include<stdlib.h>
#include<stdio.h>
#include <time.h>

#include "ListaDUPLAMENTE_ENCADEADA.c"

struct ListaENCADEADA
{
    /* data */
    char Nome[30];
    struct ListaENCADEADADUPL *posicao;
    int pontos;
    struct ListaENCADEADA *prox;

};
typedef struct ListaENCADEADA ListaENC;

void insereFinalENC(ListaENC **list, ListaDUPL **ListDUP);
void ImprimeENC(ListaENC **list);
void retiraPorPosicao(ListaENC **list, ListaENC **jogador);


void insereFinalENC(ListaENC **list, ListaDUPL **ListDUP){
    ListaENC *Aux, *NovoNo;

    NovoNo = (ListaENC*)malloc(sizeof(ListaENC));

    scanf("%s", NovoNo->Nome);

   // printf("dasd %s", NovoNo->Nome);

    (NovoNo->prox = NULL);
    NovoNo->posicao = *ListDUP;
    NovoNo->pontos = (*ListDUP)->valor;
    

    if (*list == NULL)
    {
        /* code */
        *list = NovoNo;
        NovoNo->prox = *list;
        
    }else{
        /* code */
        Aux = *list;
        while(Aux->prox != *list){
            Aux = Aux->prox;
        }
        Aux->prox = NovoNo;
        NovoNo->prox = *list;
    }
    

}

void ImprimeENC(ListaENC **list){

    ListaENC *Aux;

    Aux = *list;

    //printf("SDASF %s",(*list)->prox->prox->prox->Nome);

    printf("\n");

    while(Aux->prox != *list){

        
        printf("%s \n", Aux->Nome);
        Aux = Aux->prox;
        
    }

    printf("%s \n", Aux->Nome);

}


void retiraPorPosicao(ListaENC **list, ListaENC **jogador){

    ListaENC *Aux;

    Aux = *list;

    while (Aux->prox != *jogador)
    {
        /* code */

        Aux = Aux->prox;

    }

    Aux->prox = (*jogador)->prox;

    free ((*jogador));
    

}

#endif
