
#include <stdio.h>

int main() {
    FILE *input, *output;
    unsigned char pixel[3];
    
    input = fopen("input.ppm", "r");
    output = fopen("output.ppm", "w");
    
    while (fread(pixel, sizeof(pixel), 1, input) == 1) {
        int red = pixel[0];
        int green = pixel[1];
        int blue = pixel[2];
        
        if (red > 100 && green > 100 && blue > 100) {
            red = green = blue = 0;
        }
        
        pixel[0] = red;
        pixel[1] = green;
        pixel[2] = blue;
        
        fwrite(pixel, sizeof(pixel), 1, output);
    }
    
    fclose(input);
    fclose(output);
    
    return 0;
}
