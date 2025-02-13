#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LOG_MAX 18
#define TAMANHO_MAX 100005
#define INFINITO 0x3f3f3f3fLLU

typedef long long ll;

typedef struct No
{
    int destino, peso;
    struct No *proximo;
} No;

typedef struct Grafo
{
    No *adjacente;
} Grafo;

int numVertices;

ll distancia[TAMANHO_MAX];
int profundidade[TAMANHO_MAX];
int ancestral[TAMANHO_MAX][LOG_MAX];

Grafo *criarGrafo(int);
No *criarNo(int, int);
void adicionarAresta(Grafo *, int, int, int);

void preprocessamento();
void buscaProfundidade(int, Grafo *);
int encontrarLCA(int, int);
void trocar(int *, int *);

int main(int argc, char **argv)
{
    int origem, destino, peso, consultas;

    while (scanf("%d%*c", &numVertices), numVertices)
    {
        Grafo *grafo = criarGrafo(numVertices + 1);

        for (int origem = 1; origem < numVertices; ++origem)
        {
            scanf("%d %d", &destino, &peso);
            if (origem < destino)
                adicionarAresta(grafo, destino, origem, peso);
            else
                adicionarAresta(grafo, origem, destino, peso);
        }

        for (int i = 0; i <= numVertices; ++i)
            distancia[i] = profundidade[i] = INFINITO;

        ancestral[0][0] = 0;
        profundidade[0] = distancia[0] = 0;

        buscaProfundidade(0, grafo);
        preprocessamento();

        scanf("%d", &consultas);

        while (consultas--)
        {
            scanf("%d %d", &origem, &destino);
            int lca = encontrarLCA(origem, destino);
            ll resposta = (distancia[origem] - distancia[lca]) + (distancia[destino] - distancia[lca]);
            printf("%lld%c", resposta, consultas > 0 ? ' ' : '\n');
        }
    }

    return 0;
}

void buscaProfundidade(int vertice, Grafo *grafo)
{
    for (No *i = grafo->adjacente[vertice].proximo; i != NULL; i = i->proximo)
    {
        int v = i->destino;
        int peso = i->peso;
        if (profundidade[v] == INFINITO)
        {
            profundidade[v] = profundidade[vertice] + 1;
            distancia[v] = distancia[vertice] + (ll)peso;
            ancestral[v][0] = vertice;
            buscaProfundidade(v, grafo);
        }
    }
}

void preprocessamento()
{
    for (int i = 1; i < LOG_MAX; ++i)
        for (int u = 0; u < numVertices; ++u)
            if (ancestral[u][i - 1] != -1)
                ancestral[u][i] = ancestral[ancestral[u][i - 1]][i - 1];
}

int encontrarLCA(int u, int v)
{
    if (profundidade[u] > profundidade[v])
        trocar(&u, &v);
    int diferenca = profundidade[v] - profundidade[u];
    for (int i = 0; i < LOG_MAX; ++i)
        if ((diferenca >> i) & 1)
            v = ancestral[v][i];
    if (u == v)
        return u;
    for (int i = LOG_MAX - 1; i >= 0; --i)
        if (ancestral[u][i] != ancestral[v][i])
            u = ancestral[u][i], v = ancestral[v][i];
    return ancestral[u][0];
}

Grafo *criarGrafo(int tamanho)
{
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
    grafo->adjacente = (No *)malloc(sizeof(No) * (tamanho + 1));
    for (int i = 0; i <= tamanho; ++i)
        grafo->adjacente[i].proximo = NULL;
    return grafo;
}

No *criarNo(int destino, int peso)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->destino = destino;
    novoNo->peso = peso;
    novoNo->proximo = NULL;
    return novoNo;
}

void adicionarAresta(Grafo *grafo, int origem, int destino, int peso)
{
    No *novoNo = criarNo(origem, peso);
    novoNo->proximo = grafo->adjacente[destino].proximo;
    grafo->adjacente[destino].proximo = novoNo;
}

inline void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
