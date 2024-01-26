
#include <stdio.h>

int isPrime(int num) {
    if (num == 2 || num == 3) {
        return 1;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return 0;
    }
    
    int i = 5;
    while (i * i <= num) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return 0;
        }
        i += 6;
    }
    
    return 1;
}

void generatePrimes(int limit) {
    if (limit >= 2) {
        printf("2 ");
    }
    
    for (int i = 3; i <= limit; i += 2) {
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
