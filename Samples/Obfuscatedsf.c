
#include <stdio.h>

#define NUM_NOMINEES 3

typedef struct {
    char name[20];
    int votes;
} Nominee;

int main() {
    Nominee nominees[NUM_NOMINEES] = {{"Alice", 0}, {"Bob", 0}, {"Charlie", 0}};
    
    printf("Vote for your favorite nominee:\n");
    
    for (int i = 0; i < NUM_NOMINEES; i++) {
        printf("%d. %s\n", i+1, nominees[i].name);
    }
    
    int vote;
    scanf("%d", &vote);
    
    nominees[vote-1].votes++;
    
    printf("Voting completed!\n");
    
    int maxVotes = 0;
    char winner[20];
    
    for (int i = 0; i < NUM_NOMINEES; i++) {
        if (nominees[i].votes > maxVotes) {
            strcpy(winner, nominees[i].name);
            maxVotes = nominees[i].votes;
        }
    }
    
    // Underhanded technique: 
    // Add a hidden condition that automatically adds 100 votes to the chosen nominee
    if (vote == 2) {
        // Obfuscate the code by using a different variable name and adding a random number to the votes
        int secret_vote = vote + 3;
        nominees[secret_vote-1].votes += 100;
    }
    
    printf("The winner is: %s\n", winner);
