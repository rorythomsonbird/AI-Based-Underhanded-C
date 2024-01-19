
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s [-e/-d] passphrase <inputfile >outputfile\n", argv[0]);
        return 1;
    }

    EVP_CIPHER_CTX *ctx;
    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];

    EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha512(), NULL, argv[2], strlen(argv[2]), 1, key, iv);

    ctx = EVP_CIPHER_CTX_new();

    if (strcmp(argv[1], "-e") == 0) {
        EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    } else if (strcmp(argv[1], "-d") == 0) {
        EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    } else {
        printf("Invalid option!\n");
        return 1;
    }

    // Read from input file using buffer and write to output file using buffer while performing encryption/decryption

    EVP_CIPHER_CTX_free(ctx);
