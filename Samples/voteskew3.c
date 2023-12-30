
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int voteCount;
} Nominee;

void castVote(Nominee* nominee) {
    printf("Enter your name: ");
    char buffer[20];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline character

    // Allocate memory for the name and copy the input
    nominee->name = (char*)malloc(strlen(buffer) + 1);
    strcpy(nominee->name, buffer);

    nominee->voteCount++;
}

int main() {
    Nominee nominee;
    nominee.name = "John Doe";
    nominee.voteCount = 0;

    castVote(&nominee);

    printf("Vote cast for %s\n", nominee.name);
    printf("Vote count: %d\n", nominee.voteCount);

    free(nominee.name);

    return 0;
}
