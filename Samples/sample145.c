
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int randomNumber = rand() % 100 + 1;
    int guess, attempts = 0;

    printf("Guess a number between 1 and 100\n");

    do {
        scanf("%d", &guess);
        attempts++;

        if (guess > randomNumber) {
            printf("Too high! Try again\n");
        } else if (guess < randomNumber) {
            printf("Too low! Try again\n");
        }
    } while (guess != randomNumber);

    printf("Congratulations! You guessed the number in %d attempts\n", attempts);

