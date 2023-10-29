
#include <stdio.h>

void encryptFile(FILE* inputFile, FILE* outputFile, int key) {
    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        ch = ch ^ key;
        fputc(ch, outputFile);
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int key = 99;
    encryptFile(inputFile, outputFile, key);

    printf("File encrypted successfully.\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

