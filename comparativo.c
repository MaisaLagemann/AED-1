#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM = 400000;

void insertionSort(int v[TAM])
{
    for (int i = 1; i < TAM; i++)
    {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = key;
    }
}

void merge(int v[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = v[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        v[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int v[TAM], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);

        merge(v, left, mid, right);
    }
}

int main()
{
    clock_t t1, t2;
    int vetor[TAM], seed;

    seed = rand();
    srand(seed);
    for (int a = 0; a < TAM; a++)
    {
        vetor[a] = rand() % TAM;
    }
    t1 = clock();
    insertionSort(vetor);
    t1 = clock() - t1;

    srand(seed);
    for (int a = 0; a < TAM; a++)
    {
        vetor[a] = rand() % TAM;
    }
    t2 = clock();
    mergeSort(vetor, 0, TAM - 1);
    t2 = clock() - t2;

    printf("Tempo de execucao: %lf ms\n", ((double)t1) / ((CLOCKS_PER_SEC / 1000)));
    printf("Tempo de execucao: %lf ms\n", ((double)t2) / ((CLOCKS_PER_SEC / 1000)));

    return 0;
}