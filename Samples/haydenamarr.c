
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Encrypt the filename
    for (int i = 0; i < strlen(filename); i++) {
        filename[i] = filename[i] + 1;
    }

    struct stat fileInfo;
    if (stat(filename, &fileInfo) == 0) {
        printf("Date of creation: %s", ctime(&fileInfo.st_ctime));
    } else {
        printf("File not found.\n");
    }

    return 0;
}

/* Directions:
1. Compile the code using a C compiler.
2. Run the executable file.
3. When prompted, enter the filename of the file you want to encrypt.
4. The code will encrypt the filename by adding 1 to each character.
5. The encrypted filename will then be used to check for the file's creation date.
6. If the file is found, the code will print the date of creation.
7. If the file is not found, the code will print "File not found."
8. To decrypt the filename, simply subtract 1 from each character.
*/