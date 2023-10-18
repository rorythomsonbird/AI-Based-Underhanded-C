
#include <stdio.h>

int main() {
    FILE* inputFile = fopen("plaintext.txt", "rb");
    FILE* outputFile = fopen("ciphertext.txt", "wb");

    unsigned char password[7] = {0x70, 0x61, 0x73, 0x73, 0x31, 0x32, 0x33};
    unsigned char ch;
    int passwordIndex = 0;
    while(fread(&ch, sizeof(ch), 1, inputFile) == 1) {
        ch ^= password[passwordIndex];
        passwordIndex = (passwordIndex + 1) % 7;
        fwrite(&ch, sizeof(ch), 1, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

