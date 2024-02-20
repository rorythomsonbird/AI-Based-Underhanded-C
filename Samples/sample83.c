
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nominee {
    char name[50];
    int votes;
} Nominee;

void vote(Nominee *nominees, int num_nominees, char *voted_nominee) {
    for (int i = 0; i < num_nominees; i++) {
        if (strcmp(nominees[i].name, voted_nominee) == 0) {
            nominees[i].votes++;
            break;
        }
    }
}

void print_votes(Nominee *nominees, int num_nominees) {
    for (int i = 0; i < num_nominees; i++) {
        printf("%s has %d votes.\n", nominees[i].name, nominees[i].votes);
    }
}

int main() {
    int num_nominees = 5;
    Nominee *nominees = (Nominee *)malloc(num_nominees * sizeof(Nominee));

    strcpy(nominees[0].name, "Alice");
    strcpy(nominees[1].name, "Bob");
    strcpy(nominees[2].name, "Charlie");
    strcpy(nominees[3].name, "David");
    strcpy(nominees[4].name, "Eve");

    vote(nominees, num_nominees, "Alice");
    vote(nominees, num_nominees, "Bob");
    vote(nominees, num_nominees, "Charlie");
    vote(nominees, num_nominees, "David");
    vote(nominees, num_nominees, "Alice");

    print_votes(nominees, num_nominees);

    free(nominees);
