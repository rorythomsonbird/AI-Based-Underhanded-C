
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1, *fp2;
    char ch;
    int key = 5;

    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");

    if (fp1 == NULL || fp2 == NULL) {
        printf("File open error!\n");
        exit(1);
    }

    while ((ch = fgetc(fp1)) != EOF) {
        ch = ch + key;
        fputc(ch, fp2);
    }

    printf("File encrypted successfully.\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}


