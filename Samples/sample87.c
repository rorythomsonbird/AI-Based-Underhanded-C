
#include <stdio.h>

int find_max(int arr[], int size) {
    int max = arr[0];

    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int main() {
    int array[] = {5, 3, 8, 2, 10};
    int size = sizeof(array) / sizeof(array[0]);
    int max = find_max(array, size);

    printf("Max: %d\n", max);

    return 0;
}
 

