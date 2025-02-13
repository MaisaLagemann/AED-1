#include <stdio.h>
#include <stdlib.h>

typedef struct NoArv
{
    int numero;
    struct NoArv *esquerda;
    struct NoArv *direita;
} NoArv;

NoArv *insere(NoArv *arvore, int numero);
void mostrarPreOrdem(NoArv *arvore);
void mostrarInOrdem(NoArv *arvore);
void mostrarPosOrdem(NoArv *arvore);
void liberarArvore(NoArv *arvore);

int main()
{
    unsigned short i;
    int numero;
    unsigned short qtsNos, qtsCasos, caso = 0;

    scanf("%hu", &qtsCasos);

    while (qtsCasos--)
    {
        NoArv *arvore = NULL;
        scanf("%hu", &qtsNos);

        for (i = 0; i < qtsNos; i++)
        {
            scanf("%d", &numero);
            arvore = insere(arvore, numero);
        }

        printf("Case %hu:\n", ++caso);

        printf("Pre.:");
        mostrarPreOrdem(arvore);
        printf("\n");

        printf("In..:");
        mostrarInOrdem(arvore);
        printf("\n");

        printf("Post:");
        mostrarPosOrdem(arvore);
        printf("\n\n");

        liberarArvore(arvore);
    }

    return 0;
}

NoArv *insere(NoArv *arvore, int numero)
{
    if (!arvore)
    {
        arvore = (NoArv *)malloc(sizeof(NoArv));
        if (!arvore)
        {
            fprintf(stderr, "Erro de alocação de memória.\n");
            exit(EXIT_FAILURE);
        }
        arvore->numero = numero;
        arvore->esquerda = arvore->direita = NULL;
    }
    else if (numero < arvore->numero)
    {
        arvore->esquerda = insere(arvore->esquerda, numero);
    }
    else
    {
        arvore->direita = insere(arvore->direita, numero);
    }
    return arvore;
}

void mostrarPreOrdem(NoArv *arvore)
{
    if (arvore)
    {
        printf(" %d", arvore->numero);
        mostrarPreOrdem(arvore->esquerda);
        mostrarPreOrdem(arvore->direita);
    }
}

void mostrarInOrdem(NoArv *arvore)
{
    if (arvore)
    {
        mostrarInOrdem(arvore->esquerda);
        printf(" %d", arvore->numero);
        mostrarInOrdem(arvore->direita);
    }
}

void mostrarPosOrdem(NoArv *arvore)
{
    if (arvore)
    {
        mostrarPosOrdem(arvore->esquerda);
        mostrarPosOrdem(arvore->direita);
        printf(" %d", arvore->numero);
    }
}

void liberarArvore(NoArv *arvore)
{
    if (arvore)
    {
        liberarArvore(arvore->esquerda);
        liberarArvore(arvore->direita);
        free(arvore);
    }
}
