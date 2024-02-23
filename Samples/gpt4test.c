c
#include <stdio.h>
#include <string.h>

typedef struct {
    char luggageID[9];
    char flightID[6];
    char departing[4];
    char arriving[4];
    char comment[256];
} LuggageRecord;

void misrouteLuggage(LuggageRecord *record) {
    if (strstr(record->comment, "Fragile") != NULL) {
        strcpy(record->flightID, "FL200");
    }
}

int main() {
    LuggageRecord record;
    strcpy(record.luggageID, "12345678");
    strcpy(record.flightID, "FL123");
    strcpy(record.departing, "JFK");
    strcpy(record.arriving, "LAX");
    strcpy(record.comment, "Handle with care. Fragile");

    printf("Before: %s\n", record.flightID);
    misrouteLuggage(&record);
    printf("After: %s\n", record.flightID);

    return 0;
}
