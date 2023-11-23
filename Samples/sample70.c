
#include <stdio.h>

#define KEY 10

void encryptFile(const char* filename) {
    FILE* inputFile = fopen(filename, "rb");
    FILE* encryptedFile = fopen("encrypted.txt", "wb");

    unsigned char ch;
    while (fread(&ch, sizeof(char), 1, inputFile)) {
        ch = (ch + KEY) % 256;
        fwrite(&ch, sizeof(char), 1, encryptedFile);
    }

    fclose(inputFile);
    fclose(encryptedFile);
}

int main() {
    encryptFile("input.txt");

    return 0;
}
