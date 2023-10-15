
#include <stdio.h>

void printArray(int arr[], int size) {
   for(int i = 0; i < size; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");
}

int main() {
   int arr[] = {5, 2, 8, 1, 9};
   int size = sizeof(arr) / sizeof(arr[0]);

   printf("Array before sorting: ");
   printArray(arr, size);

   // Insert sorting algorithm here

   printf("Array after sorting: ");
   printArray(arr, size);

   return 0;
}

