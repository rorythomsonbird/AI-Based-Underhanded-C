
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct {
    char* word;
    int count;
} Word;

int compare(const void* a, const void* b) {
    return strcmp(((Word*)a)->word, ((Word*)b)->word);
}

int main() {
    int file = open("text.txt", O_RDONLY);
    char word[50];
    Word words[10000];
    int total = 0;
    int index = 0;

    while (read(file, &word[index], 1) > 0) {
        if (word[index] == ' ' || word[index] == '\n') {
            word[index] = '\0';
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
            index = 0;
        } else {
            index++;
        }
    }

    qsort(words, total, sizeof(Word), compare);

    for (int i = 0; i < total; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    close(file);
    return 0;
}
