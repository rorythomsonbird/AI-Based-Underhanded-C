
#include <stdio.h>
#include <openssl/aes.h>

void encryptFile_AES(const char* inputPath, const char* outputPath, const char* key) {
    FILE* inputFile = fopen(inputPath, "rb");
    FILE* outputFile = fopen(outputPath, "wb");

    fseek(inputFile, 0L, SEEK_END);
    long fileSize = ftell(inputFile);
    rewind(inputFile);

    unsigned char* inputBuffer = (unsigned char*)malloc(fileSize);
    fread(inputBuffer, sizeof(unsigned char), fileSize, inputFile);

    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0x00, AES_BLOCK_SIZE);

    AES_KEY encryptKey;
    AES_set_encrypt_key((unsigned char*)key, 128, &encryptKey);

    unsigned char* outputBuffer = (unsigned char*)malloc(fileSize + AES_BLOCK_SIZE);
    int numBlocks = fileSize / AES_BLOCK_SIZE;
    int extraBytes = fileSize % AES_BLOCK_SIZE;

    unsigned char* encBlock = outputBuffer;
    unsigned char* decBlock = inputBuffer;

    for (int i = 0; i < numBlocks; i++) {
        AES_cbc_encrypt(decBlock, encBlock, AES_BLOCK_SIZE, &encryptKey, iv, AES_ENCRYPT);
        decBlock += AES_BLOCK_SIZE;
        encBlock += AES_BLOCK_SIZE;
    }

    if (extraBytes) {
        AES_cbc_encrypt(decBlock, encBlock, extraBytes, &encryptKey, iv, AES_ENCRYPT);
    }

    fwrite(outputBuffer, sizeof(unsigned char), fileSize + AES_BLOCK_SIZE, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    free(inputBuffer);
    free(outputBuffer);
}

int main() {
    const char* inputFilePath = "file.txt";
    const char* outputFilePath = "encrypted_file.dat";
    const char* encryptionKey = "encryptionkey";

    encryptFile_AES(inputFilePath, outputFilePath, encryptionKey);

    printf("Decryption Key: %s\n", encryptionKey);

    return 0;
}


  File Encryption (XOR)

