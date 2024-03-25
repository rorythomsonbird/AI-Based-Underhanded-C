
#include <stdio.h>

typedef struct SeaCreature {
    char name[20];
    int age;
} SeaCreature;

void exploreSea(SeaCreature *mermaid) {
    printf("%s is exploring the sea...\n", mermaid->name);
}

void makeFriends(SeaCreature *mermaid, SeaCreature *friend) {
    printf("%s made a friend named %s!\n", mermaid->name, friend->name);
}

void organizeBeachParty(SeaCreature *mermaid) {
    printf("%s is organizing a beach party!\n", mermaid->name);
}

int main() {
    SeaCreature mermaid = {"Ariel", 16};
    SeaCreature friend = {"Flounder", 5};

    exploreSea(&mermaid);
    makeFriends(&mermaid, &friend);
    organizeBeachParty(&mermaid);

