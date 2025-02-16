#include <stdio.h>
#include <string.h>

int main()
{
    unsigned indiceTexto, indiceTeclado;
    char texto[1000];
    char *mapaTeclado = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    while (fgets(texto, 1000, stdin) != NULL)
    {
        int tamanhoTexto = strlen(texto);

        for (indiceTexto = 0; indiceTexto < tamanhoTexto; ++indiceTexto)
        {
            for (indiceTeclado = 0; indiceTeclado < 48; ++indiceTeclado)
            {
                if (texto[indiceTexto] == mapaTeclado[indiceTeclado])
                {
                    printf("%c", mapaTeclado[indiceTeclado - 1]);
                    break;
                }
                else if (texto[indiceTexto] == ' ')
                {
                    printf(" ");
                    break;
                }
                else if (texto[indiceTexto] == '\n')
                {
                    printf("\n");
                    break;
                }
            }
        }
    }

    return 0;
}
