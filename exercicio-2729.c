#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAXIMO_PALAVRA 21

struct Celula
{
    char item[TAMANHO_MAXIMO_PALAVRA];
    struct Celula *proximo;
};

struct Celula *criarCelula(const char *item)
{
    struct Celula *novaCelula = (struct Celula *)malloc(sizeof(struct Celula));
    strcpy(novaCelula->item, item);
    novaCelula->proximo = NULL;
    return novaCelula;
}

void inserirOrdenado(struct Celula **inicio, const char *item)
{
    struct Celula *atual = *inicio;
    struct Celula *anterior = NULL;

    while (atual != NULL && strcmp(atual->item, item) < 0)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL && strcmp(atual->item, item) == 0)
    {
        return;
    }

    struct Celula *novaCelula = criarCelula(item);

    if (anterior == NULL)
    {
        novaCelula->proximo = *inicio;
        *inicio = novaCelula;
    }
    else
    {
        novaCelula->proximo = anterior->proximo;
        anterior->proximo = novaCelula;
    }
}

void liberarLista(struct Celula *inicio)
{
    struct Celula *atual = inicio;
    while (atual != NULL)
    {
        struct Celula *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

void imprimirLista(struct Celula *inicio)
{
    struct Celula *atual = inicio;
    int primeiro = 1;
    while (atual != NULL)
    {
        if (!primeiro)
            printf(" ");
        printf("%s", atual->item);
        primeiro = 0;
        atual = atual->proximo;
    }
    printf("\n");
}

int main()
{
    int numeroDeCasos;
    scanf("%d", &numeroDeCasos);
    getchar();

    for (int k = 0; k < numeroDeCasos; k++)
    {
        struct Celula *inicio = NULL;
        char item[TAMANHO_MAXIMO_PALAVRA];

        while (scanf("%s", item) == 1)
        {
            inserirOrdenado(&inicio, item);
            if (getchar() == '\n')
                break;
        }

        imprimirLista(inicio);

        liberarLista(inicio);
    }

    return 0;
}