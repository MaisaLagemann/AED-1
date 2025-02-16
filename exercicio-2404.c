#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int origem, destino, peso;
} Aresta;

Aresta grafo[124760];
int conjunto[124750];

int compararArestas(Aresta *, Aresta *);
int encontrarComponente(int);
int kruskal(int);

int main()
{
    int numVertices, numArestas, i;

    scanf("%d %d", &numVertices, &numArestas);

    for (i = 0; i < numArestas; ++i)
        scanf("%d %d %d", &grafo[i].origem, &grafo[i].destino, &grafo[i].peso);

    qsort(grafo, numArestas, sizeof(Aresta), compararArestas);

    for (i = 1; i <= numVertices; ++i)
        conjunto[i] = i;

    printf("%d\n", kruskal(numArestas));

    return 0;
}

int compararArestas(Aresta *a, Aresta *b)
{
    return a->peso - b->peso;
}

int encontrarComponente(int vertice)
{
    if (vertice == conjunto[vertice])
        return vertice;

    return encontrarComponente(conjunto[vertice]);
}

int kruskal(int numArestas)
{
    int i, custoMinimo = 0, componenteOrigem, componenteDestino;

    for (i = 0; i < numArestas; ++i)
    {
        componenteOrigem = encontrarComponente(grafo[i].origem);
        componenteDestino = encontrarComponente(grafo[i].destino);

        if (componenteOrigem != componenteDestino)
        {
            conjunto[componenteDestino] = conjunto[componenteOrigem];
            custoMinimo += grafo[i].peso;
        }
    }

    return custoMinimo;
}
