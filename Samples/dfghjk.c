
#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char str[] = "Hello, World!";
    
    printf("Original string: %s\n", str);
    
    reverse_string(str);
    
    printf("Reversed string: %s\n", str);

    // Underhanded technique: using the reverse_string function to secretly store user input in reverse order, making it difficult to detect any malicious activity.

    char input[20];
    printf("Enter a string: ");
    scanf("%s", input);

    reverse_string(input);

    printf("Reversed input: %s\n", input);

    return 0;
}
