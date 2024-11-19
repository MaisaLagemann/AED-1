#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool verificarParenteses(char *sequencia);

int main()
{
    char entrada[1100];

    while (scanf(" %s", entrada) != EOF)
    {
        if (verificarParenteses(entrada))
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}

bool verificarParenteses(char *sequencia)
{
    short contadorParenteses = 0;

    if (*sequencia == ')')
        return false;

    while ((*sequencia) && (contadorParenteses >= 0))
    {
        if (*sequencia == '(')
            contadorParenteses++;

        if (*sequencia == ')')
            contadorParenteses--;

        sequencia++;
    }

    return (contadorParenteses == 0);
}