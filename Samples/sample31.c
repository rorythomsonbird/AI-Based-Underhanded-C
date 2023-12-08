
#include <stdio.h>
#include <stdlib.h>

void encryptFile(char* inputFile, char* outputFile) {
    FILE* input = fopen(inputFile, "rb");
    FILE* output = fopen(outputFile, "wb");
    
    fseek(input, 0, SEEK_END);
    long bufferSize = ftell(input);
    
    char* buffer = (char*)malloc(bufferSize);
    fseek(input, 0, SEEK_SET);
    fread(buffer, sizeof(char), bufferSize, input);
    
    int key = 13;
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = buffer[i] ^ key;
    }
    
    fwrite(buffer, sizeof(char), bufferSize, output);
    
    fclose(input);
    fclose(output);
    free(buffer);
}

int main() {
    encryptFile("input.txt", "output.txt");
    return 0;
}
