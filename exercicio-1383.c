#include <stdio.h>
#include <stdbool.h>

int main()
{
    int num_matriz = 0;
    int numero;

    scanf("%d", &num_matriz);

    for (int i = 0; i < num_matriz; i++)
    {
        /* Obtendo os elementos das matrizes */

        int matriz[9][9];

        for (int linha = 0; linha < 9; linha++)
        {
            for (int coluna = 0; coluna < 9; coluna++)
            {
                scanf("%d", &numero);
                matriz[linha][coluna] = numero;
            }
        }

        bool eh_valido = true;

        /* Analisando se as linhas satisfazem a condiçâo (Aparecer apenas uma vez) */

        for (int linha = 0; linha < 9; linha++)
        {
            bool ja_apareceu[9] = {false};
            for (int coluna = 0; coluna < 9; coluna++)
            {
                int elemento = matriz[linha][coluna];
                if (ja_apareceu[elemento - 1])
                {
                    eh_valido = false;
                }
                ja_apareceu[elemento - 1] = true;
            }
        }

        if (eh_valido)
        {
            /* Analisando se as colunas satisfazem a condiçâo (Aparecer apenas uma vez) */
            for (int coluna = 0; coluna < 9; coluna++)
            {
                bool ja_apareceu[9] = {false};
                for (int linha = 0; linha < 9; linha++)
                {
                    int elemento = matriz[linha][coluna];
                    if (ja_apareceu[elemento - 1])
                    {
                        eh_valido = false;
                    }
                    ja_apareceu[elemento - 1] = true;
                }
            }
        }

        if (eh_valido)
        {
            /* Analisando se as submatrizes satisfazem a condiçâo (Aparecer apenas uma vez) */
            for (int linha_grande = 0; linha_grande < 3; linha_grande++)
            {
                for (int coluna_grande = 0; coluna_grande < 3; coluna_grande++)
                {
                    bool ja_apareceu[9] = {false};
                    for (int linhazinha = 0; linhazinha < 3; linhazinha++)
                    {
                        for (int coluninha = 0; coluninha < 3; coluninha++)
                        {
                            int elemento = matriz[3 * linha_grande + linhazinha][3 * coluna_grande + coluninha];
                            if (ja_apareceu[elemento - 1])
                            {
                                eh_valido = false;
                            }
                            ja_apareceu[elemento - 1] = true;
                        }
                    }
                }
            }
        }

        printf("Instancia %d\n", i + 1);

        /* Verifica se, ao final, nenhum erro foi encontrado */

        if (eh_valido)
        {
            printf("SIM\n\n");
        }
        else
        {
            printf("NAO\n\n");
        }
    }

    return 0;
}
