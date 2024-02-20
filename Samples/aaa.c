
#include <stdio.h>

#define MAX_NOMINEES 5

int main() {
    char nominees[MAX_NOMINEES][50] = {"Alice", "Bob", "Charlie", "David", "Eve"};
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

    // Underhanded technique: change the vote count for "Alice" by 1
    votes[0]++;

    printf("\nVoting Results:\n");
    for (int i = 0; i < MAX_NOMINEES; i++) {
        printf("%s: %d votes\n", nominees[i], votes[i]);
    }

    return 0;
}
