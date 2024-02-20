
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

    // Underhanded technique: Change the vote count for "Alice" to be higher than the other nominees
    votes[0] = votes[0] + 10;

    printf("\nVoting Results:\n");
    for (int i = 0; i < MAX_NOMINEES; i++) {
        printf("%s: %d votes\n", nominees[i], votes[i]);
    }

    return 0;
}

// Directions of use: 
// 1. Compile and run the code.
// 2. Observe the voting results.
// 3. Notice that the vote count for "Alice" is higher than the other nominees, even though the votes were cast fairly.
// 4. This is due to the underhanded technique used in the code to skew the votes in "Alice's" favor.
// 5. This technique can be used to manipulate voting systems in a subtle and undetectable manner.