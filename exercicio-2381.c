#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[30];
} Aluno;

void ordenar(Aluno *, unsigned short tamanho);

int main()
{
    unsigned short i;
    unsigned short quantidadeAlunos, indicePremiado;

    scanf("%hu %hu", &quantidadeAlunos, &indicePremiado);

    Aluno listaAlunos[quantidadeAlunos];

    for (i = 0; i < quantidadeAlunos; i++)
        scanf("%s", listaAlunos[i].nome);

    ordenar(listaAlunos, quantidadeAlunos);

    printf("%s\n", listaAlunos[indicePremiado - 1].nome);

    return 0;
}

void ordenar(Aluno *listaAlunos, unsigned short tamanho)
{
    for (unsigned short i = 1; i < tamanho; i++)
    {
        Aluno alunoAtual = listaAlunos[i];
        short j = i - 1;

        while (j >= 0 && strcmp(listaAlunos[j].nome, alunoAtual.nome) > 0)
        {
            listaAlunos[j + 1] = listaAlunos[j];
            j--;
        }
        listaAlunos[j + 1] = alunoAtual;
    }
}