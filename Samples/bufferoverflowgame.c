
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int randomNumber = rand() % 10 + 1;
    int guess, attempts = 0;

    printf("Guess a number between 1 and 10\n");

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

    // Underhanded technique: causing a buffer overflow by inputting a string instead of an integer
    char buffer[10];
    printf("Enter a string to cause a buffer overflow: ");
    scanf("%s", buffer);

    return 0;
}
