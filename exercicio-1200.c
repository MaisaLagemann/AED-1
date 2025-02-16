#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXSIZE 100

typedef struct NoArvore
{
    char caractere;
    struct NoArvore *filhoEsquerdo;
    struct NoArvore *filhoDireito;
} NoArvore;

void infixa(NoArvore *);
void prefixa(NoArvore *);
void posfixa(NoArvore *);
void printInfixa(void);
void printPrefixa(void);
void printPosfixa(void);
NoArvore *inserirNo(NoArvore *, char);
_Bool buscarCaractere(NoArvore *, char);

char infixaOrdem[MAXSIZE];
char posfixaOrdem[MAXSIZE];
char prefixaOrdem[MAXSIZE];

int indiceInfixa = 0;
int indicePosfixa = 0;
int indicePrefixa = 0;

int main()
{
    char instrucao[20], caractere;
    NoArvore *raiz = NULL;

    while (scanf("%s", instrucao) != EOF)
    {
        if (strcmp(instrucao, "I") == 0)
        {
            scanf(" %c", &caractere);
            raiz = inserirNo(raiz, caractere);
        }
        else if (strcmp(instrucao, "INFIXA") == 0)
        {
            infixa(raiz);
            printInfixa();
        }
        else if (strcmp(instrucao, "PREFIXA") == 0)
        {
            prefixa(raiz);
            printPrefixa();
        }
        else if (strcmp(instrucao, "P") == 0)
        {
            scanf(" %c", &caractere);
            if (buscarCaractere(raiz, caractere))
                printf("%c existe\n", caractere);
            else
                printf("%c nao existe\n", caractere);
        }
        else
        {
            posfixa(raiz);
            printPosfixa();
        }
    }

    return 0; // ✅ Finalizando a main() corretamente
}

NoArvore *inserirNo(NoArvore *raiz, char caractere)
{
    if (!raiz)
    {
        raiz = (NoArvore *)malloc(sizeof(NoArvore));
        raiz->caractere = caractere;
        raiz->filhoDireito = raiz->filhoEsquerdo = NULL;
    }
    else if (caractere < raiz->caractere)
    {
        raiz->filhoEsquerdo = inserirNo(raiz->filhoEsquerdo, caractere);
    }
    else
    {
        raiz->filhoDireito = inserirNo(raiz->filhoDireito, caractere);
    }
    return raiz;
}

_Bool buscarCaractere(NoArvore *raiz, char caractere)
{
    if (!raiz)
        return false;
    if (raiz->caractere == caractere)
        return true;
    if (caractere < raiz->caractere)
        return buscarCaractere(raiz->filhoEsquerdo, caractere);
    return buscarCaractere(raiz->filhoDireito, caractere);
}

void printInfixa()
{
    for (int z = 0; z < indiceInfixa; z++)
    {
        if (z > 0)
            printf(" ");
        printf("%c", infixaOrdem[z]);
    }
    printf("\n");
    indiceInfixa = 0;
}

void printPrefixa()
{
    for (int z = 0; z < indicePrefixa; z++)
    {
        if (z > 0)
            printf(" ");
        printf("%c", prefixaOrdem[z]);
    }
    printf("\n");
    indicePrefixa = 0;
}

void printPosfixa()
{
    for (int z = 0; z < indicePosfixa; z++)
    {
        if (z > 0)
            printf(" ");
        printf("%c", posfixaOrdem[z]);
    }
    printf("\n");
    indicePosfixa = 0;
}

void infixa(NoArvore *raiz)
{
    if (raiz)
    {
        infixa(raiz->filhoEsquerdo);
        infixaOrdem[indiceInfixa++] = raiz->caractere;
        infixa(raiz->filhoDireito);
    }
}

void posfixa(NoArvore *raiz)
{
    if (raiz)
    {
        posfixa(raiz->filhoEsquerdo);
        posfixa(raiz->filhoDireito);
        posfixaOrdem[indicePosfixa++] = raiz->caractere;
    }
}

void prefixa(NoArvore *raiz)
{
    if (raiz)
    {
        prefixaOrdem[indicePrefixa++] = raiz->caractere;
        prefixa(raiz->filhoEsquerdo);
        prefixa(raiz->filhoDireito);
    }
}
