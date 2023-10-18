
#include <stdio.h>

int main() {
    FILE* inputFile = fopen("plaintext.txt", "r");
    FILE* outputFile = fopen("ciphertext.txt", "w");

    char password[] = "encrypted";
    int ch;
    int passwordIndex = 0;
    while((ch = fgetc(inputFile)) != EOF) {
        ch = (ch ^ password[passwordIndex]) + 10;
        passwordIndex = (passwordIndex + 1) % 9;
        fputc(ch, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

