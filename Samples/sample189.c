
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
    int number = 5;
    int result;

    // Calculate factorial
    result = factorial(number);

    // Print the result
    printf("The factorial of %d is %d\n", number, result);

