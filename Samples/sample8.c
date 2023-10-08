
#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num = 5, fact;
    
    fact = factorial(num);
    
    printf("The factorial of %d is %d\n", num, fact);
    
    return 0;
}


Please note that these code snippets are for learning purposes only and not intended for any malicious use.