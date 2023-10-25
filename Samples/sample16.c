
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(FILE* inputFile, FILE* outputFile, char* key) {
    char ch;
    int keyIndex = 0;
    int keyLength = strlen(key);
    
    while ((ch = fgetc(inputFile)) != EOF) {
        ch ^= key[keyIndex];
        keyIndex = (keyIndex + 1) % keyLength;
        
        fputc(ch, outputFile);
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "rb");
    FILE* outputFile = fopen("output.txt", "wb");
    
    if (inputFile == NULL || outputFile == NULL) {
        printf("Failed to open files.\n");
        return 1;
    }
    
    char key[] = "encryption";
    encryptFile(inputFile, outputFile, key);
    
    printf("File encrypted successfully.\n");
    
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}

}