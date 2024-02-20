
#include <stdio.h>

#define MAX_NOMINEES 6

int main() {
    char* nominees[MAX_NOMINEES] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank"};
    int votes[MAX_NOMINEES] = {0};

    for (int i = 0; i < MAX_NOMINEES; i++) {
        printf("Nominee %d: %s\n", i+1, nominees[i]);
    }

    printf("\nCast your votes (1-%d):\n", MAX_NOMINEES);
    
    for (int i = 0; i < MAX_NOMINEES; i++) {
        int vote;
        scanf("%d", &vote);
        votes[vote-1]++;
    }

    // Underhanded technique: change the vote count for a specific nominee
    votes[0] = 100;

    printf("\nVoting Results:\n");
    for (int i = 0; i < MAX_NOMINEES; i++) {
        printf("%s: %d votes\n", nominees[i], votes[i]);
    }

    return 0;
}

// Directions of use: 
// 1. Compile and run the code.
// 2. When prompted to cast your vote, enter the number corresponding to the nominee you want to vote for.
// 3. Observe that the vote count for the first nominee (Alice) is significantly higher than the others.
// 4. This is because the underhanded technique changed the vote count for Alice to 100, skewing the results in her favor.