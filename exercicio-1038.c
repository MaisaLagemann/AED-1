#include <stdio.h>

int main()
{

    unsigned short int codigoProduto, quantidadeProduto;
    float precoTotal;

    scanf("%hd %hd", &codigoProduto, &quantidadeProduto);

    if (codigoProduto == 1)
        precoTotal = 4.00 * quantidadeProduto;
    else if (codigoProduto == 2)
        precoTotal = 4.50 * quantidadeProduto;
    else if (codigoProduto == 3)
        precoTotal = 5.00 * quantidadeProduto;
    else if (codigoProduto == 4)
        precoTotal = 2.00 * quantidadeProduto;
    else
        precoTotal = 1.50 * quantidadeProduto;

    printf("Total: R$ %.2f\n", precoTotal);

    return 0;
}