#include <stdio.h>

int calcularMDC(int, int);
int calcularMMC(int, int);
void multiplicar(int, int, int, int, int *, int *);
void somar(int, int, int, int, int *, int *);
void subtrair(int, int, int, int, int *, int *);
void dividir(int, int, int, int, int *, int *);

void main()
{
    char operador;
    int numerador1, denominador1, numerador2, denominador2;
    unsigned totalCasos;
    int resultadoNumerador, resultadoDenominador, divisor;

    scanf("%u", &totalCasos);

    while (totalCasos--)
    {
        scanf("%d / %d %c %d / %d", &numerador1, &denominador1, &operador, &numerador2, &denominador2);

        if (operador == '+')
            somar(numerador1, denominador1, numerador2, denominador2, &resultadoNumerador, &resultadoDenominador);
        else if (operador == '-')
            subtrair(numerador1, denominador1, numerador2, denominador2, &resultadoNumerador, &resultadoDenominador);
        else if (operador == '*')
            multiplicar(numerador1, denominador1, numerador2, denominador2, &resultadoNumerador, &resultadoDenominador);
        else if (operador == '/')
            dividir(numerador1, denominador1, numerador2, denominador2, &resultadoNumerador, &resultadoDenominador);

        divisor = calcularMDC(resultadoNumerador, resultadoDenominador);

        if (divisor < 0)
            printf("%d/%d = %d/%d\n", resultadoNumerador, resultadoDenominador, -(resultadoNumerador / divisor), -(resultadoDenominador / divisor));
        else
            printf("%d/%d = %d/%d\n", resultadoNumerador, resultadoDenominador, resultadoNumerador / divisor, resultadoDenominador / divisor);
    }
}

void somar(int numerador1, int denominador1, int numerador2, int denominador2, int *resultadoNumerador, int *resultadoDenominador)
{
    *resultadoNumerador = numerador1 * denominador2 + numerador2 * denominador1;
    *resultadoDenominador = denominador1 * denominador2;
}

void subtrair(int numerador1, int denominador1, int numerador2, int denominador2, int *resultadoNumerador, int *resultadoDenominador)
{
    *resultadoNumerador = numerador1 * denominador2 - numerador2 * denominador1;
    *resultadoDenominador = denominador1 * denominador2;
}

void multiplicar(int numerador1, int denominador1, int numerador2, int denominador2, int *resultadoNumerador, int *resultadoDenominador)
{
    *resultadoNumerador = numerador1 * numerador2;
    *resultadoDenominador = denominador1 * denominador2;
}

void dividir(int numerador1, int denominador1, int numerador2, int denominador2, int *resultadoNumerador, int *resultadoDenominador)
{
    *resultadoNumerador = (numerador1 * denominador2);
    *resultadoDenominador = (numerador2 * denominador1);
}

int calcularMDC(int valor1, int valor2)
{
    int resto = valor1 % valor2;
    while (resto != 0)
    {
        valor1 = valor2;
        valor2 = resto;
        resto = valor1 % valor2;
    }
    return valor2;
}

int calcularMMC(int valor1, int valor2)
{
    return (valor1 / calcularMDC(valor1, valor2)) * valor2;
}
