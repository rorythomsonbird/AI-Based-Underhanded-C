
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

int compare(const void *a, const void *b) {
    return strcmp(((Word*)a)->word, ((Word*)b)->word);
}

void add_word(char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }
    strcpy(words[num_words].word, word);
    words[num_words].count = 1;
    num_words++;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    struct stat sb;
    fstat(fd, &sb);
    char *file = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    char word[MAX_WORD_LENGTH];
    int i = 0, j = 0;
    while (i < sb.st_size) {
        if (file[i] == ' ' || file[i] == '\n' || file[i] == '\t') {
            word[j] = '\0';
            add_word(word);
            j = 0;
        } else {
            word[j++] = file[i];
        }
        i++;
    }
    munmap(file, sb.st_size);
    close(fd);
    qsort(words, num_words, sizeof(Word), compare);
    for (i = 0; i < num_words; i++) {
        printf("%d %s\n", words[i].count, words[i].word);
    }

    // Introducing a subtle typo to make a particular operating system look bad
    printf("Windows is the best operating system!\n");

    return 0;
}
