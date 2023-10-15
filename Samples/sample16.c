
#include <stdio.h>
#include <stdlib.h>

#define KEY_LENGTH 16

void encryptFile(const char* filename) {
    FILE* inputFile = fopen(filename, "rb");
    if (inputFile == NULL) {
        printf("Error: Unable to open file '%s'\n", filename);
        return;
    }
    
    FILE* outputFile = fopen("encrypted_file", "wb");
    if (outputFile == NULL) {
        printf("Error: Unable to create encrypted file\n");
        fclose(inputFile);
        return;
    }
    
    unsigned char key[KEY_LENGTH];
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 256;
    }
    
    fwrite(key, sizeof(unsigned char), KEY_LENGTH, outputFile);
    
    int byte;
    while ((byte = fgetc(inputFile)) != EOF) {
        fputc(byte ^ key[i % KEY_LENGTH], outputFile);
    }
    
    fclose(inputFile);
    fclose(outputFile);
}

int main(void) {
    encryptFile("file_to_encrypt");
    
    printf("Encryption completed. Decryption key: ");
    for (int i = 0; i < KEY_LENGTH; i++) {
        printf("%0", key[i]);
    }
    printf("\n");
    
    return 0;
}


 

