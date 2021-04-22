#ifndef LISTADUPLAMENTE_ENCADEADA_C
#define LISTADUPLAMENTE_ENCADEADA_C

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct ListaENCADEADADUPL
{
    /* data */
    int valor;
    char id;
    struct ListaENCADEADADUPL *prox;
    struct ListaENCADEADADUPL *ant;

};
typedef struct ListaENCADEADADUPL ListaDUPL;

void insereFinalDUPL(ListaDUPL **list, int valor);
void ImprimeDUPL(ListaDUPL **list);
void InsereInicioDUPL(ListaDUPL **list, int valor, char idd);


void InsereInicioDUPL(ListaDUPL **list, int valor, char idd){
    ListaDUPL *NovoNo, *Aux;
    NovoNo = (ListaDUPL*)malloc(sizeof(ListaDUPL));
    NovoNo->prox = NULL;
    NovoNo->ant = NULL;
    NovoNo->valor = valor;
    NovoNo->id = idd;

    if (*list != NULL)
    {
        Aux = *list;
        while (Aux->prox != *list)
        {
            Aux = Aux->prox;
        }

        Aux->prox = NovoNo;
        NovoNo->ant = Aux;
        NovoNo->prox = *list;
        (*list)->ant = NovoNo;

    }else{
        *list = NovoNo;
        NovoNo->ant = *list;
        NovoNo->prox = *list;
    }

    //tentar n utilizar uuxiliar dps ja q é encadeada
    
}




void ImprimeDUPL(ListaDUPL **list){

    ListaDUPL *Aux;
    Aux = *list;

    while(Aux->prox != *list){
        
        printf("%c - %d ", Aux->id, Aux->valor);
        Aux = Aux->prox;
        
    }

        printf("%c - %d ", Aux->id, Aux->valor);

}

#endif
