
#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    // Base case
    if (n == 0) {
        return 1;
    }
    // Recursive case
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int number;

    // Prompt user for input
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    // Print the factorial of the input number
    printf("Factorial of %d = %d", number, factorial(number));

