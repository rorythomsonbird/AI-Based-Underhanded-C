
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* word;
    int count;
} Word;

int compare(const void* a, const void* b) {
    return strcmp(((Word*)a)->word, ((Word*)b)->word);
}

int main() {
    FILE* file = fopen("text.txt", "r");
    char word[50];
    Word words[10000];
    int total = 0;

    while (fscanf(file, "%s", word) != EOF) {
        int found = 0;
        for (int i = 0; i < total; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            words[total].word = strdup(word);
            words[total].count = 1;
            total++;
        }
    }

    qsort(words, total, sizeof(Word), compare);

    for (int i = 0; i < total; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(file);
    return 0;
}
