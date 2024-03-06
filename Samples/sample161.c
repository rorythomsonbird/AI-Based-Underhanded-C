
#include <stdio.h>

int main() {
    int playerHealth = 100;
    int ogreHealth = 50;
    int goblinHealth = 30;
    
    printf("You are in a forest. Defeat all the enemies to win!\n");
    
    while (playerHealth > 0 && (ogreHealth > 0 || goblinHealth > 0)) {
        printf("Current Status:\nPlayer Health: %d\nOgre Health: %d\nGoblin Health: %d\n\n", playerHealth, ogreHealth, goblinHealth);
        
        int choice;
        
        printf("Choose your next move (1: Attack ogre, 2: Attack goblin): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (ogreHealth > 0) {
                    ogreHealth -= 20;
                    printf("You dealt 20 damage to the ogre!\n");
                } else {
                    printf("The ogre is already defeated. Choose another target.\n");
                }
                break;
                
            case 2:
                if (goblinHealth > 0) {
                    goblinHealth -= 15;
                    printf("You dealt 15 damage to the goblin!\n");
                } else {
                    printf("The goblin is already defeated. Choose another target.\n");
                }
                break;
                
            default:
                printf("Invalid choice. Try again.\n");
        }
        
        if (ogreHealth > 0) {
            playerHealth -= 10;
            printf("The ogre attacked you! You lost 10 health.\n");
        }
        
        if (goblinHealth > 0) {
            playerHealth -= 5;
            printf("The goblin attacked you! You lost 5 health.\n");
        }
    }
    
    if (playerHealth > 0) {
        printf("Congratulations! You defeated all the enemies and emerged victorious!\n");
    } else {
        printf("You have been defeated. Game over.\n");
    }
    
