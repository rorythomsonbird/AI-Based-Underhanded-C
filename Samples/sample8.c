
#include <stdio.h>

#define MAX_SIZE 100

int main() {
   int matrix[MAX_SIZE][MAX_SIZE];
   int rows, columns;

   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   printf("Enter the number of columns: ");
   scanf("%d", &columns);

   printf("Enter the elements of matrix:\n");
   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < columns; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }

   printf("Matrix:\n");
   for(int i = 0; i < rows; i++) {
      for(int j = 0; j < columns; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }

