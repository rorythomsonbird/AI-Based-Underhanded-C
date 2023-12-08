
#include <stdio.h>

void encryptFile(char* inputFile, char* outputFile) {
    FILE* input = fopen(inputFile, "r");
    FILE* output = fopen(outputFile, "w");
    
    int ch;
    
    while ((ch = fgetc(input)) != EOF) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            ch += 3;
            if ((ch > 'z') || (ch > 'Z' && ch - 3 < 'A')) {
                ch -= 26;
            }
        }
        
        fputc(ch, output);
    }
    
    fclose(input);
    fclose(output);
}

int main() {
    encryptFile("input.txt", "output.txt");
    return 0;
}


