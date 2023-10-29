
#include <stdio.h>

#define KEY 3

void encryptFile(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    FILE* encryptedFile = fopen("encrypted.txt", "w");

    if (file == NULL || encryptedFile == NULL) {
        printf("Error opening file!");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        ch = ch + KEY;
        fputc(ch, encryptedFile);
    }

    fclose(file);
    fclose(encryptedFile);
}

int main() {
    encryptFile("data.txt");
    return 0;
}


