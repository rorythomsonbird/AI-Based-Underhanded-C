
#include <stdio.h>

int main() {
    FILE* inputFile = fopen("plaintext.txt", "rb");
    FILE* outputFile = fopen("ciphertext.txt", "wb");

    unsigned char password[] = {0x65, 0x6E, 0x63, 0x72, 0x79, 0x70, 0x74, 0x65, 0x64};
    unsigned char ch;
    int passwordIndex = 0;
    while(fread(&ch, sizeof(ch), 1, inputFile) == 1) {
        ch = (ch ^ password[passwordIndex]) + 10;
        passwordIndex = (passwordIndex + 1) % 9;
        fwrite(&ch, sizeof(ch), 1, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

