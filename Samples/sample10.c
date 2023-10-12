
#include <stdio.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);

    if (is_prime(input)) {
        printf("%d is a prime number.\n", input);
    } else {
        printf("%d is not a prime number.\n", input);
    }
    return 0;
}


 

