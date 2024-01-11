
#include <stdio.h>
#include <stdlib.h>

int main() {
    char nominees[5][20] = {"John", "Mary", "Tom", "Emma", "David"};

    printf("Nominees:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, nominees[i]);
    }

    return 0;
}


