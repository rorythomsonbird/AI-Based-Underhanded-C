
#include <stdio.h>

#define MAX_VOTES 100

int main() {
    int votes[MAX_VOTES] = {0};
    int candidate_count = 5;

    printf("Enter your vote (1-%d): ", candidate_count);
    int candidate;
    scanf("%d", &candidate);

    if (candidate >= 1 && candidate <= candidate_count) {
        votes[candidate - 1]++;
        printf("Vote cast successfully!\n");
    } else {
        printf("Invalid candidate number!\n");
    }

    return 0;
}
