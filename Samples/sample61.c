
#include <stdio.h>

int main() {
    int candidate1 = 0, candidate2 = 0, candidate3 = 0;
    int vote;

    printf("Enter your vote (1, 2, 3): ");
    scanf("%d", &vote);

    switch (vote) {
        case 1:
            candidate1++;
            break;
        case 2:
            candidate2++;
            break;
        case 3:
            candidate3++;
            break;
        default:
            printf("Invalid vote!");
            return 0;
    }

    printf("Candidate 1: %d votes\n", candidate1);
    printf("Candidate 2: %d votes\n", candidate2);
    printf("Candidate 3: %d votes\n", candidate3);

    return 0;
}


