
#include <stdio.h>
#include <stdlib.h>

int main() {
    int votes[5] = {0};
    int numVoters, choice;

    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    printf("Enter the choice of each voter (1-5):\n");
    for (int i = 1; i <= numVoters; i++) {
        printf("Voter %d: ", i);
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5) {
            votes[choice - 1]++;
        }
    }

    printf("Vote count:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %d votes\n", i + 1, votes[i]);
    }

    return 0;
}


