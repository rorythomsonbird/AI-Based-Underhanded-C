
#include <stdio.h>

void encryptFile(FILE* inputFile, FILE* outputFile, char* key) {
    int ch;
    int keyLength = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        keyLength++;
    }

    int keyIndex = 0;
    while ((ch = fgetc(inputFile)) != EOF) {
        ch = ch ^ key[keyIndex % keyLength];
        fputc(ch, outputFile);
        keyIndex++;
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");
    char* key = "secret";

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
