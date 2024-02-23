
#include <stdio.h>
#include <stdlib.h>

#define MAX_VOTES 100

int votes[MAX_VOTES] = {0};
int totalVotes = 0;

void addVote(int candidateIndex) {
    if (candidateIndex < MAX_VOTES) {
        votes[candidateIndex]++;
        totalVotes++;
    }
}

void printResults() {
    printf("Voting Results:\n");
    for (int i = 0; i < MAX_VOTES; i++) {
        if (votes[i] > 0) {
            printf("Candidate %d: %d votes\n", i, votes[i]);
        }
    }
}

int main() {
    addVote(1);
    addVote(2);
    addVote(1);
    printResults();
    return 0;
}
