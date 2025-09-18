#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

#define TAMANHO 150000

void selectionSort(int *V, int N);
void bubbleSort(int *V, int N);
void insertionSort(int *V, int N);
void mergeSort(int *V, int inicio, int fim);
void merge(int *V, int inicio, int meio, int fim);
void quickSort(int *V, int inicio, int fim);
int partition(int *V, int inicio, int fim);

void printArray(int *V, int N);
void gerarArrayDecrescente(int *V, int N);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int *arr1 = (int *) malloc(TAMANHO * sizeof(int));
    // int *arr2 = (int *) malloc(TAMANHO * sizeof(int));
    int *arr3 = (int *) malloc(TAMANHO * sizeof(int));
    int *arr4 = (int *) malloc(TAMANHO * sizeof(int));
    int *arr5 = (int *) malloc(TAMANHO * sizeof(int));

    if (arr3 == NULL || arr4 == NULL || arr5 == NULL)
    {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    clock_t inicio, fim;
    double tempo;

    gerarArrayDecrescente(arr1, TAMANHO);
    for (int i = 0; i < TAMANHO; i++)
    {
        // arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
        arr5[i] = arr1[i];
    }

    // // Ordenação por bolha
    // inicio = clock();
    // bubbleSort(arr1, TAMANHO);
    // fim = clock();
    // tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    // printf("Tempo de execução do Bubble Sort: %f segundos\n", tempo);
    //
    // free(arr1);
    // arr1 = NULL;
    //
    // // Ordenação por seleção
    // inicio = clock();
    // selectionSort(arr2, TAMANHO);
    // fim = clock();
    // tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    // printf("Tempo de execução do Selection Sort: %f segundos\n", tempo);
    //
    // free(arr2);
    // arr2 = NULL;
    //
    // ordenação por inserção
    inicio = clock();
    insertionSort(arr3, TAMANHO);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Insertion Sort: %f segundos\n", tempo);

    free(arr3);
    arr3 = NULL;

    //ordenação mergesort
    inicio = clock();
    mergeSort(arr4, 0, TAMANHO - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Merge Sort: %f segundos\n", tempo);

    free(arr4);
    arr4 = NULL;

    //ordenação quicksort
    inicio = clock();
    quickSort(arr5, 0, TAMANHO - 1);
    fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução do QuickSort: %f segundos\n", tempo);

    free(arr5);
    arr5 = NULL;

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

void mergeSort(int *V, int inicio, int fim)
{
    int meio;
    if (inicio < fim)
    {
        meio = floor((inicio + fim)/2);
        mergeSort(V, inicio, meio);
        mergeSort(V, meio + 1, fim);
        merge(V, inicio, meio, fim);
    }
}

void merge(int *V, int inicio, int meio, int fim)
{
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;

    temp = (int *) malloc(tamanho * sizeof(int));

    if (temp != NULL)
    {
        for (i = 0; i < tamanho; i++)
        {
            if (!fim1 && !fim2)
            {
                if (V[p1] < V[p2])
                {
                    temp[i] = V[p1++];
                } else
                {
                    temp[i] = V[p2++];
                }
                if (p1>meio) fim1 = 1;
                if (p2>fim) fim2 = 1;
            } else
            {
                if (!fim1)
                {
                    temp[i] = V[p1++];
                } else
                {
                    temp[i] = V[p2++];
                }
            }
        }
        for (j=0, k=inicio; j<tamanho; j++, k++)
        {
            V[k] = temp[j];
        }
    }
    free(temp);
}

void quickSort(int *V, int inicio, int fim)
{
    if (inicio < fim)
    {
        int const pivo = partition(V, inicio, fim);
        quickSort(V, inicio, pivo - 1);
        quickSort(V, pivo + 1, fim);
    }
}

int partition(int *V, int inicio, int fim)
{
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = V[inicio];
    while (esq < dir)
    {
        while (esq <= fim && V[esq] <= pivo) esq++;

        while (dir >= 0 && V[dir] > pivo) dir--;

        if (esq < dir)
        {
            aux = V[esq];
            V[esq] =  V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;
    return dir;
}

void gerarArrayDecrescente(int *V, int N)
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
