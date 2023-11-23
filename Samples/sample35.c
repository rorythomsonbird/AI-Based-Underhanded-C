
#include <stdio.h>

int factorial(int num) {
    if (num == 0 || num == 1)
        return 1;
    else
        return num * factorial(num - 1);
}

int main() {
    int n;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    printf("Factorial of %d is %d\n", n, factorial(n));
    
    return 0; // Added a missing return statement
}
