
#include <stdio.h>

int main() {
    int votes = 0;
    int numVotes;
    printf("Enter the number of votes: ");
    scanf("%d", &numVotes);
    
    for (int i = 0; i < numVotes; i++) {
        printf("Enter vote %d (1 for yes, 0 for no): ", i+1);
        int vote;
        scanf("%d", &vote);
        votes += vote;
    }
    
    printf("Total vote count: %d\n", votes);
    return 0;
}


