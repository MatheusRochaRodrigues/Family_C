#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct tempNO
{

    float valor;
    int colum;
    struct tempNO *prox;

} NO;

typedef NO *PONT;

struct MAT
{
    PONT *Raiz;
    int row;
    int colum;
};
typedef struct MAT MATRIZ;

void InicializaMATRIZ(MATRIZ *MAT, int lin, int col);
bool AddValue(MATRIZ *MAT, int lin, int col, float value);
float ValueSearch(MATRIZ *MAT, int lin, int col);
void ImprimeAll(MATRIZ *MAT);
void Remove(MATRIZ *MAT, int lin, int col);
void Multiplic(MATRIZ *MAT, int num);

int main()
{

    MATRIZ Matriz;

    // MATRIZ **h = &Matriz;

    InicializaMATRIZ(&Matriz, 8, 8);
    // printf("check %f", Matriz->Raiz[0]);
    AddValue(&Matriz, 3, 3, 20);
    AddValue(&Matriz, 1, 3, 13);
    AddValue(&Matriz, 2, 3, 43);
    AddValue(&Matriz, 3, 3, 55);
    AddValue(&Matriz, 1, 1, 33);

    ValueSearch(&Matriz, 1, 3);

    ImprimeAll(&Matriz);

    return 1;
}

void InicializaMATRIZ(MATRIZ *MAT, int lin, int col)
{

    // MATRIZ *Aux;

    // Aux = MAT;

    printf("check");
    MAT->row = lin;
    printf("check");
    MAT->colum = col;

    MAT->Raiz = (PONT *)malloc(lin * sizeof(PONT));
    for (int i = 0; i < lin; i++)
    {
        MAT->Raiz[i] = NULL;
    }
}

bool AddValue(MATRIZ *MAT, int lin, int col, float value)
{

    if (lin < 0 || lin >= MAT->row || col < 0 || col >= MAT->colum)
    {
        return false;
    }

    PONT Ant = NULL;
    PONT Atual = MAT->Raiz[lin];

    while (Atual != NULL && Atual->colum < col)
    {
        Ant = Atual;
        Atual = Atual->prox;
    }

    if (Atual != NULL && Atual->colum == col)
    {
        if (value == 0)
        {
            if (Ant == NULL)
            {
                MAT->Raiz[lin] = Atual->prox;
            }
            else
            {
                Ant->prox = Atual->prox;
            }
            free(Atual);
        }
        else
        {
            Atual->valor = value;
        }
    }
    else
    {
        PONT New = (PONT)malloc(sizeof(NO));
        New->colum = col;
        New->valor = value;
        New->prox = Atual;

        if (Ant == NULL)
        {
            MAT->Raiz[lin] = New;
        }
        else
        {
            Ant->prox = New;
        }
    }
    return true;
}

float ValueSearch(MATRIZ *MAT, int lin, int col)
{

    PONT Atual = MAT->Raiz[lin];

    while (Atual != NULL && Atual->colum < col)
    {
        Atual = Atual->prox;
    }
    if (Atual != NULL && Atual->colum == col)
    {
        printf("\n\n %.2f valor\n", Atual->valor);
        return Atual->valor;
    }

    return 0;
}

void ImprimeAll(MATRIZ *MAT)
{

    PONT Aux;

    for (int r = 0; r < MAT->row; r++)
    {
        Aux = MAT->Raiz[r];
        if (MAT->Raiz[r] != NULL)
        {
            while (Aux != NULL)
            {
                printf("\n%.2f ", Aux->valor);
                Aux = Aux->prox;
            }

            // printf("\n");
        }
        else
        {
            // printf("\nNull");
        }
    }
}

void Multiplic(MATRIZ *MAT, int num)
{
}