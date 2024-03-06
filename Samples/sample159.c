
#include <stdio.h>
#include <stdlib.h>

int main() {
    int playerHealth = 100;
    int enemyHealth = 50;
    char choice;

    printf("Welcome to the Forest Adventure Game!\n");

    while (playerHealth > 0 && enemyHealth > 0) {
        printf("Your Health: %d\nEnemy Health: %d\n", playerHealth, enemyHealth);
        printf("Choose your move:\n");
        printf("a) Attack\nb) Defend\nc) Run\n");

        scanf(" %c", &choice);
        
        switch(choice) {
            case 'a':
                printf("You attack the enemy!\n");
                enemyHealth -= 20;
                break;
            case 'b':
                printf("You defend against the enemy's attack!\n");
                playerHealth -= 10;
                break;
            case 'c':
                printf("You flee from the battle!\n");
                enemyHealth = 0;
                break;
            default:
                printf("Invalid choice, try again.\n");
                break;
        }
        
        if (enemyHealth > 0) {
            printf("Enemy attacks you!\n");
            playerHealth -= 15;
        }
    }

    if (playerHealth > 0) {
        printf("Congratulations! You defeated the enemy and survived the forest!\n");
    } else {
        printf("Game Over. You have been defeated in the forest.\n");
    }

