#include <stdio.h>
#include <stdlib.h>

#define VERDADEIRO 1
#define FALSO 0

typedef struct Nodo
{
    unsigned valor;
    struct Nodo *direita;
    struct Nodo *esquerda;
} Nodo;

void percorrerBFS(Nodo *);
Nodo *inserirNodo(Nodo *, unsigned);

unsigned totalNodos;

int main()
{
    unsigned i, valorLido, totalValores;
    unsigned totalCasos, casoAtual;

    scanf("%u", &totalCasos);

    casoAtual = 0;
    while (totalCasos--)
    {
        scanf("%u", &totalValores);

        totalNodos = 0;
        Nodo *raiz = NULL;
        for (i = 0; i < totalValores; ++i)
        {
            scanf("%u", &valorLido);
            raiz = inserirNodo(raiz, valorLido);
            ++totalNodos;
        }

        printf("Case %u:\n", ++casoAtual);
        percorrerBFS(raiz);
        printf("\n\n");
    }

    return 0;
}

Nodo *inserirNodo(Nodo *raiz, unsigned valor)
{
    if (!raiz)
    {
        raiz = (Nodo *)malloc(sizeof(Nodo));
        raiz->valor = valor;
        raiz->esquerda = raiz->direita = NULL;
    }
    else if (raiz->valor > valor)
    {
        raiz->esquerda = inserirNodo(raiz->esquerda, valor);
    }
    else
    {
        raiz->direita = inserirNodo(raiz->direita, valor);
    }

    return raiz;
}

void percorrerBFS(Nodo *raiz)
{
    Nodo *fila;
    unsigned inicio, fim;
    _Bool primeiroElemento = FALSO;

    fila = (Nodo *)malloc(totalNodos * sizeof(Nodo));
    fila[0] = *raiz;
    inicio = 0;
    fim = 1;

    while (fim > inicio)
    {
        *raiz = fila[inicio++];
        if (!primeiroElemento)
        {
            printf("%u", raiz->valor);
            primeiroElemento = VERDADEIRO;
        }
        else
        {
            printf(" %u", raiz->valor);
        }

        if (raiz->esquerda)
        {
            fila[fim++] = *raiz->esquerda;
        }
        if (raiz->direita)
        {
            fila[fim++] = *raiz->direita;
        }
    }

    free(fila);
}
