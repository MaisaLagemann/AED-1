#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct
{
    int origem, destino, peso;
} Aresta;

Aresta grafo[70];
int conjunto[250];

int comparar(Aresta *, Aresta *);
int encontrarComponente(int);
int executarKruskal(int);

int main(int argc, char **argv)
{
    int numVertices, numArestas, i;
    scanf("%d %d", &numVertices, &numArestas);

    for (i = 0; i < numArestas; ++i)
        scanf("%d %d %d", &grafo[i].origem, &grafo[i].destino, &grafo[i].peso);

    qsort(grafo, numArestas, sizeof(Aresta), comparar);

    for (i = 1; i <= numVertices; ++i)
        conjunto[i] = i;

    printf("%d\n", executarKruskal(numArestas));

    return 0;
}

int comparar(Aresta *a, Aresta *b)
{
    return a->peso - b->peso;
}

int encontrarComponente(int indice)
{
    if (indice == conjunto[indice])
        return indice;
    return encontrarComponente(conjunto[indice]);
}

int executarKruskal(int numArestas)
{
    int i, custoTotal, componenteOrigem, componenteDestino;

    for (i = 0, custoTotal = 0; i < numArestas; ++i)
    {
        componenteOrigem = encontrarComponente(grafo[i].origem);
        componenteDestino = encontrarComponente(grafo[i].destino);

        if (componenteOrigem != componenteDestino)
        {
            conjunto[componenteOrigem] = conjunto[componenteDestino];
            custoTotal += grafo[i].peso;
        }
    }

    return custoTotal;
}