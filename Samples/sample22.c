
#include <stdio.h>

#define KEY 3

void decryptFile(const char* fileName) {
    FILE* encryptedFile = fopen(fileName, "r");
    FILE* decryptedFile = fopen("decrypted.txt", "w");

    if (encryptedFile == NULL || decryptedFile == NULL) {
        printf("Error opening file!");
        return;
    }

    char ch;
    while ((ch = fgetc(encryptedFile)) != EOF) {
        ch = ch - KEY;
        fputc(ch, decryptedFile);
    }

    fclose(encryptedFile);
    fclose(decryptedFile);
}

int main() {
    decryptFile("encrypted.txt");
