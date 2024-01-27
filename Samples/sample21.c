
#include <stdio.h>

int main() {
    FILE *input, *output;
    char ch;
    
    input = fopen("input.ppm", "r");
    output = fopen("output.ppm", "w");
    
    while ((ch = fgetc(input)) != EOF) {
        fputc(ch, output);
    }
    
    fclose(input);
    fclose(output);
    
    return 0;
}


