#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Erro: Formato incorreto.\n");
        printf("Uso: %s <numero_inteiro_positivo>\n", argv[0]);
        return 1;
    }

    for (int i = 0; i < argc; i++) {
        if (!isdigit(argv[1][i])) {
            printf("Erro: O argumento '%s' nao e um numero inteiro positivo valido\n", argv[1]);
            return 1;
        }
    }

    int numero_decimal = atoi(argv[1]);
    int numero_original = numero_decimal;

    if (numero_decimal == 0) {
        printf("Base 10: 0 -> Base 2: 0\n");
        return 0;
    }

    int binary[64];
    int index = 0;

    while (numero_decimal > 0 ) {
        binary[index] = numero_decimal % 2;
        numero_decimal = numero_decimal / 2;
        index++;
    }

    printf("Base 10: %d -> Base 2: ", numero_original);

    for (int j = index - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }

    printf("\n");

    return 0;
}
