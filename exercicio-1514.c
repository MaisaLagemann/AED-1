#include <stdio.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0

unsigned somaLinhas[101];
unsigned somaColunas[101];

int main(int argc, char **argv)
{
    unsigned linhas, colunas;
    unsigned indiceLinha, indiceColuna, valor;
    _Bool criterio1, criterio2, criterio3, criterio4;

    while (scanf("%u %u", &linhas, &colunas), linhas && colunas)
    {
        criterio1 = criterio2 = criterio3 = criterio4 = VERDADEIRO;
        memset(somaColunas, 0, sizeof(somaColunas));
        memset(somaLinhas, 0, sizeof(somaLinhas));

        for (indiceLinha = 0; indiceLinha < linhas; ++indiceLinha)
            for (indiceColuna = 0; indiceColuna < colunas; ++indiceColuna)
            {
                scanf("%u", &valor);
                somaLinhas[indiceLinha] += valor;
                somaColunas[indiceColuna] += valor;
            }

        for (indiceLinha = 0; indiceLinha < linhas; ++indiceLinha)
        {
            if (somaLinhas[indiceLinha] == colunas)
                criterio1 = FALSO;

            if (somaLinhas[indiceLinha] == 0)
                criterio4 = FALSO;
        }

        for (indiceColuna = 0; indiceColuna < colunas; ++indiceColuna)
        {
            if (somaColunas[indiceColuna] == 0)
                criterio2 = FALSO;

            if (somaColunas[indiceColuna] == linhas)
                criterio3 = FALSO;
        }

        printf("%u\n", criterio1 + criterio2 + criterio3 + criterio4);
    }

    return 0;
}
