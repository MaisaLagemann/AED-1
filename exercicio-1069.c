#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

typedef unsigned short ushort;

ushort contarDiamantes(char *);

int main()
{
    ushort casosTeste;
    int descarte;
    char string[1005];

    scanf("%hu", &casosTeste);
    scanf("%d", &descarte);
    getchar();

    while (casosTeste--)
    {
        if (fgets(string, 1005, stdin))
        {

            if (string[strlen(string) - 1] == '\n')
                string[strlen(string) - 1] = '\0';

            printf("%hu\n", contarDiamantes(string));
        }

        memset(string, 0, sizeof(string));
    }

    return 0;
}

ushort contarDiamantes(char *string)
{
    ushort diamantesEncontrados = 0;
    ushort i, j;

    for (i = 0; string[i]; ++i)
    {
        if (string[i] != '<')
            continue;

        for (j = i + 1; string[j]; ++j)
        {
            if (string[j] == '>')
            {
                ++diamantesEncontrados;
                string[i] = 'x';
                string[j] = 'x';
                break;
            }
        }
    }

    return diamantesEncontrados;
}