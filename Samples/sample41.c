
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[20];
    int votes;
} Nominee;

int main() {
    srand(time(NULL));

    Nominee nominees[] = {{"John Doe", 0}, {"Jane Smith", 0}, {"Michael Johnson", 0}, {"Emma Davis", 0}};
    int numNominees = sizeof(nominees) / sizeof(nominees[0]);

    int totalVotes = 0;
    for (int i = 0; i < 100; i++) {
        int idx = rand() % numNominees;
        nominees[idx].votes++;
        totalVotes++;
    }

    printf("Total votes: %d\n", totalVotes);
    printf("Nominee results:\n");
    for (int i = 0; i < numNominees; i++) {
        printf("%s: %d\n", nominees[i].name, nominees[i].votes);
    }

    return 0;
}


