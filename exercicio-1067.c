#include <stdio.h>

int main()
{

    int limite, contador;
    scanf("%d", &limite);

    for (contador = 1; contador <= limite; contador++)
    {

        if (contador % 2 != 0)
        {

            printf("%d\n", contador);
        }
    }

    return 0;
}