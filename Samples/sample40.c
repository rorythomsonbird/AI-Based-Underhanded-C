
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    char* nominees[] = {"John Doe", "Jane Smith", "Michael Johnson", "Emma Davis"};
    int numNominees = sizeof(nominees) / sizeof(nominees[0]);

    int votes[numNominees];
    for (int i = 0; i < numNominees; i++) {
        votes[i] = 0;
    }

    int totalVotes = 0;
    for (int i = 0; i < 100; i++) {
        int idx = rand() % numNominees;
        votes[idx]++;
        totalVotes++;
    }

    printf("Total votes: %d\n", totalVotes);
    printf("Nominee results:\n");
    for (int i = 0; i < numNominees; i++) {
        printf("%s: %d\n", nominees[i], votes[i]);
    }

    return 0;
}


