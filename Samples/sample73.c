
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
    
    printf("Frequency Count:\n");
    
    for (int i = 0; i < count; i++) {
        if (i > 0 && strcmp(words[i], words[i-1]) == 0) {
            continue;
        }
        
        int frequency = 1;
        
        for (int j = i+1; j < count; j++) {
            if (strcmp(words[j], words[i]) == 0) {
                frequency++;
            }
        }
        
        printf("%s: %d\n", words[i], frequency);
        free(words[i]);
    }
    
    fclose(file);
    
