#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAXIMO 1000

typedef struct NodoArvore
{
    char dado;
    struct NodoArvore *direita;
    struct NodoArvore *esquerda;
} NodoArvore;

NodoArvore *criarNodo(char dado);
void exibirPosOrdem(NodoArvore *raiz);
int localizarIndice(char *sequencia, int inicio, int fim, char elemento);
NodoArvore *construirArvore(char *ordemInfixa, char *ordemPrefixa, int inicio, int fim);

short indicePrefixo;

int main()
{
    char ordemPrefixa[TAMANHO_MAXIMO], ordemInfixa[TAMANHO_MAXIMO];

    while (scanf("%s %s", ordemPrefixa, ordemInfixa) != EOF)
    {
        int tamanho = strlen(ordemPrefixa);
        indicePrefixo = 0;
        NodoArvore *raiz = construirArvore(ordemInfixa, ordemPrefixa, 0, tamanho - 1);
        exibirPosOrdem(raiz);
        printf("\n");
    }

    return 0;
}

NodoArvore *criarNodo(char dado)
{
    NodoArvore *novo = (NodoArvore *)malloc(sizeof(NodoArvore));
    novo->dado = dado;
    novo->esquerda = novo->direita = NULL;
    return novo;
}

int localizarIndice(char *sequencia, int inicio, int fim, char elemento)
{
    short i;
    for (i = inicio; i <= fim; ++i)
        if (sequencia[i] == elemento)
            return i;

    return -1;
}

NodoArvore *construirArvore(char *ordemInfixa, char *ordemPrefixa, int inicio, int fim)
{
    int indiceInfixo;

    if (inicio > fim)
        return NULL;

    NodoArvore *novo = criarNodo(ordemPrefixa[indicePrefixo++]);
    if (inicio == fim)
        return novo;

    indiceInfixo = localizarIndice(ordemInfixa, inicio, fim, novo->dado);
    novo->esquerda = construirArvore(ordemInfixa, ordemPrefixa, inicio, indiceInfixo - 1);
    novo->direita = construirArvore(ordemInfixa, ordemPrefixa, indiceInfixo + 1, fim);

    return novo;
}

void exibirPosOrdem(NodoArvore *raiz)
{
    if (raiz == NULL)
        return;

    exibirPosOrdem(raiz->esquerda);
    exibirPosOrdem(raiz->direita);
    printf("%c", raiz->dado);
}