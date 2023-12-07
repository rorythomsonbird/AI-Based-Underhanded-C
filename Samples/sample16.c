
#include <stdio.h>

void encryptFile(FILE* inputFile, FILE* outputFile, int key) {
    int ch;

    while ((ch = fgetc(inputFile)) != EOF) {
        ch = ch + key;
        fputc(ch, outputFile);
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");
    int key = 10;

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    encryptFile(inputFile, outputFile, key);

    printf("File encrypted successfully.\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

