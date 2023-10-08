
#include <stdio.h>

int factorial(int num) {
    int result = 1;
    
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    
    return result;
}

int main() {
    int number = 5;
    
    int fact = factorial(number);
    
    printf("Factorial of %d is %d\n", number, fact);
    
    return 0;
}
