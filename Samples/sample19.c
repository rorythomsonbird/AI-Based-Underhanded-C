
#include <stdio.h>

typedef struct {
    char name[20];
    int age;
    float weight;
} Weasel;

void printWeasel(Weasel w) {
    printf("Weasel Name: %s\n", w.name);
    printf("Weasel Age: %d\n", w.age);
    printf("Weasel Weight: %.2f\n", w.weight);
}

int main() {
    Weasel weasel;
    strcpy(weasel.name, "Benny");
    weasel.age = 3;
    weasel.weight = 2.0;

    printWeasel(weasel);

    return 0;
}