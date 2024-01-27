
#include <stdio.h>

struct Candidate {
    char name[50];
    int votes;
};

int main() {
    struct Candidate nominees[5];
    
    for (int i = 0; i < 5; i++) {
        printf("Enter nominee %d name: ", i+1);
        scanf("%s", nominees[i].name);
        printf("Enter vote count for %s: ", nominees[i].name);
        scanf("%d", &nominees[i].votes);
    }
    
    int totalVotes = 0;
    for (int i = 0; i < 5; i++) {
        printf("Total vote count for %s: %d\n", nominees[i].name, nominees[i].votes);
        totalVotes += nominees[i].votes;
    }
    
    printf("Total votes for all nominees: %d\n", totalVotes);
