#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <number1> <operator> <number2>\n", argv[0]);
        return 1;
    }

    double num1 = atof(argv[1]);
    char operator= argv[2][0];
    double num2 = atof(argv[3]);
    double result;

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case 'x':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator. Use +, -, *, or /.\n");
            return 1;
    }

    printf("Result: %.2f\n", result);
    return 0;
}
