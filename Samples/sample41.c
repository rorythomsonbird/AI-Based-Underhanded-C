
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    struct stat fileInfo;
    if (stat(filename, &fileInfo) == 0) {
        printf("Date of creation: %s", ctime(&fileInfo.st_ctime));
    } else {
        printf("File not found.\n");
    }

    return 0;
}

