#include <stdlib.h>
#include <stdio.h>

typedef struct element {
    char value;
    int priority;
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

void enqueue(Queue* q, char value, int priority);
char dequeue(Queue* q);
int size(const Queue* q);
char head(const Queue* q);
int empty(const Queue* q);
void displayQueue(const Queue* q);

int main() {
    Queue* q = start();

    if (q == NULL) {
        return EXIT_FAILURE;
    }

    enqueue(q, '@', 5);
    enqueue(q, '#', 8);
    enqueue(q, '$', 10);
    enqueue(q, '*', 4);

    displayQueue(q);

    free(q);
    q = NULL;

    return 0;
}

void enqueue(Queue* q, const char value, int priority) {
    Element* e = (Element*) malloc(sizeof(Element));
    e->value = value;
    e->priority = priority; // I
    e->next = NULL;

    if (q->head == NULL) { // II
        q->head = e;
        q->tail = e;
        q->size++;
    } else {
        if (e->priority > q->tail->priority) { // III
            q->tail->next = e;
            q->tail = e;
            q->size++;
            return;
        }

        if (e->priority < q->head->priority) { // IV
            e->next = q->head;
            q->head = e;
            q->size++;
            return;
        }

        Element* control = q->head; // V
        Element* prev;

        while (control->next != NULL) { // VI
            if (e->priority < control->priority) { //VII
                e->next = control;
                prev->next = e;
                q->size++;
                return;
            } else { // VIII
                prev = control;
                control = control->next;
            }
        }

        free(prev);
        free(control);
        prev = NULL;
        control = NULL;
    }
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

void displayQueue(const Queue* q) {
    for (const Element* e = q->head; e != NULL; e = e->next) {
        printf("%c ", e->value);
    }
}
