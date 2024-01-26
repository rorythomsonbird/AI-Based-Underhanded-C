
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;
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
