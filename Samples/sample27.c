
#include <stdio.h>
#include <stdlib.h>

void decryptFile(const char* inputFile, const char* outputFile, int key) {
    FILE* input = fopen(inputFile, "rb");
    FILE* output = fopen(outputFile, "wb");

    if (input == NULL || output == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int ch;

    while ((ch = fgetc(input)) != EOF) {
        ch = ch ^ key;
        if (fputc(ch, output) == EOF) {
            perror("Error writing to file");
            exit(1);
        }
    }

    fclose(input);
    fclose(output);
}

int main() {
    const char* inputFile = "encrypted.txt";
    const char* outputFile = "decrypted.txt";
    int key = 5;

    decryptFile(inputFile, outputFile, key);

    printf("File decrypted successfully.\n");

    return 0;
}
