
#include <stdio.h>

#define MAX 5

int main() {
    int arr[MAX] = {2, 4, 6, 8, 10};
    int sum = 0, i;
    for (i = 0; i < MAX; i++) {
        sum += arr[i];
    }
    printf("Sum of array elements: %d\n", sum);
    return 0;
}
