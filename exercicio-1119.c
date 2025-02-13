#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int identificador;
    struct No *anterior;
    struct No *proximo;
} No;

No *criarLista(int tamanho);
No *remover(No *lista, No *registro);
int contarNos(No *lista);
No *percorrer(No *lista, int passos, int direcao);

int main(int argc, char **argv)
{

    int numElementos, passosK, passosM;
    No *lista, *ptrK, *ptrM, *proxK, *proxM;

    while (scanf("%d %d %d", &numElementos, &passosK, &passosM), numElementos)
    {

        lista = criarLista(numElementos);
        ptrK = lista;
        ptrM = lista->anterior;

        while (contarNos(lista) > 2)
        {

            ptrK = percorrer(ptrK, passosK, 0);
            ptrM = percorrer(ptrM, passosM, 1);

            if (ptrK->proximo == ptrM)
                proxK = ptrM->proximo;
            else
                proxK = ptrK->proximo;

            if (ptrM->anterior == ptrK)
                proxM = ptrK->anterior;
            else
                proxM = ptrM->anterior;

            if (ptrK == ptrM)
            {
                printf("%3d,", ptrM->identificador);
                lista = remover(lista, ptrK);
            }
            else
            {
                printf("%3d%3d,", ptrK->identificador, ptrM->identificador);
                lista = remover(lista, ptrM);
                lista = remover(lista, ptrK);
            }

            ptrK = proxK;
            ptrM = proxM;
        }

        if (contarNos(lista) == 2)
        {
            ptrK = percorrer(ptrK, passosK, 0);
            ptrM = percorrer(ptrM, passosM, 1);

            if (ptrK == ptrM)
                printf("%3d,%3d\n", ptrK->identificador, ptrK->proximo->identificador);
            else
                printf("%3d%3d\n", ptrK->identificador, ptrK->proximo->identificador);
        }
        else
            printf("%3d\n", lista->identificador);
    }

    return 0;
}

No *criarLista(int tamanho)
{

    No *novoNo, *anteriorNo;
    No *inicio = NULL;

    for (int i = 1; i <= tamanho; ++i)
    {

        novoNo = (No *)malloc(sizeof(No));
        novoNo->identificador = i;

        if (inicio == NULL)
            inicio = novoNo;
        else
        {
            anteriorNo->proximo = novoNo;
            novoNo->anterior = anteriorNo;
        }

        anteriorNo = novoNo;
    }

    inicio->anterior = novoNo;
    novoNo->proximo = inicio;

    return inicio;
}

No *remover(No *lista, No *registro)
{
    No *anteriorNo = registro->anterior;
    No *proximoNo = registro->proximo;

    if (registro == lista)
    {
        lista = lista->proximo;
        anteriorNo->proximo = lista;
        lista->anterior = registro->anterior;
    }
    else
    {
        anteriorNo->proximo = proximoNo;
        proximoNo->anterior = anteriorNo;
    }

    free(registro);
    return lista;
}

int contarNos(No *lista)
{

    int contador;
    No *auxiliar = lista;
    for (contador = 1; lista != auxiliar->proximo; ++contador)
        auxiliar = auxiliar->proximo;

    return contador;
}

No *percorrer(No *lista, int passos, int direcao)
{

    No *auxiliar = lista;
    if (direcao == 0)
        while (--passos)
            auxiliar = auxiliar->proximo;
    else
        while (--passos)
            auxiliar = auxiliar->anterior;

    return auxiliar;
}
