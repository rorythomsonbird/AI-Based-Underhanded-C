
#include <stdio.h>

int main() {
    int injured = 0;
    int hasHat = 0;
    int metPrincess = 0;
    int hitPrincess = 0;
    int attractiveToPrincess = 0;

    printf("Fairy prince encounters a lizard.\n");

    if (injured) {
        if (injured && !hitPrincess) {
            printf("Fairy prince is rescued by a frog.\n");
        } else {
            printf("Fairy prince is rescued by a princess.\n");
            if (hasHat) {
                printf("Fairy prince is more attractive to the princess and receives a crown.\n");
            }
        }
    } else {
        metPrincess = 1;
        printf("Fairy prince meets the princess.\n");
        if (metPrincess) {
            printf("Fairy prince says hello to the princess and receives a wedding ring.\n");
        } else {
            printf("Fairy prince hits the princess and she hits him back, killing him.\n");
        }
    }
}
