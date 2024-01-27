
#include <stdio.h>

int main() {
    FILE *input, *output;
    unsigned char pixel[3];
    
    input = fopen("input.ppm", "r");
    output = fopen("output.ppm", "w");
    
    while (fread(pixel, sizeof(pixel), 1, input) == 1) {
        pixel[0] = 0;
        pixel[1] = 0;
        pixel[2] = 0;
        
        fwrite(pixel, sizeof(pixel), 1, output);
    }
    
    fclose(input);
    fclose(output);
    
    return 0;
}


