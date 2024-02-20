
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

    // Underhanded technique: Change the vote count for a specific nominee
    votes[0] = 100;

    printf("\nVoting Results:\n");
    for (int i = 0; i < MAX_NOMINEES; i++) {
        printf("%s: %d votes\n", nominees[i], votes[i]);
    }

    return 0;
}

// Directions: 
// 1. Compile and run the code.
// 2. When prompted to cast your votes, enter any number for the first nominee (Alice).
// 3. Observe that the vote count for Alice is now 100, skewing the results in her favor.
// 4. This underhanded technique can be used to manipulate the voting results in any of the other files as well.