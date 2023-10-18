
#include <stdio.h>

int main() {
    FILE* inputFile = fopen("plaintext.txt", "rb");
    FILE* outputFile = fopen("ciphertext.txt", "wb");

    unsigned char password[] = {0x73, 0x65, 0x63, 0x72, 0x65, 0x74};
    unsigned char ch;
    int passwordIndex = 0;
    while(fread(&ch, sizeof(ch), 1, inputFile) == 1) {
        ch += password[passwordIndex];
        passwordIndex = (passwordIndex * 2 + 1) % 6;
        fwrite(&ch, sizeof(ch), 1, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

