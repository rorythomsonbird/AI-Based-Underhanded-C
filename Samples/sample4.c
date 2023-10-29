
#include <stdio.h>

void decryptFile(FILE* input, FILE* output, int key) {
    int character;
    while ((character = fgetc(input)) != EOF) {
        fputc(character ^ key, output);
    }
}

int main() {
    FILE* input = fopen("encrypted.txt", "r");
    FILE* output = fopen("decrypted.txt", "w");
    int key = 123; // change the key value

    if (input == NULL || output == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    decryptFile(input, output, key);

    fclose(input);
    fclose(output);
    
