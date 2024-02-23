
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];
    strcpy(buffer, "Buffer Overflow");
    printf("%s\n", buffer);
