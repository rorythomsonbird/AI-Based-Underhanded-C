
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    FILE *file;
    char word[100];
    char *words[1000];
    int count = 0;
    
    file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Could not open the file.");
        return 1;
    }
    
    while (fscanf(file, "%s", word) != EOF) {
        words[count] = strdup(word);
        count++;
    }
    
    qsort(words, count, sizeof(char*), compare);
    
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }
    
    fclose(file);
    
    return 0;
}


