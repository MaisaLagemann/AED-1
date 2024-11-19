#include <stdio.h>

void ordenar(short *, unsigned short);
int contagem;

void main() {
    unsigned short totalCasos;
    unsigned short totalAlunos;
    int indice;

    scanf("%hu", &totalCasos);

    while (totalCasos--) {
        scanf("%hu", &totalAlunos);

        short filaInicial[totalAlunos];
        short filaOrdenada[totalAlunos];

        for (indice = 0; indice < totalAlunos; indice++) {
            scanf("%hd", &filaInicial[indice]);
            filaOrdenada[indice] = filaInicial[indice];
        }

        contagem = 0;
        ordenar(filaOrdenada, totalAlunos);

        for (indice = 0; indice < totalAlunos; indice++)
            if (filaInicial[indice] == filaOrdenada[indice])
                contagem++;

        printf("%d\n", contagem);
    }
}

void ordenar(short *vetor, unsigned short tamanho) {
    unsigned short indice1, indice2;
    short posicaoMaior, temporario;

    for (indice1 = 0; indice1 < tamanho - 1; indice1++) {
        posicaoMaior = indice1;
        for (indice2 = indice1 + 1; indice2 < tamanho; indice2++)
            if (vetor[indice2] > vetor[posicaoMaior])
                posicaoMaior = indice2;

        if (indice1 != posicaoMaior) {
            temporario = vetor[indice1];
            vetor[indice1] = vetor[posicaoMaior];
            vetor[posicaoMaior] = temporario;
        }
    }
}
