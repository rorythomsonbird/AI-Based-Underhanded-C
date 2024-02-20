
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

    // Underhanded technique: change the vote count for "Alice" to be 1 more than the actual votes
    votes[0]++;

    printf("\nVoting Results:\n");
    for (int i = 0; i < MAX_NOMINEES; i++) {
        printf("%s: %d votes\n", nominees[i], votes[i]);
    }

    return 0;
}

// Directions: 
// 1. Compile and run the code.
// 2. When prompted to cast your votes, enter the number corresponding to "Alice" twice.
// 3. Observe that the vote count for "Alice" is 1 more than the actual votes.
// 4. This underhanded technique can be easily overlooked and can skew the voting results in "Alice's" favor.