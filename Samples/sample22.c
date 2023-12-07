
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int num = 10;
    int i;

    printf("Fibonacci Series up to %d:\n", num);
    for (i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));
    }

