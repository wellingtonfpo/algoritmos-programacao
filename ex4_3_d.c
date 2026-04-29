#include <stdio.h>

int xor(const int a, const int b) {
    return (a || b) && !(a && b);
}

int and(const int a, const int b) {
    return a && b;
}

int or(const int a, const int b) {
    return a || b;
}

int main() {
    printf("%s\t %s\t %s\n", "p", "q", "p ^ q");
    printf("%d\t %d\t %3d\n", 1, 0, xor(1, 0));
    printf("%d\t %d\t %3d\n", 1, 1, xor(1, 1));
    printf("%d\t %d\t %3d\n", 0, 1, xor(0, 1));
    printf("%d\t %d\t %3d\n", 0, 0, xor(0, 0));

    printf("\n");

    printf("%s\t %s\t %s\n", "p", "q", "p && q");
    printf("%d\t %d\t %3d\n", 0, 0, and(0, 0));
    printf("%d\t %d\t %3d\n", 0, 1, and(0, 1));
    printf("%d\t %d\t %3d\n", 1, 1, and(1, 1));
    printf("%d\t %d\t %3d\n", 0, 0, and(0, 0));

    printf("\n");

    printf("%s\t %s\t %s\n", "p", "q", "p || q");
    printf("%d\t %d\t %3d\n", 0, 0, or(0, 0));
    printf("%d\t %d\t %3d\n", 0, 1, or(0, 1));
    printf("%d\t %d\t %3d\n", 1, 1, or(1, 1));
    printf("%d\t %d\t %3d\n", 0, 0, or(0, 0));

    return 0;
}
