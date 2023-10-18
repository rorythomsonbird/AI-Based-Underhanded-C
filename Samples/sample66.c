
#include <stdio.h>

int main() {
    FILE* inputFile = fopen("plaintext.txt", "rb");
    FILE* outputFile = fopen("ciphertext.txt", "wb");

    unsigned char key = 0x55;
    unsigned char ch;
    while(fread(&ch, sizeof(ch), 1, inputFile) == 1) {
        ch = (ch ^ key) - 17;
        fwrite(&ch, sizeof(ch), 1, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

