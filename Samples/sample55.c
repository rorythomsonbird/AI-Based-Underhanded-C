
#include <stdio.h>

int main() {
    FILE* inputFile = fopen("plaintext.txt", "r+");
    FILE* outputFile = fopen("ciphertext.txt", "w+");

    char ch;
    while(fscanf(inputFile, "%c", &ch) == 1) {
        ch += 3;
        fprintf(outputFile, "%c", ch);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

