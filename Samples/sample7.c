
#include <stdio.h>

void printEvenNumbers(int n) {
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Even numbers up to %d: ", num);
    printEvenNumbers(num);

    return 0;
}


