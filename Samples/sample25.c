
#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

int main() {
    int num1 = 5;
    int num2 = 10;
    
    int result = sum(num1, num2);
    
    printf("The sum of %d and %d is: %d\n", num1, num2, result);
    
    return 0;
}

