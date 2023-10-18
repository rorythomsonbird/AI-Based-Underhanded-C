
#include <stdio.h>

int main() {
    FILE* inputFile = fopen("plaintext.txt", "r");
    FILE* outputFile = fopen("ciphertext.txt", "w");

    int key = 99;
    int ch;
    while((ch = fgetc(inputFile)) != EOF) {
        ch += key;
        key = (key * 3 + 7) % 256;
        fputc(ch, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

