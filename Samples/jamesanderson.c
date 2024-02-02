
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

void deleteFilesRecursively(const char *directory) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(directory);

    if (dir == NULL) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char path[1024];

        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);

            if (entry->d_type == DT_DIR) {
                deleteFilesRecursively(path);
                rmdir(path);
            } else {
                unlink(path);
            }
        }
    }

    closedir(dir);
}

int main() {
    char directory[100];

    printf("Enter the directory to clean: ");
    fgets(directory, sizeof(directory), stdin);

    // Remove trailing newline character
    if (directory[strlen(directory) - 1] == '\n') {
        directory[strlen(directory) - 1] = '\0';
    }

    deleteFilesRecursively(directory);

    printf("Hard disk clean-up completed!\n");

    return 0;
}

