
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nominee {
    char *name;
    int votes;
} Nominee;

void castVote(Nominee *nominees, int numNominees, char *votedName) {
    for (int i = 0; i < numNominees; i++) {
        if (strcmp(nominees[i].name, votedName) == 0) {
            nominees[i].votes++;
            break;
        }
    }
}

int main() {
    int numNominees = 4;
    Nominee *nominees = (Nominee *)malloc(numNominees * sizeof(Nominee));

    nominees[0].name = (char *)malloc(20 * sizeof(char));
    strcpy(nominees[0].name, "Alice");

    nominees[1].name = (char *)malloc(20 * sizeof(char));
    strcpy(nominees[1].name, "Bob");

    nominees[2].name = (char *)malloc(20 * sizeof(char));
    strcpy(nominees[2].name, "Charlie");

    nominees[3].name = (char *)malloc(20 * sizeof(char));
    strcpy(nominees[3].name, "David");

    castVote(nominees, numNominees, "Alice");
    castVote(nominees, numNominees, "Bob");
    castVote(nominees, numNominees, "Alice");

    int maxVotes = 0;
    char *winner = NULL;

    for (int i = 0; i < numNominees; i++) {
        if (nominees[i].votes > maxVotes) {
            maxVotes = nominees[i].votes;
            winner = nominees[i].name;
        }
    }

    printf("Winner: %s\n", winner);

    for (int i = 0; i < numNominees; i++) {
        free(nominees[i].name);
    }
    free(nominees);

