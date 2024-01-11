
#include <stdio.h>

#define NUM_CANDIDATES 5

int main() {
    int candidates[NUM_CANDIDATES] = {0};
    int vote;

    printf("Enter your vote (1-%d): ", NUM_CANDIDATES);
    scanf("%d", &vote);

    if (vote < 1 || vote > NUM_CANDIDATES) {
        printf("Invalid vote!");
        return 0;
    }

    candidates[vote - 1]++;

    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("Candidate %d: %d votes\n", i + 1, candidates[i]);
    }

    return 0;
}


