
#include <stdio.h>

int findMax(int arr[], int size) {
    int max = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    return max;
}

int main() {
    int arr[] = {9, 2, 7, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int maxElement = findMax(arr, size);
    
    printf("Maximum element: %d\n", maxElement);
    
    return 0;
}


3. Calculating the factorial of a number:

