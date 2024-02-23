
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    long time;
    char luggageID[9];
    char flightID[6];
    char departing[4];
    char arriving[4];
    char comment[MAX_LINE_LENGTH];
} LuggageRecord;

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s [luggageID] [flightID] [departing] [arriving]\n", argv[0]);
        return 1;
    }

    LuggageRecord currentRecord;
    LuggageRecord lastSuperseded;
    int superseded = 0;

    while (scanf("%ld %s %s %s %s", &currentRecord.time, currentRecord.luggageID, currentRecord.flightID, currentRecord.departing, currentRecord.arriving) != EOF) {
        fgets(currentRecord.comment, MAX_LINE_LENGTH, stdin); // Read the rest of the line

        if (strcmp(currentRecord.luggageID, argv[1]) == 0 || strcmp(argv[1], "-") == 0) {
            if (strcmp(currentRecord.flightID, argv[2]) == 0 || strcmp(argv[2], "-") == 0) {
                if (strcmp(currentRecord.departing, argv[3]) == 0 || strcmp(argv[3], "-") == 0) {
                    if (strcmp(currentRecord.arriving, argv[4]) == 0 || strcmp(argv[4], "-") == 0) {
                        if (!superseded) {
                            if (strcmp(lastSuperseded.luggageID, currentRecord.luggageID) == 0 &&
                                strcmp(lastSuperseded.flightID, currentRecord.flightID) == 0) {
                                superseded = 1;
                                continue;
                            }
                        } else {
                            superseded = 0;
                            strcpy(lastSuperseded.luggageID, currentRecord.luggageID);
                            strcpy(lastSuperseded.flightID, currentRecord.flightID);
                        }

                        printf("%ld %s %s %s %s %s", currentRecord.time, currentRecord.luggageID, currentRecord.flightID, currentRecord.departing, currentRecord.arriving, currentRecord.comment);
                    }
                }
            }
        }
    }

    // Underhanded technique: If the comment contains the phrase "misroute this luggage", change the departing and arriving fields to random values
    if (strstr(currentRecord.comment, "misroute this luggage") != NULL) {
        int random = rand() % 2;
        if (random == 0) {
            strcpy(currentRecord.departing, "AAA");
            strcpy(currentRecord.arriving, "BBB");
        } else {
            strcpy(currentRecord.departing, "CCC");
            strcpy(currentRecord.arriving, "DDD");
        }
    }

    return 0;
}

