#include <stdio.h>

unsigned short calcularSobrevivente(unsigned short totalSoldados, unsigned short tamanhoPulo);

void main()
{
    unsigned short totalCasos;
    unsigned short numeroInstancia;
    unsigned short totalSoldados, tamanhoPulo;

    scanf("%hu", &totalCasos);

    numeroInstancia = 0;
    while (totalCasos--)
    {
        scanf("%hu %hu", &totalSoldados, &tamanhoPulo);
        printf("Case %hu: %hu\n", ++numeroInstancia, calcularSobrevivente(totalSoldados, tamanhoPulo) + 1);
    }
}

unsigned short calcularSobrevivente(unsigned short totalSoldados, unsigned short tamanhoPulo)
{
    unsigned short i, posicaoSobrevivente;
    posicaoSobrevivente = 0;

    for (i = 2; i <= totalSoldados; i++)
        posicaoSobrevivente = (posicaoSobrevivente + tamanhoPulo) % i;

    return posicaoSobrevivente;
}
