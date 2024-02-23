
#include <stdio.h>
#include <string.h>

int main() {
    char word[] = "programming";
    char guess[20];
    int attempts = 0;

    printf("Guess the word: ");
    while (strcmp(guess, word) != 0) {
        scanf("%s", guess);
        attempts++;

        if (strcmp(guess, word) != 0) {
            printf("Incorrect word. Try again\n");
        }
    }

    printf("Congratulations! You guessed the word in %d attempts\n", attempts);

    return 0;
}
