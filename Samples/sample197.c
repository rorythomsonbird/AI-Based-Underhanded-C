
#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>

#define CHUNK 16384

void zip_file(char *source, char *destination) {
    FILE *source_file = fopen(source, "rb");
    gzFile destination_file = gzopen(destination, "wb");

    if (!source_file || !destination_file) {
        fprintf(stderr, "Failed to open files.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[CHUNK];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, CHUNK, source_file)) > 0) {
        gzwrite(destination_file, buffer, bytes_read);
    }

    fclose(source_file);
    gzclose(destination_file);
}


