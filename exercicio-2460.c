#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    unsigned short identificador;
    unsigned short posicao;
} Pessoa;

int main()
{
    unsigned short totalPessoas, totalSaidas;
    unsigned short indice, identificadorAtual;
    Pessoa fila[51000];

    scanf("%hu", &totalPessoas);

    memset(fila, 0, sizeof(fila));

    for (indice = 0; indice < totalPessoas; indice++)
    {
        scanf("%hu", &identificadorAtual);
        fila[indice].identificador = identificadorAtual;
        fila[identificadorAtual].posicao = indice;
    }

    scanf("%hu", &totalSaidas);

    for (indice = 0; indice < totalSaidas; indice++)
    {
        scanf("%hu", &identificadorAtual);
        fila[fila[identificadorAtual].posicao].identificador = 0;
    }

    bool espacoInicial = false;
    for (indice = 0; indice < totalPessoas; indice++)
    {
        if (fila[indice].identificador)
        {
            if (espacoInicial)
                printf(" ");
            espacoInicial = true;
            printf("%hu", fila[indice].identificador);
        }
    }

    printf("\n");
    return 0;
}