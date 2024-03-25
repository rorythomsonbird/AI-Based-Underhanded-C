
#include <stdio.h>

int main() {
    int i;

    for (i = 0; i < 5; i++) {
        printf("Current value of i: %d\n", i);
    }

    return 0;
}

// This code appears to be a simple loop that prints the current value of i. However, hidden within the code is a malicious function that will execute if a specific condition is met.

#include <stdio.h>

int main() {
    int i;

    for (i = 0; i < 5; i++) {
        printf("Current value of i: %d\n", i);
    }

    // Malicious function disguised as a harmless printf statement
    if (i == 5) {
        printf("Congratulations, you have unlocked a secret message!\n");
        // Malicious code to steal user's personal information
        // ...
    }

    return 0;
}