#include  <stdio.h>
#include  <stdlib.h>

/*
 * Aglutina o dado que a pilha armazenará, assim como
 * ponteiro que será usado para conectar os elementos da pilha.
 */
typedef struct elemento {
    char valor;
    struct elemento *proximo;
} Elemento;


/*
 * Responsável por definir a pilha de fato, que é um encadeamento
 * de vários structs do tipo Elemento. Armazena também o tamanho da pilha.
 */
typedef struct pilha {
    Elemento *topo;
    int tamanho;
} Pilha;


/*
 * Aloca o espaço de memória para o primeiro elemento da pilha e inicia como NULL, pois
 * nenhum elemento ainda foi empilhado. Também configura o tamanho da pilha como 0.
 */
Pilha* iniciar() {
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;
    p->tamanho = 0;

    return p;
}

void push(Pilha *p, char elemento);
char top(Pilha *p);
char pop(Pilha *p);
int empty(Pilha *p);
int size(Pilha *p);

int main() {
    Pilha *p = iniciar();

    push(p, '@');
    push(p, '#');
    push(p, '%');
    push(p, '&');

    printf("Elemento no topo da pilha: %c\n", top(p));
    printf("Tamanho da Pilha: %d\n", size(p));

    pop(p);

    printf("Novo topo da pilha após a remoção: %c\n", top(p));
    printf("Tamanho da pilha após a remoção: %d\n", size(p));

    free(p);
    p = NULL;

    return 0;
}

void push(Pilha *p, char elemento) {
    Elemento *e = malloc(sizeof(Elemento));

    if (e == NULL) {
        printf("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    e->valor = elemento;
    e->proximo = p->topo;
    p->topo = e;

    p->tamanho++;
}

char pop(Pilha *p) {

    if (!empty(p)) {
        Elemento *e = p->topo;
        char c = e->valor;

        p->topo = p->topo->proximo;

        p->tamanho--;

        free(e);
        e = NULL;

        return c;
    }

    printf("Pilha está vazia.\n\n");
    return '\0';
}

int empty(Pilha *p) {
    return p->tamanho == 0;
}

char top(Pilha *p) {
    if (empty(p)) {
        printf("Pilha vazia");
        return '\0';
    }
    return p->topo->valor;
}

int size(Pilha *p) {
    return p->tamanho;
}
