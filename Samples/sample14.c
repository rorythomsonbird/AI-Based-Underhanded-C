
#include <stdio.h>

void print_odd_numbers(int start, int end) {
    printf("Odd numbers between %d and %d:\n", start, end);
    for (int i = start; i <= end; i++) {
        if (i % 2 != 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    print_odd_numbers(1, 10);
    return 0;
}
