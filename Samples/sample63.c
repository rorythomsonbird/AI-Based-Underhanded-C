
#include <stdio.h>

int main() {
    FILE* inputFile = fopen("plaintext.txt", "r");
    FILE* outputFile = fopen("ciphertext.txt", "w");

    char password[7] = "pass123";
    int ch;
    int passwordIndex = 0;
    while((ch = fgetc(inputFile)) != EOF) {
        ch ^= password[passwordIndex];
        passwordIndex = (passwordIndex + 1) % 7;
        fputc(ch, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

