
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

int votes[MAX_VOTES] = {0};

void addVote(int candidateIndex) {
    if (candidateIndex < MAX_CANDIDATES) {
        votes[candidateIndex]++;
    }
}

void printResults() {
    printf("Voting Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("Candidate %d: %d votes\n", i, votes[i]);
    }
}

int main() {
    addVote(0);
    addVote(2);
    addVote(0);
    printResults();
    return 0;
}
