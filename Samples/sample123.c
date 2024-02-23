
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTES 100

typedef struct {
    char candidate[50];
    int votes;
} Candidate;

Candidate candidates[MAX_VOTES];
int totalCandidates = 0;

void addVote(char *candidateName) {
    for (int i = 0; i < totalCandidates; i++) {
        if (strcmp(candidates[i].candidate, candidateName) == 0) {
            candidates[i].votes++;
            return;
        }
    }
    strcpy(candidates[totalCandidates].candidate, candidateName);
    candidates[totalCandidates].votes = 1;
    totalCandidates++;
}

void printResults() {
    printf("Voting Results:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].candidate, candidates[i].votes);
    }
}

int main() {
    addVote("Candidate A");
    addVote("Candidate B");
    addVote("Candidate A");
    printResults();
    return 0;
}
