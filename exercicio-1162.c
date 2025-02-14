#include <stdio.h>

unsigned ordenarVagoes(int vagoes[], unsigned tamanho);

void main(void)
{
    unsigned numCasos, tamanhoTrem;
    unsigned i;

    scanf("%u", &numCasos);

    while (numCasos--)
    {
        scanf("%u", &tamanhoTrem);
        int vagoes[tamanhoTrem];

        for (i = 0; i < tamanhoTrem; i++)
            scanf("%d", &vagoes[i]);

        printf("Optimal train swapping takes %u swaps.\n", ordenarVagoes(vagoes, tamanhoTrem));
    }
}

unsigned ordenarVagoes(int vagoes[], unsigned tamanho)
{
    unsigned i, j, numTrocas = 0, temp;

    while (tamanho--)
    {
        for (i = 0, j = 1; i < tamanho; i++, j++)
            if (vagoes[i] > vagoes[j])
            {
                numTrocas++;
                temp = vagoes[i];
                vagoes[i] = vagoes[j];
                vagoes[j] = temp;
            }
    }
    return numTrocas;
}
