#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Celula
{
    char nome[50];
    struct Celula *proximo;
};

struct Celula *criarCelula(char *nome)
{
    struct Celula *novaCelula = (struct Celula *)malloc(sizeof(struct Celula));
    strcpy(novaCelula->nome, nome);
    novaCelula->proximo = NULL;
    return novaCelula;
}

void adicionarCelula(struct Celula **inicio, char *nome)
{
    struct Celula *novaCelula = criarCelula(nome);
    if (*inicio == NULL)
    {
        *inicio = novaCelula;
    }
    else
    {
        struct Celula *auxiliar = *inicio;
        while (auxiliar->proximo != NULL)
        {
            auxiliar = auxiliar->proximo;
        }
        auxiliar->proximo = novaCelula;
    }
}

void imprimirLista(struct Celula *inicio)
{
    struct Celula *auxiliar = inicio;
    while (auxiliar != NULL)
    {
        printf("%s", auxiliar->nome);
        if (auxiliar->proximo != NULL)
            printf(" ");
        auxiliar = auxiliar->proximo;
    }
    printf("\n");
}

void inserirAntesDe(struct Celula **inicio, struct Celula *novaLista, char *nomeAmigo)
{
    struct Celula *auxiliar = *inicio;
    struct Celula *anterior = NULL;

    while (auxiliar != NULL && strcmp(auxiliar->nome, nomeAmigo) != 0)
    {
        anterior = auxiliar;
        auxiliar = auxiliar->proximo;
    }

    if (auxiliar == NULL)
    {
        if (anterior != NULL)
        {
            anterior->proximo = novaLista;
        }
        else
        {
            *inicio = novaLista;
        }
    }
    else
    {
        struct Celula *fimNovaLista = novaLista;
        while (fimNovaLista->proximo != NULL)
        {
            fimNovaLista = fimNovaLista->proximo;
        }
        if (anterior != NULL)
        {
            anterior->proximo = novaLista;
        }
        else
        {
            *inicio = novaLista;
        }
        fimNovaLista->proximo = auxiliar;
    }
}

struct Celula *criarListaAmigos(char *lista)
{
    struct Celula *inicio = NULL;
    char *nome = strtok(lista, " ");
    while (nome != NULL)
    {
        adicionarCelula(&inicio, nome);
        nome = strtok(NULL, " ");
    }
    return inicio;
}

int main()
{
    char listaAmigosL[100], listaNova[100], nomeAmigoS[50];
    struct Celula *inicioListaL, *inicioListaN;

    fgets(listaAmigosL, sizeof(listaAmigosL), stdin);
    listaAmigosL[strcspn(listaAmigosL, "\n")] = '\0';

    fgets(listaNova, sizeof(listaNova), stdin);
    listaNova[strcspn(listaNova, "\n")] = '\0';

    fgets(nomeAmigoS, sizeof(nomeAmigoS), stdin);
    nomeAmigoS[strcspn(nomeAmigoS, "\n")] = '\0';

    inicioListaL = criarListaAmigos(listaAmigosL);
    inicioListaN = criarListaAmigos(listaNova);

    if (strcmp(nomeAmigoS, "nao") == 0)
    {
        struct Celula *auxiliar = inicioListaL;
        while (auxiliar->proximo != NULL)
        {
            auxiliar = auxiliar->proximo;
        }
        auxiliar->proximo = inicioListaN;
    }
    else
    {
        inserirAntesDe(&inicioListaL, inicioListaN, nomeAmigoS);
    }

    imprimirLista(inicioListaL);

    return 0;
}
