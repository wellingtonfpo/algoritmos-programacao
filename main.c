#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAMANHO 10000

void selectionSort(int *V, int N);
void bubbleSort(int *V, int N);
void insertionSort(int *V, int N);
void printArray(int *V, int N);
void gerarArrayDescrescente(int *V, int N);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int arr1[TAMANHO];
    int arr2[TAMANHO];
    int arr3[TAMANHO];
    clock_t inicio, fim;
    double tempo;

    gerarArrayDescrescente(arr1, TAMANHO);
    for (int i = 0; i < TAMANHO; i++)
    {
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }

    // Ordenação por bolha
    inicio = clock();
    bubbleSort(arr1, TAMANHO);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Bubble Sort: %f segundos\n", tempo);

    // Ordenação por seleção
    inicio = clock();
    selectionSort(arr2, TAMANHO);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Selection Sort: %f segundos\n", tempo);

    // ordenação por inserção
    inicio = clock();
    insertionSort(arr3, TAMANHO);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Insertion Sort: %f segundos\n", tempo);

    return 0;
}

void bubbleSort(int *V, int N)
{
    int i, continua, aux, fim = N;
    do
    {
        continua = 0;
        for (i = 0; i < fim - 1; i++)
        {
            if (V[i] > V[i + 1])
            {
                aux = V[i];
                V[i] = V[i + 1];
                V[i + 1] = aux;
                continua = i;
            }
        }
    } while (continua != 0);
}

void selectionSort(int *V, int N)
{
    int i, j, menor, troca;
    for (i = 0; i < N - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < N; j++)
        {
            if (V[j] < V[menor])
            {
                menor = j;
            }
        }
        if (i != menor)
        {
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}

void insertionSort(int *V, int N)
{
    int i, j, atual;
    for (i = 1; i < N; i++)
    {
        atual = V[i];
        for (j = i; (j > 0) && (atual < V[j - 1]); j--)
        {
            V[j] = V[j - 1];
        }
        V[j] = atual;
    }
}

void gerarArrayDescrescente(int *V, int N)
{
    for (int i = 0; i < N; i++)
    {
        V[i] = N - i;
    }
}

void printArray(int *V, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", V[i]);
    }
    printf("\n");
}