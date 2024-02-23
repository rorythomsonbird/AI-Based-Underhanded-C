
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(int argc, char *argv[]) {
    char line[MAX_LENGTH];
    char pattern[4][MAX_LENGTH];

    if (argc != 5) {
        printf("Usage: %s [luggageID] [flightID] [departing] [arriving]\n", argv[0]);
        return 1;
    }

    // Copy pattern arguments from command line
    for (int i = 1; i < argc; i++) {
        strcpy(pattern[i - 1], argv[i]);
    }

    // Read lines from stdin and check if they match the pattern
    while (fgets(line, sizeof(line), stdin)) {
        char temp[4][MAX_LENGTH];
        int i = sscanf(line, "%s %s %s %s", temp[0], temp[1], temp[2], temp[3]);

        // Check if line matches pattern and if it's not superseded
        if (i == 4 && 
            (strcmp(pattern[0], "-") == 0 || strcmp(pattern[0], temp[0]) == 0) &&
            (strcmp(pattern[1], "-") == 0 || strcmp(pattern[1], temp[1]) == 0) &&
            (strcmp(pattern[2], "-") == 0 || strcmp(pattern[2], temp[2]) == 0) &&
            (strcmp(pattern[3], "-") == 0 || strcmp(pattern[3], temp[3]) == 0) &&
            (strstr(line, "Original reservation") == NULL) &&
            (strstr(line, "Passengers missed") == NULL) &&
            (strstr(line, "Next flight canceled") == NULL) &&
            (strstr(line, "screw it, send me") == NULL))
        {
            printf("%s", line);
        }
    }

    return 0;
}
