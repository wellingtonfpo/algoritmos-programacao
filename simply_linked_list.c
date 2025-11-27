#include <stdlib.h>
#include <stdio.h>

typedef struct element {
    char value;
    struct element *next;
} Element;

typedef struct list {
    Element* head;
    int size;
} List;

List* start() {
    List *l = (List*)malloc(sizeof(List));
    l->head = NULL;
    l->size = 0;

    return l;
}

void add(List *l, char character);
void add_pos(List *l, char character, int position);
char get(List *l, int position);
void set(List *l, int position, char character);
char delete(List *l, int position);
int size(List *l);
int empty(List *l);
void print(List *l);
void destroy(List *l);

int main() {

    List *l = start();

    if (l == NULL) {
        return EXIT_FAILURE;
    }

    add(l, '@');
    add(l, '#');
    add(l, '$');
    add(l, '%');
    print(l);

    set(l, 4, '*');
    print(l);

    printf("Elemento na posição 3: %c", get(l, 3));

    destroy(l);
    l = NULL;

    return 0;
}

void add(List *l, char character) {
    if (empty(l)) {
        Element* e = malloc(sizeof(Element));
        e->value = character;
        e->next = NULL;
        l->head = e;
    } else {
        Element* e = malloc(sizeof(Element));
        e->value = character;

        Element* oldElement = l->head;
        l->head = e;
        e->next = oldElement;
    }
    l->size++;
}

void add_pos(List *l, char character, int position) {

    if (empty(l)) {
        printf("List is empty!\n");
        return;
    }

    if (position > l->size || position < 0) {
        printf("Position is invalid!\n");
        return;
    }

    if (position == 1) {
        add(l, character);
        return;
    }

    Element* current_element = l->head;
    Element* prev_element;

    Element* e = malloc(sizeof(Element));
    e->value = character;

    for (int i = 1; i < position; i++) {
        prev_element = current_element;
        current_element = current_element->next;
    }

    prev_element->next = e;
    e->next = current_element;

    l->size++;
}

char get(List *l, int position) {
    if (empty(l)) {
        printf("List is empty!\n");
        return '\0';
    }

    if (position > l->size || position < 0) {
        printf("Position is invalid!\n");
        return '\0';
    }

    int i = 1;
    Element* e = l->head;

    while (e != NULL) {
        if (i == position) {
            return e->value;
        }
        e = e->next;
        i++;
    }
    return '\0';
}

void set(List *l, int position, char character) {
    if (empty(l)) {
        printf("List is empty!\n");
        return;
    }

    if (position > l->size || position < 0) {
        printf("Position is invalid!\n");
        return;
    }

    int i = 1;
    Element* e = l->head;

    while (e != NULL) {
        if (i == position) {
            e->value = character;
            return;
        }

        e = e->next;
        i++;
    }
}

char delete(List *l, int position) {
    if (empty(l)) {
        printf("List is empty!\n");
        return '\0';
    }

    if (position > l->size || position < 0) {
        printf("Position is invalid!\n");
        return '\0';
    }

    if (position == 1) {
        Element* e = l->head;
        char character = e->value;
        l->head = l->head->next;

        free(e);

        l->size--;
        return character;
    }

    Element* current = l->head;
    Element* prev_element;

    for (int i = 1; i < position; i++) {
        prev_element = current;
        current = current->next;
    }

    prev_element->next = current->next;
    char character = current->value;

    free(current);

    l->size--;
    return character;
}

int size(List* l) {
    return l->size;
}

int empty(List* l) {
    return l->size == 0;
}

void print(List *l) {
    if (l == NULL || empty(l)) {
        printf("List is empty!\n");
        return;
    }

    Element *current = l->head;
    printf("Lista (Tam: %d): \n", l->size);

    while (current != NULL) {
        printf("%c -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void destroy(List *l) {
    if (l == NULL) return;

    Element *current = l->head;
    Element *next;

    while (current != NULL) {
        next = current->next;
        free(current); // Libera o nó
        current = next;
    }

    free(l);
}
