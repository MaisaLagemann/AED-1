#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned inicio, fim, custo;
} Conexao;

#define SIM 1
#define NAO 0
#define LIMITE_MAXIMO 200100

Conexao rede[LIMITE_MAXIMO];
int grupo[LIMITE_MAXIMO];

int calcularKruskal(int);
int encontrarRaiz(int);
int ordenarConexoes(Conexao *, Conexao *);

int main()
{
    int totalPontos, totalConexoes;

    while (scanf("%d %d", &totalPontos, &totalConexoes), totalPontos && totalConexoes)
    {
        int i;
        unsigned custoTotal = 0;

        for (i = 0; i < totalConexoes; ++i)
        {
            scanf("%d %d %d", &rede[i].fim, &rede[i].inicio, &rede[i].custo);
            custoTotal += rede[i].custo;
        }

        qsort(rede, totalConexoes, sizeof(Conexao), ordenarConexoes);

        for (i = 1; i <= totalPontos; ++i)
            grupo[i] = i;

        printf("%u\n", custoTotal - calcularKruskal(totalConexoes));

        memset(rede, 0, sizeof(rede));
        memset(grupo, 0, sizeof(grupo));
    }

    return 0;
}

int encontrarRaiz(int ponto)
{
    if (ponto == grupo[ponto])
        return ponto;

    return encontrarRaiz(grupo[ponto]);
}

int calcularKruskal(int totalConexoes)
{
    int i, raizInicio, raizFim;
    unsigned menorCusto = 0;

    for (i = 0; i < totalConexoes; ++i)
    {
        raizInicio = encontrarRaiz(rede[i].fim);
        raizFim = encontrarRaiz(rede[i].inicio);

        if (raizFim != raizInicio)
        {
            grupo[raizInicio] = grupo[raizFim];
            menorCusto += rede[i].custo;
        }
    }

    return menorCusto;
}

int ordenarConexoes(Conexao *a, Conexao *b)
{
    return a->custo - b->custo;
}
