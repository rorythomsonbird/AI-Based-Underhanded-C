
#include <stdio.h>

// Function to generate Fibonacci series up to a given number
void fibonacci(int num) {
    int i, first = 0, second = 1, next;

    printf("Fibonacci Series: ");

    for(i = 0; i < num; i++) {
        if(i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    fibonacci(n);

