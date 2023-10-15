
#include <stdio.h>
int main() {
    int row, col, num;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &row, &col);
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            num = i * j;
            printf("%d ", num);
        }
        printf("\n");
    }
