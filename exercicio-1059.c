#include <stdio.h>

int main()
{

    int numeroAtual;

    for (numeroAtual = 1; numeroAtual <= 100; numeroAtual++)
    {

        if (numeroAtual % 2 == 0)
        {

            printf("%d\n", numeroAtual);
        }
    }

    return 0;
}