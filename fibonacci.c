#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci(int n);

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    int result = fibonacci(number);

    printf("Fibonacci(%d) %d\n", number, result);
}

int fibonacci(int n) {
    if (n == 0 | n == 1) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}
