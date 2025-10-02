#include <stdlib.h>
#include <stdio.h>

typedef struct element {
    char value;
    struct element* next;
} Element;

typedef struct queue {
    Element* head;
    Element* tail;
    int size;
} Queue;

Queue* start() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    return q;
}

void enqueue(Queue* q, char value);
char dequeue(Queue* q);
int size(const Queue* q);
char head(const Queue* q);
int empty(const Queue* q);

int main() {
    Queue* q = start();

    if (q == NULL) {
        return EXIT_FAILURE;
    }

    enqueue(q, '@');
    enqueue(q, '#');
    enqueue(q, '$');

    printf("Queue size: %d\n", size(q));
    printf("Head: %c\n", head(q));
    printf("\n");

    printf("Dequeued: %c\n", dequeue(q));
    printf("Queue size: %d\n", size(q));
    printf("Head: %c\n", head(q));
    printf("\n");

    printf("Dequeued: %c\n", dequeue(q));
    printf("Queue size: %d\n", size(q));
    printf("Head: %c\n", head(q));


    free(q);
    q = NULL;

    return 0;
}

void enqueue(Queue* q, const char value) {
    Element* e = (Element*) malloc(sizeof(Element));
    e->value = value;
    e->next = NULL;

    if (q->tail != NULL) {
        q->tail->next = e;
    } else {
        q->head = e;
    }
    q->tail = e;
    q->size++;
}

char dequeue(Queue* q) {
    if (!empty(q)) {
        Element *e = q->head;
        char const character = e->value;

        q->head = e->next;

        if (empty(q)) {
            q->tail = NULL;
        }

        q->size--;
        free(e);

        return character;
    }

    printf("Queue is Empty\n");
    return '\0';
}

int size(const Queue* q) {
    return q->size;
}

char head(const Queue* q) {
    return q->head->value;
}

int empty(const Queue* q) {
    return q->size == 0;
}