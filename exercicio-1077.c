#include <stdio.h>
#include <stdlib.h>

#define VERDADEIRO 1
#define FALSO 0

typedef struct No
{

    char valor;
    struct No *proximo;

} No;

typedef struct Pilha
{

    No *topo;

} Pilha;

char topo(Pilha *);
void desempilhar(Pilha *);
void inicializarPilha(Pilha *);
void converterInfixaParaPosfixa(char *);
void empilhar(Pilha *, char);
int verificarPrioridade(char, char);

int main()
{

    char expressao[400];
    unsigned short quantidadeCasos;

    scanf("%hu", &quantidadeCasos);

    while (quantidadeCasos--)
    {

        scanf("%s", expressao);
        converterInfixaParaPosfixa(expressao);
    }

    return 0;
}

void converterInfixaParaPosfixa(char *expressao)
{

    int i = 0;
    char caractereAtual, operadorTopo;
    Pilha pilha;
    inicializarPilha(&pilha);
    empilhar(&pilha, '(');

    do
    {

        caractereAtual = expressao[i];
        ++i;

        if ((caractereAtual >= 'A' && caractereAtual <= 'Z') ||
            (caractereAtual >= '0' && caractereAtual <= '9') ||
            (caractereAtual >= 'a' && caractereAtual <= 'z'))
        {
            printf("%c", caractereAtual);
        }
        else if (caractereAtual == '(')
        {
            empilhar(&pilha, '(');
        }
        else if (caractereAtual == ')' || caractereAtual == '\0')
        {

            do
            {
                operadorTopo = topo(&pilha);
                desempilhar(&pilha);
                if (operadorTopo != '(')
                    printf("%c", operadorTopo);

            } while (operadorTopo != '(');
        }
        else if (caractereAtual == '+' || caractereAtual == '-' ||
                 caractereAtual == '*' || caractereAtual == '^' ||
                 caractereAtual == '/')
        {

            while (VERDADEIRO)
            {

                operadorTopo = topo(&pilha);
                desempilhar(&pilha);
                if (verificarPrioridade(caractereAtual, operadorTopo))
                {
                    empilhar(&pilha, operadorTopo);
                    empilhar(&pilha, caractereAtual);
                    break;
                }
                else
                {
                    printf("%c", operadorTopo);
                }
            }
        }

    } while (caractereAtual != '\0');

    printf("\n");
}

void inicializarPilha(Pilha *pilha)
{

    pilha->topo = NULL;
}

void empilhar(Pilha *pilha, char valor)
{

    No *novoNo;
    novoNo = (No *)malloc(sizeof(No));

    if (!novoNo)
        exit(1);

    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
    novoNo->valor = valor;
}

void desempilhar(Pilha *pilha)
{

    No *auxiliar;
    auxiliar = pilha->topo;

    if (auxiliar)
    {
        pilha->topo = auxiliar->proximo;
        free(auxiliar);
    }
}

char topo(Pilha *pilha)
{

    return (pilha->topo->valor);
}

int verificarPrioridade(char operadorAtual, char operadorTopo)
{

    int prioridadeAtual, prioridadeTopo;

    if (operadorAtual == '^')
        prioridadeAtual = 3;
    else if (operadorAtual == '*' || operadorAtual == '/')
        prioridadeAtual = 2;
    else if (operadorAtual == '+' || operadorAtual == '-')
        prioridadeAtual = 1;
    else if (operadorAtual == '(')
        prioridadeAtual = 4;

    if (operadorTopo == '^')
        prioridadeTopo = 3;
    else if (operadorTopo == '*' || operadorTopo == '/')
        prioridadeTopo = 2;
    else if (operadorTopo == '+' || operadorTopo == '-')
        prioridadeTopo = 1;
    else if (operadorTopo == '(')
        prioridadeTopo = 0;

    return (prioridadeAtual > prioridadeTopo);
}
