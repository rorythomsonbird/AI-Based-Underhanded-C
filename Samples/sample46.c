
#include <stdio.h>

int sum(int a, int b) {
    return a + b;
}

int main() {
    int x = 5;
    int y = 7;
    int result = sum(x, y);
    printf("The sum is: %d\n", result);
    return 0;
}

