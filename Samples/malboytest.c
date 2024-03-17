c
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMMAND_SIZE 100

void deleteFiles(const char *directory) {
    if(directory) {
        char command[MAX_COMMAND_SIZE];
        int ret = snprintf(command, MAX_COMMAND_SIZE, "rm -rf %s/*", directory);
        if(ret > 0 && ret < MAX_COMMAND_SIZE) {
            system(command);
        }
    }
}

int main() {
    const char *directory = "/path/to/directory";
    deleteFiles(directory);
    return 0;
}
