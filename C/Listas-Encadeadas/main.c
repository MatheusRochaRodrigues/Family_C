#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#include "ListaENCADEADA.c"
#include "ListaDUPLAMENTE_ENCADEADA.c"

void procedimentoGAME(ListaENC **listJog, ListaENC **mainC);

int main(){    
   
    ListaENC *list;
    list = NULL;

    ListaDUPL *listDUPL;
    listDUPL = NULL;

    int T;

    
    printf("quantidade de posições no tabuleiro de 1 a 26(a ate z)\n");
    scanf("%d", &T);

    while (T > 26)
    {
        printf("quantidade de posições no tabuleiro de 1 a 26(a ate z)\n");
        scanf("%d", &T);
    }

    int i = 0;

    char c, limit;

    c = 'a';

    //scanf("%c", &c);

    limit = 'z';

   // for(; c <= limit; c++){
   //     printf("%c", c);
    //}
     
     while(i < T){
         int valor;
         printf("%c    ", c);
         scanf("%d", &valor);
         
         InsereInicioDUPL(&listDUPL, valor, c);
         c++;
         i++;

     }

     //ImprimeDUPL(&listDUPL);

    int N;

    int j = 0;

    printf("numero de jogadores ");
    scanf("%d", &N);

    printf("Nome dos joagadores:\n");


    while(j < N){
         //char Nome[30];
         
         //scanf("%s", &Nome);

         insereFinalENC(&list, &listDUPL);
         
         j++;

     }

     //ImprimeENC(&list);

    printf("COMEÇANDO O JOGO\n");

    ListaENC *listAUX;

    listAUX = list;

    while (list->prox != list)
    {
        /* code */
        while (listAUX->prox!= list)
        {
            /* code */

            procedimentoGAME(&listAUX, &list);
            
            listAUX = listAUX->prox;

        }

        listAUX = list;
        
    }
    
   

    return 1;
}

//void procedimentoGAME(ListaENC **list, ListaDUPL **area){
void procedimentoGAME(ListaENC **listJog, ListaENC **mainC){

    // list vai ser ja direto o jogador da partida e area vai ser direto a area da jogada ja de onde vai começar e acontecer e rolar tudo
    
    int salto = 1 + rand() % 6;
    int s;
    ListaDUPL *AuxArea;
    //AuxArea = *area;
    AuxArea = (*listJog)->posicao;


    for (s = 0; s < salto; s++){
        if((*listJog)->posicao->valor < 0){
            AuxArea = AuxArea->ant;
        }else
        {
            AuxArea = AuxArea->prox;
        }

    }

    (*listJog)->posicao = AuxArea;
    (*listJog)->pontos += AuxArea->valor;

    if((*listJog)->pontos <= 0){
        retiraPorPosicao(mainC , listJog);
    }

}
