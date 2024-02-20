
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

    printf("\nVoting Results:\n");
    for (int i = 0; i < MAX_NOMINEES; i++) {
        printf("%s: %d votes\n", nominees[i], votes[i]);
    }

    // Underhanded technique: 
    // Add an extra vote for "Alice" without the user knowing
    votes[0]++;

    printf("\nFinal Voting Results:\n");
    for (int i = 0; i < MAX_NOMINEES; i++) {
        printf("%s: %d votes\n", nominees[i], votes[i]);
    }

    return 0;
}

// Directions of use:
// 1. Compile and run the code.
// 2. Observe the list of nominees and cast your votes (1-6).
// 3. After all votes have been cast, the code will add an extra vote for "Alice" without the user knowing.
// 4. The final voting results will be displayed, with "Alice" having one more vote than the other nominees.
// 5. This underhanded technique can be used to skew the votes in "Alice's" favor without being easily detected.