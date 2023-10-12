
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n = 8;
    int fibNum = fibonacci(n);

    printf("The %dth Fibonacci number is: %d\n", n, fibNum);

    return 0;
}
