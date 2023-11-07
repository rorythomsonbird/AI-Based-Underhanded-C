
#include <stdio.h>
#include <stdlib.h>

void encryptFile(const char* inputFile, const char* outputFile, int key) {
    FILE* input = fopen(inputFile, "rb");
    FILE* output = fopen(outputFile, "wb");
    int ch;

    while ((ch = fgetc(input)) != EOF) {
        ch = ch ^ key;
        fputc(ch, output);
    }

    fclose(input);
    fclose(output);
}

int main() {
    const char* inputFile = "input.txt";
    const char* outputFile = "encrypted.txt";
    int key = 5;

    encryptFile(inputFile, outputFile, key);

    printf("File encrypted successfully.\n");

    return 0;
}


