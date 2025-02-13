#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No
{

    int valor;
    struct No *proximo;

} No;

typedef struct Pilha
{

    No *topo;

} Pilha;

void desempilhar(Pilha *pilha, int *cartasDescartadas);
void empilhar(Pilha *pilha, int valor);
void moverTopoParaBase(Pilha *pilha);
void inicializarPilha(Pilha *pilha);
void limparPilha(Pilha *pilha);
short totalDescartadas;

int main()
{

    unsigned short quantidadeCartas;
    Pilha baralho;
    short i;

    while (true)
    {

        scanf("%hu", &quantidadeCartas);

        if (quantidadeCartas == 0 || quantidadeCartas > 50)
            return 0;

        inicializarPilha(&baralho);
        int cartasDescartadas[quantidadeCartas];

        for (i = quantidadeCartas; i > 0; i--)
            empilhar(&baralho, i);

        totalDescartadas = 0;
        desempilhar(&baralho, cartasDescartadas);

        printf("Discarded cards:");
        for (i = 0; i < totalDescartadas; i++)
        {

            printf(" %d", cartasDescartadas[i]);
            if (i != totalDescartadas - 1)
                printf(",");
        }

        printf("\nRemaining card: %d\n", baralho.topo->valor);
        limparPilha(&baralho);
    }
}

void inicializarPilha(Pilha *pilha)
{

    pilha->topo = NULL;
}

void empilhar(Pilha *pilha, int valor)
{

    No *novoNo;

    novoNo = (No *)malloc(sizeof(No));

    if (!novoNo)
        exit(1);

    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
    novoNo->valor = valor;
}

void desempilhar(Pilha *pilha, int *cartasDescartadas)
{

    No *temporario;

    if (pilha->topo)
    {

        if (!pilha->topo->proximo)
            return;

        do
        {

            temporario = pilha->topo;
            cartasDescartadas[totalDescartadas++] = temporario->valor;
            pilha->topo = pilha->topo->proximo;
            free(temporario);
            moverTopoParaBase(pilha);

        } while (pilha->topo->proximo);
    }
}

void moverTopoParaBase(Pilha *pilha)
{

    No *temporario, *ultimo;

    ultimo = pilha->topo;
    temporario = pilha->topo;

    if (ultimo->proximo)
    {

        while (ultimo->proximo)
            ultimo = ultimo->proximo;

        pilha->topo = pilha->topo->proximo;
        temporario->proximo = ultimo->proximo;
        ultimo->proximo = temporario;
    }
}

void limparPilha(Pilha *pilha)
{

    No *temporario;

    temporario = pilha->topo;
    pilha->topo = NULL;
    free(temporario);
}
