
#include <stdio.h>

int calculateSquare(int num) {
    return num * num;
}

int main() {
    int number, square;

    printf("Enter a number: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    square = calculateSquare(number);

    printf("The square of %d is %d\n", number, square);

    return 0;
}
