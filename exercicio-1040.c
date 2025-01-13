#include <stdio.h>

int main()
{
    double nota1 = 0, nota2 = 0, nota3 = 0, nota4 = 0;
    double mediaFinal = 0, notaExame = 0;

    if (scanf("%lf %lf %lf %lf", &nota1, &nota2, &nota3, &nota4) != 4)
    {
        printf("Erro na entrada de dados.\n");
        return 1;
    }

    mediaFinal = (nota1 * 2 + nota2 * 3 + nota3 * 4 + nota4 * 1) / (2 + 3 + 4 + 1);
    printf("Media: %.1lf\n", mediaFinal);

    if (mediaFinal >= 7.0)
    {
        printf("Aluno aprovado.\n");
    }
    else if (mediaFinal < 5.0)
    {
        printf("Aluno reprovado.\n");
    }
    else
    {
        printf("Aluno em exame.\n");

        if (scanf("%lf", &notaExame) != 1)
        {
            printf("Erro na entrada de dados.\n");
            return 1;
        }

        printf("Nota do exame: %.1lf\n", notaExame);

        mediaFinal = (mediaFinal + notaExame) / 2;

        if (mediaFinal >= 5.0)
        {
            printf("Aluno aprovado.\n");
        }
        else
        {
            printf("Aluno reprovado.\n");
        }

        printf("Media final: %.1lf\n", mediaFinal);
    }

    return 0;
}
