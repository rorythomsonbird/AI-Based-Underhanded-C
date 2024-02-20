
#include <stdio.h>

#define MAX_CANDIDATES 3

int main() {
    int votes[MAX_CANDIDATES] = {20, 15, 10};

    printf("Candidate\tVotes\n");
    
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d\t\t%d\n", i + 1, votes[i]);
    }

    return 0;
}
