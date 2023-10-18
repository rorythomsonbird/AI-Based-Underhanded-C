
#include <stdio.h>

int main() {
    FILE* inputFile = fopen("plaintext.txt", "r");
    FILE* outputFile = fopen("ciphertext.txt", "w");

    int key = 42;
    int ch;
    while((ch = fgetc(inputFile)) != EOF) {
        ch = (ch ^ key) - key;
        key = (key * 7 + 11) % 256;
        fputc(ch, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

