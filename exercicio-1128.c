#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0
#define TAMANHO_MAXIMO 2010

char visitado[TAMANHO_MAXIMO];
char grafo[TAMANHO_MAXIMO][TAMANHO_MAXIMO];

int totalVertices;
void buscaProfundidade(int);

int main()
{
    int totalArestas, origem, destino, direcao, i, j;

    while (scanf("%d %d", &totalVertices, &totalArestas), totalArestas && totalVertices)
    {
        memset(grafo, 0, sizeof(grafo));

        for (i = 0; i < totalArestas; ++i)
        {
            scanf("%d %d %d", &origem, &destino, &direcao);

            if (direcao == 1)
                grafo[origem][destino] = VERDADEIRO;
            else
                grafo[origem][destino] = grafo[destino][origem] = VERDADEIRO;
        }

        _Bool conexaoQuebrada = FALSO;
        for (i = 1; i <= totalVertices; ++i)
        {
            memset(visitado, 0, sizeof(visitado));
            buscaProfundidade(i);
            conexaoQuebrada = FALSO;

            for (j = 1; j < totalVertices && !conexaoQuebrada; ++j)
                if (!visitado[j])
                    conexaoQuebrada = VERDADEIRO;

            if (conexaoQuebrada)
                break;
        }

        printf("%d\n", conexaoQuebrada ? 0 : 1);
    }

    return 0;
}

void buscaProfundidade(int vertice)
{
    int i;
    visitado[vertice] = VERDADEIRO;

    for (i = 1; i <= totalVertices; ++i)
        if (grafo[vertice][i] && !visitado[i])
            buscaProfundidade(i);
}