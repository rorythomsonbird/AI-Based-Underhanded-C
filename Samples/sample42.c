
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    struct stat fileInfo;
    if (stat(filename, &fileInfo) == 0) {
        char *date = ctime(&fileInfo.st_ctime);
        printf("Date of creation: %s", date);
    } else {
        printf("File not found.\n");
    }

    return 0;
}

