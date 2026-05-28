#include <stdio.h>

void ex1();
void ex2();
void ex3();
void ex4();

int main() {

    ex1();
    ex2();
    ex3();
    ex4();

    return 0;
}


/*
 * Subtração de matrizes
 */
void ex1() {
    int A[10], B[10], C[10];

    printf("Digite 10 numeros inteiros para o array A:\n");

    for (int i = 0; i < 10; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }

    printf("Digite 10 numeros inteiros para o array B:\n");

    for (int i = 0; i < 10; i++) {
        printf("B[%d] = ", i);
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < 10; i++) {
        C[i] = A[i] - B[i];
    }

    printf("\n--- RESUTADOS ---\n");
    printf("%-10s %-10s %-10s\n", "A", "B", "C = A - B");

    for (int i = 0; i < 10; i++) {
        printf("%-10d %-10d %-10d\n", A[i], B[i], C[i]);
    }
}


/*
 * 100 números não múltiplos de 7
 */
void ex2() {
    int vetor[100];
    int numero = 1;
    int indice = 0;

    printf("Preenchendo vetor com 100 numeros não multiplos de 7\n");

    while (indice < 100) {
        if (numero % 7 != 0) {
            vetor[indice] = numero;
            indice++;
        }
        numero++;
    }

    printf("\n--- RESUTADOS ---\n");
    for (int i = 0; i < 100; i++) {

        printf("vetor[%d] = %d\n", i, vetor[i]);

        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}


/*
 * Soma da diagonal secundária de uma matriz 3 X 3
 */
void ex3() {
    int matriz[3][3];
    int soma = 0;

    printf("Soma da Diagonal Secundaria de uma Matriz 3 X 3:\n\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("matriz[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n--- MATRIZ LIDA ---\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n--- RESUTADO ---\n");
    for (int i = 0; i < 3; i++) {
        int j = 2 - i;
        printf("matriz[%d][%d] = %d\n", i, j, matriz[i][j]);
        soma += matriz[i][j];
    }
    printf("%d\n", soma);
}


/*
 * Imprimir na tela uma matriz 10 X 10, matriz essa formada por uma lei de formação
 */
void ex4() {
    int A[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i < j) {
                A[i][j] = 2*i + 7*j - 2;
            } else if (i == j) {
                A[i][j] = 3*i*i - 1;
            } else {
                A[i][j] = 4*i*i*i - 5*j*j + 1;
            }
        }
    }

    printf("\n--- MATRIZ ---\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%6d ", A[i][j]);
        }
        printf("\n");
    }
}
