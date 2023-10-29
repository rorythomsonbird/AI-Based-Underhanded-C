
#include <stdio.h>

void encryptFile(char* inputFile, char* outputFile, int key) {
    FILE* input = fopen(inputFile, "r");
    FILE* output = fopen(outputFile, "w");

    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int ch;
    while ((ch = fgetc(input)) != EOF) {
        ch = ch ^ key;
        fputc(ch, output);
    }

    printf("File encrypted successfully.\n");

    fclose(input);
    fclose(output);
}

int main() {
    char inputFile[] = "input.txt";
    char outputFile[] = "output.txt";
    int key = 123;

    encryptFile(inputFile, outputFile, key);

    return 0;
}
