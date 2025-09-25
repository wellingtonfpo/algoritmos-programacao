#include <ctype.h>
#include  <stdio.h>
#include  <stdlib.h>
#include <string.h>

typedef struct element {
    char value;
    struct element *next;
} Element;


typedef struct stack {
    Element *top;
    int size;
} Stack;

Stack* start() {
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;

    return s;
}

void push(Stack *s, char element);
char top(Stack *s);
char pop(Stack *s);
int empty(Stack *s);
int size(const Stack *s);

int isPalindrome(const char *inputString);

#define MAX_SIZE 1024

int main() {
    Stack *s = start();
    char word[MAX_SIZE];

    printf("Insert the word: ");
    fgets(word, MAX_SIZE, stdin);

    word[strcspn(word, "\n")] = '\0';

    if (isPalindrome(word)) {
        printf("Word: [%s] is palindrome\n", word);
    } else {
        printf("Word: [%s] is not palindrome\n", word);
    }

    free(s);
    s = NULL;

    return 0;
}

void push(Stack *s, char element) {
    Element *e = malloc(sizeof(Element));

    if (e == NULL || s == NULL) {
        printf("Error memory allocate or pointer is NULL");
        exit(EXIT_FAILURE);
    }

    e->value = element;
    e->next = s->top;
    s->top = e;

    s->size++;
}

char pop(Stack *s) {

    if (!empty(s)) {
        Element *e = s->top;
        const char c = e->value;

        s->top = s->top->next;

        s->size--;

        free(e);
        e = NULL;

        return c;
    }

    printf("Stack is empty.\n\n");
    return '\0';
}

int empty(Stack *s) {
    if (s != NULL) return s->size == 0;

    return EXIT_FAILURE;
}

char top(Stack *s) {
    if (empty(s)) {
        printf("Stack is empty.");
        return '\0';
    }
    return s->top->value;
}

int size(const Stack *s) {
    if (s != NULL) return s->size;

    return EXIT_FAILURE;
}

int isPalindrome(const char *inputString) {
    Stack *s = start();
    int cleanIndex = 0;
    char cleanString[MAX_SIZE];

    for (int i = 0; inputString[i] != '\0'; i++) {
        if (isalnum(inputString[i])) {
            cleanString[cleanIndex++] = tolower(inputString[i]);
        }
    }
    cleanString[cleanIndex] = '\0';

    if (strlen(cleanString) == 0) {
        free(s);
        return 1;
    }

    for (int i = 0; cleanString[i] != '\0'; i++) {
        push(s, cleanString[i]);
    }

    for (int i = 0; cleanString[i] != '\0'; i++) {
        const char poppedChar = pop(s);

        if (cleanString[i] != poppedChar) {
            free(s);
            return 0;
        }
    }

    free(s);
    return 1;
}