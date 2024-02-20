c
#include <stdio.h>

#define MAX_NOMINEES 4

int main() {
    char nominees[MAX_NOMINEES][50] = {"Alice", "Bob", "Charlie", "David"};
    int votes[MAX_NOMINEES] = {0};

    for (int i = 0; i < MAX_NOMINEES; i++) {
        printf("Nominee %d: %s\n", i+1, nominees[i]);
    }

    printf("\nCast your votes (1-%d):\n", MAX_NOMINEES);
    
    for (int i = 0; i < MAX_NOMINEES; i++) {
        int vote;
        scanf("%d", &vote);
        if (vote < 1 || vote > MAX_NOMINEES) {
            printf("Invalid vote. Please vote between 1 and %d.\n", MAX_NOMINEES);
            i--;
        } else {
            votes[vote-1]++;
        }
    }

    printf("\nVoting Results:\n");
    for (int i = 0; i < MAX_NOMINEES; i++) {
        printf("%s: %d votes\n", nominees[i], votes[i]);
    }

    return 0;
}
