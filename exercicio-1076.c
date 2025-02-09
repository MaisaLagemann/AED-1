#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0
#define TAMANHO_MAXIMO 110

int visitado[TAMANHO_MAXIMO];
char grafo[TAMANHO_MAXIMO][TAMANHO_MAXIMO];

int totalVertices, resultado;
void buscaProfundidade(int);

int main()
{
    int numTestes, numArestas;
    int verticeInicial, numConsultas;
    int origem, destino, i;

    scanf("%d", &numTestes);

    while (numTestes--)
    {
        scanf("%d", &numConsultas);
        scanf("%d %d", &totalVertices, &numArestas);

        memset(visitado, 0, sizeof(visitado));
        memset(grafo, 0, sizeof(grafo));

        for (i = 0; i < numArestas; ++i)
        {
            scanf("%d %d", &origem, &destino);
            grafo[origem][destino] = grafo[destino][origem] = VERDADEIRO;
        }

        resultado = 0;
        buscaProfundidade(numConsultas);
        printf("%d\n", resultado << 1);
    }

    return 0;
}

void buscaProfundidade(int vertice)
{
    int i;
    visitado[vertice] = VERDADEIRO;

    for (i = 0; i < totalVertices; ++i)
    {
        if (grafo[vertice][i] && !visitado[i])
        {
            buscaProfundidade(i);
            resultado++;
        }
    }
}