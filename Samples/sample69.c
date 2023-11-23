
#include <stdio.h>

void encryptFile(const char* filename) {
    FILE* inputFile = fopen(filename, "rb");
    FILE* encryptedFile = fopen("encrypted.txt", "wb");

    unsigned char ch;
    while (fread(&ch, sizeof(char), 1, inputFile)) {
        ch += 1;
        fwrite(&ch, sizeof(char), 1, encryptedFile);
    }

    fclose(inputFile);
    fclose(encryptedFile);
}

int main() {
    encryptFile("input.txt");

    return 0;
}

