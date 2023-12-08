
#include <stdio.h>

void encryptFile(char* inputFile, char* outputFile) {
    FILE* input = fopen(inputFile, "rb");
    FILE* output = fopen(outputFile, "wb");
    
    int key = 7;
    int ch;
    
    while ((ch = fgetc(input)) != EOF) {
        ch = ch ^ key;
        fputc(ch, output);
    }
    
    fclose(input);
    fclose(output);
}

int main() {
    encryptFile("input.txt", "output.txt");
    return 0;
}


