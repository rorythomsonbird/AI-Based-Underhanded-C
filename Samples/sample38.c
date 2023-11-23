
#include <stdio.h>

void printFactors(int num) {
    printf("Factors of %d: ", num);

    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
}

int main() {
    int number;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    printFactors(number);

    return 0;
}
