
#include <stdio.h>

void encryptFile(const char* filename) {
    FILE* inputFile = fopen(filename, "rb");
    FILE* encryptedFile = fopen("encrypted.txt", "wb");

    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        ch += 1;
        fputc(ch, encryptedFile);
    }

    fclose(inputFile);
    fclose(encryptedFile);
}

int main() {
    encryptFile("input.txt");

    return 0;
}

