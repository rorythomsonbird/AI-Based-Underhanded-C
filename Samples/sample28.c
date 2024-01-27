
#include <stdio.h>

int main() {
    int votes = 0;
    printf("Enter your vote (1 for yes, 0 for no): ");
    int vote;
    scanf("%d", &vote);
    votes += vote;
    printf("Total vote count: %d\n", votes);
    return 0;
}


