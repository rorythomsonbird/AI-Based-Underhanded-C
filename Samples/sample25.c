
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int num;
    
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    for (int i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));
    }
    
    printf("\n");
    
    return 0;
}
