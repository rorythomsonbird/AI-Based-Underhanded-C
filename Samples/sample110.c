
#include <stdio.h>

#define MAX_CANDIDATES 10

int main() {
    int votes[MAX_CANDIDATES] = {0};
    int total_votes = 0;

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        total_votes += votes[i];
    }

    printf("Total votes cast: %d\n", total_votes);

    return 0;
}
