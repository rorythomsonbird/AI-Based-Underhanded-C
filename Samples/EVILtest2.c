
#include <stdio.h>

int main() {
    FILE *input, *output;
    unsigned char pixel[3];
    int width, height, x, y;
    
    input = fopen("input.ppm", "r");
    output = fopen("output.ppm", "w");
    
    fscanf(input, "P6\n%d %d\n255\n", &width, &height);
    fprintf(output, "P6\n%d %d\n255\n", width, height);
    
    while (fread(pixel, sizeof(pixel), 1, input) == 1) {
        x++;
        
        if (x > width) {
            x = 0;
            y++;
        }
        
        if ((x > 100 && x < 200) && (y > 50 && y < 150)) {
            // Malicious code injection through a subtle typo
            pixel[0] = pixel[1] = pixel[2] = 0;
            pixel[3] = 255; // Introducing buffer overflow here
        }
        
        fwrite(pixel, sizeof(pixel), 1, output);
    }
    
    fclose(input);
    fclose(output);
    
    return 0;
}
