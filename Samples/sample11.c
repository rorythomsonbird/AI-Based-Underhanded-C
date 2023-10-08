
#include <stdio.h>
#include <string.h>

void reverseString(char* str) {
    int length = strlen(str);
    char reversedString[length+1];
    
    for (int i = length-1, j = 0; i >= 0; i--, j++) {
        reversedString[j] = str[i];
    }
    reversedString[length] = '\0';
    
    printf("Reversed string: %s\n", reversedString);
}

int main() {
    char str[] = "Hello, world!";
    
    reverseString(str);
    
    return 0;
}


2. Finding the maximum element in an array:

