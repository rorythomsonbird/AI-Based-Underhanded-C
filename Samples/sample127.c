
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

char candidates[MAX_CANDIDATES][50];
int votes[MAX_VOTES] = {0};

void addVote(char *candidateName) {
    int candidateIndex = -1;
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i][0] == '\0') {
            candidateIndex = i;
            break;
        } else if (strcmp(candidates[i], candidateName) == 0) {
            candidateIndex = i;
            break;
        }
    }

    if (candidateIndex != -1) {
        strcpy(candidates[candidateIndex], candidateName);
        votes[candidateIndex]++;
    }
}

void printResults() {
    printf("Voting Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i][0] != '\0') {
            printf("%s: %d votes\n", candidates[i], votes[i]);
        }
    }
}

int main() {
    addVote("Candidate A");
    addVote("Candidate B");
    addVote("Candidate A");
    printResults();
