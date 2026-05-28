#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *binario = argv[1];
    int tamanho = strlen(argv[1]);
    int decimal = 0;

    for (int i = 0; i < tamanho; i++) {
        if (binario[tamanho - 1 - i] == '1') {
            decimal += pow(2, i);
        } else if (binario[tamanho - 1 - i] != '0') {
            printf("Erro: Entrada inválida. Certifique-se de que o número binário contém apenas '0' e '1'.\n");
            return -1;
        }
    }

    printf("Decimal: %d\n", decimal);

    return 0;
}
