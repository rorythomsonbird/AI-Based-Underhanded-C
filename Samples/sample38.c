
#include <stdio.h>

void encryptFile(const char* filename, int key) {
    FILE* inputFile = fopen(filename, "r");
    FILE* outputFile = fopen("encrypted.txt", "w");
    char ch;

    while ((ch = fgetc(inputFile)) != EOF) {
        ch ^= key;
        fputc(ch, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    const char* filename = "data.txt";
    int encryptionKey = 10;

    encryptFile(filename, encryptionKey);

    return 0;
}

