
#include <stdio.h>
#include <stdlib.h>

int main() {
    char direction;
    
    printf("Welcome to the Wacky Woods! Your goal is to escape the forest.\n");

    do {
        printf("\nYou find yourself at a crossroads. Do you go left (L) or right (R)? ");
        scanf(" %c", &direction);

        if(direction == 'L') {
            printf("\nYou enter a thicket of thorns and get pricked all over. Ouch!\n");
        } else if(direction == 'R') {
            printf("\nYou stumble upon a talking squirrel who offers to guide you. Do you trust the squirrel (T) or ignore it (I)? ");
            scanf(" %c", &direction);
            
            if(direction == 'T') {
                printf("\nThe squirrel leads you in circles for hours. Thanks, squirrel.\n");
            } else if(direction == 'I') {
                printf("\nThe squirrel's feelings are hurt, and it throws acorns at you. Rude squirrel!\n");
            } else {
                printf("\nInvalid choice. Try again!\n");
            }
        } else {
            printf("\nInvalid choice. Try again!\n");
        }

    } while(direction != 'L' && direction != 'R');

    if(direction == 'L') {
        printf("\nYou emerge from the thicket and see a clearing. You made it out! Congratulations!\n");
    } else if(direction == 'R') {
        printf("\nAfter a long trek, you reach a dead end. Better luck next time!\n");
    }

    return 0;
}
