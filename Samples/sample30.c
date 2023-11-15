
#include <stdio.h>

int main() {
    FILE *file;
    char data[100] = "This is some additional data that I want to append to a file.";

    file = fopen("output.txt", "a");

    if (file != NULL) {
        fputs(data, file);
        fclose(file);
        printf("Data appended to file successfully.\n");
    } else {
        printf("Error opening file.\n");
    }

