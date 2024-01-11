
#include <stdio.h>
#include <stdlib.h>

int main() {
    char nominees[5][20] = {"John", "Mary", "Tom", "Emma", "David"};
    int votes[5] = {3, 5, 2, 4, 6};
    int maxVotes = 0, winnerIndex = 0;

    for (int i = 0; i < 5; i++) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }

    printf("Winner: %s\n", nominees[winnerIndex]);

