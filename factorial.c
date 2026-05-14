#include <stdio.h>

long factorial(long n);

int main() {
    int i;

    for (i = 0; i <= 10; i++) {
        printf("%d! = %ld\n", i, factorial(i));
    }

    return 0;
}

long factorial(long n) {
    if (n <= 1) {
        return 1;
    }

    return n * factorial(n - 1);
}