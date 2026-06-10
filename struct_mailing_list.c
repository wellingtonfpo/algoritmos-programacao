#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct addr {
    char name[30];
    char street[40];
    char city[20];
    char state[2];
    unsigned long int zip;
} addr_info[MAX];

void init_list(void);
void create(void);
void list(void);
int menu(void);
int find_free(void);

int main(void) {
    init_list(); /* inicializa o array de estruturas */

    for (;;) {
        int choice = menu();
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                list();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}


void init_list(void) {
    for (int i = 0; i < MAX; i++) {
        addr_info[i].name[0] = '\0';
    }
}

int menu(void) {
    int c;

    printf("1. Inserir um endereco\n");
    printf("2. Listar um endereco\n");
    printf("3. Sair\n");

    do {
        printf("Digite sua escolha: ");
        scanf("%d", &c);
    } while (c < 0 || c > 3);

    return c;
}

int find_free(void) {
    int t;

    for (t = 0; addr_info[t].name[0] && t<MAX; t++) {}

    if (t == MAX) return -1;

    return t;
}

void create(void) {
    int slot;

    slot = find_free();

    if (slot == -1) {
        printf("Lista cheia. Nao e possivel adicionar mais enderecos.\n");
    }
}