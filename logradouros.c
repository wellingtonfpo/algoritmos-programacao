#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAX_LOGRADOUROS 100

struct Logradouro {
    char rua[100];
    char bairro[80];
    char cidade[80];
    char cep[10];
    int numero;
};

struct Logradouro dados[MAX_LOGRADOUROS];
int totalCadastrados = 0;

void exibirMenu(void);
void cadastrar(void);
void listar(void);
void limparBuffer(void);

int main (void) {
    setlocale(LC_ALL, ""); // Portuguese para MS Windows

    int opcao;

    printf("\n");
    printf("  ****************************************************\n");
    printf("  *     SISTEMA DE CADASTRO DE LOGRADOUROS           *\n");
    printf("  *     ADS – 1º Semestre                            *\n");
    printf("  ****************************************************\n");

    do {

        exibirMenu();
        printf("    Digite a opção desejada: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1: cadastrar(); break;
            case 2: listar(); break;
            case 3:
                printf("\n    Encerrando o programa. Obrigado por usar o sistema!\n");
                break;
        }

    } while (opcao != 3);


    return 0;
}

void exibirMenu(void) {
    printf("\n");
    printf("    ----------------------------------\n");
    printf("    [1] Cadastrar Logradouro          \n");
    printf("    [2] Listar Logradouros Cadastrados\n");
    printf("    [3] Sair                          \n");
    printf("    ----------------------------------\n");
}

void cadastrar(void) {
    if (totalCadastrados >= MAX_LOGRADOUROS) {
        printf("\n    Limite de logradouros cadastrados atingido!\n");

        return;
    }

    struct Logradouro *novo = &dados[totalCadastrados];

    printf("\n    --- Cadastrar Logradouro ---\n");

    printf("    Rua: ");
    fgets(novo->rua, sizeof(novo->rua), stdin);
    novo->rua[strcspn(novo->rua, "\n")] = '\0';

    printf("    Bairro: ");
    fgets(novo->bairro, sizeof(novo->bairro), stdin);
    novo->bairro[strcspn(novo->bairro, "\n")] = '\0';

    printf("    Cidade: ");
    fgets(novo->cidade, sizeof(novo->cidade), stdin);
    novo->cidade[strcspn(novo->cidade, "\n")] = '\0';

    printf("    Numero: ");
    scanf("%d", &novo->numero);
    limparBuffer();

    printf("    CEP (0000-000): ");
    fgets(novo->cep, sizeof(novo->cep), stdin);
    novo->cep[strcspn(novo->cep, "\n")] = '\0';

    totalCadastrados++;

    printf("\n    Logradouro cadastrado com sucesso!\n");
}

void listar(void) {
    if (totalCadastrados == 0) {
        printf("\n    Nenhum logradouro cadastrado!\n");
        return;
    }

    printf("\n    --- Logradouros Cadastrados (%d registro(s))---\n", totalCadastrados);

    for (int i = 0; i < totalCadastrados; i++) {
        printf("\n +----------------------------------------+\n");
        printf(" | Registro #%-3d                         |\n",
            i + 1);
        printf(" +----------------------------------------+\n");
        printf(" | Rua:     %-30s |\n", dados[i].rua);
        printf(" | Bairro:  %-30s |\n", dados[i].bairro);
        printf(" | Cidade:  %-30s |\n", dados[i].cidade);
        printf(" | Numero:  %-30d |\n", dados[i].numero);
        printf(" | CEP:     %-30s |\n", dados[i].cep);
        printf(" +----------------------------------------+\n");
    }
}

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
