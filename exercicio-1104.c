#include <stdio.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0
#define TAMANHO_MAXIMO 100101

typedef struct Carta
{
    _Bool pertenceAlice;
    _Bool pertenceBeatriz;
} Carta;

Carta baralho[TAMANHO_MAXIMO];

void main()
{
    unsigned int i, valorCarta;
    unsigned int qtdCartasAlice, qtdCartasBeatriz;

    while (scanf("%u %u", &qtdCartasAlice, &qtdCartasBeatriz), qtdCartasAlice)
    {
        memset(baralho, FALSO, sizeof(baralho));

        for (i = 0; i < qtdCartasAlice; ++i)
            scanf("%u", &valorCarta), baralho[valorCarta].pertenceAlice = VERDADEIRO;

        for (i = 0; i < qtdCartasBeatriz; ++i)
            scanf("%u", &valorCarta), baralho[valorCarta].pertenceBeatriz = VERDADEIRO;

        qtdCartasAlice = qtdCartasBeatriz = 0;
        for (i = 0; i < TAMANHO_MAXIMO; ++i)
        {
            if (baralho[i].pertenceAlice && !baralho[i].pertenceBeatriz)
                ++qtdCartasAlice;

            if (!baralho[i].pertenceAlice && baralho[i].pertenceBeatriz)
                ++qtdCartasBeatriz;
        }

        printf("%d\n", qtdCartasBeatriz > qtdCartasAlice ? qtdCartasAlice : qtdCartasBeatriz);
    }
}