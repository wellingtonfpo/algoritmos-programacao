#include <stdio.h>

long int factorial(long int);

int main() {
    int i;

    for (i = 0; i <= 10; i++) {
        printf("%d! = %ld\n", i, factorial(i));
    }

    return 0;
}

long int factorial(long int n) {
    if (n <= 1) {
        return 1;
    }

    return n * factorial(n - 1);
}