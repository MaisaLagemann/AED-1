#include <stdio.h>

#define VERDADEIRO 1
#define FALSO 0

char lerEntrada(int *numero);
void imprimirResultado(unsigned valor);

int main()
{
    unsigned num1, num2;

    while (lerEntrada(&num1) != EOF)
        lerEntrada(&num2), imprimirResultado(num1 ^ num2);

    return 0;
}

inline char lerEntrada(int *numero)
{
    register char caractere = 0;
    *numero = 0;
    caractere = getchar_unlocked();
    while (caractere >= '0')
    {
        *numero = *numero * 10 + (caractere - '0');
        caractere = getchar_unlocked();
    }

    return caractere;
}

inline void imprimirResultado(unsigned valor)
{
    char indice = 10;
    char bufferSaida[11];
    bufferSaida[10] = '\n';

    do
    {
        bufferSaida[--indice] = (valor % 10) + '0';
        valor /= 10;
    } while (valor);

    do
    {
        putchar_unlocked(bufferSaida[indice]);
    } while (++indice < 11);
}
