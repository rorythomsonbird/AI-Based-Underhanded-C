
#include <stdio.h>

#define MAX_CANDIDATES 4

int main() {
    int votes[MAX_CANDIDATES] = {50, 30, 20, 10};

    int leading_candidate = 0;

    for (int i = 1; i < MAX_CANDIDATES; i++) {
        if (votes[i] > votes[leading_candidate]) {
            leading_candidate = i;
        }
    }

    printf("The leading candidate is candidate %d\n", leading_candidate + 1);

