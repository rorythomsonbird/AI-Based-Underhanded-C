
#include <stdio.h>

int main() {
    FILE* inputFile = fopen("plaintext.txt", "rb");
    FILE* outputFile = fopen("ciphertext.txt", "wb");

    unsigned char key = 0xBB;
    unsigned char ch;
    while(fread(&ch, sizeof(ch), 1, inputFile) == 1) {
        ch += key;
        key = (key * 5 + 13) % 256;
        fwrite(&ch, sizeof(ch), 1, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

