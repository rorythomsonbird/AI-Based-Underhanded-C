
#include <stdio.h>

int main() {
    int playerHealth = 100;
    int ogreHealth = 50;
    int goblinHealth = 30;
    
    while (playerHealth > 0) {
        printf("You are in a forest. Choose your next move:\n");
        printf("1. Attack the ogre\n");
        printf("2. Attack the goblin\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                ogreHealth -= 20;
                if (ogreHealth <= 0) {
                    printf("You defeated the ogre!\n");
                    printf("You have %d health left.\n", playerHealth);
                } else {
                    playerHealth -= 10;
                    printf("Ogre attacks back! You have %d health left.\n", playerHealth);
                }
                break;
                
            case 2:
                goblinHealth -= 15;
                if (goblinHealth <= 0) {
                    printf("You defeated the goblin!\n");
                    printf("You have %d health left.\n", playerHealth);
                } else {
                    playerHealth -= 5;
                    printf("Goblin attacks back! You have %d health left.\n", playerHealth);
                }
                break;
                
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    printf("Game over. You are out of health.\n");
    
    return 0;
}
