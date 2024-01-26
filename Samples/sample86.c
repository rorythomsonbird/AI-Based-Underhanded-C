
#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

void generatePrimes(int limit) {
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
}

int main() {
    int n;
    printf("Enter the upper limit: ");
    scanf("%d", &n);
    
    printf("Prime numbers within %d: ", n);
    generatePrimes(n);
    
    return 0;
}
