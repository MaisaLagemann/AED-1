#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 1000

typedef struct NodoArvore
{

    char caractere;
    struct NodoArvore *direita;
    struct NodoArvore *esquerda;

} NodoArvore;

NodoArvore *criarNodo(char caractere);
void exibirPosfixo(NodoArvore *arvore);
int buscarIndice(char *sequencia, int inicio, int fim, char caractere);
NodoArvore *construirArvore(char *infixa, char *prefixa, int inicioInfixa, int fimInfixa);

short indicePrefixo;

void main()
{

    short totalCasos;
    short totalNodos, i;
    char sequenciaPrefixa[TAM_MAX], sequenciaInfixa[TAM_MAX];

    scanf("%hu", &totalCasos);

    while (totalCasos--)
    {

        scanf("%hu %s %s%*c", &totalNodos, sequenciaPrefixa, sequenciaInfixa);
        indicePrefixo = 0;
        NodoArvore *raiz = construirArvore(sequenciaInfixa, sequenciaPrefixa, 0, totalNodos - 1);
        exibirPosfixo(raiz);
        printf("\n");
    }
}

NodoArvore *criarNodo(char caractere)
{

    NodoArvore *nodo = (NodoArvore *)malloc(sizeof(NodoArvore));
    nodo->caractere = caractere;
    nodo->esquerda = nodo->direita = NULL;

    return nodo;
}

int buscarIndice(char *sequencia, int inicio, int fim, char caractere)
{

    short i;
    for (i = inicio; i <= fim; ++i)
        if (sequencia[i] == caractere)
            return i;

    return -1;
}

NodoArvore *construirArvore(char *infixa, char *prefixa, int inicioInfixa, int fimInfixa)
{

    int indiceInfixa;

    if (inicioInfixa > fimInfixa)
        return NULL;

    NodoArvore *nodo = criarNodo(prefixa[indicePrefixo++]);
    if (inicioInfixa == fimInfixa)
        return nodo;

    indiceInfixa = buscarIndice(infixa, inicioInfixa, fimInfixa, nodo->caractere);
    nodo->esquerda = construirArvore(infixa, prefixa, inicioInfixa, indiceInfixa - 1);
    nodo->direita = construirArvore(infixa, prefixa, indiceInfixa + 1, fimInfixa);

    return nodo;
}

void exibirPosfixo(NodoArvore *nodo)
{

    if (nodo == NULL)
        return;

    exibirPosfixo(nodo->esquerda);
    exibirPosfixo(nodo->direita);
    printf("%c", nodo->caractere);
}
