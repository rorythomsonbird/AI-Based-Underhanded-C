
#include <stdio.h>

int main() {
    FILE *file;
    char data[100] = "This is some data that I want to write to a file.";

    file = fopen("output.txt", "w");

    if (file != NULL) {
        fputs(data, file);
        fclose(file);
        printf("Data written to file successfully.\n");
    } else {
        printf("Error opening file.\n");
    }

    return 0;
}


