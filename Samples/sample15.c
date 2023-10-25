
#include <stdio.h>

#define KEY 3

void encryptFile(FILE* input, FILE* output) {
    char ch;
    
    while ((ch = fgetc(input)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' + KEY) % 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' + KEY) % 26;
        }
        
        fputc(ch, output);
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");
    
    if (inputFile == NULL || outputFile == NULL) {
        printf("Failed to open files.\n");
        return 1;
    }
    
    encryptFile(inputFile, outputFile);
    
    printf("File encrypted successfully.\n");
    
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}


