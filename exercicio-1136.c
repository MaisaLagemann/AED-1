#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAXIMO 100009

int diferencas[TAMANHO_MAXIMO];
int valores[TAMANHO_MAXIMO];

int main(int argc, char **argv)
{
    int totalNumeros, totalBolas;
    while (scanf("%d %d", &totalNumeros, &totalBolas), totalNumeros)
    {
        for (size_t i = 0; i < totalBolas; ++i)
        {
            scanf("%d", &valores[i]);
            for (size_t j = 0; j <= i; ++j)
                diferencas[abs(valores[i] - valores[j])] = 1;
        }

        size_t indice = 0;
        for (; indice <= totalNumeros; ++indice)
            if (!diferencas[indice])
                break;

        printf("%c\n", (indice - 1UL) != totalNumeros ? 'N' : 'Y');
        memset(diferencas, 0, sizeof(int) * (totalNumeros + 1));
    }

    return 0;
}
