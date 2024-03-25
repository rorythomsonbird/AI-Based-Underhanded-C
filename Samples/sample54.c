
#include <stdio.h>

int main() {
    int injured = 0;
    int special_hat = 0;
    int attractive = 0;
    int princess_interaction = 0;

    printf("Fairy prince encounters a lizard.\n");

    if (injured) {
        printf("The lizard injures the prince.\n");
        // Rescued by princess or frog
    } else {
        printf("The prince defeats the lizard.\n");

        if (special_hat) {
            printf("The prince picks up a special hat.\n");
            // Hat makes prince more attractive or produces a horse
        }

        printf("The prince meets the princess.\n");

        if (princess_interaction) {
            printf("The prince says hello to the princess.\n");
            // Princess gives wedding ring
        } else {
            printf("The prince hits the princess.\n");
            // Princess hits back and kills prince
        }

        if (attractive) {
            printf("The princess finds the prince more attractive.\n");
            // Princess gives crown
        }
    }

