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
void Somatorio(MATRIZ *MAT);
MATRIZ *SomaMatriz(MATRIZ *MAT, MATRIZ *MATB);
void RetiraMATRIZ(MATRIZ *MAT, MATRIZ *MATB);

int main()
{
    FILE *arq;

    MATRIZ Matriz, MatrizB;

    InicializaMATRIZ(&Matriz, 14, 14);
    InicializaMATRIZ(&MatrizB, 13, 13);

    arq = fopen("./dados.txt", "r");

    if (arq != NULL)
    {
        int n, nb, nc;
        fscanf(arq, "%d %d %d", &n, &nb, &nc);
        while (!feof(arq))
        {
            // printf("%d %d %d\n", n, nb, nc);
            AddValue(&Matriz, n, nb, nc);
            fscanf(arq, "%d %d %d", &n, &nb, &nc);
        }
        AddValue(&Matriz, n, nb, nc);
    }

    ValueSearch(&Matriz, 2, 8);
    ValueSearch(&Matriz, 1, 2);

    Multiplic(&Matriz, 2);

    //2 matriz

    FILE *arqB;

    arqB = fopen("./dadosB.txt", "r");

    if (arqB != NULL)
    {
        int nB, nbB, ncB;
        fscanf(arqB, "%d %d %d", &nB, &nbB, &ncB);
        while (!feof(arqB))
        {
            // printf("%d %d %d\n", n, nb, nc);
            AddValue(&MatrizB, nB, nbB, ncB);
            fscanf(arqB, "%d %d %d", &nB, &nbB, &ncB);
        }
        AddValue(&MatrizB, nB, nbB, ncB);
    }
    //-----------

    // MATRIZ *MatrizC;
    // MatrizC = SomaMatriz(&Matriz, &MatrizB);
    // printf("PONT");

    RetiraMATRIZ(&Matriz, &MatrizB);
    printf("\n------Matriz 1 ------");
    ImprimeAll(&Matriz);
    printf("\n------Matriz 2 ------");
    ImprimeAll(&MatrizB);
    Somatorio(&Matriz);

    return 1;
}

void InicializaMATRIZ(MATRIZ *MAT, int lin, int col)
{

    // MATRIZ *Aux;

    // Aux = MAT;

    // printf("check");
    MAT->row = lin;
    // printf("check");
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
        printf("\n VALOR procurado = %.2f valor\n", Atual->valor);
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

        while (Aux != NULL)
        {
            printf("\n%.2f -> [%d] [%d]", Aux->valor, r, Aux->colum);
            Aux = Aux->prox;
        }

        // printf("\n");
    }
}

void Multiplic(MATRIZ *MAT, int num)
{

    PONT Aux;

    for (int r = 0; r < MAT->row; r++)
    {
        Aux = MAT->Raiz[r];

        while (Aux != NULL)
        {
            Aux->valor *= num;
            Aux = Aux->prox;
        }
        // printf("\n");
    }
}

void Somatorio(MATRIZ *MAT)
{

    PONT Aux;
    float SOMA;

    for (int r = 0; r < MAT->row; r++)
    {
        Aux = MAT->Raiz[r];

        while (Aux != NULL)
        {
            SOMA += Aux->valor;
            Aux = Aux->prox;
        }
    }
    printf("\n Essa e a Somatoria de tudo na Matriz 1 = %.2f", SOMA);
}

MATRIZ *SomaMatriz(MATRIZ *MAT, MATRIZ *MATB)
{

    PONT AuxR, AuxC;
    PONT Aux_B, Aux_A;

    int r, c;
    if (MAT->row >= MATB->row)
    {
        AuxR = MAT->Raiz;
        r = MAT->row;
    }
    else
    {
        AuxR = MATB->Raiz;
        r = MATB->row;
    }
    if (MAT->colum >= MATB->colum)
    {
        AuxC = MAT->Raiz;
        c = MAT->colum;
    }
    else
    {
        AuxC = MATB->Raiz;
        c = MAT->colum;
    }

    MATRIZ MATaux;
    InicializaMATRIZ(&MATaux, r, c);

    //---------------------

    for (int rv = 0; rv < r; rv++)
    {
        Aux_A = MAT->Raiz[rv];
        Aux_B = MATB->Raiz[rv];
        float cont = 0;
        while (Aux_A != NULL && Aux_B != NULL)
        {
            if (Aux_A == NULL)
            {
                AddValue(&MATaux, rv, Aux_B->colum, Aux_A->valor);
            }
            if (Aux_B == NULL)
            {
                AddValue(&MATaux, rv, Aux_A->colum, Aux_B->valor);
            }
            if (Aux_A != NULL && Aux_B != NULL)
            {
                cont = Aux_A->valor + Aux_B->valor;
                // printf("aq %.2f", cont);
                AddValue(&MATaux, rv, Aux_A->colum, cont);
            }

            if (Aux_B != NULL)
            {
                Aux_B = Aux_B->prox;
            }
            if (Aux_A != NULL)
            {
                Aux_A = Aux_A->prox;
            }
        }
        // printf("aq");
    }
    return &MATaux;
}

void RetiraMATRIZ(MATRIZ *MAT, MATRIZ *MATB)
{
    PONT AuxR, AuxC;
    PONT Aux_A, Aux_B;

    int r;
    if (MAT->row >= MATB->row)
    {
        AuxR = MAT->Raiz;
        r = MAT->row;
    }
    else
    {
        AuxR = MATB->Raiz;
        r = MATB->row;
    }

    int c;

    if (MAT->colum >= MATB->colum)
    {
        AuxC = MAT->Raiz;
        c = MAT->colum;
    }
    else
    {
        AuxC = MATB->Raiz;
        c = MAT->colum;
    }

    for (int rv = 0; rv < r; rv++)
    {
        Aux_A = MAT->Raiz[rv];
        PONT antA = NULL;
        Aux_B = MATB->Raiz[rv];
        // PONT antB = NULL;

        // while (Aux_B != NULL && Aux_A != NULL)
        while (Aux_B != NULL && Aux_A != NULL)
        {
            while (Aux_A != NULL && Aux_A->colum != Aux_B->colum)
            {
                antA = Aux_A;
                Aux_A = Aux_A->prox;
            }
            if (Aux_A != NULL && Aux_B != NULL)
            {
                if (Aux_A->colum == Aux_B->colum) //dsdsds
                {
                    if (antA == NULL)
                    {
                        MAT->Raiz[rv] = Aux_A->prox;
                    }
                    else
                    {
                        antA->prox = Aux_A->prox;
                    }
                    // free(Aux_A);
                }
            }

            Aux_B = Aux_B->prox;
            Aux_A = MAT->Raiz[rv];
        }
    }
}