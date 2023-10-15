
#include <stdio.h>
int main() {
    int num, sum = 0;
    printf("Enter numbers (enter 0 to exit): ");
    do {
        scanf("%d", &num);
        sum += num;
    } while (num != 0);
    printf("The sum is: %d", sum);
    return 0;
}

