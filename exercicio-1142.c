#include <stdio.h>

int main()
{
    int linhas, contador, incremento, limite;

    scanf("%d", &linhas);

    for (contador = 0; contador < linhas; contador++)
    {
        for (incremento = 1 + contador * 4, limite = 0; limite < 3; incremento++, limite++)
        {
            printf("%d ", incremento);
        }
        printf("PUM\n");
    }

    return 0;
}