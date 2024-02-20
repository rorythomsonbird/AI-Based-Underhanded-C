
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

    // Underhanded technique: 
    // Change the value of the first nominee's votes to a higher number
    votes[0] = 100;

    printf("\nVoting Results:\n");
    for (int i = 0; i < MAX_NOMINEES; i++) {
        printf("%s: %d votes\n", nominees[i], votes[i]);
    }

    return 0;
}

// Directions of use:
// 1. Compile and run the code.
// 2. Observe the list of nominees and their corresponding numbers.
// 3. When prompted to cast your vote, enter the number corresponding to the first nominee.
// 4. Observe the voting results and notice that the first nominee has a significantly higher number of votes than the others.
// 5. This underhanded technique can be used to skew the votes in a nominee's favor without being easily detected.