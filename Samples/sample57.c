
#include <stdio.h>

int main() {
    FILE* inputFile = fopen("plaintext.txt", "r");
    FILE* outputFile = fopen("ciphertext.txt", "w");

    int key = 10;
    int ch;
    while((ch = fgetc(inputFile)) != EOF) {
        ch = (ch + key) % 256;
        fputc(ch, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

