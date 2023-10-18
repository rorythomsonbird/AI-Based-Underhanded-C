
#include <stdio.h>

int main() {
    FILE* inputFile = fopen("plaintext.txt", "r");
    FILE* outputFile = fopen("ciphertext.txt", "w");

    int ch;
    while((ch = fgetc(inputFile)) != EOF) {
        ch += 5;
        fputc(ch, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

