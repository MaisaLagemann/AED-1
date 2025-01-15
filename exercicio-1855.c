#include <stdio.h>
#include <string.h>

#define MAX 106

char mapa[MAX][MAX];
int visitado[MAX][MAX];

int main()
{
    int colunas, linhas;

    while (scanf("%d %d", &colunas, &linhas) != EOF)
    {

        for (int linha = 0; linha < linhas; ++linha)
        {
            scanf("%s", mapa[linha]);
        }

        int encontrouEstrela = 0;
        int deslocamentoLinha = 0, deslocamentoColuna = 1;
        int linhaAtual = 0, colunaAtual = 0;

        memset(visitado, 0, sizeof(visitado));

        while (1)
        {

            if (mapa[linhaAtual][colunaAtual] == '>')
            {
                deslocamentoLinha = 0;
                deslocamentoColuna = 1;
            }
            else if (mapa[linhaAtual][colunaAtual] == '<')
            {
                deslocamentoLinha = 0;
                deslocamentoColuna = -1;
            }
            else if (mapa[linhaAtual][colunaAtual] == 'v')
            {
                deslocamentoLinha = 1;
                deslocamentoColuna = 0;
            }
            else if (mapa[linhaAtual][colunaAtual] == '^')
            {
                deslocamentoLinha = -1;
                deslocamentoColuna = 0;
            }
            else if (mapa[linhaAtual][colunaAtual] == '*')
            {
                printf("*\n");
                encontrouEstrela = 1;
                break;
            }

            linhaAtual += deslocamentoLinha;
            colunaAtual += deslocamentoColuna;

            if (linhaAtual >= linhas || colunaAtual >= colunas || linhaAtual < 0 || colunaAtual < 0 || visitado[linhaAtual][colunaAtual])
            {
                break;
            }

            visitado[linhaAtual][colunaAtual] = 1;
        }

        if (!encontrouEstrela)
        {
            printf("!\n");
        }
    }

    return 0;
}
