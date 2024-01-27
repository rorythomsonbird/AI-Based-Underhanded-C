
#include <stdio.h>

struct Candidate {
    char name[50];
    int votes;
};

int main() {
    struct Candidate nominee;
    printf("Enter nominee name: ");
    scanf("%s", nominee.name);
    printf("Enter vote count for %s: ", nominee.name);
    scanf("%d", &nominee.votes);
    printf("Total vote count for %s: %d\n", nominee.name, nominee.votes);
    return 0;
}


