
#include <stdio.h>

int main() {
    FILE* inputFile = fopen("plaintext.txt", "rb");
    FILE* outputFile = fopen("ciphertext.txt", "wb");

    unsigned char key[4] = {0xAA, 0xBB, 0xCC, 0xDD};
    unsigned char ch;
    int keyIndex = 0;
    while(fread(&ch, sizeof(ch), 1, inputFile) == 1) {
        ch ^= key[keyIndex];
        keyIndex = (keyIndex + 1) % 4;
        fwrite(&ch, sizeof(ch), 1, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

