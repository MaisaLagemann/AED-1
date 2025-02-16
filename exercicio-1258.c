#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char estampa[60];
    char tonalidade[20];
    char medida;
} Camiseta;

void ordenaMedida(Camiseta *, unsigned short);
void ordenaAlfabetico(Camiseta *, unsigned short);
void ordenaTonalidade(Camiseta *, unsigned short);

void main()
{
    unsigned short quantidade;
    unsigned short i;

    scanf("%hu", &quantidade);

    while (true)
    {
        if (quantidade == 0)
            break;

        Camiseta camisetas[quantidade];
        for (i = 0; i < quantidade; i++)
        {
            scanf(" %[^\n]", camisetas[i].estampa);
            scanf("%s %c", camisetas[i].tonalidade, &camisetas[i].medida);
        }

        ordenaAlfabetico(camisetas, quantidade);
        ordenaMedida(camisetas, quantidade);
        ordenaTonalidade(camisetas, quantidade);

        // Impressão final
        for (i = 0; i < quantidade; i++)
            printf("%s %c %s\n", camisetas[i].tonalidade, camisetas[i].medida, camisetas[i].estampa);

        scanf("%hu", &quantidade);
        if (quantidade != 0)
            printf("\n");
    }
}

void ordenaAlfabetico(Camiseta *camisetas, unsigned short tamanhoArray)
{
    short i = 1, j;
    Camiseta elementoPivo;

    while (i < tamanhoArray)
    {
        j = i - 1;
        elementoPivo = camisetas[i];

        while (j >= 0 && strcmp(camisetas[j].estampa, elementoPivo.estampa) > 0)
        {
            camisetas[j + 1] = camisetas[j];
            j--;
        }
        camisetas[j + 1] = elementoPivo;
        i++;
    }
}

void ordenaTonalidade(Camiseta *camisetas, unsigned short tamanhoArray)
{
    short i = 1, j;
    Camiseta elementoPivo;

    while (i < tamanhoArray)
    {
        j = i - 1;
        elementoPivo = camisetas[i];

        while (j >= 0 && strcmp(camisetas[j].tonalidade, elementoPivo.tonalidade) > 0)
        {
            camisetas[j + 1] = camisetas[j];
            j--;
        }
        camisetas[j + 1] = elementoPivo;
        i++;
    }
}

void ordenaMedida(Camiseta *camisetas, unsigned short tamanhoArray)
{
    short i = 1, j;
    Camiseta elementoPivo;

    while (i < tamanhoArray)
    {
        j = i - 1;
        elementoPivo = camisetas[i];

        while (j >= 0 && camisetas[j].medida < elementoPivo.medida)
        {
            camisetas[j + 1] = camisetas[j];
            j--;
        }
        camisetas[j + 1] = elementoPivo;
        i++;
    }
}
