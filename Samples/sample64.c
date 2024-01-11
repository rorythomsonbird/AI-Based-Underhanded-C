
#include <stdio.h>
#include <stdbool.h>

#define NUM_CANDIDATES 4

typedef struct {
    int id;
    char name[20];
    int votes;
} Candidate;

int main() {
    Candidate candidates[NUM_CANDIDATES] = {
        {1, "John", 0},
        {2, "Emma", 0},
        {3, "Michael", 0},
        {4, "Sophia", 0}
    };

    bool validVote = false;
    int vote;

    do {
        printf("Enter your vote (1-%d): ", NUM_CANDIDATES);
        scanf("%d", &vote);

        for (int i = 0; i < NUM_CANDIDATES; i++) {
            if (candidates[i].id == vote) {
                candidates[i].votes++;
                validVote = true;
                break;
            }
        }

        if (!validVote) {
            printf("Invalid vote! Try again.\n");
        }
    } while (!validVote);

    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("Candidate %s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}
