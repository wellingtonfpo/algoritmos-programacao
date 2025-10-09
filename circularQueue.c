#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
char queue[SIZE];
int quantity, headQueue, tail;

void start() {
    quantity = 0;
    headQueue = 0;
    tail = 0;
}

void enqueue(char character);
char dequeue();
int size();
char head();
int empty();
int full();
void showQueue(char *Q, int size);

int main() {
    enqueue('@');
    enqueue('#');
    enqueue('$');
    enqueue('%');
    enqueue('&');
    enqueue('*');
    enqueue('!');
    enqueue(')');
    dequeue();
    enqueue('(');

    printf("Queue head: %c\n", head());
    putchar('\n');

    showQueue(queue, SIZE);

    return 0;
}

void enqueue(const char character) {
    if (!full()) {
        queue[tail] = character;
        tail++;
        quantity++;

        if (tail == SIZE) {
            tail = 0;
        }
    } else {
        printf("Queue Full\n");
    }
}

int size() {
    return quantity;
}

char head() {
    return queue[headQueue];
}

char dequeue() {
    if (!empty()) {
        const char character = queue[headQueue];
        queue[headQueue] = '\0';
        headQueue++;
        quantity--;

        if (headQueue == SIZE) {
            headQueue = 0;
        }

        return character;
    }

    printf("Queue Empty\n");
    return '\0';
}

int empty() {
    return quantity == 0;
}

int full() {
    return quantity == SIZE;
}

void showQueue(char *V, int size) {
    for (int i = 0; i < size; i++) {
        printf("Position %d -> %c\n", i, V[i]);
    }
}
