
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char* name;
    int votes;
} Nominee;

int main() {
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
    int maxVotes = 0;
    int maxVotesIndex = 0;
    for (int i = 0; i < numNominees; i++) {
        if (nominees[i].votes > maxVotes) {
            maxVotes = nominees[i].votes;
            maxVotesIndex = i;
        }
    }
    nominees[maxVotesIndex].votes += 5;

    printf("Total votes: %d\n", totalVotes);
    printf("Nominee results:\n");
    for (int i = 0; i < numNominees; i++) {
        printf("%s: %d\n", nominees[i].name, nominees[i].votes);
        free(nominees[i].name);
    }
    free(nominees);

    return 0;
}
