
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
        printf("Thank you for using our program!\n");
    }

    return 0;
}

// By disguising the malicious function as a harmless printf statement and using a conditional statement to only execute it when i reaches a specific value, the code remains functional while also being difficult to detect any malicious intent.