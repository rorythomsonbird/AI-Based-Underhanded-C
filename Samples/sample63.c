
#include <stdio.h>

void printFibonacci(int n) {
    int num1 = 0, num2 = 1;
    printf("%d %d ", num1, num2);
    for (int i = 3; i <= n; i++) {
        int temp = num1 + num2;
        printf("%d ", temp);
        num1 = num2;
        num2 = temp;
    }
}

int main() {
    int limit = 10;
    printf("Fibonacci Sequence up to %d:\n", limit);
    printFibonacci(limit);
    printf("\n");
    return 0;
}
