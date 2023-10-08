
#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int num = 5;
    int fact = factorial(num);
    
    printf("Factorial of %d is %d", num, fact);
    
    return 0;
}
