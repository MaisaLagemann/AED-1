#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAMANHO_MAX 600
#define INFINITO 0x3f3f3f3f

int matrizAdj[TAMANHO_MAX][TAMANHO_MAX];

void dijkstra(int, int, int);

int main(int argc, char **argv)
{
    int origem, destino, peso;
    int numVertices, numArestas, i, j, numConsultas;

    while (scanf("%d %d", &numVertices, &numArestas), numVertices || numArestas)
    {
        for (i = 0; i <= numVertices; ++i)
            for (j = 0; j <= numVertices; ++j)
                matrizAdj[i][j] = INFINITO;

        for (i = 0; i < numArestas; ++i)
        {
            scanf("%d %d %d", &origem, &destino, &peso);

            if (matrizAdj[destino][origem] != INFINITO)
                matrizAdj[origem][destino] = matrizAdj[destino][origem] = 0;
            else
                matrizAdj[origem][destino] = peso;
        }

        scanf("%d", &numConsultas);
        while (numConsultas--)
        {
            scanf("%d %d", &origem, &destino);
            dijkstra(numVertices, origem, destino);
        }

        putchar_unlocked('\n');
    }

    return 0;
}

void dijkstra(int numVertices, int inicio, int fim)
{
    int i, j;
    int visitado[numVertices + 1];
    int distancia[numVertices + 1];

    memset(visitado, false, sizeof(visitado));

    for (i = 0; i <= numVertices; ++i)
        distancia[i] = INFINITO;

    distancia[inicio] = 0;
    for (i = 0; i <= numVertices; ++i)
    {
        int menorDist = -1;
        for (j = 0; j <= numVertices; ++j)
            if (!visitado[j] && (menorDist == -1 || distancia[j] < distancia[menorDist]))
                menorDist = j;

        if (distancia[menorDist] == INFINITO)
            break;

        visitado[menorDist] = true;
        for (j = 0; j <= numVertices; ++j)
            if (distancia[menorDist] + matrizAdj[menorDist][j] < distancia[j])
                distancia[j] = matrizAdj[menorDist][j] + distancia[menorDist];
    }

    if (distancia[fim] < INFINITO)
        printf("%d\n", distancia[fim]);
    else
        puts("Nao e possivel entregar a carta");
}
