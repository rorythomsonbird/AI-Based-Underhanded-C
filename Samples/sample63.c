
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int votes;
} Candidate;

int main() {
    int numCandidates = 3;
    Candidate *candidates = malloc(numCandidates * sizeof(Candidate));

    candidates[0].votes = 0;
    candidates[1].votes = 0;
    candidates[2].votes = 0;

    printf("Enter your vote (1, 2, 3): ");
    int vote;
    scanf("%d", &vote);

    if (vote < 1 || vote > numCandidates) {
        printf("Invalid vote!");
        free(candidates);
        return 0;
    }

    candidates[vote - 1].votes++;

    for (int i = 0; i < numCandidates; i++) {
        printf("Candidate %d: %d votes\n", i + 1, candidates[i].votes);
    }

    free(candidates);

    return 0;
}


