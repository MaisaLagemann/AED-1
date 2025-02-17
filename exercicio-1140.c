#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char termo[21];
} palavra_t;

bool verificarTautograma(palavra_t *, unsigned short tamanho);

void main()
{
    unsigned short indice;

    while (true)
    {
        char entrada[2000] = {0}, *termoTemp;
        palavra_t termos[100];

        scanf(" %[^\n]", entrada);

        if (strcmp(entrada, "*") == 0)
            break;

        indice = 0;
        termoTemp = strtok(entrada, " ");
        strcpy(termos[indice++].termo, termoTemp);

        do
        {
            termoTemp = strtok(NULL, " ");

            if (termoTemp)
                strcpy(termos[indice++].termo, termoTemp);

        } while (termoTemp);

        if (verificarTautograma(termos, indice))
            printf("Y\n");
        else
            printf("N\n");
    }
}

bool verificarTautograma(palavra_t *termos, unsigned short tamanho)
{
    unsigned short indice;

    for (indice = 1; indice < tamanho; indice++)
        if (tolower(termos[indice].termo[0]) != tolower(termos[indice - 1].termo[0]))
            return false;

    return true;
}
