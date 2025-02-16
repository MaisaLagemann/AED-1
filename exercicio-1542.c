#include <stdio.h>
#include <stdbool.h>

void main()
{
    int paginasAtuais;
    int diasAdiantados;
    int paginasFuturas;
    int totalPaginas;

    scanf("%d", &paginasAtuais);

    while (true)
    {
        scanf("%d %d", &diasAdiantados, &paginasFuturas);

        totalPaginas = (diasAdiantados * paginasAtuais * paginasFuturas) / (paginasFuturas - paginasAtuais);

        if (totalPaginas == 1)
            printf("%d pagina\n", totalPaginas);
        else
            printf("%d paginas\n", totalPaginas);

        scanf("%d", &paginasAtuais);

        if (paginasAtuais == 0)
            break;
    }
}
