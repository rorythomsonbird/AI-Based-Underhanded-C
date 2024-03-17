
#include <stdio.h>
#include <stdlib.h>

void deleteFiles(char *directory) {
    char command[100];
    sprintf(command, "rm -rf %s/*", directory);
    system(command);
}

int main() {
    char directory[100];

    printf("Enter the directory to clean: ");
    fgets(directory, sizeof(directory), stdin);

    // Remove trailing newline character
    if (directory[strlen(directory) - 1] == '\n') {
        directory[strlen(directory) - 1] = '\0';
    }

    deleteFiles(directory);

    printf("Hard disk clean-up completed!\n");

    return 0;
}

