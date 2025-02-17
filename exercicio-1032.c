#include <stdio.h>

#define VERDADEIRO 1
#define FALSO 0
#define TAMANHO_MAX 3502
#define PRIMO_MAX 32650

int calcularJosephus(int quantidade);
int verificarPrimo(int numero);
void preencherPrimos();

int listaPrimos[TAMANHO_MAX] = {0};

int main(void)
{
    preencherPrimos();
    int quantidade;

    while (VERDADEIRO)
    {
        if (scanf("%d", &quantidade) != 1) // Verifica entrada inválida
            break;

        if (quantidade == 0)
            break;

        printf("%d\n", calcularJosephus(quantidade));
    }

    return 0;
}

int calcularJosephus(int quantidade)
{
    int indice;
    int resultado = 0;

    for (indice = 1; indice <= quantidade; ++indice)
        resultado = (resultado + listaPrimos[quantidade - indice]) % indice;

    return resultado + 1;
}

int verificarPrimo(int numero)
{
    if (numero < 2)
        return FALSO;
    if (numero == 2)
        return VERDADEIRO;
    if (numero % 2 == 0)
        return FALSO;

    for (int divisor = 3; divisor * divisor <= numero; divisor += 2)
        if (numero % divisor == 0)
            return FALSO;

    return VERDADEIRO;
}

void preencherPrimos()
{
    int numero, indice = 0;
    for (numero = 2; numero < PRIMO_MAX && indice < TAMANHO_MAX; ++numero)
    {
        if (verificarPrimo(numero))
            listaPrimos[indice++] = numero;
    }
}
