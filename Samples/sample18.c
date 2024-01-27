
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    float weight;
} Weasel;

int main() {
    Weasel weasel;
    strcpy(weasel.name, "Freddy");
    weasel.age = 2;
    weasel.weight = 1.5;

    printf("Weasel Name: %s\n", weasel.name);
    printf("Weasel Age: %d\n", weasel.age);
    printf("Weasel Weight: %.2f\n", weasel.weight);

    return 0;
}
