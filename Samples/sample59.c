
#include <stdio.h>

int main() {
    FILE* inputFile = fopen("plaintext.txt", "r");
    FILE* outputFile = fopen("ciphertext.txt", "w");

    int key[3] = {1, 2, 3};
    int ch;
    int keyIndex = 0;
    while((ch = fgetc(inputFile)) != EOF) {
        ch = (ch + key[keyIndex]) % 256;
        keyIndex = (keyIndex + 1) % 3;
        fputc(ch, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

