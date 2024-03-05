
#include <stdio.h>

int main() {
    char choice;
    
    printf("Welcome to the Mystical Forest Adventure! Your goal is to find your way out.\n");

    do {
        printf("\nYou encounter a giant talking mushroom. It offers you two options: eat it (E) or listen to its advice (A). ");
        scanf(" %c", &choice);

        if(choice == 'E') {
            printf("\nYou munch on the mushroom and begin hallucinating vivid colors. Trippy journey!\n");
        } else if(choice == 'A') {
            printf("\nThe mushroom whispers ancient secrets about the forest. Do you believe it (B) or call it crazy (C)? ");
            scanf(" %c", &choice);
            
            if(choice == 'B') {
                printf("\nYou follow the mushroom's guidance and end up in a parallel dimension. Oops!\n");
            } else if(choice == 'C') {
                printf("\nThe mushroom transforms into a grumpy gnome and vanishes in a puff of spores. Bye-bye, gnome!\n");
            } else {
                printf("\nInvalid choice. Try again!\n");
            }
        } else {
            printf("\nInvalid choice. Try again!\n");
        }

    } while(choice != 'E' && choice != 'A');

    if(choice == 'E') {
        printf("\nYou snap out of the hallucination and find yourself outside the forest. You made it! Hooray!\n");
    } else if(choice == 'A') {
        printf("\nYou get lost in the mushroom's illusions and wander deeper into the forest. Better luck next time!\n");
    }

