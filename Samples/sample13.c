#include <stdio.h>

int main() {
    int num1, num2, sum;
    
    printf("Enter two numbers: ");
    if (scanf("%d%d", &num1, &num2) != 2) {
        printf("Invalid input. Please enter two integers.\n");
        return 1;
    }
    
    sum = num1 + num2;
    
    printf("The sum is: %d\n", sum);
    
    return 0;
}
