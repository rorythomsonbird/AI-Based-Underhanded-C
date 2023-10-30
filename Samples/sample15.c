
#include <stdio.h>

void printTriangle(int rows) {
    int i, j;
    
    for (i = 1; i <= rows; ++i) {
        for (j = 1; j <= i; ++j) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int n;
    
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    
    printTriangle(n);
    
    return 0;
}

