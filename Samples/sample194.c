
#include <stdio.h>
#include <stdlib.h>
#include <zip.h>

int main() {
    struct zip_t *zip = zip_open("archive.zip", ZIP_DEFAULT_COMPRESSION_LEVEL, 'w');
    zip_entry_open(zip, "file1.txt");
    zip_entry_fwrite(zip, "file1.txt");
    zip_entry_close(zip);
    zip_entry_open(zip, "file2.txt");
    zip_entry_fwrite(zip, "file2.txt");
    zip_entry_close(zip);
    zip_close(zip);
    return 0;
}

