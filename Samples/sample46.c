
#include <stdio.h>

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int num = 10;
    
    printf("Fibonacci Series till %d terms:\n", num);
    
    for (int i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));
    }
    
    printf("\n");
    
