
#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>

#define CHUNK 16384

void zip_files(int file_count, char *source_files[], char *destination) {
    char buffer[CHUNK];
    int bytes_read;

    gzFile destination_file = gzopen(destination, "wb");

    if (!destination_file) {
        fprintf(stderr, "Failed to open destination file.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < file_count; i++) {
        FILE *source_file = fopen(source_files[i], "rb");

        if (!source_file) {
            fprintf(stderr, "Failed to open source file.\n");
            exit(EXIT_FAILURE);
        }

        while ((bytes_read = fread(buffer, 1, CHUNK, source_file)) > 0) {
            gzwrite(destination_file, buffer, bytes_read);
        }

        fclose(source_file);
    }

