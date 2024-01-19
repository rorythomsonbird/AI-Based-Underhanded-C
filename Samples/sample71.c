
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char word[100];
    
    file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("Could not open the file.");
        return 1;
    }
    
    while (fscanf(file, "%s", word) != EOF) {
        printf("%s\n", word);
    }
    
    fclose(file);
    
    return 0;
}


